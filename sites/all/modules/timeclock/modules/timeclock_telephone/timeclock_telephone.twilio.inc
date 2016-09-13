<?php
/**
 * @file
 * include file for timeclock_telephone.
 */
 
  /**
  * Custom function to generate twilio Twiml documents to handle 
  * incoming calls.
  */
  function timeclock_telephone_handle_incoming() {
    $realm = 'Restricted API Interface';
    if (empty($_SERVER['PHP_AUTH_DIGEST'])) {
      header('WWW-Authenticate: Digest realm="' . $realm . '",qop="auth",nonce="' . uniqid() . '",opaque="' . md5($realm) . '"');
      header('HTTP/1.1 401 Unauthorized');
      die('Unauthorized Access Attempt to API Interface - This infraction has been logged.');
    }
    // analyze the PHP_AUTH_DIGEST variable
    $authpass = TRUE;
    if (!($data = timeclock_telephone_http_digest_parse($_SERVER['PHP_AUTH_DIGEST'])) || $data['username'] != variable_get('timeclock_telephone_apiuser')) {
      $authpass = false;
    }
    // generate the valid response
    $A1 = md5($data['username'] . ':' . $realm . ':' . variable_get('timeclock_telephone_apipass'));
    $A2 = md5($_SERVER['REQUEST_METHOD'].':'.$data['uri']);
    $valid_response = md5($A1.':'.$data['nonce'].':'.$data['nc'].':'.$data['cnonce'].':'.$data['qop'].':'.$A2);
    if ($_REQUEST['AccountSid'] == variable_get('timeclock_telephone_accountsid', '0') && $data['response'] == $valid_response && $authpass) {
      $called_number = $_REQUEST['To'];
      $call_script = timeclock_telephone_get_script_from_number($called_number);
      $verbs = timeclock_telephone_get_current_verbs($call_script);
      timeclock_telephone_output_twiml($verbs, $call_script);
    }
    else {
      //AccountSid doesn't match
      watchdog('Incoming call failed', 'Either there was a mismatch in the information supplied from Twilio, such as AccountSID, Username, Password. Check your Twilio Account page as well as the settings for this module.');
      $call_script = 0;
      $verbs = timeclock_telephone_get_current_verbs($call_script);
      timeclock_telephone_output_twiml($verbs, $call_script);
    }
    drupal_exit(); 
  }
    
  function timeclock_telephone_output_twiml($verbs, $call_script, $resume = 0) {  
    $mtime = strtotime('now');
    $last_modified = gmdate(DATE_RFC1123, $mtime);
    $etag = '"' . md5($last_modified) . '"';

    $headers = array(
      'Content-type' => 'text/xml; charset=utf-8',
      'Last-modified' => $last_modified,
      'Etag' => $etag,
      'Expires' => gmdate(DATE_RFC1123, $mtime),
      'Cache-Control' => 'must-revalidate',
      'X-Robots-Tag' => 'noindex, follow',
    );
    if (ob_get_level()) {
      ob_end_clean();
    }
    foreach ($headers as $name => $value) {
      drupal_add_http_header($name, $value);
    }
    drupal_send_headers();
    print '<?xml version="1.0" encoding="UTF-8"?>' . "\n";
    print '<Response>' . "\n";
    foreach ($verbs as $order => $verb) {
      if ($order > $resume) {
        print timeclock_telephone_assemble_twiml_verbs($verb, $order, $call_script);
        print "\n";
        if ($verb['verb'] == 'gather' || $verb['verb'] == 'record') {
          //Add an error prompt after gather and record prompts, shouldn't
          //ever be played unless gather fails. Call will disconnect after.
          print '<Say voice="alice">There was an error with your submission.</Say>';
          print "\n";
          break;
        }
      }
    }
    print '</Response>';
  }

  function timeclock_telephone_assemble_twiml_verbs($verb, $order, $call_script) {
    $return = '';
    $option_string = '';
    if (isset($verb['options'])) {
      foreach ($verb['options'] as $option => $value) {
        $option_string .= ' ' . $option . '="' . $value . '"';
      }
    }
    switch ($verb['verb']) {
      case 'say':
        $return = '<Say' . $option_string . '>'.$verb['value'].'</Say>';
        break;
      case 'pause':
        $length = (is_numeric($verb['value'])) ? 'length="'.$verb['value'] . '"' : 'length="1"';
        $return = '<Pause ' . $length .'/>';
        break;
      case 'play':
        $return = '<Play' . $option_string . '>'.$verb['value'].'</Play>';
        break;
      case 'gather':
        if (isset($verb['nest'])) {
          $option_string = '';
          if (isset($verb['nest']['options'])) {
            foreach ($verb['nest']['options'] as $option => $value) {
              $option_string .= ' ' . $option . '="' . $value . '"';
            }
          }  
          if (isset($verb['nest']['verb']) && $verb['nest']['verb'] == 'say') {
            $nest =  "\n" . '<Say' . $option_string . '>'.$verb['nest']['value'].'</Say>' . "\n";
          }
          elseif (isset($verb['nest']['verb']) && $verb['nest']['verb'] == 'play') {
            $nest =  "\n" . '<Play' . $option_string . '>'.$verb['nest']['value'].'</Play> . "\n"';
          }
          else {
            $nest = '';
          }
        }
        $return = '<Gather action="/twilio_gather.php?cs=' . $call_script . '&amp;ord=' . $order  . '&amp;function=' . $verb['function'] . '" method="POST">' . $nest . '</Gather>';
        break;
      case 'record':
        $return = '<Record action="/twilio_record.php?cs=' . $call_script . '&amp;ord=' . $order . '" method="POST"' . $option_string .'/>';
        break;
      default:
        $return = '';
    }
    return $return;
  }

  function timeclock_telephone_get_current_verbs($call_script = 0) {
    if ($call_script > 0) {
      $script = timeclock_telephone_load($call_script);
      $verbs = array();
      $verbs = unserialize($script->script);
    }
    else {
      $verbs['1'] = array(
        'verb' => 'say',
        'value' => 'An error has occured.',
        'options' => array(
          'voice' => 'alice',
        ),
      );
    }
    return $verbs;
  }

  function timeclock_telephone_get_script_from_number($called_number) {
    $query = db_select('timeclock_telephone_scripts', 's')
      ->fields('s', array('sid'))
      ->condition('number', $called_number, '=');
    $results = $query
      ->range(0, 1)
      ->execute()
      ->fetchAll();
    foreach ($results as $row) {
      $call_script = $row->sid;
    }
    if (!is_numeric($call_script)) {
      $call_script = 0;
    }
    return $call_script;
  }

  function timeclock_telephone_handle_gather() {
    $call_script = $_REQUEST['cs'];
    $order = $_REQUEST['ord'];
    $digits = $_REQUEST['Digits'];
    $variable = $_REQUEST['var'];
    $verbs = timeclock_telephone_get_current_verbs($call_script);
    timeclock_telephone_output_twiml($verbs, $call_script, $order);
    drupal_exit(); 
  }

/**
 * Custom function to parse values from HTTP Digest for Twilio login into Page.
 * Based on PHP Manul Page: http://php.net/manual/en/features.http-auth.php
 **/

function timeclock_telephone_http_digest_parse($txt) {
  // protect against missing data
    $needed_parts = array('nonce'=>1, 'nc'=>1, 'cnonce'=>1, 'qop'=>1, 'username'=>1, 'uri'=>1, 'response'=>1);
    $data = array();

    preg_match_all('@(\w+)=(?:([\'"])([^$2]+)$2|([^\s,]+))@', $txt, $matches, PREG_SET_ORDER);
   
    foreach ($matches as $m) {
        $data[$m[1]] = $m[3] ? trim($m[3],"\",'") : trim($m[4],"\",'");
        unset($needed_parts[$m[1]]);
    }
   
    return $needed_parts ? false : $data;
}
