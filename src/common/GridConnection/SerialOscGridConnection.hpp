#include "GridConnection.hpp"

struct SerialOscGridConnection : GridConnection
{
    SerialOscGridConnection(MonomeModuleBase* controlledModule, const MonomeDevice* const device);

    void connect() override;
    void disconnect() override;
    void processInput() override;
    void updateQuadrant(int x, int y, uint8_t* leds) override;
    void clearAll() override;

    bool operator==(const SerialOscGridConnection& other) const;
};