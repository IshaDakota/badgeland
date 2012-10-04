<?php

/* implements hook_rules_action_info */

function user_badges_rules_action_info() {
  return array(
    'user_badges_rules_add_badge_action' => array(
      'label' => t('Add badge'),
      'group' => t('User Badges'),
      'module' => 'user_badges',
      'parameter' => array(
        'account' => array(
          'type' => 'user',
          'label' => t('User'),
        ),
        
        'badges' => array(
          'type' => 'list<integer>',
          'label' => t('Badges'),
          'options list' => 'user_badges_rules_get_badges',
          'restriction' => 'input',
        ),
      ),
    ),
    'user_badges_rules_remove_badge_action' => array(
      'label' => t('Remove badge'),
      'group' => t('User Badges'),
      'module' => 'user_badges',
      'parameter' => array(
        'account' => array(
          'type' => 'user',
          'label' => t('User'),
        ),
        
        'badges' => array(
          'type' => 'list<integer>',
          'label' => t('Badges'),
          'options list' => 'user_badges_rules_get_badges',
          'restriction' => 'input',
        ),
      ),
    ),
  );
}

function user_badges_rules_get_badges() {
  $badges = user_badges_get_badges('all');
  $items = array();
  foreach($badges as $badge) :
    $items[$badge->bid] = check_plain($badge->name);
  endforeach;
  return $items;
}

function user_badges_rules_add_badge_action($account, $badges) {
  $context = array('badges' => $badges, 'uid' => $account->uid);
  user_badges_add_badge_action($account, $context);  
}

function user_badges_rules_remove_badge_action($account, $badges) {
  $context = array('badges' => $badges, 'uid' => $account->uid);
  user_badges_remove_badge_action($account, $context);  
}