#ifndef GUARD_DUNGEON_CAPABILITIES_1_H
#define GUARD_DUNGEON_CAPABILITIES_1_H

#include "dungeon_entity.h"

bool8 CannotUseItems(struct Entity *pokemon);
bool8 HasStatusThatPreventsActing(struct Entity *pokemon);
bool8 CannotAttack(struct Entity *pokemon, bool8 skipSleep);
bool8 CanMoveInDirection(struct Entity *pokemon, u32 direction);

#endif
