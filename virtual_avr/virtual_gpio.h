#include <conf_board.h>

#ifdef __cplusplus
extern "C" {
#endif

int vgpio_get(uint32_t pin);
void vgpio_set(uint32_t pin, int value);

uint16_t vadc_get(int channel);
void vadc_set(int channel, uint16_t value);

uint16_t vdac_get(int channel);
void vdac_set(int channel, uint16_t value);

void simulate_clock_normal_interrupt();
void simulate_external_clock_interrupt();
void simulate_timer_interrupt(float sampleTime);

#ifdef __cplusplus
}
#endif
