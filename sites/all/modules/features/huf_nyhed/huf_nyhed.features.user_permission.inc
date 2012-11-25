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

  // Exported permission: create nyhed content.
  $permissions['create nyhed content'] = array(
    'name' => 'create nyhed content',
    'roles' => array(
      0 => 'Bestyrelse',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any nyhed content.
  $permissions['delete any nyhed content'] = array(
    'name' => 'delete any nyhed content',
    'roles' => array(
      0 => 'Bestyrelse',
    ),
    'module' => 'node',
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

  return $permissions;
}
