#include "rack.hpp"

#pragma once

extern rack::Plugin* pluginInstance;

struct VirtualGridKey;
struct VirtualGridModule;

struct VirtualGridWidget : rack::app::ModuleWidget
{
    VirtualGridWidget(VirtualGridModule* module, unsigned w, unsigned h);
    ~VirtualGridWidget();

    void onDragEnter(const rack::event::DragEnter& e) override;
    void onDragStart(const rack::event::DragStart& e) override;
    void onDragEnd(const rack::event::DragEnd& e) override;
    void onDragLeave(const rack::event::DragLeave& e) override;
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
