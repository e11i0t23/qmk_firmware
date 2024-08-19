
// int32_t            value_array[8]
#include "quantum.h"

typedef enum { _TIME = 0, _MEM, _CPU_FREQ, _CPU_TEMP, _GPU_TEMP, _GPU_MEM, _VOL, _NOWPLAYING, _IMAGE, _IMG_FS } display_data_type;

void display_init(void);
void display_housekeeping_task(void);
