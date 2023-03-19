#pragma once

#include "LibAVR32ModuleWidget.hpp"
#include "SifamTPM.hpp"
#include "USBAJack.hpp"

using namespace rack;

struct MeadowphysicsWidget : LibAVR32ModuleWidget
{
    MeadowphysicsWidget(MeadowphysicsModule* module)
    {
        setModule(module);

        box.size = Vec(15 * 6, 380);

        {
            auto panel = new SvgPanel();
            panel->setBackground(APP->window->loadSvg(rack::asset::plugin(pluginInstance, "res/meadowphysics.svg")));
            panel->box.size = box.size;
            addChild(panel);
        }

        // Screws positioned for sliding nuts :)
        addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH / 2, 0)));
        addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH / 2, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

        addParam(createParam<USBAJack>(Vec(7, 333), module, MeadowphysicsModule::USB_PARAM));
        addParam(createParam<TL1105>(Vec(62, 336), module, MeadowphysicsModule::BUTTON_PARAM));
        addParam(createParam<SifamTPN111GrayBlackStripe>(Vec(12, 232), module, MeadowphysicsModule::CLOCK_PARAM));

        addOutput(createOutput<PJ301MPort>(Vec(15, 54), module, MeadowphysicsModule::TR1_OUTPUT));
        addOutput(createOutput<PJ301MPort>(Vec(50, 75), module, MeadowphysicsModule::TR2_OUTPUT));
        addOutput(createOutput<PJ301MPort>(Vec(15, 92), module, MeadowphysicsModule::TR3_OUTPUT));
        addOutput(createOutput<PJ301MPort>(Vec(50, 113), module, MeadowphysicsModule::TR4_OUTPUT));
        addOutput(createOutput<PJ301MPort>(Vec(15, 130), module, MeadowphysicsModule::TR5_OUTPUT));
        addOutput(createOutput<PJ301MPort>(Vec(50, 151), module, MeadowphysicsModule::TR6_OUTPUT));
        addOutput(createOutput<PJ301MPort>(Vec(15, 168), module, MeadowphysicsModule::TR7_OUTPUT));
        addOutput(createOutput<PJ301MPort>(Vec(50, 189), module, MeadowphysicsModule::TR8_OUTPUT));
        addInput(createInput<PJ301MPort>(Vec(15, 286), module, MeadowphysicsModule::CLOCK_INPUT));
        addOutput(createOutput<PJ301MPort>(Vec(50, 286), module, MeadowphysicsModule::CLOCK_OUTPUT));

        addChild(createLight<MediumLight<YellowLight>>(Vec(3, 71), module, MeadowphysicsModule::TR1_LIGHT));
        addChild(createLight<MediumLight<YellowLight>>(Vec(77, 71), module, MeadowphysicsModule::TR2_LIGHT));
        addChild(createLight<MediumLight<YellowLight>>(Vec(3, 109), module, MeadowphysicsModule::TR3_LIGHT));
        addChild(createLight<MediumLight<YellowLight>>(Vec(77, 109), module, MeadowphysicsModule::TR4_LIGHT));
        addChild(createLight<MediumLight<YellowLight>>(Vec(3, 147), module, MeadowphysicsModule::TR5_LIGHT));
        addChild(createLight<MediumLight<YellowLight>>(Vec(77, 147), module, MeadowphysicsModule::TR6_LIGHT));
        addChild(createLight<MediumLight<YellowLight>>(Vec(3, 185), module, MeadowphysicsModule::TR7_LIGHT));
        addChild(createLight<MediumLight<YellowLight>>(Vec(77, 185), module, MeadowphysicsModule::TR8_LIGHT));
        addChild(createLight<MediumLight<YellowLight>>(Vec(77, 282), module, MeadowphysicsModule::CLOCK_LIGHT));
    }
};
