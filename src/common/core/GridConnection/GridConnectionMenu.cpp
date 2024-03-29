#include "GridConnectionMenu.hpp"
#include "SerialOscInterface.hpp"

using namespace rack;

struct ConnectGridItem : rack::ui::MenuItem
{
    Grid* grid;
    IGridConsumer* consumer;
    ActionQueue* actionQueue;

    void onAction(const rack::event::Action& e) override
    {
        if (actionQueue)
        {
            auto thisGrid = grid;
            auto thisConsumer = consumer;

            actionQueue->push([thisGrid, thisConsumer]() {
                GridConnectionManager::get().toggleConnection(thisGrid, thisConsumer);
            });
        }
    }
};

void menuUserReacquireGrid(IGridConsumer* consumer, std::string lastDeviceId, ActionQueue* actionQueue)
{
    for (Grid* grid : GridConnectionManager::get().getGrids())
    {
        if (lastDeviceId == grid->getDevice().id)
        {
            if (actionQueue)
            {
                actionQueue->push([grid, consumer]() {
                    GridConnectionManager::get().connect(grid, consumer);
                });
            }
            return;
        }
    }
}

void appendDeviceConnectionMenu(rack::Menu* menu, IGridConsumer* consumer, ActionQueue* actionQueue, bool hardwareOnly)
{
    std::string currentConnectedDeviceId = consumer->gridGetCurrentDeviceId();
    std::string lastConnectedDeviceId = consumer->gridGetLastDeviceId(false);

    menu->addChild(construct<MenuLabel>(&MenuLabel::text, "Device Connection"));

    if (SerialOscInterface::get()->isServiceDetected())
    {
        menu->addChild(
            construct<MenuLabel>(
                &MenuLabel::text,
                "serialosc version " + SerialOscInterface::get()->getServiceVersion()));
    }
    else
    {
        menu->addChild(
            createMenuItem("└ serialosc service not detected, click here to install", "",
                [=]()
                {
                    system::openBrowser("https://monome.org/docs/serialosc/setup/");
                }));
    }

    // enumerate registered grid devices
    int deviceCount = 0;
    bool preferredDeviceFound = false;
    for (Grid* grid : GridConnectionManager::get().getGrids())
    {
        if (hardwareOnly && !grid->isHardware())
        {
            continue;
        }

        auto connectItem = new ConnectGridItem();
        connectItem->text = "└ " + grid->getDevice().type + " (" + grid->getDevice().id + ") ";

        auto rightText = "";
        if (currentConnectedDeviceId == grid->getDevice().id)
        {
            rightText = "✔";
            preferredDeviceFound = true;
        }
        else if (currentConnectedDeviceId == "" && lastConnectedDeviceId == grid->getDevice().id)
        {
            rightText = "⋯";
            preferredDeviceFound = true;
        }

        connectItem->rightText = rightText;
        connectItem->grid = grid;
        connectItem->actionQueue = actionQueue;
        connectItem->consumer = consumer;

        menu->addChild(connectItem);
        deviceCount++;
    }

    if (deviceCount == 0)
    {
        std::string message = hardwareOnly ? "no hardware devices found" : "no hardware or virtual devices found";
        menu->addChild(construct<MenuLabel>(&MenuLabel::text, "  (" + message + ")"));
    }

    if (currentConnectedDeviceId == "" && lastConnectedDeviceId != "")
    {
        if (preferredDeviceFound)
        {
            menu->addChild(createMenuItem("Reacquire grid", "", [=]()
                {
                    if (lastConnectedDeviceId != "")
                    {
                        menuUserReacquireGrid(consumer, lastConnectedDeviceId, actionQueue);
                    }
                }
            ));
        }
        else
        {
            menu->addChild(construct<MenuLabel>(&MenuLabel::text, "Can't reacquire grid (" + lastConnectedDeviceId + " not found)"));
        }
    }
}