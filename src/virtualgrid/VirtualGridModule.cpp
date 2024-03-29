#include "VirtualGridModule.hpp"
#include "LibAVR32Module.hpp"
#include "GridConsumerBase.hpp"

#include <iomanip>
#include <sstream>

struct MirrorModeGridConsumer : GridConsumerBase
{
    MirrorModeGridConsumer(VirtualGridModule* module)
        : module(module)
    {
    }

    virtual ~MirrorModeGridConsumer()
    {
    }

    void gridConnected(Grid* newConnection) override
    {
        if (newConnection == module)
        {
            // don't mirror self
            return;
        }

        GridConsumerBase::gridConnected(newConnection);

        if (module && newConnection)
        {
            // update initial LED state
            uint8_t leds[64];
            for (int x_offset = 0; x_offset < 16; x_offset += 8)
            {
                for (int y_offset = 0; y_offset < 16; y_offset += 8)
                {
                    for (int x = 0; x < 8; x++)
                    {
                        for (int y = 0; y < 8; y++)
                        {
                            leds[y * 8 + x] = module->ledBuffer[(y_offset + y) * 16 + x_offset + x];
                        }
                    }
                    newConnection->updateQuadrant(x_offset, y_offset, leds);
                }
            }
        }
    }

    void gridButtonEvent(int x, int y, bool state) override
    {
        if (module)
        {
            int w = module->device.width;
            auto param = module->getParamQuantity((x + y * w) * 2);
            if (param)
            {
                module->audioThreadActions.push([param, state]()
                    { param->setImmediateValue(state ? 1 : 0); });
            }
        }
    }

    void encDeltaEvent(int n, int d) override
    {

    }

protected:
    VirtualGridModule* module;
};

std::string formatVirtualDeviceId(int64_t id)
{
    std::ostringstream ss;
    std::string prefix("virt");

    // Rack IDs are in the range 0-2^53
    ss << prefix << std::setw(14) << std::setfill('0') << std::hex << id;
    return ss.str();
}

VirtualGridModule::VirtualGridModule(unsigned w, unsigned h)
{
    if (w * h > GRID_MAX_SIZE) {
        FATAL("Unsupported grid size");
        assert(0);
    }

    config(w * h * 2, 0, 0, 0);

    for (unsigned j = 0; j < h; j++)
    {
        for (unsigned i = 0; i < w; i++)
        {
            int n = i + j * w * 2;
            // first set of params, for midi mapping
            auto param = configButton(n, rack::string::f("(%d,%d)", i , j));
            param->resetEnabled = false;
            param->smoothEnabled = false;
            param->randomizeEnabled = false;
            // second set of params, for interactive use
            param = configButton(n + 1, rack::string::f("(%d,%d)", i, j));
            param->resetEnabled = false;
            param->smoothEnabled = false;
            param->randomizeEnabled = false;
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

    mirrorModeConsumer = new MirrorModeGridConsumer(this);

    clearAll();
}

VirtualGridModule::~VirtualGridModule()
{
    GridConnectionManager::get().deregisterGridConsumer(mirrorModeConsumer);
    delete mirrorModeConsumer;
}

void VirtualGridModule::onAdd()
{
    device.id = formatVirtualDeviceId(id);
}

void VirtualGridModule::process(const ProcessArgs& args)
{
    while (audioThreadActions.size())
    {
        audioThreadActions.shift()();
    }

    std::vector<std::tuple<int, int>> presses;
    std::vector<std::tuple<int, int>> releases;

    for (int i = 0; i < device.width; i++)
    {
        for (int j = 0; j < device.height; j++)
        {
            // we need to check the pressed state of two parameters per button,
            // one for MIDI mapping, one for interactive presses, in order to
            // prevent midi-mappings from locking a button at 0 and preventing clicking.
            int n = i + (j * device.width);
            int p = n * 2;
            bool state = (params[p].getValue() > 0) || (params[p + 1].getValue() > 0);
            if (state != pressedState[n])
            {
                pressedState[n] = state;
                if (state) {
                    presses.push_back(std::make_tuple(i, j));
                } else {
                    releases.push_back(std::make_tuple(i, j));
                }
            }
        }
    }

    // ensure any near-simultaneous releases and presses are processed releases-first
    std::for_each(releases.begin(), releases.end(), [=](std::tuple<int, int> c) {
        GridConnectionManager::get().dispatchButtonMessage(&this->device, std::get<0>(c), std::get<1>(c), false);
    });

    std::for_each(presses.begin(), presses.end(), [=](std::tuple<int, int> c) {
        GridConnectionManager::get().dispatchButtonMessage(&this->device, std::get<0>(c), std::get<1>(c), true);
    });
}

json_t* VirtualGridModule::dataToJson()
{
    json_t* rootJ = json_object();
    json_object_set_new(rootJ, "protocol", json_integer(device.protocol));
    json_object_set_new(rootJ, "theme", json_integer(theme));

    auto consumer = dynamic_cast<GridConsumerBase*>(mirrorModeConsumer);
    if (consumer)
    {
        json_t* mirrorJ = json_object();
        consumer->saveGridConnectionToJson(mirrorJ);
        json_object_set_new(rootJ, "mirror", mirrorJ);
    }

    return rootJ;
}

json_t* VirtualGridModule::paramsToJson()
{
    // don't serialize key states
    json_t* rootJ = json_array();
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

    auto consumer = dynamic_cast<GridConsumerBase*>(mirrorModeConsumer);
    if (consumer)
    {
        auto json_mirror = json_object_get(rootJ, "mirror");
        consumer->loadGridConnectionFromJson(json_mirror);
        GridConnectionManager::get().registerGridConsumer(consumer);
    }
}

const MonomeDevice& VirtualGridModule::getDevice()
{
    return device;
}

void VirtualGridModule::updateRow(int x_offset, int y, uint8_t bitfield)
{
    if (mirrorModeConsumer)
    {
        auto mirroredGrid = mirrorModeConsumer->gridGetDevice();
        if (mirroredGrid)
        {
            mirroredGrid->updateRow(x_offset, y, bitfield);
        }
    }

    uint8_t* ptr = ledBuffer + y * 16 + x_offset;
    for (int i = 0; i < 8; i++)
    {
        *ptr++ = ((bitfield & (1 << i)) > 0) ? 0xF : 0;
    }
}

void VirtualGridModule::updateQuadrant(int x_offset, int y_offset, uint8_t* leds)
{
    if (mirrorModeConsumer)
    {
        auto mirroredGrid = mirrorModeConsumer->gridGetDevice();
        if (mirroredGrid)
        {
            mirroredGrid->updateQuadrant(x_offset, y_offset, leds);
        }
    }

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

    for (auto p : params)
    {
        p.setValue(0);
    }
}
