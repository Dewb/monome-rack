#include <rack.hpp>

template<int Multiplier>
struct Clock12BitParam : rack::engine::ParamQuantity
{
    std::string getDisplayValueString() override
    {
        float v = getDisplayValue();
        if (std::isnan(v))
            return "NaN";
        uint16_t word = ((((uint16_t)(v * 1638.3) >> 4)) & 0xFFF);
        uint16_t halfPeriod = (Multiplier * 12500) / (word + 25);
        return rack::string::f("%d", 2 * halfPeriod);
    }
};