#ifndef GUARD_DUNGEON_AI_ITEMS_H
#define GUARD_DUNGEON_AI_ITEMS_H

#include "dungeon_entity.h"
#include "position.h"

void DecideUseItem(struct DungeonEntity *pokemon);
void FindStraightThrowableTargets(struct DungeonEntity *pokemon, s32 thrownAIFlag, struct ItemSlot *item, bool8 ignoreRollChance);
void FindRockItemTargets(struct DungeonEntity *pokemon, struct ItemSlot *item, struct Position potentialTargets[], bool8 ignoreRollChance);
void TargetThrownItem(struct DungeonEntity *pokemon, struct DungeonEntity *targetPokemon, struct ItemSlot *item, s32 targetingFlags, bool8 ignoreRollChance);

#endif
