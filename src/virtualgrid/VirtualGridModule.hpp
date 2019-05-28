#pragma once
#include "GridConnection.hpp"
#include "rack.hpp"

#define GRID_MAX_SIZE 256

struct VirtualGridModule : rack::Module, Grid
{
    MonomeDevice device;

    uint8_t ledBuffer[GRID_MAX_SIZE];
    bool pressedState[GRID_MAX_SIZE];

    VirtualGridModule(unsigned w, unsigned h);
    ~VirtualGridModule();

    void process(const ProcessArgs& args) override;

    json_t* dataToJson() override;
    void dataFromJson(json_t* rootJ) override;

    // Grid methods
    const MonomeDevice& getDevice() override;
    void updateRow(int x_offset, int y, uint8_t bitfield) override;
    void updateQuadrant(int x_offset, int y_offset, uint8_t* leds) override;
    void clearAll() override;

protected:
    bool firstStep;
};

template <unsigned width, unsigned height, unsigned modelIndex>
struct VirtualGridModuleTemplate : VirtualGridModule
{
    VirtualGridModuleTemplate()
        : VirtualGridModule(width, height)
    {
    }
};
