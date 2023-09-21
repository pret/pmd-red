#ifndef GUARD_MAKUHITA_DOJO2_H
#define GUARD_MAKUHITA_DOJO2_H

#include "constants/dungeon.h"
#include "input.h"
#include "structs/str_text.h"

// size: 0xD0
typedef struct MakuhitaDojoWork2
{
    s16 unk0[NUM_DUNGEON_MAZE];
    /* 0x30 */ MenuInputStruct input;
    u32 unk64;
    UnkTextStruct2 *unk68;
    UnkTextStruct2 unk6C[4];
    u8 unkCC[4];
} MakuhitaDojoWork2;

bool8 MakuhitaDojo_ReturnFalse(void);

bool8 sub_80302E8(s32, UnkTextStruct2_sub *, u32);
u32 sub_80303AC(bool8);
s16 sub_8030418(void);
void sub_8030480(void);

#endif // GUARD_MAKUHITA_DOJO2_H