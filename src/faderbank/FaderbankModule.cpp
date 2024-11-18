#include "FaderbankModule.hpp"


FaderbankModule::FaderbankModule()
{
    config(NUM_FADERS, 0, NUM_FADERS, 0);

    for (unsigned i = 0; i < NUM_FADERS; i++)
    {
        configParam(i, 0.0, 10.0, 0.0, rack::string::f("Fader %d", i + 1), " V");
    }

    resetConfig();
}

FaderbankModule::~FaderbankModule()
{
}

void FaderbankModule::process(const ProcessArgs& args)
{
    processMIDIMessages(args);

    for (unsigned i = 0; i < NUM_FADERS; i++)
    {
        outputs[i].setVoltage(params[i].getValue());
    }

    if (polyphonicMode)
    {
        outputs[NUM_FADERS - 1].setChannels(16);
        for (unsigned i = 0; i < NUM_FADERS; i++)
        {
            outputs[NUM_FADERS - 1].setVoltage(params[i].getValue(), i);
        }
    }
    else
    {
        outputs[NUM_FADERS - 1].setChannels(1);
    }
}

void FaderbankModule::processMIDIMessages(const ProcessArgs& args)
{
    int min14bitInterval = 16;

    rack::midi::Message msg;
    while (midiInput.tryPop(&msg, args.frame))
    {
        DEBUG("MIDI: %lld %s", msg.getFrame(), msg.toString().c_str());

        switch (msg.getStatus())
        {
            case 0xb: // Continuous Controller
                {
                    // Combine channel and CC number into a lookup key
                    uint8_t ccNum = msg.getNote();
                    uint16_t key = (msg.getChannel() << 8) | ccNum;

                    auto iter = inputMap.find(key);
                    if (iter != inputMap.end())
                    {
                        auto faderDestinations = iter->second;
                        for (auto index : faderDestinations) {
                            if (index < NUM_FADERS)
                            {
                                records[index].highValue = msg.getValue();
                                records[index].lastHighValue = msg.getValue();
                                records[index].lastHighValueFrame = args.frame;
                            }
                        }
                    }
                    else if (ccNum >= 32 && ccNum < 64)
                    {
                        // look for potential LSB CC of 14-bit CC 0-31
                        key = (msg.getChannel() << 8) | (ccNum - 32);
                        iter = inputMap.find(key);
                        if (iter != inputMap.end())
                        {
                            auto faderDestinations = iter->second;
                            for (auto index : faderDestinations)
                            {
                                if (index < NUM_FADERS && records[index].faderMode == FaderMode14bitCC)
                                {
                                    records[index].lowValue = msg.getValue();
                                    records[index].lastLowValueFrame = args.frame;
                                }
                            }
                        }
                    }
                }
                break;
            case 0xF: // System Exclusive
                {
                    if (msg.bytes[1] == 0x7d && // 16n manufacturer ID
                        msg.bytes[2] == 0x00 &&
                        msg.bytes[3] == 0x00 &&
                        msg.bytes[4] == 0x0F && // sysex config response ID
                        msg.bytes.size() >= (9 + 80))
                    {
                        for (int i = 0; i < NUM_FADERS; i++)
                        {
                            uint8_t channel = ((msg.bytes[9 + 16 + i]) & 0xF) - 1;
                            uint8_t ccNum = msg.bytes[9 + 48 + i] & 0x7F;
                            records[i].ccNum = ccNum;
                            records[i].channel = channel;
                            if (msg.bytes.size() >= 9 + 82)
                            {
                                uint16_t ccMode = msg.bytes[9 + 80] << 8 | msg.bytes[9 + 81];
                                records[i].faderMode = (ccMode & (1 << i)) == 0 ? FaderMode14bitCC : FaderModeCC;
                            }
                        }
                        updateInputMap();
                    }
                }
                break;
            default:
                break;
        }
    }

    for (int i = 0; i < NUM_FADERS; i++)
    {
        uint16_t value;
        bool updateable = false;
        bool expect14bit = records[i].faderMode == FaderMode14bitCC && records[i].ccNum < 32;

        if (records[i].highValue != 0xFF)
        {
            if (expect14bit)
            {
                if (records[i].lowValue != 0xFF)
                {
                    value = ((records[i].highValue & 0x7F) << 7) + (records[i].lowValue & 0x7F);
                    updateable = true;
                }
                else if ((args.frame - records[i].lastHighValueFrame) > min14bitInterval)
                {
                    // give up waiting for a low value
                    value = (records[i].highValue & 0x7F) << 7;
                    updateable = true;
                }
            }
            else
            {
                value = (records[i].highValue & 0x7F) << 7;
                updateable = true;
            }
        }
        else if (expect14bit && records[i].lowValue != 0xFF && (args.frame - records[i].lastLowValueFrame) > min14bitInterval)
        {
            // give up waiting for a high value
            value = ((records[i].lastHighValue & 0x7F) << 7) + (records[i].lowValue & 0x7F);
            updateable = true;
        }

        if (updateable)
        {
            auto param = getParamQuantity(i);
            if (param)
            {
                param->setScaledValue((value * 1.0f) / (0x3FFF * 1.0f));
            }

            records[i].highValue = 0xFF;
            records[i].lowValue = 0xFF;
        }
    }
}

void FaderbankModule::resetConfig()
{
    for (int i = 0; i < NUM_FADERS; i++)
    {
        // by default, assign CC faders starting with 32, all on channel 1
        records[i].ccNum = 32 + i;
        records[i].channel = 0;
        records[i].faderMode = FaderModeCC;
    }

    updateInputMap();
}

void FaderbankModule::updateInputMap()
{
    inputMap.clear();

    for (int i = 0; i < NUM_FADERS; i++)
    {
        uint16_t key = (records[i].channel << 8) | records[i].ccNum;
        if (inputMap.find(key) == inputMap.end())
        {
            inputMap.insert(make_pair(key, std::vector<uint8_t>()));
        }

        inputMap[key].push_back(i);
    }
}

void FaderbankModule::updateFaderRanges()
{
    for (int i = 0; i < NUM_FADERS; i++)
    {
        auto param = getParamQuantity(i);
        if (param != nullptr)
        {
            float orig = param->getValue();
            switch (faderRange)
            {
                case FaderRange10V:
                    {
                        param->minValue = 0.0;
                        param->maxValue = 10.0;
                    }
                    break;
                case FaderRange5V:
                    {
                        param->minValue = 0.0;
                        param->maxValue = 5.0;
                    }
                    break;
                case FaderRangeBipolar:
                    {
                        param->minValue = -5.0;
                        param->maxValue = 5.0;
                    }
                    break;
                default:
                    break;
            }
            param->setValue(orig);
        }
    }
}

void FaderbankModule::autodetectConfig()
{
    resetConfig();

    midiInput.setDriverId(rack::midi::getDriverIds()[0]);
    if (midiInput.deviceId == -1)
    {
        for (int deviceId : midiInput.getDeviceIds())
        {
            if (midiInput.getDeviceName(deviceId).substr(0, 3).find("16n") != std::string::npos)
            {
                midiInput.setDeviceId(deviceId);
                break;
            }
        }
    }

    midiOutput.setDriverId(rack::midi::getDriverIds()[0]);
    if (midiOutput.deviceId == -1)
    {
        for (int deviceId : midiOutput.getDeviceIds())
        {
            if (midiOutput.getDeviceName(deviceId).find("16n") != std::string::npos)
            {
                midiOutput.setDeviceId(deviceId);
                break;
            }
        }
    }

    // Send a sysex message to request device channel/CC config.
    if (midiOutput.deviceId != -1)
    {
        rack::midi::Message msg;
        msg.setSize(6);
        msg.bytes = { 0xF0, 0x7d, 0x00, 0x00, 0x1F, 0xF7 };

        midiOutput.sendMessage(msg);
    }
}

json_t* FaderbankModule::dataToJson()
{
    json_t* rootJ = json_object();

    json_object_set_new(rootJ, "faderRange", json_integer(faderRange));
    json_object_set_new(rootJ, "faderSize", json_integer(faderSize));
    json_object_set_new(rootJ, "polyphonicMode", json_boolean(polyphonicMode));

    json_object_set_new(rootJ, "midi", midiInput.toJson());
    json_object_set_new(rootJ, "midiOutput", midiOutput.toJson());

    json_t* configJ = json_array();
    for (auto& entry : records)
    {
        json_t* faderRecord = json_object();
        json_object_set_new(faderRecord, "channel", json_integer(entry.channel));
        json_object_set_new(faderRecord, "faderMode", json_integer(entry.faderMode));
        json_object_set_new(faderRecord, "ccNum", json_integer(entry.ccNum));

        json_array_append(configJ, faderRecord);
    }
    json_object_set_new(rootJ, "fader_config", configJ);

    return rootJ;
}

void FaderbankModule::dataFromJson(json_t* rootJ)
{
    json_t* faderRangeJ = json_object_get(rootJ, "faderRange");
    if (faderRangeJ)
        faderRange = static_cast<FaderRange>(json_integer_value(faderRangeJ));

    updateFaderRanges();

    json_t* faderSizeJ = json_object_get(rootJ, "faderSize");
    if (faderSizeJ)
        faderSize = static_cast<FaderSize>(json_integer_value(faderSizeJ));

    json_t* polyphonicModeJ = json_object_get(rootJ, "polyphonicMode");
    if (polyphonicModeJ)
        polyphonicMode = json_boolean_value(polyphonicModeJ);

    json_t* midiJ = json_object_get(rootJ, "midi");
    if (midiJ)
        midiInput.fromJson(midiJ);

    json_t* midiOutputJ = json_object_get(rootJ, "midiOutput");
    if (midiOutputJ)
        midiOutput.fromJson(midiOutputJ);

    // backwards compatibility for patches with older config structure
    json_t* oldConfigJ = json_object_get(rootJ, "16n_config");
    if (oldConfigJ)
    {
        json_t* dataJ;
        const char* key;
        json_object_foreach(oldConfigJ, key, dataJ)
        {
            int16_t val = std::stoi(key);
            int8_t fader = json_integer_value(dataJ);
            records[fader].ccNum = val & 0x7F;
            records[fader].channel = val >> 8;
        }
    }

    // current format for config
    json_t* configJ = json_object_get(rootJ, "fader_config");
    if (configJ)
    {
        json_t* dataJ;
        size_t key;
        json_array_foreach(configJ, key, dataJ)
        {
            if (key < NUM_FADERS)
            {
                json_t* channelJ = json_object_get(dataJ, "channel");
                if (channelJ)
                {
                    records[key].channel = json_integer_value(channelJ) & 0xF;
                }
                json_t* modeJ = json_object_get(dataJ, "faderMode");
                if (modeJ)
                {
                    records[key].faderMode = static_cast<FaderMode>(json_integer_value(modeJ));
                }
                json_t* ccJ = json_object_get(dataJ, "ccNum");
                if (ccJ)
                {
                    records[key].ccNum = json_integer_value(ccJ) & 0x7F;
                }
            }
        }
    }

    updateInputMap();
}

void FaderbankModule::fromJson(json_t* rootJ)
{
    // deserialize data before params, so voltage range option is set correctly
    json_t* dataJ = json_object_get(rootJ, "data");
    if (dataJ)
        dataFromJson(dataJ);

    Module::fromJson(rootJ);
}

FaderbankModule::ControllerRecord::ControllerRecord()
{
    highValue = 0xFF;
    lowValue = 0xFF;
    lastHighValue = 0;
    channel = 0;
    ccNum = 0;
    faderMode = FaderModeCC;
}