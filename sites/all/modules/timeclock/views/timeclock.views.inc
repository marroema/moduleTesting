<?php
/**
 * @file
 * File for timeclock.
 */

/**
 * Implements hook_views_data().
 */
function timeclock_views_data() {
  $data = array();
  // Define timeclock_employees table data to views.
  $data['timeclock_employees']['table']['group'] = t('Timeclock Employees');
  $data['timeclock_employees']['table']['base'] = array(
    'field' => 'eid',
    'title' => 'TimeClock Employees',
    'weight' => 5,
    'access query tag' => 'view timeclock punches'
  );
  $data['timeclock_employees']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid',
    )
  );
  $data['timeclock_employees']['uid'] = array(
    'title' => t('Employee Drupal user ID'),
    'help' => t('Employee Drupal user ID number'),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument',
    ),
    'relationship' => array(
      'base' => 'users',
      'field' => 'uid',
      'handler' => 'views_handler_relationship',
      'skip base' => 'users',
      'label' => t('User'),
    ),
  );
  $data['timeclock_employees']['eid'] = array(
    'title' => t('Employee ID'),
    'help' => t('Employee ID number'),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument',
    ),
  );
  $data['timeclock_employees']['status'] = array(
    'title' => t('Employee Status'),
    'help' => t('Employee status value'),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('Enabled'),
      'type' => 'enabled-disabled',
    ),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument',
    ),
  );
  $data['timeclock_employees']['in_out'] = array(
    'title' => t('Employee Clocked In Status'),
    'help' => t('Employee status clocked in status value'),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('Clocked In'),
      'type' => 'yes-no',
    ),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument',
    ),
  );
  $data['timeclock_employees']['name'] = array(
    'title' => t('Employee Name'),
    'help' => t('Employee Name'),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument',
    ),
  );
  $data['timeclock_employees']['department'] = array(
    'title' => t('Department'),
    'help' => t('Department reference'),
    'filter' => array(
      'handler' => 'views_handler_filter_entity_bundle',
    ),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument',
    ),
  );
  // Describe timeclock_punches to views.
  $data['timeclock_punches']['table']['group'] = t('Timeclock Punches');
  $data['timeclock_punches']['table']['base'] = array(
    'field' => 'pid',
    'title' => 'TimeClock Punches',
    'weight' => 5,
    'access query tag' => 'view timeclock punches'
  );
  $data['timeclock_punches']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid',
    ),
    'timeclock_employees' => array(
      'left_field' => 'eid',
      'field' => 'eid',
    ),
  );
  $data['timeclock_punches']['pid'] = array(
    'title' => t('Unique Punch ID'),
    'help' => t('Punch Identifier Number'),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument',
    ),
    'relationship' => array(
      'base' => 'timeclock_punches_edits',
      'field' => 'pid',
      'handler' => 'views_handler_relationship',
      'skip base' => 'timeclock_punches_edits',
      'label' => t('Punch Edits'),
    ),
  );
  $data['timeclock_punches']['uid'] = array(
    'title' => t('User ID of user entering punch'),
    'help' => t('The user ID of the user who entered the punch'),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument',
    ),
    'relationship' => array(
      'base' => 'users',
      'field' => 'uid',
      'handler' => 'views_handler_relationship',
      'skip base' => 'users',
      'label' => t('User'),
    ),
  );
  $data['timeclock_punches']['eid'] = array(
    'title' => t('Employee ID'),
    'help' => t('Employee ID number'),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument',
    ),
    'relationship' => array(
      'base' => 'timeclock_employees',
      'field' => 'eid',
      'handler' => 'views_handler_relationship',
      'skip base' => 'timeclock_employees',
      'label' => t('Employee'),
    ),
  );
  $data['timeclock_punches']['timestamp'] = array(
    'title' => t('Punch Timestamp'),
    'help' => t('Original timestamp for punch, may have been overridden by edits table.'),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
      'label' => t('TimeStamp'),
    ),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
  );
  $data['timeclock_punches']['in_out'] = array(
    'title' => t('Punch in or out'),
    'help' => t('Was this a punch in our a punch out.'),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('Clocking In'),
      'type' => 'yes-no',
    ),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument',
    ),
  );
  $data['timeclock_punches']['method'] = array(
    'title' => t('Punch Method'),
    'help' => t('Sub-Module that processed the punch'),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
      'label' => t('Method'),
    ),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['timeclock_punches']['failure_code'] = array(
    'title' => t('Failure Code'),
    'help' => t('Code number for failing punch validation'),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
      'label' => t('Method'),
    ),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['timeclock_punches']['failure_module'] = array(
    'title' => t('Failure Modules'),
    'help' => t('Module name for failing punch validation'),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
      'label' => t('Failure Module'),
    ),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  // Describe timeclock_punches_edits to views.
  $data['timeclock_punches_edits']['table']['group'] = t('Timeclock Edited Punches');
  $data['timeclock_punches_edits']['table']['base'] = array(
    'field' => 'pid',
    'title' => 'TimeClock Edited Punches',
    'weight' => 5,
    'access query tag' => 'view timeclock punches'
  );
  $data['timeclock_punches_edits']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid',
    ),
    'timeclock_punches' => array(
      'left_field' => 'pid',
      'field' => 'pid',
    ),
  );
  $data['timeclock_punches_edits']['pid'] = array(
    'title' => t('Unique Punch ID'),
    'help' => t('Punch Identifier Number'),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument',
    ),
    'relationship' => array(
      'base' => 'timeclock_punches',
      'field' => 'pid',
      'handler' => 'views_handler_relationship',
      'skip base' => 'timeclock_punches',
      'label' => t('Punch Edits'),
    ),
  );
  $data['timeclock_punches_edits']['memo'] = array(
    'title' => t('Edit Memo'),
    'help' => t('Required notes when modifying a punch'),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
      'label' => t('Method'),
    ),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
    $data['timeclock_punches']['uid'] = array(
    'title' => t('User ID of user editing punch'),
    'help' => t('The user ID of the user who edited the punch'),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument',
    ),
    'relationship' => array(
      'base' => 'users',
      'field' => 'uid',
      'handler' => 'views_handler_relationship',
      'skip base' => 'users',
      'label' => t('User'),
    ),
  );
  $data['timeclock_punches_edits']['edit_timestamp'] = array(
    'title' => t('Edited Timestamp'),
    'help' => t('Edited timestamp for punch.'),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
      'label' => t('TimeStamp'),
    ),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
  );
return $data;
}
