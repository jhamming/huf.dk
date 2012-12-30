<?php
/**
 * @file
 * huf_user.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function huf_user_taxonomy_default_vocabularies() {
  return array(
    'anonym_adgang' => array(
      'name' => 'Anonym adgang',
      'machine_name' => 'anonym_adgang',
      'description' => 'Ved at tildele dette tag, giver du anonyme brugere, altså ikke-medlemmer, adgang til at læse siden',
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
    'newsletter_categories' => array(
      'name' => 'Newsletter categories',
      'machine_name' => 'newsletter_categories',
      'description' => 'Vocabulary used to store the categories of newsletter lists',
      'hierarchy' => '0',
      'module' => 'newsletter',
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
    'stadie' => array(
      'name' => 'Stadie',
      'machine_name' => 'stadie',
      'description' => 'Stadie af færdiggørelse af tekster',
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
    'tekststadie' => array(
      'name' => 'Tekststadie',
      'machine_name' => 'tekststadie',
      'description' => 'Stadie af færdiggørelse af tekster',
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
