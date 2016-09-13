<?php

/**
 * @file
 * Administration forms for the timeclock_web module.
 */

/**
 * Page callback for admin page form.
 *
 * Default values for each variable are set on hook_install().
 */
function timeclock_web_admin() {
  $form = array();

  $form['timeclock_web_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Do you want to save records to the Database when a punch is submitted?'),
    '#default_value' => variable_get('timeclock_web_enabled'),
  );

  return system_settings_form($form);
}

/**
 * Validates admin form submissions.
 */
function timeclock_web_admin_validate($form, &$form_state) {
  // Placeholder function for future use.
  if ($form_state['values']['timeclock_web_enabled'] == 1) {
    drupal_set_message(t('Time clock submissions will be enabled.'), 'status');
  }
}
