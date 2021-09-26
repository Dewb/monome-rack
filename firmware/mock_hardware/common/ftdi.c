#include "mock_hardware_api.h"
#include "monome.h"
#include "types.h"
#include "events.h"
#include <string.h>

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

void ftdi_setup(void)
{

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