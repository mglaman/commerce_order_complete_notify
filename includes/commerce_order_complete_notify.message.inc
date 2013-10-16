<?php

function commerce_order_complete_notify_default_message_type() {

  $items['commerce_order_complete_notify'] = entity_import('message_type', '{
    "name" : "commerce_order_complete_notify",
    "description" : "Commerce Order: order complete notify",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : { "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" } },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "Order completed @{message:message-commerce-order:order-number} at [site:name]",
          "format" : null,
          "safe_value" : "Order @{message:message-commerce-order:order-number} at [site:name]"
        },
        {
          "value" : "Thanks for your order @{message:message-commerce-order:order-number} at [site:name].\r\n\r\nIf this is your first order with us, you will receive a separate e-mail with login instructions. You can view your order history with us at any time by logging into our website at:\r\n\r\n[site:login-url]\r\n\r\nYou can find the status of your current order at:\r\n\r\n[message:message-commerce-order:view-url]\r\n\r\nPlease contact us if you have any questions about your order.",
          "format" : "commerce_order_message",
          "safe_value" : "Thanks for your order @{message:message-commerce-order:order-number} at [site:name].\n\nIf this is your first order with us, you will receive a separate e-mail with login instructions. You can view your order history with us at any time by logging into our website at:\n\n[site:login-url]\n\nYou can find the status of your current order at:\n\n[message:message-commerce-order:view-url]\n\nPlease contact us if you have any questions about your order."
        }
      ]
    },
    "rdf_mapping" : []
  }');

  return $items;
}

/**
 * Refresh the fields attached to the message types we support.
 */
function commerce_order_complete_notify_message_field_refresh() {
  $fields['message_commerce_order']['field'] = array (
    'type' => 'entityreference',
    'module' => 'entityreference',
    'cardinality' => '1',
    'translatable' => FALSE,
    'settings' => array(
      'target_type' => 'commerce_order',
      'handler' => 'base',
      'handler_settings' => array(
        'target_bundles' => array(),
        'sort' => array(
          'type' => 'property',
          'property' => 'order_id',
          'direction' => 'ASC',
        ),
      ),
    ),
    'locked' => TRUE,
  );
  $bundles = array(
    'commerce_order_complete_notify',
  );
  $fields['message_commerce_order']['instances'][] = array(
    'entity_type' => 'message',
    'bundles' => $bundles,
    'label' => 'Order',
    'required' => TRUE,
    'widget' => array(
      'type' => 'entityreference_autocomplete',
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'size' => '60',
        'path' => '',
      ),
    ),
    'settings' => array(),
    'display' => array(
      'default' => array(
        'label' => 'above',
        'type' => 'entityreference_label',
        'settings' => array(
          'link' => FALSE,
        ),
        'module' => 'entityreference',
        'weight' => 0,
      ),
    ),
  );
  $fields['message_commerce_line_item']['field'] = array (
    'type' => 'entityreference',
    'module' => 'entityreference',
    'cardinality' => '1',
    'translatable' => FALSE,
    'settings' => array(
      'target_type' => 'commerce_line_item',
      'handler' => 'base',
      'handler_settings' => array(
        'target_bundles' => array(),
        'sort' => array(
          'type' => 'property',
          'property' => 'line_item_id',
          'direction' => 'ASC',
        ),
      ),
    ),
    'locked' => TRUE,
  );
  $fields['message_commerce_line_item']['instances'][] = array(
    'entity_type' => 'message',
    'bundles' => array('commerce_order_cart_add', 'commerce_order_cart_remove'),
    'label' => 'Line item',
    'required' => TRUE,
    'widget' => array(
      'type' => 'entityreference_autocomplete',
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'size' => '60',
        'path' => '',
      ),
    ),
    'settings' => array(),
    'display' => array(
      'default' => array(
        'label' => 'above',
        'type' => 'entityreference_label',
        'settings' => array(
          'link' => FALSE,
        ),
        'module' => 'entityreference',
        'weight' => 0,
      ),
    ),
  );
  $fields['message_commerce_payment']['field'] = array (
    'type' => 'entityreference',
    'module' => 'entityreference',
    'cardinality' => '1',
    'translatable' => FALSE,
    'settings' => array(
      'target_type' => 'commerce_payment_transaction',
      'handler' => 'base',
      'handler_settings' => array(
        'target_bundles' => array(),
        'sort' => array(
          'type' => 'property',
          'property' => 'transaction_id',
          'direction' => 'ASC',
        ),
      ),
    ),
    'locked' => TRUE,
  );
  $fields['message_commerce_payment']['instances'][] = array(
    'entity_type' => 'message',
    'bundles' => array('commerce_order_payment_entered'),
    'label' => 'Line item',
    'required' => TRUE,
    'widget' => array(
      'type' => 'entityreference_autocomplete',
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'size' => '60',
        'path' => '',
      ),
    ),
    'settings' => array(),
    'display' => array(
      'default' => array(
        'label' => 'above',
        'type' => 'entityreference_label',
        'settings' => array(
          'link' => FALSE,
        ),
        'module' => 'entityreference',
        'weight' => 0,
      ),
    ),
  );
  $fields['message_commerce_body']['field'] = array (
    'type' => 'text_long',
    'module' => 'text',
    'cardinality' => '1',
    'translatable' => FALSE,
    'settings' => array(),
    'locked' => TRUE,
  );
  $bundles = array(
    'commerce_order_user_comment',
    'commerce_order_admin_comment',
  );
  $fields['message_commerce_body']['instances'][] = array(
    'entity_type' => 'message',
    'bundles' => $bundles,
    'label' => 'Message',
    'required' => TRUE,
    'widget' => array(
      'type' => 'text_textarea',
      'module' => 'text',
      'settings' => array(
        'rows' => '3',
      ),
    ),
    'settings' => array(
      'text_processing' => TRUE,
    ),
    'display' => array(
      'default' => array(
        'label' => 'above',
        'type' => 'text_default',
        'settings' => array(),
        'module' => 'text',
        'weight' => 1,
      ),
    ),
  );

  // Create the missing fields.
  foreach ($fields as $field_name => $info) {
    $field = $info['field'];
    $field += array(
      'field_name' => $field_name,
    );
    if (!field_info_field($field_name)) {
      field_create_field($field);
    }

    foreach ($info['instances'] as $instance) {
      foreach ($instance['bundles'] as $bundle) {
        $instance['bundle'] = $bundle;
        unset($instance['bundles']);
        $instance['field_name'] = $field_name;
        if (!field_info_instance($instance['entity_type'], $instance['field_name'], $instance['bundle'])) {
          field_create_instance($instance);
        }
      }
    }
  }
}
