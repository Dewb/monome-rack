#include <rack.hpp>

template<int Multiplier, int DividerModeWhenInputPatched = -1>
struct Clock12BitParam : rack::engine::ParamQuantity
{
    std::string divisorLabels[9] = {
        "1/16", "1/8", "1/4", "1/2", "1", "2", "4", "8", "16"
    };

    bool isDividerMode()
    {
        return
            DividerModeWhenInputPatched >= 0 &&
            module &&
            module->inputs[DividerModeWhenInputPatched].isConnected();
    }

    std::string getDisplayValueString() override
    {
        float v = getDisplayValue();
        if (std::isnan(v))
            return "NaN";

        uint16_t word = ((((uint16_t)(v * 1638.3) >> 4)) & 0xFFF);

        if (isDividerMode())
        {
            int div = rack::math::clamp((word << 2) / 455, 0, 8);
            unit = "x";
            return divisorLabels[div];
        }
        else
        {
            uint16_t period = 2 * (Multiplier * 12500) / (word + 25);
            unit = "ms";
            return rack::string::f("%d", period);
        }
    }

    void setDisplayValueString(std::string s) override
    {
        if (isDividerMode())
        {
            // remove any whitespace
            s.erase(std::remove_if(s.begin(), s.end(), isspace), s.end());
            s = s == "1/1" ? "1" : s;

            for (int i = 0; i < 9; i++)
            {
                if (s == divisorLabels[i])
                {
                    uint16_t word = (i * 455 + 227) << 2;
                    setImmediateValue(word * (10.0 / 16383.0) + 0.0007);
                    return;
                }
            }
        }
        else
        {
            ParamQuantity::setDisplayValueString(s);
        }
    }

    void setDisplayValue(float dv) override
    {
        uint16_t period = rack::math::clamp((int)floor(dv), 22 * Multiplier, 1000 * Multiplier);
        uint16_t word = (Multiplier * 12500 / (period / 2) - 25) << 4;
        setImmediateValue(word * (10.0 / 16383.0) + 0.0007);
    }
};