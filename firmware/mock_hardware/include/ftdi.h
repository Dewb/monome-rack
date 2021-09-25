#include "types.h"
#include "uhc.h"

#pragma once

#define FTDI_RX_BUF_SIZE 64
#define FTDI_STATUS_BYTES 2

void ftdi_read(void);
void ftdi_write(u8* data, u32 bytes);

void ftdi_change(uhc_device_t* dev, u8 plug);
void ftdi_setup(void);

u8* ftdi_rx_buf(void);
u8 ftdi_rx_bytes(void);
u8 ftdi_rx_busy(void);
u8 ftdi_tx_busy(void);
u8 ftdi_connected(void);
