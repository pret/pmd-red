#ifndef GUARD_EFFECT_MAIN_H
#define GUARD_EFFECT_MAIN_H

#include "structs/sprite_oam.h"
#include "structs/str_position.h"
#include "effect_data.h"

typedef struct unkStruct_80416E0
{
    s32 unk0;
    s32 unk4;
    s32 dir;
    DungeonPos pos1;
    DungeonPos pos2;
    s32 unk14;
    u32 unk18;
    unkStruct_2039DB0 spriteMasks;
} unkStruct_80416E0;

typedef struct unkStruct_800EA44
{
    s16 unk0;
    s16 unk2;
} unkStruct_800EA44;

struct UnkStruct_8040094
{
    u16 unk0;
    s16 unk2;
    DungeonPos unk4;
    DungeonPos unk8;
    s32 unkC;
    s32 unk10;
};

void sub_800DAC0(u32 fileSelection);
void sub_800DB7C(void);
void sub_800DBBC(void);
void sub_800DC14(s32 param_1);
s32 sub_800DC9C(s32 a0);
s32 sub_800E308(struct UnkStruct_8040094 *a0, DungeonPos *a1);
void sub_800E3AC(s32 a0, DungeonPos *pos, s32 a2);
s32 sub_800E448(u8 a0, DungeonPos *pos);
s32 sub_800E49C(u8 a0, DungeonPos *pos, DungeonPos posArray[4], bool8 a3, s32 a4);
s32 sub_800E52C(struct UnkStruct_8040094 *a0);
s32 sub_800E6D8(s32 a0);
s32 sub_800E700(s32 a0);
s32 sub_800E710(s32 a0_, s32 a1);
s32 sub_800E790(s32 a0_, s32 a1);
bool8 sub_800E7D0(u16 *param_1);
bool8 sub_800E838(u16 *param_1, s32 param_2);
s32 sub_800E890(unkStruct_80416E0 *param_1);
void sub_800E8AC(s32 a0, DungeonPos *a1, DungeonPos *a2, s32 a3, unkStruct_2039DB0 *a4);
bool8 sub_800E90C(DungeonPos *param_1);
void sub_800E970(void);
bool8 sub_800E9A8(s32 a0);
bool8 sub_800E9E4(u32 param_1);
bool8 sub_800E9FC(u8 a0);
u8 sub_800EA44(unkStruct_800EA44 param_1, s32 param_2);
s32 sub_800EA84(struct UnkStruct_8040094 *a0);
void sub_800EB24(s32 param_1, DungeonPos *param_2, DungeonPos *param_3, s32 r5, s32 r4);
s32 sub_800EBC8(struct UnkStruct_8040094 *a0);
u8 sub_800EC74(void);
u8 sub_800EC84(s32 param_1);
u8 sub_800EC94(s32 param_1);


#endif // GUARD_EFFECT_MAIN_H
