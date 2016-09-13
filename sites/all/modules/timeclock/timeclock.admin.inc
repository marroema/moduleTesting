<?php

/**
 * @file
 * Administration forms for the timeclock module.
 */

/**
 * Page callback for admin page form.
 *
 * Default values for each variable are set on hook_install().
 */
function timeclock_admin() {
  $form = array();

  $form['timeclock_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Do you want to save records to the Database when a punch is submitted?'),
    '#default_value' => variable_get('timeclock_enabled'),
  );
  $vocabulary = array();
  /**
   * @TODO figure out how to get Vocab list or create custom vocab on module install?.
   */
  $vocabulary = array(1,2,3,4);
  $form['department'] = array(
    '#type' => 'select',
    '#title' => t('Department Vocabulary Taxonomy'),
    '#options' => $vocabulary,
    '#description' => t('Select the Taxonomy Vocabulary that contains your departments.')
  );

  return system_settings_form($form);
}

/**
 * Validates admin form submissions.
 */
function timeclock_admin_validate($form, &$form_state) {
  // Placeholder function for future use.
  if ($form_state['values']['timeclock_enabled'] == 1) {
    drupal_set_message(t('Time clock submissions will be enabled.'), 'status');
  }
}
