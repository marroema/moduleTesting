<?php
/**
 * @file
 * Page callbacks for timeclock_payroll.
 */

function timeclock_payroll_main_page () {
  drupal_add_css(drupal_get_path('module', 'timeclock_payroll') . '/timeclock_payroll.css', array('group' => CSS_DEFAULT, 'every_page' => TRUE));
  $users = array();
  if (is_numeric(arg(3)) && arg(2) == 'previous') {
    $length = variable_get('timeclock_payroll_payperiod_length');
    $period = 7 * (int) $length;
    $start = strtotime('-' . $period . ' days', arg(3));
    $end = (int) arg(3);
  }
  elseif (is_numeric(arg(3)) && arg(2) == 'next') {
    $length = variable_get('timeclock_payroll_payperiod_length');
    $period = 7 * $length;
    $start = arg(3);
    $end = strtotime($period . ' days', arg(3));
  }
  else {
    $current_payperiod = timeclock_payroll_current_payperiod();
    $start = $current_payperiod['current'];
    $end = $current_payperiod['next'];
  }
  $last_day = strtotime('-1 days',$end);
  $previous_payperiods = timeclock_payroll_payperiod_dates(7);
  $previous_payperiods_links = '';
  foreach ($previous_payperiods as $payperiod) {
    $payperiod_end = strtotime('-1 days',$payperiod['end']);
    $previous_payperiods_links .= l(date('M d Y', $payperiod['start']) . ' - ' . date('M d Y', $payperiod_end), 'timeclock/payroll/previous/' . $payperiod['end']);
    $previous_payperiods_links .= ' | ';
  }
  $output['top'] = array(
    '#markup' => l(date('M d Y', $start) . ' - ' . date('M d Y', $last_day), 'timclock/payroll') . ' | ' . $previous_payperiods_links . '<br />',
  );
  $output['top_nav'] = array(
    '#markup' => l('<- Previous Payperiod', 'timeclock/payroll/previous/' . $start) . ' - ' . l('Current Payperiod', 'timeclock/payroll') . ' - ' . l('Next Payperiod ->', 'timeclock/payroll/next/' . $end),
  );
  foreach (timeclock_payroll_get_employees_for_period($start, $end) as $employee) {
    $user_fields = user_load(timeclock_lookup_uid_from_eid($employee->eid));
    if (is_numeric(arg(3)) && arg(2) == 'previous') {
      $users[] = l(timeclock_lookup_name_from_eid($employee->eid), 'user/' . $user_fields->uid . '/payroll/previous/' . $end);
    }
    elseif (is_numeric(arg(3)) && arg(2) == 'next') {
      $users[] = l(timeclock_lookup_name_from_eid($employee->eid), 'user/' . $user_fields->uid . '/payroll/next/' . $end);
    }
    else {
      $users[] = l(timeclock_lookup_name_from_eid($employee->eid), 'user/' . $user_fields->uid . '/payroll');
    }
  }
  $output['header'] = array(
      '#markup' => '<hr><p><strong>' . t('Users with punches for payroll period: ') . date('M d Y', $start) . ' - ' . date('M d Y', $last_day) . '</strong></p>',
  );
  $output['content'] = array(
    'user_list' => array(
      '#items' => $users,
      '#type' => 'ul',
      '#theme' => 'item_list',
    ),
  );
  return $output;
}

//Page Callback for viewing User Timesheet
function timeclock_payroll_user_timesheet() {
  drupal_add_css(drupal_get_path('module', 'timeclock_payroll') . '/timeclock_payroll.css', array('group' => CSS_DEFAULT, 'every_page' => TRUE));
  $userpageload = user_load(arg(1));
  $uid = $userpageload->uid;
  if (is_numeric(arg(4)) && arg(3) == 'previous') {
    $length = variable_get('timeclock_payroll_payperiod_length');
    $period = 7 * (int) $length;
    $start = strtotime('-' . $period . ' days', arg(4));
    $end = (int) arg(4);
  }
  elseif (is_numeric(arg(4)) && arg(3) == 'next') {
    $length = variable_get('timeclock_payroll_payperiod_length');
    $period = 7 * $length;
    $start = arg(4);
    $end = strtotime($period . ' days', arg(4));
  }
  else {
    $current_payperiod = timeclock_payroll_current_payperiod();
    $start = $current_payperiod['current'];
    $end = $current_payperiod['next'];
  }
  $last_day = strtotime('-1 days',$end);
  $previous_payperiods = timeclock_payroll_payperiod_dates(7);
  $previous_payperiods_links = '';
  foreach ($previous_payperiods as $payperiod) {
    $payperiod_end = strtotime('-1 days',$payperiod['end']);
    $previous_payperiods_links .= l(date('M d Y', $payperiod['start']) . ' - ' . date('M d Y', $payperiod_end),'user/' . $uid . '/payroll/previous/' . $payperiod['end']);
    $previous_payperiods_links .= ' | ';
  }
  $output['top'] = array(
    '#markup' => '<div class="timeclock_payroll_pay_periods">' . l(date('M d Y', $start) . ' - ' . date('M d Y', $last_day), 'user/' . $uid . '/payroll') . ' | ' . $previous_payperiods_links . '</div>',
  );
  $output['top_nav'] = array(
    '#markup' => '<div class="timeclock_payroll_pay_periods_nav">' . l('<- Previous Pay Period', 'user/' . $uid . '/payroll/previous/' . $start) . ' - ' . l('Current Pay Period', 'user/' . $uid . '/payroll') . ' - ' . l('Next Pay Period ->', 'user/' . $uid . '/payroll/next/' . $end ) . '</div>',
  );
  $output['above_table'] = array(
    '#markup' => '<h1>' . timeclock_lookup_name_from_uid($uid) . '</h1><h2>' . t('Pay Period'). ': ' . date('M d Y', $start) . ' - ' . date('M d Y', $last_day) . '</h2>',
  );
  $output['div'] = array(
      '#markup' => '<div class="timeclock_payroll_inline_form">'
  );
  $output['form'] = drupal_get_form('timeclock_payroll_timesheet', $start, $end, $uid, 0);
  $output['no_div'] = array(
    '#markup' => '</div>',
  );
  $output['bottom_nav'] = array(
    '#markup' => '<br />' . l('Previous Payperiod', 'user/' . $uid . '/payroll/previous/' . $start) . ' - ' . l('Current Payperiod', 'user/' . $uid . '/payroll') . ' - ' . l('Next Payperiod', 'user/' . $uid . '/payroll/next/' . $end),
  );
  $variables['page']['sidebar_first'] = NULL;
  return $output;
}

function timeclock_payroll_timesheet($form, $form_state, $start, $end, $uid, $current_user) {
  $eid = timeclock_lookup_eid_from_uid($uid);
  $data = timeclock_payroll_get_employee_shifts($eid, $start, $end);
  
  //Build form array
  $form['checkall_top'] = array(
    '#type' => 'checkbox',
    '#title' => t('Select / Unselect all'),
    '#attributes' => array('onclick' => 'checkUncheckAll(this);'),
    '#weight' => -10,
    '#prefix' => '<div class="select_all_checkbox">',
    '#suffix' => '</div>',
  );
  $form['checkall_billing_top'] = array(
    '#type' => 'checkbox',
    '#title' => t('Select / Unselect all Billing'),
    '#attributes' => array('onclick' => 'checkUncheckBilling(this);'),
    '#weight' => -9,
    '#prefix' => '<div class="select_all_checkbox">',
    '#suffix' => '</div>',
  );
  $form['checkall_payroll_top'] = array(
    '#type' => 'checkbox',
    '#title' => t('Select / Unselect all Payroll'),
    '#attributes' => array('onclick' => 'checkUncheckPayroll(this);'),
    '#weight' => -8,
    '#prefix' => '<div class="select_all_checkbox">',
    '#suffix' => '</div>',
  );
   $form['submit_top'] = array(
    '#type' => 'submit',
    '#value' => 'Save',
    '#prefix' => '<div class="save_button">',
    '#suffix' => '</div>',
    '#weight' => -7,
  );
  foreach ($data as $value) {
    if ($value->in_out == 1) {
      $in = $value->timestamp;
      $in_pid = $value->pid;
    }
    else {
      $pid = $value->pid;
      $form['pid_' . $pid] = array(
        '#type' => 'fieldset',
        '#title' => 'Department: Onondaga CDPAP Job/Client: John Smith',
        '#tree' => TRUE,
        '#collapsible' => TRUE,
        '#collapsed' => FALSE,
      );
      $dateformat = 'm/d/y h:i A';
      $form['pid_' . $pid]['in'] = array(
        '#type' => 'date_select',
        '#title' => t('In'),
        '#date_timezone' => date_default_timezone(),
        '#date_format' => $dateformat,
        '#date_year_range' => '-3:+3',
        '#size' => 15,
        '#default_value' => date($dateformat, $in),
        '#weight' => 7,
      );
      $form['pid_' . $pid]['out'] = array(
        '#type' => 'date_select',
        '#title' => t('Out'),
        '#date_timezone' => date_default_timezone(),
        '#date_format' => $dateformat,
        '#date_year_range' => '-3:+3',
        '#size' => 15,
        '#default_value' => date($dateformat, $value->timestamp),
        '#weight' => 8,
      );
      $form['pid_' . $pid]['div1'] = array(
        '#markup' => '<div class="container-inline-approve">',
        '#weight' => 9,
      );
      $difference = $value->timestamp - $in;
      $form['pid_' . $pid]['shift_total'] = array(
        '#type' => 'textfield',
        '#title' => t('Total'),
        '#size' => 10,
        '#default_value' => timeclock_payroll_calculate_shift_length($difference),
        '#weight' => 10,
        '#disabled' => TRUE,
      );
      $form['pid_' . $pid]['pay_approve_' . $pid] = array(
        '#type' => 'checkbox',
        '#title' => t('Approve Payroll'),
        '#weight' => 11,
        '#prefix' => '<br>',
      );
       $form['pid_' . $pid]['bill_approve_' . $pid] = array(
        '#type' => 'checkbox',
        '#title' => t('Approve Billing'),
        '#weight' => 12,
        '#prefix' => '<br>',
      );
      $form['pid_' . $pid]['div2'] = array(
        '#markup' => '</div>',
        '#weight' => 13,
      );
    }
  }
  $form['box'] = array(
    '#type' => 'markup',
    '#prefix' => '<div id="new_box">',
    '#suffix' => '</div>',
    '#markup' => '<h1>Click the button to add more fields.</h1>',
  ); 
  $form['add_more'] = array(
    '#type' => 'submit',
    '#ajax' => array(
      'callback' => 'timeclock_payroll_user_timesheet_add',
      'wrapper' => 'new_box',
    ),
    '#value' => t('Add'),
  ); 
  drupal_add_js("
    function checkUncheckAll(theElement){
      var theForm = theElement.form, z = 0;
      for(z=0; z<theForm.length;z++){
        if(theForm[z].type == 'checkbox' && theForm[z].name != 'checkall'){
          theForm[z].checked = theElement.checked;
        }
      }
    }
    function checkUncheckBilling(theElement){
      var theForm = theElement.form, z = 0;
      for(z=0; z<theForm.length;z++){
        if(theForm[z].type == 'checkbox' && theForm[z].name != 'checkall' && theForm[z].name != 'checkall_billing' && theForm[z].name != 'checkall_payroll' && theForm[z].name != 'checkall_billing_top' && theForm[z].name != 'checkall_payroll_top' && theForm[z].name != 'checkall_top' && theForm[z].name.indexOf('pay') == -1){
          theForm[z].checked = theElement.checked;
        }
      }
    }
    function checkUncheckPayroll(theElement){
      var theForm = theElement.form, z = 0;
      for(z=0; z<theForm.length;z++){
        if(theForm[z].type == 'checkbox' && theForm[z].name != 'checkall' && theForm[z].name != 'checkall_billing' && theForm[z].name != 'checkall_payroll' && theForm[z].name != 'checkall_billing_top' && theForm[z].name != 'checkall_payroll_top' && theForm[z].name != 'checkall_top' && theForm[z].name.indexOf('bill') == -1){
          theForm[z].checked = theElement.checked;
        }
      }
    }
  ", 'inline');
  $form['checkall'] = array(
    '#type' => 'checkbox',
    '#title' => t('Select / Unselect all'),
    '#attributes' => array('onclick' => 'checkUncheckAll(this);'),
    '#weight' => 25,
    '#prefix' => '<br><div class="select_all_checkbox">',
    '#suffix' => '</div>',
  );
  $form['checkall_billing'] = array(
    '#type' => 'checkbox',
    '#title' => t('Select / Unselect all Billing'),
    '#attributes' => array('onclick' => 'checkUncheckBilling(this);'),
    '#weight' => 26,
    '#prefix' => '<div class="select_all_checkbox">',
    '#suffix' => '</div>',
  );
  $form['checkall_payroll'] = array(
    '#type' => 'checkbox',
    '#title' => t('Select / Unselect all Payroll'),
    '#attributes' => array('onclick' => 'checkUncheckPayroll(this);'),
    '#weight' => 27,
    '#prefix' => '<div class="select_all_checkbox">',
    '#suffix' => '</div>',
  );
   $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Save',
    '#weight' => 28,
    '#prefix' => '<div class="save_button">',
    '#suffix' => '</div>',
  );
return $form;
}

function timeclock_payroll_user_timesheet_add(&$form, &$formstate) {
  $new_form['box'] = array(
    '#type' => 'markup',
    '#prefix' => '<div id="new_box">',
    '#suffix' => '</div>',
    '#markup' => '',
  );
  $pid = '122654686926543';
  $new_form['pid_' . $pid] = array(
    '#type' => 'fieldset',
    '#title' => 'Department: Onondaga CDPAP Job/Client: John Smith',
    '#tree' => TRUE,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $dateformat = 'm/d/y h:i A';
  $timestamp = strtotime("now");
  $new_form['pid_' . $pid]['in'] = array(
    '#type' => 'textfield',
    '#title' => t('In'),
    '#date_timezone' => date_default_timezone(),
    '#date_format' => date('m/d/y h:i A', $timestamp),
    '#date_year_range' => '-3:+3',
    '#size' => 15,
    '#default_value' => NULL,
    '#weight' => 7,
  );
  $new_form['pid_' . $pid]['out'] = array(
    '#type' => 'date',
    '#title' => t('Out'),
    '#date_timezone' => date_default_timezone(),
    '#date_format' => $dateformat,
    '#date_year_range' => '-3:+3',
    '#size' => 15,
    '#default_value' => date($dateformat, $timestamp),
    '#weight' => 8,
  );
  $new_form['pid_' . $pid]['div1'] = array(
    '#markup' => '<div class="container-inline-approve">',
    '#weight' => 9,
  );
  $new_form['pid_' . $pid]['shift_total'] = array(
    '#type' => 'textfield',
    '#title' => t('Total'),
    '#size' => 10,
    '#default_value' => 0,
    '#weight' => 10,
    '#disabled' => TRUE,
  );
  $new_form['pid_' . $pid]['pay_approve_' . $pid] = array(
    '#type' => 'checkbox',
    '#title' => t('Approve Payroll'),
    '#weight' => 11,
    '#prefix' => '<br>',
  );
  $new_form['pid_' . $pid]['bill_approve_' . $pid] = array(
    '#type' => 'checkbox',
    '#title' => t('Approve Billing'),
    '#weight' => 12,
    '#prefix' => '<br>',
  );
  $new_form['pid_' . $pid]['div2'] = array(
    '#markup' => '</div>',
    '#weight' => 13,
  );
return $new_form;
}

