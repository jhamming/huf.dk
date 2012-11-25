<?php
/**
 * @file
 * huf_nyhed.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function huf_nyhed_taxonomy_default_vocabularies() {
  return array(
    'nyhedskategorier' => array(
      'name' => 'Nyhedskategorier',
      'machine_name' => 'nyhedskategorier',
      'description' => 'Kategorier til nyhedsartikler',
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
