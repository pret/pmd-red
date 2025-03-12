#ifndef GUARD_DUNGEON_MENU_MOVES_H
#define GUARD_DUNGEON_MENU_MOVES_H

#include "structs/dungeon_entity.h"
#include "structs/menu.h"
#include "structs/str_status_text.h"

void ShowMovesFromTeamMenu(ActionContainer *a0);
bool8 ShowDungeonMovesMenu(Entity * entity, bool8 addLinkOptions, bool8 addUseMove, s32 a3, s32 a4);
void ActionShowMoveInfo(ActionContainer *a0);
void ShowStatusDescriptionMenu(const struct StatusText *status, MenuInputStructSub *menuSub);
void ActionSetOrUnsetMove(ActionContainer *a0, bool8 flagToSet);
void ActionToggleMoveUsableForAi(ActionContainer *a0);
void ActionLinkMoves(ActionContainer *a0);
void ActionDelinkMoves(ActionContainer *a0, bool8 showMsg);
bool8 sub_8063E70(Entity *entity, Move *moves, bool8 showYesNoBox, bool8 allowBPress);

#endif
