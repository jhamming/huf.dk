<?php
/**
 * @file
 * huf_nyhed.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function huf_nyhed_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer huf_event registration.
  $permissions['administer huf_event registration'] = array(
    'name' => 'administer huf_event registration',
    'roles' => array(
      0 => 'Bestyrelse',
      1 => 'administrator',
    ),
    'module' => 'registration',
  );

  // Exported permission: administer own huf_event registration.
  $permissions['administer own huf_event registration'] = array(
    'name' => 'administer own huf_event registration',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'registration',
  );

  // Exported permission: administer registration.
  $permissions['administer registration'] = array(
    'name' => 'administer registration',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'registration',
  );

  // Exported permission: administer registration states.
  $permissions['administer registration states'] = array(
    'name' => 'administer registration states',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'registration',
  );

  // Exported permission: administer registration types.
  $permissions['administer registration types'] = array(
    'name' => 'administer registration types',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'registration',
  );

  // Exported permission: create huf_event registration.
  $permissions['create huf_event registration'] = array(
    'name' => 'create huf_event registration',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'registration',
  );

  // Exported permission: create huf_event registration other anonymous.
  $permissions['create huf_event registration other anonymous'] = array(
    'name' => 'create huf_event registration other anonymous',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'registration',
  );

  // Exported permission: create huf_event registration other users.
  $permissions['create huf_event registration other users'] = array(
    'name' => 'create huf_event registration other users',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'registration',
  );

  // Exported permission: create nyhed content.
  $permissions['create nyhed content'] = array(
    'name' => 'create nyhed content',
    'roles' => array(
      0 => 'Bestyrelse',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any huf_event registration.
  $permissions['delete any huf_event registration'] = array(
    'name' => 'delete any huf_event registration',
    'roles' => array(
      0 => 'Bestyrelse',
      1 => 'administrator',
    ),
    'module' => 'registration',
  );

  // Exported permission: delete any nyhed content.
  $permissions['delete any nyhed content'] = array(
    'name' => 'delete any nyhed content',
    'roles' => array(
      0 => 'Bestyrelse',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own huf_event registration.
  $permissions['delete own huf_event registration'] = array(
    'name' => 'delete own huf_event registration',
    'roles' => array(
      0 => 'Bestyrelse',
      1 => 'administrator',
    ),
    'module' => 'registration',
  );

  // Exported permission: delete own nyhed content.
  $permissions['delete own nyhed content'] = array(
    'name' => 'delete own nyhed content',
    'roles' => array(
      0 => 'Bestyrelse',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any nyhed content.
  $permissions['edit any nyhed content'] = array(
    'name' => 'edit any nyhed content',
    'roles' => array(
      0 => 'Bestyrelse',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own nyhed content.
  $permissions['edit own nyhed content'] = array(
    'name' => 'edit own nyhed content',
    'roles' => array(
      0 => 'Bestyrelse',
    ),
    'module' => 'node',
  );

  // Exported permission: update any huf_event registration.
  $permissions['update any huf_event registration'] = array(
    'name' => 'update any huf_event registration',
    'roles' => array(
      0 => 'Bestyrelse',
      1 => 'administrator',
    ),
    'module' => 'registration',
  );

  // Exported permission: update own huf_event registration.
  $permissions['update own huf_event registration'] = array(
    'name' => 'update own huf_event registration',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'registration',
  );

  // Exported permission: view huf_event registration.
  $permissions['view huf_event registration'] = array(
    'name' => 'view huf_event registration',
    'roles' => array(
      0 => 'Bestyrelse',
      1 => 'administrator',
    ),
    'module' => 'registration',
  );

  // Exported permission: view own huf_event registration.
  $permissions['view own huf_event registration'] = array(
    'name' => 'view own huf_event registration',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'registration',
  );

  return $permissions;
}
