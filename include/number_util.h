#ifndef GUARD_NUMBER_UTIL_H
#define GUARD_NUMBER_UTIL_H

// Fixed point with an integer part and fraction part in thousandths
typedef struct FixedPoint
{
    s16 unk0;
    s16 unk2;
} FixedPoint;

// Binary 48.16 fixed point
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

#endif
