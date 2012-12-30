<?php
/**
 * @file
 * huf_nyhed.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function huf_nyhed_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'nyheder';
  $context->description = 'All pages concerning news from huf.dk';
  $context->tag = 'section';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'event' => 'event',
        'nyhed' => 'nyhed',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        '/nyheder/*' => '/nyheder/*',
      ),
    ),
    'views' => array(
      'values' => array(
        'comments_recent' => 'comments_recent',
        'comments_recent:page' => 'comments_recent:page',
        'forside_seneste_nyt:page_1' => 'forside_seneste_nyt:page_1',
        'nyheder' => 'nyheder',
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
        'views-nyheder-block_1' => array(
          'module' => 'views',
          'delta' => 'nyheder-block_1',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'newsletter-newsletter_subscribe' => array(
          'module' => 'newsletter',
          'delta' => 'newsletter_subscribe',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'tagclouds-2' => array(
          'module' => 'tagclouds',
          'delta' => '2',
          'region' => 'sidebar_second',
          'weight' => '-5',
        ),
        'views-nyheder-block' => array(
          'module' => 'views',
          'delta' => 'nyheder-block',
          'region' => 'sidebar_second',
          'weight' => '-4',
        ),
        'facebook_boxes-fb_like' => array(
          'module' => 'facebook_boxes',
          'delta' => 'fb_like',
          'region' => 'sidebar_second',
          'weight' => '-1',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('All pages concerning news from huf.dk');
  t('section');
  $export['nyheder'] = $context;

  return $export;
}
