#include "types.h"
#include "virtual_gpio.h"

typedef unsigned long size_t;


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
   // fill out adc[0]-[1] with clock and param pots
}

void spi_write(u32 chip, u32 byte) 
{
    // store byte in CVA/CVB data
}

void spi_selectChip(u32 arg1, u32 arg2) {};
void spi_unselectChip(u32 arg1, u32 arg2) {};

volatile void *flashc_memset8(volatile void* dst, const void* src, size_t nbytes, bool erase) { return NULL; }
volatile void *flashc_memset32(volatile void* dst, const void* src, size_t nbytes, bool erase) { return NULL; }
volatile void *flashc_memcpy(volatile void* dst, const void* src, size_t nbytes, bool erase) { return NULL; }

void init_dbg_rs232(int hertz) {;;}
void init_gpio() {;;}

void init_spi() {;;}
void init_adc() {;;}

void init_tc(void) {}
void init_usb_host (void) {}
void init_i2c_slave(uint8_t addr) {}
void init_i2c_master(void) {}

void register_interrupts() {;;}

void ftdi_read(void) {;;}
void ftdi_write(u8* data, u32 bytes) {;;}

typedef void uhc_device_t;
void ftdi_change(uhc_device_t* dev, u8 plug) {;;}
void ftdi_setup(void) {;;}

u8* ftdi_rx_buf(void) { return 0; }
u8 ftdi_rx_bytes(void) { return 0; }
u8 ftdi_rx_busy(void) { return 0; }
u8 ftdi_tx_busy(void) { return 0; }
u8 ftdi_connected(void) { return 0; }

void sysclk_init() {;;}

void clock_null(uint8_t phase) {;;}
volatile uint64_t tcTicks = 0;
volatile uint8_t tcOverflow = 0;
static const uint64_t tcMax = 0x7fffffffUL;
static const uint64_t tcMaxInv = 0x10000000UL;

typedef void(*clock_pulse_t)(uint8_t phase);
volatile clock_pulse_t clock_pulse = &clock_null;
volatile uint8_t clock_external;