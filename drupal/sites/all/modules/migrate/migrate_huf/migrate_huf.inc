<?php
/*
Implemented with inspiration from http://btmash.com/article/2011-03-02/migrating-content-part-1-users
*/
class HufUserMigration extends Migration {
  public function __construct() {
    parent::__construct();
    $this->description = t('Migrate HUF users');
 
    $source_fields = array(
      'ID' => t('User ID'),
    );
 
    $query = db_select('HUF_Users','u')
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