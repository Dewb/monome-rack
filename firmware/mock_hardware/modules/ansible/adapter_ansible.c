#include "types.h"
#include "mock_hardware_api.h"


void hid_parse_frame(u8* data, u8 sz)
{
}

void process_keypress(uint8_t key, uint8_t mod_key, bool is_held_key)
{
}

void hardware_serializePreset(tt_serializer_t* stream, uint8_t preset_num)
{
}

void hardware_deserializePreset(tt_deserializer_t* stream, uint8_t preset_num)
{
}

void hardware_afterVRAMUpdate()
{
}
