<?php
/**
 * @file
 * huf_nyhed.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function huf_nyhed_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_views_api().
 */
function huf_nyhed_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function huf_nyhed_node_info() {
  $items = array(
    'event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => t('Content type for calendar events'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'nyhed' => array(
      'name' => t('Nyhed'),
      'base' => 'node_content',
      'description' => t('Seneste nyt fra HUF'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
