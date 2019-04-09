#include "../../hal/bcm2835.h"
#include "../inc/gpio.h"

#include <stdio.h>

Status gpio_init(const Gpio *gpio) {
	if (!gpio) {
		printf("ERROR: Invalid arguments for gpio_init\n");
		return STATUS_INVALID_ARGS;
	}

	bcm2835_gpio_fsel(gpio->pin, gpio->function);
	return STATUS_OK;
}

Status gpio_read(const Gpio *gpio, GpioState *state) {
	if (!gpio || !state) {
		return STATUS_INVALID_ARGS;
	}

	*state = bcm2835_gpio_lev(gpio->pin);
	return STATUS_OK;
}

Status gpio_write(const Gpio *gpio, const GpioState state) {
	if (!gpio) {
		return STATUS_INVALID_ARGS;
	}

	bcm2835_gpio_write(gpio->pin, state);
	return STATUS_OK;
}
