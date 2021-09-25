#include "mock_hardware_api.h"
#include "types.h"

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