#include <stdio.h>
#include <string.h>

#ifdef FIRMWARE_DEBUG_OUTPUT
static void print_dbg(const char* str) { fprintf(stderr, "%s", str); }
static void print_dbg_char(int c) { fprintf(stderr, "%d", c); }
static void print_dbg_ulong(unsigned long n) { fprintf(stderr, "%ld", n); }
static void print_dbg_char_hex(unsigned char n) { fprintf(stderr, "%x", n); }
static void print_dbg_short_hex(unsigned short n) { fprintf(stderr, "%d", n); }
static void print_dbg_hex(unsigned long n) { fprintf(stderr, "%lx", n); }
#else
static void print_dbg(const char* str) { }
static void print_dbg_char(int c) { }
static void print_dbg_ulong(unsigned long n) { }
static void print_dbg_char_hex(unsigned char n) { }
static void print_dbg_short_hex(unsigned short n) { }
static void print_dbg_hex(unsigned long n) { }
#endif