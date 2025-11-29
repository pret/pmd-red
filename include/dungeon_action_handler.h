#ifndef GUARD_DUNGEON_ACTION_HANDLER_H
#define GUARD_DUNGEON_ACTION_HANDLER_H

#include "structs/dungeon_entity.h"

void HandlePickUpPlayerAction_Async(Entity *entity);
void HandleSetItemAction_Async(Entity *param_1, bool8 param_2);
void HandleUnsetItemAction_Async(Entity *entity, bool8 enableMessage);
void HandleGiveItemAction_Async(Entity *param_1);
void HandleTakeItemAction_Async(Entity *param_1);
void sub_8066BD4_Async(Entity *param_1);
void HandleUseItemAction(Entity *param_1);
void HandlePlaceItemAction_Async(Entity *entity);
void sub_8066E14(Entity *entity);
void sub_8066FA4(Entity *entity);
void sub_8067110(Entity *entity);
void sub_80671A0(Entity *entity);
void HandleTalkFieldAction(Entity *entity);
void sub_806752C(ActionContainer *a0);
void sub_8067768(ActionContainer *a0);
void HandleUseMovePlayerAction(Entity *entity);
void sub_8067904(Entity *entity, u16 moveId);

#endif // GUARD_DUNGEON_ACTION_HANDLER_H
