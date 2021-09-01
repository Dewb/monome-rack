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

iiDevice::iiDevice(rack::Module* module)
: _module(module)
{
    if (_module) 
    {
        _module->rightExpander.producerMessage = new iiCommand();
        _module->leftExpander.producerMessage = new iiCommand();
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

void iiDevice::transmit(const iiCommand& msg)
{
    if (_module) 
    {
        if (_module->rightExpander.producerMessage)
        {
            *(reinterpret_cast<iiCommand*>(_module->rightExpander.producerMessage)) = msg;
            _module->rightExpander.messageFlipRequested = true;
        }
        if (_module->leftExpander.producerMessage)
        {
            *(reinterpret_cast<iiCommand*>(_module->leftExpander.producerMessage)) = msg;
            _module->leftExpander.messageFlipRequested = true;
        }
    }
}