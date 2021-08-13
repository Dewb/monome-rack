#include "iiBus.h"

iiFollowerData_t iiBus::FollowerData;

void iiBus::Initialize()
{
    for (int device = 0x34; device <= 0x37; device++) 
    {
        for (int fader = 0; fader < 16; fader++)
        {
            iiBus::FollowerData.emplace(std::make_pair((device << 8) | fader, 0));
        }
    }
}

void iiDevice::setAddress(uint8_t address)
{
    _address = address;
}

void iiDevice::updateFollowerData(uint8_t id, uint16_t data)
{
    const auto record = iiBus::FollowerData.find((_address << 8) | id);
    if (record != iiBus::FollowerData.end()) 
    {
        record->second.store(data, std::memory_order_relaxed);
    }
}