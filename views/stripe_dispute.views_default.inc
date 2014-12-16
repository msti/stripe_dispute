<?php
/**
 * @file
 * Views definitions.
 */


/**
 * Implements hook_views_default().
 */
function stripe_dispute_views_default_views() {

  $view = new view();
  $view->name = 'disputes';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_eck_stripe_dispute';
  $view->human_name = 'Disputes';
  $view->core = 7;
  $view->api_version = '3.0';
  /* Edit this to true to make a default view disabled initially */
  $view->disabled = FALSE;

  /* Display: Master */

  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Disputes';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'stripe_dispute_manage_dispute';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'chargeback_creation' => 'chargeback_creation',
    'amount' => 'amount',
    'view_order' => 'view_order',
    'reason' => 'reason',
    'status' => 'status',
    'due_by' => 'due_by',
    'dispute_link' => 'dispute_link',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'chargeback_creation' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'amount' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_order' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'reason' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'due_by' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'dispute_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Stripe Dispute: Commerce Order */

  $handler->display->display_options['relationships']['order_id']['id'] = 'order_id';
  $handler->display->display_options['relationships']['order_id']['table'] = 'eck_eck_stripe_dispute';
  $handler->display->display_options['relationships']['order_id']['field'] = 'order_id';
  /* Field: Stripe Dispute: Id */

  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_eck_stripe_dispute';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: Stripe Dispute: Chargeback Creation */

  $handler->display->display_options['fields']['chargeback_creation']['id'] = 'chargeback_creation';
  $handler->display->display_options['fields']['chargeback_creation']['table'] = 'eck_eck_stripe_dispute';
  $handler->display->display_options['fields']['chargeback_creation']['field'] = 'chargeback_creation';
  $handler->display->display_options['fields']['chargeback_creation']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['chargeback_creation']['date_format'] = 'short';
  $handler->display->display_options['fields']['chargeback_creation']['second_date_format'] = 'long';
  /* Field: Stripe Dispute: Amount */

  $handler->display->display_options['fields']['amount']['id'] = 'amount';
  $handler->display->display_options['fields']['amount']['table'] = 'eck_eck_stripe_dispute';
  $handler->display->display_options['fields']['amount']['field'] = 'amount';
  $handler->display->display_options['fields']['amount']['element_label_colon'] = FALSE;
  /* Field: Commerce Order: Link */

  $handler->display->display_options['fields']['view_order']['id'] = 'view_order';
  $handler->display->display_options['fields']['view_order']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['view_order']['field'] = 'view_order';
  $handler->display->display_options['fields']['view_order']['relationship'] = 'order_id';
  $handler->display->display_options['fields']['view_order']['label'] = 'Order';
  $handler->display->display_options['fields']['view_order']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_order']['text'] = 'View order';
  /* Field: Stripe Dispute: Reason */

  $handler->display->display_options['fields']['reason']['id'] = 'reason';
  $handler->display->display_options['fields']['reason']['table'] = 'eck_eck_stripe_dispute';
  $handler->display->display_options['fields']['reason']['field'] = 'reason';
  $handler->display->display_options['fields']['reason']['element_label_colon'] = FALSE;
  /* Field: Stripe Dispute: Status */

  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'eck_eck_stripe_dispute';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['element_label_colon'] = FALSE;
  /* Field: Stripe Dispute: Evidence Due By */

  $handler->display->display_options['fields']['due_by']['id'] = 'due_by';
  $handler->display->display_options['fields']['due_by']['table'] = 'eck_eck_stripe_dispute';
  $handler->display->display_options['fields']['due_by']['field'] = 'due_by';
  $handler->display->display_options['fields']['due_by']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['due_by']['date_format'] = 'short';
  $handler->display->display_options['fields']['due_by']['second_date_format'] = 'long';
  /* Field: Stripe Dispute: Dispute link */

  $handler->display->display_options['fields']['dispute_link']['id'] = 'dispute_link';
  $handler->display->display_options['fields']['dispute_link']['table'] = 'eck_eck_stripe_dispute';
  $handler->display->display_options['fields']['dispute_link']['field'] = 'dispute_link';
  /* Sort criterion: Stripe Dispute: Chargeback Creation */

  $handler->display->display_options['sorts']['chargeback_creation']['id'] = 'chargeback_creation';
  $handler->display->display_options['sorts']['chargeback_creation']['table'] = 'eck_eck_stripe_dispute';
  $handler->display->display_options['sorts']['chargeback_creation']['field'] = 'chargeback_creation';
  $handler->display->display_options['sorts']['chargeback_creation']['order'] = 'DESC';
  /* Filter criterion: Stripe Dispute: Status */

  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'eck_eck_stripe_dispute';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['operator'] = 'contains';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );

  /* Display: Page */

  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/commerce/stripe/disputes';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Stripe Disputes';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  // (Export ends here.)

  // Add view to list of views to provide.
  $views[$view->name] = $view;

  // ...Repeat all of the above for each view the module should provide.

  // At the end, return array of default views.
  return $views;
}
