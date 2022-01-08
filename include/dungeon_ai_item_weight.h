#ifndef GUARD_DUNGEON_AI_ITEM_WEIGHT_H
#define GUARD_DUNGEON_AI_ITEM_WEIGHT_H

#include "dungeon_entity.h"

// 0x48F28
u32 EvaluateItem(struct DungeonEntity *targetPokemon, struct ItemSlot *item, u32 itemTargetFlags);
// 0x494EC
bool8 CanTargetAdjacentPokemon(struct DungeonEntity *pokemon);

#endif
