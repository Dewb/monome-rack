#include "mock_hardware_api.h"
#include "mock_hardware_api_private.h"
#include "mock_serial.h"
#include "mock_interrupt.h"

#include "events.h"
#include "hid.h"

#include "cbbq.h"
//#include "test/cbbq_utils.h"

#include <stdio.h>
#include <string.h>


#define GPIO_NUM_PINS 50
bool gpioBlock[GPIO_NUM_PINS];

uint16_t adcBlock[4];
uint16_t dacBlock[4];

#define VSERIAL_IN_BUFFER_SIZE 512
#define VSERIAL_OUT_BUFFER_SIZE 512

cbbq serial_in_queue;
cbbq serial_out_queue;

void* nvram_ptr = NULL;
void* vram_ptr = NULL;
uint32_t nvram_size = 0;
uint32_t vram_size = 0;

uint8_t* screenBuffer = NULL;
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// main interface points to module code -- the two halves of main() in the original source
extern void initialize_module(void);
extern void check_events(void);

// this *could* be simulated as an event, but key press/hold has already been calculated in glfw,
// and getting module timing assumptions right is tricky, so just let's just skip to the handler
extern void process_keypress(uint8_t key, uint8_t mod_key, bool is_held_key, bool is_release);


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

void initialize_serial()
{
    queue_init(&serial_in_queue, VSERIAL_IN_BUFFER_SIZE);
    queue_init(&serial_out_queue, VSERIAL_OUT_BUFFER_SIZE);
}

void hardware_init()
{
    initialize_serial();
    initialize_module();
    hardware_afterInit();
}

void hardware_step()
{
    check_events();
    hardware_afterStep();
}

void hardware_triggerInterrupt(int interrupt)
{
    mock_interrupt(interrupt);
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
            mock_gpio_interrupt(pin);
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

void hardware_postEvent(uint32_t type, uint32_t data)
{
    event_t e;
    e.type = type;
    e.data = data;
    event_post(&e);
}

void hardware_serialConnectionChange(bool connected, uint8_t type, uint8_t protocol, uint8_t width, uint8_t height)
{
    mock_monome_serial_setup(connected, type, protocol, width, height);
}

int hardware_readSerial(uint8_t** pbuf, uint8_t* pcount)
{
    int ret = queue_read(&serial_out_queue, pbuf, pcount);
    // queue_display(&serial_out_queue);
    // printf("hardware_readSerial queue_read returned: %d\n", ret);
    return ret;
}

int hardware_writeSerial_internal(uint8_t* buf, uint8_t byteCount)
{
    int ret = queue_write(&serial_out_queue, buf, byteCount);
    // queue_display(&serial_out_queue);
    // printf("hardware_writeSerial_internal queue_write returned: %d\n", ret);
    return ret;
}

int hardware_readSerial_internal(uint8_t** pbuf, uint8_t* pcount)
{
    int ret = queue_read(&serial_in_queue, pbuf, pcount);
    // queue_display(&serial_in_queue);
    // printf("hardware_readSerial_internal queue_read returned: %d\n", ret);
    return ret;
}

int hardware_writeSerial(uint8_t* buf, uint8_t byteCount)
{
    int ret = queue_write(&serial_in_queue, buf, byteCount);
    // queue_display(&serial_in_queue);
    // printf("hardware_writeSerial queue_write returned: %d\n", ret);
    return ret;
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
    hardware_beforeReadVRAM(vram_ptr, vram_size);

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
    hardware_afterWriteVRAM(vram_ptr, vram_size);
}

void hardware_getScreenBuffer(uint8_t** ptr, uint16_t* width, uint16_t* height)
{
    if (ptr) *ptr = screenBuffer;
    if (width)
        *width = 128;
    if (height)
        *height = 64;
}

void hardware_setScreenBuffer(uint8_t* buf)
{
    screenBuffer = buf;
}

// TODO: make this generic for all followers somehow
uint16_t faderbank[16];

void hardware_iiUpdateFollowerData(uint16_t key, uint16_t data)
{
    if (key >> 8 == 0x34)
    {
        faderbank[key & 0xFF] = data;
    }
}

uint16_t hardware_iiGetFollowerData(uint16_t key)
{
    if (key >> 8 == 0x34)
    {
        return faderbank[key & 0xFF];
    }
    return 0;
}

#define II_MAX_DATA 8
#define II_MAX_MESSAGES 32

typedef struct 
{
    uint8_t addr;
    uint8_t data[II_MAX_DATA];
    uint8_t length;
} iiMessage;

iiMessage iiMessageBuffer[II_MAX_MESSAGES];
size_t iiMessageBufferIndex = 0;

bool hardware_iiPushMessage(uint8_t addr, uint8_t* data, uint8_t length)
{
    if (iiMessageBufferIndex < II_MAX_MESSAGES && length <= II_MAX_DATA) {
        iiMessageBuffer[iiMessageBufferIndex].addr = addr;
        iiMessageBuffer[iiMessageBufferIndex].length = length;
        memcpy(iiMessageBuffer[iiMessageBufferIndex].data, data, length);
        iiMessageBufferIndex++;
        return true;
    }
    return false;
}

bool hardware_iiPopMessage(uint8_t* addr, uint8_t* data, uint8_t* length)
{
    if (iiMessageBufferIndex > 0)
    {
        if (addr) {
            *addr = iiMessageBuffer[iiMessageBufferIndex].addr;
        }
        if (length) {
            *length = iiMessageBuffer[iiMessageBufferIndex].length;
        }
        if (data && *length <= II_MAX_DATA) {
            memcpy(data, iiMessageBuffer[iiMessageBufferIndex].data, *length);
        }
        iiMessageBufferIndex--;
        return true;
    }
    return false;
}
