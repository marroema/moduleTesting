<?php

/**
 * @file
 * Forms for the timeclock_web module.
 */

/**
 * Form callback for timeclock_web page and block.
 */
function timeclock_web_punch_form() {
  global $user;
  $uid = $user->uid;
  if (timeclock_user_eid_set($uid)) {
    if (timeclock_read_in_out_bit_by_uid($uid) == 1) {
      $current_status = t('clocked in.');
      $status_action = t('Clock Out');
    }
    else {
      $current_status = t('clocked out.');
      $status_action = t('Clock In');
    }
    $form['timeclock_web_punch_form_special_instructions'] = array(
      '#markup' => variable_get('timeclock_web_block_instructions', t('Use the button below to clock in and out.')),
    );
    $form['timeclock_web_punch_form_employee_status'] = array(
      '#markup' => '<br /><strong>' . t('You are currently @status', array('@status' => $current_status)) . '</strong><br />',
    );
    $form['jid'] = array(
      '#type' => 'textfield',
      '#title' => t('Job/Client ID'),
      '#description' => t('Enter the ID number of the job you are clocking into or leave blank if unknown.'),
      '#size' => '10',
    );
    $form['timeclock_web_punch_form_submit'] = array(
      '#type' => 'submit',
      '#value' => $status_action,
    );
    return $form;
  }
  //User is anonymous
  elseif ($uid == 0) {
    $form['timeclock_web_punch_form_special_instructions'] = array(
      '#markup' => t('Punch in for Anonymous users is not yet configured, please sign in before continuing.'),
    );
    $form['eid'] = array(
      '#type' => 'textfield',
      '#title' => t('Employee ID'),
      '#size' => '10',
    );
    $form['pin'] = array(
      '#type' => 'password',
      '#title' => t('Pin'),
      '#size' => '10',
    );
    $form['jid'] = array(
      '#type' => 'textfield',
      '#title' => t('Job ID'),
      '#description' => t('Enter the ID number of the job you are clocking into or leave blank if unknown.'),
      '#size' => '10',
    );
    
    $form['timeclock_web_punch_form_submit'] = array(
      '#type' => 'submit',
      '#value' => t('Submit Punch'),
    );
    return $form;
  }
  else {
    $form['timeclock_web_punch_form_special_instructions'] = array(
      '#markup' => t('Your user has not yet been configured to clock in through this system.'),
    );
    return $form;
  }
}

/**
 * Submit handler for timeclock_web_punch_form().
 */
function timeclock_web_punch_form_submit($form, &$form_state) {
  global $user;
  $uid = $user->uid;
  $return = array();
  if ($uid == 0) {
    dpm($form);
    $eid = $form_state['values']['eid'];
    $pin = $form_state['values']['pin'];
    $data = array(
      'eid' => $eid,
      'pin' => $pin,
      'module' => 'timeclock_web',
    );
  }
  else {
    $eid = timeclock_lookup_eid_from_uid($uid);
    $data = array(
      'eid' => $eid,
      'module' => 'timeclock_web',
    );
  }
  $return = timeclock_process_punch($data);
  if ($return['valid']) {
    drupal_set_message(t('Your timeclock punch has been accepted.'), 'status');
  }
  else {
    drupal_set_message(t('Timeclock Exception: @message', array(
      '@message' => timeclock_submodule_status_message($return['module'], $return['status']),
    )), 'warning');
  }
}
