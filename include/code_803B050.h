#ifndef GUARD_CODE_803B050_H
#define GUARD_CODE_803B050_H

#include "structs/str_802C39C.h"

// size: 0x8
typedef struct unkStruct_80E9920
{
    /* 0x0 */ s16 unkA;
    /* 0x2 */ s16 unkB;
    /* 0x4 */ u8 *text;
} unkStruct_80E9920;

// size: 0xC
typedef struct unkStruct_80E9F8C
{
    /* 0x0 */ s16 unkA;
    /* 0x2 */ s16 unkB;
    /* 0x4 */ u8 *text1;
    /* 0x8 */ u8 *text2;
} unkStruct_80E9F8C;

void CreateRescueDescription(unkStruct_802C39C *);
void CreateRescueTitle(unkStruct_802C39C *);

void sub_803B6B0(s32 x, s32 y, u8 index, u32);

// code_803B050.s
extern unkStruct_803B344 *sub_803B344(u8);
extern void sub_803B35C(WonderMail *, unkStruct_802C39C *);

#endif // GUARD_CODE_803B050_H