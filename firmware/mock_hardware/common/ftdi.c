#include "mock_hardware.h"
#include "monome.h"
#include "events.h"
#include <string.h>

#define FTDI_STRING_MAX_LEN 64
char manufacturer_string[FTDI_STRING_MAX_LEN];
char product_string[FTDI_STRING_MAX_LEN];
char serial_string[FTDI_STRING_MAX_LEN];

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