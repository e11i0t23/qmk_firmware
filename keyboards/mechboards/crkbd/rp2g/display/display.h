
// int32_t            value_array[8]
#include "quantum.h"

typedef enum { _TIME = 0, _CPU, _GPU, _RAM, _PROGRESS, _NOWPLAYING, _IMAGE, _IMG_FS } display_data_type;

void display_init(void);
void display_housekeeping_task(void);
void draw_master(void);
void draw_slave(void);
