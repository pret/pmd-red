#ifndef GUARD_CODE_800E9A8_H
#define GUARD_CODE_800E9A8_H

#include "structs/axdata.h"
#include "structs/sprite_oam.h"
#include "structs/str_position.h"
#include "structs/str_file_system.h"
#include "structs/str_8009A7C.h"

struct unkStruct_203B0CC_x94
{
    struct Struct_8009A7C sub;
    s32 unk14;
    s32 unk18;
    s32 fill1C;
    u8 unk20;
};

struct unkStruct_203B0CC_xC
{
    s32 unkC;
    s32 unk10;
    s32 unk14;
    DungeonPos unk18;
    DungeonPos unk1c;
    s32 unk20;
    s32 unk24;
    unkStruct_2039DB0 spriteMasks;
};

struct unkStruct_203B0CC_sub
{
    // size: 0xD0
    u32 unk0;
    s32 unk4;
    s32 unk8;
    struct unkStruct_203B0CC_xC unkC;
    u32 unk34;
    u32 effectID;
    s32 paletteNum;
    s32 unk40;
    s32 unk44;
    s32 unk48;
    u32 unk4C;
    s32 unk50;
    u8 unk54;
    u8 unk55;
    axdata unk58;
    struct unkStruct_203B0CC_x94 unk94;
    OpenedFile *unkB8;
    u8 fillBC[0xCC - 0xBC];
    s16 unkCC[2];
};

#define UNK_203B0CC_ARR_COUNT 0x20

struct unkStruct_203B0CC
{
    // size: 0x1A18
    struct unkStruct_203B0CC_sub unk0[UNK_203B0CC_ARR_COUNT];
    s32 unk1A00;
    /* 0x1A04 */ u32 fileSelection;
    s32 unk1A08;
    s32 unk1A0C;
    s32 unk1A10;
    u16 unk1A14;
};

bool8 sub_800E9A8(s32 a0);
bool8 sub_800E9E4(u32);
bool8 sub_800E9FC(u8 a0);

#endif
