<?php
/**
 * @file
 * article.features.inc
 */

/**
 * Implements hook_node_info().
 */
function article_node_info() {
  $items = array(
    'article' => array(
      'name' => t('Tekster'),
      'base' => 'node_content',
      'description' => t('Indholdstype til at skive tekster forfatter af HUFs medlemmer.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
