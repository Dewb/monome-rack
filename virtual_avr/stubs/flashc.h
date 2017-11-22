volatile void *flashc_memset8(volatile void *dst, uint8_t src, size_t nbytes, bool erase);
volatile void *flashc_memset32(volatile void *dst, uint32_t src, size_t nbytes, bool erase);
volatile void *flashc_memcpy(volatile void* dst, const void* src, size_t nbytes, bool erase);
