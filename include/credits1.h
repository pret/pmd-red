#ifndef GUARD_CREDITS1_H
#define GUARD_CREDITS1_H

#include "text.h"

// size: 0x6C
typedef struct Credits1Work
{
    UnkTextStruct2 unk0[4];
    s32 unk60;
    s32 unk64;
    /* 0x68 */ s32 creditsCategoryIndex;
} Credits1Work;

// size: 0xC
typedef struct CreditsData
{
    /* 0x0 */ s16 type;
    /* 0x2 */ s16 x;
    /* 0x4 */ s16 y;
    /* 0x8 */ u8 *text;
} CreditsData;

bool8 DrawCredits(s32 creditsCategoryIndex, s32);

s32 sub_8035574(void);
void sub_803565C(void);

#endif // GUARD_CREDITS1_H