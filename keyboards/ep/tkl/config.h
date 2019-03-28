#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x8080
#define DEVICE_VER 		  0x0001
#define MANUFACTURER    Elliot Powell
#define PRODUCT         EPTKL
#define DESCRIPTION     qmk eptkl

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 18

/* Planck PCB default pin-out */
#define MATRIX_ROW_PINS { B11, A1, A5, A6, A4, C4}
//#define MATRIX_COL_PINS { A10, B1, A2, C10, A15, A14, A13, C11, C12, D2, B4, B5, B6, B7, C13, C14, C15, F0 }
#define MATRIX_COL_PINS { A10, B1, A2, C10, A15, C6, C7, C11, C12, D2, B4, B5, B6, B7, C13, C14, C15, F0 }
#define UNUSED_PINS


/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST


/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE


#define NUMBER_OF_ENCODERS 1
#define ENCODERS_PAD_A { A9 }
#define ENCODERS_PAD_B { B14 }
#define ENCODER_RESOLUTION 1
#define MIDI_ADVANCED

#define RGBLIGHT_ANIMATIONS

#define WS2812_LED_N 88
#define RGBLED_NUM WS2812_LED_N
#define PORT_WS2812     GPIOA
#define PIN_WS2812      7
#define WS2812_SPI SPID1
#define RGBLIGHT_LIMIT_VAL 175

// TODO: refactor with new user EEPROM code (coming soon)
#define EEPROM_MAGIC 0x451F
#define EEPROM_MAGIC_ADDR 32
// Bump this every time we change what we store
// This will automatically reset the EEPROM with defaults
// and avoid loading invalid data from the EEPROM
#define EEPROM_VERSION 0x08
#define EEPROM_VERSION_ADDR 34

// Backlight config starts after EEPROM version
#define RGB_BACKLIGHT_CONFIG_EEPROM_ADDR 35
// Dynamic keymap starts after backlight config (35+32)
#define DYNAMIC_KEYMAP_EEPROM_ADDR 67
#define DYNAMIC_KEYMAP_LAYER_COUNT 4
// Dynamic macro starts after dynamic keymaps (67+(4*5*14*2)) = (67+560)
#define DYNAMIC_KEYMAP_MACRO_EEPROM_ADDR 627
#define DYNAMIC_KEYMAP_MACRO_EEPROM_SIZE 398
#define DYNAMIC_KEYMAP_MACRO_COUNT 16

// Dynamic macro starts after dynamic keymaps (35+(4*6*16*2)) = (35+768) = 803

// I'm also putting my custom stuff after that
// 1 for enabled encoder modes
// 1 for custom backlighting controls
// 1 for OLED default mode
// 6 for 3x custom encoder settings, left, right, and press (18 total)

#define DYNAMIC_KEYMAP_ENABLED_ENCODER_MODES 803
#define DYNAMIC_KEYMAP_CUSTOM_ENCODER 806

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION
