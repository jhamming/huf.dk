<?php
/**
 * @file
 * huf_nyhed.features.inc
 */

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
