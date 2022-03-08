#ifndef GUARD_DUNGEON_AI_ITEM_WEIGHT_H
#define GUARD_DUNGEON_AI_ITEM_WEIGHT_H

#include "dungeon_entity.h"

u32 EvaluateItem(struct DungeonEntity *targetPokemon, struct ItemSlot *item, u32 itemTargetFlags);
bool8 CanTargetAdjacentPokemon(struct DungeonEntity *pokemon);

#endif
