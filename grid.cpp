#include "grid.hpp"
#include "virtual_gpio.h"


struct MonomeKey : ParamWidget {

    uint8_t* ledAddress;
    int key_x;
    int key_y;

    typedef enum {
        OFF,
        PRESSED,
        HELD
    } KeyPressState;

    MonomeKey() : ParamWidget() {
    }

    Grid128Widget* getGrid() {
        return dynamic_cast<Grid128Widget*>(parent);
    }
        
    void setKeyAddress(int x, int y, uint8_t* ledByte)
    {
        ledAddress = ledByte;
        key_x = x;
        key_y = y;
    }

    void draw(NVGcontext *vg) override
    {
        uint8_t val = *ledAddress;
        NVGcolor color1 = nvgRGB(val * 14 + 31, val * 13 + 31, val * 11 + 16);
        NVGcolor color2 = nvgRGB(val * 12 + 31, val * 11 + 15, val * 10 + 8);

        if (value == HELD) 
        {
            nvgBeginPath(vg);
            nvgRoundedRect(vg, -3, -3, box.size.x + 6, box.size.y + 6, 6);
            nvgFillColor(vg, nvgRGB(180, 180, 0));
            nvgFill(vg);
        }

        nvgBeginPath(vg);
        auto paint = nvgBoxGradient(vg, 0, 0, box.size.x, box.size.y, box.size.x * 0.5, box.size.x * 1.2, color1, color2);
        nvgRoundedRect(vg, 0, 0, box.size.x, box.size.y, 4);
        if (val > 0)
        {
            nvgFillPaint(vg, paint);
        } 
        else
        {
            nvgFillColor(vg, nvgRGB(0,0,0));
        }
        nvgFill(vg);
    }

    void beginPress()
    {
        if (guiIsModPressed() && value != HELD) {
            // hold key down
            setValue(HELD);
        } else {
            setValue(PRESSED);
        }
    }

    void endPress()
    {
        if (value != HELD)
        {
            setValue(OFF);
        }
    }

    void onMouseDown(EventMouseDown &e) override
    {
        if (e.button == 1) { 
            return; 
        }
        e.target = this;
        e.consumed = true;
        beginPress();
    }

    void onMouseUp(EventMouseUp &e) override
    {
        if (e.button == 1) { 
            return; 
        }
        e.target = this;
        e.consumed = true;
        endPress();
    }

    void onDragStart(EventDragStart &e) override
    {
        getGrid()->keysTouchedThisDrag.clear();
        getGrid()->keysTouchedThisDrag.insert(this);
    }

    void onDragEnd(EventDragEnd &e) override
    {
        endPress();
        getGrid()->keysTouchedThisDrag.clear();
    }

    void onDragMove(EventDragMove &e) override
    {
    }

    void onDragLeave(EventDragEnter &e) override
    {
        endPress();
    }

    void onDragEnter(EventDragEnter &e) override
    {
        auto ret = getGrid()->keysTouchedThisDrag.insert(this);
        if (ret.second) 
        {
            // this button wasn't already in the touched set
            beginPress();
        }
    }
};


Grid128Widget::Grid128Widget() {

    auto *module = new Grid<16, 8>();
    setModule(module);
    box.size = Vec(15*48, 380);

    {
        auto panel = new LightPanel();
        panel->box.size = box.size;
        addChild(panel);
    }

    Vec margins(20, 20);
    int spacing = 9;

    int max_width = (box.size.x - margins.x * 2 - (module->X - 1) * spacing) / module->X;
    int max_height = (box.size.y - margins.y * 2 - (module->Y - 1) * spacing) / module->Y;
    int button_size = max_width > max_height ? max_width : max_height;

    for(int i = 0; i < module->X; i++) 
    {
        for(int j = 0; j < module->Y; j++)
        {
            int x = margins.x + i * (button_size + spacing);
            int y = margins.y + j * (button_size + spacing);
            int n = i | (j << 4);

            MonomeKey* key = (MonomeKey*)createParam<MonomeKey>(Vec(x, y), module, n, 0, 2.0, 0);
            key->setKeyAddress(x, y, module->ledBuffer + n);
            key->box.size = Vec(button_size, button_size);
            addParam(key);
        }
    }
}

json_t *Grid128Widget::toJson() {
    json_t *rootJ = json_object();

    // manufacturer
    json_object_set_new(rootJ, "plugin", json_string(model->plugin->slug.c_str()));
    // model
    json_object_set_new(rootJ, "model", json_string(model->slug.c_str()));
    // pos
    json_t *posJ = json_pack("[f, f]", (double) box.pos.x, (double) box.pos.y);
    json_object_set_new(rootJ, "pos", posJ);
    
    return rootJ;
}

void Grid128Widget::fromJson(json_t *rootJ) {
    // pos
    json_t *posJ = json_object_get(rootJ, "pos");
    double x, y;
    json_unpack(posJ, "[F, F]", &x, &y);
    box.pos = Vec(x, y);
}

void Grid128Widget::clearHeldKeys() {
    for(auto p : params) {
        p->setValue(MonomeKey::OFF);
    }
}

void Grid128Widget::onMouseDown(EventMouseDown &e)
{
    Widget::onMouseDown(e);
    if (e.consumed)
        return;

    if (e.button == 1) {
        createContextMenu();
        e.consumed = true;
        e.target = this;
    }

    if (e.button == 0 && guiIsModPressed()) { 
        clearHeldKeys();
        e.target = this;
        e.consumed = true;
    }
}

struct CloneMenuItem : MenuItem {
    ModuleWidget *moduleWidget;
    void onAction(EventAction &e) override {
        gRackWidget->cloneModule(moduleWidget);
    }
};

struct DeleteMenuItem : MenuItem {
    ModuleWidget *moduleWidget;
    void onAction(EventAction &e) override {
        gRackWidget->deleteModule(moduleWidget);
        moduleWidget->finalizeEvents();
        delete moduleWidget;
    }
};

struct GridReleaseHeldKeysItem : MenuItem {
    Grid128Widget* grid;
    void onAction(EventAction &e) override {
        grid->clearHeldKeys();
    }
};

Menu *Grid128Widget::createContextMenu() {
    Menu *menu = gScene->createMenu();

    MenuLabel *menuLabel = new MenuLabel();
    menuLabel->text = model->manufacturer + " " + model->name;
    menu->addChild(menuLabel);

    auto *cloneItem = new CloneMenuItem();
    cloneItem->text = "Duplicate";
    cloneItem->rightText = GUI_MOD_KEY_NAME "+D";
    cloneItem->moduleWidget = this;
    menu->addChild(cloneItem);

    auto *deleteItem = new DeleteMenuItem();
    deleteItem->text = "Delete";
    deleteItem->rightText = "Backspace/Delete";
    deleteItem->moduleWidget = this;
    menu->addChild(deleteItem);

    menu->addChild(construct<MenuEntry>());
    menu->addChild(construct<MenuLabel>(&MenuLabel::text, "Actions"));
    auto *releaseItem = new GridReleaseHeldKeysItem();
    releaseItem->text = "Release held keys";
    releaseItem->rightText = GUI_MOD_KEY_NAME "+Click";
    releaseItem->grid = this;
    menu->addChild(releaseItem);

    return menu;
}