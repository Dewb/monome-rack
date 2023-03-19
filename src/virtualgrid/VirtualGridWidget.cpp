#include "VirtualGridWidget.hpp"
#include "Screenshot.hpp"
#include "VirtualGridKey.hpp"
#include "VirtualGridModule.hpp"
#include "VirtualGridTheme.hpp"

using namespace rack;

uint8_t samplePattern[] = {
     0,  0,  0, 15,  0,  0,  0,  0,  0,  0,  0, 15,  0,  0,  0,  0,
     0, 15,  0, 14,  0,  0,  0,  0,  0, 15,  0, 14,  0,  0,  0,  0,
     0, 14,  0, 12,  0,  0, 15,  0,  0, 14,  0, 12,  0, 15,  0,  0,
     0, 12,  0,  9, 15,  0, 14,  0,  0, 12,  0,  9,  0, 14,  0,  0,
    15,  9,  0,  5, 14,  0, 12,  0,  0,  9,  0,  5,  0, 12,  0, 15,
    14,  5,  0,  1, 12,  0,  9,  0,  0,  5,  0,  1,  0,  9,  0, 14,
    12,  1,  0,  0,  9,  0,  5,  0, 15,  1,  0,  0,  0,  5,  0, 12,
     9,  0,  0,  0,  5,  0,  1,  0, 14,  0,  0,  0,  0,  1,  0,  9,
     5,  0,  0,  0,  1, 15,  0,  0, 12,  0,  0,  0,  0,  0, 15,  5,
     1,  0, 15,  0,  0, 14,  0,  0,  9,  0,  0,  0,  0,  0, 14,  1,
     0,  0, 14,  0,  0, 12,  0,  0,  5,  0, 15,  0,  0,  0, 12,  0,
     0,  0, 12,  0,  0,  9,  0,  0,  1,  0, 14,  0, 15,  0,  9,  0,
     0,  0,  9,  0,  0,  5,  0, 15,  0,  0, 12,  0, 14,  0,  5,  0,
     0,  0,  5,  0,  0,  1,  0, 14,  0,  0,  9,  0, 12,  0,  1,  0,
     0,  0,  1,  0,  0,  0,  0, 12,  0,  0,  5,  0,  9,  0,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  9,  0,  0,  1,  0,  5,  0,  0,  0,
};

GridTheme sampleThemeYellow = GridTheme::Yellow;
GridTheme sampleThemeOrange = GridTheme::Orange;
GridTheme sampleThemeRed = GridTheme::Red;

VirtualGridWidget::VirtualGridWidget(VirtualGridModule* module, unsigned w, unsigned h)
{
    setModule(module);
    if (module)
    {
        VirtualGridModule* grid = dynamic_cast<VirtualGridModule*>(module);
        assert(grid);
        GridConnectionManager::get().registerGrid(grid);
        id = grid->device.id;
    }

    float rackWidth = 0;
    GridTheme* sampleTheme = &sampleThemeYellow;

    if (w == h)
    {
        rackWidth = 375;
        margins.x = 13.5;
        margins.y = 16;
        sampleTheme = h == 8 ? &sampleThemeOrange : &sampleThemeRed;
    }
    else if (w == 2 * h)
    {
        rackWidth = 735;
        margins.x = 16;
        margins.y = 16;
        sampleTheme = &sampleThemeYellow;
    }
    else
    {
        FATAL("Unsupported grid size");
        assert(0);
    }

    box.size = Vec(rackWidth, 380);

    // create an opaque child underneath the keys to defeat module dragging in between the buttons
    auto gridZone = new OpaqueWidget();
    gridZone->setSize(Vec(box.size.x - 2 * margins.x, box.size.y - 2 * margins.y));
    gridZone->setPosition(Vec(margins.x, margins.y));
    addChild(gridZone);

    float spacingRatio = 0.14;
    float button_size = (box.size.y - margins.y * 2) / (h + (h - 1) * spacingRatio);
    float spacing = button_size * spacingRatio;
    float keyMargin = 0.5 * spacing;

    for (unsigned j = 0; j < h; j++)
    {
        for (unsigned i = 0; i < w; i++)
        {
            float x = margins.x + i * (button_size + spacing) - keyMargin;
            float y = margins.y + j * (button_size + spacing) - keyMargin;
            int n = i + j * w;

            VirtualGridKey* key = (VirtualGridKey*)createParam<VirtualGridKey>(Vec(x, y), module, n * 2);
            if (module)
            {
                key->setKeyAddress(module->ledBuffer + i + j * 16);
                key->theme = &(module->theme);
            } else {
                key->setKeyAddress(samplePattern + i + j * 16);
                key->theme = sampleTheme;
            }
            key->box.size = Vec(button_size + spacing, button_size + spacing);
            key->margin = keyMargin;
            key->pushAmount = h == 16 ? 2.1 : 3.8;
            key->cornerRadius = h == 16 ? 2.5 : 4.3;
            addParam(key);
        }
    }

    PanelBorder* pb = new PanelBorder;
    pb->box.size = box.size;
    addChild(pb);
}

VirtualGridWidget::~VirtualGridWidget()
{
    if (module)
    {
        GridConnectionManager::get().deregisterGrid(id);
    }
}

void VirtualGridWidget::draw(const DrawArgs& args)
{
    nvgBeginPath(args.vg);
    nvgRect(args.vg, 0.0, 0.0, box.size.x, box.size.y);
    nvgFillColor(args.vg, nvgRGB(0xf0, 0xf0, 0xf0));
    nvgFill(args.vg);

    rack::app::ModuleWidget::draw(args);
}

void VirtualGridWidget::clearHeldKeys()
{
    for (auto p : getParams())
    {
        auto key = static_cast<VirtualGridKey*>(p);
        if (key && !key->isLocked())
        {
            key->getSecondaryParamQuantity()->setImmediateValue(VirtualGridKey::OFF);
        }
    }
}

void VirtualGridWidget::clearLockedKeys()
{
    for (auto p : getParams())
    {
        auto key = static_cast<VirtualGridKey*>(p);
        if (key && key->isLocked())
        {
            key->setLocked(false);
            key->getSecondaryParamQuantity()->setImmediateValue(VirtualGridKey::OFF);
        }
    }
}

void VirtualGridWidget::onDragEnter(const event::DragEnter& e)
{
}

void VirtualGridWidget::onDragStart(const event::DragStart& e)
{
    ModuleWidget::onDragStart(e);
}

void VirtualGridWidget::onDragEnd(const event::DragEnd& e)
{
    ModuleWidget::onDragEnd(e);
}

void VirtualGridWidget::onDragLeave(const event::DragLeave& e)
{
    clearHeldKeys();
    ModuleWidget::onDragLeave(e);
}

void VirtualGridWidget::onHoverKey(const rack::Widget::HoverKeyEvent& e)
{
#if defined ARCH_MAC
    bool isHoldModifier = e.key == GLFW_KEY_LEFT_SUPER || e.key == GLFW_KEY_RIGHT_SUPER;
#else
    bool isHoldModifier = e.key == GLFW_KEY_LEFT_CONTROL || e.key == GLFW_KEY_RIGHT_CONTROL;
#endif

    if (isHoldModifier && e.action == GLFW_RELEASE)
    {
        clearHeldKeys();
    }
    else if (e.key == GLFW_KEY_ESCAPE && e.action == GLFW_PRESS)
    {
        clearHeldKeys();
        clearLockedKeys();
    }
}

void VirtualGridWidget::onLeave(const rack::Widget::LeaveEvent& e)
{
    clearHeldKeys();
}

void setProtocol(VirtualGridModule* grid, MonomeProtocol protocol)
{
    if (protocol != grid->device.protocol)
    {
        GridConnectionManager::get().deregisterGrid(grid->device.id, false);
        grid->device.protocol = protocol;
        GridConnectionManager::get().registerGrid(grid);
    }
}

void VirtualGridWidget::appendContextMenu(Menu * menu)
{
    VirtualGridModule* grid = dynamic_cast<VirtualGridModule*>(module);
    assert(grid);

    menu->addChild(new MenuSeparator());

    menu->addChild(createMenuItem("Save grid screenshot", "", [this]() {
        screenshotModulePNG(this, "grid-screenshot.png");
    }));

    menu->addChild(new MenuSeparator());
    menu->addChild(createIndexPtrSubmenuItem("Theme", { "Red", "Orange", "Yellow", "White" }, &grid->theme));
    menu->addChild(createIndexSubmenuItem("Protocol", {"40h", "Series", "Mext (varibright)"}, 
        [=]() { return grid ? grid->device.protocol : 0; },
        [=](size_t index) {
            setProtocol(grid, static_cast<MonomeProtocol>(index));
        }));

    menu->addChild(createMenuItem("Release Locked Keys", "Esc", [this]() {
        this->clearLockedKeys();
    }));

    menu->addChild(construct<MenuLabel>(&MenuLabel::text, model->name + " (" + id + ")"));
}