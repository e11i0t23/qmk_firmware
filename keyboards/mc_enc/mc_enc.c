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
#include "tmk_core/common/eeprom.h"

//structure for HID change messages
/*
* 0 prject code 0x45
* 1 Encoder Mode Code between 0x01 and 0x06
* 2 Key:
*      clockwise 0x00
*      anticlockwise 0x01
*      button 0x02
* 4 Keycode
*/
//typedef uint8_t BYTE;
// typedef union {
//   BYTE raw[64];
//   struct {
//     bool configd;
//     uint16_t actions[6][3];
//   };
// } encoder_actions_t;

// encoder_actions_t encoder_actions;
uint16_t EEPROM_ADDR = 512;
uint16_t eepromAdressOfsets[6][3] = {{0x01,0x03,0x05},{0x07,0x09, 0x0B},{0x0D, 0x0F, 0x11},{0x13,0x15, 0x17},{0x19,0x1B, 0x1D},{0x1F, 0x21, 0x23}};
uint16_t default_actions[6][3] = {{0x0080, 0x0081, 0x007F},{0x0052, 0x0051, 0x004A},{0x004F, 0x004E, 0x002C},{0x007A, 0x0079, 0x007D},{0x0048, 0x0047, 0x00A6},{0x5CC4, 0x5CC5, 0x5CC3}};
uint16_t encoder_mode = 0;
bool setlights = false;

void eeprom_enc_init(void) {
    // encoder_actions.configd = true;
    eeprom_write_byte((uint8_t *)EEPROM_ADDR, 0x01);
    for (int8_t x = 0; x < 6; x++){
       for (int8_t y = 0; y < 3; y++){
           eeprom_write_word((uint16_t *)(EEPROM_ADDR+eepromAdressOfsets[x][y]), default_actions[x][y]);
        }
    }
    //eeconfig_update_kb(encoder_actions.raw);
}
void matrix_init_kb(void){
    uprintf("Check:    0x%04X\n", eeprom_read_byte((uint8_t *)(EEPROM_ADDR)));
    if (eeprom_read_byte((uint8_t *)(EEPROM_ADDR)) != 0x01){
        printf("1");
        eeprom_enc_init();
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
        data[2] = eeprom_read_word((uint16_t *)(EEPROM_ADDR+eepromAdressOfsets[active_mode][0]))>>8;
        data[3] = eeprom_read_word((uint16_t *)(EEPROM_ADDR+eepromAdressOfsets[active_mode][0]));
        data[4] = eeprom_read_word((uint16_t *)(EEPROM_ADDR+eepromAdressOfsets[active_mode][1]))>>8;
        data[5] = eeprom_read_word((uint16_t *)(EEPROM_ADDR+eepromAdressOfsets[active_mode][1]));
        data[6] = eeprom_read_word((uint16_t *)(EEPROM_ADDR+eepromAdressOfsets[active_mode][2]))>>8;
        data[7] = eeprom_read_word((uint16_t *)(EEPROM_ADDR+eepromAdressOfsets[active_mode][2]));
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

    if (check == 0x4553 ) {
        if (active_mode != 0x0000){
            rgblight_mode(active_mode);
        }else{
            data[0] = check>>8;
            data[1] = check;
            data[2] = ((uint16_t)rgblight_get_mode()>>8);
            data[3] = (uint16_t)rgblight_get_mode();
            raw_hid_send(data, length);
        }
        return;
    }


    if (check != 0x4550) return;
    uprintf("Key:      0x%04X\n", key);
    uprintf("Keycode:  0x%04X\n", newKeycode);
    eeprom_update_word((uint16_t *)(EEPROM_ADDR+eepromAdressOfsets[active_mode][key]), newKeycode);
    // encoder_actions.actions[active_mode][key] = newKeycode;
    // eeconfig_update_kb(encoder_actions.raw);
    //uprintf("4 0x%04X\n", encoder_actions.actions[active_mode][key]);


    raw_hid_send(data, length);
}

// void sendRGBMode(){
//     // uint8_t data[8];
//     // data[0] = 0x4552>>8;
//     // data[1] = ((uint8_t)0x4552);
//     // data[2] = encoder_mode>>8;
//     // data[3] = encoder_mode;
//     // uint8_t length = 32;
//     // raw_hid_send(data, length);

// }

void handle_keycode(uint16_t keycode){

    switch (keycode)
    {
    case 0x5CC3:
        rgblight_toggle();
        break;
    case 0x5CC4:
        if (rgblight_is_enabled()){
            rgblight_step();
            uprintf("RGBMODE:    0x%04X\n", rgblight_get_mode());
        }
        break;
    case 0x5CC5:
        if (rgblight_is_enabled()){
            rgblight_step_reverse();
            uprintf("RGBMODE:    0x%04X\n", rgblight_get_mode());
        }
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
            uprintf("RGBMODE:    0x%04X\n", rgblight_get_mode());

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
            if (rgblight_is_enabled()){
                rgblight_set_effect_range(0, 0);
                set_lighting();
            }

            break;

        default:
            if (clockwise) {
                handle_keycode(eeprom_read_word((uint16_t *)(EEPROM_ADDR+eepromAdressOfsets[encoder_mode][0])));
            } else {
                handle_keycode(eeprom_read_word((uint16_t *)(EEPROM_ADDR+eepromAdressOfsets[encoder_mode][1])));
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
            handle_keycode(eeprom_read_word((uint16_t *)(EEPROM_ADDR+eepromAdressOfsets[encoder_mode][2])));
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
