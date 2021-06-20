#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include "avr32/io.h"

#ifndef _COMPILER_AVR32_H_
#define _COMPILER_AVR32_H_

#define COMPILER_PRAGMA(arg) 
#define COMPILER_PACK_SET(alignment) COMPILER_PRAGMA(pack(alignment))
#define COMPILER_PACK_RESET() COMPILER_PRAGMA(pack())
#define COMPILER_ALIGNED(a) __attribute__((__aligned__(a)))

#define COMPILER_WORD_ALIGNED __attribute__((__aligned__(4)))

typedef int8_t S8; //!< 8-bit signed integer.
typedef uint8_t U8; //!< 8-bit unsigned integer.
typedef int16_t S16; //!< 16-bit signed integer.
typedef uint16_t U16; //!< 16-bit unsigned integer.
typedef uint16_t le16_t;
typedef uint16_t be16_t;
typedef int32_t S32; //!< 32-bit signed integer.
typedef uint32_t U32; //!< 32-bit unsigned integer.
typedef uint32_t le32_t;
typedef uint32_t be32_t;
typedef signed long long int S64; //!< 64-bit signed integer.
typedef unsigned long long int U64; //!< 64-bit unsigned integer.
typedef float F32; //!< 32-bit floating-point number.
typedef double F64; //!< 64-bit floating-point number.
typedef uint32_t iram_size_t;
//! @}

/*! \name Status Types
 */
//! @{
typedef bool Status_bool_t; //!< Boolean status.
typedef U8 Status_t; //!< 8-bit-coded status.
//! @}

/*! \name Aliasing Aggregate Types
 */
//! @{

//! 16-bit union.
typedef union
{
    S16 s16;
    U16 u16;
    S8 s8[2];
    U8 u8[2];
} Union16;

//! 32-bit union.
typedef union
{
    S32 s32;
    U32 u32;
    S16 s16[2];
    U16 u16[2];
    S8 s8[4];
    U8 u8[4];
} Union32;

//! 64-bit union.
typedef union
{
    S64 s64;
    U64 u64;
    S32 s32[2];
    U32 u32[2];
    S16 s16[4];
    U16 u16[4];
    S8 s8[8];
    U8 u8[8];
} Union64;

//! Union of pointers to 64-, 32-, 16- and 8-bit unsigned integers.
typedef union
{
    S64* s64ptr;
    U64* u64ptr;
    S32* s32ptr;
    U32* u32ptr;
    S16* s16ptr;
    U16* u16ptr;
    S8* s8ptr;
    U8* u8ptr;
} UnionPtr;

//! Union of pointers to volatile 64-, 32-, 16- and 8-bit unsigned integers.
typedef union
{
    volatile S64* s64ptr;
    volatile U64* u64ptr;
    volatile S32* s32ptr;
    volatile U32* u32ptr;
    volatile S16* s16ptr;
    volatile U16* u16ptr;
    volatile S8* s8ptr;
    volatile U8* u8ptr;
} UnionVPtr;

//! Union of pointers to constant 64-, 32-, 16- and 8-bit unsigned integers.
typedef union
{
    const S64* s64ptr;
    const U64* u64ptr;
    const S32* s32ptr;
    const U32* u32ptr;
    const S16* s16ptr;
    const U16* u16ptr;
    const S8* s8ptr;
    const U8* u8ptr;
} UnionCPtr;

//! Union of pointers to constant volatile 64-, 32-, 16- and 8-bit unsigned integers.
typedef union
{
    const volatile S64* s64ptr;
    const volatile U64* u64ptr;
    const volatile S32* s32ptr;
    const volatile U32* u32ptr;
    const volatile S16* s16ptr;
    const volatile U16* u16ptr;
    const volatile S8* s8ptr;
    const volatile U8* u8ptr;
} UnionCVPtr;

//! Structure of pointers to 64-, 32-, 16- and 8-bit unsigned integers.
typedef struct
{
    S64* s64ptr;
    U64* u64ptr;
    S32* s32ptr;
    U32* u32ptr;
    S16* s16ptr;
    U16* u16ptr;
    S8* s8ptr;
    U8* u8ptr;
} StructPtr;

//! Structure of pointers to volatile 64-, 32-, 16- and 8-bit unsigned integers.
typedef struct
{
    volatile S64* s64ptr;
    volatile U64* u64ptr;
    volatile S32* s32ptr;
    volatile U32* u32ptr;
    volatile S16* s16ptr;
    volatile U16* u16ptr;
    volatile S8* s8ptr;
    volatile U8* u8ptr;
} StructVPtr;

//! Structure of pointers to constant 64-, 32-, 16- and 8-bit unsigned integers.
typedef struct
{
    const S64* s64ptr;
    const U64* u64ptr;
    const S32* s32ptr;
    const U32* u32ptr;
    const S16* s16ptr;
    const U16* u16ptr;
    const S8* s8ptr;
    const U8* u8ptr;
} StructCPtr;

//! Structure of pointers to constant volatile 64-, 32-, 16- and 8-bit unsigned integers.
typedef struct
{
    const volatile S64* s64ptr;
    const volatile U64* u64ptr;
    const volatile S32* s32ptr;
    const volatile U32* u32ptr;
    const volatile S16* s16ptr;
    const volatile U16* u16ptr;
    const volatile S8* s8ptr;
    const volatile U8* u8ptr;
} StructCVPtr;


/*! \name Usual Constants
 */
//! @{
#define DISABLE 0
#define ENABLE 1
#ifndef __cplusplus
#if !defined(__bool_true_false_are_defined)
#define false 0
#define true 1
#endif
#endif
#define PASS 0
#define FAIL 1
#define LOW 0
#define HIGH 1
//! @}


/*! \name Mathematics
 *
 * The same considerations as for clz and ctz apply here but AVR32-GCC does not
 * provide built-in functions to access the assembly instructions abs, min and
 * max and it does not produce them by itself in most cases, so two sets of
 * macros are defined here:
 *   - Abs, Min and Max to apply to constant expressions (values known at
 *     compile time);
 *   - abs, min and max to apply to non-constant expressions (values unknown at
 *     compile time).
 */
//! @{

/*! \brief Takes the absolute value of \a a.
 *
 * \param a Input value.
 *
 * \return Absolute value of \a a.
 *
 * \note More optimized if only used with values known at compile time.
 */
#define Abs(a) (((a) < 0) ? -(a) : (a))

/*! \brief Takes the minimal value of \a a and \a b.
 *
 * \param a Input value.
 * \param b Input value.
 *
 * \return Minimal value of \a a and \a b.
 *
 * \note More optimized if only used with values known at compile time.
 */
#define Min(a, b) (((a) < (b)) ? (a) : (b))

/*! \brief Takes the maximal value of \a a and \a b.
 *
 * \param a Input value.
 * \param b Input value.
 *
 * \return Maximal value of \a a and \a b.
 *
 * \note More optimized if only used with values known at compile time.
 */
#define Max(a, b) (((a) > (b)) ? (a) : (b))

#define abs(a) Abs(a)
#define min(a, b) Min(a, b)
#define max(a, b) Max(a, b)

#endif