#include "mock_hardware.h"
#include "events.h"
#include "hid.h"
#include "monome.h"
#include "timers.h"
#include <stdio.h>
#include <string.h>

#define GPIO_NUM_PINS 50
bool gpioBlock[GPIO_NUM_PINS];

uint16_t adcBlock[4];
uint16_t dacBlock[4];

#define VSERIAL_BUFFER_SIZE 128
#define VSERIAL_MAX_MESSAGES 32

uint8_t* vserial_out_buffer = NULL;
int vserial_out_read_index = 0;
int vserial_out_write_index = 0;
uint32_t vserial_out_message_size[VSERIAL_MAX_MESSAGES];

uint8_t* vserial_in_buffer = NULL;
int vserial_in_read_index = 0;
int vserial_in_write_index = 0;
uint32_t vserial_in_message_size[VSERIAL_MAX_MESSAGES];

float phase = 0.0;
float clockRate = 0.001; // 1 ms

void* nvram_ptr = NULL;
void* vram_ptr = NULL;
uint32_t nvram_size = 0;
uint32_t vram_size = 0;

uint8_t* screenBuffer = NULL;
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// hardware interface points
extern void initialize_module(void);
extern void check_events(void);

extern void mock_ftdi_change(u8 plug, const char* manstr, const char* prodstr, const char* serstr);
extern void process_keypress(uint8_t key, uint8_t mod_key, bool is_held_key, bool is_release);

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

void simulate_ansible_key_interrupt(int pin, int offset)
{
    event_t e = { .type = kEventKey, .data = hardware_getGPIO(pin) + offset };
    event_post(&e);
}

void simulate_trigger_interrupt(int pin)
{
    event_t e = { .type = kEventTrigger, .data = pin };
    event_post(&e);
}

void simulate_ansible_tr_interrupt(int pin, int offset)
{
    event_t e = { .type = kEventTr, .data = hardware_getGPIO(pin) + offset };
    event_post(&e);
}

extern void set_funcs();
extern void monome_connect_write_event();

// protocol enumeration
typedef enum
{
    eProtocol40h, /// 40h and arduinome protocol (pre-2007)
    eProtocolSeries, /// series protocol (2007-2011)
    eProtocolMext, /// extended protocol (2011 - ? ), arcs + grids
    eProtocolNumProtocols // dummy and count
} eMonomeProtocol;

// device descriptor
typedef struct e_monomeDesc
{
    eMonomeProtocol protocol;
    eMonomeDevice device;
    u8 cols; // number of columns
    u8 rows; // number of rows
    u8 encs; // number of encoders
    u8 tilt; // has tilt (??)
    u8 vari; // is variable brightness, true/false
} monomeDesc;

extern monomeDesc mdesc;

static void simulate_monome_setup_mext(int rows, int cols)
{
    ftdi_setup();
    mdesc.protocol = eProtocolMext;
    mdesc.vari = 1;
    mdesc.device = eDeviceGrid;
    mdesc.rows = rows;
    mdesc.cols = cols;
    mdesc.tilt = 1;
    set_funcs();
    monome_connect_write_event();
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

void hardware_hidMessage(uint8_t key, uint8_t mod, bool held, bool release)
{
    process_keypress(key, mod, held, release);
}

void hardware_hidConnect()
{
    event_t ev;
    ev.type = kEventHidConnect;
    event_post(&ev);
}

void hardware_hidDisconnect()
{
    event_t ev;
    ev.type = kEventHidDisconnect;
    event_post(&ev);
}

void hardware_init()
{
    hardware_initSerial();
    initialize_module();
}

void hardware_step()
{
    uint8_t* msg;
    uint32_t count;

    hardware_resetSerialOut();

    check_events();

    hardware_readSerial_internal(FTDI_BUS, &msg, &count);
    while (msg)
    {
        if (msg[0] == 0xF0 && count >= 4)
        {
            simulate_monome_key(msg[1], msg[2], msg[3]);
        }
        hardware_readSerial_internal(FTDI_BUS, &msg, &count);
    }

    hardware_resetSerialIn();
}

void hardware_triggerInterrupt(int interrupt)
{
    switch (interrupt)
    {
        // todo: make an enum for this
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
        case 4: // panel key1 pressed
            simulate_ansible_key_interrupt(38, 0);
            break;
        case 5: // panel key2 pressed
            simulate_ansible_key_interrupt(39, 2);
            break;
        case 6: // input 1 change
            simulate_ansible_tr_interrupt(40, 0);
            break;
        case 7: // input 2 change
            simulate_ansible_tr_interrupt(41, 2);
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

        // Trigger interrupt only on rising edge
        if (changed && value)
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

    hardware_resetSerialIn();
    hardware_resetSerialOut();
}

void hardware_resetSerialIn()
{
    vserial_in_read_index = 0;
    vserial_in_write_index = 0;
}

void hardware_resetSerialOut()
{
    vserial_out_read_index = 0;
    vserial_out_write_index = 0;
}

void hardware_serialConnectionChange(serial_bus_t bus, uint8_t connected, const char* manufacturer, const char* product, const char* serial)
{
    if (bus == FTDI_BUS)
    {
        //mock_ftdi_change(connected, manufacturer, product, serial);
        simulate_monome_setup_mext(8, 16);
    }
    else if (bus == HID_BUS)
    {
    }
}

void hardware_readSerial(serial_bus_t bus, uint8_t** pbuf, uint32_t* pcount)
{
    if (vserial_out_read_index >= vserial_out_write_index)
    {
        *pbuf = NULL;
        *pcount = 0;
    }
    else
    {

        *pbuf = vserial_out_buffer + VSERIAL_BUFFER_SIZE * vserial_out_read_index;
        *pcount = vserial_out_message_size[vserial_out_read_index];
        vserial_out_read_index++;
    }
}

void hardware_writeSerial_internal(serial_bus_t bus, uint8_t* buf, uint32_t byteCount)
{
    if (vserial_out_buffer && vserial_out_write_index < VSERIAL_MAX_MESSAGES)
    {
        uint8_t* dest = vserial_out_buffer + VSERIAL_BUFFER_SIZE * vserial_out_write_index;
        memcpy(dest, buf, byteCount <= VSERIAL_BUFFER_SIZE ? byteCount : VSERIAL_BUFFER_SIZE);
        vserial_out_message_size[vserial_out_write_index] = byteCount;
        vserial_out_write_index++;
    }
    else
    {
        //fprintf(stderr, "Cannot write to outgoing serial line, buffer full.\n");
    }
}

void hardware_readSerial_internal(serial_bus_t bus, uint8_t** pbuf, uint32_t* pcount)
{
    if (vserial_in_read_index >= vserial_in_write_index)
    {
        *pbuf = NULL;
        *pcount = 0;
    }
    else
    {
        *pbuf = vserial_in_buffer + VSERIAL_BUFFER_SIZE * vserial_in_read_index;
        *pcount = vserial_in_message_size[vserial_in_read_index];
        vserial_in_read_index++;
    }
}

void hardware_writeSerial(serial_bus_t bus, uint8_t* buf, uint32_t byteCount)
{
    if (vserial_in_buffer && vserial_in_write_index < VSERIAL_MAX_MESSAGES)
    {
        uint8_t* dest = vserial_in_buffer + VSERIAL_BUFFER_SIZE * vserial_in_write_index;
        memcpy(dest, buf, byteCount <= VSERIAL_BUFFER_SIZE ? byteCount : VSERIAL_BUFFER_SIZE);
        vserial_in_message_size[vserial_in_write_index] = byteCount;
        vserial_in_write_index++;
    }
    else
    {
        //fprintf(stderr, "Cannot write to incoming serial line, buffer full.\n");
    }
}

void hardware_declareNVRAM(void* ptr, uint32_t size)
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

void hardware_declareVRAM(void* ptr, uint32_t size)
{
    vram_ptr = ptr;
    vram_size = size;
}

void hardware_readVRAM(void** ptr, uint32_t* size)
{
    if (ptr)
    {
        *ptr = vram_ptr;
    }
    if (size)
    {
        *size = vram_size;
    }
}

void hardware_writeVRAM(const void* src, uint32_t size)
{
    memcpy(vram_ptr, src, vram_size >= size ? size : vram_size);
}

void hardware_getScreenBuffer(uint8_t** ptr, uint16_t* width, uint16_t* height)
{
    if (!screenBuffer)
    {
        screenBuffer = (uint8_t*)malloc(sizeof(uint8_t) * SCREEN_WIDTH * SCREEN_HEIGHT);
        memset(screenBuffer, 0, sizeof(uint8_t) * SCREEN_WIDTH * SCREEN_HEIGHT);

        // initialize a distinctive pattern for debugging purposes
        for (int j = 0; j < SCREEN_HEIGHT; j++)
        {
            for (int i = 0; i < SCREEN_WIDTH; i++)
            {
                if ((j / 16) % 2)
                {
                    screenBuffer[i + SCREEN_WIDTH * j] = i % 16;
                }
                else
                {
                    screenBuffer[i + SCREEN_WIDTH * j] = 15 - (i % 16);
                }
            }
        }
    }
    if (ptr)
    {
        *ptr = screenBuffer;
    }
    if (width)
    {
        *width = 128;
    }
    if (height)
    {
        *height = 64;
    }
}