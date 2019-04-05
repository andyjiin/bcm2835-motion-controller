// I2C control class
// Requires bcm2835_init() to be called first

#ifndef I2C_H
#define I2C_H

#include "status.h"

Status i2c_init(void);

#endif // I2C_H