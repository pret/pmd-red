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
typedef struct s24_8 {
    // It's almost certainly not an actual struct, but keep it as one until we decomp all structures that include it
    s32 raw;
} s24_8;

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

FixedPoint FixedPoint_Add(FixedPoint a, FixedPoint b);
FixedPoint FixedPoint_Subtract(FixedPoint a, FixedPoint b);
FixedPoint FixedPoint_Min(FixedPoint a, FixedPoint b);
FixedPoint FixedPoint_Max(FixedPoint a, FixedPoint b);
FixedPoint sub_8094370(FixedPoint param_1, FixedPoint param_2);
FixedPoint IntToFixedPoint(s32 a);
FixedPoint FixedPoint_SetFromUnk(s48_16* param_1);
FixedPoint FixedPoint_Div(FixedPoint a, FixedPoint b);
s32 FixedPointToInt(FixedPoint a); // Always rounded up

#define IntToF248_2(x) ((s24_8){x * 0x100})
#define FloatToF248_2(x) ((s24_8){(int)(x * 0x100)})
static inline s24_8 IntToF248(s32 x) {
    return (s24_8){x * 256};
}

static inline s24_8 FloatToF248(float x) {
    return (s24_8){(int)(x * 256)};
}

static inline s32 F248ToInt(s24_8 x) {
    return x.raw / 256;
}


#endif
