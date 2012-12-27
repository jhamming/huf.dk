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
  $context->name = 'calendar';
  $context->description = 'All pages concerning news from huf.dk';
  $context->tag = 'section';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'calendar' => 'calendar',
        'calendar:page' => 'calendar:page',
        'calendar:page_1' => 'calendar:page_1',
        'calendar:page_2' => 'calendar:page_2',
        'calendar:page_3' => 'calendar:page_3',
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
          'weight' => '-8',
        ),
        'views-calendar-block_4' => array(
          'module' => 'views',
          'delta' => 'calendar-block_4',
          'region' => 'content_bottom',
          'weight' => '-10',
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
      'touchpro_subtheme' => array(
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
          'footer_extra' => 0,
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
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('All pages concerning news from huf.dk');
  t('section');
  $export['calendar'] = $context;

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
          'weight' => '-9',
        ),
        'panels_mini-nyeste_indhold' => array(
          'module' => 'panels_mini',
          'delta' => 'nyeste_indhold',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'sidebar_second',
          'weight' => '-10',
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
