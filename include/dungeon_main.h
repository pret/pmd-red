#ifndef GUARD_DUNGEON_MAIN_H
#define GUARD_DUNGEON_MAIN_H

#include "structs/dungeon_entity.h"

struct UnkMenuBitsStruct {
    u8 a0_8;
    u8 a0_16;
    u8 a0_24;
    u8 a0_32;
};

void DungeonHandlePlayerInput(void);
void sub_805E804(void);
void sub_805EE30(void);
void sub_805EFB4(Entity *a0, bool8 a1);
void sub_805F02C(void);
ActionContainer *GetLeaderActionContainer(void);
u16 GetLeaderActionId(void);
bool8 DungeonGiveNameToRecruitedMon(u8 *name);

#endif // GUARD_DUNGEON_MAIN_H
