#ifndef GUARD_MAKUHITA_DOJO2_H
#define GUARD_MAKUHITA_DOJO2_H

#include "constants/dungeon.h"
#include "structs/menu.h"
#include "structs/str_text.h"
#include "structs/struct_sub80095e4.h"

// size: 0xD0
typedef struct MakuhitaDojoWork2
{
    s16 unk0[NUM_DUNGEON_MAZE];
    /* 0x30 */ struct_Sub80095E4_2 s30;
} MakuhitaDojoWork2;

bool8 MakuhitaDojo_ReturnFalse(void);

bool8 sub_80302E8(s32, DungeonPos *, u32);
u32 sub_80303AC(bool8);
s16 sub_8030418(void);
void sub_8030480(void);

#endif // GUARD_MAKUHITA_DOJO2_H
