#ifndef GUARD_DUNGEON_CAPABILITIES_H
#define GUARD_DUNGEON_CAPABILITIES_H

#include "structs/dungeon_entity.h"

bool8 CheckVariousStatuses2(Entity *pokemon, bool8 checkBlinker);
bool8 sub_8070BC0(Entity* entity);
bool8 CheckVariousConditions(Entity *pokemon);
bool8 CheckVariousStatuses(Entity *pokemon);
bool8 CannotAttack(Entity *pokemon, bool8 skipSleep);
bool8 CanMoveInDirection(Entity *pokemon, u32 direction);

#endif
