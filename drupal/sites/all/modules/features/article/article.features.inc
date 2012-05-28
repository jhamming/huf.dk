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
      'name' => t('Artikel'),
      'base' => 'node_content',
      'description' => t('Brug <em>artikler</em> til tidsfølsomt indhold som nyheder, pressemeddelelser eller blogindlæg.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
