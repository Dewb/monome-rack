#include <conf_board.h>

#ifdef __cplusplus
extern "C" {
#endif

int vgpio_get(uint32_t pin);
void vgpio_set(uint32_t pin, int value);

#ifdef __cplusplus
}
#endif
