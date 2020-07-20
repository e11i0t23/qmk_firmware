/*
Copyright 2020 Elliot Powell

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

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x4550
#define PRODUCT_ID      0x4C53
#define DEVICE_VER      0x0001
#define MANUFACTURER    Elliot Powell
#define PRODUCT         Lets Split Hotswap edition
#define DESCRIPTION     A HotSwap Lets Split

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 8
#define MATRIX_COLS 6

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5
#define USE_SERIAL

/* Let's Split EH? pin-out */
#define MATRIX_ROW_PINS { F1, F0, B7, F5 }
#define MATRIX_COL_PINS { F4, D5, B3, B2, B1, B0 }
#define UNUSED_PINS

#define DIODE_DIRECTION COL2ROW

/* ws2812 RGB LED */
#define RGB_DI_PIN F6
#define RGBLED_NUM 20    // Number of LEDs (each hand)
#define RGBLED_SPLIT { 10, 10 }
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_LIMIT_VAL 160

/* Split Defines */
#define EE_HANDS
#define SOFT_SERIAL_PIN E6
#define SPLIT_USB_DETECT
#define SELECT_SOFT_SERIAL_SPEED 2

