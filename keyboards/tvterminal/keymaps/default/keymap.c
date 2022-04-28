#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ 7 │ 8 │ 9 │ / │
     * ├───┼───┼───┼───┤
     * │ 4 │ 5 │ 6 │ * │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │ - │
     * ├───┼───┼───┼───┤
     * │ 0 │ . │Ent│ + │
     * └───┴───┴───┴───┘
     */
    [0] = LAYOUT(
        KC_ESC,   oneMin,    threeMin,   fifteenMin,   oneHour,      KC_5,   KC_6,   KC_7,   KC_8,         KC_9,
        KC_0,     fourHour,  day,        week,         month,        KC_5,   KC_6,   KC_7,   KC_8,         KC_9,

        KC_NUM,                    KC_3,     KC_4,              KC_6,   KC_7,                 KC_9,
        KC_P7,   KC_P8,   KC_P9,   KC_3,     KC_4,              KC_6,   KC_7,                 KC_9,
        KC_4,    KC_P5,   KC_P6,   KC_3,     KC_4,
        KC_P1,   KC_P2,   KC_P3,   KC_3,     KC_4,                                            KC_9,
        KC_P0,          KC_PDOT,             KC_4,              KC_6,   KC_7
    )
};

enum custom_keycodes {
    oneMin = SAFE_RANGE,
    threeMin,
    fifteenMin,
    oneHour,
    fourHour,
    day,
    week,
    month,
    indicator,
    invert,
    alert,
    reset,
    fib,
    tLine,
    hLine
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case oneMin:
        if (record->event.pressed) {
            SEND_STRING("1");
        }
        break;
    case threeMin:
        if (record->event.pressed) {
            SEND_STRING("3");
        }
        break;
    case fifteenMin:
        if (record->event.pressed) {
            SEND_STRING("15");
        }
        break;
    case oneHour:
        if (record->event.pressed) {
            SEND_STRING("1H");
        }
        break;
    case fourHour:
        if (record->event.pressed) {
            SEND_STRING("4H");
        }
        break;
    }


    return true;
};
