#include "mock_hardware_api.h"
#include "types.h"

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
