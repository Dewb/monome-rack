#include "mock_hardware_api.h"
#include "types.h"
#include <string.h>

void* flashc_memset64(void* dst, uint64_t src, size_t nbytes, bool erase)
{
    (*(uint64_t*)dst) = src;
    return dst;
}

void* flashc_memset32(void* dst, uint32_t src, size_t nbytes, bool erase)
{
    (*(uint32_t*)dst) = src;
    return dst;
}

void* flashc_memset16(void* dst, uint16_t src, size_t nbytes, bool erase)
{
    (*(uint16_t*)dst) = src;
    return dst;
}

void* flashc_memset8(void* dst, uint8_t src, size_t nbytes, bool erase)
{
    (*(uint8_t*)dst) = src;
    return dst;
}

void* flashc_memcpy(void* dst, const void* src, size_t nbytes, bool erase)
{
    memcpy(dst, src, nbytes);
    return dst;
}