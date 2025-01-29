#ifndef GUARD_CODE_800DAC0_H
#define GUARD_CODE_800DAC0_H

#include "structs/sprite_oam.h"
#include "structs/str_position.h"

typedef struct unkStruct_80416E0
{
    s32 unk0;
    s32 unk4;
    s32 dir;
    u16 x;
    u16 y;
    u16 unk10;
    u16 unk12;
    s32 unk14;
    u32 unk18;
} unkStruct_80416E0;

u32 sub_800E890(unkStruct_80416E0 *);

void sub_800DC14(s32);
bool8 sub_800E9A8(s32);
void sub_800DAC0(u32);
void sub_800DB7C(void);
void sub_800DBBC(void);
void sub_800E90C(DungeonPos *);
void sub_800E8AC(s32 a0, void *a1, void *a2, s32 a3, void *a4); // a2 could be DungeonPos

#endif // GUARD_CODE_800DAC0_H
