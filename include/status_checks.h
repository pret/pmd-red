#ifndef GUARD_STATUS_CHECKS_H
#define GUARD_STATUS_CHECKS_H

#include "structs/dungeon_entity.h"

extern const s16 gConfusedAttackChance;

bool8 HasStatusAffectingActions(Entity *pokemon);

#endif
