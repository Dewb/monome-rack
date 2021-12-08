#include "rack.hpp"

#pragma once

struct VirtualGridKey;
struct VirtualGridModule;

struct VirtualGridWidget : rack::app::ModuleWidget
{
    VirtualGridWidget(VirtualGridModule* module, unsigned w, unsigned h);
    ~VirtualGridWidget();

    void draw(const DrawArgs& args) override;
    void onDragEnter(const rack::event::DragEnter& e) override;
    void onDragStart(const rack::event::DragStart& e) override;

    void clearHeldKeys();
    void appendContextMenu(rack::ui::Menu* menu) override;

protected:
    friend struct VirtualGridKey;
    rack::Vec margins;
    std::string id;
};

template <unsigned width, unsigned height>
struct VirtualGridWidgetTemplate : VirtualGridWidget
{
    VirtualGridWidgetTemplate(VirtualGridModule* module)
        : VirtualGridWidget(module, width, height)
    {
    }
};
