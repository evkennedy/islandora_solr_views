<?php

/**
 * @file
 * Views base handler for arguments
 */

// @codingStandardsIgnoreStart
// This Whole file is ignored due to classes and methods are not camelcase and it
// being called all over the place. TODO bring up to coding standards
class islandora_solr_views_handler_argument extends views_handler_argument {
  /**
   * Function query.
   */
  function query() {

    if (!empty($this->argument)) {
      $value = $this->argument;

      module_load_include('inc', 'islandora_solr', 'includes/utilities');
      $value = islandora_solr_lesser_escape($value);

      $fieldname = $this->field;

      if (is_array($value)) {
        $values = array_filter($value);
        // Ensure that some values have been selected.
        if (!empty($values)) {
          $this->query->add_filter($fieldname, '(' . implode('OR', $values) . ')');
        }
        return;
      }
      $this->query->add_filter($fieldname, $value);
    }
  }
}
// @codingStandardsIgnoreEnd
