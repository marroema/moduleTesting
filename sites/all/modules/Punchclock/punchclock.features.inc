<?php
/**
 * @file
 * punchclock.features.inc
 */

/**
 * Implementation of hook_node_info().
 */
function punchclock_node_info() {
  $items = array(
    'shift' => array(
      'name' => t('Shift'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Short Description'),
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function punchclock_views_api() {
  return array(
    'api' => '3.0',
  );
}
