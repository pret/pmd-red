#ifndef GUARD_DUNGEON_ITEM_ACTION_H
#define GUARD_DUNGEON_ITEM_ACTION_H

#include "structs/str_items.h"
#include "structs/dungeon_entity.h"

void sub_80479B8(bool8 param_1, bool8 param_2, u8 param_3, Entity *pokemon, Entity *target, Item *item);
bool8 sub_8048950(Entity *param_1,Item *item);
bool8 sub_8048A68(Entity *param_1,Item *item);
bool8 HandleLinkBoxAction(Entity *entity, Item *item);
bool8 sub_8048D50(Entity *pokemon, Item *item);

#endif // GUARD_DUNGEON_ITEM_ACTION_H
