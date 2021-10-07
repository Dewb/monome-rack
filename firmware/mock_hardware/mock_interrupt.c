#include "mock_hardware_api.h"

// libavr32 headers
#include "types.h"
#include "events.h"
#include "timers.h"


#define B08 40
#define B09 41
#define NMI 13

// state variables from module init_*.c
volatile u64 tcTicks = 0;
volatile u8 tcOverflow = 0;
static const u64 tcMax = (u64)0x7fffffff;
static const u64 tcMaxInv = (u64)0x10000000;


// reimplement function from module init_*.c
u64 get_ticks(void)
{
    return tcTicks;
}

void simulate_tc_interrupt()
{
    tcTicks++;
    // overflow control
    if (tcTicks > tcMax)
    {
        tcTicks = 0;
        tcOverflow = 1;
    }
    else
    {
        tcOverflow = 0;
    }
    process_timers();
}

void simulate_clock_normal_interrupt()
{
    event_t e;
    e.type = kEventClockNormal;
    e.data = !hardware_getGPIO(B09);
    event_post(&e);
}

void simulate_external_clock_interrupt()
{
    event_t e;
    e.type = kEventClockExt;
    e.data = hardware_getGPIO(B08);
    event_post(&e);
}

void simulate_front_button_interrupt()
{
    event_t e;
    e.type = kEventFront;
    e.data = hardware_getGPIO(NMI);
    event_post(&e);
}

void mock_gpio_interrupt(int pin)
{
    event_t e;
    e.type = kEventTrigger;
    e.data = pin;
    event_post(&e);
}

void simulate_ansible_tr_interrupt(int pin, int offset)
{
    event_t e;
    e.type = kEventTr;
    e.data = hardware_getGPIO(pin) + offset;
    event_post(&e);
}


void mock_interrupt(int interrupt)
{
    switch (interrupt)
    {
        // todo: make an enum for this
        case 0: // system clock
            simulate_tc_interrupt();
            break;
        case 1: // clock jack normal
            simulate_clock_normal_interrupt();
            break;
        case 2: // external clock rising edge
            simulate_external_clock_interrupt();
            break;
        case 3: // front button state change
            simulate_front_button_interrupt();
            break;
        case 6: // ansible input 1 change
            simulate_ansible_tr_interrupt(40, 0);
            break;
        case 7: // ansible input 2 change
            simulate_ansible_tr_interrupt(41, 2);
            break;
    }
}