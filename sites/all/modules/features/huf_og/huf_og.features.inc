<?php
/**
 * @file
 * huf_og.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function huf_og_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_views_api().
 */
function huf_og_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function huf_og_node_info() {
  $items = array(
    'gruppe' => array(
      'name' => t('Gruppe'),
      'base' => 'node_content',
      'description' => t('Laver en gruppe af medlemmer'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
