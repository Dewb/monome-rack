#include "FirmwareManager.hpp"
#include "rack.hpp"

#include <cstdio>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <unordered_set>

using namespace std;

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

#define GET_PROC_ADDRESS(handle, name)                              \
    fw_fn_##name = (fw_fn_##name##_t)GetProcAddress(handle, #name); \
    if (!fw_fn_##name)                                              \
    {                                                               \
        WARN("Failed to find symbol '" #name "'");            \
        return false;                                               \
    }

#elif ARCH_LIN || ARCH_MAC

#include <dlfcn.h>
#include <sys/stat.h>
#include <unistd.h>

#define GET_PROC_ADDRESS(handle, name)                     \
    fw_fn_##name = (fw_fn_##name##_t)dlsym(handle, #name); \
    if (!fw_fn_##name)                                     \
    {                                                      \
        WARN("Failed to find symbol '" #name "'");   \
        return false;                                      \
    }

#endif

#define DECLARE_PROC(returntype, name, argslist)    \
    typedef returntype(*fw_fn_##name##_t) argslist; \
    fw_fn_##name##_t fw_fn_##name;

struct FirmwareManagerImpl
{
    DECLARE_PROC(void, hardware_init, ())
    DECLARE_PROC(void, hardware_step, ())
    DECLARE_PROC(bool, hardware_getGPIO, (uint32_t pin))
    DECLARE_PROC(void, hardware_setGPIO, (uint32_t pin, bool value))
    DECLARE_PROC(uint16_t, hardware_getDAC, (int channel))
    DECLARE_PROC(void, hardware_setADC, (int channel, uint16_t value))
    DECLARE_PROC(void, hardware_serialConnectionChange, (serial_bus_t bus, uint8_t connected, const char* manufacturer, const char* product, const char* serial))
    DECLARE_PROC(void, hardware_readSerial, (serial_bus_t bus, uint8_t** pbuf, uint32_t* pcount))
    DECLARE_PROC(void, hardware_writeSerial, (serial_bus_t bus, uint8_t* buf, uint32_t byteCount))
    DECLARE_PROC(void, hardware_triggerInterrupt, (int interrupt))
    DECLARE_PROC(void, hardware_readNVRAM, (void** ptr, uint32_t* bytes))
    DECLARE_PROC(void, hardware_writeNVRAM, (const void* ptr, uint32_t bytes))
    DECLARE_PROC(void, hardware_readVRAM, (void** ptr, uint32_t* bytes))
    DECLARE_PROC(void, hardware_writeVRAM, (const void* ptr, uint32_t bytes))

    float clockPeriod;
    float clockPhase;

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

        SetErrorMode(SEM_NOOPENFILEERRORBOX | SEM_FAILCRITICALERRORS);
        handle = LoadLibrary(libraryToLoad.c_str());
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

        GET_PROC_ADDRESS(handle, hardware_init);
        GET_PROC_ADDRESS(handle, hardware_step);
        GET_PROC_ADDRESS(handle, hardware_getGPIO);
        GET_PROC_ADDRESS(handle, hardware_setGPIO);
        GET_PROC_ADDRESS(handle, hardware_getDAC);
        GET_PROC_ADDRESS(handle, hardware_setADC);
        GET_PROC_ADDRESS(handle, hardware_serialConnectionChange);
        GET_PROC_ADDRESS(handle, hardware_readSerial);
        GET_PROC_ADDRESS(handle, hardware_writeSerial);
        GET_PROC_ADDRESS(handle, hardware_triggerInterrupt);
        GET_PROC_ADDRESS(handle, hardware_readNVRAM);
        GET_PROC_ADDRESS(handle, hardware_writeNVRAM);
        GET_PROC_ADDRESS(handle, hardware_readVRAM);
        GET_PROC_ADDRESS(handle, hardware_writeVRAM);

        return true;
    }
};

unordered_set<string> FirmwareManagerImpl::alreadyLoadedPaths;

FirmwareManager::FirmwareManager()
{
}

FirmwareManager::~FirmwareManager()
{
    delete impl;
}

bool FirmwareManager::load(string modulePath)
{
    impl = new FirmwareManagerImpl();
    if (!impl->load(modulePath))
    {
        impl = NULL;
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

bool FirmwareManager::getGPIO(uint32_t pin) const
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

void FirmwareManager::serialConnectionChange(serial_bus_t bus, uint8_t connected, const char* manufacturer, const char* product, const char* serial)
{
    if (impl)
    {
        return impl->fw_fn_hardware_serialConnectionChange(bus, connected, manufacturer, product, serial);
    }
}

void FirmwareManager::readSerial(serial_bus_t bus, uint8_t** pbuf, uint32_t* pcount)
{
    if (impl)
    {
        return impl->fw_fn_hardware_readSerial(bus, pbuf, pcount);
    }
    else
    {
        *pbuf = NULL;
        *pcount = 0;
    }
}

void FirmwareManager::writeSerial(serial_bus_t bus, uint8_t* buf, uint32_t byteCount)
{
    if (impl)
    {
        impl->fw_fn_hardware_writeSerial(bus, buf, byteCount);
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