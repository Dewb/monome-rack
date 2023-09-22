#include "i2c.h"
#include "mock_hardware_api.h"
#include "types.h"

uint8_t last_port = 0;
int i2c_leader_tx(uint8_t addr, uint8_t* data, uint8_t l)
{
    hardware_iiPushMessage(addr, data, l);
    if (l >= 1)
    {
        last_port = data[0];
    }

    return 0;
}

int i2c_leader_rx(uint8_t addr, uint8_t* data, uint8_t l)
{
    if (l == 2)
    {
        uint16_t value = hardware_iiGetFollowerData(addr, last_port);
        data[0] = value >> 8;
        data[1] = value & 0xFF;
    }

    return 0;
}

void twi_follower_rx(uint8_t u8_value) { }
uint8_t twi_follower_tx(void) { return 0; }
void twi_follower_stop(void) { }

void ii_tx_queue(uint8_t u8_value) { }

volatile process_ii_t process_ii;
