<?php
/**
 * @file
 * huf_frontpage.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function huf_frontpage_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:afholdte_arrangementer
  $menu_links['main-menu:afholdte_arrangementer'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'afholdte_arrangementer',
    'router_path' => 'afholdte_arrangementer',
    'link_title' => 'Afholdte arrangementer',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-7',
    'parent_path' => 'calendar-node-field-dato',
  );
  // Exported menu link: main-menu:calendar-node-field-dato
  $menu_links['main-menu:calendar-node-field-dato'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'calendar-node-field-dato',
    'router_path' => 'calendar-node-field-dato',
    'link_title' => 'Arrangementer',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '1',
    'weight' => '-48',
  );
  // Exported menu link: main-menu:forum
  $menu_links['main-menu:forum'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'forum',
    'router_path' => 'forum',
    'link_title' => 'Forum',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-44',
  );
  // Exported menu link: main-menu:gallerier
  $menu_links['main-menu:gallerier'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'gallerier',
    'router_path' => 'gallerier',
    'link_title' => 'Galleri',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-5',
    'parent_path' => 'calendar-node-field-dato',
  );
  // Exported menu link: main-menu:group-list
  $menu_links['main-menu:group-list'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'group-list',
    'router_path' => 'group-list',
    'link_title' => 'Medlemmer',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Exported menu link: main-menu:node/1858
  $menu_links['main-menu:node/1858'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/1858',
    'router_path' => 'node/%',
    'link_title' => 'Om huf',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-43',
  );
  // Exported menu link: main-menu:nyheder
  $menu_links['main-menu:nyheder'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'nyheder',
    'router_path' => 'nyheder',
    'link_title' => 'Nyheder',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Exported menu link: main-menu:taxonomy/term/756
  $menu_links['main-menu:taxonomy/term/756'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/756',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Artikler',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-46',
  );
  // Exported menu link: main-menu:taxonomy/term/757
  $menu_links['main-menu:taxonomy/term/757'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/757',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Udgivelser',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-45',
  );
  // Exported menu link: main-menu:tekster
  $menu_links['main-menu:tekster'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'tekster',
    'router_path' => 'tekster',
    'link_title' => 'Tekster',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-47',
  );
  // Exported menu link: menu-arrangementer:begivenheder
  $menu_links['menu-arrangementer:begivenheder'] = array(
    'menu_name' => 'menu-arrangementer',
    'link_path' => 'begivenheder',
    'router_path' => 'begivenheder',
    'link_title' => 'Arrangementer',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Afholdte arrangementer');
  t('Arrangementer');
  t('Artikler');
  t('Forum');
  t('Galleri');
  t('Medlemmer');
  t('Nyheder');
  t('Om huf');
  t('Tekster');
  t('Udgivelser');


  return $menu_links;
}
