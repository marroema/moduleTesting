<?php
/**
 * @file
 * The file for admin forms and functionality for the timeclock_telephone entity
 */

/**
 * Implements hook_form().
 */
function timeclock_telephone_form($form, &$form_state, $timeclock_telephone = NULL) {
  $form = array();

  $form['title'] = array(
    '#title' => t('Title'),
    '#type' => 'textfield',
    '#default_value' => isset($timeclock_telephone->title) ? $timeclock_telephone->title : '',
    '#description' => t('Telephone Script name.'),
    '#required' => TRUE,
    '#maxlength' => 255,
  );
  $form['number'] = array(
    '#title' => t('Phone Number'),
    '#type' => 'textfield',
    '#default_value' => isset($timeclock_telephone->number) ? $timeclock_telephone->number : '',
    '#description' => t('Incoming Number for this script.'),
    '#required' => TRUE,
    '#maxlength' => 255,
  );

  $verbs = unserialize($timeclock_telephone->script);
  $verb_array_id = 1;
  $verb_types = array(
    'pause' => t('Pause'),
    'say' => t('Say'),
    'gather' => t('Gather'),
    'record' => t('Record'),
  );
  $pause_options = array(
    1 => 1,
    2 => 2,
    3 => 3,
    4 => 4,
    5 => 5,
    6 => 6,
    7 => 7,
    8 => 8,
    9 => 9,
    10 => 10
  );
  $gather_functions = array(
    'eid' => t('Employee ID'),
    'pin' => t('PIN Number'),
    'job' => t('Job ID Number'),
  );
  $form['verbs_fieldset'] = array(
    '#title' => t('Call Script Verbs'),
    '#type' => 'fieldset',
    '#collapisble' => '1',
    '#collapsed' => '',
  );
  foreach ($verbs as $key => $value) {
    
    $form['verbs_fieldset'][$key] = array(
      '#title' => t('Verb @array_id', array('@array_id' => $key)),
      '#type' => 'fieldset',
      '#collapisble' => TRUE,
      '#collapsed' => FALSE,
    );
    $form['verbs_fieldset'][$key]['verb'] = array(
      '#type' => 'select',
      '#title' => t('Select Verb'),
      '#options' => $verb_types,
      '#default_value' => $value['verb'],
    );
    if ($value['verb'] == 'say') {
      $form['verbs_fieldset'][$key]['value'] = array(
        '#title' => t('Value'),
        '#type' => 'textfield',
        '#default_value' => $value['value'],
      );
    }
    if ($value['verb'] == 'pause') {
      $form['verbs_fieldset'][$key]['value'] = array(
        '#title' => t('Value'),
        '#type' => 'select',
        '#default_value' => $value['value'],
        '#options' => $pause_options,
      );
    }
    if ($value['verb'] == 'gather') {
      $form['verbs_fieldset'][$key]['value'] = array(
        '#title' => t('Function'),
        '#type' => 'select',
        '#default_value' => isset($value['function']) ? $value['function'] : 'eid',
        '#options' => $gather_functions,
      );
    }
  }
$form['script'] = array(
    '#title' => t('Script'),
    '#type' => 'hidden',
    '#default_value' => isset($timeclock_telephone->script) ? $timeclock_telephone->script : '',
    '#description' => t('The serialized Script Array.'),
    '#required' => TRUE,
    '#maxlength' => 5000000,
  );
  field_attach_form('timeclock_telephone', $timeclock_telephone, $form, $form_state);

  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => isset($timeclock_telephone->sid) ? t('Update telephone') : t('Save telephone'),
    ),
    'delete_link' => array(
      '#markup' => isset($timeclock_telephone->sid) ? l(t('Delete'), 'admin/content/telephone/manage/' . $timeclock_telephone->sid . '/delete', array('attributes' => array('id' => array('timeclock_telephone-delete-' . $timeclock_telephone->sid), 'class' => array('button remove')), 'query' => array('destination' => 'admin/content/telephone'))) : ''));
  return $form;
}

/**
 * Implements hook_form_validate().
 */
function timeclock_telephone_form_validate($form, &$form_state) {

}

/**
 * Implements hook_form_submit().
 */
function timeclock_telephone_form_submit($form, &$form_state) {
  $verbs = array();
  foreach ($form_state['complete form']['verbs_fieldset'] as $order => $FAPI_verb) {
    if (is_numeric($order)) {
      switch($FAPI_verb['verb']['#value']) {
        case 'say':
          $verbs[] = array(
            'verb' => $FAPI_verb['verb']['#value'],
            'value' => $FAPI_verb['value']['#value'],
            'options' => array(
              'voice' => 'alice',
            ),
          );
          break;
        case 'pause':
          $verbs[] = array(
            'verb' => $FAPI_verb['verb']['#value'],
            'value' => $FAPI_verb['value']['#value'],
          );
          break;
        case 'gather':
          $verbs[] = array(
            'verb' => $FAPI_verb['verb']['#value'],
            'function' => $FAPI_verb['value']['#value'],
          );
          break;
      }
    }
  }
  dpm($verbs);
  $form_state['complete form']['script']['#value'] = serialize($verbs);
  form_set_value($form['script'], serialize($verbs), $form_state);
  //$timeclock_telephone = entity_ui_form_submit_build_entity($form, $form_state);
  //$timeclock_telephone->save();
  //drupal_set_message(t('@telephone telephone script has been saved.', array('@telephone' => $timeclock_telephone->title)));
  // $form_state['redirect'] = 'admin/content/telephone';
  $form_state['redirect'] = 'telephone/' . $timeclock_telephone->sid;
}

/**
 * Confirmation before bulk deleting timeclock_telephone.
 */
function timeclock_telephone_bulk_delete($form, &$form_state, $sids) {
  $sids = explode('|', $sids);
  $timeclock_telephone = timeclock_telephone_load_multiple($sids);

  $form = array();
  $form_state['sids'] = $sids;

  $variables = array(
    'type' => 'ul',
    'items' => array(),
    'title' => '',
    'attributes' => array(),
  );

  foreach ($timeclock_telephone as $telephone) {
    $variables['items'][] = $telephone->title;
  }

  $form['summary'] = array(
    '#markup' => theme_item_list($variables),
  );

  return confirm_form($form, t('Delete all telephone?'), 'admin/content/telephone', t('Placeholder description'), t('Delete all'), t('Cancel'));
}

/**
 * Implements hook_submit().
 */
function timeclock_telephone_bulk_delete_submit($form, &$form_state) {
  $sids = $form_state['sids'];
  timeclock_telephone_delete_multiple($sids);

  drupal_set_message(t('telephone deleted'));
  drupal_goto('admin/content/telephone');
}
