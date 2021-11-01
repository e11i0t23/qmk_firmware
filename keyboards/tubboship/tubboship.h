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

#pragma once

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define Layout( \
	                                                                                                                                                            K026, K027, K028, K029, K030, K031, K032, K033, K034, K035, K036, K037,                   \
	                                                                                                                                                            K126, K127, K128, K129, K130, K131, K132, K133, K134, K135, K136, K137,                  \
	K200, K201,       K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, K215, K216, K415, K218, K219, K220,       K222, K223, K224, K225,                                                                                     \
	K300, K301,       K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, K315, K316,       K318, K319, K320,       K322, K323, K324, K325,                                                                                     \
	K400, K401,       K403, K404, K405, K406, K407, K408, K409, K410, K411, K412, K413, K414,       K416,       K418, K419, K420,       K422, K423, K424, K425,                                                                                     \
	K500, K501,       K503, K504, K505, K506, K507, K508, K509, K510, K511, K512, K513, K514, K515, K516,       K518, K519, K520,       K522, K523, K524, K525,                                                                                     \
	K600, K601,       K603, K604, K605,                   K609,             K612, K613, K614, K615, K616,       K618, K619, K620,       K622, K623, K624, K625  \
) { \
	{ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, K026,  K027,  K028,  K029,  K030,  K031   }, \
	{ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, K126,  K127,  K128,  K129,  K130,  K131   }, \
	{ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, K032,  K033,  K034,  K035,  K036,  K037   }, \
	{ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, K132,  K133,  K134,  K135,  K136,  K137   }, \
	{ K200,  K201,  K203,  K204,  K205,  K206,  K207,  K208,  K209,  K210,  K211,  K212,  K213,  K214,  K215,  K216,  K218,  K219,  K220,  K222,  K223,  K224,  K225,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO  }, \
	{ K300,  K301,  K303,  K304,  K305,  K306,  K307,  K308,  K309,  K310,  K311,  K312,  K313,  K314,  K315,  K316,  K318,  K319,  K320,  K322,  K323,  K324,  K325,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO  }, \
	{ K400,  K401,  K403,  K404,  K405,  K406,  K407,  K408,  K409,  K410,  K411,  K412,  K413,  K414,  K415,  K416,  K418,  K419,  K420,  K422,  K423,  K424,  K425,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO  }, \
	{ K500,  K501,  K503,  K504,  K505,  K506,  K507,  K508,  K509,  K510,  K511,  K512,  K513,  K514,  K515,  K516,  K518,  K519,  K520,  K522,  K523,  K524,  K525,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO  }, \
	{ K600,  K601,  K603,  K604,  K605,  KC_NO, KC_NO, KC_NO, K609,  KC_NO, KC_NO, K612,  K613,  K614,  K615,  K616,  K618,  K619,  K620,  K622,  K623,  K624,  K625,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO  }  \
}
