#include "../../hal/bcm2835.h"
#include "../inc/i2c.h"

#include <stdio.h>

Status i2c_init(void) {
	if (!bcm2835_i2c_begin()) {
    printf("ERROR: Failed to initialize I2C module!\n");
    return STATUS_FAILURE;
  }

  return STATUS_OK;
}


