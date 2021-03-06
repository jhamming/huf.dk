<?php
/**
 * @file
 * huf_forum.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function huf_forum_taxonomy_default_vocabularies() {
  return array(
    'forums' => array(
      'name' => 'Forummer',
      'machine_name' => 'forums',
      'description' => 'Ordforråd til forumnavigation',
      'hierarchy' => '1',
      'module' => 'forum',
      'weight' => '-10',
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'forumtype' => array(
      'name' => 'Forumtype',
      'machine_name' => 'forumtype',
      'description' => 'Angiver forummets type (administrativt eller kreativt)',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
