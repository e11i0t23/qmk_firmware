#pragma once

#include_next <lv_conf.h>

#define LV_MEM_SIZE 64 * 1024

#undef LV_FONT_DEFAULT
#define LV_FONT_DEFAULT &lv_font_montserrat_18

#undef LV_FONT_MONTSERRAT_14
#define LV_FONT_MONTSERRAT_14 0

#undef LV_FONT_MONTSERRAT_18
#define LV_FONT_MONTSERRAT_18 1

#undef LV_FONT_MONTSERRAT_26
#define LV_FONT_MONTSERRAT_26 1

#undef LV_FONT_MONTSERRAT_48
#define LV_FONT_MONTSERRAT_48 1
