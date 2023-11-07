// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#define QAZ LAYOUT_ortho_4x10
//combo defs
const uint16_t PROGMEM esc_qw[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM tab_as[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM bksp_op[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM caps[] = {KC_S, KC_D, COMBO_END};
// const uint16_t PROGMEM cut[] = [KC_Z, KC_X, COMBO_END];

combo_t key_combos[] = {
    COMBO(esc_qw, KC_ESC),
    COMBO(tab_as, KC_TAB),
    COMBO(bksp_op, KC_BSPC),
    COMBO(caps, KC_CAPS_LOCK)
    // COMBO(cut, )
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
    [0] = QAZ(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    LSFT_T(KC_V),    RSFT_T(KC_B),    KC_N,    KC_M,    LCTL_T(KC_COMM),    LT(KC_LALT, KC_DOT),
        MO(1), KC_LGUI, LT(2, KC_SPC),  MO(3),    KC_BSPC
    ),
    [1] = QAZ(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_NUHS,   KC_GRV,   KC_QUOT,  KC_LBRC,    S(KC_LBRC),    LSA(KC_0),  KC_MINS,    KC_EQL, _______, _______,
        _______, KC_GRV,   LSA(KC_QUOT),  KC_RBRC ,   LSA(KC_NUHS),  LSA(KC_SCLN),  S(KC_SCLN), LALT(KC_P), LSA(KC_P),_______,
        _______, _______, _______, _______, _______
    ),
    [2] = QAZ(
    LGUI(KC_1),    LGUI(KC_2),    LGUI(KC_3),    LGUI(KC_4),    LGUI(KC_5),    LGUI(KC_6),    LGUI(KC_7),    LGUI(KC_8),    LGUI(KC_9), KC_DEL,
    KC_EXLM,       KC_AT,         KC_HASH,       KC_DLR,        KC_PERC,       KC_CIRC,       KC_AMPR,       KC_ASTR,       KC_LPRN,    KC_RPRN,
    KC_MUTE,       KC_VOLD,       KC_VOLU,       KC_MPRV,       KC_MPLY,       KC_MNXT,       _______,       _______,       _______,    _______,
    _______, _______, _______, _______, _______
    ),
    [3] = QAZ(
        _______,  _______,   _______,   _______,   _______,   _______,   _______,   KC_HOME, KC_UP,  KC_END,
        _______,  _______,   _______,   _______,   _______,   _______,   _______,   KC_LEFT, KC_DOWN, KC_RIGHT, 
        _______,  _______,  _______,    _______,   _______,   _______,   _______,   KC_PGUP,   _______, KC_PGDN, 
        QK_BOOT, _______, _______, _______, _______
    )
};
 