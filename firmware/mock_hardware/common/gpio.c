#include "mock_hardware.h"

void gpio_set_gpio_pin(u32 pin)
{
    hardware_setGPIO(pin, true);
}

void gpio_clr_gpio_pin(u32 pin)
{
    hardware_setGPIO(pin, false);
}

void gpio_set_pin_high(u32 pin)
{
    hardware_setGPIO(pin, true);
}

void gpio_set_pin_low(u32 pin)
{
    hardware_setGPIO(pin, false);
}

int gpio_get_pin_value(u32 pin)
{
    return hardware_getGPIO(pin);
}
