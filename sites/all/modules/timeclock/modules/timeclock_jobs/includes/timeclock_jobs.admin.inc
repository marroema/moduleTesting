<?php
/**
 * @file
 * The file for admin forms and functionality for the timeclock_jobs entity
 */

/**
 * Implements hook_form().
 */
function timeclock_jobs_form($form, &$form_state, $timeclock_jobs = NULL) {
  $form = array();

  $form['name'] = array(
    '#title' => t('Job Name'),
    '#type' => 'textfield',
    '#default_value' => isset($timeclock_jobs->name) ? $timeclock_jobs->name : '',
    '#description' => t('A descriptive name for the job or client.'),
    '#required' => TRUE,
    '#maxlength' => 255,
  );

  field_attach_form('timeclock_jobs', $timeclock_jobs, $form, $form_state);

  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => isset($timeclock_jobs->job_id) ? t('Update job') : t('Save job'),
    ),
    'delete_link' => array(
      '#markup' => isset($timeclock_jobs->job_id) ? l(t('Delete'), 'admin/content/jobs/manage/' . $timeclock_jobs->job_id . '/delete', array('attributes' => array('id' => array('timeclock_jobs-delete-' . $timeclock_jobs->job_id), 'class' => array('button remove')), 'query' => array('destination' => 'admin/content/jobs'))) : ''));
  return $form;
}

/**
 * Implements hook_form_validate().
 */
function timeclock_jobs_form_validate($form, &$form_state) {
}

/**
 * Implements hook_form_submit().
 */
function timeclock_jobs_form_submit($form, &$form_state) {
  $timeclock_jobs = entity_ui_form_submit_build_entity($form, $form_state);
  $timeclock_jobs->save();
  drupal_set_message(t('@job job has been saved.', array('@job' => $timeclock_jobs->name)));
  // $form_state['redirect'] = 'admin/content/jobs';
  $form_state['redirect'] = 'jobs/' . $timeclock_jobs->job_id;
}

/**
 * Confirmation before bulk deleting timeclock_jobs.
 */
function timeclock_jobs_bulk_delete($form, &$form_state, $job_ids) {
  $job_ids = explode('|', $job_ids);
  $timeclock_jobs = timeclock_jobs_load_multiple($job_ids);

  $form = array();
  $form_state['job_ids'] = $job_ids;

  $variables = array(
    'type' => 'ul',
    'items' => array(),
    'title' => '',
    'attributes' => array(),
  );

  foreach ($timeclock_jobs as $job) {
    $variables['items'][] = $job->job;
  }

  $form['summary'] = array(
    '#markup' => theme_item_list($variables),
  );

  return confirm_form($form, t('Delete all jobs?'), 'admin/content/jobs', t('Placeholder description'), t('Delete all'), t('Cancel'));
}

/**
 * Implements hook_submit().
 */
function timeclock_jobs_bulk_delete_submit($form, &$form_state) {
  $job_ids = $form_state['job_ids'];
  timeclock_jobs_delete_multiple($job_ids);

  drupal_set_message(t('jobs deleted'));
  drupal_goto('admin/content/jobs');
}
