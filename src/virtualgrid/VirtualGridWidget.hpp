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
    void onHoverKey(const rack::Widget::HoverKeyEvent& e) override;
    void onLeave(const rack::Widget::LeaveEvent& e) override;
    void appendContextMenu(rack::ui::Menu* menu) override;

    void clearHeldKeys();
    void clearLockedKeys();

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
