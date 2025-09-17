<?php
/**
 * @file
 * Admin page callbacks for the password strength module.
 */

/**
 * Form builder for password strength form.
 *
 * @see system_settings_form()
 * @ingroup forms
 */
function password_strength_settings() {
  $config = config('password_strength.settings');
  $form = array();
  $desc = "Password strengths are measured and based both on the amount of entropy (randomness) in the password and an estimate of the amount of time it could take to crack the password using brute-force attempts. The estimated time to crack at each level is about two orders of magnitude greater than the next lower level, so a Weak password can be cracked nearly instantly, while a Very strong password might take years.";
  $form['#config'] = 'password_strength.settings';
  $form['description'] = array(
    '#type' => 'markup',
    '#markup' => '<p>' . t($desc) . '</p>',
  );
  $form['default_required_score'] = array(
    '#type' => 'select',
    '#title' => t('Minimum required password strength'),
    '#description' => t('The minimum strength required for user account passwords.'),
    '#default_value' => $config->get('default_required_score'),
    '#options' => password_strength_score_list(),
  );
  $form['default_required_score']['#options'][0] = t('disabled');
  $form['test'] = array(
    '#type' => 'fieldset',
    '#title' => 'Test password strength',
    '#description' => t('Try different passwords to see what strength they are.'),
    '#collapsible' => TRUE,
    '#collapsed' => $config->get('default_required_score') == 0,
  );
  $form['test']['password'] = array(
    '#type' => 'textfield',
    '#title' => t('Password test'),
    '#attributes' => array(
      'class' => array('password-field', 'password-test'),
    ),
  );
  global $user;
  password_strength_form_password_js_attach($form['test']['password'], $user);

  $form['default_password_length'] = array(
    '#type' => 'number',
    '#title' => t('Minimum password length'),
    '#description' => t('The minimum password length in number of characters.'),
    '#default_value' => $config->get('default_password_length'),
  );
  // We need to remove any password entered for testing so it is not saved in
  // config.
  $form['#submit'][] = 'password_strength_settings_remove_password';

  return system_settings_form($form);
}

/**
 * Additional submit handler to remove any test values from the Password test
 * field.
 */
function password_strength_settings_remove_password($form, &$form_state) {
  unset($form_state['values']['password']);
}
