/*
Copyright 2021 Elliot Powell

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
#include "tvterminal.h"

bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) { return false; }
    if (index == 0) {
        switch (biton32(layer_state)){
        case 1:
            if (clockwise) {
                tap_code(KC_MS_WH_UP);
            } else {
                tap_code(KC_MS_WH_DOWN);
            }
            break;
        default:
            if (clockwise) {
                tap_code(KC_MS_WH_RIGHT);
            } else {
                tap_code(KC_MS_WH_LEFT);
            }
            break;
        }
    }
    return true;
}
