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
        KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,
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
        KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,
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
        KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS
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
            case 1:
                if (clockwise) {
                tap_code(KC_UP);
                } else {
                tap_code(KC_DOWN);
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

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

void render_default_layer_state(void) {
    oled_write_P(PSTR("Layout: "), false);
    switch (get_highest_layer(default_layer_state)) {
        case 0:
            oled_write_ln_P(PSTR("Layer 0"), false);
            break;
    }
}
#endif
