<?php
function punchclock_admin_form() {
  $form = array();

  $form['punchclock_approved_domains'] = array(
    '#type' => 'textarea',
    '#title' => t('Approved domains'),
    '#default_value' => variable_get('punchclock_approved_domains', 'example.com'),
    '#description' => t("Only emails from these domains should be considered for punch ins and outs."),
    '#required' => FALSE,
  );
  
  $form['punchclock_imap_connection_string'] = array(
    '#type' => 'textfield',
    '#title' => t('IMAP Connection String'),
    '#default_value' => variable_get('punchclock_imap_connection_string', '{imap.gmail.com:993/imap/ssl}INBOX'),
    '#description' => t("Connection string for IMAP, such as {imap.gmail.com:993/imap/ssl}INBOX"),
    '#required' => FALSE,
  );
  
  $form['punchclock_imap_username'] = array(
    '#type' => 'textfield',
    '#title' => t('IMAP Username'),
    '#default_value' => variable_get('punchclock_imap_username', ''),
    '#description' => t("Username for an account to be checked."),
    '#required' => FALSE,
  );
  
  $form['punchclock_imap_password'] = array(
    '#type' => 'textfield',
    '#title' => t('IMAP Password'),
    '#default_value' => variable_get('punchclock_imap_password', ''),
    '#description' => t("Password for an account to be checked."),
    '#required' => FALSE,
  );

  return system_settings_form($form);
}