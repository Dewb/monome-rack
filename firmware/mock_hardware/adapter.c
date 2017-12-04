#include "mock_hardware.h"
#include "types.h"
#include <stdio.h>
#include <string.h>

typedef enum {
    WAITING,
    WRITING_CVA_HIGH,
    WRITING_CVA_LOW,
    WRITING_CVB_HIGH,
    WRITING_CVB_LOW
} spi_dac_state_t;

spi_dac_state_t spi_dac_state = WAITING;
u32 spi_word;

u8 queryresponse[] = { 0, 1, 2, 0, 0, 0 };

typedef void uhc_device_t;

volatile uint64_t tcTicks = 0;
volatile uint8_t tcOverflow = 0;

typedef void (*clock_pulse_t)(uint8_t phase);
volatile uint8_t clock_external;

void gpio_set_gpio_pin(u32 pin)
{
    hardware_setGPIO(pin, 1);
}

void gpio_clr_gpio_pin(u32 pin)
{
    hardware_setGPIO(pin, 0);
}

void gpio_set_pin_high(u32 pin)
{
    hardware_setGPIO(pin, 1);
}

void gpio_set_pin_low(u32 pin)
{
    hardware_setGPIO(pin, 0);
}

int gpio_get_pin_value(u32 pin)
{
    return hardware_getGPIO(pin);
}

void adc_convert(u16* adc)
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
                spi_dac_state = WRITING_CVA_HIGH;
            }
            else if (byte == 0x38)
            {
                spi_dac_state = WRITING_CVB_HIGH;
            }
            break;
        }
        case WRITING_CVA_HIGH:
        {
            spi_word = byte << 4;
            spi_dac_state = WRITING_CVA_LOW;
            break;
        }
        case WRITING_CVA_LOW:
        {
            spi_word |= byte;
            hardware_setDAC(0, spi_word);
            spi_dac_state = WAITING;
            break;
        }
        case WRITING_CVB_HIGH:
        {
            spi_word = byte << 4;
            spi_dac_state = WRITING_CVB_LOW;
            break;
        }
        case WRITING_CVB_LOW:
        {
            spi_word |= byte;
            hardware_setDAC(1, spi_word);
            spi_dac_state = WAITING;
            break;
        }
    }
}

void spi_selectChip(u32 arg1, u32 arg2){};
void spi_unselectChip(u32 arg1, u32 arg2){};

void* flashc_memset64(void* dst, uint64_t src, size_t nbytes, bool erase)
{
    memcpy(dst, &src, sizeof(uint64_t));
    return dst;
}

void* flashc_memset32(void* dst, uint32_t src, size_t nbytes, bool erase)
{
    return flashc_memset64(dst, src | (uint64_t)src << 32, nbytes, erase);
}

void* flashc_memset16(void* dst, uint16_t src, size_t nbytes, bool erase)
{
    return flashc_memset32(dst, src | (uint32_t)src << 16, nbytes, erase);
}

void* flashc_memset8(void* dst, uint8_t src, size_t nbytes, bool erase)
{
    return flashc_memset16(dst, src | (uint16_t)src << 8, nbytes, erase);
}

void* flashc_memcpy(void* dst, const void* src, size_t nbytes, bool erase)
{
    memcpy(dst, src, nbytes);
    return dst;
}

void init_gpio() {}

void init_spi() {}
void init_adc() {}

void init_tc(void) {}
void init_usb_host(void) {}
void init_i2c_slave(uint8_t addr) {}
void init_i2c_master(void) {}

void register_interrupts() {}

void ftdi_read(void) {}
void ftdi_write(u8* data, u32 bytes)
{
    hardware_writeSerial_internal(0, data, bytes);
}

void ftdi_change(uhc_device_t* dev, u8 plug) {}
void ftdi_setup(void) {}

u8* ftdi_rx_buf(void) { return queryresponse; }
u8 ftdi_rx_bytes(void) { return 6; }
u8 ftdi_rx_busy(void) { return 0; }
u8 ftdi_tx_busy(void) { return 0; }
u8 ftdi_connected(void) { return 0; }

void sysclk_init() {}

void clock_null(uint8_t phase) {}
volatile clock_pulse_t clock_pulse = &clock_null;

void init_dbg_rs232(long pba_hz) {}

void print_dbg(const char* str) { fprintf(stderr, "%s", str); }
void print_dbg_char(int c) { fprintf(stderr, "%d", c); }
void print_dbg_ulong(unsigned long n) { fprintf(stderr, "%ld", n); }
void print_dbg_char_hex(unsigned char n) { fprintf(stderr, "%x", n); }
void print_dbg_short_hex(unsigned short n) { fprintf(stderr, "%d", n); }
void print_dbg_hex(unsigned long n) { fprintf(stderr, "%lx", n); }

int i2c_master_tx(uint8_t addr, uint8_t* data, uint8_t l) { return 0; }
int i2c_master_rx(uint8_t addr, uint8_t* data, uint8_t l) { return 0; }

u64 get_ticks(void)
{
    return tcTicks;
}

void hid_change(uhc_device_t* dev, u8 plug) {}
u8 hid_get_byte_flag(u8 byte)
{
    return 0;
}
void hid_parse_frame(u8* frame, u8 size) {}
const u8* hid_get_frame_data(void)
{
    return 0;
}

const u32 hid_get_frame_dirty(void)
{
    return 0;
}

void hid_clear_frame_dirty(void) {}
const u8 hid_get_frame_size(void) {}

void init_oled(void) {}
void screen_draw_region(u8 x, u8 y, u8 w, u8 h, u8* data) {}
void screen_draw_region_offset(u8 x, u8 y, u8 w, u8 h, u32 len, u8* data, u32 off) {}
void screen_clear(void) {}
void screen_startup(void) {}

u8 irqs_pause(void) { return 0; }
void irqs_resume(u8 irq_flags) {}

void tele_usb_disk() {}
