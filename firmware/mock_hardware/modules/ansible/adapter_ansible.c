#include "gitversion.h"
#include "types.h"

#include "mock_hardware_api.h"
#include "mock_hardware_api_private.h"

#include <string.h>

#include "main.h"
#include "flashc.h"

void hid_parse_frame(u8* data, u8 sz)
{
}

void process_keypress(uint8_t key, uint8_t mod_key, bool is_held_key)
{
}

void hardware_serializePreset(tt_serializer_t* stream, uint8_t preset_num)
{
}

void hardware_deserializePreset(tt_deserializer_t* stream, uint8_t preset_num, bool clearExisting)
{
}

nvram_data_t ansible_vram;
DECLARE_VRAM(&ansible_vram, sizeof(nvram_data_t))

void hardware_beforeReadVRAM(void* ptr, uint32_t size)
{
    save_tuning(&ansible_vram);
    save_levels(&ansible_vram);
    save_cycles(&ansible_vram);
    save_kria(&ansible_vram);
    save_mp(&ansible_vram);
    save_es(&ansible_vram);
}

void hardware_afterWriteVRAM(void* ptr, uint32_t size)
{
    init_tuning(&ansible_vram);
    init_levels(&ansible_vram);
    init_cycles(&ansible_vram);
    init_kria(&ansible_vram);
    init_mp(&ansible_vram);
    init_es(&ansible_vram);
}

void hardware_afterInit()
{
}

void hardware_afterStep()
{
}

void hardware_getVersion(char* buffer)
{
    strcpy(buffer, git_version);
}

double hardware_getClockPeriod()
{
    return 0.001;
}
