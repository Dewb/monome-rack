#ifndef MOCK_API_SKIP_TYPES
#include "../teletype/src/serializer.h"
#include <stdint.h>
#include <stdbool.h>

typedef enum
{
    FTDI_BUS,
    HID_BUS, // obselete: HID no longer uses the mocked serial bus, just FTDI.
    NUM_BUSES
} serial_bus_t;
#endif

#ifndef MOCK_API
#define MOCK_API(returntype, name, argslist) returntype hardware_##name argslist
#endif

MOCK_API(void, init, ());
MOCK_API(void, step, ());

MOCK_API(void, triggerInterrupt, (int interrupt));

MOCK_API(bool, getGPIO, (uint32_t pin));
MOCK_API(void, setGPIO, (uint32_t pin, bool value));

MOCK_API(uint16_t, getADC, (int channel));
MOCK_API(void, setADC, (int channel, uint16_t value));

MOCK_API(uint16_t, getDAC, (int channel));
MOCK_API(void, setDAC, (int channel, uint16_t value));

MOCK_API(void, initSerial, ());
MOCK_API(void, resetSerialIn, ());
MOCK_API(void, resetSerialOut, ());

MOCK_API(void, serialConnectionChange, (serial_bus_t bus, uint8_t connected, const char* manufacturer, const char* product, const char* serial));

MOCK_API(void, readSerial, (serial_bus_t bus, uint8_t** pbuf, uint32_t* pcount));
MOCK_API(void, writeSerial, (serial_bus_t bus, uint8_t* buf, uint32_t byteCount));

MOCK_API(void, readSerial_internal, (serial_bus_t bus, uint8_t** pbuf, uint32_t* pcount));
MOCK_API(void, writeSerial_internal, (serial_bus_t bus, uint8_t* buf, uint32_t byteCount));

MOCK_API(void, readNVRAM, (void** ptr, uint32_t* size));
MOCK_API(void, writeNVRAM, (const void* src, uint32_t size));

MOCK_API(void, readVRAM, (void** ptr, uint32_t* size));
MOCK_API(void, writeVRAM, (const void* src, uint32_t size));

MOCK_API(void, getScreenBuffer, (uint8_t * *ptr, uint16_t* width, uint16_t* height));
MOCK_API(void, copyScreenBuffer, (uint8_t* dest));

MOCK_API(void, hidConnect, ());
MOCK_API(void, hidDisconnect, ());
MOCK_API(void, hidMessage, (uint8_t key, uint8_t mod, bool held, bool release));

MOCK_API(void, iiUpdateFollowerData, (uint16_t key, uint16_t data));
MOCK_API(uint16_t, iiGetFollowerData, (uint16_t key));
MOCK_API(bool, iiPushMessage, (uint8_t addr, uint8_t* data, uint8_t length));
MOCK_API(bool, iiPopMessage, (uint8_t* addr, uint8_t* data, uint8_t* length));

MOCK_API(void, serializePreset, (tt_serializer_t* stream, uint8_t preset_num));
MOCK_API(void, deserializePreset, (tt_deserializer_t* stream, uint8_t preset_num));