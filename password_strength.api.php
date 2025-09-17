<?php
/**
 * @file
 *
 * Function to alter the minimum score required depending on the user account.
 */

/**
 * Allows alteration of the score depending on any attribute of the user
 * account.
 */
function hook_password_strength_minimum_score_alter(&$score, $account){
  if (user_has_role('admin', $account)) {
    $score = PASSWORD_STRENGTH_SCORE_VERYSTRONG;
  }
}
