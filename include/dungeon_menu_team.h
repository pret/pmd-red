#ifndef GUARD_DUNGEON_MENU_TEAM_H
#define GUARD_DUNGEON_MENU_TEAM_H

#include "structs/dungeon_entity.h"
#include "structs/subStruct_203B240.h"

bool8 ShowDungeonTeamMenu(Entity *a0);
void ShowDungeonTacticsMenu(ActionContainer *a0);
void ShowDungeonSummaryOrIQMenu(ActionContainer *a0, bool8 a1);
void sub_8062500(void);
void sub_80625A4(s32 count, struct subStruct_203B240 **strings);
#define WHICH_MENU_MOVES 1
#define WHICH_MENU_ITEMS 2
Entity *ShowDungeonToWhichMonMenu(s32 *teamId, s32 caseId);

#endif
