#include "mock_hardware.h"
#include "types.h"
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
    vgpio_set(pin, 1);
}

void gpio_clr_gpio_pin(u32 pin)
{
    vgpio_set(pin, 0);
}

int gpio_get_pin_value(u32 pin)
{
    return vgpio_get(pin);
}

void adc_convert(u16* adc)
{
    adc[0] = vadc_get(0);
    adc[1] = vadc_get(1);
    adc[2] = vadc_get(2);
    adc[3] = vadc_get(3);
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
            vdac_set(0, spi_word);
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
            vdac_set(1, spi_word);
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

void init_dbg_rs232(int hertz) {}
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
    vserial_write(data, bytes);
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
