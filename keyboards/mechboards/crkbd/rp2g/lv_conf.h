#pragma once

#include_next <lv_conf.h>

#define LV_MEM_SIZE 64 * 1024

#undef LV_FONT_CUSTOM_DECLARE
#define LV_FONT_CUSTOM_DECLARE LV_FONT_DECLARE(pixellari_24) LV_FONT_DECLARE(pixellari_18) LV_FONT_DECLARE(pixellari_14) LV_FONT_DECLARE(lv_font_montserrat_14) LV_FONT_DECLARE(lv_font_montserrat_18) LV_FONT_DECLARE(lv_font_montserrat_24)

#undef LV_FONT_DEFAULT
#define LV_FONT_DEFAULT &pixellari_18

#undef LV_FONT_MONTSERRAT_14
#define LV_FONT_MONTSERRAT_14 1

#undef LV_FONT_MONTSERRAT_18
#define LV_FONT_MONTSERRAT_18 1

#undef LV_FONT_MONTSERRAT_24
#define LV_FONT_MONTSERRAT_24 1
