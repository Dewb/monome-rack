#include "VirtualGridWidget.hpp"
#include "VirtualGridKey.hpp"
#include "VirtualGridTheme.hpp"
#include "VirtualGridModule.hpp"
#include "window.hpp"


using namespace rack;


VirtualGridWidget::VirtualGridWidget(VirtualGridModule* module, unsigned w, unsigned h)
{
    setModule(module);

    float rackWidth = 0;
    if (w == h)
    {
        rackWidth = 375;
        margins.x = 13.5;
        margins.y = 16;

    }
    else if (w == 2 * h)
    {
        rackWidth = 735;
        margins.x = 16;
        margins.y = 16;
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

            VirtualGridKey* key = (VirtualGridKey*)createParam<VirtualGridKey>(Vec(x, y), module, n);
            if (module)
            {
                key->setKeyAddress(module->ledBuffer + i + j * 16);
                key->theme = &(module->theme);
            }
            key->box.size = Vec(button_size + spacing, button_size + spacing);
            key->index = n;
            key->margin = keyMargin;
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
            p->paramQuantity->setValue(VirtualGridKey::OFF);
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
        if (grid) 
        {
            grid->clearHeldKeys();
        }
    }
};

struct GridThemeItem : MenuItem
{
    VirtualGridModule* module;
    GridTheme theme;
    
    GridThemeItem(VirtualGridModule* module, std::string str, GridTheme theme) 
    : module(module), theme(theme) {
        text = str;
        rightText = (module->theme == theme) ? CHECKMARK_STRING : "";
    };

    void onAction(const event::Action& e) override
    {
        if (module)
        {
            module->theme = theme;
        }
    }
};

struct GridProtocolItem : MenuItem
{
    VirtualGridModule* module;
    MonomeProtocol protocol;

    GridProtocolItem(VirtualGridModule* module, std::string str, MonomeProtocol protocol)
     : module(module), protocol(protocol) {
        text = str;
        rightText = (module->device.protocol == protocol) ? CHECKMARK_STRING : "";
    };

    void onAction(const event::Action& e) override
    {
        if (module && protocol != module->device.protocol) 
        {
            GridConnectionManager::get()->deregisterGrid(module->device.id, false);
            module->device.protocol = protocol;
            GridConnectionManager::get()->registerGrid(module);
        }
    }
};

void
VirtualGridWidget::appendContextMenu(Menu* menu)
{
    VirtualGridModule* grid = dynamic_cast<VirtualGridModule*>(module);
    assert(grid);

    menu->addChild(construct<MenuLabel>());
    menu->addChild(construct<MenuLabel>(&MenuLabel::text, "Theme"));
    menu->addChild(new GridThemeItem(grid, "\tRed", GridTheme::Red));
    menu->addChild(new GridThemeItem(grid, "\tOrange", GridTheme::Orange));
    menu->addChild(new GridThemeItem(grid, "\tYellow", GridTheme::Yellow));
    menu->addChild(new GridThemeItem(grid, "\tWhite", GridTheme::White));
    menu->addChild(construct<MenuLabel>());
    menu->addChild(construct<MenuLabel>(&MenuLabel::text, "Protocol"));

    // 40h only on 8x8
    if (grid->getDevice().width == 8 && grid->getDevice().height == 8)
    {
        menu->addChild(new GridProtocolItem(grid, "\t40h", PROTOCOL_40H));
    }
    menu->addChild(new GridProtocolItem(grid, "\tSeries", PROTOCOL_SERIES));
    menu->addChild(new GridProtocolItem(grid, "\tMext", PROTOCOL_MEXT));

    menu->addChild(construct<MenuLabel>());
    menu->addChild(construct<GridReleaseHeldKeysItem>(&MenuItem::text, "Release Held Keys", &MenuItem::rightText, "Ctrl+Click", &GridReleaseHeldKeysItem::grid, this));
    menu->addChild(construct<MenuLabel>(&MenuLabel::text, model->name + " (" + grid->device.id + ")"));
}