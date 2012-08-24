<?php
/*
Implemented with inspiration from http://btmash.com/article/2011-03-02/migrating-content-part-1-users
*/

const MY_MIGRATION_DATABASE_NAME = 'HUF_';
const MY_MIGRATION_FORUM_DATABASE_NAME = 'TESTFORUM_';
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
        ->fields('u', array('ID','Brugernavn','Password','Email','Oprettet'))
        ->condition('u.Brugernavn', array('admin', 'HUF', 'webmaster'), 'NOT IN')
        ->condition('u.ID', 0, '>');
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
      $this->addFieldMapping('uid', 'ID');
      $this->addFieldMapping('name', 'Brugernavn')->dedupe('users', 'name');
      $this->addFieldMapping('pass')->defaultValue('1234');
      //$this->addFieldMapping('mail', 'Email')->dedupe('users', 'mail');
      $this->addFieldMapping('language')->defaultValue('');
      $this->addFieldMapping('theme')->defaultValue('');
      $this->addFieldMapping('signature')->defaultValue('');
      $this->addFieldMapping('signature_format')->defaultValue('filtered_html');
      $this->addFieldMapping('created', 'Oprettet');
      //$this->addFieldMapping('access', 'access');
      //$this->addFieldMapping('login', 'login');
      $this->addFieldMapping('status')->defaultValue('1');
      //$this->addFieldMapping('picture')->defaultValue(0);
      $this->addFieldMapping('init', 'init');
      $this->addFieldMapping('timezone')->defaultValue(NULL);
      $this->addFieldMapping('path')->issueGroup(t('DNM'));
      $this->addFieldMapping('pathauto_perform_alias')->defaultValue('1');
      $this->addFieldMapping('roles', 'roles');
    }
  }

  class HufArticleMigration extends HufMigration {
    /**
     * Class Constructor
     */
    public function __construct() {
        parent::__construct();
     
        $this->description = t('Migrate old articles');
        $this->dependencies = array('HufUser','HufKategoriTerm');
        $source_fields = array(
          'ID' => t('The node ID of the article'),
        //  'linked_files' => t('The set of linked files'),
        //  'right_side_images' => t('The set of images that previously appeared on the side'),
        );
     
        $query = db_select(MY_MIGRATION_DATABASE_NAME .'Story', 's')
          ->fields('s', array('ID', 'ejer_id', 'Note', 'kap','Rubrik', 'Text_', 'Dato', 'Chg', 'Kategori', 'samling'));

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
        $this->addFieldMapping('created', 'Dato');
        $this->addFieldMapping('changed', 'Dato');
        $this->addFieldMapping('body', 'Text_');
        $this->addFieldMapping('uid', 'ejer_id');
        $this->addFieldMapping('field_kategori', 'Kategori');
        $this->addFieldMapping('field_samling', 'samling');
        $this->addFieldMapping('field_note', 'Note');
        $this->addFieldMapping('field_kapitel', 'kap');
        $this->addFieldMapping(NULL, 'ID');
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
    $this->destination = new MigrateDestinationComment('comment_node_migrate_huf');
    // Mapped fields
    //$this->addSimpleMappings(array('name', 'subject', 'mail'));
    $this->addFieldMapping('status')
         ->defaultValue(COMMENT_PUBLISHED);

    // We preserved bid => nid ids during BeerNode import so simple mapping suffices.
    $this->addFieldMapping('nid', 'ID')
         ->sourceMigration('HufArticle');
    $this->addFieldMapping('uid', 'fra_id')
         ->sourceMigration('HufUser')
         ->defaultValue(0);
    $this->addFieldMapping('pid')
         ->defaultValue(0);
    $this->addFieldMapping('subject', substr('comment',0,100));
         //->defaultValue(1); //need to figure out what to put here
//regex for determining first period: /^(.*?(?<!\b\w)[.?!])\s+[A-Z0-9]/
         //pulling out substring: $string2 = substr($string1, 0, 100);
    //$this->addFieldMapping('comment_body', 'Comment'); //need to find out how to append the body
    $this->addFieldMapping(NULL,'ejer_id');
    $this->addFieldMapping('created', 'dato');
    $this->addFieldMapping('changed', 'dato');
    // No unmapped source fields

    // Unmapped destination fields
    $this->addUnmigratedDestinations(array('name', 'mail', 'hostname', 'thread', 'homepage', 'language'));
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
        $account->body['und'][0]['value'] = utf8_encode(html_entity_decode($account->body['und'][0]['value']));
        
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
    $this->addFieldMapping('language')->defaultValue('da');
    $this->addFieldMapping('comment_body:language')->defaultValue('da');
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
        $account->comment_body['und'][0]['value'] = utf8_encode(html_entity_decode($account->comment_body['und'][0]['value']));
        
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
