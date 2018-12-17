#include "sp.h"

void i2c_init(void)
{
  setPinInput(B13); // Try releasing special pins for a short time
  setPinInput(B14);
  chThdSleepMilliseconds(10);

  palSetPadMode(GPIOB, 13, PAL_MODE_ALTERNATE(4) | PAL_STM32_OTYPE_OPENDRAIN | PAL_STM32_PUPDR_PULLUP);
  palSetPadMode(GPIOB, 14, PAL_MODE_ALTERNATE(4) | PAL_STM32_OTYPE_OPENDRAIN | PAL_STM32_PUPDR_PULLUP);

  //i2cInit(); //This is invoked by halInit() so no need to redo it.
}
