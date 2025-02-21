#ifndef GUARD_MAKUHITA_DOJO1_H
#define GUARD_MAKUHITA_DOJO1_H

#include "file_system.h"
#include "structs/menu.h"
#include "structs/str_text.h"

enum MakuhitaDojoInitMode
{
    MAKUHITA_DOJO_INIT_MODE_UNK0_AWAKE,
    MAKUHITA_DOJO_INIT_MODE_UNK1_AWAKE,
    MAKUHITA_DOJO_INIT_MODE_UNK2_AWAKE,
    MAKUHITA_DOJO_INIT_MODE_UNK3_AWAKE,
    MAKUHITA_DOJO_INIT_MODE_UNK4_ASLEEP,
    MAKUHITA_DOJO_INIT_MODE_UNK5_ASLEEP,
    MAKUHITA_DOJO_INIT_MODE_UNK6_ASLEEP,
    MAKUHITA_DOJO_INIT_MODE_UNK7_ASLEEP,
};

// size: 0xCC
typedef struct MakuhitaDojoWork1
{
    /* 0x0 */ u32 mode; // Corresponds to the enum: MakuhitaDojoInitMode
    /* 0x4 */ u32 dlgMode; // Corresponds to the enum: MakuhitaDojoMode
    /* 0x8 */ s32 state;
    /* 0xC */ s32 fallbackState;
    s16 unk10;
    /* 0x14 */ s32 menuAction;
    MenuItem unk18[4];
    u8 fill38[0x58 - 0x38];
    /* 0x58 */ struct MonPortraitMsg monPortrait;
    struct MonPortraitMsg *monPortraitPtr;
    UnkTextStruct3 unk6C;
} MakuhitaDojoWork1;

void MakuhitaDojo_Delete(void);
bool8 MakuhitaDojo_New(u32 mode);

u32 HandleMakuhitaDojoState(void);
s16 sub_802FED0(void);

#endif // GUARD_MAKUHITA_DOJO1_H
