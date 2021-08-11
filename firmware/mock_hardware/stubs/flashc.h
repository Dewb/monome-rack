// TODO: find a better way to make sure these are defined here
#define NMI 13
#define B11 43

void hardware_declareNVRAM(const void* ptr, uint32_t bytes);
void hardware_declareVRAM(const void* ptr, uint32_t bytes);

#define DECLARE_NVRAM(ptr, bytes)                                      \
    void declare_nvram_constructor(void) __attribute__((constructor)); \
    void declare_nvram_constructor(void)                               \
    {                                                                  \
        hardware_declareNVRAM(ptr, bytes);                             \
    }

#define DECLARE_VRAM(ptr, bytes)                                      \
    void declare_vram_constructor(void) __attribute__((constructor)); \
    void declare_vram_constructor(void)                               \
    {                                                                 \
        hardware_declareVRAM(ptr, bytes);                             \
    }

void* flashc_memset8(void* dst, uint8_t src, size_t nbytes, bool erase);
void* flashc_memset16(void* dst, uint16_t src, size_t nbytes, bool erase);
void* flashc_memset32(void* dst, uint32_t src, size_t nbytes, bool erase);
void* flashc_memset64(void* dst, uint64_t src, size_t nbytes, bool erase);
void* flashc_memcpy(void* dst, const void* src, size_t nbytes, bool erase);
