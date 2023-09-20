#include "FaderbankModule.hpp"

#define FADERBANK_II_MAX_VALUE 16383

struct FBFaderParam : rack::engine::ParamQuantity
{
    std::string getDisplayValueString() override
    {
        return "";
    }
};

FaderbankModule::FaderbankModule()
: startCC(32)
, _iiDevice(this)
{
    config(NUM_FADERS, 0, NUM_FADERS, 0);

    for (unsigned i = 0; i < NUM_FADERS; i++)
    {
        configParam<FBFaderParam>(i, 0.0, 10.0, 0.0);
    }

    _iiDevice.setAddress(0x34);
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
        
        float iiValue = params[i].getValue() / 10.0 * FADERBANK_II_MAX_VALUE;
        _iiDevice.updateFollowerData(i, static_cast<uint16_t>(iiValue));
    }
}

void FaderbankModule::processMIDIMessage(const rack::midi::Message& msg)
{
    DEBUG("MIDI: %lld %s", msg.getFrame(), msg.toString().c_str());

    switch (msg.getStatus())
    {
        case 0xb:
            {
                uint8_t cc = msg.getNote();
                int index = cc - startCC;
                if (index >= 0 && index < NUM_FADERS)
                {
                    params[index].setValue((msg.getValue() * 10.0) / 127.0);
                }
            }
            break;
        default:
            break;
    }
}

json_t* FaderbankModule::dataToJson()
{
    json_t* rootJ = json_object();
    json_object_set_new(rootJ, "midi", midiInput.toJson());
    json_object_set_new(rootJ, "faderSize", json_integer(faderSize));
    return rootJ;
}

void FaderbankModule::dataFromJson(json_t* rootJ)
{
    json_t* midiJ = json_object_get(rootJ, "midi");
    if (midiJ)
        midiInput.fromJson(midiJ);

    json_t* faderSizeJ = json_object_get(rootJ, "faderSize");
    if (faderSizeJ)
        faderSize = static_cast<FaderSize>(json_integer_value(faderSizeJ));
}
