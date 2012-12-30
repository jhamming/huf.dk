<?php
/**
 * @file
 * huf_user.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function huf_user_context_default_contexts() {
  $export = array();

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
