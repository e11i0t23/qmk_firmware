#include QMK_KEYBOARD_H

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
    hide,
    fib,
    tLine,
    hLine,
    hRay,
    save,
    reset,
    undo,
    redo,
    copy,
    paste,
    buy,
    sell,
    confirm,
    search,
    macro1,
    macro2,
    macro3,
    macro4
};

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
        KC_ESC,   oneMin,    threeMin,   fifteenMin,    oneHour,      indicator,    invert,   alert,   hide,        save,
        KC_ESC,   fourHour,  day,        week,          month,        fib,          tLine,    hLine,   hRay,         reset,

        KC_NUM,                          search,        KC_DEL,                     undo,     redo,                    buy,
        KC_P7,    KC_P8,     KC_P9,      KC_PMNS,       macro1,                     copy,     paste,                   sell,
        KC_4,     KC_P5,     KC_P6,      KC_PPLS,       macro2,
        KC_P1,    KC_P2,     KC_P3,      KC_PENT,       macro3,                                                      confirm,
        KC_P0,             KC_PDOT,                     macro4,                     KC_BTN1,  KC_BTN2
    )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case oneMin:
        if (record->event.pressed) {
            SEND_STRING(",1" SS_TAP(X_ENTER));
        }
        break;
    case threeMin:
        if (record->event.pressed) {
            SEND_STRING(",3" SS_TAP(X_ENTER));
        }
        break;
    case fifteenMin:
        if (record->event.pressed) {
            SEND_STRING(",15" SS_TAP(X_ENTER));
        }
        break;
    case oneHour:
        if (record->event.pressed) {
            SEND_STRING(",1H" SS_TAP(X_ENTER));
        }
        break;
    case fourHour:
        if (record->event.pressed) {
            SEND_STRING(",4H" SS_TAP(X_ENTER));
        }
        break;

    case day:
        if (record->event.pressed) {
            SEND_STRING(",1D" SS_TAP(X_ENTER));
        }
        break;

    case week:
        if (record->event.pressed) {
            SEND_STRING(",1W" SS_TAP(X_ENTER));
        }
        break;
    case month:
        if (record->event.pressed) {
            SEND_STRING(",1M" SS_TAP(X_ENTER));
        }
        break;
    case indicator:
        if (record->event.pressed) {
            SEND_STRING("/");
        }
        break;
    case invert:
        if (record->event.pressed) {
            SEND_STRING(SS_LALT("i"));
        }
        break;
    case alert:
        if (record->event.pressed) {
            SEND_STRING(SS_LALT("a"));
        }
        break;
    case hide:
        if (record->event.pressed) {
            SEND_STRING(SS_LALT("r"));
        }
        break;
    case fib:
        if (record->event.pressed) {
            SEND_STRING(SS_LALT("f"));
        }
        break;
    case tLine:
        if (record->event.pressed) {
            SEND_STRING(SS_LALT("t"));
        }
        break;
    case hLine:
        if (record->event.pressed) {
            SEND_STRING(SS_LALT("h"));
        }
        break;
    case hRay:
        if (record->event.pressed) {
            SEND_STRING(SS_LALT("j"));
        }
        break;
    case save:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTRL("s"));
        }
        break;
    case reset:
        if (record->event.pressed) {
            SEND_STRING(SS_LALT("r"));
        }
        break;
    case undo:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTRL("z"));
        }
        break;
    case redo:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTRL("y"));
        }
        break;
    case copy:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTRL("c"));
        }
        break;
    case paste:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTRL("v"));
        }
        break;
    case buy:
        if (record->event.pressed) {
            SEND_STRING(SS_LSFT("b"));
        }
        break;
    case sell:
        if (record->event.pressed) {
            SEND_STRING(SS_LSFT("s"));
        }
        break;
    case confirm:
        if (record->event.pressed) {
            SEND_STRING(SS_LALT("j"));
        }
        break;
    case search:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTRL("k"));
        }
        break;
    case macro1:
        if (record->event.pressed) {
            SEND_STRING(SS_LALT("j"));
        }
        break;
    case macro2:
        if (record->event.pressed) {
            SEND_STRING(SS_LALT("j"));
        }
        break;
    case macro3:
        if (record->event.pressed) {
            SEND_STRING(SS_LALT("j"));
        }
        break;
    case macro4:
        if (record->event.pressed) {
            SEND_STRING(SS_LALT("j"));
        }
        break;
    }


    return true;
};
