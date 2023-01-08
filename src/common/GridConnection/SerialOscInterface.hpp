#include "SerialOsc.h"

struct SerialOscInterface final : public SerialOsc::Listener
{
    // constructor is private
    ~SerialOscInterface();

    bool isServiceDetected() const;
    std::string getServiceVersion() const;

    // SerialOsc::Listener methods
    void deviceFound(const MonomeDevice* const device) override;
    void deviceRemoved(const std::string& id) override;
    void buttonPressMessageReceived(MonomeDevice* device, int x, int y, bool state) override;
    void encDeltaMessageReceived(MonomeDevice* device, int n, int delta) override;

    SerialOsc* driver;

    static SerialOscInterface* get();

private:
    SerialOscInterface();
    SerialOscInterface(const SerialOscInterface&) = delete;
    SerialOscInterface& operator=(const SerialOscInterface&) = delete;
    SerialOscInterface(SerialOscInterface&&) = delete;
    SerialOscInterface&& operator=(const SerialOscInterface&&) = delete;
};
