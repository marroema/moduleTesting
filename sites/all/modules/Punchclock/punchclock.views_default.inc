<?php
/**
 * @file
 * punchclock.views_default.inc
 */

/**
 * Implementation of hook_views_default_views().
 */
function punchclock_views_default_views() {
  $views = array();

  // Exported view: punchclock_status
  $view = new view;
  $view->name = 'punchclock_status';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Punchclock Status';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Punched In';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view punches';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['external'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['picture']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['picture']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['html'] = 0;
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['picture']['hide_empty'] = 0;
  $handler->display->display_options['fields']['picture']['empty_zero'] = 0;
  $handler->display->display_options['fields']['picture']['hide_alter_empty'] = 0;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  /* Sort criterion: User: Last access */
  $handler->display->display_options['sorts']['access']['id'] = 'access';
  $handler->display->display_options['sorts']['access']['table'] = 'users';
  $handler->display->display_options['sorts']['access']['field'] = 'access';
  $handler->display->display_options['sorts']['access']['order'] = 'DESC';
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid_1']['id'] = 'rid_1';
  $handler->display->display_options['filters']['rid_1']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid_1']['field'] = 'rid';
  $handler->display->display_options['filters']['rid_1']['value'] = array(
    4 => '4',
    5 => '5',
  );
  $handler->display->display_options['filters']['rid_1']['reduce_duplicates'] = 1;

  /* Display: Employee Punch Status */
  $handler = $view->new_display('page', 'Employee Punch Status', 'punch_status');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Punch Status';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Punched In */
  $handler->display->display_options['fields']['field_punch_status']['id'] = 'field_punch_status';
  $handler->display->display_options['fields']['field_punch_status']['table'] = 'field_data_field_punch_status';
  $handler->display->display_options['fields']['field_punch_status']['field'] = 'field_punch_status';
  $handler->display->display_options['fields']['field_punch_status']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_punch_status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_punch_status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_punch_status']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_punch_status']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_punch_status']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_punch_status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_punch_status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_punch_status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_punch_status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_punch_status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_punch_status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_punch_status']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_punch_status']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_punch_status']['empty'] = 'Out';
  $handler->display->display_options['fields']['field_punch_status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_punch_status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_punch_status']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_punch_status']['field_api_classes'] = 0;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['external'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['picture']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['picture']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['html'] = 0;
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['picture']['hide_empty'] = 0;
  $handler->display->display_options['fields']['picture']['empty_zero'] = 0;
  $handler->display->display_options['fields']['picture']['hide_alter_empty'] = 0;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  $handler->display->display_options['fields']['name']['format_username'] = 1;
  /* Field: User: Tasks */
  $handler->display->display_options['fields']['field_punch_tasks']['id'] = 'field_punch_tasks';
  $handler->display->display_options['fields']['field_punch_tasks']['table'] = 'field_data_field_punch_tasks';
  $handler->display->display_options['fields']['field_punch_tasks']['field'] = 'field_punch_tasks';
  $handler->display->display_options['fields']['field_punch_tasks']['label'] = 'Next 5 Tasks';
  $handler->display->display_options['fields']['field_punch_tasks']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_punch_tasks']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_punch_tasks']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_punch_tasks']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_punch_tasks']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_punch_tasks']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_punch_tasks']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_punch_tasks']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_punch_tasks']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_punch_tasks']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_punch_tasks']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_punch_tasks']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_punch_tasks']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_punch_tasks']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_punch_tasks']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_punch_tasks']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_punch_tasks']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_punch_tasks']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_punch_tasks']['delta_limit'] = '5';
  $handler->display->display_options['fields']['field_punch_tasks']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_punch_tasks']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_punch_tasks']['multi_type'] = 'ol';
  $handler->display->display_options['fields']['field_punch_tasks']['field_api_classes'] = 0;
  /* Field: User: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['external'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['edit_node']['hide_alter_empty'] = 0;
  $handler->display->display_options['path'] = 'punchclock/status';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Punch Status';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Punch Clock';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';

  /* Display: Punched In */
  $handler = $view->new_display('block', 'Punched In', 'punch_block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Currently Punched In';
  $handler->display->display_options['display_description'] = 'Punched In';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['external'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['picture']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['picture']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['html'] = 0;
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['picture']['hide_empty'] = 0;
  $handler->display->display_options['fields']['picture']['empty_zero'] = 0;
  $handler->display->display_options['fields']['picture']['hide_alter_empty'] = 0;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  $handler->display->display_options['fields']['name']['format_username'] = 1;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid_1']['id'] = 'rid_1';
  $handler->display->display_options['filters']['rid_1']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid_1']['field'] = 'rid';
  $handler->display->display_options['filters']['rid_1']['value'] = array(
    4 => '4',
    5 => '5',
  );
  $handler->display->display_options['filters']['rid_1']['reduce_duplicates'] = 1;
  /* Filter criterion: User: Punched In (field_punch_status) */
  $handler->display->display_options['filters']['field_punch_status_value']['id'] = 'field_punch_status_value';
  $handler->display->display_options['filters']['field_punch_status_value']['table'] = 'field_data_field_punch_status';
  $handler->display->display_options['filters']['field_punch_status_value']['field'] = 'field_punch_status_value';
  $handler->display->display_options['filters']['field_punch_status_value']['value'] = array(
    1 => '1',
  );

  $views[$view->name] = $view;

  // Exported view: punchlog
  $view = new view;
  $view->name = 'punchlog';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Punch Log';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Punch Log by Shift';
  $handler->display->display_options['css_class'] = 'total';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view punches';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_punch_start' => 'field_punch_start',
    'field_punch_duration' => 'field_punch_duration',
    'field_punch_activity' => 'field_punch_activity',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_punch_start' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_punch_duration' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_punch_activity' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Add new shift link';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  $handler->display->display_options['header']['area']['content'] = '<?php
print l("Add a new shift...", \'node/add/shift\');
?><br />';
  $handler->display->display_options['header']['area']['format'] = 'php_code';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['label'] = 'Total Tme';
  $handler->display->display_options['footer']['area']['empty'] = FALSE;
  $handler->display->display_options['footer']['area']['content'] = '<?php
   $view = views_get_current_view();
   $duration = 0;
   foreach ($view->result as $row) {
     $duration += $row->field_field_punch_duration[0][\'raw\'][\'value\'];
   }
$hours = floor($duration/60);
$minutes = $duration%60;
$display_output = "$hours hours, $minutes minutes";
print $display_output;
?>';
  $handler->display->display_options['footer']['area']['format'] = 'php_code';
  $handler->display->display_options['footer']['area']['tokenize'] = 0;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = 1;
  /* Relationship: Field: Activity (field_punch_activity) */
  $handler->display->display_options['relationships']['field_punch_activity_tid']['id'] = 'field_punch_activity_tid';
  $handler->display->display_options['relationships']['field_punch_activity_tid']['table'] = 'field_data_field_punch_activity';
  $handler->display->display_options['relationships']['field_punch_activity_tid']['field'] = 'field_punch_activity_tid';
  $handler->display->display_options['relationships']['field_punch_activity_tid']['required'] = 1;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['relationship'] = 'uid';
  $handler->display->display_options['fields']['picture']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['external'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['picture']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['picture']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['html'] = 0;
  $handler->display->display_options['fields']['picture']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['picture']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['picture']['hide_empty'] = 1;
  $handler->display->display_options['fields']['picture']['empty_zero'] = 0;
  $handler->display->display_options['fields']['picture']['hide_alter_empty'] = 0;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  $handler->display->display_options['fields']['name']['format_username'] = 1;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Field: Punch in time */
  $handler->display->display_options['fields']['field_punch_start']['id'] = 'field_punch_start';
  $handler->display->display_options['fields']['field_punch_start']['table'] = 'field_data_field_punch_start';
  $handler->display->display_options['fields']['field_punch_start']['field'] = 'field_punch_start';
  $handler->display->display_options['fields']['field_punch_start']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_punch_start']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_punch_start']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_punch_start']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_punch_start']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_punch_start']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_punch_start']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_punch_start']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_punch_start']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_punch_start']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_punch_start']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_punch_start']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_punch_start']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_punch_start']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_punch_start']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_punch_start']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_punch_start']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_punch_start']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_punch_start']['field_api_classes'] = 0;
  /* Field: Content: Duration */
  $handler->display->display_options['fields']['field_punch_duration']['id'] = 'field_punch_duration';
  $handler->display->display_options['fields']['field_punch_duration']['table'] = 'field_data_field_punch_duration';
  $handler->display->display_options['fields']['field_punch_duration']['field'] = 'field_punch_duration';
  $handler->display->display_options['fields']['field_punch_duration']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_punch_duration']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_punch_duration']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_punch_duration']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_punch_duration']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_punch_duration']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_punch_duration']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_punch_duration']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_punch_duration']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_punch_duration']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_punch_duration']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_punch_duration']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_punch_duration']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_punch_duration']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_punch_duration']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_punch_duration']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_punch_duration']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_punch_duration']['field_api_classes'] = 0;
  /* Field: Field: Activity */
  $handler->display->display_options['fields']['field_punch_activity']['id'] = 'field_punch_activity';
  $handler->display->display_options['fields']['field_punch_activity']['table'] = 'field_data_field_punch_activity';
  $handler->display->display_options['fields']['field_punch_activity']['field'] = 'field_punch_activity';
  $handler->display->display_options['fields']['field_punch_activity']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_punch_activity']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_punch_activity']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_punch_activity']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_punch_activity']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_punch_activity']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_punch_activity']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_punch_activity']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_punch_activity']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_punch_activity']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_punch_activity']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_punch_activity']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_punch_activity']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_punch_activity']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_punch_activity']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_punch_activity']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_punch_activity']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_punch_activity']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_punch_activity']['field_api_classes'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'shift' => 'shift',
  );
  $handler->display->display_options['filters']['type']['group'] = 0;
  /* Filter criterion: Field: Punch in time (field_punch_start) */
  $handler->display->display_options['filters']['field_punch_start_value']['id'] = 'field_punch_start_value';
  $handler->display->display_options['filters']['field_punch_start_value']['table'] = 'field_data_field_punch_start';
  $handler->display->display_options['filters']['field_punch_start_value']['field'] = 'field_punch_start_value';
  $handler->display->display_options['filters']['field_punch_start_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_punch_start_value']['group'] = 0;
  $handler->display->display_options['filters']['field_punch_start_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_punch_start_value']['expose']['operator_id'] = 'field_punch_start_value_op';
  $handler->display->display_options['filters']['field_punch_start_value']['expose']['label'] = 'Punch in time';
  $handler->display->display_options['filters']['field_punch_start_value']['expose']['use_operator'] = 1;
  $handler->display->display_options['filters']['field_punch_start_value']['expose']['operator'] = 'field_punch_start_value_op';
  $handler->display->display_options['filters']['field_punch_start_value']['expose']['identifier'] = 'field_punch_start_value';
  $handler->display->display_options['filters']['field_punch_start_value']['expose']['multiple'] = FALSE;
  $handler->display->display_options['filters']['field_punch_start_value']['granularity'] = 'minute';
  $handler->display->display_options['filters']['field_punch_start_value']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_punch_start_value']['default_date'] = '-14 days';
  $handler->display->display_options['filters']['field_punch_start_value']['year_range'] = '-3:+1';
  /* Filter criterion: Content: Punched Out Time (field_punch_end) */
  $handler->display->display_options['filters']['field_punch_end_value']['id'] = 'field_punch_end_value';
  $handler->display->display_options['filters']['field_punch_end_value']['table'] = 'field_data_field_punch_end';
  $handler->display->display_options['filters']['field_punch_end_value']['field'] = 'field_punch_end_value';
  $handler->display->display_options['filters']['field_punch_end_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_punch_end_value']['group'] = 0;
  $handler->display->display_options['filters']['field_punch_end_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_punch_end_value']['expose']['operator_id'] = 'field_punch_end_value_op';
  $handler->display->display_options['filters']['field_punch_end_value']['expose']['label'] = 'Punch Out Time';
  $handler->display->display_options['filters']['field_punch_end_value']['expose']['use_operator'] = 1;
  $handler->display->display_options['filters']['field_punch_end_value']['expose']['operator'] = 'field_punch_end_value_op';
  $handler->display->display_options['filters']['field_punch_end_value']['expose']['identifier'] = 'field_punch_end_value';
  $handler->display->display_options['filters']['field_punch_end_value']['expose']['multiple'] = FALSE;
  $handler->display->display_options['filters']['field_punch_end_value']['granularity'] = 'minute';
  $handler->display->display_options['filters']['field_punch_end_value']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_punch_end_value']['default_date'] = 'now';
  $handler->display->display_options['filters']['field_punch_end_value']['year_range'] = '-3:+1';
  /* Filter criterion: Field: Activity (field_punch_activity) */
  $handler->display->display_options['filters']['field_punch_activity_tid']['id'] = 'field_punch_activity_tid';
  $handler->display->display_options['filters']['field_punch_activity_tid']['table'] = 'field_data_field_punch_activity';
  $handler->display->display_options['filters']['field_punch_activity_tid']['field'] = 'field_punch_activity_tid';
  $handler->display->display_options['filters']['field_punch_activity_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_punch_activity_tid']['expose']['operator_id'] = 'field_punch_activity_tid_op';
  $handler->display->display_options['filters']['field_punch_activity_tid']['expose']['label'] = 'Activity';
  $handler->display->display_options['filters']['field_punch_activity_tid']['expose']['operator'] = 'field_punch_activity_tid_op';
  $handler->display->display_options['filters']['field_punch_activity_tid']['expose']['identifier'] = 'field_punch_activity_tid';
  $handler->display->display_options['filters']['field_punch_activity_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_punch_activity_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_punch_activity_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_punch_activity_tid']['vocabulary'] = 'punchclock_activities';
  $handler->display->display_options['filters']['field_punch_activity_tid']['error_message'] = 1;

  /* Display: Punch Log */
  $handler = $view->new_display('page', 'Punch Log', 'punchlog');
  $handler->display->display_options['path'] = 'punchclock/punchlog';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Punch Log';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';

  $views[$view->name] = $view;

  return $views;
}
