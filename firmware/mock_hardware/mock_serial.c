// libavr32 headers
#include "monome.h"

#include <stdint.h>
#include <stdbool.h>

// types and declarations private to monome.c not in monome.h

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

extern void set_funcs();


// end types and declarations from monome.c

// private functions in mock_hardware_api.c
extern int hardware_readSerial_internal(uint8_t** pbuf, uint8_t* pcount);
extern int hardware_writeSerial_internal(uint8_t* buf, uint8_t byteCount);

u8* mock_serial_current_message_buffer;
u8 mock_serial_current_message_length;
bool mock_serial_isconnected = false;

u8 mock_serial_connected() 
{
    return mock_serial_isconnected ? 1 : 0;
}

void mock_serial_read(void)
{
    if (hardware_readSerial_internal(&mock_serial_current_message_buffer, &mock_serial_current_message_length) > 0)
    {
        (*monome_read_serial)();
    }
}

void mock_serial_write(u8* data, u32 bytes)
{
    hardware_writeSerial_internal(data, bytes);
}

volatile u8 mock_serial_tx_busy()
{
    return 0;
}

volatile u8 mock_serial_rx_busy()
{
    return 0;
}

u8* mock_serial_rx_buf(void)
{
    return mock_serial_current_message_buffer;
}

u8 mock_serial_rx_bytes(void)
{
    return mock_serial_current_message_length;
}

void setup_mock_serial()
{
    serial_read = &mock_serial_read;
    serial_write = &mock_serial_write;
    tx_busy = &mock_serial_tx_busy;
    rx_busy = &mock_serial_rx_busy;
    rx_buf = &mock_serial_rx_buf;
    rx_bytes = &mock_serial_rx_bytes;
    serial_connected = &mock_serial_connected;
}

void mock_monome_serial_setup(bool connected, uint8_t protocol, uint8_t width, uint8_t height)
{
    if (connected)
    {
        // fill out the global mdesc structure
        mdesc.protocol = (eMonomeProtocol)protocol;
        mdesc.vari = mdesc.protocol == eProtocolMext;
        mdesc.device = eDeviceGrid;
        mdesc.rows = height;
        mdesc.cols = width;
        mdesc.tilt = 1;

        // set device-specific event handlers based on the global mdesc
        set_funcs();
        setup_mock_serial();

        // push a connection event
        event_t ev;
        ev.type = kEventMonomeConnect;
        u8* data = (u8*)(&(ev.data));
        *data++ = (u8)(mdesc.device);
        *data++ = mdesc.cols;
        *data++ = mdesc.rows;
        event_post(&ev);

        mock_serial_isconnected = true;
    }
    else
    {
        // push a disconnect event
        event_t ev;
        ev.type = kEventMonomeDisconnect;
        event_post(&ev);

        mock_serial_isconnected = false;
    }
}

