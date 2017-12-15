#include "GridConnection.hpp"

struct MonomeGrid;

struct RackGridConnection : GridConnection
{
    RackGridConnection(MonomeModuleBase* controlledModule, MonomeGrid* gridModule);
    MonomeGrid* grid;

    void connect() override;
    void disconnect() override;
    void processInput() override;
    void updateQuadrant(int x, int y, uint8_t* leds) override;
    void clearAll() override;

    bool operator==(const RackGridConnection& other) const;
};