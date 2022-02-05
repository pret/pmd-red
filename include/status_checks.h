#ifndef GUARD_STATUS_CHECKS_H
#define GUARD_STATUS_CHECKS_H

#include "dungeon_entity.h"

extern const s16 gConfusedAttackChance;

// 0x7001C
bool8 HasStatusAffectingActions(struct DungeonEntity *pokemon);

#endif
