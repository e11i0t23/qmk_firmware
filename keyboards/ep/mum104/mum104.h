// Copyright 2022 Elliot Powell (@e11i0t23)
// SPDX-License-Identifier: GPL-2,0-or-later

#pragma once

#include "quantum.h"

#define XXXX KC_NO

/* This is a shortcut to help you visually see your layout,
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys,
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix,
 */
#define LAYOUT_fullsize_iso( \
    K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012,        K600, K601, K602,                         \
    K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K603,  K604, K605, K606, K607, K608, K609, K610, \
    K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212,        K700, K701, K702, K704, K705, K706, K710, \
    K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K703,                    K707, K708, K709,       \
    K400, K401, K402, K403, K404, K405, K406, K407, K408, K409, K410, K411, K412,              K803,       K804, K805, K806, K810, \
    K500, K501, K502,                   K506,             K509, K510, K511, K512,        K800, K801, K802,    K807,   K809         \
) { \
    { K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012 }, \
    { K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112 }, \
    { K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212 }, \
    { K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312 }, \
    { K400, K401, K402, K403, K404, K405, K406, K407, K408, K409, K410, K411, K412 }, \
    { K500, K501, K502, XXXX, XXXX, XXXX, K506, XXXX, XXXX, K509, K510, K511, K512 }, \
    { K600, K601, K602, K603, K604, K605, K606, K607, K608, K609, K610, XXXX, XXXX }, \
    { K700, K701, K702, K703, K704, K705, K706, K707, K708, K709, K710, XXXX, XXXX }, \
    { K800, K801, K802, K803, K804, K805, K806, K807, XXXX, K809, K810, XXXX, XXXX }, \
}
