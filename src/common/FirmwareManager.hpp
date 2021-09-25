#include <cstdint>
#include <string>


#pragma once

#ifdef MOCK_API
#undef MOCK_API
#endif
#define MOCK_API(RET, METHODNAME, ARGS)
#include "mock_hardware_api.h"
#define MOCK_API_SKIP_TYPES

struct FirmwareManager
{
    FirmwareManager();
    ~FirmwareManager();

    bool load(std::string firmwarePath);
    void unload();

    void setClockPeriod(float seconds);
    void advanceClock(float seconds);

#ifdef MOCK_API
#undef MOCK_API
#endif
#define MOCK_API(RET, METHODNAME, ARGS) RET METHODNAME ARGS

#include "mock_hardware_api.h"

    struct FirmwareManagerImpl* impl;
};