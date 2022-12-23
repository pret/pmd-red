#ifndef GUARD_CODE_8094F88_H
#define GUARD_CODE_8094F88_H

#include "item.h"

// TODO: same as unkStruct_8095228 
struct unkStruct_203B480
{
    /* 0x0 */ u8 mailType;
    /* 0x1 */ u8 missionType;
    /* 0x4 */ struct DungeonLocation dungeon;
    /* 0x8 */ u32 unk8;
    /* 0xC */ s16 clientSpecies;
    /* 0xE */ s16 targetSpecies;
    /* 0x10 */ u32 unk10;
    /* 0x14 */ u8 playerName[0x20 - 0x14];;
    struct ItemSlot unk20;
    u32 unk24;
    u32 unk28;
    s8 unk2C;
    u8 unk2D;
    u8 padding4[0x30 - 0x2E];
};

struct unkStruct_203B484
{
    u32 unk0;
    struct PokemonStruct unk4;
};

struct unkStruct_203B48C
{
    s32 unk0;
    s32 unk4[0x20];
};

bool8 sub_80951FC(struct unkStruct_203B480 *param_1);
struct unkStruct_203B480 * sub_8095228(u8 index);
void sub_8095240(u8 index);
void sub_8095274(u32 param_1);
bool8 sub_8095298(s32 param_1);
void sub_80952C4(void);
bool8 sub_80952F0(u8 mailType, u32 param_2);
s32 sub_8095324(u8 mailType);
u32 sub_8095350(void);
s32 sub_8095374(void);
s32 sub_809539C(u8 mailType, u32 param_2);
s32 sub_80953D4(u8 param_1);


#endif
