#include "AnsibleWidget.hpp"
#include "AnsibleModule.hpp"
#include "MonomeWidgets.hpp"

using namespace rack;

AnsibleWidget::AnsibleWidget(AnsibleModule* module)
{
    setModule(module);

    box.size = Vec(15 * 6, 380);

    {
        auto panel = new SvgPanel();
        panel->setBackground(APP->window->loadSvg(rack::asset::plugin(pluginInstance, "res/ansible.svg")));
        panel->box.size = box.size;
        addChild(panel);
    }

    addChild(createWidget<USBAJack>(Vec(10, 338)));

    addParam(createParam<TL1105>(Vec(62, 336), module, AnsibleModule::MODE_PARAM));
    addParam(createParam<TL1105>(Vec(17, 256), module, AnsibleModule::KEY1_PARAM));
    addParam(createParam<TL1105>(Vec(54, 256), module, AnsibleModule::KEY2_PARAM));

    addChild(createLight<MediumLight<YellowLight>>(Vec(2, 72), module, AnsibleModule::TR1_LIGHT));
    addChild(createLight<MediumLight<WhiteLight>>(Vec(77, 72), module, AnsibleModule::CV1_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(2, 110), module, AnsibleModule::TR2_LIGHT));
    addChild(createLight<MediumLight<WhiteLight>>(Vec(77, 110), module, AnsibleModule::CV2_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(2, 148), module, AnsibleModule::TR3_LIGHT));
    addChild(createLight<MediumLight<WhiteLight>>(Vec(77, 148), module, AnsibleModule::CV3_LIGHT));
    addChild(createLight<MediumLight<YellowLight>>(Vec(2, 186), module, AnsibleModule::TR4_LIGHT));
    addChild(createLight<MediumLight<WhiteLight>>(Vec(77, 186), module, AnsibleModule::CV4_LIGHT));
    addChild(createLight<MediumLight<YellowWhiteLight>>(Vec(77, 326), module, AnsibleModule::MODE_YELLOW_LIGHT));

    addOutput(createOutput<PJ301MPort>(Vec(13, 54), module, AnsibleModule::TR1_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(50, 75), module, AnsibleModule::CV1_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(13, 92), module, AnsibleModule::TR2_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(50, 111), module, AnsibleModule::CV2_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(13, 130), module, AnsibleModule::TR3_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(50, 149), module, AnsibleModule::CV3_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(13, 168), module, AnsibleModule::TR4_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(50, 187), module, AnsibleModule::CV4_OUTPUT));

    addInput(createInput<PJ301MPort>(Vec(13, 286), module, AnsibleModule::IN1_INPUT));
    addInput(createInput<PJ301MPort>(Vec(50, 286), module, AnsibleModule::IN2_INPUT));
}
