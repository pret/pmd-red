#ifndef GUARD_MAKUHITA_DOJO_H
#define GUARD_MAKUHITA_DOJO_H

#include "constants/dungeon.h"
#include "file_system.h"
#include "input.h"
#include "menu.h"
#include "text.h"

// size: 0xCC
struct unkStruct_203B318
{
    u32 unk0;
    u32 unk4;
    /* 0x8 */ s32 state;
    /* 0xC */ s32 fallbackState;
    s16 unk10;
    /* 0x14 */ s32 menuAction;
    struct MenuItem unk18[4];
    u8 fill38[0x58 - 0x38];
    /* 0x58 */ struct OpenedFile *faceFile;
    /* 0x5C */ u8 *faceData;
    u16 unk60;
    u16 unk62;
    u8 unk64;
    u8 unk65;
    u8 unk66;
    u8 unk67;
    struct OpenedFile** unk68;
    struct UnkTextStruct2 unk6C[4];
};

// size: 0xD0
struct unkStruct_203B31C
{
    s16 unk0[NUM_DUNGEON_MAZE];
    /* 0x30 */ struct MenuInputStruct input;
    u32 unk64;
    struct UnkTextStruct2 *unk68;
    struct UnkTextStruct2 unk6C[4];
    u8 unkCC[4];
};

bool8 sub_80302E8(s32, struct UnkTextStruct2_sub *, u32);

#endif // GUARD_MAKUHITA_DOJO_H