#ifndef MOCK_API_SKIP_TYPES
#include "../teletype/src/serializer.h"
#include <stdint.h>
#include <stdbool.h>
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

MOCK_API(void, postEvent, (uint32_t type, uint32_t data));

MOCK_API(void, serialConnectionChange, (bool connected, uint8_t type, uint8_t protocol, uint8_t width, uint8_t height));

MOCK_API(int, readSerial, (uint8_t** pbuf, uint8_t* pcount));
MOCK_API(int, writeSerial, (uint8_t* buf, uint8_t byteCount));

MOCK_API(void, readNVRAM, (void** ptr, uint32_t* size));
MOCK_API(void, writeNVRAM, (const void* src, uint32_t size));

MOCK_API(void, readVRAM, (void** ptr, uint32_t* size));
MOCK_API(void, writeVRAM, (const void* src, uint32_t size));

MOCK_API(void, getScreenBuffer, (uint8_t * *ptr, uint16_t* width, uint16_t* height));

MOCK_API(void, hidConnect, ());
MOCK_API(void, hidDisconnect, ());
MOCK_API(void, hidMessage, (uint8_t key, uint8_t mod, bool held, bool release));

MOCK_API(void, iiUpdateFollowerData, (uint16_t key, uint16_t data));
MOCK_API(uint16_t, iiGetFollowerData, (uint16_t key));
MOCK_API(bool, iiPushMessage, (uint8_t addr, uint8_t* data, uint8_t length));
MOCK_API(bool, iiPopMessage, (uint8_t* addr, uint8_t* data, uint8_t* length));

MOCK_API(void, serializePreset, (tt_serializer_t* stream, uint8_t preset_num));
MOCK_API(void, deserializePreset, (tt_deserializer_t* stream, uint8_t preset_num, bool clearExisting));

MOCK_API(void, getVersion, (char* buffer));
MOCK_API(double, getClockPeriod, ());
