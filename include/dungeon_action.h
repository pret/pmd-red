#ifndef GUARD_DUNGEON_ACTION_H
#define GUARD_DUNGEON_ACTION_H

#include "structs/dungeon_entity.h"
#include "structs/str_items.h"

// size: 0x4
typedef struct SubMenuAction
{
    u16 actionId;
    u8 unk2;
    bool8 canBeChosen;
} SubMenuAction;

void SetLeaderActionToNothing(bool8 clearActionFields);
void SetLeaderActionFields(u16 action);
void ClearMonsterActionFields(ActionContainer *actionPointer);
void SetMonsterActionFields(ActionContainer *actionPointer, u16 action);
void SetActionPassTurnOrWalk(ActionContainer *actionPointer, s16 species);
Item * sub_8044CC8(Entity *param_1, ActionParameter *param_2, UNUSED s32 a3);
bool8 sub_8044D40(ActionContainer *param_1,s32 index);
Item *sub_8044D90(Entity *entity, s32 index, s32 unused);
Entity *sub_8044DA4(Entity *entity, s32 index);
u16 sub_8044DC8(Item *param_1);
void sub_8044DF0(Entity *entity, s32 index, u32 unused);
void sub_8044E24(Entity *entity,int index,u32 unused);
const u8 *GetDungeonSubMenuItemString(s32 param_1);
bool8 CanSubMenuItemBeChosen(s32 itemId);
void AddActionToDungeonSubMenu(u16 actionId, u8 param_2);
s32 ActionToDungeonSubMenuId(u16 actionId);
void SetActionUnusableInDungeonSubMenu(u16 actionId);
bool8 IsNotAttacking(Entity *param_1, bool8 param_2);
void sub_8045064(void);

extern SubMenuAction gDungeonSubMenu[10];
extern s32 gDungeonSubMenuItemsCount;

#endif
