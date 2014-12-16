<?php

/**
 * @file
 * Definition of views field.
 */

/**
 * class definition
 */
class views_action_views_handler_dispute_link extends eck_views_handler_field_link {

  /**
   * Render function: return html output.
   */
  function render_link($entity, $values) {

    $output = l(t('Dispute'), 'admin/stripe/dispute/' . $entity->id);
    if ($entity->status != 'needs_response') {
      $output = t('Disputed');
    }
    return $output;
  }
}
