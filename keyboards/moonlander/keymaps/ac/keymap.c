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
    MDIA,  // media keys
};

enum custom_keycodes {
    VRSN = ML_SAFE_RANGE,
};

enum functions {
  ULTRA_KEY,
  G_TAB,
  S_ENT,
  GUI_SPC,
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
  TEST_1,
};

const uint16_t PROGMEM fn_actions[] = {
  [ULTRA_KEY] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC),
  [ULTRA_KEY] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC),
  [G_TAB] = ACTION_MODS_TAP_KEY(MOD_LGUI, KC_TAB),
  [S_ENT] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_ENT),
  [GUI_SPC] = ACTION_MODS_TAP_KEY(MOD_RGUI, KC_SPC),
  [S_1a] = ACTION_MODS_KEY(MOD_LGUI, KC_1),
  [S_2a] = ACTION_MODS_KEY(MOD_LGUI, KC_2),
  [S_3a] = ACTION_MODS_KEY(MOD_LGUI, KC_3),
  [S_4a] = ACTION_MODS_KEY(MOD_LGUI, KC_4),
  [S_5a] = ACTION_MODS_KEY(MOD_LGUI, KC_5),
  [S_6a] = ACTION_MODS_KEY(MOD_LGUI, KC_6),
  [S_7a] = ACTION_MODS_KEY(MOD_LGUI, KC_7),
  [S_8a] = ACTION_MODS_KEY(MOD_LGUI, KC_8),
  [S_9a] = ACTION_MODS_KEY(MOD_LGUI, KC_9),
  [S_0a] = ACTION_MODS_KEY(MOD_LGUI, KC_0),
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_moonlander(
        _______,  _______,    _______,    _______,    _______,    _______,    _______,     _______, _______,    _______,   _______,    _______,    _______,    _______,
        F(G_TAB),  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______,                   _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        F(ULTRA_KEY), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______,                _______,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z, KC_X,   KC_C,    KC_V,    KC_B,                                          KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLS, F(S_ENT),
        _______,_______,_______,_______, _______,  LALT_T(KC_APP),                                  RCTL_T(KC_ESC),   _______,   _______, _______, _______, _______,
                                            LT(SYMB, KC_LBRC),  KC_SPC, KC_LGUI,              KC_LALT,  KC_TAB,  KC_ENT
    ),

    [SYMB] = LAYOUT_moonlander(
        _______,  _______,    _______,    _______,    _______,    _______,    _______,     _______, _______,    _______,   _______,    _______,    _______,    _______,
        _______, _______, _______,  KC_LPRN, KC_RPRN, _______,  _______,           _______, _______,   KC_PLUS,    _______,   _______,    _______, _______,
        _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD,           _______, KC_EQL, KC_MINS,    KC_LCBR,    KC_RCBR,    _______, KC_BSLS,
        _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD,                             KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, _______,
        _______, F(S_1a), F(S_2a), F(S_3a), F(S_3a),  F(S_4a),  F(S_5a),  _______, KC_DOT,  KC_0,    KC_EQL,  _______,
                                            RGB_HUD, RGB_VAD, RGB_HUI, TOGGLE_LAYER_COLOR,_______, _______
    ),

    [MDIA] = LAYOUT_moonlander(
        LED_LEVEL,_______,_______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, RESET,
        _______, _______, _______, KC_MS_U, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,           _______, _______, _______, _______, _______, _______, KC_MPLY,
        _______, _______, _______, _______, _______, _______,                             _______, _______, KC_MPRV, KC_MNXT, _______, _______,
        _______, _______, _______, KC_BTN1, KC_BTN2,         _______,            _______,          KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
        case VRSN:
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
        }
    }
    return true;
}
