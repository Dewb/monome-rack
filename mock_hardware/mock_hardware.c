#include "mock_hardware.h"
#include "timers.h"
#include "events.h"
#include "monome.h"
#include <string.h>

int gpioBlock[8];
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
    if (pin == NMI) { return gpioBlock[7]; }
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
    if (pin == NMI) { gpioBlock[7] = !!value; }
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

#define VSERIAL_BUFFER_SIZE 72
#define VSERIAL_MAX_MESSAGES 12

uint8_t* vserial_buffer = NULL;
int vserial_read_index = 0;
int vserial_write_index = 0;

void vserial_reset()
{
    if (vserial_buffer == NULL)
    {
        vserial_buffer = (uint8_t*)malloc(VSERIAL_BUFFER_SIZE * VSERIAL_MAX_MESSAGES * sizeof(uint8_t));
    }
    vserial_read_index = 0;
    vserial_write_index = 0;
}

uint8_t *vserial_read()
{
    if (vserial_read_index >= vserial_write_index)
    {
        return NULL;
    }

    return vserial_buffer + VSERIAL_BUFFER_SIZE * vserial_read_index++;
}
void vserial_write(uint8_t *buf, uint32_t byteCount)
{
    if (vserial_buffer)
    {
        uint8_t* dest = vserial_buffer + VSERIAL_BUFFER_SIZE * vserial_write_index++;
        memcpy(dest, buf, byteCount <= VSERIAL_BUFFER_SIZE ? byteCount : VSERIAL_BUFFER_SIZE);
    }
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

void simulate_front_button_interrupt()
{
    event_t e;
    e.type = kEventFront;
    e.data = vgpio_get(NMI);
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