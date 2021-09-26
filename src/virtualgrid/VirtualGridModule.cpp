#include "VirtualGridModule.hpp"
#include "LibAVR32Module.hpp"

VirtualGridModule::VirtualGridModule(unsigned w, unsigned h)
{
    config(w * h, 0, 0, w * h);

    for (unsigned j = 0; j < h; j++)
    {
        for (unsigned i = 0; i < w; i++)
        {
            int n = i + j * w;
            // set an infinite bound so it won't be serialized [and also won't be midi mappable ): ]
            configParam(n, 0.0, INFINITY, 0.0);
        }
    }

    device.width = w;
    device.height = h;
    device.port = 0;
    device.rotation = 0;
    device.id = "mv000000";
    device.prefix = "";
    device.type = "virtual " + std::to_string(w * h);

    clearAll();
    firstStep = true;
}

VirtualGridModule::~VirtualGridModule()
{
    GridConnectionManager::get()->deregisterGrid(this->device.id, false);
}

void VirtualGridModule::process(const ProcessArgs& args)
{
    if (firstStep)
    {
        GridConnectionManager::get()->registerGrid(this);
        firstStep = false;
    }

    for (int i = 0; i < device.width; i++)
    {
        for (int j = 0; j < device.height; j++)
        {
            int n = i + (j * device.width);
            bool state = params[n].getValue() > 0;
            if (state != pressedState[n])
            {
                pressedState[n] = state;
                GridConnectionManager::get()->dispatchButtonMessage(&this->device, i, j, pressedState[n]);
            }
            lights[n].setBrightness(ledBuffer[n] / 255.0);
        }
    }
}

json_t* VirtualGridModule::dataToJson()
{
    json_t* rootJ = json_object();
    json_object_set_new(rootJ, "deviceId", json_string(device.id.c_str()));
    return rootJ;
}

void VirtualGridModule::dataFromJson(json_t* rootJ)
{
    device.id = json_string_value(json_object_get(rootJ, "deviceId"));
}

const MonomeDevice& VirtualGridModule::getDevice()
{
    return device;
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
    memset(pressedState, 0, sizeof(uint8_t) * GRID_MAX_SIZE);
}
