<?php
/**
 * @file
 * huf_og.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function huf_og_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'grupper';
  $context->description = 'gruppe-side';
  $context->tag = 'section';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'og_list' => 'og_list',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'panels_mini-statistik' => array(
          'module' => 'panels_mini',
          'delta' => 'statistik',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'views-active_users-block' => array(
          'module' => 'views',
          'delta' => 'active_users-block',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'views-nyeste_medlemmer-block' => array(
          'module' => 'views',
          'delta' => 'nyeste_medlemmer-block',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'views-63268134c8e44815c81d3822c9584e62' => array(
          'module' => 'views',
          'delta' => '63268134c8e44815c81d3822c9584e62',
          'region' => 'content_top',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('gruppe-side');
  t('section');
  $export['grupper'] = $context;

  return $export;
}
