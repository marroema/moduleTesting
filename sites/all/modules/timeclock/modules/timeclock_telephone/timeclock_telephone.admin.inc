<?php

/**
 * @file
 * Administration forms for the timeclock_telephone module.
 */

/**
 * Page callback for admin page form.
 *
 * Default values for each variable are set on hook_install().
 */
function timeclock_telephone_admin() {
  $form = array();

  $form['timeclock_telephone_accountsid'] = array(
    '#type' => 'textfield',
    '#title' => t('Twilio Account ID'),
    '#default_value' => variable_get('timeclock_telephone_accountsid'),
  );
  $form['timeclock_telephone_apiuser'] = array(
    '#type' => 'textfield',
    '#title' => t('Incoming Call Page Username'),
    '#default_value' => variable_get('timeclock_telephone_apiuser',md5(variable_get('site_name'))),
  );
  $form['timeclock_telephone_apipass'] = array(
    '#type' => 'textfield',
    '#title' => t('Incoming Call Page Password'),
    '#default_value' => variable_get('timeclock_telephone_apiuser',md5(REQUEST_TIME)),
  );

  return system_settings_form($form);
}

/**
 * Validates admin form submissions.
 */
function timeclock_telephone_admin_validate($form, &$form_state) {
}
