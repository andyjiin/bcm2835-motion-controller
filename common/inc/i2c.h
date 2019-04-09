// I2C control class which forces GPIO_PIN_3 (SDA) and GPIO_PIN_5 (SCL)
// Requires bcm2835_init() to be called first 

#ifndef I2C_H
#define I2C_H

#include "status.h"

#include <stddef.h>

typedef enum I2cSpeed {
	I2C_SPEED_STANDARD = 0,  // 100 kHz
	I2C_SPEED_FULL,			     // 400 kHz
	I2C_SPEED_FAST,			     // 1 MHz
	I2C_SPEED_HIGH,          // 3.2 MHz
	NUM_I2C_SPEEDS,
} I2cSpeed;

typedef struct I2c {
	// Address of the slave to communicate to (0x0 to )
	uint8_t slave_address;

  // I2C clock speed
	I2cSpeed speed;
} I2c;

Status i2c_init(const I2c *i2c);

Status i2c_read(char *rx_buffer, size_t rx_len);

Status i2c_write(const char *tx_buffer, size_t tx_len);

Status i2c_terminate();

#endif // I2C_H