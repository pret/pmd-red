#ifndef GUARD_DUNGEON_CAPABILITIES_H
#define GUARD_DUNGEON_CAPABILITIES_H

#include "structs/dungeon_entity.h"

bool8 CannotMove(Entity *pokemon, bool8 checkBlinker);
bool8 sub_8070BC0(Entity* entity);
bool8 CannotUseItems(Entity *pokemon);
bool8 HasStatusThatPreventsActing(Entity *pokemon);
bool8 CannotAttack(Entity *pokemon, bool8 skipSleep);
bool8 CanMoveInDirection(Entity *pokemon, u32 direction);

#endif
