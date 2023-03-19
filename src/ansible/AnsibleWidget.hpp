#pragma once

#include "AnsibleModule.hpp"
#include "HoldableButton.hpp"
#include "LibAVR32ModuleWidget.hpp"
#include "USBAJack.hpp"
#include "YellowWhiteLight.hpp"

using namespace rack;

struct AnsibleWidget : LibAVR32ModuleWidget
{
    AnsibleWidget(AnsibleModule* module)
    {
        setModule(module);

        box.size = Vec(15 * 6, 380);

        {
            auto panel = new SvgPanel();
            panel->setBackground(APP->window->loadSvg(rack::asset::plugin(pluginInstance, "res/ansible.svg")));
            panel->box.size = box.size;
            addChild(panel);
        }

        addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH / 2, 0)));
        addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH / 2, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

        addParam(createParam<USBAJack>(Vec(7, 333), module, AnsibleModule::USB_PARAM));
        addParam(createParam<TL1105>(Vec(62, 336), module, AnsibleModule::MODE_PARAM));
        addParam(createParam<HoldableButton>(Vec(19, 256), module, AnsibleModule::KEY1_PARAM));
        addParam(createParam<HoldableButton>(Vec(54, 256), module, AnsibleModule::KEY2_PARAM));

        addOutput(createOutput<PJ301MPort>(Vec(15, 54), module, AnsibleModule::TR1_OUTPUT));
        addOutput(createOutput<PJ301MPort>(Vec(50, 75), module, AnsibleModule::CV1_OUTPUT));
        addOutput(createOutput<PJ301MPort>(Vec(15, 92), module, AnsibleModule::TR2_OUTPUT));
        addOutput(createOutput<PJ301MPort>(Vec(50, 111), module, AnsibleModule::CV2_OUTPUT));
        addOutput(createOutput<PJ301MPort>(Vec(15, 130), module, AnsibleModule::TR3_OUTPUT));
        addOutput(createOutput<PJ301MPort>(Vec(50, 149), module, AnsibleModule::CV3_OUTPUT));
        addOutput(createOutput<PJ301MPort>(Vec(15, 168), module, AnsibleModule::TR4_OUTPUT));
        addOutput(createOutput<PJ301MPort>(Vec(50, 187), module, AnsibleModule::CV4_OUTPUT));

        addInput(createInput<PJ301MPort>(Vec(15, 286), module, AnsibleModule::IN1_INPUT));
        addInput(createInput<PJ301MPort>(Vec(50, 286), module, AnsibleModule::IN2_INPUT));

        addChild(createLight<MediumLight<YellowLight>>(Vec(3, 72), module, AnsibleModule::TR1_LIGHT));
        addChild(createLight<MediumLight<WhiteLight>>(Vec(77, 72), module, AnsibleModule::CV1_LIGHT));
        addChild(createLight<MediumLight<YellowLight>>(Vec(3, 110), module, AnsibleModule::TR2_LIGHT));
        addChild(createLight<MediumLight<WhiteLight>>(Vec(77, 110), module, AnsibleModule::CV2_LIGHT));
        addChild(createLight<MediumLight<YellowLight>>(Vec(3, 148), module, AnsibleModule::TR3_LIGHT));
        addChild(createLight<MediumLight<WhiteLight>>(Vec(77, 148), module, AnsibleModule::CV3_LIGHT));
        addChild(createLight<MediumLight<YellowLight>>(Vec(3, 186), module, AnsibleModule::TR4_LIGHT));
        addChild(createLight<MediumLight<WhiteLight>>(Vec(77, 186), module, AnsibleModule::CV4_LIGHT));
        addChild(createLight<MediumLight<YellowWhiteLight>>(Vec(77, 326), module, AnsibleModule::MODE_YELLOW_LIGHT));
    }
};
