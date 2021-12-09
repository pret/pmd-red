#ifndef GUARD_DUNGEON_AI_ITEMS_H
#define GUARD_DUNGEON_AI_ITEMS_H

#include "dungeon_entity.h"

// 0x73658
void DecideUseItem(struct DungeonEntity *pokemon);
// 0x739DC
void FindStraightThrowableTargets(struct DungeonEntity* pokemon, s32 thrownAIFlag, struct ItemSlot* item, bool8 ignoreRollChance);

#endif
