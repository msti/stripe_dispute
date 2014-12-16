<?php

/**
 * @file
 * Created behavior.
 * Save the current time when an entity is created.
 */

$plugin = array(
  'label' => "Commerce Order",
  'property_info' => 'eck_commerce_order_property_property_info',
);

/**
 * Associate this eck entity with the commerce_order table when the
 * commerce_order property is used in the addProperty().
 */
function eck_commerce_order_property_property_info($property, $vars) {
  $vars['properties'][$property]['type'] = 'commerce_order';
  return $vars;
}
