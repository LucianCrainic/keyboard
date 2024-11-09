/**
 * @file keymap.c
 * @brief Custom keymap for the Keebio Iris CE keyboard.
 *
 * This file contains the implementation of custom keycodes and their corresponding
 * string outputs for the Keebio Iris CE keyboard.
 */
#include QMK_KEYBOARD_H

enum custom_keycodes {
    PASSWD = SAFE_RANGE,
    //à è ì ò ù é ó
    // ITA_E=SAFE_RANGE+1,
    // ITA_E2=SAFE_RANGE+2,
    // ITA_I=SAFE_RANGE+3,
    // ITA_O=SAFE_RANGE+4,
    // ITA_O2=SAFE_RANGE+5,
    // ITA_U=SAFE_RANGE+6,
    // ITA_A=SAFE_RANGE+7,
};

enum custom_layers {
     _DELTA,
     _BETA,
     _GAMMA,
};
/**
 * @brief Sends a custom string based on the provided keycode.
 *
 * This function maps specific keycodes to their corresponding string outputs.
 * It is used to send predefined strings when certain keys are pressed.
 *
 * @param keycode The custom keycode that triggers the string output.
 */
void send_custom_string(uint16_t keycode) {
    switch (keycode) {
        case PASSWD:
            SEND_STRING("22!ShelbyCat11");
            break;
        // case ITA_E:
        //     SEND_STRING("è");
        //     break;
        // case ITA_E2:
        //     SEND_STRING("é");
        //     break;
        // case ITA_I:
        //     SEND_STRING("ì");
        //     break;
        // case ITA_O:
        //     SEND_STRING("ò");
        //     break;
        // case ITA_O2:
        //     SEND_STRING("ó");
        //     break;
        // case ITA_U:
        //     SEND_STRING("ù");
        //     break;
        // case ITA_A:
        //     SEND_STRING("à");
        //     break;
    }
}

/**
 * Processes a keycode when a key event occurs.
 *
 * @param keycode The keycode of the key event.
 * @param record A pointer to the keyrecord_t structure containing information about the key event.
 * @return Returns false if the key event was handled and no further processing is needed, true otherwise.
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        send_custom_string(keycode);
        return false;
    }
    return true;
}

/**
 * This file defines the keymap layers for the Iris keyboard.
 *
 * Layers:
 * - _DELTA: Default layer with standard QWERTY layout and some custom key bindings.
 * - _BETA: Secondary layer with custom key bindings for special characters and shortcuts.
 * - _GAMMA: Tertiary layer with function keys and mouse controls.
 *
 * Keymap Layout:
 * - Each layer is defined using the LAYOUT macro.
 * - The keymap is a 2D array where each element represents a key in the matrix.
 * - Special keycodes and macros are used for custom functionality.
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DELTA] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_PSCR,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MUTE,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_MINS,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_SLSH,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_GRV,  LGUI_T(KC_A), LALT_T(KC_S),  LSFT_T(KC_D),  LCTL_T(KC_F),  KC_G,        KC_H, RCTL_T(KC_J), RSFT_T(KC_K),   LALT_T(KC_L), RGUI_T(KC_SCLN), KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_HYPR, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_TAB,            CW_TOGG,  KC_N,    KC_M,    KC_COMM, KC_DOT , KC_EQL, KC_MEH,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    MO(1),   KC_ENT,  KC_SPC,                   KC_BSPC, KC_ESC,  MO(2)
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

//   [_BETA] = LAYOUT(
//   //┌────────┬────────┬────────┬───────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
//      ITA_A,  _______, C(KC_Z), C(KC_A), RCS(KC_V), RCS(KC_C),                       C(KC_PGUP), KC_PGDN, KC_PGUP, C(KC_PGDN), _______, ITA_O,
//   //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
//      ITA_E, KC_QUOTE, KC_LABK, KC_RABK, KC_DQUO, KC_DOT,                            KC_AMPR, KC_SCLN, KC_LBRC, KC_RBRC, KC_PERC, ITA_O2,
//   //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
//      ITA_E2, KC_EXLM, KC_MINS, KC_PLUS, KC_EQL , KC_HASH,                            KC_PIPE, KC_COLN, KC_LPRN, KC_RPRN, KC_QUES, ITA_U,
//   //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
//      ITA_I, KC_CIRC,KC_SLSH, KC_ASTR, KC_BSLS, KC_UNDS, _______,          _______, KC_TILD,  KC_DLR, KC_LCBR, KC_RCBR, KC_AT, _______,
//   //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
//                                     _______, _______, _______,                   _______, _______, _______
//                                 // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
//   ),

  [_GAMMA] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,   KC_F6,                              KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______,  KC_UP, _______, _______,                            _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______,                            KC_WH_U, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     PASSWD, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, QK_BOOT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

};

/**
 * @brief Toggles the RGB lighting based on the Caps Word state.
 *
 * This function is called when the Caps Word feature is activated or deactivated.
 * When activated, it disables the RGB lighting. When deactivated, it enables the RGB lighting.
 *
 * @param active A boolean indicating whether the Caps Word feature is active.
 */
void caps_word_set_user(bool active) {
    if (active) {
        rgblight_disable();
    } else {
        rgblight_enable();
    }
}
