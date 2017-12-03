#include "firmwaremanager.hpp"
#include "util.hpp"

void warn(const char* format, ...);

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

#define GET_PROC_ADDRESS(libname, handle, name)                           \
    fw_fn_##name = (fw_fn_##name##_t)GetProcAddress(handle, #name);       \
    if (!fw_fn_##name)                                                    \
    {                                                                     \
        warn("Failed to read symbol '" #name "' in %s", libname.c_str()); \
        return false;                                                     \
    }

#elif ARCH_LIN || ARCH_MAC

#include <dlfcn.h>

#define GET_PROC_ADDRESS(libname, handle, name)                           \
    fw_fn_##name = (fw_fn_##name##_t)dlsym(handle, #name);                \
    if (!fw_fn_##name)                                                    \
    {                                                                     \
        warn("Failed to read symbol '" #name "' in %s", libname.c_str()); \
        return false;                                                     \
    }

#endif

struct FirmwareManagerImpl
{
    typedef void (*fw_fn_init_t)();
    typedef void (*fw_fn_step_t)();
    typedef uint8_t (*fw_fn_getGPIO_t)(uint32_t pin);
    typedef void (*fw_fn_setGPIO_t)(uint32_t pin, uint8_t value);
    typedef uint16_t (*fw_fn_getDAC_t)(int channel);
    typedef void (*fw_fn_setADC_t)(int channel, uint16_t value);
    typedef uint8_t* (*fw_fn_readSerial_t)(int bus);
    typedef void (*fw_fn_writeSerial_t)(int bus, uint8_t* buf, uint32_t byteCount);
    typedef void (*fw_fn_triggerInterrupt_t)(int interrupt);

    fw_fn_init_t fw_fn_init;
    fw_fn_step_t fw_fn_step;
    fw_fn_getGPIO_t fw_fn_getGPIO;
    fw_fn_setGPIO_t fw_fn_setGPIO;
    fw_fn_getDAC_t fw_fn_getDAC;
    fw_fn_setADC_t fw_fn_setADC;
    fw_fn_readSerial_t fw_fn_readSerial;
    fw_fn_writeSerial_t fw_fn_writeSerial;
    fw_fn_triggerInterrupt_t fw_fn_triggerInterrupt;

    float clockPeriod;
    float clockPhase;

    FirmwareManagerImpl()
    {
        clockPhase = 0.0;
        clockPeriod = 0.001;
    }

    bool load(string firmwarePath)
    {
        string libraryFilename;
        libraryFilename = firmwarePath + LIB_EXTENSION;

#if ARCH_WIN
        SetErrorMode(SEM_NOOPENFILEERRORBOX | SEM_FAILCRITICALERRORS);
        HINSTANCE handle = LoadLibrary(libraryFilename.c_str());
        SetErrorMode(0);
        if (!handle)
        {
            int error = GetLastError();
            warn("Failed to load library %s: %d", libraryFilename.c_str(), error);
            return false;
        }
#elif ARCH_LIN || ARCH_MAC
        void* handle = dlopen(libraryFilename.c_str(), RTLD_NOW);
        if (!handle)
        {
            warn("Failed to load library %s: %s", libraryFilename.c_str(), dlerror());
            return false;
        }
#endif

        GET_PROC_ADDRESS(libraryFilename, handle, init);
        GET_PROC_ADDRESS(libraryFilename, handle, step);
        GET_PROC_ADDRESS(libraryFilename, handle, getGPIO);
        GET_PROC_ADDRESS(libraryFilename, handle, setGPIO);
        GET_PROC_ADDRESS(libraryFilename, handle, getDAC);
        GET_PROC_ADDRESS(libraryFilename, handle, setADC);
        GET_PROC_ADDRESS(libraryFilename, handle, readSerial);
        GET_PROC_ADDRESS(libraryFilename, handle, writeSerial);
        GET_PROC_ADDRESS(libraryFilename, handle, triggerInterrupt);
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
        impl->fw_fn_init();
    }
}

void FirmwareManager::step()
{
    if (impl)
    {
        impl->fw_fn_step();
    }
}

uint8_t FirmwareManager::getGPIO(uint32_t pin) const
{
    if (impl)
    {
        return impl->fw_fn_getGPIO(pin);
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
        impl->fw_fn_setGPIO(pin, value);
    }
}

uint16_t FirmwareManager::getDAC(int channel)
{
    if (impl)
    {
        return impl->fw_fn_getDAC(channel);
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
        impl->fw_fn_setADC(channel, value);
    }
}

uint8_t* FirmwareManager::readSerial(int bus)
{
    if (impl)
    {
        return impl->fw_fn_readSerial(bus);
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
        impl->fw_fn_writeSerial(bus, buf, byteCount);
    }
}

void FirmwareManager::triggerInterrupt(int interrupt)
{
    if (impl)
    {
        impl->fw_fn_triggerInterrupt(interrupt);
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
            impl->fw_fn_triggerInterrupt(0);
        }
    }
}