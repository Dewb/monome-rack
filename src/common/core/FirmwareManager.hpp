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

    const std::string getLibExtension();

    bool load(std::string firmwareName);
    void unload();

    const std::string& getLoadedName() const { return loadedName; }

    void setClockPeriod(float seconds);
    void advanceClock(float seconds);

#ifdef MOCK_API
#undef MOCK_API
#endif
#define MOCK_API(RET, METHODNAME, ARGS) RET METHODNAME ARGS

#include "mock_hardware_api.h"

    struct FirmwareManagerImpl* impl;
protected:
    std::string loadedName;
};