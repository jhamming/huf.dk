<?php

/*
Implemented with inspiration from http://btmash.com/article/2011-03-02/migrating-content-part-1-users
*/

//const MY_MIGRATION_DATABASE_NAME = 'HUF_';
//const MY_MIGRATION_FORUM_DATABASE_NAME = 'TESTFORUM_';
abstract class HufMigration extends Migration {
  public function __construct() {
    // Always call the parent constructor first for basic setup
    parent::__construct();

    
  }
}

/**
 * There are four essential components to set up in your constructor:
 *  $this->source - An instance of a class derived from MigrateSource, this
 *    will feed data to the migration.
 *  $this->destination - An instance of a class derived from MigrateDestination,
 *    this will receive data that originated from the source and has been mapped
 *    by the Migration class, and create Drupal objects.
 *  $this->map - An instance of a class derived from MigrateMap, this will keep
 *    track of which source items have been imported and what destination objects
 *    they map to.
 *  Mappings - Use $this->addFieldMapping to tell the Migration class what source
 *    fields correspond to what destination fields, and additional information
 *    associated with the mappings.
 */

  class HufKategoriTermMigration extends HufMigration {
    public function __construct() {
      parent::__construct();
      // Human-friendly description of your migration process. Be as detailed as you
      // like.
      $this->description = t('Migrate categories from the HUF article database');

      // Create a map object for tracking the relationships between source rows
      // and their resulting Drupal objects. Usually, you'll use the MigrateSQLMap
      // class, which uses database tables for tracking. Pass the machine name
      // of this migration to use in generating map and message tables.
      // And, pass schema definitions for the primary keys of the source and
      // destination - we need to be explicit for our source, but the destination
      // class knows its schema already.
      $this->map = new MigrateSQLMap($this->machineName,
          array(
            'Kategori' => array('type' => 'varchar',
                             'length' => 255,
                             'not null' => TRUE,
                             'description' => 'Category ID',
                            )
          ),
          MigrateDestinationTerm::getKeySchema()
        );

      $query = db_select(MY_MIGRATION_DATABASE_NAME .'Story', 's')
               ->fields('s', array('Kategori'));
               

      // Create a MigrateSource object, which manages retrieving the input data.
      $this->source = new MigrateSourceSQL($query);

      // Set up our destination - terms in the migrate_example_beer_styles vocabulary
      $this->destination = new MigrateDestinationTerm('kategori');

      // Assign mappings TO destination fields FROM source fields. To discover
      // the names used in these calls, use the drush commands
      // drush migrate-fields-destination BeerTerm
      // drush migrate-fields-source BeerTerm
      $this->addFieldMapping('name', 'Kategori');
      }
  }
  

  class HufUserMigration extends HufMigration {
    public function __construct() {
      parent::__construct();
      $this->description = t('Migrate HUF users');
   
      $source_fields = array(
        'ID' => t('User ID'),
      );
   
      $query = db_select(MY_MIGRATION_DATABASE_NAME .'Users' , 'u')
        ->fields('u', array('ID','Brugernavn','Password','Email','Oprettet', 'Navn', 'Nick', 'Adresse', 'region', 'kommune', 'Alder', 'Tlf', 'Profil', 'lukket', 'seneste_indbetaling'))
        ->condition('u.Brugernavn', array('admin','webmaster'), 'NOT IN')
        ->condition('u.ID', 2, '>')
        ->orderBy('ID', 'ASC');
      $this->source = new MigrateSourceSQL($query, $source_fields);
      $this->destination = new MigrateDestinationUser();

      $this->map = new MigrateSQLMap($this->machineName,
        array(
          'ID' => array(
            'type' => 'int',
            'unsigned' => TRUE,
            'not null' => TRUE,
            'description' => 'Old Unique User ID',
            'alias' => 'u',
          )
        ),
        MigrateDestinationUser::getKeySchema()
      );
   
      // Make the mappings
      $this->addFieldMapping('is_new')->defaultValue(TRUE);
      $this->addFieldMapping(NULL, 'ID');
      $this->addFieldMapping('name', 'Brugernavn')->dedupe('users', 'name');
      $this->addFieldMapping('pass')->defaultValue('1234');
      //$this->addFieldMapping('mail', 'Email')->dedupe('users', 'mail');
      $this->addFieldMapping('language')->defaultValue('da');
      $this->addFieldMapping('theme')->defaultValue(NULL);
      $this->addFieldMapping('signature')->defaultValue(NULL);
      $this->addFieldMapping('signature_format')->defaultValue('filtered_html');
      $this->addFieldMapping('created', 'Oprettet');
      $this->addFieldMapping('access', NULL);
      $this->addFieldMapping('login', NULL);
      $this->addFieldMapping('status', 'lukket');
      //$this->addFieldMapping('picture')->defaultValue(0);
      $this->addFieldMapping('init', NULL);
      $this->addFieldMapping('mail', 'Email');
      $this->addFieldMapping('timezone')->defaultValue(NULL);
      $this->addFieldMapping('path')->issueGroup(t('DNM'));
      $this->addFieldMapping('roles')->defaultValue(2);
      $this->addFieldMapping('field_navn', 'Navn');
      $this->addFieldMapping('field_nick', 'Nick');
      $this->addFieldMapping('field_adresse', 'Adresse');
      $this->addFieldMapping('field_region', 'region');
      $this->addFieldMapping('field_kommune', 'kommune');
      $this->addFieldMapping('field_telefonnummer', 'Tlf');
      $this->addFieldMapping('field_profiltekst', 'Profil');
      $this->addFieldMapping('field_seneste_indbetaling', 'seneste_indbetaling')->callbacks(array($this, 'indbetalingCleanUp'));
      $this->addFieldMapping('field_f_dselsdato', 'Alder')->callbacks(array($this, 'debugging'));
      }

      protected function debugging($value) {
        $value = str_replace('/', '-', $value);
        //var_dump($value);die;
        return $value;
      }

      protected function indbetalingCleanUp($value) {
        $value = str_replace('0000-00-00', NULL, $value);
        return $value;
      }

      public function prepare(stdClass $account, stdClass $row) {
        
        //Flip the bit for wether a user is active
        switch ($row->lukket) {

          case 0;
            $account->status = 1;
            break;
          case 1;
            $account->status = 0;
            break;
          default;
            $account->status = 0;
            break;
        }

        /* Set the default created time to 2005-01-01
        to avoid it being set to now */
        switch ($row->Oprettet) {
          
          case '';
            $account->created = 1104559200;
            break;
          default;
            break;
        }
      
      }    
  }

  class HufArticleMigration extends HufMigration {
    /**
     * Class Constructor
     */
    public function __construct() {
        parent::__construct();
     
        $this->description = t('Migrate old articles');
        $this->dependencies = array('HufUser');
        $source_fields = array(
          'ID' => t('The node ID of the article'),
        //  'linked_files' => t('The set of linked files'),
        //  'right_side_images' => t('The set of images that previously appeared on the side'),
        );
     
        $query = db_select(MY_MIGRATION_DATABASE_NAME .'Story', 's')
          ->fields('s', array('ID', 'ejer_id', 'Note', 'kap','Rubrik', 'Text_', 'Dato', 'Chg', 'Kategori', 'samling', 'inaktiv'));

        $this->source = new MigrateSourceSQL($query, $source_fields);
        $this->destination = new MigrateDestinationNode('article');
     
        $this->map = new MigrateSQLMap($this->machineName,
          array(
            'ID' => array(
              'type' => 'int',
              'unsigned' => TRUE,
              'not null' => TRUE,
              'description' => 'Old Unique Node ID',
              'alias' => 's',
            )
          ),
          MigrateDestinationNode::getKeySchema()
        );
       // Make the mappings
        $this->addFieldMapping('title', 'Rubrik');
        $this->addFieldMapping('revision')->defaultValue(TRUE);
        $this->addFieldMapping('language')->defaultValue('da');
        $this->addFieldMapping('body:language')->defaultValue('da');
        $this->addFieldMapping('created', 'Dato');
        $this->addFieldMapping('changed', 'Dato');
        $this->addFieldMapping('body', 'Text_');
        $this->addFieldMapping('uid', 'ejer_id')
             ->sourceMigration('HufUser');
        $this->addFieldMapping('field_kategori', 'Kategori');
        $this->addFieldMapping('field_samling', 'samling');
        $this->addFieldMapping('field_samling:create_term')->defaultValue(TRUE);
        $this->addFieldMapping('field_note', 'Note');
        $this->addFieldMapping('field_kapitel', 'kap');
        $this->addFieldMapping('status', 'inaktiv');
        $this->addFieldMapping(NULL, 'ID');
      }
      public function prepare($account, $row) {
        //Getting rid of &#039; and other special chars
        $account->body['und'][0]['value'] = html_entity_decode(htmlspecialchars_decode(($account->body['und'][0]['value']), ENT_QUOTES));
        $unwantedchars = array('&#8221;', '&#8220;', '&#8222;', '&#8230');
        $wantedchars = array('”', '“', '„', '…');
        $account->body['und'][0]['value'] = str_replace($unwantedchars, $wantedchars, $account->body['und'][0]['value']); 

        $account->title = html_entity_decode(htmlspecialchars_decode(($account->title), ENT_QUOTES));
        $account->title = str_replace($unwantedchars, $wantedchars, $account->title); 

        switch ($row->inaktiv) {
          case 0;
            $account->status = 1;
            break;
          case 1;
            $account->status = 0;
            break;
          default;
            $account->status = 1;
            break;
            }    
      }    
  }
  class HufCommentMigration extends HufMigration {
  public function __construct() {
    parent::__construct();
    $this->description = 'Comments to Huf articles';
    $this->dependencies = array('HufArticle');
    $this->map = new MigrateSQLMap($this->machineName,
      //should this be set to ID? perhaps query needs to be moved up before this part
      array('ID' => array(
            'type' => 'int',
            'not null' => TRUE,
            'description' => 'Comment ID'
           )
         ),
      MigrateDestinationComment::getKeySchema()
    );
    //debugging to be done, why do i not get any data from the source database
    //echo MY_MIGRATION_DATABASE_NAME .'Comment';
    $query = db_select(MY_MIGRATION_DATABASE_NAME .'Comment', 'mec')
             ->fields('mec', array('ID', 'ejer_id', 'fra_id', 'Comment', 'Dato'));
    $this->source = new MigrateSourceSQL($query);
    $this->destination = new MigrateDestinationComment('comment_node_article');

    $this->addFieldMapping('status')
         ->defaultValue(COMMENT_PUBLISHED);
    $this->addFieldMapping('nid', 'ID')
         ->sourceMigration('HufArticle');
    $this->addFieldMapping('uid', 'fra_id')
         ->sourceMigration('HufUser')
         ->defaultValue(0);
    $this->addFieldMapping('pid')
         ->defaultValue(0);
    $this->addFieldMapping('subject', NULL);
    $this->addFieldMapping('comment_body', 'Comment');
    $this->addFieldMapping('comment_body:language')->defaultValue('da');
    $this->addFieldMapping(NULL,'ejer_id');
    $this->addFieldMapping('created', 'dato');
    $this->addFieldMapping('changed', 'dato');
    $this->addFieldMapping('language')->defaultValue('da');
    // No unmapped source fields

    // Unmapped destination fields
    $this->addUnmigratedDestinations(array('name', 'mail', 'hostname', 'thread', 'homepage', 'comment_body:format', 'path'));
    }
    public function prepare($account) {
        
        //We get the article title and use it as subject for all the comments, since they don't have a subject on the old site.
        $nid = $account->nid;
        if ($nid) {
          $nid = node_load($nid);
          $articletitle = $nid->title;
          //get the first 64 characters since the title can't be longer
          $articletitle = substr($articletitle, 0, 64);
          $account->subject = $articletitle;
          }
          else
            return FALSE;

        //we need to convert the name and description to utf 8 from iso latin to avoid errors with special characters
        //$account->subject = utf8_encode(html_entity_decode($account->subject));
        //$account->comment_body['und'][0]['value'] = str_replace('&#039;', '´', $account->comment_body['und'][0]['value']);
        $account->comment_body['und'][0]['value'] = utf8_encode(html_entity_decode(($account->comment_body['und'][0]['value']), ENT_QUOTES));
    } 
  }

  class HufForumTypeMigration extends HufMigration {
    public function __construct() {
      parent::__construct();
      // Human-friendly description of your migration process. Be as detailed as you
      // like.
      $this->description = t('Migrate forum types from the old HUF database. Will map the type with the ones created on the forum type migration');
      // Create a map object for tracking the relationships between source rows
      // and their resulting Drupal objects. Usually, you'll use the MigrateSQLMap
      // class, which uses database tables for tracking. Pass the machine name
      // of this migration to use in generating map and message tables.
      // And, pass schema definitions for the primary keys of the source and
      // destination - we need to be explicit for our source, but the destination
      // class knows its schema already.
      $this->map = new MigrateSQLMap($this->machineName,
          array(
            'ID' => array('type' => 'int',
                             //'length' => 255,
                             'not null' => TRUE,
                             'description' => 'Forum Type ID',
                            )
          ),
          MigrateDestinationTerm::getKeySchema()
        );

      $query = db_select(MY_MIGRATION_FORUM_DATABASE_NAME .'type', 'ft')
               ->fields('ft', array('ID','titel','beskrivelse'));
               

      // Create a MigrateSource object, which manages retrieving the input data.
      $this->source = new MigrateSourceSQL($query);

      // Set up our destination - terms in the migrate_example_beer_styles vocabulary
      $this->destination = new MigrateDestinationTerm('forumtype');

      // Assign mappings TO destination fields FROM source fields. To discover
      // the names used in these calls, use the drush commands
      // drush migrate-fields-destination BeerTerm
      // drush migrate-fields-source BeerTerm
      $this->addFieldMapping('name', 'titel');
      $this->addFieldMapping('description', 'beskrivelse');
      $this->addFieldMapping(NULL, 'id');
      $this->addUnmigratedDestinations(array('parent', 'parent_name', 'format', 'weight', 'path'));
      }
  }
  
  class HufForumMigration extends HufMigration {
    public function __construct() {
      parent::__construct();
      // Human-friendly description of your migration process. Be as detailed as you
      // like.

      $this->dependencies = array('HufForumType');
      $this->description = t('Migrate forums from the old HUF database. Needs to be run after ForumTypeMigration');

      $this->map = new MigrateSQLMap($this->machineName,
          array(
            'ID' => array('type' => 'int',
                             //'length' => 255,
                             'not null' => TRUE,
                             'description' => 'Forum Type ID',
                            )
          ),
          MigrateDestinationTerm::getKeySchema()
        );

      $query = db_select(MY_MIGRATION_FORUM_DATABASE_NAME .'fora', 'ff')
               ->fields('ff', array('ID','type','titel','beskrivelse'));
               

      // Create a MigrateSource object, which manages retrieving the input data.
      $this->source = new MigrateSourceSQL($query);

      // Set up our destination - terms in the migrate_example_beer_styles vocabulary
      $this->destination = new MigrateDestinationTerm('forums');

      // Assign mappings TO destination fields FROM source fields. To discover
      // the names used in these calls, use the drush commands
      // drush migrate-fields-destination BeerTerm
      // drush migrate-fields-source BeerTerm
      $this->addFieldMapping('field_forum_type', 'type')
      ->sourceMigration('HufForumType')
      ->arguments(array('source_type' => 'tid'));
      //$this->addFieldMapping('field_forum_type:source_type', 'ID')
      //->sourceMigration('HufForumType');
      //$this->addFieldMapping('field_forum_type:create_term')->defaultValue(TRUE);
      $this->addFieldMapping('name', 'titel');
      $this->addFieldMapping('description', 'beskrivelse');
      $this->addFieldMapping(NULL, 'id');
      $this->addUnmigratedDestinations(array('parent', 'parent_name', 'format', 'weight', 'path'));

      }

      public function prepare(stdClass $account) {
        //we need to convert the name and description to utf 8 from iso latin to avoid errors with special characters
        $account->name = utf8_encode(html_entity_decode($account->name));
        $account->description = utf8_encode(html_entity_decode($account->description));   
    }
  }
    
 class HufForumThreadMigration extends HufMigration {
    /**
     * Class Constructor
     */
    public function __construct() {
        parent::__construct();
     
        $this->description = t('Migrate old forum');
        $this->dependencies = array('HufUser','HufForum');
        $source_fields = array(
          'ID' => t('The node ID of the thread'),
        //  'linked_files' => t('The set of linked files'),
        //  'right_side_images' => t('The set of images that previously appeared on the side'),
        );
     
        $query = db_select(MY_MIGRATION_FORUM_DATABASE_NAME .'threads', 'fth')
          ->fields('fth', array('ID', 'fora', 'opretter', 'titel', 'text', 'oprettet', 'important', 'archive'));
        $this->source = new MigrateSourceSQL($query, $source_fields);
        $this->destination = new MigrateDestinationNode('forum');
     //echo $this->source;die;
        $this->map = new MigrateSQLMap($this->machineName,
          array(
            'ID' => array(
              'type' => 'int',
              'unsigned' => TRUE,
              'not null' => TRUE,
              'description' => 'Old Unique thread ID',
              'alias' => 'fth',
            )
          ),
          MigrateDestinationNode::getKeySchema()
        );
       // Make the mappings
        $this->addFieldMapping('title', 'titel');
        $this->addFieldMapping('status', 'archive');
        $this->addFieldMapping('revision')->defaultValue(TRUE);
        $this->addFieldMapping('promote')->defaultValue(FALSE);
        $this->addFieldMapping('language')->defaultValue('da');
        $this->addFieldMapping('sticky', 'important');
        $this->addFieldMapping('created', 'oprettet');
        $this->addFieldMapping('changed', 'oprettet');
        $this->addFieldMapping('body', 'text');
        $this->addFieldMapping('uid', 'opretter')
        ->sourceMigration('HufUser');
        $this->addFieldMapping('taxonomy_forums', 'fora')
        ->sourceMigration('HufForum')
        ->arguments(array('source_type' => 'tid'));
        $this->addFieldMapping(NULL, 'ID');
      }
      public function prepare(stdClass $account, stdClass $row) {
        //we need to convert the name and description to utf 8 from iso latin to avoid errors with special characters
        $account->title = utf8_encode(html_entity_decode($account->title));
        $account->body['und'][0]['value'] = utf8_encode(html_entity_decode($account->body['und'][0]['value'], ENT_QUOTES));
        //$account->body['und'][0]['value'] = str_replace('&#039;', '´', $account->body['und'][0]['value']);
        
        //since the parameter archive indicates with a '1' that a node is archived, we need to flip it, to make it fit with the published parameter in Drupal
        switch ($row->archive) {
          case 0;
            $account->status = 1;
            break;
          case 1;
            $account->status = 0;
            break;
          default;
            $account->status = 1;
            break;
          }
        }
    }
  class HufForumCommentMigration extends HufMigration {
    public function __construct() {
    parent::__construct();
    $this->description = 'Comments to Huf Forum';
    $this->dependencies = array('HufForumThread');
    $this->map = new MigrateSQLMap($this->machineName,
      array('ID' => array(
            'type' => 'int',
            'not null' => TRUE,
            'description' => 'Forum Comment ID'
           )
         ),
      MigrateDestinationComment::getKeySchema()
    );


    //debugging to be done, why do i not get any data from the source database
    //echo MY_MIGRATION_DATABASE_NAME .'Comment';
    $query = db_select(MY_MIGRATION_FORUM_DATABASE_NAME .'svar', 'fsv')
             ->fields('fsv', array('ID', 'thread', 'opretter', 'tekst', 'oprettet'));
    $this->source = new MigrateSourceSQL($query);
    $this->destination = new MigrateDestinationComment('comment_node_forum');

    $this->addFieldMapping('status')
         ->defaultValue(COMMENT_PUBLISHED);
    $this->addFieldMapping('nid', 'thread')
         ->sourceMigration('HufForumThread')
         ->description('Matching comment to parent thread, removing orphans in prepare statement');
    $this->addFieldMapping('uid', 'opretter')
         ->sourceMigration('HufUser')
         ->defaultValue(0);
    $this->addFieldMapping('pid')
         ->defaultValue(0);
    $this->addFieldMapping('subject', NULL);
    $this->addFieldMapping('comment_body', 'tekst');
    //$this->addFieldMapping('language')->defaultValue('da');
    //$this->addFieldMapping('comment_body:language')->defaultValue('da');
    $this->addFieldMapping(NULL, 'id');
         //->defaultValue(1); //need to figure out what to put here
          //regex for determining first period: /^(.*?(?<!\b\w)[.?!])\s+[A-Z0-9]/
         //pulling out substring: $string2 = substr($string1, 0, 100);
          //$this->addFieldMapping('comment_body', 'Comment'); //need to find out how to append the body
    $this->addFieldMapping('created', 'oprettet');
    //$this->addFieldMapping('changed', 'dato');
    // No unmapped source fields

    // Unmapped destination fields
    $this->addUnmigratedDestinations(array('name', 'mail', 'hostname', 'thread', 'homepage', 'changed', 'path', 'comment_body:format'));
    }

    public function prepare($account) {
        
        //We get the thread title and use it as subject for all the comments, since they don't have a subject on the old site.
        $nid = $account->nid;
        if ($nid) {
          $nid = node_load($nid);
          $threadtitle = $nid->title;
          //get the first 64 characters since the title can't be longer
          $threadtitle = substr($threadtitle, 0, 64);
          $account->subject = $threadtitle;
          }
          else
            return FALSE;

        //we need to convert the name and description to utf 8 from iso latin to avoid errors with special characters
        //$account->subject = utf8_encode(html_entity_decode($account->subject));
        /*$account->comment_body['und'][0]['value'] = utf8_encode(html_entity_decode($account->comment_body['und'][0]['value']));
        $commentbody = $account->comment_body['und'][0]['value'];
        */
        $account->comment_body['und'][0]['value'] = utf8_encode(html_entity_decode($account->comment_body['und'][0]['value'], ENT_QUOTES));
        //print $commentbody;
        //var_dump($account->comment_body['und'][0]['value']);die;
        //this was an attempt to extract first sentence, but it became to long and didn't make any sence.        
        //$subject = $account->subject;
        //$pattern = '/^(.*?(?<!\b\w)[.?!])\s+[A-Z0-9]/'; //need to get this regex working
        //$subject = 'U.S.A. hej. med dig';
        //$pattern = '/^[^.!?]*/';
        //var_dump($subject);die;
        //preg_match($pattern, $subject, $matches);
        //print($matches[0]); die;
        //$account->subject = $matches[0];
        //var_dump($account->subject); die;
    } 
  }    
