#include "events.h"
#include "mock_hardware.h"
#include "monome.h"
#include "types.h"
#include <stdio.h>
#include <string.h>

typedef enum
{
    WAITING,
    WRITING_CHANNEL1_HIGH,
    WRITING_CHANNEL1_LOW,
    WRITING_CHANNEL2_HIGH,
    WRITING_CHANNEL2_LOW,
    WRITING_CHANNEL3_HIGH,
    WRITING_CHANNEL3_LOW,
    WRITING_CHANNEL4_HIGH,
    WRITING_CHANNEL4_LOW,
    WAITING_SECOND_WRITE,
    ARG1,
    ARG2
} spi_dac_state_t;

spi_dac_state_t spi_dac_state = WAITING;
u32 spi_word;
int spi_num_devices = 1;

typedef void (*clock_pulse_t)(uint8_t phase);
volatile uint8_t clock_external;

#define FTDI_STRING_MAX_LEN 64
char manufacturer_string[FTDI_STRING_MAX_LEN];
char product_string[FTDI_STRING_MAX_LEN];
char serial_string[FTDI_STRING_MAX_LEN];

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

void adc_convert(u16 adc[4])
{
    adc[0] = hardware_getADC(0);
    adc[1] = hardware_getADC(1);
    adc[2] = hardware_getADC(2);
    adc[3] = hardware_getADC(3);
}

void spi_write(u32 chip, u32 byte)
{
    switch (spi_dac_state)
    {
        case WAITING:
        {
            if (byte == 0x31)
            {
                spi_dac_state = WRITING_CHANNEL1_HIGH;
            }
            else if (byte == 0x38)
            {
                spi_dac_state = WRITING_CHANNEL2_HIGH;
            }
            else if (byte == 0x80)
            {
                spi_num_devices = 2;
                spi_dac_state = ARG1;
            }
            break;
        }
        case WAITING_SECOND_WRITE:
        {
            if (byte == 0x31)
            {
                spi_dac_state = WRITING_CHANNEL3_HIGH;
            }
            else if (byte == 0x38)
            {
                spi_dac_state = WRITING_CHANNEL4_HIGH;
            }
            else if (byte == 0x80)
            {
                spi_num_devices = 2;
                spi_dac_state = ARG1;
            }
            break;
        }
        case WRITING_CHANNEL1_HIGH:
        {
            spi_word = byte << 8;
            spi_dac_state = WRITING_CHANNEL1_LOW;
            break;
        }
        case WRITING_CHANNEL1_LOW:
        {
            spi_word |= byte;
            hardware_setDAC(0, spi_word);
            if (spi_num_devices == 1)
            {
                spi_dac_state = WAITING;
            }
            else
            {
                spi_dac_state = WAITING_SECOND_WRITE;
            }
            break;
        }
        case WRITING_CHANNEL2_HIGH:
        {
            spi_word = byte << 8;
            spi_dac_state = WRITING_CHANNEL2_LOW;
            break;
        }
        case WRITING_CHANNEL2_LOW:
        {
            spi_word |= byte;
            hardware_setDAC(1, spi_word);
            if (spi_num_devices == 1)
            {
                spi_dac_state = WAITING;
            }
            else
            {
                spi_dac_state = WAITING_SECOND_WRITE;
            }
            break;
        }
        case WRITING_CHANNEL3_HIGH:
        {
            spi_word = byte << 8;
            spi_dac_state = WRITING_CHANNEL3_LOW;
            break;
        }
        case WRITING_CHANNEL3_LOW:
        {
            spi_word |= byte;
            hardware_setDAC(2, spi_word);
            spi_dac_state = WAITING;
            break;
        }
        case WRITING_CHANNEL4_HIGH:
        {
            spi_word = byte << 8;
            spi_dac_state = WRITING_CHANNEL4_LOW;
            break;
        }
        case WRITING_CHANNEL4_LOW:
        {
            spi_word |= byte;
            hardware_setDAC(3, spi_word);
            spi_dac_state = WAITING;
            break;
        }
        case ARG1:
        {
            spi_dac_state = ARG2;
        }
        case ARG2:
        {
            spi_dac_state = WAITING;
        }
    }
}

void spi_selectChip(u32 arg1, u32 arg2) {};
void spi_unselectChip(u32 arg1, u32 arg2) {};

void* flashc_memset64(void* dst, uint64_t src, size_t nbytes, bool erase)
{
    (*(uint64_t*)dst) = src;
    return dst;
}

void* flashc_memset32(void* dst, uint32_t src, size_t nbytes, bool erase)
{
    (*(uint32_t*)dst) = src;
    return dst;
}

void* flashc_memset16(void* dst, uint16_t src, size_t nbytes, bool erase)
{
    (*(uint16_t*)dst) = src;
    return dst;
}

void* flashc_memset8(void* dst, uint8_t src, size_t nbytes, bool erase)
{
    (*(uint8_t*)dst) = src;
    return dst;
}

void* flashc_memcpy(void* dst, const void* src, size_t nbytes, bool erase)
{
    memcpy(dst, src, nbytes);
    return dst;
}

void init_gpio() { }

void init_spi() { }
void init_adc() { }

void init_tc(void) { }
void init_usb_host(void) { }

// for modules using older libavr32
void init_i2c_slave(uint8_t addr) { }
void init_i2c_master(void) { }

void init_i2c_follower(uint8_t addr) { }
void init_i2c_leader(void) { }

void register_interrupts() { }

u8* current_ftdi_message;
u32 current_ftdi_message_length;
u8 ftdiConnect;

void ftdi_read(void)
{
    hardware_readSerial_internal(FTDI_BUS, &current_ftdi_message, &current_ftdi_message_length);
}

void ftdi_write(u8* data, u32 bytes)
{
    hardware_writeSerial_internal(FTDI_BUS, data, bytes);
}

void mock_ftdi_change(u8 plug, const char* manstr, const char* prodstr, const char* serstr)
{
    event_t e;
    if (plug)
    {
        ftdiConnect = 1;
        e.type = kEventFtdiConnect;

        if (manstr != NULL && strlen(manstr) < FTDI_STRING_MAX_LEN)
        {
            strcpy(manufacturer_string, manstr);
        }
        if (prodstr != NULL && strlen(prodstr) < FTDI_STRING_MAX_LEN)
        {
            strcpy(product_string, prodstr);
        }
        if (serstr != NULL && strlen(serstr) < FTDI_STRING_MAX_LEN)
        {
            strcpy(serial_string, serstr);
        }
    }
    else
    {
        ftdiConnect = 0;
        e.type = kEventFtdiDisconnect;
    }
    event_post(&e);
}

void ftdi_setup(void)
{
    check_monome_device_desc(manufacturer_string, product_string, serial_string);
}

u8* ftdi_rx_buf(void)
{
    return current_ftdi_message;
}
u8 ftdi_rx_bytes(void)
{
    return current_ftdi_message_length;
}

u8 ftdi_rx_busy(void) { return 0; }
u8 ftdi_tx_busy(void) { return 0; }

u8 ftdi_connected(void)
{
    return ftdiConnect;
}

void cdc_write(uint8_t* data, uint32_t bytes)
{
}

void cdc_read(void)
{
}

void cdc_setup(void)
{
}

u8* cdc_rx_buf(void)
{
    return 0;
}
u8 cdc_rx_bytes(void)
{
    return 0;
}

u8 cdc_rx_busy(void) { return 0; }
u8 cdc_tx_busy(void) { return 0; }

uint8_t cdc_connected(void) 
{ 
    return false; 
}

void sysclk_init() { }

void clock_null(uint8_t phase) { }
volatile clock_pulse_t clock_pulse = &clock_null;

void init_dbg_rs232(long pba_hz) { }

void print_dbg(const char* str) { fprintf(stderr, "%s", str); }
void print_dbg_char(int c) { fprintf(stderr, "%d", c); }
void print_dbg_ulong(unsigned long n) { fprintf(stderr, "%ld", n); }
void print_dbg_char_hex(unsigned char n) { fprintf(stderr, "%x", n); }
void print_dbg_short_hex(unsigned short n) { fprintf(stderr, "%d", n); }
void print_dbg_hex(unsigned long n) { fprintf(stderr, "%lx", n); }

u8 irqs_pause(void) { return 0; }
void irqs_resume(u8 irq_flags) { }

void midi_read(void) { }
bool midi_write(const u8* data, u32 bytes) { return true; }
void midi_change(uhc_device_t* dev, u8 plug) { }
int i2c_master_tx(uint8_t addr, uint8_t* data, uint8_t l) { return 0; }
int i2c_master_rx(uint8_t addr, uint8_t* data, uint8_t l) { return 0; }

u64 get_ticks(void)
{
    static u64 tcTicks = 0;
    return tcTicks;
}

extern u8 get_revision(void)
{
    return gpio_get_pin_value(33) == 0;
}

void init_oled(void) { }
void screen_startup(void) { }

void screen_draw_region(u8 x, u8 y, u8 w, u8 h, u8* data)
{
    u8* screen;
    uint16_t width, height;
    hardware_getScreenBuffer(&screen, &width, &height);

    screen += y * width + x;

    for (int j = 0; j < h; j++)
    {
        memcpy(screen, data, w);
        data += w;
        screen += width;
    }
}

void screen_draw_region_offset(u8 x, u8 y, u8 w, u8 h, u32 len, u8* data, u32 off)
{
}

void screen_set_direction(u8 flipped)
{
}

void screen_clear(void)
{
    u8* screen;
    uint16_t width, height;
    hardware_getScreenBuffer(&screen, &width, &height);
    memset(screen, 0, sizeof(uint8_t) * width * height);
}

void tele_usb_disk() { }
