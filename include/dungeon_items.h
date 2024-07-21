#ifndef GUARD_DUNGEON_ITEMS_H
#define GUARD_DUNGEON_ITEMS_H

#include "structs/dungeon_entity.h"

bool8 HasHeldItem(Entity *pokemon, u8 id);
void sub_8046CE4(Item *item, s32 param_2);
void sub_8046D20(void);

#endif
