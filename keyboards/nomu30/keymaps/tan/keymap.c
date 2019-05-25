/* Copyright 2019 Naoto Takai
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

#define _BASE 0
#define _NUMS 1
#define _SYMS 2
#define _FUNC 3


#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define KC_TBSF  LSFT_T(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
        KC_TBSF, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_ENT,
        KC_LCTL, LALT_T(KC_Z), LGUI_T(KC_X), KC_C, LT(_SYMS, KC_V), LT(_FUNC, KC_B), LT(_NUMS, KC_N), KC_M, KC_SPC
    ),
    [_NUMS] = LAYOUT(
        KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_GRV,
        _______, KC_LBRC, KC_RBRC, KC_SLSH, KC_BSLS, KC_JYEN, KC_MINS, KC_EQL, KC_SCLN, KC_QUOT, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_COMM, KC_DOT
    ),
    [_SYMS] = LAYOUT(
        KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD,
        _______, KC_LCBR, KC_RCBR, KC_QUES, KC_PIPE, _______, KC_UNDS, KC_PLUS, KC_COLN, KC_DQUO, _______,
        _______, KC_LABK, KC_RABK, _______, _______, _______, KC_RO, _______, _______
    ),
    [_FUNC] = LAYOUT(
        KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_DEL,
        KC_TAB, KC_F11, KC_F12, KC_MUTE, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, RESET,
        _______, KC_LALT, KC_LGUI, _______, _______, _______, KC_COMM, KC_DOT, _______
    )
};
