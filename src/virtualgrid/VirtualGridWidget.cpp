#include "VirtualGridWidget.hpp"
#include "VirtualGridModule.hpp"
#include "window.hpp"

#include <iomanip>
#include <random>
#include <sstream>

using namespace rack;

struct MonomeKey : rack::ParamWidget
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
        : ParamWidget()
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
        if (rack::windowIsModPressed() && value != HELD)
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

    void onMouseDown(rack::EventMouseDown& e) override
    {
        if (e.button == 1)
        {
            return;
        }
        e.target = this;
        e.consumed = true;
        beginPress();
    }

    void onMouseUp(rack::EventMouseUp& e) override
    {
        if (e.button == 1)
        {
            return;
        }
        e.target = this;
        e.consumed = true;
        endPress();
    }

    void onDragStart(rack::EventDragStart& e) override
    {
        getGrid()->keysTouchedThisDrag.clear();
        getGrid()->keysTouchedThisDrag.insert(this);
        getGrid()->isDraggingKeys = true;
    }

    void onDragEnd(rack::EventDragEnd& e) override
    {
        endPress();
        getGrid()->keysTouchedThisDrag.clear();
        getGrid()->isDraggingKeys = false;
    }

    void onDragLeave(rack::EventDragEnter& e) override
    {
        if (getGrid()->isDraggingKeys)
        {
            endPress();
            getGrid()->keysTouchedThisDrag.erase(this);
        }
    }

    void onDragEnter(rack::EventDragEnter& e) override
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
        for (rack::Widget* w : rack::gRackWidget->moduleContainer->children)
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
    : ModuleWidget(module)
{
    if (model > 5)
    {
        model = 5;
    }
    std::string models[6] = { "mv40h", "mv64-", "mv128-", "mv256-", "mv512", "mv" };

    module->device.id = getUniqueVirtualDeviceId(models[model]);
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

    for (unsigned j = 0; j < h; j++)
    {
        for (unsigned i = 0; i < w; i++)
        {
            int x = margins.x + i * (button_size + spacing);
            int y = margins.y + j * (button_size + spacing);
            int n = i + j * w;

            MonomeKey* key = (MonomeKey*)createParam<MonomeKey>(Vec(x, y), module, n, 0, 2.0, 0);
            key->setKeyAddress(module->ledBuffer + i + j * 16);
            key->box.size = Vec(button_size, button_size);
            key->index = n;
            key->theme = theme;
            addParam(key);
        }
    }

    isDraggingKeys = false;
}

void VirtualGridWidget::randomize()
{
}

json_t* VirtualGridWidget::dataToJson()
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
        json_t* dataJ = module->dataToJson();
        if (dataJ)
        {
            json_object_set_new(rootJ, "data", dataJ);
        }
    }
    return rootJ;
}

void VirtualGridWidget::dataFromJson(json_t* rootJ)
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
        module->dataFromJson(dataJ);
    }
}

void VirtualGridWidget::clearHeldKeys()
{
    for (auto p : params)
    {
        p->setValue(MonomeKey::OFF);
    }
}

void VirtualGridWidget::onDragEnter(EventDragEnter& e)
{
    // Disable key drag-tapping if this drag began anyhwere but on a child key of this module
    if (e.origin->parent != this)
    {
        isDraggingKeys = false;
    }
}

void VirtualGridWidget::onMouseDown(EventMouseDown& e)
{
    ModuleWidget::onMouseDown(e);

    if (e.target == this && e.button == 0)
    {
        if (rack::windowIsModPressed())
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
    VirtualGridWidget* grid;
    void onAction(EventAction& e) override
    {
        grid->clearHeldKeys();
    }
};

Menu* VirtualGridcreateWidgetContextMenu()
{
    Menu* menu = gScene->createMenu();

    auto gridModule = dynamic_cast<VirtualGridModule*>(module);

    MenuLabel* menuLabel = new MenuLabel();
    menuLabel->text = model->name + " (" + gridModule->device.id + ")";
    menu->addChild(menuLabel);

    auto* cloneItem = new CloneMenuItem();
    cloneItem->text = "Duplicate";
    cloneItem->rightText = WINDOW_MOD_KEY_NAME "+D";
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
    releaseItem->rightText = WINDOW_MOD_KEY_NAME "+Click";
    releaseItem->grid = this;
    menu->addChild(releaseItem);

    return menu;
}