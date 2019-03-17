#include "status.h"

typedef enum {
	GPIO_FUNC_INPUT = BCM2835_GPIO_FSEL_INPT, 
    GPIO_FUNC_OUTPUT = BCM2835_GPIO_FSEL_OUTP,
    GPIO_FUNC_ALT0 = BCM2835_GPIO_FSEL_ALT0, 
    GPIO_FUNC_ALT1 = BCM2835_GPIO_FSEL_ALT1,
    GPIO_FUNC_ALT2 = BCM2835_GPIO_FSEL_ALT2, 
    GPIO_FUNC_ALT3 = BCM2835_GPIO_FSEL_ALT3, 
    GPIO_FUNC_ALT4 = BCM2835_GPIO_FSEL_ALT4, 
    GPIO_FUNC_ALT5 = BCM2835_GPIO_FSEL_ALT5,
    GPIO_FUNC_MASK = BCM2835_GPIO_FSEL_MASK,
} gpio_function;

typedef struct {
	uint8_t pin;
	gpio_function function;
} gpio_settings;

Status gpio_init(const gpio_settings *settings);