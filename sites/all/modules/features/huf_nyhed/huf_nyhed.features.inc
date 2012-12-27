<?php
/**
 * @file
 * huf_nyhed.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function huf_nyhed_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_views_api().
 */
function huf_nyhed_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function huf_nyhed_node_info() {
  $items = array(
    'event' => array(
      'name' => t('Arrangement'),
      'base' => 'node_content',
      'description' => t('Content type for calendar events'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'nyhed' => array(
      'name' => t('Nyhed'),
      'base' => 'node_content',
      'description' => t('Seneste nyt fra HUF'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implements hook_default_registration_state().
 */
function huf_nyhed_default_registration_state() {
  $items = array();
  $items['canceled'] = entity_import('registration_state', '{
    "name" : "canceled",
    "label" : "Canceled",
    "description" : "Registration was cancelled",
    "default_state" : "0",
    "active" : "0",
    "show_on_form" : "0",
    "weight" : "1",
    "rdf_mapping" : []
  }');
  $items['complete'] = entity_import('registration_state', '{
    "name" : "complete",
    "label" : "Complete",
    "description" : "Registration has been completed.",
    "default_state" : "1",
    "active" : "1",
    "show_on_form" : "0",
    "weight" : "1",
    "rdf_mapping" : []
  }');
  $items['pending'] = entity_import('registration_state', '{
    "name" : "pending",
    "label" : "Pending",
    "description" : "Registration is pending.",
    "default_state" : "0",
    "active" : "0",
    "show_on_form" : "0",
    "weight" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_registration_type().
 */
function huf_nyhed_default_registration_type() {
  $items = array();
  $items['huf_event'] = entity_import('registration_type', '{
    "name" : "huf_event",
    "label" : "Huf Event",
    "locked" : "0",
    "weight" : "0",
    "data" : null,
    "rdf_mapping" : []
  }');
  return $items;
}
