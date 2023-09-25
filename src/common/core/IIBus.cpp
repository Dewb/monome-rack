#include "IIBus.h"
#include "LibAVR32Module.hpp"

#define FADERBANK_II_MAX_VALUE 16383

extern rack::plugin::Model* modelFaderbank;

IIBus::IIBus(LibAVR32Module* leader)
    : leader(leader)
{
}

bool IIBus::isFollower(rack::Module* module)
{
    // Only faderbanks participate in II right now
    return module != nullptr && module->model == modelFaderbank;
}

void IIBus::step()
{
    if (leader == nullptr)
    {
        return;
    }

    // let's tentatively define a bus as an unbroken chain of II-supporting
    // modules directly attached to either the left or right of the leader.

    // scan the "bus" for eligible modules, starting to the leader's left
    std::vector<rack::Module*> followers;
    auto module = leader->getLeftExpander().module;
    while (isFollower(module))
    {
        followers.push_back(module);
        module = module->getLeftExpander().module;
    }

    // flip the order, so we can prioritize left-to-right
    if (followers.size() > 1)
    {
        std::reverse(followers.begin(), followers.end());
    }

    // scan to the leader's right
    module = leader->getRightExpander().module;
    while (isFollower(module))
    {
        followers.push_back(module);
        module = module->getRightExpander().module;
    }

    // gather params from all followers
    for (size_t follower = 0; follower < std::min(static_cast<size_t>(4), followers.size()); follower++)
    {
        for (uint8_t fader = 0; fader < std::min(16, followers[follower]->getNumParams()); fader++)
        {
            auto param = followers[follower]->getParamQuantity(fader);
            if (param)
            {
                uint16_t value = static_cast<uint16_t>(param->getScaledValue() * FADERBANK_II_MAX_VALUE);
                leader->firmware.iiUpdateFollowerData(follower + 0x34, fader, value);
            }
        }
    }
}
