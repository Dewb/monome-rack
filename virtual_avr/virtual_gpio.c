#include "virtual_gpio.h"

int gpioBlock[6];

int vgpio_get(uint32_t pin)
{
    if (pin == B00) { return gpioBlock[0]; }
    if (pin == B01) { return gpioBlock[1]; }
    if (pin == B02) { return gpioBlock[2]; }
    if (pin == B03) { return gpioBlock[3]; }
    if (pin == B09) { return gpioBlock[4]; }
    if (pin == B10) { return gpioBlock[5]; }
    return 0;
}

void vgpio_set(uint32_t pin, int value)
{
    if (pin == B00) { gpioBlock[0] = value; }
    if (pin == B01) { gpioBlock[1] = value; }
    if (pin == B02) { gpioBlock[2] = value; }
    if (pin == B03) { gpioBlock[3] = value; }
    if (pin == B09) { gpioBlock[4] = value; }
    if (pin == B10) { gpioBlock[5] = value; }
}

