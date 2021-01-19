#pragma once

#include "quantum.h"


#define LAYOUT( \
      k0000, K000,       K001, K002, K003, K004, K005, K006, K007, K008, K009, K011, K012, K013,       K014, K015, k016,\
             K500, K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K111, K112, K113,       K114, K115, k116,\
             K501, K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K211, K212, K213,       K214, K215, k216,\
             K502, K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K311, K312,                              \
             K503, K400, K401, K402, K403, K404, K405, K406, K407, K408, K409, K411, K412,                   K415,      \
             K504, K505, K506,                   K507,                   K509, K511, K512, K513,       K514, K515, k516 \
) \
{ \
    {k0000,   K000, KC_NO, K001, K002,  K003,  K004,  K005, K006,  K007,  K008,  K009, K011,  K012, K013,       K014,  K015,  k016 }, \
	{KC_NO,   K500, K100,  K101, K102,  K103,  K104,  K105, K106,  K107,  K108,  K109, K111,  K112, K113,       K114,  K115,  k116 },\
    {KC_NO,   K501, K200,  K201, K202,  K203,  K204,  K205, K206,  K207,  K208,  K209, K211,  K212, K213,       K214,  K215,  k216 },\
	{KC_NO,   K502, K300,  K301, K302,  K303,  K304,  K305, K306,  K307,  K308,  K309, K311,  K312, KC_NO,      KC_NO, KC_NO, KC_NO}, \
    {KC_NO,   K503, K400,  K401, K402,  K403,  K404,  K405, K406,  K407,  K408,  K409, K411,  K412, KC_NO,      KC_NO, K415,  KC_NO}, \
	{KC_NO,   K504, K505,  K506, KC_NO, KC_NO, KC_NO, K507, KC_NO, KC_NO, KC_NO, K509, K511,  K512, K513,       K514,  K515,  k516 } \
}
