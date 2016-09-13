<?php
/**
 * @file
 * punchclock.features.menu_links.inc
 */

/**
 * Implementation of hook_menu_default_menu_links().
 */
function punchclock_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: management:punchclock
  $menu_links['management:punchclock'] = array(
    'menu_name' => 'management',
    'link_path' => 'punchclock',
    'router_path' => 'punchclock',
    'link_title' => 'Punch Clock',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Punch Clock');


  return $menu_links;
}
