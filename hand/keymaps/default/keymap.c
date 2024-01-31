// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define QAZ LAYOUT_ortho_4x10

//oled definitions
#ifdef OLED_ENABLE

// Rotate OLED
// oled_rotation_t oled_init_user(oled_rotation_t rotation) {
//     return OLED_ROTATION_180;  
// }

// Draw to OLED
bool oled_task_user() {
    // Set cursor position
    oled_set_cursor(0, 1);
    
    // Write text to OLED
    oled_write("Hello World!", false);
    
    return false;
}

#endif

// enum qapy_layers {
//     _default,
//     _num,
//     _alt,
//     _nav
// };

enum custom_keycodes {
  LLOCK = SAFE_RANGE,
};

//combo defs
const uint16_t PROGMEM esc_qw[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM tab_as[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM bksp_op[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM caps[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM del[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM qkb[] = {KC_Q, KC_P, KC_LALT,LSFT_T(KC_DOT), COMBO_END};

combo_t key_combos[] = {
    COMBO(esc_qw, KC_ESC),
    COMBO(tab_as, KC_TAB),
    COMBO(bksp_op, KC_BSPC),
    COMBO(caps, KC_CAPS_LOCK),
    COMBO(del, KC_DEL),
    COMBO(qkb, QK_BOOT)
};

#include "features/layer_lock.h"

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_layer_lock(keycode, record, LLOCK)) { return false; }
  // Your macros ...

  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │ A │ B │ C │ D │ E │ F │ G │ H │ I │ J │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ A │ B │ C │ D │ E │ F │ G │ H │ I │ J │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ A │ B │ C │ D │ E │ F │ G │ H │ I │ J │
     * ├───────┼───┼───┼───┴───┼───┼───┼───────┤
     * │       │ C │ D │   E   │ G │ H │       │
     * └───────┴───┴───┴───────┴───┴───┴───────┘
     */
    [0] = QAZ( //main
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    LCTL_T(KC_COMM),    LSFT_T(KC_DOT),
        KC_LALT, KC_LGUI, LT(2, KC_SPC),  MO(3), MO(1)
    ),
    [1] = QAZ( //num et accents
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_NUHS,   KC_GRV, KC_SLSH,  KC_QUOT,  KC_LBRC,    S(KC_LBRC),    LSA(KC_0),  KC_MINS,    KC_EQL, _______,
        _______, LALT(KC_Q),   LSA(KC_QUOT),  KC_RBRC ,   LSA(KC_NUHS),  LSA(KC_SCLN),  KC_SCLN, LALT(KC_P), LSA(KC_P),_______,
        _______, _______, _______, _______, _______
    ),
    [2] = QAZ( //alt
    KC_EXLM,       KC_AT,         KC_HASH,       KC_DLR,        KC_PERC,       KC_CIRC,       KC_AMPR,       KC_ASTR,       KC_LPRN,    KC_RPRN,
    LGUI(KC_GRV),       KC_NUBS,       S(KC_EQL),       KC_EQL,       _______, ALGR(KC_GRV), LALT(KC_7),    LALT(KC_8),    LALT(KC_9),    LALT(KC_0),       
    LGUI(KC_1),    LGUI(KC_2),    LGUI(KC_3),    LGUI(KC_4),    LGUI(KC_5),    LGUI(KC_6),    LGUI(KC_7),    LGUI(KC_8),    LGUI(KC_9), _______,
    _______, _______, _______, _______, _______
    ),
    [3] = QAZ(  //nav          
        KC_F1,    KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,     KC_F7,     KC_F8,   KC_F9, KC_F10,
        KC_F11,  KC_MPRV,   KC_MPLY,   KC_MNXT,   _______,   _______,   KC_PGUP,   KC_HOME, KC_UP,  KC_END, 
        _______,  KC_MUTE,   KC_VOLD,   KC_VOLU,   _______,   _______,   KC_PGDN,   KC_LEFT, KC_DOWN, KC_RIGHT, 
        _______, _______, _______, _______, LLOCK
    )
};