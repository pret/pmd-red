#ifndef GUARD_CODE_800E9A8_H
#define GUARD_CODE_800E9A8_H

#include "structs/axdata.h"
#include "structs/sprite_oam.h"
#include "structs/str_position.h"
#include "structs/str_file_system.h"

struct unkStruct_203B0CC_sub
{
    // size: 0xD0
    u32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    DungeonPos unk18;
    DungeonPos unk1c;
    s32 unk20;
    s32 unk24;
    unkStruct_2039DB0 spriteMasks;
    u32 unk34;
    u32 effectID;
    s32 paletteNum;
    u8 fill40[0x4C - 0x40];
    u32 unk4C;
    s32 unk50;
    u8 unk54;
    u8 fill55[0x58 - 0x55];
    axObject unk58;
    u8 fillA4[0xB8 - 0xA4];
    OpenedFile *unkB8;
    u8 fillBC[0xCC - 0xBC];
    s16 unkCC[2]; // NOTE: might be DungeonPos
};

struct unkStruct_203B0CC
{
    // size: 0x1A18
    struct unkStruct_203B0CC_sub unk0[0x20];
    u32 unk1A00;
    /* 0x1A04 */ u32 fileSelection;
    u32 unk1A08;
    u32 unk1A0C;
    u32 unk1A10;
    u8 fill1A14[0x1A18 - 0x1A14];
};

bool8 sub_800E9A8(s32 a0);
bool8 sub_800E9E4(u32);
bool8 sub_800E9FC(u8 a0);

#endif
