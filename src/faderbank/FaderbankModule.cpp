#include "FaderbankModule.hpp"


FaderbankModule::FaderbankModule()
{
    config(NUM_FADERS, 0, NUM_FADERS, 0);

    for (unsigned i = 0; i < NUM_FADERS; i++)
    {
        configParam(i, -10.0, 10.0, 0.0, rack::string::f("Fader %d", i + 1), " V");
    }

    resetConfig();
}

FaderbankModule::~FaderbankModule()
{
}

void FaderbankModule::process(const ProcessArgs& args)
{
    rack::midi::Message msg;
    while (midiInput.tryPop(&msg, args.frame))
    {
        processMIDIMessage(msg);
    }

    for (unsigned i = 0; i < NUM_FADERS; i++)
    {
        outputs[i].setVoltage(params[i].getValue());
    }
}

void FaderbankModule::processMIDIMessage(const rack::midi::Message& msg)
{
    DEBUG("MIDI: %lld %s", msg.getFrame(), msg.toString().c_str());

    switch (msg.getStatus())
    {
        case 0xb: // Continuous Controller
            {
                // Combine channel and CC number into a lookup key
                uint16_t key = (msg.getChannel() << 8) | msg.getNote();
                auto iter = inputMap.find(key);
                if (iter != inputMap.end())
                {
                    uint8_t index = iter->second;
                    if (index >= 0 && index < NUM_FADERS)
                    {
                        auto param = getParamQuantity(index);
                        if (param)
                        {
                            param->setScaledValue((msg.getValue() * 1.0) / 127.0);
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
                    msg.bytes.size() > (9 + 48 + NUM_FADERS))
                {
                    inputMap.clear();
                    for (int i = 0; i < NUM_FADERS; i++)
                    {
                        uint8_t channel = msg.bytes[9 + 16 + i] - 1;
                        uint8_t ccNum = msg.bytes[9 + 48 + i];
                        inputMap[(channel << 8) | ccNum] = i;
                    }
                }
            }
            break;
        default:
            break;
    }
}

void FaderbankModule::resetConfig()
{
    inputMap.clear();
    for (int i = 0; i < NUM_FADERS; i++)
    {
        // by default, assign CC faders starting with 32, all on channel 1
        inputMap[32 + i] = i;
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

json_t* FaderbankModule::dataToJson()
{
    json_t* rootJ = json_object();

    json_object_set_new(rootJ, "faderRange", json_integer(faderRange));
    json_object_set_new(rootJ, "faderSize", json_integer(faderSize));
    json_object_set_new(rootJ, "midi", midiInput.toJson());

    json_t* configJ = json_object();
    for (auto& entry : inputMap)
    {
        json_object_set_new(configJ, std::to_string(entry.first).c_str(), json_integer(entry.second));
    }
    json_object_set_new(rootJ, "16n_config", configJ);

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

    json_t* midiJ = json_object_get(rootJ, "midi");
    if (midiJ)
        midiInput.fromJson(midiJ);

    json_t* configJ = json_object_get(rootJ, "16n_config");
    if (configJ)
    {
        inputMap.clear();
        json_t* dataJ;
        const char* key;
        json_object_foreach(configJ, key, dataJ)
        {
            int16_t val = std::stoi(key);
            inputMap[val] = json_integer_value(dataJ);
        }
    }
}
