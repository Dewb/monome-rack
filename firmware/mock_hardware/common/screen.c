#include "mock_hardware_api.h"
#include "types.h"
#include <string.h>

u8 _is_screen_flipped = 0;

void init_oled(void) { }
void screen_startup(void) { }

void screen_draw_region(u8 x, u8 y, u8 w, u8 h, u8* data)
{
    u8* screen;
    uint16_t width, height;
    hardware_getScreenBuffer(&screen, &width, &height);

    if (!_is_screen_flipped)
    {
        screen += y * width + x;
        for (int j = 0; j < h; j++)
        {
            memcpy(screen, data, w);
            data += w;
            screen += width;
        }
    }
    else
    {
        screen += (height - y) * width - x - 1;
        for (int j = 0; j < h; j++)
        {
            for (int i = 0; i < w; i++)
            {
                memcpy(screen--, data++, 1);
            }
            screen -= (width - w);
        }
    }
}

void screen_draw_region_offset(u8 x, u8 y, u8 w, u8 h, u32 len, u8* data, u32 off)
{
    // this is implemented in libavr32 but not called by TT -- no need to implement at present
}

void screen_set_direction(u8 flipped)
{
    _is_screen_flipped = flipped;
}

void screen_clear(void)
{
    u8* screen;
    uint16_t width, height;
    hardware_getScreenBuffer(&screen, &width, &height);
    memset(screen, 0, sizeof(uint8_t) * width * height);
}
