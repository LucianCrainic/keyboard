#include "keycodes.h"
#include "quantum_keycodes.h"
#include QMK_KEYBOARD_H

// enum that defines the custom keycodes implemented in the keymap.
enum custom_keycodes {
    PASSWD = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // this case handles all the custom keycodes.
        case PASSWD:
            if (record->event.pressed) {
                SEND_STRING("22!ShelbyCat11");
            }
            return false;
    }
    return true;
}

enum layers {
    _DELTA,
    _BETA,
    _GAMMA,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_DELTA] = LAYOUT(
        KC_PSCR,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,  _______,           _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MUTE,
        KC_MINS,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, _______,           _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_SLSH,
        KC_GRV,   HOME_A,  HOME_S,  HOME_D,  HOME_F,  KC_G,  _______,           _______, KC_H,   HOME_J,  HOME_K,  HOME_L, HOME_SCLN, KC_QUOT,
        KC_HYPR, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                             KC_N,    KC_M,    KC_COMM, KC_DOT , KC_EQL, KC_MEH,
        _______, _______, _______, _______, _______,          KC_TAB,            CW_TOGG,          _______, _______, _______, _______, _______,
                                            KC_SPC,   KC_ENT,  MO(1),            MO(2), KC_ESC,  KC_BSPC
    ),

    [_BETA] = LAYOUT(
        _______, _______, C(KC_Z), C(KC_A), RCS(KC_V), RCS(KC_C), _______,           _______, C(KC_PGUP), KC_PGDN, KC_PGUP, C(KC_PGDN), _______, _______,
        _______, KC_QUOTE, KC_LABK, KC_RABK, KC_DQUO, KC_DOT,     _______,           _______, KC_AMPR, KC_SCLN, KC_LBRC, KC_RBRC, KC_PERC, _______,
        _______, KC_EXLM, KC_MINS, KC_PLUS, KC_EQL , KC_HASH,     _______,           _______,  KC_PIPE, KC_COLN, KC_LPRN, KC_RPRN, KC_QUES, _______,
        _______, KC_CIRC,KC_SLSH, KC_ASTR, KC_BSLS, KC_UNDS,                                    KC_TILD,  KC_DLR, KC_LCBR, KC_RCBR, KC_AT, _______,
        _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,                       _______, _______, _______
    ),

    [_GAMMA] = LAYOUT(
        KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , _______,           _______, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
        _______, _______, _______, KC_UP, _______, _______, _______,           _______, _______,  KC_BTN1, KC_MS_U, KC_BTN2, _______, _______,
        _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,           _______,  KC_WH_U, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______,
        _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        PASSWD, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, QK_BOOT,
                                            _______, _______, _______,           _______, _______, _______
    ),

    // [TEMPLATE] = LAYOUT(
    //     _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, _______,
    //                                         _______, _______, _______,           _______, _______, _______
    // ),
};

// The following code is used to disable the RGB lighting when the CAPS_LOCK key is pressed.
void caps_word_set_user(bool active) {
    if (active) {
        rgblight_disable();
    } else {
        rgblight_enable();
    }
}
