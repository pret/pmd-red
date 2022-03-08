#ifndef GUARD_DUNGEON_AI_TARGETING_1_H
#define GUARD_DUNGEON_AI_TARGETING_1_H

#include "dungeon_entity.h"

bool8 ShouldAvoidEnemies(struct DungeonEntity *pokemon);
bool8 ShouldAvoidEnemiesAndShowEffect(struct DungeonEntity *pokemon, bool8 showRunAwayEffect);

#endif
