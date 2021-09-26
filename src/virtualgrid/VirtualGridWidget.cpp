#include "VirtualGridWidget.hpp"
#include "VirtualGridModule.hpp"
#include "window.hpp"

#include <iomanip>
#include <random>
#include <sstream>

using namespace rack;

struct MonomeKey : rack::app::ParamWidget
{
    uint8_t* ledAddress;
    int index;
    GridTheme theme;

    typedef enum
    {
        OFF,
        PRESSED,
        HELD
    } KeyPressState;

    MonomeKey()
        : ledAddress(NULL)
    {
    }

    VirtualGridWidget* getGrid()
    {
        return dynamic_cast<VirtualGridWidget*>(parent);
    }

    void setKeyAddress(uint8_t* ledByte)
    {
        ledAddress = ledByte;
    }

    void draw(const DrawArgs& args) override
    {
        auto vg = args.vg;
        uint8_t val = ledAddress != NULL ? *ledAddress : 0;
        NVGcolor color1 = nvgRGB(val * 11 + 90, val * 11 + 63, val * 8 + 48);
        NVGcolor color2 = nvgRGB(val * 12 + 48, val * 12 + 31, val * 4 + 16);

        if (theme == MonoRed)
        {
            color1 = val > 0 ? nvgRGB(240, 140, 30) : nvgRGB(0, 0, 0);
            color2 = val > 0 ? nvgRGB(250, 60, 20) : nvgRGB(0, 0, 0);
        }

        if (paramQuantity && paramQuantity->getValue() == HELD)
        {
            nvgBeginPath(vg);
            nvgRoundedRect(vg, -3, -3, box.size.x + 6, box.size.y + 6, 6);
            nvgFillColor(vg, nvgRGB(180, 180, 0));
            nvgFill(vg);
        }

        nvgBeginPath(vg);
        auto paint = nvgBoxGradient(vg, 0, 0, box.size.x, box.size.y, box.size.x * 0.4, box.size.x * 1.2, color1, color2);
        nvgRoundedRect(vg, 0, 0, box.size.x, box.size.y, 4);
        if (val > 0)
        {
            nvgFillPaint(vg, paint);
        }
        else
        {
            nvgFillColor(vg, nvgRGB(0, 0, 0));
        }
        nvgFill(vg);

        /*
        std::stringstream label;
        //label << index;
        label << ((uint64_t)ledAddress & 0xff);
        nvgTextAlign(vg, NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE);
        nvgFillColor(vg, nvgRGB(0, 0, 0));
        nvgText(vg, box.size.x / 2, box.size.y / 2, label.str().c_str(), NULL);
        nvgFillColor(vg, nvgRGB(255, 255, 255));
        nvgText(vg, box.size.x / 2 - 1, box.size.y / 2 - 1, label.str().c_str(), NULL);
        */
    }

    void beginPress()
    {
        if (paramQuantity)
        {
            float value = paramQuantity->getValue();

            if ((APP->window->getMods() & RACK_MOD_MASK) == RACK_MOD_CTRL && value != HELD)
            {
                // hold key down
                paramQuantity->setValue(HELD);
            }
            else
            {
                paramQuantity->setValue(PRESSED);
            }
        }
    }

    void endPress()
    {
        if (paramQuantity)
        {
            if (paramQuantity->getValue() != HELD)
            {
                paramQuantity->setValue(OFF);
            }
        }
    }

    void onButton(const rack::event::Button& e) override
    {
        if (e.button != GLFW_MOUSE_BUTTON_LEFT)
        {
            return;
        }
        e.consume(this);

        if (e.action == GLFW_PRESS)
        {
            beginPress();
        }
        else
        {
            endPress();
        }
    }

    void onDragStart(const rack::event::DragStart& e) override
    {
        beginPress();
    }

    void onDragEnd(const rack::event::DragEnd& e) override
    {
        if (e.getTarget() == nullptr || e.getTarget()->parent == this->parent) 
        {
            endPress();
        }
    }

    void onDragLeave(const rack::event::DragLeave& e) override
    {
        if (e.origin->parent == this->parent)
        {
            endPress();
        }
    }

    void onDragEnter(const rack::event::DragEnter& e) override
    {
        if (e.origin->parent == this->parent) 
        {
            beginPress();
        }
    }
};

std::string getUniqueVirtualDeviceId(std::string prefix)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 999999);

    bool uniqueIdFound = false;
    while (true)
    {
        std::ostringstream ss;
        ss << prefix << std::setw(6) << std::setfill('0') << dis(gen);
        uniqueIdFound = true;

        // enumerate modules
        for (rack::Widget* w : APP->scene->rack->moduleContainer->children)
        {
            VirtualGridWidget* gridWidget = dynamic_cast<VirtualGridWidget*>(w);
            if (gridWidget)
            {
                auto gridModule = dynamic_cast<VirtualGridModule*>(gridWidget->module);
                if (gridModule->device.id == ss.str())
                {
                    uniqueIdFound = false;
                    break;
                }
            }
        }

        if (uniqueIdFound)
        {
            return ss.str();
        }
    }
}

VirtualGridWidget::VirtualGridWidget(VirtualGridModule* module, unsigned w, unsigned h, unsigned model)
{
    setModule(module);

    if (model > 5)
    {
        model = 5;
    }
    std::string models[6] = { "mv40h", "mv64-", "mv128-", "mv256-", "mv512", "mv" };

    if (module)
    {
        module->device.id = getUniqueVirtualDeviceId(models[model]);
    }

    theme = model == 5 ? VariYellow : MonoRed;

    box.size = Vec(43.125 * w + 45, 380);

    margins.x = 16;
    margins.y = 16;

    // create an opaque child underneath the keys to defeat module dragging in between the buttons
    auto gridZone = new OpaqueWidget();
    gridZone->setSize(Vec(box.size.x - 2 * margins.x, box.size.y - 2 * margins.y));
    gridZone->setPosition(Vec(margins.x, margins.y));
    addChild(gridZone);

    float spacingRatio = 0.14;
    float button_size = (box.size.y - margins.y * 2) / (h + (h - 1) * spacingRatio);
    float spacing = button_size * spacingRatio;

    for (unsigned j = 0; j < h; j++)
    {
        for (unsigned i = 0; i < w; i++)
        {
            float x = margins.x + i * (button_size + spacing);
            float y = margins.y + j * (button_size + spacing);
            int n = i + j * w;

            MonomeKey* key = (MonomeKey*)createParam<MonomeKey>(Vec(x, y), module, n);
            if (module)
            {
                key->setKeyAddress(module->ledBuffer + i + j * 16);
            }
            key->box.size = Vec(button_size, button_size);
            key->index = n;
            key->theme = theme;
            addParam(key);
        }
    }

    PanelBorder* pb = new PanelBorder;
    pb->box.size = box.size;
    addChild(pb);
}

void VirtualGridWidget::draw(const DrawArgs& args)
{
    nvgBeginPath(args.vg);
    nvgRect(args.vg, 0.0, 0.0, box.size.x, box.size.y);
    nvgFillColor(args.vg, nvgRGB(0xe6, 0xe6, 0xe6));
    nvgFill(args.vg);
    Widget::draw(args);
}

void VirtualGridWidget::clearHeldKeys()
{
    for (auto p : params)
    {
        if (p->paramQuantity)
        {
            p->paramQuantity->setValue(MonomeKey::OFF);
        }
    }
}

void VirtualGridWidget::onDragEnter(const event::DragEnter& e)
{
}

void VirtualGridWidget::onDragStart(const event::DragStart& e)
{
    ModuleWidget::onDragStart(e);

    if (e.getTarget() == this && e.button == GLFW_MOUSE_BUTTON_LEFT)
    {
        if ((APP->window->getMods() & RACK_MOD_MASK) == RACK_MOD_CTRL)
        {
            clearHeldKeys();
            e.consume(this);
            return;
        }
    }
}

struct GridReleaseHeldKeysItem : MenuItem
{
    VirtualGridWidget* grid;
    void onAction(const event::Action& e) override
    {
        grid->clearHeldKeys();
    }
};

void VirtualGridWidget::appendContextMenu(Menu* menu)
{
    VirtualGridModule* grid = dynamic_cast<VirtualGridModule*>(module);
    assert(grid);

    menu->addChild(construct<MenuLabel>());
    menu->addChild(construct<GridReleaseHeldKeysItem>(&MenuItem::text, "Release Held Keys", &MenuItem::rightText, "Ctrl+Click", &GridReleaseHeldKeysItem::grid, this));
    menu->addChild(construct<MenuLabel>(&MenuLabel::text, model->name + " (" + grid->device.id + ")"));
}