#include "mock_hardware.h"
#include "monome.h"

void midi_read(void) { }
bool midi_write(const u8* data, u32 bytes) { return true; }
void midi_change(uhc_device_t* dev, u8 plug) { }