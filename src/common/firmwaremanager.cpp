#include "firmwaremanager.hpp"
#include "util.hpp"

#include <cstdio>
#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace rack;

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
        warn("Failed to find symbol '" #name "'");                  \
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
        warn("Failed to find symbol '" #name "'");         \
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
    DECLARE_PROC(uint8_t*, hardware_readSerial, (int bus))
    DECLARE_PROC(void, hardware_writeSerial, (int bus, uint8_t* buf, uint32_t byteCount))
    DECLARE_PROC(void, hardware_triggerInterrupt, (int interrupt))
    DECLARE_PROC(void, hardware_readNVRAM, (void** ptr, uint32_t* bytes))
    DECLARE_PROC(void, hardware_writeNVRAM, (const void* ptr, uint32_t bytes))
    DECLARE_PROC(void, hardware_readVRAM, (void** ptr, uint32_t* bytes))
    DECLARE_PROC(void, hardware_writeVRAM, (const void* ptr, uint32_t bytes))

    float clockPeriod;
    float clockPhase;

    string tempLibraryFolder;
    string tempLibraryFile;

    MODULE_HANDLE_TYPE handle;

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

        unlink(tempLibraryFile.c_str());
        rmdir(tempLibraryFolder.c_str());
    }

    bool load(string firmwarePath)
    {
        string librarySource;
        librarySource = firmwarePath + LIB_EXTENSION;

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
                tempLibraryFolder += string(name);

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
            warn("Could not create temporary folder for firmware");
            return false;
        }

        tempLibraryFile = tempLibraryFolder + PATH_SEPARATOR + "monome_vcvrack_firmware" + LIB_EXTENSION;

        info("Creating new temporary firmware instance at %s", tempLibraryFile.c_str());
        {
            std::ifstream src(librarySource, std::ios::binary);
            std::ofstream dst(tempLibraryFile, std::ios::binary);
            dst << src.rdbuf();
        }

#if ARCH_WIN

        SetErrorMode(SEM_NOOPENFILEERRORBOX | SEM_FAILCRITICALERRORS);
        handle = LoadLibrary(tempLibraryFile.c_str());
        SetErrorMode(0);
        if (!handle)
        {
            int error = GetLastError();
            warn("Failed to load library %s: %d", tempLibraryFile.c_str(), error);
            return false;
        }

#elif ARCH_LIN || ARCH_MAC

        handle = dlopen(tempLibraryFile.c_str(), RTLD_NOW | RTLD_LOCAL);
        if (!handle)
        {
            warn("Failed to load library %s: %s", tempLibraryFile.c_str(), dlerror());
            return false;
        }

#endif

        GET_PROC_ADDRESS(handle, hardware_init);
        GET_PROC_ADDRESS(handle, hardware_step);
        GET_PROC_ADDRESS(handle, hardware_getGPIO);
        GET_PROC_ADDRESS(handle, hardware_setGPIO);
        GET_PROC_ADDRESS(handle, hardware_getDAC);
        GET_PROC_ADDRESS(handle, hardware_setADC);
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

uint8_t* FirmwareManager::readSerial(int bus)
{
    if (impl)
    {
        return impl->fw_fn_hardware_readSerial(bus);
    }
    else
    {
        return NULL;
    }
}

void FirmwareManager::writeSerial(int bus, uint8_t* buf, uint32_t byteCount)
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