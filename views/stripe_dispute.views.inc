<?php

/**
 * @file
 * Provides views integration
 */

/**
 * Implements hook_views_data_alter().
 */
function stripe_dispute_views_data_alter(&$data) {

  $data['eck_eck_stripe_dispute']['dispute_link'] = array(
    'field' => array(
      'title' => t('Dispute link'),
      'help' => t('Click to autocreate a chargeback dispute report'),
      'handler' => 'views_action_views_handler_dispute_link',
    ),
  );
}
