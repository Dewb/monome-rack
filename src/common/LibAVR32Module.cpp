#include "LibAVR32Module.hpp"
#include "base64.h"
#include <string.h>


LibAVR32Module::LibAVR32Module(std::string firmwareName)
: firmwareName(firmwareName)
{
    gridConnection = nullptr;
    firstStep = true;
    reloadRequested = ReloadRequest::None;

    dacOffsetVolts = 0.0007;
    triggerThresholdVolts = 2.21;

    firmware.load(firmwareName);
    firmware.init();
}

LibAVR32Module::~LibAVR32Module()
{
    GridConnectionManager::get()->deregisterGridConsumer(this);
}

void LibAVR32Module::gridConnected(Grid* newConnection)
{
    if (gridConnection != nullptr)
    {
        firmware.serialConnectionChange(false, 0, 0, 0);
    }

    gridConnection = newConnection;
    if (gridConnection)
    {
        std::string id = gridConnection->getDevice().id;
        lastConnectedDeviceId = id;

        auto d = gridConnection->getDevice();
        firmware.serialConnectionChange(true, d.protocol, d.width, d.height);
    }
}

void LibAVR32Module::gridDisconnected(bool ownerChanged)
{
    gridConnection = nullptr;
    firmware.serialConnectionChange(false, 0, 0, 0);
    if (ownerChanged)
    {
        lastConnectedDeviceId = "";
    }
}

void LibAVR32Module::gridButtonEvent(int x, int y, bool state)
{
    // send grid press as serial event
    if (gridConnection)
    {
        switch (gridConnection->getDevice().protocol)
        {
            case PROTOCOL_40H:
                {
                    uint8_t msg[2] = {
                        (uint8_t)(state ? 0x01 : 0x00),
                        (uint8_t)(((0x0F & x) << 4) | (0x0F & y))
                     };
                    firmware.writeSerial(msg, 2);
                }
                break;

            case PROTOCOL_SERIES:
                {
                    uint8_t msg[2] = {
                        (uint8_t)(state ? 0x00 : 0x10),
                        (uint8_t)(((0x0F & x) << 4) | (0x0F & y))
                    };
                    firmware.writeSerial(msg, 2);
                }
                break;

            case PROTOCOL_MEXT:
                {
                    uint8_t msg[3] = {
                        (uint8_t)(state ? 0x21 : 0x20),
                        (uint8_t)x,
                        (uint8_t)y
                    };
                    firmware.writeSerial(msg, 3);
                }
                break;

            default:
                break;
        }
    }

    // alternative: send grid press directly to event queue
    // performance is surprisingly much worse!
    // uint32_t data = (0xF & x) | ((0xF & y) << 8) | ((state ? 0 : 1) << 16);
    // firmware.postEvent(16 /* kEventMonomeGridKey */, data);
}

std::string LibAVR32Module::gridGetLastDeviceId()
{
    return lastConnectedDeviceId;
}

void LibAVR32Module::readSerialMessages()
{
    uint8_t* msg;
    uint8_t count;

    if (firmware.readSerial(&msg, &count) > 0)
    {
        if ((msg[0] & 0xF0) == 0x70)
        {
            while ((msg[0] & 0xF0) == 0x70 && count >= 2)
            {
                // 40h protocol row update
                uint8_t y = msg[0] & 0x0F;
                uint8_t bitfield = msg[1];

                if (gridConnection)
                {
                    gridConnection->updateRow(0, y, bitfield);
                }

                if (count > 2) // there are more 0x7x two-byte commands in this serial message
                {
                    msg += 2;
                    count -= 2;
                }
                else
                {
                    break;
                }
            }
        }
        else if (msg[0] == 0x1A && count >= 35)
        {
            // mext protocol quadrant update
            uint8_t x = msg[1];
            uint8_t y = msg[2];
            uint8_t leds[64];
            for (int i = 0; i < 32; i++)
            {
                leds[2 * i + 0] = msg[3 + i] >> 4;
                leds[2 * i + 1] = msg[3 + i] & 0xF;
            }

            if (gridConnection)
            {
                gridConnection->updateQuadrant(x, y, leds);
            }
        }
        else if ((msg[0] & 0xF0) == 0x80 && count >= 9)
        {
            // series protocol quadrant update
            int x = (msg[0] & 0x1) * 8;
            int y = (msg[0] & 0x2) * 8;
            uint8_t leds[64];
            for (int j = 0; j < 8; j++)
            {
                for (int i = 0; i < 8; i++)
                {
                    leds[i + 8 * j] = (msg[1 + j] & (0x1 << i)) ? 15 : 0;
                }
            }

            if (gridConnection)
            {
                gridConnection->updateQuadrant(x, y, leds);
            }
        }
    }
}

void LibAVR32Module::reloadFirmware(bool preserveMemory)
{
    void *data, *nvram_copy, *vram_copy = 0;
    uint32_t nvram_size, vram_size = 0;

    if (preserveMemory) {
        firmware.readNVRAM(&data, &nvram_size);
        nvram_copy = malloc(nvram_size);
        memcpy(nvram_copy, data, nvram_size);

        firmware.readVRAM(&data, &vram_size);
        vram_copy = malloc(vram_size);
        memcpy(vram_copy, data, vram_size);
    }

    firmware.load(firmwareName);
    firmware.init();

    if (preserveMemory) {
        firmware.writeNVRAM(nvram_copy, nvram_size);
        firmware.writeVRAM(vram_copy, vram_size);
        free(nvram_copy);
        free(vram_copy);
    }
    
    gridConnected(gridConnection);
}

void LibAVR32Module::process(const ProcessArgs& args)
{
    if (firstStep)
    {
        GridConnectionManager::get()->registerGridConsumer(this);
        firstStep = false;
    }

    if (reloadRequested != ReloadRequest::None)
    {
        switch (reloadRequested)
        {
        case ReloadRequest::ReloadAndRestart:
            reloadFirmware(false);
            break;
        case ReloadRequest::HotReload:
            reloadFirmware(true);
            break;
        default:
            break;
        }
        reloadRequested = ReloadRequest::None;
    }

    // Module-specific code to bind Rack inputs to GPIO/ADC
    processInputs(args);

    // Advance hardware timers
    firmware.advanceClock(args.sampleTime);

    // Pump hardware event loop
    firmware.step();

    // Module-specific code to bind GPIO/DAC to Rack outputs & lights
    processOutputs(args);

    // Act on serial output from module to the outside world (grid LEDs, etc.)
    readSerialMessages();
}

json_t* LibAVR32Module::dataToJson()
{
    std::string deviceId = lastConnectedDeviceId;
    if (gridConnection)
    {
        deviceId = gridConnection->getDevice().id;
    }

    json_t* rootJ = json_object();
    json_object_set_new(rootJ, "connectedDeviceId", json_string(deviceId.c_str()));

    void* data = 0;
    uint32_t size = 0;

    firmware.readNVRAM(&data, &size);
    if (data && size > 0)
    {
        json_object_set_new(rootJ, "nvram", json_string(base64_encode((unsigned char*)data, size).c_str()));
    }

    firmware.readVRAM(&data, &size);
    if (data && size > 0)
    {
        json_object_set_new(rootJ, "vram", json_string(base64_encode((unsigned char*)data, size).c_str()));
    }

    return rootJ;
}

void LibAVR32Module::dataFromJson(json_t* rootJ)
{
    json_t* id = json_object_get(rootJ, "connectedDeviceId");
    if (id)
    {
        lastConnectedDeviceId = json_string_value(id);
    }

    void* data = 0;
    uint32_t size = 0;
    json_t* jd;

    jd = json_object_get(rootJ, "nvram");
    if (jd)
    {
        std::string decoded = base64_decode(json_string_value(jd));

        firmware.readNVRAM(&data, &size);
        if (data && size == decoded.length())
        {
            firmware.writeNVRAM((void*)decoded.c_str(), size);
        }
    }

    jd = json_object_get(rootJ, "vram");
    if (jd)
    {
        std::string decoded = base64_decode(json_string_value(jd));

        firmware.readVRAM(&data, &size);
        if (data && size == decoded.length())
        {
            firmware.writeVRAM((void*)decoded.c_str(), size);
            firmware.afterVRAMUpdate();
        }
    }
}

void LibAVR32Module::onReset() {
    rack::engine::Module::onReset();
    reloadFirmware(false);
}
