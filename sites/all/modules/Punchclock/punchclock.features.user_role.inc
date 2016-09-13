<?php
/**
 * @file
 * punchclock.features.user_role.inc
 */

/**
 * Implementation of hook_user_default_roles().
 */
function punchclock_user_default_roles() {
  $roles = array();

  // Exported role: Employee
  $roles['Employee'] = array(
    'name' => 'Employee',
    'weight' => '8',
  );

  // Exported role: Supervisor
  $roles['Supervisor'] = array(
    'name' => 'Supervisor',
    'weight' => '9',
  );

  return $roles;
}
