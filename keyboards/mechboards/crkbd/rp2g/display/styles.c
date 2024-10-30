#include "styles.h"
#include "qp_lvgl.h"

// WPM Chart
lv_style_t style_chart;

// Spotify Player Indicator
lv_style_t style_main;
lv_style_t style_indicator;
lv_style_t style_knob;

// Usage Bar
lv_style_t bar_style_bg;
lv_style_t bar_style_indic;

// Layer Button Matrix
lv_style_t style_btn_matrix;
lv_style_t style_btn;
lv_style_t style_btn_checked;

const int mb_col = 0x30b1b6;

void init_styles(void) {
    // WPM Chart
    lv_style_init(&style_chart);
    lv_style_set_bg_color(&style_chart, lv_color_hex(0x000000));
    lv_style_set_line_width(&style_chart, 0);
    lv_style_set_border_width(&style_chart, 0);

    // Spotify Player Indicator
    lv_style_init(&style_main);
    lv_style_set_bg_color(&style_main, lv_color_hex3(0xbbb));
    lv_style_set_radius(&style_main, LV_RADIUS_CIRCLE);
    lv_style_set_width(&style_main, 1);
    lv_style_init(&style_indicator);
    lv_style_set_bg_opa(&style_indicator, LV_OPA_COVER);
    lv_style_set_bg_color(&style_indicator, lv_color_hex3(0xbbb));
    lv_style_set_radius(&style_indicator, LV_RADIUS_CIRCLE);
    lv_style_init(&style_knob);
    lv_style_set_bg_opa(&style_knob, LV_OPA_COVER);
    lv_style_set_bg_color(&style_knob, lv_color_hex(mb_col));
    lv_style_set_radius(&style_knob, LV_RADIUS_CIRCLE);
    lv_style_set_pad_all(&style_knob, 1);

    // Usage Bar
    lv_style_init(&bar_style_bg);
    lv_style_set_bg_color(&bar_style_bg, lv_color_hex(0x111111));
    lv_style_set_radius(&bar_style_bg, 0);
    lv_style_init(&bar_style_indic);
    lv_style_set_bg_color(&bar_style_indic, lv_color_hex(mb_col));
    lv_style_set_radius(&bar_style_indic, 0);

    // Layer Button Matrix
    lv_style_init(&style_btn_matrix);
    lv_style_init(&style_btn);
    lv_style_init(&style_btn_checked);
    lv_style_set_bg_opa(&style_btn_matrix, LV_OPA_TRANSP); // Set transparent background
    lv_style_set_pad_all(&style_btn_matrix, 4);
    lv_style_set_pad_column(&style_btn_matrix, 1);
    lv_style_set_border_width(&style_btn_matrix, 0);
    lv_style_set_border_width(&style_btn_matrix, 0);

    lv_style_set_radius(&style_btn, 5);                              // Set rounded edges
    lv_style_set_text_color(&style_btn, lv_color_hex(0xffffff));     // Set white text color
    lv_style_set_bg_color(&style_btn, lv_color_hex(0x444444));       // Set background color
    lv_style_set_bg_color(&style_btn_checked, lv_color_hex(mb_col)); // Set background color if checked
}
