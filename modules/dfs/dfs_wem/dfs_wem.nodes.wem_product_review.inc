<?php

/**
 * @file
 *  Migrations for WEM Commerce Product Nodes.
 */

class DFSWEMProductReviewNodes extends DemoFrameworkBaseNodes {

  public function __construct() {
    parent::__construct();
    $this->description = t('Import product review nodes.');

    $import_path = drupal_get_path('module', 'dfs_wem') . '/import/';

    // Create a MigrateSource object.
    $this->source = new MigrateSourceCSV($import_path . 'dfs_wem.nodes.wem_product_review.csv', $this->csvcolumns(), array('header_rows' => 1));

    $this->destination = new MigrateDestinationNode('wem_product_review');

    // Author
    $this->addFieldMapping('uid', 'author')->sourceMigration('DFSWEMUsers');

    // Entity Reference
    $this->addFieldMapping('field_commerce_reference', 'commerce')->sourceMigration('DFSWEMCommerceNodes');
     
    // Image
    $this->addFieldMapping('field_product_review_image', 'image');
    $this->addFieldMapping('field_product_review_image:file_replace')->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_product_review_image:source_dir')->defaultValue($import_path . 'images');
    $this->addFieldMapping('field_product_review_image:destination_file', 'filename');

  }

  function csvcolumns() {
    $columns[0] = array('title', 'Title');
    $columns[1] = array('body', 'Body');
    $columns[2] = array('commerce', 'Commerce');
    $columns[3] = array('image', 'Image');
    $columns[4] = array('author', 'Author');
    return $columns;
  }

}
