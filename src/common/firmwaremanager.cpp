#include "firmwaremanager.hpp"
#include "util.hpp"

#include <cstdio>
#include <fstream>
#include <iostream>

void warn(const char* format, ...)
{
    va_list args;
    va_start(args, format);
    fprintf(stderr, "[warning] ");
    vfprintf(stderr, format, args);
    fprintf(stderr, "\n");
    fflush(stderr);
    va_end(args);
}

#if ARCH_LIN
#define LIB_EXTENSION ".so"
#elif ARCH_WIN
#define LIB_EXTENSION ".dll"
#elif ARCH_MAC
#define LIB_EXTENSION ".dylib"
#endif

#if ARCH_WIN

#include <direct.h>
#include <windows.h>

#define GET_PROC_ADDRESS(libname, handle, name)                     \
    fw_fn_##name = (fw_fn_##name##_t)GetProcAddress(handle, #name); \
    if (!fw_fn_##name)                                              \
    {                                                               \
        warn("Failed to read symbol '" #name "' in %s", libname);   \
        return false;                                               \
    }

#elif ARCH_LIN || ARCH_MAC

#include <dlfcn.h>

#define GET_PROC_ADDRESS(libname, handle, name)                   \
    fw_fn_##name = (fw_fn_##name##_t)dlsym(handle, #name);        \
    if (!fw_fn_##name)                                            \
    {                                                             \
        warn("Failed to read symbol '" #name "' in %s", libname); \
        return false;                                             \
    }

#endif

#define DECLARE_PROC(returntype, name, argslist)    \
    typedef returntype(*fw_fn_##name##_t) argslist; \
    fw_fn_##name##_t fw_fn_##name;

struct FirmwareManagerImpl
{
    DECLARE_PROC(void, hardware_init, ())
    DECLARE_PROC(void, hardware_step, ())
    DECLARE_PROC(uint8_t, hardware_getGPIO, (uint32_t pin))
    DECLARE_PROC(void, hardware_setGPIO, (uint32_t pin, uint8_t value))
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

    FirmwareManagerImpl()
    {
        clockPhase = 0.0;
        clockPeriod = 0.001;
    }

    bool load(string firmwarePath)
    {
        string librarySource;
        librarySource = firmwarePath + LIB_EXTENSION;
        char libraryFilename[] = "module-firmwareXXXXXX";
        mkstemp(libraryFilename);
        warn("Creating new temporary firmware instance at %s", libraryFilename);

        {
            std::ifstream src(librarySource, std::ios::binary);
            std::ofstream dst(libraryFilename, std::ios::binary);
            dst << src.rdbuf();
        }

#if ARCH_WIN

        SetErrorMode(SEM_NOOPENFILEERRORBOX | SEM_FAILCRITICALERRORS);
        HINSTANCE handle = LoadLibrary(libraryFilename);
        SetErrorMode(0);
        if (!handle)
        {
            int error = GetLastError();
            warn("Failed to load library %s: %d", libraryFilename, error);
            return false;
        }

#elif ARCH_LIN || ARCH_MAC

        void* handle = dlopen(libraryFilename, RTLD_NOW | RTLD_LOCAL);
        if (!handle)
        {
            warn("Failed to load library %s: %s", libraryFilename, dlerror());
            return false;
        }

#endif

        GET_PROC_ADDRESS(libraryFilename, handle, hardware_init);
        GET_PROC_ADDRESS(libraryFilename, handle, hardware_step);
        GET_PROC_ADDRESS(libraryFilename, handle, hardware_getGPIO);
        GET_PROC_ADDRESS(libraryFilename, handle, hardware_setGPIO);
        GET_PROC_ADDRESS(libraryFilename, handle, hardware_getDAC);
        GET_PROC_ADDRESS(libraryFilename, handle, hardware_setADC);
        GET_PROC_ADDRESS(libraryFilename, handle, hardware_readSerial);
        GET_PROC_ADDRESS(libraryFilename, handle, hardware_writeSerial);
        GET_PROC_ADDRESS(libraryFilename, handle, hardware_triggerInterrupt);
        GET_PROC_ADDRESS(libraryFilename, handle, hardware_readNVRAM);
        GET_PROC_ADDRESS(libraryFilename, handle, hardware_writeNVRAM);
        GET_PROC_ADDRESS(libraryFilename, handle, hardware_readVRAM);
        GET_PROC_ADDRESS(libraryFilename, handle, hardware_writeVRAM);

        return true;
    }
};

FirmwareManager::FirmwareManager()
{
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

uint8_t FirmwareManager::getGPIO(uint32_t pin) const
{
    if (impl)
    {
        return impl->fw_fn_hardware_getGPIO(pin);
    }
    else
    {
        return 0;
    }
}

void FirmwareManager::setGPIO(uint32_t pin, uint8_t value)
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