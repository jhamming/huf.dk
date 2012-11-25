<?php
/**
 * @file
 * huf_gallery.features.inc
 */

/**
 * Implements hook_node_info().
 */
function huf_gallery_node_info() {
  $items = array(
    'gallery' => array(
      'name' => t('Gallery'),
      'base' => 'node_content',
      'description' => t('Content type for galleries'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
