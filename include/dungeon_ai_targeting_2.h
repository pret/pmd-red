#ifndef GUARD_DUNGEON_AI_TARGETING_2_H
#define GUARD_DUNGEON_AI_TARGETING_2_H

#include "dungeon_entity.h"

u8 CanTarget(struct DungeonEntity *pokemon, struct DungeonEntity *targetPokemon, bool8 ignoreInvisible, bool8 checkPetrified);

#endif
