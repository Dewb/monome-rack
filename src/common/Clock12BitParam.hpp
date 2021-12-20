#include <rack.hpp>

struct Clock12BitParam : rack::engine::ParamQuantity
{
    std::string getDisplayValueString() override
    {
        float v = getDisplayValue();
        if (std::isnan(v))
            return "NaN";
        return rack::string::f("%.1f", 25000.0 / ((((uint16_t)v) >> 4) + 25));
    }
};