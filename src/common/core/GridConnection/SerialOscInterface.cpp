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

bool SerialOscInterface::isServiceDetected() const
{
    return driver->isServiceDetected();
}

std::string SerialOscInterface::getServiceVersion() const
{
    return driver->getVersionString();
}

void SerialOscInterface::deviceFound(const MonomeDevice* const device)
{
    if (!device)
    {
        return;
    }

    // don't register the same device id twice
    for (auto grid : GridConnectionManager::get().getGrids())
    {
        if (grid->getDevice().id == device->id)
        {
            return;
        }
    }

    GridConnectionManager::get().registerGrid(new SerialOscGrid(device));
}

void SerialOscInterface::deviceRemoved(const std::string& id)
{
    GridConnectionManager::get().deregisterGrid(id, true);
}

void SerialOscInterface::buttonPressMessageReceived(MonomeDevice* device, int x, int y, bool state)
{
    GridConnectionManager::get().dispatchButtonMessage(device, x, y, state);
}

void SerialOscInterface::encDeltaMessageReceived(MonomeDevice* device, int n, int d)
{
    GridConnectionManager::get().dispatchEncDeltaMessage(device, n, d);
}

SerialOscInterface* SerialOscInterface::get()
{
    static SerialOscInterface* instance = new SerialOscInterface();
    return instance;
}