#ifndef GUARD_DUNGEON_MENU_TEAM_H
#define GUARD_DUNGEON_MENU_TEAM_H

#include "structs/dungeon_entity.h"
#include "structs/str_status_text.h"

bool8 ShowDungeonTeamMenu(Entity *a0);
void ShowDungeonTacticsMenu(ActionContainer *a0);
void ShowDungeonSummaryOrIQMenu(ActionContainer *a0, bool8 a1);
void ShowStatusDescriptionMenuArrow(void);
void ShowStatusesDescriptionMenu(s32 count, STATUSTEXTS(statuses));
#define WHICH_MENU_MOVES 1
#define WHICH_MENU_ITEMS 2
Entity *ShowDungeonToWhichMonMenu(s32 *teamId, s32 caseId);

extern s32 gTeamMenuChosenId;

#endif // GUARD_DUNGEON_MENU_TEAM_H
