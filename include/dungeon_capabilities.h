#ifndef GUARD_DUNGEON_CAPABILITIES_H
#define GUARD_DUNGEON_CAPABILITIES_H

#include "dungeon_entity.h"

bool8 CannotMove(struct Entity *pokemon, bool8 checkBlinker);
bool8 sub_8070BC0(struct Entity* entity);
bool8 CannotUseItems(struct Entity *pokemon);
bool8 HasStatusThatPreventsActing(struct Entity *pokemon);
bool8 CannotAttack(struct Entity *pokemon, bool8 skipSleep);
bool8 CanMoveInDirection(struct Entity *pokemon, u32 direction);

#endif
