/* Copyright 2018 Elliot Powell
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
#include "sp.h"

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( /* Base */ \
    KC_GESC,   KC_1,     KC_2,    KC_3,    KC_4,  KC_5,                         KC_6,   KC_7,     KC_8,    KC_9,     KC_0,    KC_BSPACE,  \
    KC_TAB,    KC_Q,     KC_W,    KC_E,    KC_R,  KC_T,                         KC_Y,   KC_U,     KC_I,    KC_O,     KC_P,    KC_BSLASH,  \
    KC_CAPS,   KC_A,     KC_S,    KC_D,    KC_F,  KC_G,                         KC_H,   KC_J,     KC_K,    KC_L,     KC_SCLN, KC_QUOTE,  \
    KC_LSHIFT, KC_Z,     KC_X,    KC_C,    KC_V,  KC_B,                         KC_N,   KC_M,     KC_COMM, KC_DOT,   KC_SLSH, KC_RSHIFT,  \
    KC_F5,     KC_LCTRL, KC_LWIN, KC_LALT, MO(1), KC_SPACE, KC_DEL,   KC_BSPC, KC_ENT, KC_RWIN , KC_RCTL, KC_VOLU , KC_MUTE, KC_VOLD  \
  ),
};

const uint16_t fn_actions[] = {
};
