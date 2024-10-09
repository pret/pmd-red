#ifndef GUARD_CODE_800DAC0_H
#define GUARD_CODE_800DAC0_H

#include "ground_sprite.h"

typedef struct unkStruct_80416E0
{
    s32 unk0;
    s32 unk4;
    s32 unk8;
    u16 x;
    u16 y;
    u16 unk10;
    u16 unk12;
    s32 unk14;
    u32 unk18;
    unkStruct_2039DB0 unk1C;
} unkStruct_80416E0;

u32 sub_800E890(unkStruct_80416E0 *);

void sub_800DAC0(u32);
void sub_800DB7C(void);

#endif // GUARD_CODE_800DAC0_H
