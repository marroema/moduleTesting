<?php
/**
 * @file
 * punchclock.features.user_permission.inc
 */

/**
 * Implementation of hook_user_default_permissions().
 */
function punchclock_user_default_permissions() {
  $permissions = array();

  // Exported permission: delete any shift content
  $permissions['delete any shift content'] = array(
    'name' => 'delete any shift content',
    'roles' => array(
      0 => 'Supervisor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own shift content
  $permissions['delete own shift content'] = array(
    'name' => 'delete own shift content',
    'roles' => array(
      0 => 'Employee',
      1 => 'Supervisor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any shift content
  $permissions['edit any shift content'] = array(
    'name' => 'edit any shift content',
    'roles' => array(
      0 => 'Supervisor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit field_punch_activity
  $permissions['edit field_punch_activity'] = array(
    'name' => 'edit field_punch_activity',
    'roles' => array(
      0 => 'Supervisor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_punch_start
  $permissions['edit field_punch_start'] = array(
    'name' => 'edit field_punch_start',
    'roles' => array(
      0 => 'Supervisor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_punch_status
  $permissions['edit field_punch_status'] = array(
    'name' => 'edit field_punch_status',
    'roles' => array(
      0 => 'Supervisor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_punch_tasks
  $permissions['edit field_punch_tasks'] = array(
    'name' => 'edit field_punch_tasks',
    'roles' => array(
      0 => 'Supervisor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_punch_activity
  $permissions['edit own field_punch_activity'] = array(
    'name' => 'edit own field_punch_activity',
    'roles' => array(
      0 => 'Employee',
      1 => 'Supervisor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_punch_start
  $permissions['edit own field_punch_start'] = array(
    'name' => 'edit own field_punch_start',
    'roles' => array(
      0 => 'Employee',
      1 => 'Supervisor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_punch_tasks
  $permissions['edit own field_punch_tasks'] = array(
    'name' => 'edit own field_punch_tasks',
    'roles' => array(
      0 => 'Employee',
      1 => 'Supervisor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own shift content
  $permissions['edit own shift content'] = array(
    'name' => 'edit own shift content',
    'roles' => array(
      0 => 'Employee',
      1 => 'Supervisor',
    ),
    'module' => 'node',
  );

  // Exported permission: view field_punch_activity
  $permissions['view field_punch_activity'] = array(
    'name' => 'view field_punch_activity',
    'roles' => array(
      0 => 'Employee',
      1 => 'Supervisor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_punch_start
  $permissions['view field_punch_start'] = array(
    'name' => 'view field_punch_start',
    'roles' => array(
      0 => 'Employee',
      1 => 'Supervisor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_punch_status
  $permissions['view field_punch_status'] = array(
    'name' => 'view field_punch_status',
    'roles' => array(
      0 => 'Employee',
      1 => 'Supervisor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_punch_tasks
  $permissions['view field_punch_tasks'] = array(
    'name' => 'view field_punch_tasks',
    'roles' => array(
      0 => 'Employee',
      1 => 'Supervisor',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
