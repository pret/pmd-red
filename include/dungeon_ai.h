#ifndef GUARD_DUNGEON_AI_H
#define GUARD_DUNGEON_AI_H

#include "dungeon_entity.h"

// 0x71494
bool8 ShouldAvoidEnemies(struct DungeonEntity *pokemon);
// 0x71518
bool8 ShouldAvoidEnemiesAndShowEffect(struct DungeonEntity *pokemon, bool8 showRunAwayEffect);

#endif
