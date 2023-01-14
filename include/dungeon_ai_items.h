#ifndef GUARD_DUNGEON_AI_ITEMS_H
#define GUARD_DUNGEON_AI_ITEMS_H

#include "dungeon_entity.h"
#include "position.h"

void DecideUseItem(struct Entity *pokemon);
void FindStraightThrowableTargets(struct Entity *pokemon, s32 thrownAIFlag, struct Item *item, bool8 ignoreRollChance);
void FindRockItemTargets(struct Entity *pokemon, struct Item *item, struct Position potentialTargets[], bool8 ignoreRollChance);
void TargetThrownItem(struct Entity *pokemon, struct Entity *targetPokemon, struct Item *item, s32 targetingFlags, bool8 ignoreRollChance);

#endif
