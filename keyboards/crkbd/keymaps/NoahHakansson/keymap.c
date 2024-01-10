/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

// swedish åäö
// #define U_SW_AO_LOWER UM(0x00E5) // å
// #define U_SW_AO_UPPER UM(0x00C5) // Å
// #define U_SW_AA_LOWER UM(0x00E4) // ä
// #define U_SW_AA_UPPER UM(0x00C4) // Ä
// #define U_SW_OO_LOWER UM(0x00F6) // ö
// #define U_SW_OO_UPPER UM(0x00D6) // Ö

// Left-hand home row mods
#define HOME_S LGUI_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LALT_T(KC_F)
// Left-hand bottom row mods
#define HOME_Z LCTL_T(KC_Z)

// Right-hand home row mods
#define HOME_H LALT_T(KC_H)
#define HOME_J LSFT_T(KC_J)
#define HOME_K LGUI_T(KC_K)
// Right-hand bottom row mods
#define HOME_N LCTL_T(KC_N)

// Layer shorthand
#define _BASE 0
#define _CODE 1
#define _NUMBERS 2
#define _RGB 3
#define _NAV 4
#define _SE 5

enum custom_keycodes {
    SW_AO = SAFE_RANGE,
    SW_AA,
    SW_OO,
};

// send codes on keypress
uint8_t mod_state;
bool    process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();
    switch (keycode) {
        case SW_AO:
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    send_unicode_string("Å");
                } else {
                    send_unicode_string("å");
                }
            }
            break;
        case SW_AA:
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    send_unicode_string("Ä");
                } else {
                    send_unicode_string("ä");
                }
            }
            break;
        case SW_OO:
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    send_unicode_string("Ö");
                } else {
                    send_unicode_string("ö");
                }
            }
            break;
    }
    return true;
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_QUOT,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                        KC_GRAVE, KC_Y,    KC_U,     KC_I,   KC_O,    KC_P,
  //|--------+--------+--------+--------+--------+------------|                |--------+--------+--------+--------+--------+--------|
      QK_GESC,  KC_A,   HOME_S,  HOME_D,  HOME_F,  LT(4,KC_G),                  KC_BSPC,  HOME_H,  HOME_J,  HOME_K,  KC_L,   KC_SCLN,
  //|--------+--------+--------+--------+--------+------------|                |--------+--------+--------+--------+--------+--------|
      OSL(_SE), HOME_Z, KC_X,    KC_C,    KC_V,    KC_B,                        KC_NO,  HOME_N,  KC_M,   KC_COMM,  KC_DOT, KC_SLSH,
  //|--------+--------+--------+--------+--------+------------|                |--------+--------+--------+--------+--------+--------|
                              MEH(KC_NO), HYPR_T(KC_SPC), OSL(_CODE),    KC_ENT, LSFT_T(KC_TAB), OSL(_NUMBERS)),
                                      //`--------------------------'  `--------------------------'

	[_CODE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_NO,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,   KC_NO,                       KC_CIRC, KC_PLUS, KC_LPRN, KC_RPRN,  KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      TO(0),  KC_PERC, KC_ASTR, KC_AMPR, KC_PIPE,  KC_NO,                       KC_MINS, KC_COLN, KC_LCBR, KC_RCBR,  KC_EQL,  KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,  KC_BSLS, KC_LT,   KC_GT,   KC_TILD,  KC_NO,                       KC_GRV,  KC_UNDS, KC_LBRC, KC_RBRC,  KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                            KC_NO, KC_NO, TO(_NUMBERS),      TO(0), KC_NO, KC_NO),
                                      //`--------------------------'  `--------------------------'

	[_NUMBERS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      TO(0),    KC_1,    KC_2,    KC_3,    KC_4,   KC_5,                         KC_NO,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,   KC_F12,  KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,  KC_COMM,  KC_DOT, KC_SLSH,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                               KC_NO, KC_NO, TO(_RGB),     TO(0), KC_NO, KC_NO),
                                      //`--------------------------'  `--------------------------'

	[_RGB] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      RGB_TOG, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      TO(0),  RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, KC_NO,                         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,  RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, KC_NO,                         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                              KC_NO, KC_NO, KC_NO,      TO(0), KC_NO, KC_NO),
                                      //`--------------------------'  `--------------------------'

	[_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,  KC_VOLD, KC_MPLY, KC_MNXT, KC_VOLU,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      TO(0),   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_HOME, KC_LEFT, KC_DOWN,  KC_UP,  KC_RGHT,  KC_END,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_PGDN,   KC_PGUP,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                               KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO, KC_NO),
                                      //`--------------------------'  `--------------------------'

	[_SE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   SW_AO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      TO(0),   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   SW_OO,   SW_AA,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                              KC_NO, KC_NO, KC_NO,      TO(0), KC_LSFT, KC_NO)
                                      //`--------------------------'  `--------------------------'
};
// clang-format on
