#include <conf_board.h>

#ifdef __cplusplus
extern "C" {
#endif

void hardware_init();
void hardware_step();

void triggerInterrupt(int interrupt);

int vgpio_get(uint32_t pin);
void vgpio_set(uint32_t pin, int value);

uint16_t vadc_get(int channel);
void vadc_set(int channel, uint16_t value);

uint16_t vdac_get(int channel);
void vdac_set(int channel, uint16_t value);

void vserial_reset();
uint8_t* vserial_read();
void vserial_write(uint8_t* buf, uint32_t byteCount);

void simulate_clock_normal_interrupt();
void simulate_external_clock_interrupt();
void simulate_front_button_interrupt();
void simulate_timer_interrupt(float sampleTime);

void simulate_monome_connect();
void simulate_monome_key(uint8_t x, uint8_t u, uint8_t val);

#ifdef __cplusplus
}
#endif
