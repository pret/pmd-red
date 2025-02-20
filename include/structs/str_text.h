#ifndef GUARD_STR_TEXT_H
#define GUARD_STR_TEXT_H

// size: 0x48
typedef struct UnkTextStruct1
{
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14;
    u32 *unk18;
    u32 *unk1C;
    s32 unk20;
    s32 unk24;
    u32 *unk28; // Somewhere in VRAM
    s32 unk2C;
    u32 *unk30; // Somewhere in VRAM?
    u32 *unk34;
    s32 unk38;
    u32 *unk3C;
    u32 *unk40;
    u8 unk44;
    bool8 unk45;
    u8 unk46;
} UnkTextStruct1;

typedef struct UnkTextStruct2_sub2
{
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
} UnkTextStruct2_sub2;

#include "structs/str_position.h"

// size: 0x18
typedef struct UnkTextStruct2
{
    u8 unk0;
    u8 fill1[0x4 - 0x1];
    s32 unk4;
    DungeonPos pos;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12;
    const UnkTextStruct2_sub2 *unk14; // Pointer to 4 bytes which may be x-coord related. Could be window's header?
} UnkTextStruct2;

typedef struct UnkTextStruct3 {
    UnkTextStruct2 a0[4];
    // Something ugly, so that sub_805FD74 could match weird compiler memcpy/stack initialization
    #ifndef NONMATCHING
    u8 fakeMatch[0];
    #endif // NONMATCHING
} UnkTextStruct3;

#endif // GUARD_STR_TEXT_H
