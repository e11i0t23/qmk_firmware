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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_1:
      // Play a tone when enter is pressed
      if (record->event.pressed) {

      }
      return true; // Let QMK send the enter press/release events
    default:
      return true; // Process all other keycodes normally
  }
}

/**
HSV_RED 0, 255, 255
HSV_YELLOW 43, 255, 255
HSV_GREEN 85, 255, 255
HSV_BLUE 170, 255, 255
HSV_PURPLE 191, 255, 255
**/
void set_lighting(void) {

        rgblight_sethsv_range(  27, 255,  75, 27,  30);
        rgblight_sethsv_range(  27, 255,  75, 0,  3);
        rgblight_sethsv_range( 43, 255,  75,  3,  9);
        rgblight_sethsv_range( 85, 255,  75,  9, 15);
        rgblight_sethsv_range(170, 255,  75, 15, 21);
        rgblight_sethsv_range(191, 255,  75, 21, 27);

        switch (encoder_mode/64)
        {
        case 0:
            rgblight_sethsv_range(  27, 255, 255, 27,  30);
            rgblight_sethsv_range(  27, 255, 255, 0,  3);
            break;
        case 1:
            rgblight_sethsv_range( 43, 255, 255,  3,  9);
            break;
        case 2:
            rgblight_sethsv_range( 85, 255, 255,  9, 15);
            break;
        case 3:
            rgblight_sethsv_range(170, 255, 255, 15, 21);
            break;
        case 4:
            rgblight_sethsv_range(191, 255, 255, 21, 27);
            break;
        default:
            rgblight_sethsv_range(191, 255, 255, 21, 27);
            break;
        }

}

void housekeeping_task_user(void){
    switch (biton32(layer_state))
    {
    case 1:
        rgblight_set_effect_range(0, 0);
        break;
    default:
        rgblight_reload_from_eeprom();
        break;
    }
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
            rgblight_reload_from_eeprom();
            switch(encoder_mode)
            {
            case 3*64:
                if (clockwise) {
                    rgblight_step();
                } else {
                    rgblight_step_reverse();
                }
                break;
            case 2*64:
                if (clockwise) {
                    tap_code(KC_RIGHT);
                } else {
                    tap_code(KC_LEFT);
                }
                break;
            case 1*64:
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
