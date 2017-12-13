#include <iomanip>
#include <random>
#include <sstream>

#include "grid.hpp"

MonomeGrid::MonomeGrid(unsigned w, unsigned h)
    : Module(w * h, 0, 0, 0)
{
    device.width = w;
    device.height = h;
    device.port = 0;
    device.rotation = 0;
    device.id = "mv000000";
    device.prefix = "";
    device.type = "virtual " + std::to_string(w * h);

    clearAll();
}

void MonomeGrid::step()
{
    if (connectedModule)
    {
        for (int i = 0; i < device.width; i++)
        {
            for (int j = 0; j < device.height; j++)
            {
                int n = i + (j * device.width);
                if ((params[n].value > 0) != pressedState[n])
                {
                    connectedModule->buttonPressMessageReceived(NULL, i, j, params[n].value > 0);
                    pressedState[n] = params[n].value > 0;
                }
            }
        }
    }
    else
    {
        clearAll();
    }
}

void MonomeGrid::reset()
{
}

void MonomeGrid::randomize()
{
}

json_t* MonomeGrid::toJson()
{
    json_t* rootJ = json_object();
    json_object_set_new(rootJ, "deviceId", json_string(device.id.c_str()));
    return rootJ;
}

void MonomeGrid::fromJson(json_t* rootJ)
{
    device.id = json_string_value(json_object_get(rootJ, "deviceId"));
}

void MonomeGrid::updateQuadrant(int x, int y, uint8_t* leds)
{
    uint8_t* ptr = ledBuffer + y * 16 + x;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            *ptr++ = *leds++;
        }
        ptr += 8;
    }
}

void MonomeGrid::clearAll()
{
    memset(ledBuffer, 0, sizeof(uint8_t) * GRID_MAX_SIZE);
}

struct MonomeKey : ParamWidget
{
    uint8_t* ledAddress;
    int key_x;
    int key_y;
    int index;
    GridTheme theme;

    typedef enum {
        OFF,
        PRESSED,
        HELD
    } KeyPressState;

    MonomeKey()
        : ParamWidget()
    {
    }

    MonomeGridWidget* getGrid()
    {
        return dynamic_cast<MonomeGridWidget*>(parent);
    }

    void setKeyAddress(int x, int y, uint8_t* ledByte)
    {
        ledAddress = ledByte;
        key_x = x;
        key_y = y;
    }

    void draw(NVGcontext* vg) override
    {
        uint8_t val = *ledAddress;
        NVGcolor color1 = nvgRGB(val * 11 + 90, val * 11 + 63, val * 8 + 48);
        NVGcolor color2 = nvgRGB(val * 12 + 48, val * 12 + 31, val * 4 + 16);

        if (theme == MonoRed)
        {
            color1 = val > 0 ? nvgRGB(240, 140, 30) : nvgRGB(0, 0, 0);
            color2 = val > 0 ? nvgRGB(250, 60, 20) : nvgRGB(0, 0, 0);
        }

        if (value == HELD)
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
        label << index;
        nvgTextAlign(vg, NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE);
        nvgFillColor(vg, nvgRGB(0, 0, 0));
        nvgText(vg, box.size.x / 2, box.size.y / 2, label.str().c_str(), NULL);
        nvgFillColor(vg, nvgRGB(255, 255, 255));
        nvgText(vg, box.size.x / 2 - 1, box.size.y / 2 - 1, label.str().c_str(), NULL);
        */
    }

    void beginPress()
    {
        if (guiIsModPressed() && value != HELD)
        {
            // hold key down
            setValue(HELD);
        }
        else
        {
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

    void onMouseDown(EventMouseDown& e) override
    {
        if (e.button == 1)
        {
            return;
        }
        e.target = this;
        e.consumed = true;
        beginPress();
    }

    void onMouseUp(EventMouseUp& e) override
    {
        if (e.button == 1)
        {
            return;
        }
        e.target = this;
        e.consumed = true;
        endPress();
    }

    void onDragStart(EventDragStart& e) override
    {
        getGrid()->keysTouchedThisDrag.clear();
        getGrid()->keysTouchedThisDrag.insert(this);
        getGrid()->isDraggingKeys = true;
    }

    void onDragEnd(EventDragEnd& e) override
    {
        endPress();
        getGrid()->keysTouchedThisDrag.clear();
        getGrid()->isDraggingKeys = false;
    }

    void onDragLeave(EventDragEnter& e) override
    {
        if (getGrid()->isDraggingKeys)
        {
            endPress();
            getGrid()->keysTouchedThisDrag.erase(this);
        }
    }

    void onDragEnter(EventDragEnter& e) override
    {
        if (getGrid()->isDraggingKeys)
        {
            auto ret = getGrid()->keysTouchedThisDrag.insert(this);
            if (ret.second)
            {
                // this button wasn't already in the touched set
                beginPress();
            }
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
        for (Widget* w : gRackWidget->moduleContainer->children)
        {
            MonomeGridWidget* gridWidget = dynamic_cast<MonomeGridWidget*>(w);
            if (gridWidget)
            {
                auto gridModule = dynamic_cast<MonomeGrid*>(gridWidget->module);
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

MonomeGridWidget::MonomeGridWidget(unsigned w, unsigned h, unsigned model)
{
    if (model > 5)
    {
        model = 5;
    }
    string models[6] = { "mv40h", "mv64-", "mv128-", "mv256-", "mv512", "mv" };

    auto* module = new MonomeGrid(w, h);
    module->device.id = getUniqueVirtualDeviceId(models[model]);
    setModule(module);

    theme = model == 5 ? VariYellow : MonoRed;

    box.size = Vec(43.125 * w + 30, 47.5 * h);

    {
        auto panel = new LightPanel();
        panel->box.size = box.size;
        addChild(panel);
    }

    margins.x = 15;
    margins.y = 15;

    int spacing = 8;

    //int max_width = (box.size.x - margins.x * 2 - (w - 1) * spacing) / w;
    int max_height = (box.size.y - margins.y * 2 - (h - 1) * spacing) / h;
    int button_size = max_height; // max_width > max_height ? max_width : max_height;

    for (unsigned i = 0; i < w; i++)
    {
        for (unsigned j = 0; j < h; j++)
        {
            int x = margins.x + i * (button_size + spacing);
            int y = margins.y + j * (button_size + spacing);
            int n = i + j * w;

            MonomeKey* key = (MonomeKey*)createParam<MonomeKey>(Vec(x, y), module, n, 0, 2.0, 0);
            key->setKeyAddress(x, y, module->ledBuffer + i + j * 16);
            key->box.size = Vec(button_size, button_size);
            key->index = n;
            key->theme = theme;
            addParam(key);
        }
    }

    isDraggingKeys = false;
}

json_t* MonomeGridWidget::toJson()
{
    json_t* rootJ = json_object();

    // manufacturer
    json_object_set_new(rootJ, "plugin", json_string(model->plugin->slug.c_str()));
    // model
    json_object_set_new(rootJ, "model", json_string(model->slug.c_str()));
    // pos
    json_t* posJ = json_pack("[f, f]", (double)box.pos.x, (double)box.pos.y);
    json_object_set_new(rootJ, "pos", posJ);

    // no param serialization

    // data
    if (module)
    {
        json_t* dataJ = module->toJson();
        if (dataJ)
        {
            json_object_set_new(rootJ, "data", dataJ);
        }
    }
    return rootJ;
}

void MonomeGridWidget::fromJson(json_t* rootJ)
{
    // pos
    json_t* posJ = json_object_get(rootJ, "pos");
    double x, y;
    json_unpack(posJ, "[F, F]", &x, &y);
    box.pos = Vec(x, y);

    // no param deserialization

    // data
    json_t* dataJ = json_object_get(rootJ, "data");
    if (dataJ && module)
    {
        module->fromJson(dataJ);
    }
}

void MonomeGridWidget::clearHeldKeys()
{
    for (auto p : params)
    {
        p->setValue(MonomeKey::OFF);
    }
}

void MonomeGridWidget::onDragEnter(EventDragEnter& e)
{
    // Disable key drag-tapping if this drag began anyhwere but on a child key of this module
    if (e.origin->parent != this)
    {
        isDraggingKeys = false;
    }
}

void MonomeGridWidget::onMouseDown(EventMouseDown& e)
{
    ModuleWidget::onMouseDown(e);

    if (e.target == this && e.button == 0)
    {
        if (guiIsModPressed())
        {
            clearHeldKeys();
            e.consumed = true;
            return;
        }
        else
        {
            // Allow drag only at edges of module
            if (e.pos.x < margins.x || e.pos.x > box.size.x - margins.x || e.pos.y < margins.y || e.pos.y > box.size.y - margins.y)
            {
                return;
            }
            else
            {
                e.consumed = true;
                e.target = NULL;
            }
        }
    }

    if (e.button == 1)
    {
        createContextMenu();
        e.consumed = true;
        e.target = this;
    }
}

struct CloneMenuItem : MenuItem
{
    ModuleWidget* moduleWidget;
    void onAction(EventAction& e) override
    {
        gRackWidget->cloneModule(moduleWidget);
    }
};

struct DeleteMenuItem : MenuItem
{
    ModuleWidget* moduleWidget;
    void onAction(EventAction& e) override
    {
        gRackWidget->deleteModule(moduleWidget);
        moduleWidget->finalizeEvents();
        delete moduleWidget;
    }
};

struct GridReleaseHeldKeysItem : MenuItem
{
    MonomeGridWidget* grid;
    void onAction(EventAction& e) override
    {
        grid->clearHeldKeys();
    }
};

Menu* MonomeGridWidget::createContextMenu()
{
    Menu* menu = gScene->createMenu();

    auto gridModule = dynamic_cast<MonomeGrid*>(module);

    MenuLabel* menuLabel = new MenuLabel();
    menuLabel->text = model->manufacturer + " " + model->name + " (" + gridModule->device.id + ")";
    menu->addChild(menuLabel);

    auto* cloneItem = new CloneMenuItem();
    cloneItem->text = "Duplicate";
    cloneItem->rightText = GUI_MOD_KEY_NAME "+D";
    cloneItem->moduleWidget = this;
    menu->addChild(cloneItem);

    auto* deleteItem = new DeleteMenuItem();
    deleteItem->text = "Delete";
    deleteItem->rightText = "Backspace/Delete";
    deleteItem->moduleWidget = this;
    menu->addChild(deleteItem);

    menu->addChild(construct<MenuEntry>());
    menu->addChild(construct<MenuLabel>(&MenuLabel::text, "Actions"));
    auto* releaseItem = new GridReleaseHeldKeysItem();
    releaseItem->text = "Release held keys";
    releaseItem->rightText = GUI_MOD_KEY_NAME "+Click";
    releaseItem->grid = this;
    menu->addChild(releaseItem);

    return menu;
}