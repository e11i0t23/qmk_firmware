/* Copyright 2021 Elliot Powell
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
uint8_t encoder_mode = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [0] = LAYOUT(
        LT(1, KC_MUTE)
    )
};

int leds[9][9][2] = {
    {{27, 3}, {3, 6}, {6, 9}, {9, 12}, {12, 15}, {15, 18}, {18, 21}, {21, 24}, {24, 27}},
    {{3, 6}, {6, 9}, {9, 12}, {12, 15}, {15, 18}, {18, 21}, {21, 24}, {24, 27}, {27, 3}},
    {{6, 9}, {9, 12}, {12, 15}, {15, 18}, {18, 21}, {21, 24}, {24, 27}, {27, 3}, {3, 6}},
    {{9, 12}, {12, 15}, {15, 18}, {18, 21}, {21, 24}, {24, 27}, {27, 3}, {3, 6}, {6, 9}},
    {{12, 15}, {15, 18}, {18, 21}, {21, 24}, {24, 27}, {27, 3}, {3, 6}, {6, 9}, {9, 12}},
    {{15, 18}, {18, 21}, {21, 24}, {24, 27}, {27, 3}, {3, 6}, {6, 9}, {9, 12}, {12, 15}},
    {{18, 21}, {21, 24}, {24, 27}, {27, 3}, {3, 6}, {6, 9}, {9, 12}, {12, 15}, {15, 18}},
    {{21, 24}, {24, 27}, {27, 3}, {3, 6}, {6, 9}, {9, 12}, {12, 15}, {15, 18}, {18, 21}},
    {{24, 27}, {27, 3}, {3, 6}, {6, 9}, {9, 12}, {12, 15}, {15, 18}, {18, 21}, {21, 24}},
    };

void set_lighting(void) {

        rgblight_sethsv_range(HSV_PURPLE, leds[encoder_mode/32][0][0], leds[encoder_mode/32][0][1]);
        rgblight_sethsv_range(HSV_RED, leds[encoder_mode/32][1][0], leds[encoder_mode/32][1][1]);
        rgblight_sethsv_range(HSV_YELLOW, leds[encoder_mode/32][2][0], leds[encoder_mode/32][2][1]);
        rgblight_sethsv_range(HSV_PINK, leds[encoder_mode/32][3][0], leds[encoder_mode/32][3][1]);
        rgblight_sethsv_range(HSV_GREEN, leds[encoder_mode/32][4][0], leds[encoder_mode/32][4][1]);
        rgblight_sethsv_range(HSV_BLUE, leds[encoder_mode/32][5][0], leds[encoder_mode/32][5][1]);
        rgblight_sethsv_range(HSV_ORANGE, leds[encoder_mode/32][6][0], leds[encoder_mode/32][6][1]);
        rgblight_sethsv_range(HSV_CYAN, leds[encoder_mode/32][7][0], leds[encoder_mode/32][7][1]);
        rgblight_sethsv_range(HSV_MAGENTA, leds[encoder_mode/32][8][0], leds[encoder_mode/32][8][1]);
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    set_lighting();
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        switch (biton32(layer_state))
        {
        case 1:
                if (clockwise) {
                    encoder_mode += 32;
                } else {
                    encoder_mode += -32;
                }
                set_lighting();
            break;

        default:
            switch(encoder_mode)
            {
            case 7*32:
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
            case 6*32:
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
            case 5*32:
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
            case 4*32:
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
            case 3*32:
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
            case 2*32:
                if (clockwise) {
                    tap_code(KC_RIGHT);
                } else {
                    tap_code(KC_LEFT);
                }
                break;
            case 1*32:
                if (clockwise) {
                    tap_code(KC_PGDN);
                } else {
                    tap_code(KC_PGUP);
                }
                break;
            case 0*32:
                if (clockwise) {
                    tap_code(KC_DOWN);
                } else {
                    tap_code(KC_UP);
                }
                break;
            default:
                if (clockwise){
                    tap_code(KC_VOLU);
                } else{
                    tap_code(KC_VOLD);
                }
                break;
            }
            break;
        }
    }
}
