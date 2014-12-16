<?php

/**
 * @file
 * Menu implementation
 */

/**
 * Hook_menu callback.
 *
 * Generates a form report for stripe submission
 */
function stripe_dispute_manage_dispute($form_id, &$form_state, $dispute_id) {

  $dispute = entity_load('eck_stripe_dispute', array($dispute_id));
  $dispute = current($dispute);

  if (!is_object($dispute)) {
    drupal_set_message(t('Error. The dispute could not be found. Please contact support.'), 'error');
    $form['error'] = array();
    return $form;
  }

  $evidence = stripe_dispute_generate_evidence($dispute);

  if (!isset($form_state['storage']['confirm'])) {

    $form['dispute_evidence'] = array(
      '#type' => 'textarea',
      '#title' => t('Dispute evidence'),
      '#required' => TRUE,
      '#description' => 'This dispute report was automatically generated. Please change as necessary and submit.',
      '#default_value' => $evidence,
      '#rows' => 10,
    );
    $form['stripe_id'] = array(
      '#type' => 'hidden',
      // @todo remove this hardcoded value and replace with: $dispute->charge_id,
      '#value' => 'ch_14PBo24h7wFfc3EYfTeXlbnL',
    );

    $form['submit'] = array('#type' => 'submit', '#value' => t('Submit'));
    return $form;
  }
  else {

    return confirm_form(
      array(),
      'Are you sure you want to submit this form?',
      current_path(),
      "Are you sure you want to submit this data?",
      'Yes, submit it!',
      'No, go back'
    );
  }
}

/**
 * Hook_menu callback.
 *
 * This is the endpoint where we receive the stripe webhooks
 * Most of this code is from the stripe documentation.
 */
function stripe_webhook_page_callback() {

  commerce_stripe_load_library();
  // @todo set the correct secret key here
  Stripe::setApiKey('');

  $input = @file_get_contents("php://input");

  if ($input) {
    $webhook = json_decode($input);
    $type = $webhook->type;

    // HOOK!
    rules_invoke_all('stripe_dispute', $webhook, $type);

    // Need to return return http 200 status code. set a status msg as well.
    return drupal_json_output(array('status' => 'OK'));
  }
  else {
    drupal_add_http_header('status', '403');
  }
}
