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
    /* 0x0 */ u32 mode; // Corresponds to the enum: MakuhitaDojoMode
    /* 0x4 */ bool32 isAsleep;
    /* 0x8 */ s32 state;
    /* 0xC */ s32 fallbackState;
    s16 unk10;
    /* 0x14 */ s32 menuAction;
    MenuItem unk18[4];
    u8 fill38[0x58 - 0x38];
    /* 0x58 */ OpenedFile *faceFile;
    /* 0x5C */ u8 *faceData;
    u16 unk60;
    u16 unk62;
    u8 unk64;
    u8 unk65;
    u8 unk66;
    u8 unk67;
    OpenedFile** unk68;
    UnkTextStruct2 unk6C[4];
};

// size: 0xD0
struct unkStruct_203B31C
{
    s16 unk0[NUM_DUNGEON_MAZE];
    /* 0x30 */ MenuInputStruct input;
    u32 unk64;
    UnkTextStruct2 *unk68;
    UnkTextStruct2 unk6C[4];
    u8 unkCC[4];
};

// mode corresponds to the enum: MakuhitaDojoMode
u32 MakuhitaDojo_New(u32 mode);
void MakuhitaDojo_Delete(void);

u32 sub_802FE58(void);
s16 sub_802FED0(void);
bool8 sub_80302E8(s32, UnkTextStruct2_sub *, u32);
u32 sub_80303AC(bool8);
s16 sub_8030418(void);
void sub_8030480(void);

enum MakuhitaDojoMode
{
    MAKUHITA_DOJO_MODE_UNK0_AWAKE = 0,
    MAKUHITA_DOJO_MODE_UNK1_AWAKE = 1,
    MAKUHITA_DOJO_MODE_UNK2_AWAKE = 2,
    MAKUHITA_DOJO_MODE_UNK3_AWAKE = 3,
    MAKUHITA_DOJO_MODE_UNK4_ASLEEP = 4,
    MAKUHITA_DOJO_MODE_UNK5_ASLEEP = 5,
    MAKUHITA_DOJO_MODE_UNK6_ASLEEP = 6,
    MAKUHITA_DOJO_MODE_UNK7_ASLEEP = 7,
};

#endif // GUARD_MAKUHITA_DOJO_H