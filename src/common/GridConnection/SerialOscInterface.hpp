#include "SerialOsc.h"

struct SerialOscInterface : public SerialOsc::Listener
{
    SerialOscInterface();
    ~SerialOscInterface();

    // SerialOsc::Listener methods
    void deviceFound(const MonomeDevice* const device) override;
    void deviceRemoved(const std::string& id) override;
    void buttonPressMessageReceived(MonomeDevice* device, int x, int y, bool state) override;

    SerialOsc* driver;
};
