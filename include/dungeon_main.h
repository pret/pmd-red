#ifndef GUARD_DUNGEON_MAIN_H
#define GUARD_DUNGEON_MAIN_H

#include "structs/str_text.h"

void DungeonHandlePlayerInput(void);
void sub_805E804(void);
void sub_805EE30(void);
void sub_805EFB4(Entity *a0, bool8 a1);
void sub_805F02C(void);
ActionContainer *GetLeaderActionContainer(void);
u16 GetLeaderActionId(void);
bool8 sub_805FBE8(u8 *a0);
void CreateDungeonMenuSubWindow(Window *mainWindow, s32 subWindowX);

#endif
