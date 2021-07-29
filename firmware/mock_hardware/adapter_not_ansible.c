#include "events.h"
#include "i2c.h"
#include "mock_hardware.h"
#include "monome.h"
#include "types.h"
#include <stdio.h>
#include <string.h>

void clock_null(uint8_t phase) { }
typedef void (*clock_pulse_t)(uint8_t phase);
volatile uint8_t clock_external;
volatile clock_pulse_t clock_pulse = &clock_null;