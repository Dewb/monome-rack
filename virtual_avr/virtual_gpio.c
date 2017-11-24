#include "virtual_gpio.h"
#include "timers.h"
#include "events.h"
#include "monome.h"

int gpioBlock[7];
uint16_t adcBlock[4];
uint16_t dacBlock[2];


int vgpio_get(uint32_t pin)
{
    if (pin == B00) { return gpioBlock[0]; }
    if (pin == B01) { return gpioBlock[1]; }
    if (pin == B02) { return gpioBlock[2]; }
    if (pin == B03) { return gpioBlock[3]; }
    if (pin == B08) { return gpioBlock[4]; }
    if (pin == B09) { return gpioBlock[5]; }
    if (pin == B10) { return gpioBlock[6]; }
    return 0;
}

void vgpio_set(uint32_t pin, int value)
{
    if (pin == B00) { gpioBlock[0] = !!value; }
    if (pin == B01) { gpioBlock[1] = !!value; }
    if (pin == B02) { gpioBlock[2] = !!value; }
    if (pin == B03) { gpioBlock[3] = !!value; }
    if (pin == B08) { gpioBlock[4] = !!value; }
    if (pin == B09) { gpioBlock[5] = !!value; }
    if (pin == B10) { gpioBlock[6] = !!value; }
}

uint16_t vadc_get(int channel)
{
    return adcBlock[channel];
}

void vadc_set(int channel, uint16_t value)
{
    adcBlock[channel] = value;
}

uint16_t vdac_get(int channel)
{
    return dacBlock[channel];
}

void vdac_set(int channel, uint16_t value)
{
    dacBlock[channel] = value;
}

void simulate_clock_normal_interrupt()
{
    event_t e;
    e.type = kEventClockNormal;
    e.data = !vgpio_get(B09);
    event_post(&e);
}

void simulate_external_clock_interrupt()
{
    event_t e;
    e.type = kEventClockExt;
    e.data = vgpio_get(B08);
    event_post(&e);
}

float phase = 0.0;
float clockRate = 0.001; // 1 ms

void simulate_timer_interrupt(float sampleTime)
{
    phase += sampleTime;
    if (phase > clockRate)
    {
        phase -= clockRate;
        process_timers();
    }
}

void simulate_monome_connect()
{
    check_monome_device_desc("m o n o m e", "", "m X X X X X X X X X");
}

void simulate_monome_key(uint8_t x, uint8_t y, uint8_t val)
{
    event_t ev;
    uint8_t* data = (uint8_t*)(&(ev.data));
    data[0] = x;
    data[1] = y;
    data[2] = val;
    ev.type = kEventMonomeGridKey;
    event_post(&ev);
}