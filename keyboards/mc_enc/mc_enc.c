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
#include <stdio.h>
#include "print.h"
#include "mc_enc.h"
#include "raw_hid.h"

//structure for HID change messages
/*
 * Update Command structure no response needed:
 * 0 Command Code:              0x4550
 * 1 Encoder Mode:              0x00 to 0x05
 * 2 Key:                       clockwise 0x00
 *                              anticlockwise 0x01
 *                              button 0x02
 * 4 Keycode:                   Keycode
 *
 * Fetch Current Keymap:
 * 0 Command Code:              0x4551
 * 1 Encoder Mode:              0x00 to 0x05
 *
 * Respond with:
 * 0 Command Code:              0x4551
 * 1 Clockwise Keycode:         Keycode
 * 2 Anti-Clockwise Keycode:    Keycode
 * 3 Button Keycode:            Keycode
 *
 * Bi-Directional Layer Mirroring Commands:
 * 0 Command Code:              0x4552
 * 1 Encoder Mode:              0x00 to 0x05
 */

typedef union {
  uint32_t raw;
  struct {
    bool configd;
    uint16_t actions[6][3];
  };
} encoder_actions_t;

encoder_actions_t encoder_actions;
uint16_t default_actions[6][3] = {{0x0080, 0x0081, 0x007F},{0x0052, 0x0051, 0x004A},{0x004F, 0x004E, 0x002C},{0x007A, 0x0079, 0x007D},{0x00BD, 0x00BE, 0x00A6},{0x5CC4, 0x5CC5, 0x5CC3}};
uint16_t encoder_mode = 0;
bool setlights = false;

void eeconfig_init_kb(void) {
    encoder_actions.configd = true;
    for (int8_t x = 0; x < 6; x++){
       for (int8_t y = 0; y < 3; y++){
           encoder_actions.actions[x][y] = default_actions[x][y];
        }
    }
    eeconfig_update_kb(encoder_actions.raw);
    eeconfig_init_user();
}
void matrix_init_kb(void){

    encoder_actions.raw = eeconfig_read_kb();
    if (!encoder_actions.configd){
        eeconfig_init_kb();
    }

    return matrix_init_user();
}


void raw_hid_receive(uint8_t *data, uint8_t length) {

    uint16_t check = ((uint16_t)data[1] << 8) | data[0];
    uint16_t active_mode = ((uint16_t)data[3] << 8) | data[2];
    uint16_t key = ((uint16_t)data[5] << 8) | data[4];
    uint16_t newKeycode = ((uint16_t)data[7] << 8) | data[6];

    uprintf("Check:    0x%04X\n", check);
    uprintf("Enc Mode: 0x%04X\n", active_mode);

    if (check == 0x4551){
        data[0] = check>>8;
        data[1] = check;
        data[2] = encoder_actions.actions[active_mode][0]>>8;
        data[3] = encoder_actions.actions[active_mode][0];
        data[4] = encoder_actions.actions[active_mode][1]>>8;
        data[5] = encoder_actions.actions[active_mode][1];
        data[6] = encoder_actions.actions[active_mode][2]>>8;
        data[7] = encoder_actions.actions[active_mode][2];
        raw_hid_send(data, length);
        encoder_mode = active_mode;
        return;
    }

    if (check == 0x4552) {
        data[0] = check>>8;
        data[1] = check;
        data[2] = encoder_mode>>8;
        data[3] = encoder_mode;
        raw_hid_send(data, length);
        return;
    }


    if (check != 0x4550) return;
    uprintf("Key:      0x%04X\n", key);
    uprintf("Keycode:  0x%04X\n", newKeycode);
    encoder_actions.actions[active_mode][key] = newKeycode;
    eeconfig_update_kb(encoder_actions.raw);
    uprintf("4 0x%04X\n", encoder_actions.actions[active_mode][key]);


    raw_hid_send(data, length);
}

void handle_keycode(uint16_t keycode){

    switch (keycode)
    {
    case 0x5CC3:
        rgblight_toggle();
        break;
    case 0x5CC4:
        rgblight_step();
        break;
    case 0x5CC5:
        rgblight_step_reverse();
        break;
    default:
        tap_code16(keycode);
        break;
    }

}

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
        case 0:
            rgblight_sethsv_range(  5, 255, 255,  0,  5);
            break;
        case 1:
            rgblight_sethsv_range( 43, 255, 255,  5, 10);
            break;
        case 2:
            rgblight_sethsv_range( 85, 255, 255, 10, 15);
            break;
        case 3:
            rgblight_sethsv_range(130, 255, 255, 15, 20);
            break;
        case 4:
            rgblight_sethsv_range(234, 255, 255, 20, 25);
            break;
        case 5:
            rgblight_sethsv_range(  0,   0, 255, 25, 30);
            break;
        default:
            break;
        }

}

void housekeeping_task_kb(void){
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


bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        switch (biton32(layer_state))
        {
        case 1:
            if (clockwise) {
                if (encoder_mode == 5) {
                    encoder_mode = 0;
                } else encoder_mode += 1;
            } else {
                 if (encoder_mode == 0) {
                    encoder_mode = 5;
                } else encoder_mode -= 1;
            }
            uint8_t data[8];
            data[0] = 0x4552>>8;
            data[1] = ((uint8_t)0x4552);
            data[2] = encoder_mode>>8;
            data[3] = encoder_mode;
            uint8_t length = 32;
            raw_hid_send(data, length);

            rgblight_set_effect_range(0, 0);
            set_lighting();
            break;

        default:
            if (clockwise) {
                handle_keycode(encoder_actions.actions[encoder_mode][0]);
            } else {
                handle_keycode(encoder_actions.actions[encoder_mode][1]);
            }
            break;
        }
    }
    return encoder_update_user(index, clockwise);
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {

    switch (keycode)
    {
    case LT(1, KC_X):
        if (record->tap.count && record->event.pressed) {
            handle_keycode(encoder_actions.actions[encoder_mode][2]);
            return false; // Let QMK send the enter press/release events
        }else{
            return true;
        }

    default:
        break;
    }
    uprintf("KL: kc: 0x%04X \n", keycode);
    return process_record_user(keycode, record);
}
