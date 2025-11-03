#ifndef GUARD_NUMBER_UTIL_H
#define GUARD_NUMBER_UTIL_H

/**
 * This type represents a decimal, signed fixed-point number, where the first
 * 16-bit field is the integer part and the second 16-bit field is the fraction,
 * expressed in thousandths.
 */
typedef struct FixedPoint
{
    s16 unk0;
    s16 unk2;
} FixedPoint;

/**
 * This type represents a signed 24.8 fixed-point number, where the 24 most
 * significant bits are the integer part and the 8 least significant bits are
 * the fractional part.
 */
typedef s32 s24_8; // Does not match as a struct in Blue/Sky.

#define F248_ZERO ((s24_8)0)
#define F248_ONE ((s24_8)0x100)
#define F248_MAX ((s24_8)0x7FFFFFFF)

/**
 * This type represents a signed 48.16 fixed-point number, where the 48 most
 * significant bits are the integer part and the 16 least significant bits are
 * the fractional part.
 */
typedef struct s48_16
{
    s32 hi;
    u32 lo; // some math.c funcs require this to be a u32, but other funcs check if it's negative (aka >= INT32_MAX)
} s48_16;
#define F4816_ZERO ((s48_16){})
#define F4816_ONE ((s48_16){0, 0x10000})
#define F4816_MAX ((s48_16){0x7FFFFFFF, 0xFFFFFFFF})

#define S48_16(x) ((s48_16){ ((x) * (1 >> 0x10)), (((x) * (1 << 0x10))) })

FixedPoint FixedPoint_Add(FixedPoint a, FixedPoint b);
FixedPoint FixedPoint_Subtract(FixedPoint a, FixedPoint b);
FixedPoint FixedPoint_Min(FixedPoint a, FixedPoint b);
FixedPoint FixedPoint_Max(FixedPoint a, FixedPoint b);
FixedPoint sub_8094370(FixedPoint param_1, FixedPoint param_2);
FixedPoint IntToFixedPoint(s32 a);
FixedPoint FixedPoint_SetFromS48_16(s48_16* param_1);
FixedPoint FixedPoint_Div(FixedPoint a, FixedPoint b);
s32 FixedPointToInt(FixedPoint a); // Always rounded up

#include "data_serializer.h"
void ReadBellyBits(DataSerializer *r0, FixedPoint *dst);
void WriteBellyBits(DataSerializer *r0, FixedPoint *src);

// Sometimes it's used directly as opposed to calling IntToFixedPoint
#define IntToFixedPointMacro(x) ((FixedPoint){x, 0})

#define IntToF248(x) (((x) << 8))
#define FloatToF248(x) ((int)(x * 0x100))
#define F248ToInt(x) ((s24_8)(x / 256))

#endif
