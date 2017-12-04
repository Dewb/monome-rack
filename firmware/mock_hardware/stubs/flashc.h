void *flashc_memset8(void *dst, uint8_t src, size_t nbytes, bool erase);
void *flashc_memset16(void *dst, uint16_t src, size_t nbytes, bool erase);
void *flashc_memset32(void *dst, uint32_t src, size_t nbytes, bool erase);
void *flashc_memset64(void *dst, uint64_t src, size_t nbytes, bool erase);
void *flashc_memcpy(void* dst, const void* src, size_t nbytes, bool erase);
