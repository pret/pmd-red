#ifndef GUARD_DUNGEON_AI_ITEM_WEIGHT_H
#define GUARD_DUNGEON_AI_ITEM_WEIGHT_H

#include "structs/dungeon_entity.h"

u32 EvaluateItem(Entity *targetPokemon, Item *item, u32 itemTargetFlags);
bool8 CanTargetAdjacentPokemon(Entity *pokemon);

#endif
