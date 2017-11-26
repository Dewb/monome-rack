#include "rack.hpp"
#include "monomemodulebase.hpp"

#include <unordered_set>

using namespace rack;


template <size_t GRID_X, size_t GRID_Y>
struct Grid : Module
{

    enum ParamIds
    {
        NUM_PARAMS = GRID_X * GRID_Y
    };
    enum InputIds
    {
        NUM_INPUTS
    };
    enum OutputIds
    {
        NUM_OUTPUTS
    };
    enum LightIds
    {
        NUM_LIGHTS = GRID_X * GRID_Y
    };

    const int X = GRID_X;
    const int Y = GRID_Y;
    bool pressedState[GRID_X * GRID_Y];

    MonomeModuleBase* connectedModule = NULL;
    uint8_t ledBuffer[256];

    Grid() : Module(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS)
    {
        memset(ledBuffer, 0, sizeof(uint8_t) * 256);
    }

    void step() override
    {
        if (connectedModule)
        {
            for (size_t i = 0; i < GRID_X; i++)
            {
                for (size_t j = 0; j < GRID_Y; j++)
                {
                    int n = i | (j << 4);
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
            memset(ledBuffer, 0, sizeof(uint8_t) * 256);
        }
    }

    json_t *toJson() override
    {
        json_t *rootJ = json_object();
        return rootJ;
    }

    void fromJson(json_t *rootJ) override
    {
    }

    void reset() override
    {
    }

    void randomize() override
    {
    }

    void updateQuadrant(int x, int y, uint8_t *leds)
    {
        uint8_t *ptr = ledBuffer + y * 16 + x;
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                *ptr++ = *leds++;
            }
            ptr += 8;
        }
    }
};

struct MonomeKey;

struct Grid128Widget : ModuleWidget {
    Grid128Widget();

    json_t* toJson() override;
    void fromJson(json_t *rootJ) override;
    Menu *createContextMenu() override;
    void onMouseDown(EventMouseDown &e) override;

    void clearHeldKeys();

protected:
    friend struct MonomeKey;
    std::unordered_set<MonomeKey*> keysTouchedThisDrag;
};


