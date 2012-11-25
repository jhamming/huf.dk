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
        'forside_seneste_nyt:page_1' => 'forside_seneste_nyt:page_1',
        'nyheder' => 'nyheder',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'panels_mini-kalender_og_kommende' => array(
          'module' => 'panels_mini',
          'delta' => 'kalender_og_kommende',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'newsletter-newsletter_subscribe' => array(
          'module' => 'newsletter',
          'delta' => 'newsletter_subscribe',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'facebook_boxes-fb_like' => array(
          'module' => 'facebook_boxes',
          'delta' => 'fb_like',
          'region' => 'sidebar_second',
          'weight' => '-6',
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
      ),
    ),
    'region' => array(
      'arctica' => array(
        'disable' => array(
          'header' => 0,
          'featured' => 0,
          'preblocks' => 0,
          'sidebar_first' => 0,
          'sidebar_second' => 0,
          'content_top' => 0,
          'help' => 0,
          'content' => 0,
          'content_bottom' => 0,
          'postblocks' => 0,
          'footer' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
      'bartik' => array(
        'disable' => array(
          'header' => 0,
          'help' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
          'highlighted' => 0,
          'featured' => 0,
          'content' => 0,
          'sidebar_first' => 0,
          'sidebar_second' => 0,
          'triptych_first' => 0,
          'triptych_middle' => 0,
          'triptych_last' => 0,
          'footer_firstcolumn' => 0,
          'footer_secondcolumn' => 0,
          'footer_thirdcolumn' => 0,
          'footer_fourthcolumn' => 0,
          'footer' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
      'responsive' => array(
        'disable' => array(
          'sidebar_first' => 0,
          'header' => 0,
          'front_welcome' => 0,
          'content' => 0,
          'content_top' => 0,
          'help' => 0,
          'footer' => 0,
          'footer_first' => 0,
          'footer_second' => 0,
          'footer_third' => 0,
          'footer_fourth' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
      'rubik' => array(
        'disable' => array(
          'content' => 0,
          'help' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
      'seven' => array(
        'disable' => array(
          'content' => 0,
          'help' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
          'sidebar_first' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
      'tao' => array(
        'disable' => array(
          'sidebar_first' => 0,
          'sidebar_second' => 0,
          'content' => 0,
          'header' => 0,
          'help' => 0,
          'footer' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
          'highlighted' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
      'touch' => array(
        'disable' => array(
          'sidebar_first' => 'sidebar_first',
          'search_box' => 0,
          'sidebar_second' => 0,
          'header' => 0,
          'highlighted' => 0,
          'content' => 0,
          'navigation' => 0,
          'help' => 0,
          'footer_first' => 0,
          'footer_second' => 0,
          'footer_third' => 0,
          'footer_fourth' => 0,
          'footer' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
      'touchpro' => array(
        'disable' => array(
          'sidebar_first' => 'sidebar_first',
          'header' => 0,
          'featured' => 0,
          'preblocks' => 0,
          'sidebar_second' => 0,
          'content_top' => 0,
          'help' => 0,
          'content' => 0,
          'content_bottom' => 0,
          'postblocks' => 0,
          'footer' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
      'tundra' => array(
        'disable' => array(
          'header' => 0,
          'featured' => 0,
          'preblocks' => 0,
          'sidebar_first' => 0,
          'sidebar_second' => 0,
          'content_top' => 0,
          'help' => 0,
          'content' => 0,
          'content_bottom' => 0,
          'postblocks' => 0,
          'footer' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
      'zen' => array(
        'disable' => array(
          'header' => 0,
          'navigation' => 0,
          'highlighted' => 0,
          'help' => 0,
          'content' => 0,
          'sidebar_first' => 0,
          'sidebar_second' => 0,
          'footer' => 0,
          'bottom' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
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
