/*
Copyright 2015 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID 0xFEED
#define PRODUCT_ID 0x8080
#define DEVICE_VER 0x0001
#define MANUFACTURER Elliot Powell
#define PRODUCT EPTKL
#define DESCRIPTION qmk eptkl

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 18

#define MATRIX_ROW_PINS \
  { B11, A1, A5, A6, B8, C4 }
#define MATRIX_COL_PINS \
  { A10, B1, A2, C10, A15, A14, A13, C11, C12, D2, B4, B5, B6, B7, C13, C14, C15, F0 }
//#define MATRIX_COL_PINS { A10, B1, A2, C10, A15, C6, C7, C11, C12, D2, B4, B5, B6, B7, C13, C14, C15, F0 }
#define DIODE_DIRECTION COL2ROW

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST


#define NUMBER_OF_ENCODERS 1
#define ENCODERS_PAD_A { A9 }
#define ENCODERS_PAD_B { B14 }
#define ENCODER_RESOLUTION 2

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define RGBLIGHT_ANIMATIONS

#define WS2812_LED_N 88
#define RGBLED_NUM WS2812_LED_N
#define PORT_WS2812 GPIOA
#define PIN_WS2812 7
#define WS2812_SPI SPID1
#define RGBLIGHT_LIMIT_VAL 175

#define BACKLIGHT_LEVELS 1
#define BACKLIGHT_BREATHING
#define BREATHING_PERIOD 1

// EEPROM usage
// TODO: refactor with new user EEPROM code (coming soon)
#define EEPROM_MAGIC 0x451F
#define EEPROM_MAGIC_ADDR 32
// Bump this every time we change what we store
// This will automatically reset the EEPROM with defaults
// and avoid loading invalid data from the EEPROM
#define EEPROM_VERSION 0x02
#define EEPROM_VERSION_ADDR 34

#define DYNAMIC_KEYMAP_LAYER_COUNT 3
// Dynamic macro starts after dynamic keymaps (35+(4*5*15*2)) = (35+600) = 635
// start + layer * rows * col * 2
#define DYNAMIC_KEYMAP_EEPROM_ADDR 35
#define EEPROM_CUSTOM_BACKLIGHT 684
#define DYNAMIC_KEYMAP_MACRO_EEPROM_ADDR 685
#define DYNAMIC_KEYMAP_MACRO_EEPROM_SIZE 200
#define DYNAMIC_KEYMAP_MACRO_COUNT 16

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
