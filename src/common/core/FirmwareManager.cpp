#include "FirmwareManager.hpp"
#include "rack.hpp"

#include <cstdio>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <unordered_set>

extern rack::Plugin* pluginInstance;

#if ARCH_LIN
#define LIB_EXTENSION ".so"
#define PATH_SEPARATOR '/'
#define MODULE_HANDLE_TYPE void*
#elif ARCH_WIN
#define LIB_EXTENSION ".dll"
#define PATH_SEPARATOR '\\'
#define MODULE_HANDLE_TYPE HINSTANCE
#elif ARCH_MAC
#define LIB_EXTENSION ".dylib"
#define PATH_SEPARATOR '/'
#define MODULE_HANDLE_TYPE void*
#endif

#if ARCH_WIN

#include <direct.h>
#include <windows.h>

#define GET_PROC_ADDRESS(returntype, name, argslist)   \
    fw_fn_hardware_##name = reinterpret_cast<fw_fn_hardware_##name##_t>( \
        reinterpret_cast<void*>(                       \
            GetProcAddress(handle, "hardware_" #name)));           \
    if (!fw_fn_hardware_##name)                                 \
    {                                                  \
        WARN("Failed to find symbol 'hardware" #name "'");     \
        return false;                                  \
    }

#elif ARCH_LIN || ARCH_MAC

#include <dlfcn.h>
#include <sys/stat.h>
#include <unistd.h>

#define GET_PROC_ADDRESS(returntype, name, argslist)   \
    fw_fn_hardware_##name = reinterpret_cast<fw_fn_hardware_##name##_t>( \
        reinterpret_cast<void*>(                       \
            dlsym(handle, "hardware_" #name)));                    \
    if (!fw_fn_hardware_##name)                                 \
    {                                                  \
        WARN("Failed to find symbol 'hardware_" #name "'");     \
        return false;                                  \
    }

#endif

#define DECLARE_PROC(returntype, name, argslist)    \
    typedef returntype(*fw_fn_hardware_##name##_t) argslist; \
    fw_fn_hardware_##name##_t fw_fn_hardware_##name;

struct FirmwareManagerImpl
{
#ifdef MOCK_API
#undef MOCK_API
#endif
#define MOCK_API DECLARE_PROC
#include "mock_hardware_api.h"

    double clockPeriod;
    double clockPhase;

    std::string tempLibraryFolder;
    std::string tempLibraryFile;

    MODULE_HANDLE_TYPE handle;

    static std::unordered_set<std::string> alreadyLoadedPaths;

    FirmwareManagerImpl()
    {
        clockPhase = 0.0;
        clockPeriod = 0.001;
    }

    ~FirmwareManagerImpl()
    {
#if ARCH_WIN
        FreeLibrary(handle);
#elif ARCH_LIN || ARCH_MAC
        dlclose(handle);
#endif

        if (!tempLibraryFile.empty())
        {
            unlink(tempLibraryFile.c_str());
        }
        if (!tempLibraryFolder.empty())
        {
            rmdir(tempLibraryFolder.c_str());
        }
    }

    bool load(std::string firmwareName)
    {
        using namespace rack;

        std::string librarySource;
        librarySource = rack::asset::plugin(pluginInstance, "res/firmware/" + firmwareName + LIB_EXTENSION);
        std::string libraryToLoad = librarySource;

        // If we have already loaded this firmware at least once, create a temp copy so it will have its own address space
        if (alreadyLoadedPaths.find(libraryToLoad) != alreadyLoadedPaths.end())
        {
            bool success = false;

#if ARCH_WIN
            char* tempdir = 0;
            (tempdir = getenv("TMPDIR")) || (tempdir = getenv("TMP")) || (tempdir = getenv("TEMP")) || (tempdir = getenv("TEMPDIR")) || (tempdir = getenv("LOCALAPPDATA"));

            if (tempdir != 0)
            {
                char* name = tmpnam(NULL);
                if (name != 0)
                {
                    tempLibraryFolder = tempdir;
                    if (tempLibraryFolder.back() != PATH_SEPARATOR && name[0] != PATH_SEPARATOR)
                    {
                        tempLibraryFolder += PATH_SEPARATOR;
                    }
                    tempLibraryFolder += std::string(name);

                    if (mkdir(tempLibraryFolder.c_str()) == 0)
                    {
                        success = true;
                    }
                }
            }

#elif ARCH_LIN || ARCH_MAC

            char* name = tmpnam(NULL);
            if (name != 0)
            {
                tempLibraryFolder = name;

                if (mkdir(tempLibraryFolder.c_str(), 0777) == 0)
                {
                    success = true;
                }
            }

#endif

            if (!success)
            {
                WARN("Could not create temporary folder for firmware");
                return false;
            }

            tempLibraryFile = tempLibraryFolder + PATH_SEPARATOR + "monome_vcvrack_firmware" + LIB_EXTENSION;

            INFO("Creating new temporary firmware instance at %s", tempLibraryFile.c_str());

            {
                std::ifstream src(librarySource, std::ios::binary);
                std::ofstream dst(tempLibraryFile, std::ios::binary);
                dst << src.rdbuf();
            }

            libraryToLoad = tempLibraryFile;
        }
        else
        {
            // first time load, record it.
            alreadyLoadedPaths.insert(libraryToLoad);
        }

        INFO("Loading module firmware from %s", libraryToLoad.c_str());

#if ARCH_WIN

        wchar_t* libName = new wchar_t[4096];
        MultiByteToWideChar(CP_ACP, 0, libraryToLoad.c_str(), -1, libName, 4096);

        SetErrorMode(SEM_NOOPENFILEERRORBOX | SEM_FAILCRITICALERRORS);
        handle = LoadLibrary(libName);
        SetErrorMode(0);
        if (!handle)
        {
            int error = GetLastError();
            WARN("Failed to load library %s: %d", libraryToLoad.c_str(), error);
            return false;
        }

#elif ARCH_LIN || ARCH_MAC

        handle = dlopen(libraryToLoad.c_str(), RTLD_NOW | RTLD_LOCAL);
        if (!handle)
        {
            WARN("Failed to load library %s: %s", libraryToLoad.c_str(), dlerror());
            return false;
        }

#endif

#ifdef MOCK_API
#undef MOCK_API
#endif
#define MOCK_API GET_PROC_ADDRESS
#include "mock_hardware_api.h"

        // cache this so we don't have to call it constantly
        clockPeriod = fw_fn_hardware_getClockPeriod();

        return true;
    }
};

std::unordered_set<std::string> FirmwareManagerImpl::alreadyLoadedPaths;

FirmwareManager::FirmwareManager()
    : impl(nullptr)
{
}

FirmwareManager::~FirmwareManager()
{
    delete impl;
}

bool FirmwareManager::load(std::string modulePath)
{
    delete impl;
    impl = new FirmwareManagerImpl();
    if (!impl->load(modulePath))
    {
        impl = nullptr;
        WARN("Could not load firmware %s", modulePath.c_str());
        return false;
    }
    return true;
}

void FirmwareManager::init()
{
    if (impl)
    {
        impl->fw_fn_hardware_init();
    }
}

void FirmwareManager::step()
{
    if (impl)
    {
        impl->fw_fn_hardware_step();
    }
}

bool FirmwareManager::getGPIO(uint32_t pin)
{
    if (impl)
    {
        return impl->fw_fn_hardware_getGPIO(pin);
    }
    else
    {
        return false;
    }
}

void FirmwareManager::setGPIO(uint32_t pin, bool value)
{
    if (impl)
    {
        impl->fw_fn_hardware_setGPIO(pin, value);
    }
}

uint16_t FirmwareManager::getDAC(int channel)
{
    if (impl)
    {
        return impl->fw_fn_hardware_getDAC(channel);
    }
    else
    {
        return 0;
    }
}

void FirmwareManager::setADC(int channel, uint16_t value)
{
    if (impl)
    {
        impl->fw_fn_hardware_setADC(channel, value);
    }
}

void FirmwareManager::postEvent(uint32_t type, uint32_t data)
{
    if (impl)
    {
        impl->fw_fn_hardware_postEvent(type, data);
    }
}

void FirmwareManager::serialConnectionChange(bool connected, uint8_t type, uint8_t protocol, uint8_t width, uint8_t height)
{
    if (impl)
    {
        return impl->fw_fn_hardware_serialConnectionChange(connected, type, protocol, width, height);
    }
}

int FirmwareManager::readSerial(uint8_t** pbuf, uint8_t* pcount)
{
    if (impl)
    {
        return impl->fw_fn_hardware_readSerial(pbuf, pcount);
    }
    else
    {
        *pbuf = NULL;
        *pcount = 0;
        return -1;
    }
}

int FirmwareManager::writeSerial(uint8_t* buf, uint8_t byteCount)
{
    if (impl)
    {
        return impl->fw_fn_hardware_writeSerial(buf, byteCount);
    }
    else 
    {
        return -1;
    }
}

void FirmwareManager::triggerInterrupt(int interrupt)
{
    if (impl)
    {
        impl->fw_fn_hardware_triggerInterrupt(interrupt);
    }
}

void FirmwareManager::setClockPeriod(float seconds)
{
    if (impl)
    {
        impl->clockPeriod = seconds;
    }
}

void FirmwareManager::advanceClock(float seconds)
{
    if (impl)
    {
        impl->clockPhase += seconds;
        if (impl->clockPhase > impl->clockPeriod)
        {
            impl->clockPhase -= impl->clockPeriod;
            impl->fw_fn_hardware_triggerInterrupt(0);
        }
    }
}

void FirmwareManager::readNVRAM(void** ptr, uint32_t* size)
{
    if (impl)
    {
        impl->fw_fn_hardware_readNVRAM(ptr, size);
    }
}

void FirmwareManager::writeNVRAM(const void* ptr, uint32_t size)
{
    if (impl)
    {
        impl->fw_fn_hardware_writeNVRAM(ptr, size);
    }
}

void FirmwareManager::readVRAM(void** ptr, uint32_t* size)
{
    if (impl)
    {
        impl->fw_fn_hardware_readVRAM(ptr, size);
    }
}

void FirmwareManager::writeVRAM(const void* ptr, uint32_t size)
{
    if (impl)
    {
        impl->fw_fn_hardware_writeVRAM(ptr, size);
    }
}

void FirmwareManager::setScreenBuffer(uint8_t* ptr)
{
    if (impl)
    {
        impl->fw_fn_hardware_setScreenBuffer(ptr);
    }
}

void FirmwareManager::hidConnect()
{
    if (impl)
    {
        impl->fw_fn_hardware_hidConnect();
    }
}

void FirmwareManager::hidDisconnect()
{
    if (impl)
    {
        impl->fw_fn_hardware_hidDisconnect();
    }
}

void FirmwareManager::hidMessage(uint8_t key, uint8_t mod, bool held, bool release)
{
    if (impl)
    {
        impl->fw_fn_hardware_hidMessage(key, mod, held, release);
    }
}

void FirmwareManager::iiUpdateFollowerData(uint16_t key, uint16_t value)
{
    if (impl)
    {
        impl->fw_fn_hardware_iiUpdateFollowerData(key, value);
    }
}

bool FirmwareManager::iiPopMessage(uint8_t* addr, uint8_t* data, uint8_t* length)
{
    if (impl)
    {
        return impl->fw_fn_hardware_iiPopMessage(addr, data, length);
    }
    return false;
}

void FirmwareManager::serializePreset(tt_serializer_t* stream, uint8_t preset_num)
{
    if (impl)
    {
        return impl->fw_fn_hardware_serializePreset(stream, preset_num);
    }
}

void FirmwareManager::deserializePreset(tt_deserializer_t* stream, uint8_t preset_num, bool clearExisting)
{
    if (impl)
    {
        return impl->fw_fn_hardware_deserializePreset(stream, preset_num, clearExisting);
    }
}

void FirmwareManager::getVersion(char* buffer)
{
    if (impl)
    {
        return impl->fw_fn_hardware_getVersion(buffer);
    }
}

double FirmwareManager::getClockPeriod()
{
    if (impl)
    {
        return impl->fw_fn_hardware_getClockPeriod();
    }
    else
    {
        return 0.001;
    }
}
