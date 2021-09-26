#include "VirtualGridTheme.hpp"

void levelToGradient(GridTheme theme, uint8_t level, NVGcolor* color1, NVGcolor* color2)
{
    if (theme == GridTheme::Red) 
    {
        if (color1) *color1 = nvgRGB(level * 16 + 15, level * 11 + 10, level * 2);
        if (color2) *color2 = nvgRGB(level * 16 + 15, level * 5  + 10,  level * 1);
    }
    else if (theme == GridTheme::Orange)
    {
        if (color1) *color1 = nvgRGB(level * 16 + 15, level * 13 + 15, level * 5);
        if (color2) *color2 = nvgRGB(level * 14 + 15, level * 7 + 10,  level * 3);
    }
    else if (theme == GridTheme::White)
    {
        if (color1) *color1 = nvgRGB(level * 11 + 90, level * 11 + 90, level * 8 + 96);
        if (color2) *color2 = nvgRGB(level * 9 + 48, level * 9 + 49, level * 12 + 54);
    }
    else // if (theme == GridTheme::Yellow)
    {
        if (color1) *color1 = nvgRGB(level * 11 + 90, level * 10 + 63, level * 7 + 42);
        if (color2) *color2 = nvgRGB(level * 10 + 48, level * 9 + 41, level * 3 + 12);
    }
}
