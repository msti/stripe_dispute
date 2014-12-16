<?php

/**
 * @file
 * Describe the hooks provided by the module
 */


/**
 * Alters the dispute evidence to be submitted to Stripe.
 *
 * This hook allows other modules to add/remove data to the dispute evidence submitted
 *
 * @param $evidence
 *   An array of dispute evidence.
 *   The contents of the array will be submitted as plain text to stripe.
 *   Each element of the array is a single line of text.
 * @param $dispute
 *   The $dispute entity
 */
function hook_stripe_dispute_evidence_alter(&$evidence, $dispute) {

}

/**
 * Allow other modules to react when a stripe webhook is detected.
 *
 * @param $webhook
 *   The webhook object as it is received from stripe
 * @param $type
 *   The type of the webhook (eg charge.dispute.created)
 */
function hook_stripe_dispute($webhook, $type) {

}
