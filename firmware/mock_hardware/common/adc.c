#include "mock_hardware.h"

void adc_convert(u16 adc[4])
{
    adc[0] = hardware_getADC(0);
    adc[1] = hardware_getADC(1);
    adc[2] = hardware_getADC(2);
    adc[3] = hardware_getADC(3);
}