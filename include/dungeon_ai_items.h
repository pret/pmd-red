#ifndef GUARD_DUNGEON_AI_ITEMS_H
#define GUARD_DUNGEON_AI_ITEMS_H

#include "structs/dungeon_entity.h"
#include "structs/str_position.h"

void AIDecideUseItem(Entity *pokemon);
void GetPossibleAIThrownItemDirections(Entity *pokemon, s32 thrownAIFlag, Item *item, bool8 ignoreRollChance);
void GetPossibleAIArcItemTargets(Entity *pokemon, Item *item, DungeonPos potentialTargets[], bool8 ignoreRollChance);
void TargetThrownItem(Entity *pokemon, Entity *targetPokemon, Item *item, s32 targetingFlags, bool8 ignoreRollChance);

#endif
