#ifndef GUARD_CODE_8023144_H
#define GUARD_CODE_8023144_H

#include "structs/menu.h"
#include "structs/str_text.h"

// size: 0x3FC
typedef struct unkStruct_3001B5C
{
    u8 unk0;
    u32 unk4;
    s32 unk8;
    s16 unkC[2];
    u32 unk10;
    u8 fill14[0x354 - 0x14];
    u8 unk354;
    u8 fill355[0x35C - 0x355];
    /* 0x35C */ MenuInputStruct input;
    u32 unk390;
    UnkTextStruct2 *unk394;
    UnkTextStruct2 unk398[4];
    u8 unk3F8[4];
} unkStruct_3001B5C;

bool8 sub_8023144(s32, s32 index, UnkTextStruct2_sub *sub, u32);
u32 sub_8023278(bool8);
s16 sub_802331C(void);
void sub_8023354(bool8 cursorSprite);
void sub_80233A0(void);

#endif // GUARD_CODE_8023144_H