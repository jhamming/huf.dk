<?php
/**
 * @file
 * huf_frontpage.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function huf_frontpage_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'frontpage';
  $context->description = 'Frontpage of huf.dk context';
  $context->tag = 'section';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
    'user' => array(
      'values' => array(
        'Bestyrelse' => 'Bestyrelse',
        'administrator' => 'administrator',
        'authenticated user' => 'authenticated user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-aktuelt-block' => array(
          'module' => 'views',
          'delta' => 'aktuelt-block',
          'region' => 'preblocks',
          'weight' => '-10',
        ),
        'user-login' => array(
          'module' => 'user',
          'delta' => 'login',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'views-gallery_slideshow-block' => array(
          'module' => 'views',
          'delta' => 'gallery_slideshow-block',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'newsletter-newsletter_subscribe' => array(
          'module' => 'newsletter',
          'delta' => 'newsletter_subscribe',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'block-2' => array(
          'module' => 'block',
          'delta' => '2',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'panels_mini-statistik' => array(
          'module' => 'panels_mini',
          'delta' => 'statistik',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'panels_mini-kalender_og_kommende' => array(
          'module' => 'panels_mini',
          'delta' => 'kalender_og_kommende',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'panels_mini-nyeste_indhold' => array(
          'module' => 'panels_mini',
          'delta' => 'nyeste_indhold',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Frontpage of huf.dk context');
  t('section');
  $export['frontpage'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'frontpage_anonymus';
  $context->description = 'Frontpage of huf.dk context for anonymus users';
  $context->tag = 'section';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
    'user' => array(
      'values' => array(
        'anonymous user' => 'anonymous user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'user-login' => array(
          'module' => 'user',
          'delta' => 'login',
          'region' => 'sidebar_first',
          'weight' => '-25',
        ),
        'newsletter-newsletter_subscribe' => array(
          'module' => 'newsletter',
          'delta' => 'newsletter_subscribe',
          'region' => 'sidebar_first',
          'weight' => '-23',
        ),
        'block-2' => array(
          'module' => 'block',
          'delta' => '2',
          'region' => 'sidebar_first',
          'weight' => '-22',
        ),
        'panels_mini-statistik' => array(
          'module' => 'panels_mini',
          'delta' => 'statistik',
          'region' => 'sidebar_first',
          'weight' => '-21',
        ),
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'panels_mini-kalender_og_kommende' => array(
          'module' => 'panels_mini',
          'delta' => 'kalender_og_kommende',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'views-gallery_slideshow-block' => array(
          'module' => 'views',
          'delta' => 'gallery_slideshow-block',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Frontpage of huf.dk context for anonymus users');
  t('section');
  $export['frontpage_anonymus'] = $context;

  return $export;
}
