#pragma once
#include "rack.hpp"

typedef enum
{
    Red,
    Orange,
    Yellow,
    White,
    NUM_THEMES
} GridTheme;

void levelToGradient(GridTheme theme, uint8_t level, NVGcolor* color1, NVGcolor* color2);
void initThemes();