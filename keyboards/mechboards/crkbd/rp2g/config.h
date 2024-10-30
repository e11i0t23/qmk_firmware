/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
Copyright 2021 Elliot Powell @e11i0t23

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

// SPI pins
#define SPI_DRIVER SPID1
#define SPI_SCK_PIN GP14
#define SPI_MOSI_PIN GP15
#define SPI_MISO_PIN NO_PIN

// LCD Configuration
#define LCD_RST_PIN GP11
#define LCD_CS_PIN GP13
#define LCD_DC_PIN GP12
// #define LCD_BLK_PIN GP
#define LCD_SPI_DIVISOR 4
#define LCD_SPI_MODE 0
#define LCD_WAIT_TIME 200
#define LCD_WIDTH 80
#define LCD_HEIGHT 160
#define LCD_ROTATION QP_ROTATION_180
#define LCD_OFFSET_X 26
#define LCD_OFFSET_Y 1
#define LCD_INVERT_COLOUR

#define QUANTUM_PAINTER_DISPLAY_TIMEOUT 0

// QP Configuration
#define QUANTUM_PAINTER_SUPPORTS_NATIVE_COLORS TRUE
#define ST7735_NO_AUTOMATIC_VIEWPORT_OFFSETS

#define SERIAL_USART_FULL_DUPLEX // Enable full duplex operation mode.
#define SERIAL_USART_TX_PIN GP0  // USART TX pin
#define SERIAL_USART_RX_PIN GP1  // USART RX pin

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET              // Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U // Timeout window in ms in which the double tap can occur.

#define SPLIT_TRANSACTION_IDS_KB SCR_SLV_SYNC
#define SPLIT_WPM_ENABLE
#define SPLIT_LAYER_STATE_ENABLE
