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

Status i2c_read(const I2c *i2c, char *rx_buffer, size_t rx_len) {
	bcm2835_i2c_setSlaveAddress(i2c->slave_address);
    bcm2835_i2c_set_baudrate(i2c->speed);
    bcm2835_i2c_end(); 
	return STATUS_OK;
}

Status i2c_write(const I2c *i2c, char *tx_buffer, size_t tx_len) {
	return STATUS_OK;
}
