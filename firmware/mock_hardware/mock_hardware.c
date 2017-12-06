#include "mock_hardware.h"
#include "events.h"
#include "monome.h"
#include "timers.h"
#include <stdio.h>
#include <string.h>

#define GPIO_NUM_PINS 43
bool gpioBlock[GPIO_NUM_PINS];

uint16_t adcBlock[4];
uint16_t dacBlock[2];

#define VSERIAL_BUFFER_SIZE 128
#define VSERIAL_MAX_MESSAGES 32

uint8_t* vserial_out_buffer = NULL;
int vserial_out_read_index = 0;
int vserial_out_write_index = 0;

uint8_t* vserial_in_buffer = NULL;
int vserial_in_read_index = 0;
int vserial_in_write_index = 0;

float phase = 0.0;
float clockRate = 0.001; // 1 ms

void* nvram_ptr;
void* vram_ptr;
uint32_t nvram_size;
uint32_t vram_size;

// hardware interface points
extern void initialize_module(void);
extern void check_events(void);

void simulate_clock_normal_interrupt()
{
    event_t e;
    e.type = kEventClockNormal;
    e.data = !hardware_getGPIO(B09);
    event_post(&e);
}

void simulate_external_clock_interrupt()
{
    event_t e;
    e.type = kEventClockExt;
    e.data = hardware_getGPIO(B08);
    event_post(&e);
}

void simulate_front_button_interrupt()
{
    event_t e;
    e.type = kEventFront;
    e.data = hardware_getGPIO(NMI);
    event_post(&e);
}

void simulate_trigger_interrupt(int pin)
{
    event_t e = { .type = kEventTrigger, .data = pin };
    event_post(&e);
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

void hardware_init()
{
    hardware_initSerial();
    initialize_module();
    simulate_monome_connect();
}

void hardware_step()
{
    uint8_t* msg = hardware_readSerial_internal(0);
    while (msg)
    {
        if (msg[0] == 0xF0)
        {
            simulate_monome_key(msg[1], msg[2], msg[3]);
        }
        msg = hardware_readSerial_internal(0);
    }

    hardware_resetSerial();

    check_events();
}

void hardware_triggerInterrupt(int interrupt)
{
    switch (interrupt)
    {
        case 0: // system clock
            process_timers();
            break;
        case 1: // clock jack normal
            simulate_clock_normal_interrupt();
            break;
        case 2: // external clock rising edge
            simulate_external_clock_interrupt();
            break;
        case 3: // front button pressed
            simulate_front_button_interrupt();
            break;
    }
}

bool hardware_getGPIO(uint32_t pin)
{
    if (pin >= 0 && pin < GPIO_NUM_PINS)
    {
        return gpioBlock[pin];
    }
    return false;
}

void hardware_setGPIO(uint32_t pin, bool value)
{
    if (pin >= 0 && pin < GPIO_NUM_PINS)
    {
        // Check for interrupt on pins A00-A07
        bool changed = false;
        if (pin < 8 && gpioBlock[pin] != value)
        {
            changed = true;
        }

        gpioBlock[pin] = value;

        if (changed)
        {
            simulate_trigger_interrupt(pin);
        }
    }
}

uint16_t hardware_getADC(int channel)
{
    return adcBlock[channel];
}

void hardware_setADC(int channel, uint16_t value)
{
    adcBlock[channel] = value;
}

uint16_t hardware_getDAC(int channel)
{
    return dacBlock[channel];
}

void hardware_setDAC(int channel, uint16_t value)
{
    dacBlock[channel] = value;
}

void hardware_initSerial()
{
    if (vserial_in_buffer == NULL)
    {
        vserial_in_buffer = (uint8_t*)malloc(VSERIAL_BUFFER_SIZE * VSERIAL_MAX_MESSAGES * sizeof(uint8_t));
    }

    if (vserial_out_buffer == NULL)
    {
        vserial_out_buffer = (uint8_t*)malloc(VSERIAL_BUFFER_SIZE * VSERIAL_MAX_MESSAGES * sizeof(uint8_t));
    }

    hardware_resetSerial();
}

void hardware_resetSerial()
{
    vserial_in_read_index = 0;
    vserial_in_write_index = 0;
    vserial_out_read_index = 0;
    vserial_out_write_index = 0;
}

uint8_t* hardware_readSerial(int bus)
{
    if (vserial_out_read_index >= vserial_out_write_index)
    {
        return NULL;
    }

    return vserial_out_buffer + VSERIAL_BUFFER_SIZE * vserial_out_read_index++;
}

void hardware_writeSerial_internal(int bus, uint8_t* buf, uint32_t byteCount)
{
    if (vserial_out_buffer && vserial_out_write_index < VSERIAL_MAX_MESSAGES)
    {
        uint8_t* dest = vserial_out_buffer + VSERIAL_BUFFER_SIZE * vserial_out_write_index++;
        memcpy(dest, buf, byteCount <= VSERIAL_BUFFER_SIZE ? byteCount : VSERIAL_BUFFER_SIZE);
    }
    else
    {
        //fprintf(stderr, "Cannot write to outgoing serial line, buffer full.\n");
    }
}

uint8_t* hardware_readSerial_internal(int bus)
{
    if (vserial_in_read_index >= vserial_in_write_index)
    {
        return NULL;
    }

    return vserial_in_buffer + VSERIAL_BUFFER_SIZE * vserial_in_read_index++;
}

void hardware_writeSerial(int bus, uint8_t* buf, uint32_t byteCount)
{
    if (vserial_in_buffer && vserial_in_write_index < VSERIAL_MAX_MESSAGES)
    {
        uint8_t* dest = vserial_in_buffer + VSERIAL_BUFFER_SIZE * vserial_in_write_index++;
        memcpy(dest, buf, byteCount <= VSERIAL_BUFFER_SIZE ? byteCount : VSERIAL_BUFFER_SIZE);
    }
    else
    {
        //fprintf(stderr, "Cannot write to incoming serial line, buffer full.\n");
    }
}

void hardware_declareNVRAM(const void* ptr, uint32_t size)
{
    nvram_ptr = ptr;
    nvram_size = size;
}

void hardware_readNVRAM(void** ptr, uint32_t* size)
{
    *ptr = nvram_ptr;
    *size = nvram_size;
}

void hardware_writeNVRAM(const void* src, uint32_t size)
{
    memcpy(nvram_ptr, src, nvram_size >= size ? size : nvram_size);
}

void hardware_declareVRAM(const void* ptr, uint32_t size)
{
    vram_ptr = ptr;
    vram_size = size;
}

void hardware_readVRAM(void** ptr, uint32_t* size)
{
    *ptr = vram_ptr;
    *size = vram_size;
}

void hardware_writeVRAM(const void* src, uint32_t size)
{
    memcpy(vram_ptr, src, vram_size >= size ? size : vram_size);
}