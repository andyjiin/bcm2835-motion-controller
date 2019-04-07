// I2C control class which forces GPIO_PIN_3 (SDA) and GPIO_PIN_5 (SCL)
// Requires bcm2835_init() to be called first 

#ifndef I2C_H
#define I2C_H

#include "status.h"

#define I2C_SPEED_STANDARD_HZ 100000
#define I2C_SPEED_FULL_HZ 400000
#define I2C_SPEED_FAST_HZ 1000000
#define I2C_SPEED_HIGH_HZ 3200000

typedef struct I2c {
	// Address of the slave to communicate to (0x0 to )
	uint8_t slave_address;

	uint32_t speed;
} I2c;

Status i2c_init(void);

Status i2c_read(const I2c *i2c, char *rx_buffer, size_t rx_len);

Status i2c_write(const I2c *i2c, char *tx_buffer, size_t tx_len);

#endif // I2C_H