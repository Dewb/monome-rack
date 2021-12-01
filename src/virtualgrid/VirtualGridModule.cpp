#include "VirtualGridModule.hpp"
#include "LibAVR32Module.hpp"

#include <iomanip>
#include <sstream>

std::string formatVirtualDeviceId(int id)
{
    std::string prefix("virt");

    std::ostringstream ss;
    ss << prefix << std::setw(6) << std::setfill('0') << id;

    return ss.str();
}

VirtualGridModule::VirtualGridModule(unsigned w, unsigned h)
{
    if (w * h > GRID_MAX_SIZE) {
        FATAL("Unsupported grid size");
        assert(0);
    }

    config(w * h, 0, 0, 0);

    for (unsigned j = 0; j < h; j++)
    {
        for (unsigned i = 0; i < w; i++)
        {
            int n = i + j * w;
            // set an infinite bound so the params won't be serialized [and also won't be midi mappable ): ]
            configParam(n, 0.0, INFINITY, 0.0);
        }
    }

    device.width = w;
    device.height = h;
    device.port = 0;
    device.rotation = 0;
    device.id = formatVirtualDeviceId(0);
    device.prefix = "";
    device.type = "virtual " + std::to_string(w * h);
    device.protocol = PROTOCOL_MEXT;

    theme = GridTheme::Yellow;

    clearAll();
}

VirtualGridModule::~VirtualGridModule()
{
}

void VirtualGridModule::onAdd()
{
    device.id = formatVirtualDeviceId(id);
}

void VirtualGridModule::process(const ProcessArgs& args)
{
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
        }
    }
}

json_t* VirtualGridModule::dataToJson()
{
    json_t* rootJ = json_object();
    json_object_set_new(rootJ, "protocol", json_integer(device.protocol));
    json_object_set_new(rootJ, "theme", json_integer(theme));
    return rootJ;
}

void VirtualGridModule::dataFromJson(json_t* rootJ)
{
    auto json_proto = json_object_get(rootJ, "protocol");
    if (json_proto)
    {
        device.protocol = static_cast<MonomeProtocol>(json_integer_value(json_proto));
    }

    auto json_theme = json_object_get(rootJ, "theme");
    if (json_theme)
    {
        theme = static_cast<GridTheme>(json_integer_value(json_theme));
    }
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
        *ptr++ = ((bitfield & (1 << i)) > 0) ? 0xF : 0;
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
