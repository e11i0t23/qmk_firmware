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

void set_lighting(void) {
        switch(encoder_mode)
            {
            case 3*64:
                rgblight_sethsv(HSV_CYAN);
                break;
            case 1*64:
                rgblight_sethsv(HSV_GREEN);
                break;
            case 2*64:
                rgblight_sethsv(HSV_RED);
                break;
            case 0*64:
                rgblight_sethsv(HSV_ORANGE);
                break;
            default:
                rgblight_sethsv(HSV_PURPLE);
                break;
            }
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
                    encoder_mode += 64;
                } else {
                    encoder_mode += -64;
                }
                set_lighting();
            break;

        default:
            switch(encoder_mode)
            {
            case 3*64:
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
            case 1*64:
                if (clockwise) {
                    tap_code(KC_RIGHT);
                } else {
                    tap_code(KC_LEFT);
                }
                break;
            case 2*64:
                if (clockwise) {
                    tap_code(KC_PGDN);
                } else {
                    tap_code(KC_PGUP);
                }
                break;
            case 0*64:
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
