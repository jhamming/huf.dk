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
    'node' => array(
      'values' => array(
        'event' => 'event',
        'gallery' => 'gallery',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'views' => array(
      'values' => array(
        'calendar' => 'calendar',
        'calendar:page' => 'calendar:page',
        'calendar:page_1' => 'calendar:page_1',
        'calendar:page_2' => 'calendar:page_2',
        'calendar:page_3' => 'calendar:page_3',
        'gallery' => 'gallery',
        'gallery:page' => 'gallery:page',
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
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('All pages concerning news from huf.dk');
  t('section');
  $export['calendar'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'forum';
  $context->description = 'Kontekst til forumsider';
  $context->tag = 'section';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'forum' => 'forum',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'forum*' => 'forum*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'user-login' => array(
          'module' => 'user',
          'delta' => 'login',
          'region' => 'sidebar_second',
          'weight' => '-41',
        ),
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'sidebar_second',
          'weight' => '-40',
        ),
        'views-forum-block' => array(
          'module' => 'views',
          'delta' => 'forum-block',
          'region' => 'sidebar_second',
          'weight' => '-39',
        ),
        'views-forum-block_1' => array(
          'module' => 'views',
          'delta' => 'forum-block_1',
          'region' => 'sidebar_second',
          'weight' => '-38',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Kontekst til forumsider');
  t('section');
  $export['forum'] = $context;

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
        'block-1' => array(
          'module' => 'block',
          'delta' => '1',
          'region' => 'preblocks',
          'weight' => '-10',
        ),
        'user-login' => array(
          'module' => 'user',
          'delta' => 'login',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'newsletter-newsletter_subscribe' => array(
          'module' => 'newsletter',
          'delta' => 'newsletter_subscribe',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'panels_mini-kalender_og_kommende' => array(
          'module' => 'panels_mini',
          'delta' => 'kalender_og_kommende',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'views-gallery_slideshow-block' => array(
          'module' => 'views',
          'delta' => 'gallery_slideshow-block',
          'region' => 'sidebar_second',
          'weight' => '-6',
        ),
        'panels_mini-nyeste_indhold' => array(
          'module' => 'panels_mini',
          'delta' => 'nyeste_indhold',
          'region' => 'sidebar_second',
          'weight' => '-5',
        ),
        'panels_mini-statistik' => array(
          'module' => 'panels_mini',
          'delta' => 'statistik',
          'region' => 'sidebar_second',
          'weight' => '-4',
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
    'user' => array(
      'values' => array(
        'anonymous user' => 'anonymous user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-2' => array(
          'module' => 'block',
          'delta' => '2',
          'region' => 'preblocks',
          'weight' => '-10',
        ),
        'user-login' => array(
          'module' => 'user',
          'delta' => 'login',
          'region' => 'sidebar_first',
          'weight' => '-45',
        ),
        'panels_mini-kalender_og_kommende' => array(
          'module' => 'panels_mini',
          'delta' => 'kalender_og_kommende',
          'region' => 'sidebar_first',
          'weight' => '-44',
        ),
        'newsletter-newsletter_subscribe' => array(
          'module' => 'newsletter',
          'delta' => 'newsletter_subscribe',
          'region' => 'sidebar_first',
          'weight' => '-43',
        ),
      ),
    ),
    'region' => array(
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
      'touchpro' => array(
        'disable' => array(
          'sidebar_second' => 'sidebar_second',
          'header' => 0,
          'featured' => 0,
          'preblocks' => 0,
          'sidebar_first' => 0,
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
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Frontpage of huf.dk context for anonymus users');
  t('section');
  $export['frontpage_anonymus'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'omhuf';
  $context->description = 'Kontekst til Om Huf siderne';
  $context->tag = 'section';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        761 => 761,
      ),
      'options' => array(
        'node_form' => '1',
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
        'block-8' => array(
          'module' => 'block',
          'delta' => '8',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'block-9' => array(
          'module' => 'block',
          'delta' => '9',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'panels_mini-kalender_og_kommende' => array(
          'module' => 'panels_mini',
          'delta' => 'kalender_og_kommende',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'block-5' => array(
          'module' => 'block',
          'delta' => '5',
          'region' => 'sidebar_second',
          'weight' => '-6',
        ),
        'webform-client-block-100010245' => array(
          'module' => 'webform',
          'delta' => 'client-block-100010245',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Kontekst til Om Huf siderne');
  t('section');
  $export['omhuf'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'tekster';
  $context->description = 'All pages concerning text content from huf.dk';
  $context->tag = 'section';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '*/tekster*' => '*/tekster*',
        '*taxonomy*' => '*taxonomy*',
      ),
    ),
    'views' => array(
      'values' => array(
        'seneste_tekster' => 'seneste_tekster',
        'seneste_tekster:page' => 'seneste_tekster:page',
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
          'weight' => '-13',
        ),
        'views-seneste_tekster-block_2' => array(
          'module' => 'views',
          'delta' => 'seneste_tekster-block_2',
          'region' => 'sidebar_second',
          'weight' => '-8',
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
        'panels_mini-nyeste_indhold' => array(
          'module' => 'panels_mini',
          'delta' => 'nyeste_indhold',
          'region' => 'sidebar_second',
          'weight' => '-1',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('All pages concerning text content from huf.dk');
  t('section');
  $export['tekster'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'tekster_underside';
  $context->description = 'All pages concerning texts from huf.dk';
  $context->tag = 'section';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'article' => 'article',
      ),
      'options' => array(
        'node_form' => '1',
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
          'weight' => '-11',
        ),
        'views-seneste_tekster-block_3' => array(
          'module' => 'views',
          'delta' => 'seneste_tekster-block_3',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-seneste_tekster-block_2' => array(
          'module' => 'views',
          'delta' => 'seneste_tekster-block_2',
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
        'panels_mini-nyeste_indhold' => array(
          'module' => 'panels_mini',
          'delta' => 'nyeste_indhold',
          'region' => 'sidebar_second',
          'weight' => '-1',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('All pages concerning texts from huf.dk');
  t('section');
  $export['tekster_underside'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'udgivelser';
  $context->description = 'All pages concerning publications from huf.dk';
  $context->tag = 'section';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        757 => 757,
        760 => 760,
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        '*/done*' => '*/done*',
        'udgivelser*' => 'udgivelser*',
        'medlemsboeger*' => 'medlemsboeger*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-5' => array(
          'module' => 'block',
          'delta' => '5',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'block-6' => array(
          'module' => 'block',
          'delta' => '6',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'webform-client-block-100010242' => array(
          'module' => 'webform',
          'delta' => 'client-block-100010242',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('All pages concerning publications from huf.dk');
  t('section');
  $export['udgivelser'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'user_sign_up';
  $context->description = 'Kontekst til opret bruger siden';
  $context->tag = 'section';
  $context->conditions = array(
    'user_page' => array(
      'values' => array(
        'register' => 'register',
      ),
      'options' => array(
        'mode' => 'all',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-3' => array(
          'module' => 'block',
          'delta' => '3',
          'region' => 'content_top',
          'weight' => '-10',
        ),
        'block-4' => array(
          'module' => 'block',
          'delta' => '4',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Kontekst til opret bruger siden');
  t('section');
  $export['user_sign_up'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'users';
  $context->description = 'User pages';
  $context->tag = 'section';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'users' => 'users',
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
          'weight' => '-15',
        ),
        'views-active_users-block' => array(
          'module' => 'views',
          'delta' => 'active_users-block',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-nyeste_medlemmer-block' => array(
          'module' => 'views',
          'delta' => 'nyeste_medlemmer-block',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'facebook_boxes-fb_like' => array(
          'module' => 'facebook_boxes',
          'delta' => 'fb_like',
          'region' => 'sidebar_second',
          'weight' => '-5',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('User pages');
  t('section');
  $export['users'] = $context;

  return $export;
}
