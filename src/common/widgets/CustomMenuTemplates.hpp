#pragma once

#include "rack.hpp"
using namespace rack;

template <class TMenuItem = ui::MenuItem>
TMenuItem* createUnconsumingIndexSubmenuItem(std::string text, std::vector<std::string> labels, std::function<size_t()> getter, std::function<void(size_t val)> setter, bool disabled = false)
{
    struct IndexItem : ui::MenuItem
    {
        std::function<size_t()> getter;
        std::function<void(size_t)> setter;
        size_t index;

        void step() override
        {
            size_t currIndex = getter();
            this->rightText = CHECKMARK(currIndex == index);
            MenuItem::step();
        }
        void onAction(const event::Action& e) override
        {
            setter(index);
            e.unconsume();
        }
    };

    struct Item : TMenuItem
    {
        std::function<size_t()> getter;
        std::function<void(size_t)> setter;
        std::vector<std::string> labels;

        void step() override
        {
            size_t currIndex = getter();
            std::string label = (currIndex < labels.size()) ? labels[currIndex] : "";
            this->rightText = label + "  " + RIGHT_ARROW;
            TMenuItem::step();
        }
        ui::Menu* createChildMenu() override
        {
            ui::Menu* menu = new ui::Menu;
            for (size_t i = 0; i < labels.size(); i++)
            {
                IndexItem* item = createMenuItem<IndexItem>(labels[i]);
                item->getter = getter;
                item->setter = setter;
                item->index = i;
                menu->addChild(item);
            }
            return menu;
        }
    };

    Item* item = createMenuItem<Item>(text);
    item->getter = getter;
    item->setter = setter;
    item->labels = labels;
    item->disabled = disabled;
    return item;
}

template <class TMenuItem = ui::MenuItem>
TMenuItem* createUnconsumingIndexSubmenuItemWithDynamicLabels(std::string text, std::function<std::vector<std::string>()> getLabels, std::function<size_t()> getter, std::function<void(size_t val)> setter, bool disabled = false)
{
    struct IndexItem : ui::MenuItem
    {
        std::function<size_t()> getter;
        std::function<void(size_t)> setter;
        size_t index;

        void step() override
        {
            size_t currIndex = getter();
            this->rightText = CHECKMARK(currIndex == index);
            MenuItem::step();
        }
        void onAction(const event::Action& e) override
        {
            setter(index);
            e.unconsume();
        }
    };

    struct Item : TMenuItem
    {
        std::function<std::vector<std::string>()> getLabels;
        std::function<size_t()> getter;
        std::function<void(size_t)> setter;

        void step() override
        {
            size_t currIndex = getter();
            auto labels = getLabels();
            std::string label = (currIndex < labels.size()) ? labels[currIndex] : "";
            this->rightText = label + "  " + RIGHT_ARROW;
            TMenuItem::step();
        }
        ui::Menu* createChildMenu() override
        {
            ui::Menu* menu = new ui::Menu;
            auto labels = getLabels();
            for (size_t i = 0; i < labels.size(); i++)
            {
                IndexItem* item = createMenuItem<IndexItem>(labels[i]);
                item->getter = getter;
                item->setter = setter;
                item->index = i;
                menu->addChild(item);
            }
            return menu;
        }
    };

    Item* item = createMenuItem<Item>(text);
    item->getter = getter;
    item->setter = setter;
    item->getLabels = getLabels;
    item->disabled = disabled;
    return item;
}

template <class TMenuItem = ui::MenuItem>
TMenuItem* createSubmenuItemWithDynamicRightText(std::string text, std::function<std::string(void)> getRightText, std::function<void(ui::Menu* menu)> createMenu, bool disabled = false)
{
    struct Item : TMenuItem
    {
        std::function<std::string(void)> getRightText;
        std::function<void(ui::Menu* menu)> createMenu;

        void step() override
        {
            this->rightText = getRightText() + "  " + RIGHT_ARROW;
            TMenuItem::step();
        }

        ui::Menu* createChildMenu() override
        {
            ui::Menu* menu = new ui::Menu;
            createMenu(menu);
            return menu;
        }
    };

    Item* item = createMenuItem<Item>(text, getRightText() + "  " + RIGHT_ARROW);
    item->getRightText = getRightText;
    item->createMenu = createMenu;
    item->disabled = disabled;
    return item;
}