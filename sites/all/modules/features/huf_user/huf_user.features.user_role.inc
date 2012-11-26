<?php
/**
 * @file
 * huf_user.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function huf_user_user_default_roles() {
  $roles = array();

  // Exported role: Bestyrelse.
  $roles['Bestyrelse'] = array(
    'name' => 'Bestyrelse',
    'weight' => '2',
  );

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => '3',
  );

  return $roles;
}
