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

enum custom_keycodes {
    NEWSKETCH = SAFE_RANGE,
    MIRROR,
    INSERTDXF,
    NEWCOMPONENT,
    CHAMFER,
    ROTATE
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [0] = LAYOUT(
                 KC_2,    KC_3,     KC_4,   KC_MUTE,
                          MO(3),    TO(1),  TO(2),
        KC_1,    KC_2,    KC_3,     KC_4,   KC_5,
        KC_1,    KC_2,    KC_3,     KC_4,   KC_5,
        KC_1,    KC_2,    KC_3,     KC_4,   KC_5,
        KC_1,    KC_2,    KC_3,     KC_4,   KC_5,
        KC_1,    KC_2,    KC_3,     KC_4,   KC_5
    ),
    [1] = LAYOUT(
                    KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,
                                TO(0),       TO(1),     TO(2),
        KC_ESC,    KC_TRNS,     KC_TRNS,     KC_TRNS,   KC_ENTER,
        S(C(KC_A)), C(KC_1),    S(C(KC_P)),  A(KC_N),   KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS
    ),
    [2] = LAYOUT(
                    KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,
                                TO(0),       TO(1),     TO(2),
// newsketce, line, retangle, circle, dimension
        NEWSKETCH,    KC_L,    KC_R,     KC_C,   KC_D,
//MIRROR, INSERTDXF, trim, project, ofset
        MIRROR,    INSERTDXF,    KC_T,     KC_P,   KC_O,
        NEWCOMPONENT,    KC_E,    KC_H,     KC_F,   CHAMFER,
        KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS
    ),
    [3] = LAYOUT( // TAP LAYER
                    KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,
                                KC_TRNS,     TO(4),     TO(5),
        KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS
    ),
    [4] = LAYOUT(
                    KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,
                                TO(0),       TO(1),     TO(5),
        KC_ESC,    KC_TRNS,    KC_SPACE,     KC_TRNS,   KC_ENTER,
// route, route diff pair, move, mirror, rotate
        KC_R,    C(KC_R),    KC_M,     MIRROR,   ROTATE,
        KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS
    ),
    [5] = LAYOUT(
                    KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,
                                TO(0),       TO(4),     TO(2),
        KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,     MAGIC_SWAP_CTL_GUI,   MAGIC_UNSWAP_CTL_GUI
    ),
};


bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code(KC_DOWN);
        } else {
            tap_code(KC_UP);
        }
    } else if (index == 2) { /* Third encoder */
// example of how to have encoder actions be layer dependent
        switch(biton32(layer_state)){
            case 2:
                if (clockwise) {
                tap_code16(S(G(KC_Z)));
                } else {
                tap_code16(G(KC_Z));
                }
                break;
            case 4:
                if (clockwise) {
                tap_code16(S(G(KC_Z)));
                } else {
                tap_code16(G(KC_Z));
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
    }
    return true;
}

const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {6, 1, HSV_RED}       // Light 1 LEDs, starting with LED 6
);
const rgblight_segment_t PROGMEM my_layer0_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {11, 1, HSV_GREEN}
);
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {10, 1, HSV_GREEN}

);const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {9, 1, HSV_GREEN}
);
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {11, 1, HSV_CYAN}
);
const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {10, 1, HSV_PURPLE}

);const rgblight_segment_t PROGMEM my_layer5_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {9, 1, HSV_PURPLE}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_layer0_layer,
    my_layer1_layer,
    my_layer2_layer,
    my_layer3_layer,
    my_layer4_layer,
    my_layer5_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, 0));
    rgblight_set_layer_state(2, layer_state_cmp(state, 1));
    rgblight_set_layer_state(3, layer_state_cmp(state, 2));
    rgblight_set_layer_state(4, layer_state_cmp(state, 3));
    rgblight_set_layer_state(5, layer_state_cmp(state, 4));
    rgblight_set_layer_state(6, layer_state_cmp(state, 5));
    return state;
}

#ifdef OLED_DRIVER_ENABLE
#include <stdio.h>

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
}


void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case 0:
            oled_write_ln_P(PSTR("0"), false);
            break;
        case 1:
            oled_write_ln_P(PSTR("1"), false);
            break;
        case 2:
            oled_write_ln_P(PSTR("2"), false);
            break;
        case 3:
            oled_write_ln_P(PSTR("3"), false);
            break;
        case 4:
            oled_write_ln_P(PSTR("4"), false);
            break;
        case 5:
            oled_write_ln_P(PSTR("5"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };
    oled_write_P(qmk_logo, false);
}

void oled_task_user(void) {
    oled_render_logo();
    oled_render_layer_state();
    oled_render_keylog();
}
#endif // OLED_DRIVER_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    set_keylog(keycode, record);
    switch (keycode) {
    case NEWSKETCH:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            tap_code(KC_S);
            SEND_STRING("ske");
            tap_code(KC_ENTER);
        }
        break;
    case MIRROR:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            tap_code(KC_S);
            SEND_STRING("MIRROR");
            tap_code(KC_ENTER);
        }
        break;
    case ROTATE:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            tap_code(KC_S);
            SEND_STRING("ROTATE");
            tap_code(KC_ENTER);
        }
        break;
    case INSERTDXF:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            tap_code(KC_S);
            SEND_STRING("DXF");
            tap_code(KC_ENTER);
        }
        break;
    case NEWCOMPONENT:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            tap_code(KC_S);
            SEND_STRING("New");
            tap_code(KC_ENTER);
        }
        break;
    case CHAMFER:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            tap_code(KC_S);
            SEND_STRING("Chamfer");
            tap_code(KC_ENTER);
        }
        break;
    }

    return true;
};

