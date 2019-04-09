#include "../../hal/bcm2835.h"
#include "../inc/i2c.h"

#include <stdio.h>

#define I2C_SPEED_STANDARD_HZ 0x186A0
#define I2C_SPEED_FULL_HZ 0x61A80
#define I2C_SPEED_FAST_HZ 0xF4240
#define I2C_SPEED_HIGH_HZ 0x30D400
#define I2C_SPEED_INVALID 0x0

static uint32_t i2c_get_speed(I2cSpeed speed) {
  switch(speed){
    case I2C_SPEED_STANDARD:
      return I2C_SPEED_STANDARD_HZ;
    case I2C_SPEED_FULL:
      return I2C_SPEED_FULL_HZ;
    case I2C_SPEED_FAST:
      return I2C_SPEED_FAST_HZ;
    case I2C_SPEED_HIGH:
      return I2C_SPEED_HIGH_HZ;
    default:
      return I2C_SPEED_INVALID;
  }
}

static Status i2c_handle_communication_err(bcm2835I2CReasonCodes err) {
  switch(err) {
    case BCM2835_I2C_REASON_OK:
      return STATUS_OK;
    case BCM2835_I2C_REASON_ERROR_NACK:
      printf("ERROR: Received a NACK bit\n");
      return STATUS_FAILURE;
    case BCM2835_I2C_REASON_ERROR_CLKT:
      printf("ERROR: Received Clock Stretch Timeout\n");
      return STATUS_FAILURE;
    case BCM2835_I2C_REASON_ERROR_DATA:
      printf("ERROR: Not all I2C data was sent/received\n");
      return STATUS_FAILURE;
  }
}

Status i2c_init(const I2c *i2c) {
  if (!i2c) {
    printf("ERROR: Invalid arguments for i2c_init\n");
    return STATUS_INVALID_ARGS;
  }

  // Set the slave address
  bcm2835_i2c_setSlaveAddress(i2c->slave_address);

  // Set the i2c speed by first checking validity
  uint32_t speed = i2c_get_speed(i2c->speed);
  if (speed == I2C_SPEED_INVALID) {
    printf("ERROR: Invalid I2C speed provided\n");
    return STATUS_INVALID_ARGS;
  }

  bcm2835_i2c_set_baudrate(speed);

  // Begin I2C transactions
  if (!bcm2835_i2c_begin()) {
    printf("ERROR: Failed to initialize I2C module!\n");
    return STATUS_FAILURE;
  }

  return STATUS_OK;
}


Status i2c_read(char *rx_buffer, size_t rx_len) {
  if (!rx_buffer) {
    printf("ERROR: Invalid arguments for i2c_read\n");
    return STATUS_INVALID_ARGS;
  }

  bcm2835I2CReasonCodes rc = bcm2835_i2c_read(rx_buffer, rx_len);
  return i2c_handle_communication_err(rc);
}

Status i2c_write(const char *tx_buffer, size_t tx_len) {
  if (!tx_buffer) {
    printf("ERROR: Invalid arguments for i2c_read\n");
    return STATUS_INVALID_ARGS;
  }

  bcm2835I2CReasonCodes rc = bcm2835_i2c_write(tx_buffer, tx_len);
  return i2c_handle_communication_err(rc);
}

Status i2c_terminate() {
  bcm2835_i2c_end(); 
  return STATUS_OK;
}
