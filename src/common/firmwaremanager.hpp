#include <cstdint>
#include <string>

#pragma once

using namespace std;

struct FirmwareManager
{
    FirmwareManager();
    ~FirmwareManager();

    bool load(string firmwarePath);

    void init();
    void step();

    uint8_t getGPIO(uint32_t pin) const;
    void setGPIO(uint32_t pin, uint8_t value);

    uint16_t getDAC(int channel);
    void setADC(int channel, uint16_t value);

    uint8_t* readSerial(int bus);
    void writeSerial(int bus, uint8_t* buf, uint32_t byteCount);

    void triggerInterrupt(int interrupt);

    void setClockPeriod(float seconds);
    void advanceClock(float seconds);

    void readNVRAM(void** ptr, uint32_t* size);
    void writeNVRAM(const void* ptr, uint32_t size);
    void readVRAM(void** ptr, uint32_t* size);
    void writeVRAM(const void* ptr, uint32_t size);

    struct FirmwareManagerImpl* impl;
};