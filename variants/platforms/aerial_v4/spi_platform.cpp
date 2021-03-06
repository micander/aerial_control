#include "variant/spi_platform.hpp"

#include "hal.h"

SPIPlatform::SPIPlatform() {
  // SPI1
  palSetPadMode(GPIOB, 3, PAL_MODE_ALTERNATE(5) | PAL_STM32_OSPEED_HIGHEST);     // SPI1 SCK
  palSetPadMode(GPIOB, 4, PAL_MODE_ALTERNATE(5) | PAL_STM32_OSPEED_HIGHEST);     // SPI1 MISO
  palSetPadMode(GPIOB, 5, PAL_MODE_ALTERNATE(5) | PAL_STM32_OSPEED_HIGHEST);     // SPI1 MOSI

  // SPI2
  palSetPadMode(GPIOB, 13, PAL_MODE_ALTERNATE(5) | PAL_STM32_OSPEED_HIGHEST);    // SPI2 SCK
  palSetPadMode(GPIOC, 2, PAL_MODE_ALTERNATE(5) | PAL_STM32_OSPEED_HIGHEST);     // SPI2 MISO
  palSetPadMode(GPIOC, 3, PAL_MODE_ALTERNATE(5) | PAL_STM32_OSPEED_HIGHEST);     // SPI2 MOSI

  // Slave Select
  palSetPadMode(GPIOC, 13, PAL_MODE_OUTPUT_PUSHPULL | PAL_STM32_OSPEED_HIGHEST); // MS5611 CS
  palSetPadMode(GPIOC, 14, PAL_MODE_OUTPUT_PUSHPULL | PAL_STM32_OSPEED_HIGHEST); // MPU-9250 CS
  palSetPadMode(GPIOC, 15, PAL_MODE_OUTPUT_PUSHPULL | PAL_STM32_OSPEED_HIGHEST); // H3LIS331DL CS
  palSetPad(GPIOC, 13);   // Unselect
  palSetPad(GPIOC, 14);   // Unselect
  palSetPad(GPIOC, 15);   // Unselect
}
