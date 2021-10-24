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
        LT(1, KC_1)
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_1:
      // Play a tone when enter is pressed
      if (record->event.pressed) {
        switch (encoder_mode)
        {
        case 1:
            //mute
            tap_code(KC_MUTE);
            break;
        case 2:
            //
            break;
        case 3:
            //
            break;
        case 4:
            // Sleep
            tap_code(KC_SLEP);
            break;
        case 5:
            // PASTE
            tap_code(KC_PSTE);
            break;
        case 6:
            // RGB TOG
            tap_code16(RGB_TOG);
            break;
        default:
            break;
        }
      }
      return false; // Let QMK send the enter press/release events
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
HSV_GOLDENROD 30, 218, 218
**/

bool setlights = false;

void set_lighting(void) {
        setlights = true;
        rgblight_sethsv_range(  5, 255,  45,  0,   5);
        rgblight_sethsv_range( 43, 255,  45,  5,  10);
        rgblight_sethsv_range( 85, 255,  45, 10,  15);
        rgblight_sethsv_range(130, 255,  45, 15,  20);
        rgblight_sethsv_range(234, 255,  45, 20,  25);
        rgblight_sethsv_range(  0,   0,  45, 25,  30);

        switch (encoder_mode)
        {
        case 1:
            rgblight_sethsv_range(  5, 255, 255,  0,  5);
            break;
        case 2:
            rgblight_sethsv_range( 43, 255, 255,  5, 10);
            break;
        case 3:
            rgblight_sethsv_range( 85, 255, 255, 10, 15);
            break;
        case 4:
            rgblight_sethsv_range(130, 255, 255, 15, 20);
            break;
        case 5:
            rgblight_sethsv_range(234, 255, 255, 20, 25);
            break;
        case 6:
            rgblight_sethsv_range(  0,   0, 255, 25, 30);
            break;
        default:
            break;
        }

}

void housekeeping_task_user(void){
    switch (biton32(layer_state))
    {
    case 1:
        break;
    default:
        if (setlights){
            setlights = false;
            rgblight_set_effect_range(0, 30);
            rgblight_reload_from_eeprom();
        }
        break;
    }
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        switch (biton32(layer_state))
        {
        case 1:
                if (clockwise) {
                    encoder_mode += 1;
                    if (encoder_mode == 7) {
                        encoder_mode = 1;
                    }
                } else {
                    encoder_mode += -1;
                    if (encoder_mode == 0) {
                        encoder_mode = 6;
                    }
                }
                rgblight_set_effect_range(0, 0);
                set_lighting();
            break;

        default:
            switch(encoder_mode)
            {
            case 1:
                // VOLUME
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
            case 2:
                // UP/DOWN
                if (clockwise) {
                    tap_code(KC_DOWN);
                } else {
                    tap_code(KC_UP);
                }
                break;
            case 3:
                //LEFT/RIGHT
                if (clockwise) {
                    tap_code(KC_RIGHT);
                } else {
                    tap_code(KC_LEFT);
                }
                break;
            case 4:
                // Brightness
                if (clockwise) {
                    tap_code(KC_BRIU);
                } else {
                    tap_code(KC_BRID);
                }
                break;
            case 5:
                // UNDO REDO
                if (clockwise) {
                    tap_code(KC_AGAIN);
                } else {
                    tap_code(KC_UNDO);
                }
                break;
            case 6:
                // RGB MODE
                if (clockwise) {
                    rgblight_step();
                } else {
                    rgblight_step_reverse();
                }
                break;
            default:
                break;
            }
            break;
        }
    }
}
