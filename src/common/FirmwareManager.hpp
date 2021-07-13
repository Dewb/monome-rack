#include <cstdint>
#include <string>

#pragma once

typedef enum
{
    FTDI_BUS,
    HID_BUS,
    NUM_BUSES
} serial_bus_t;

struct FirmwareManager
{
    FirmwareManager();
    ~FirmwareManager();

    bool load(std::string firmwarePath);

    void init();
    void step();

    bool getGPIO(uint32_t pin) const;
    void setGPIO(uint32_t pin, bool value);

    uint16_t getDAC(int channel);
    void setADC(int channel, uint16_t value);

    void serialConnectionChange(serial_bus_t bus, uint8_t connected, const char* manufacturer, const char* product, const char* serial);
    void readSerial(serial_bus_t bus, uint8_t** pbuf, uint32_t* pcount);
    void writeSerial(serial_bus_t bus, uint8_t* buf, uint32_t byteCount);

    void triggerInterrupt(int interrupt);

    void setClockPeriod(float seconds);
    void advanceClock(float seconds);

    void readNVRAM(void** ptr, uint32_t* size);
    void writeNVRAM(const void* ptr, uint32_t size);
    void readVRAM(void** ptr, uint32_t* size);
    void writeVRAM(const void* ptr, uint32_t size);

    void getScreenBuffer(uint8_t** ptr, uint16_t* width, uint16_t* height);

    void hidConnect();
    void hidDisconnect();
    void hidMessage(uint8_t key, uint8_t mod, bool held, bool release);

    struct FirmwareManagerImpl* impl;
};