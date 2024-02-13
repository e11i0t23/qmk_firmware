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

#include "qp.h"
#include "qp_comms.h"
#include "qp_st77xx_opcodes.h"
#include "logo/mb.qgf.h"

painter_device_t lcd;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Init board:
// - Draw logo

void keyboard_post_init_kb(void) {
    wait_ms(LCD_WAIT_TIME);

    // Initialise the LCD
    lcd = qp_st7735_make_spi_device(LCD_HEIGHT, LCD_WIDTH, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, LCD_SPI_DIVISOR, 0);
    qp_init(lcd, LCD_ROTATION);

// Invert Colour
#ifdef LCD_INVERT_COLOUR
    qp_comms_start(lcd);
    qp_comms_command(lcd, ST77XX_CMD_INVERT_ON);
    qp_comms_stop(lcd);
#endif

    // Apply Offset
    qp_set_viewport_offsets(lcd, LCD_OFFSET_X, LCD_OFFSET_Y);

    // Turn on the LCD and clear the display
    qp_power(lcd, true);
    qp_rect(lcd, 0, 0, LCD_WIDTH, LCD_HEIGHT, HSV_GREEN, true);

    // Show logo
    painter_image_handle_t logo_image = qp_load_image_mem(gfx_mb);
    qp_drawimage(lcd, 0, 0, logo_image);

    keyboard_post_init_user();
}
