<?php

/**
 * @file
 * Created behavior.
 *
 * Save the current time when an entity is created.
 */

$plugin = array(
  'label' => 'Date',
  'property_info' => 'eck_date_property_property_info',
);

/**
 * Let the system know this property is a date.
 */
function eck_date_property_property_info($property, $vars) {
  $vars['properties'][$property]['type'] = 'date';
  $vars['properties'][$property]['description'] = t("A date field.");
  return $vars;
}

