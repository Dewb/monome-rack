#include "VirtualGridModule.hpp"
#include "MonomeModuleBase.hpp"

VirtualGridModule::VirtualGridModule(unsigned w, unsigned h)
    : Module(w * h, 0, 0, 0)
{
    device.width = w;
    device.height = h;
    device.port = 0;
    device.rotation = 0;
    device.id = "mv000000";
    device.prefix = "";
    device.type = "virtual " + std::to_string(w * h);

    clearAll();
}

void VirtualGridModule::step()
{
    if (connectedModule)
    {
        for (int i = 0; i < device.width; i++)
        {
            for (int j = 0; j < device.height; j++)
            {
                int n = i + (j * device.width);
                if ((params[n].value > 0) != pressedState[n])
                {
                    connectedModule->buttonPressMessageReceived(NULL, i, j, params[n].value > 0);
                    pressedState[n] = params[n].value > 0;
                }
            }
        }
    }
    else
    {
        clearAll();
    }
}

json_t* VirtualGridModule::toJson()
{
    json_t* rootJ = json_object();
    json_object_set_new(rootJ, "deviceId", json_string(device.id.c_str()));
    return rootJ;
}

void VirtualGridModule::fromJson(json_t* rootJ)
{
    device.id = json_string_value(json_object_get(rootJ, "deviceId"));
}

void VirtualGridModule::updateRow(int x_offset, int y, uint8_t bitfield)
{
    uint8_t* ptr = ledBuffer + y * 16 + x_offset;
    for (int i = 0; i < 8; i++)
    {
        *ptr++ = ((bitfield & (1 << i)) > 0) ? 104 : 0;
    }
}

void VirtualGridModule::updateQuadrant(int x_offset, int y_offset, uint8_t* leds)
{
    uint8_t* ptr = ledBuffer + y_offset * 16 + x_offset;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            *ptr++ = *leds++;
        }
        ptr += 8;
    }
}

void VirtualGridModule::clearAll()
{
    memset(ledBuffer, 0, sizeof(uint8_t) * GRID_MAX_SIZE);
}
