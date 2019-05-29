#include "SerialOscInterface.hpp"
#include "SerialOscGrid.hpp"

SerialOscInterface::SerialOscInterface()
{
    driver = new SerialOsc("rack", 13000);
    driver->start(this);
}

SerialOscInterface::~SerialOscInterface()
{
    driver->stop();
    delete driver;
}

void SerialOscInterface::deviceFound(const MonomeDevice* const device)
{
    GridConnectionManager::get()->registerGrid(new SerialOscGrid(device));
}

void SerialOscInterface::deviceRemoved(const std::string& id)
{
    GridConnectionManager::get()->deregisterGrid(id, true);
}

void SerialOscInterface::buttonPressMessageReceived(MonomeDevice* device, int x, int y, bool state)
{
    GridConnectionManager::get()->dispatchButtonMessage(device, x, y, state);
}

SerialOscInterface* SerialOscInterface::get()
{
    static SerialOscInterface* instance = new SerialOscInterface();
    return instance;
}