#include "FaderbankWidget.hpp"
#include "FaderbankModule.hpp"

extern rack::Plugin* pluginInstance;

using namespace rack;

struct ThemedSvgSlider : app::SvgSlider
{
    std::vector<std::shared_ptr<window::Svg>> lightThemedBackgrounds;
    std::vector<std::shared_ptr<window::Svg>> darkThemedBackgrounds;

    unsigned int *theme = 0;

    void updateGraphics()
    {
        int t = theme == nullptr ? 0 : *theme;
        SvgSlider::setBackgroundSvg(
            settings::preferDarkPanels ?
                darkThemedBackgrounds[t % darkThemedBackgrounds.size()] :
                lightThemedBackgrounds[t % lightThemedBackgrounds.size()]
        );
    }

    void step() override
    {
        updateGraphics();
        SvgSlider::step();
    }
};

struct FaderbankSlider : ThemedSvgSlider
{
    FaderbankSlider()
    {
        lightThemedBackgrounds.push_back(Svg::load(asset::plugin(pluginInstance, "res/FaderBackground90mm.svg")));
        lightThemedBackgrounds.push_back(Svg::load(asset::plugin(pluginInstance, "res/FaderBackground60mm.svg")));
        darkThemedBackgrounds.push_back(Svg::load(asset::plugin(pluginInstance, "res/FaderBackground90mm-dark.svg")));
        darkThemedBackgrounds.push_back(Svg::load(asset::plugin(pluginInstance, "res/FaderBackground60mm-dark.svg")));

        setHandleSvg(Svg::load(asset::plugin(pluginInstance, "res/FaderHandle.svg")));
        updateGraphics();

        maxHandlePos = rack::window::mm2px(math::Vec(0.738, 1.8));
        minHandlePos = rack::window::mm2px(math::Vec(0.738, 87.3));

        box.grow(math::Vec(3, 1));
    }

    void step() override
    {
        minHandlePos = rack::window::mm2px(math::Vec(0.738, (theme == nullptr || *theme == 0) ? 87.3 : 59.8));
        ThemedSvgSlider::step();
    }
};

struct WideYellowLight : YellowLight
{
    // custom draw function to make glow look better on a
    // rectangular light that is much wider than it is tall
    void drawHalo(const DrawArgs& args) override
    {
        if (args.fb)
            return;

        const float halo = settings::haloBrightness;
        if (halo == 0.f)
            return;

        if (color.r == 0.f && color.g == 0.f && color.b == 0.f)
            return;

        math::Vec c = box.size.div(2);

        float xoradius = c.x + std::min(c.x * 1.55f, 15.f);
        float yoradius = c.y + std::min(c.y * 1.85f, 15.f);

        nvgBeginPath(args.vg);
        nvgRect(args.vg, c.x - xoradius, c.y - yoradius, 2 * xoradius, 3 * yoradius);

        NVGcolor icol = color::mult(color, halo);
        NVGcolor ocol = nvgRGBA(0, 0, 0, 0);
        nvgSave(args.vg);
        nvgScale(args.vg, 1.0f, 1.85f * c.y / c.x);
        NVGpaint paint = nvgRadialGradient(args.vg, c.x, c.y, c.x * 0.46, xoradius * 0.8, icol, ocol);
        nvgFillPaint(args.vg, paint);
        nvgFill(args.vg);
        nvgRestore(args.vg);
    }
};

template <typename TBase>
struct FaderbankSliderLight : RectangleLight<TSvgLight<TBase>>
{
    FaderbankSliderLight()
    {
        this->setSvg(Svg::load(asset::plugin(pluginInstance, "res/FaderSliderLight.svg")));
    }
};

struct FaderbankSliderYellow : LightSlider<FaderbankSlider, FaderbankSliderLight<WideYellowLight>>
{
    FaderbankSliderYellow()
    {
        getLight()->box.size.x = getLight()->box.size.x * 6;
        getLight()->box.size.y = getLight()->box.size.y * 0.4;
    }
};

FaderbankWidget::FaderbankWidget(FaderbankModule* module)
{
    setModule(module);

    box.size = Vec(735, 380);

    {
        auto panel = new ThemedSvgPanel();
        panel->setBackground(
            APP->window->loadSvg(rack::asset::plugin(pluginInstance, "res/grid.svg")),
            APP->window->loadSvg(rack::asset::plugin(pluginInstance, "res/grid-dark.svg")));
        panel->box.size = box.size;
        addChild(panel);
    }

    // dummy opaque widget to prevent accidentally dragging the module when clicking between faders
    // TODO: increase hitboxes of faders instead
    auto dummy = new OpaqueWidget();
    dummy->box.size = Vec(735 - 29, 300);
    dummy->setPosition(Vec(14.5, 60));
    addChild(dummy);

    for (int i = 0; i < NUM_FADERS; i++)
    {
        addOutput(createOutput<ThemedPJ301MPort>(Vec(17 + 45 * i, 20), module, i));
        auto slider = createParam<FaderbankSliderYellow>(Vec(14.5 + 45 * i, 60), module, i);
        if (module != nullptr)
        {
            slider->theme = (unsigned int*)&module->faderSize;
        }
        else
        {
            // set the handles on a diagonal in the library
            slider->handle->box.pos = slider->minHandlePos.crossfade(slider->maxHandlePos, i/(NUM_FADERS * 1.0));
        }
        addParam(slider);
    }
}

void appendFaderConfigMenu(FaderbankModule* fb, ::Menu* menu, int faderIndex)
{
    if (fb == nullptr || menu == nullptr || faderIndex < 0 || faderIndex > NUM_FADERS)
    {
        return;
    }

    FaderbankModule::ControllerRecord record = fb->records[faderIndex];

    std::vector<std::string> modeNames { "CC", "CC (14-bit)" };
    uint8_t ccMax = record.faderMode == FaderbankModule::FaderMode14bitCC ? 31 : 127;

    std::vector<std::string> channelNames;
    for (auto i = 0; i < 16; i++)
    {
        std::ostringstream ss;
        ss << (i + 1);
        channelNames.push_back(ss.str());
    }

    std::vector<std::string> ccNames;
    for (auto i = 0; i < ccMax + 1; i++)
    {
        std::ostringstream ss;
        ss << i;
        ccNames.push_back(ss.str());
    }

    std::ostringstream faderName;
    faderName << faderIndex + 1;

    std::ostringstream faderDesc;
    faderDesc << "Ch " << (int)(record.channel + 1) << " " << modeNames[record.faderMode] << " ";
    if (record.faderMode == FaderbankModule::FaderModeCC)
    {
        faderDesc << (int)record.ccNum;
    }
    else if (record.faderMode == FaderbankModule::FaderMode14bitCC)
    {
        faderDesc << (int)record.ccNum << "/" << (int)(record.ccNum + 32);
    }

    menu->addChild(createSubmenuItem(faderName.str(), faderDesc.str(),
        [=](Menu* childMenu)
        {
            childMenu->addChild(createIndexSubmenuItem("Channel", channelNames,
                [=]()
                {
                    return fb->records[faderIndex].channel;
                },
                [=](int index)
                {
                    fb->records[faderIndex].channel = index & 0xF;
                    fb->updateInputMap();
                }
            ));

            childMenu->addChild(createIndexSubmenuItem("Mode", modeNames,
                [=]()
                {
                    return fb->records[faderIndex].faderMode;
                },
                [=](int index)
                {
                    fb->records[faderIndex].faderMode = static_cast<FaderbankModule::FaderMode>(index);
                    fb->updateInputMap();
                }
            ));

            childMenu->addChild(createIndexSubmenuItem("CC Number", ccNames,
                [=]()
                {
                    return fb->records[faderIndex].ccNum;
                },
                [=](int index)
                {
                    fb->records[faderIndex].ccNum = index & 0x7F;
                    fb->updateInputMap();
                }
            ));
        }
    ));
}

void FaderbankWidget::appendContextMenu(Menu* menu)
{
    auto fb = dynamic_cast<FaderbankModule*>(module);
    if (!fb)
    {
        return;
    }

    menu->addChild(new MenuSeparator());

    menu->addChild(createIndexSubmenuItem("Fader voltage range", { "0-10V", "0-5V", "+/-5V" },
        [=]() {
            return fb->faderRange;
        },
        [=](int index) {
            fb->faderRange = static_cast<FaderbankModule::FaderRange>(index);
            fb->updateFaderRanges();
            // update all the slider handle positions
            for (widget::Widget* child : children)
            {
                child->step();
                ChangeEvent eChange;
                child->onChange(eChange);
            }
        }));

    menu->addChild(createIndexSubmenuItem("Fader size", { "90mm", "60mm" },
        [=]() {
            return fb->faderSize;
        },
        [=](int index) {
            fb->faderSize = static_cast<FaderbankModule::FaderSize>(index);
            // update all the slider handle positions
            for (widget::Widget* child : children)
            {
                child->step();
                ChangeEvent eChange;
                child->onChange(eChange);
            }
        }
    ));

    menu->addChild(createCheckMenuItem(
        "Polyphonic mode", "",
        [=]() {
            return fb->polyphonicMode;
        },
        [=]() {
            fb->polyphonicMode = !fb->polyphonicMode;
        }));

    menu->addChild(new MenuSeparator());

    menu->addChild(createMenuItem("Autodetect 16n hardware", "",
        [=]()
        {
            fb->autodetectConfig();
        }));

    menu->addChild(createSubmenuItem("MIDI Configuration", "",
        [=](Menu* configMenu)
        {
            configMenu->addChild(createSubmenuItem("Input device", fb->midiInput.getDeviceName(fb->midiInput.getDeviceId()),
                [=](Menu* childMenu)
                {
                    appendMidiMenu(childMenu, &fb->midiInput);
                    // remove channel selection
                    auto last = childMenu->children.back();
                    childMenu->removeChild(last);
                    delete last;
                    // and separator
                    last = childMenu->children.back();
                    childMenu->removeChild(last);
                    delete last;
                }));

            configMenu->addChild(createSubmenuItem("Output device", fb->midiOutput.getDeviceName(fb->midiOutput.getDeviceId()),
                [=](Menu* childMenu)
                {
                    appendMidiMenu(childMenu, &fb->midiOutput);
                    // remove channel selection
                    auto last = childMenu->children.back();
                    childMenu->removeChild(last);
                    delete last;
                    // and separator
                    last = childMenu->children.back();
                    childMenu->removeChild(last);
                    delete last;
                }));

            configMenu->addChild(createSubmenuItem("Fader settings", "",
                [=](Menu* childMenu)
                {
                    for (int i = 0; i < NUM_FADERS; i++)
                    {
                        appendFaderConfigMenu(fb, childMenu, i);
                    }
                }));

            configMenu->addChild(new MenuSeparator());

            configMenu->addChild(createMenuItem("Write configuration to 16n hardware", "",
                [=]()
                {
                    fb->writeConfigSysex();
                }
            ));
        }
    ));
}

