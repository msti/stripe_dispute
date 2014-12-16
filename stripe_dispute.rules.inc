<?php

/**
 * Implements hook_rules_event_info().
 */
function stripe_dispute_rules_event_info() {
  $events = array();

  $events['stripe_webhook'] = array(
    'label' => t('After a stripe webhook has been received'),
    'group' => t('Stripe'),
    'help' => 'This event is invoked after a stripe webhook has been received.',
    'variables' => array(
      'stripe-webhook' => array(
        'type' => 'stripe_webhook',
        'label' => t('Webhook', array(), array()),
      ),
      'result' => array(
        'type' => 'text',
        'label' => t('Type'),
        'description' => t('The webhook type.'),
      ),
    ),
  );

  return $events;
}

