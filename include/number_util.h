#ifndef GUARD_NUMBER_UTIL_H
#define GUARD_NUMBER_UTIL_H

typedef struct FixedPoint
{
    s16 unk0;
    s16 unk2;
} FixedPoint;

typedef struct unkStruct_80943A8
{
    s32 s0;
    u32 s4; // sub_800A5A4 requires this to be a u32, but other funcs check if it's negative...
} unkStruct_80943A8;

FixedPoint FixedPoint_Add(FixedPoint a, FixedPoint b);
FixedPoint FixedPoint_Subtract(FixedPoint a, FixedPoint b);
FixedPoint FixedPoint_Min(FixedPoint a, FixedPoint b);
FixedPoint FixedPoint_Max(FixedPoint a, FixedPoint b);
FixedPoint sub_8094370(FixedPoint param_1, FixedPoint param_2);
FixedPoint IntToFixedPoint(s32 a);
FixedPoint FixedPoint_SetFromUnk(unkStruct_80943A8* param_1);
FixedPoint FixedPoint_Div(FixedPoint a, FixedPoint b);
s32 FixedPointToInt(FixedPoint a); // Always rounded up

#endif