#include "VirtualGridTheme.hpp"

NVGcolor themeColors[4][16][2];

// e^kx - 1 / e^k - 1 easing function
int ease(int level, int minval, int maxval, float curve)
{
    int range = maxval - minval;
    float y = (exp(curve * level / 15.0) - 1) / (exp(curve) - 1);
    return (int)floor(y * range) + minval;
}

NVGcolor calcColor(int level, float curve, int minR, int maxR, int minG, int maxG, int minB, int maxB)
{
    return nvgRGB(ease(level, minR, maxR, curve), ease(level, minG, maxG, curve), ease(level, minB, maxB, curve));
}

void initThemes()
{
    float curve0 = -2.7;
    float curve1 = -2.2;

    for (int level = 0; level < 16; level++)
    {
        themeColors[GridTheme::Red][level][0] = calcColor(level, curve0, 20, 255, 15, 175, 5, 30);
        themeColors[GridTheme::Red][level][1] = calcColor(level, curve1, 15, 255, 10, 85, 0, 15);

        themeColors[GridTheme::Orange][level][0] = calcColor(level, curve0, 15, 255, 15, 210, 0, 75);
        themeColors[GridTheme::Orange][level][1] = calcColor(level, curve1, 12, 225, 10, 115, 0, 45);

        themeColors[GridTheme::White][level][0] = calcColor(level, curve0, 30, 255, 22, 255, 22, 207);
        themeColors[GridTheme::White][level][1] = calcColor(level, curve1, 15, 160, 15, 170, 15, 224);

        themeColors[GridTheme::Yellow][level][0] = calcColor(level, curve0, 22, 255, 22, 250, 21, 142);
        themeColors[GridTheme::Yellow][level][1] = calcColor(level, curve1, 9, 203, 3, 176, 6, 217);
    }
}

void levelToGradient(GridTheme theme, uint8_t level, NVGcolor* color1, NVGcolor* color2)
{
    if (theme >= 0 && theme < 4 && level >= 0 && level < 16)
    {
        if (color1)
        {
            *color1 = themeColors[theme][level][0];
        }
        if (color2)
        {
            *color2 = themeColors[theme][level][1];
        }
    }
}
