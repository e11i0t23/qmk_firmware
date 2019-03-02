#include "ch.h"

#include "timer.h"

static systime_t last_systime = 0;
static systime_t overflow = 0;
static uint64_t current_time_ms = 0;

void timer_init(void) {
	timer_clear();
}

void timer_clear(void) {
	 last_systime = chVTGetSystemTime();
	 overflow = 0;
	 current_time_ms = 0;
}

uint16_t timer_read(void)
{
    return (uint16_t)timer_read32();
}

uint32_t timer_read32(void)
{
	systime_t current_systime = chVTGetSystemTime();
	systime_t elapsed = current_systime - last_systime + overflow;
	uint64_t elapsed_ms = TIME_I2MS(elapsed);
	current_time_ms += elapsed_ms;
//	overflow = elapsed - TIME_MS2I(elapsed_ms);
	last_systime = current_systime;

    return (uint32_t)current_time_ms;
}

uint16_t timer_elapsed(uint16_t last)
{
    return (uint16_t)(TIME_I2MS(chVTTimeElapsedSinceX(TIME_MS2I(last))));
}

uint32_t timer_elapsed32(uint32_t last)
{
    return TIME_I2MS(chVTTimeElapsedSinceX(TIME_MS2I(last)));
}
