/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */



#include QMK_KEYBOARD_H
#include "version.h"


enum layers {
    BASE,  // default layer
    SYMB,  // symbols
    NUM,  // media keys
};

enum custom_keycodes {
    VRSN = ML_SAFE_RANGE,
    MOVEL,
    MOVER,
    S_1a,
    S_2a,
    S_3a,
    S_4a,
    S_5a,
    S_6a,
    S_7a,
    S_8a,
    S_9a,
    S_0a,
};

enum functions {
  ULTRA_KEY,
  G_TAB,
  S_ENT,
  GUI_SPC,
};

const uint16_t PROGMEM fn_actions[] = {
  [ULTRA_KEY] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC),
  [ULTRA_KEY] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC),
  [G_TAB] = ACTION_MODS_TAP_KEY(MOD_LGUI, KC_TAB),
  [S_ENT] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_ENT),
  [GUI_SPC] = ACTION_MODS_TAP_KEY(MOD_RGUI, KC_SPC),
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_moonlander(
        _______,  _______,    _______,    _______,    _______,    _______,    _______,     _______, _______,    _______,   _______,    _______,    _______,    _______,
        LGUI_T(KC_TAB),  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______,                   _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        LCTL_T(KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______,                _______,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z, KC_X,   KC_C,    KC_V,    KC_B,                                          KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT),
        KC__MUTE,KC__VOLDOWN,KC__VOLUP,KC_MPLY, LT(SYMB, KC_LBRC),  MOVEL,                                  MOVER,   LT(NUM, KC_RBRC),   KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,
                                            KC_SPC,  KC_LALT, KC_LGUI,              KC_RCTL,  KC_RALT,  RGUI_T(KC_ENT)
    ),

    [SYMB] = LAYOUT_moonlander(
        _______,  _______,    _______,    _______,    _______,    _______,    _______,     _______, _______,    _______,   _______,    _______,    _______,    _______,
        _______, _______, _______,   _______, _______, _______, _______,           _______, _______,   KC_PLUS,    _______,   _______,    _______, _______,
        _______, _______, _______,  KC_LPRN, KC_RPRN, _______,  _______,           _______, KC_EQL, KC_MINS,    KC_LCBR,    KC_RCBR,    _______, KC_BSLS,
        _______, S_1a, S_2a, S_3a, S_4a, S_5a,                             S_6a, S_7a,    S_8a,    S_9a,    S_0a, _______,
        _______, _______, _______, _______, _______,     _______,                   _______,    _______, _______,  _______,    _______,  _______,
                                            _______, _______, _______,        _______,_______, _______
    ),

    [NUM] = LAYOUT_moonlander(
        _______,_______,_______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        KC_GRV, KC_EXLM,  KC_AT, KC_HASH, KC_DLR, KC_PERC, _______,          _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
        KC_TILD, KC_1,    KC_2,    KC_3,    KC_4, KC_5,   _______,           _______, KC_6,     KC_7,    KC_8,   KC_9,    KC_0, KC_PIPE,
        _______, S_1a, S_2a, S_3a, S_4a, S_5a,                         S_6a, S_7a,    S_8a,    S_9a,    S_0a, _______,
        _______, _______, _______, _______, _______,         _______,            _______,          _______, _______, _______, _______, _______,
                                            KC_UNDS, _______, _______,           _______, _______, _______
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
        case VRSN:
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
        case MOVEL:
            SEND_STRING (SS_DOWN(X_LGUI) SS_DOWN(X_LALT) SS_TAP(X_LEFT) SS_UP(X_LGUI) SS_UP(X_LALT));
            return false;
        case MOVER:
            SEND_STRING (SS_DOWN(X_LGUI) SS_DOWN(X_LALT) SS_TAP(X_RIGHT) SS_UP(X_LGUI) SS_UP(X_LALT));
            return false;
        case S_1a:
            SEND_STRING (SS_DOWN(X_LGUI) "1" SS_UP(X_LGUI));
            return false;
        case S_2a:
            SEND_STRING (SS_DOWN(X_LGUI) "2" SS_UP(X_LGUI));
            return false;
        case S_3a:
            SEND_STRING (SS_DOWN(X_LGUI) "3" SS_UP(X_LGUI));
            return false;
        case S_4a:
            SEND_STRING (SS_DOWN(X_LGUI) "4" SS_UP(X_LGUI));
            return false;
        case S_5a:
            SEND_STRING (SS_DOWN(X_LGUI) "5" SS_UP(X_LGUI));
            return false;
        case S_6a:
            SEND_STRING (SS_DOWN(X_LGUI) "6" SS_UP(X_LGUI));
            return false;
        case S_7a:
            SEND_STRING (SS_DOWN(X_LGUI) "7" SS_UP(X_LGUI));
            return false;
        case S_8a:
            SEND_STRING (SS_DOWN(X_LGUI) "8" SS_UP(X_LGUI));
            return false;
        case S_9a:
            SEND_STRING (SS_DOWN(X_LGUI) "9" SS_UP(X_LGUI));
            return false;
        case S_0a:
            SEND_STRING (SS_DOWN(X_LGUI) "0" SS_UP(X_LGUI));
            return false;
        }
    }
    return true;
}
