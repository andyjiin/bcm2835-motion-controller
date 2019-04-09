// GPIO control class
// Requires bcm2835_init() to be called first

#ifndef GPIO_H
#define GPIO_H

#include "status.h"

typedef enum {
    GPIO_STATE_HIGH = HIGH,
    GPIO_STATE_LOW = LOW,
    NUM_GPIO_STATES
} GpioState;

typedef enum {
	GPIO_FUNCTION_INPUT = BCM2835_GPIO_FSEL_INPT, 
    GPIO_FUNCTION_OUTPUT = BCM2835_GPIO_FSEL_OUTP,
    GPIO_FUNCTION_ALT0 = BCM2835_GPIO_FSEL_ALT0, 
    GPIO_FUNCTION_ALT1 = BCM2835_GPIO_FSEL_ALT1,
    GPIO_FUNCTION_ALT2 = BCM2835_GPIO_FSEL_ALT2, 
    GPIO_FUNCTION_ALT3 = BCM2835_GPIO_FSEL_ALT3, 
    GPIO_FUNCTION_ALT4 = BCM2835_GPIO_FSEL_ALT4, 
    GPIO_FUNCTION_ALT5 = BCM2835_GPIO_FSEL_ALT5,
    GPIO_FUNCTION_MASK = BCM2835_GPIO_FSEL_MASK,
    NUM_GPIO_FUNCTIONS
} GpioFunction;

typedef enum {
    GPIO_PIN_3 = RPI_GPIO_P1_03,
    GPIO_PIN_5 = RPI_GPIO_P1_05,
    GPIO_PIN_7 = RPI_GPIO_P1_07,
    GPIO_PIN_8 = RPI_GPIO_P1_08,    // Pin P1-08, defaults to alt function 0 UART0_TXD
    GPIO_PIN_10 = RPI_GPIO_P1_10,   // Defaults to alt function 0 UART0_RXD
    GPIO_PIN_11 = RPI_GPIO_P1_11,
    GPIO_PIN_12 = RPI_GPIO_P1_12,   // PWM channel 0 in ALT FUN 5
    GPIO_PIN_13 = RPI_GPIO_P1_13,
    GPIO_PIN_15 = RPI_GPIO_P1_15,
    GPIO_PIN_16 = RPI_GPIO_P1_16,
    GPIO_PIN_18 = RPI_GPIO_P1_18,
    GPIO_PIN_19 = RPI_GPIO_P1_19,   // MOSI when SPI0 in use
    GPIO_PIN_21 = RPI_GPIO_P1_21,   // MISO when SPI0 in use
    GPIO_PIN_22 = RPI_GPIO_P1_22,
    GPIO_PIN_23 = RPI_GPIO_P1_23,   // CLK when SPI0 in use
    GPIO_PIN_24 = RPI_GPIO_P1_24,   // CE0 when SPI0 in use
    GPIO_PIN_26 = RPI_GPIO_P1_26,   // CE1 when SPI0 in use
    NUM_GPIO_PINS,
} GpioPin;

typedef struct Gpio {
    // GPIO pin
    GpioPin pin;

    // GPIO pin function
    GpioFunction function;
} Gpio;

Status gpio_init(const Gpio *gpio);

Status gpio_read(const Gpio *gpio, GpioState *state);

Status gpio_write(const Gpio *gpio, const GpioState state);

#endif // GPIO_H
