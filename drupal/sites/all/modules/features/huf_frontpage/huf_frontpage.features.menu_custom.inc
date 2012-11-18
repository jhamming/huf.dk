<?php
/**
 * @file
 * huf_frontpage.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function huf_frontpage_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: main-menu.
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Hovedmenu',
    'description' => 'Menuen <em>Main</em> bruges på mange sites til at vise sitets overordnede sektioner, typisk i en navigationsbjælke i toppen af siden.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Hovedmenu');
  t('Menuen <em>Main</em> bruges på mange sites til at vise sitets overordnede sektioner, typisk i en navigationsbjælke i toppen af siden.');


  return $menus;
}
