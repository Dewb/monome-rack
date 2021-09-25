#include <cstdint>
#include <string>


#pragma once

typedef enum
{
    FTDI_BUS,
    HID_BUS,
    NUM_BUSES
} serial_bus_t;

// from teletype/module/serialize.h -- todo: unify somehow
typedef struct
{
    void (*write_buffer)(void* user_data, uint8_t* buffer, uint16_t size);
    void (*write_char)(void* user_data, uint8_t c);
    void (*print_dbg)(const char* str);
    void *data;
} tt_serializer_t;

typedef struct
{
    uint16_t (*read_char)(void* user_data);
    bool (*eof)(void* user_data);
    void (*print_dbg)(const char* str);
    void *data;
} tt_deserializer_t;

struct FirmwareManager
{
    FirmwareManager();
    ~FirmwareManager();

    bool load(std::string firmwarePath);
    void unload();

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
    void copyScreenBuffer(uint8_t* dest);

    void hidConnect();
    void hidDisconnect();
    void hidMessage(uint8_t key, uint8_t mod, bool held, bool release);

    void iiUpdateFollowerData(uint16_t key, uint16_t value);
    bool iiPopMessage(uint8_t* addr, uint8_t* data, uint8_t* length);

    void serializePreset(tt_serializer_t* stream, uint8_t preset_num);
    void deserializePreset(tt_deserializer_t* stream, uint8_t preset_num);

    struct FirmwareManagerImpl* impl;
};