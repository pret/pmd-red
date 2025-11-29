#ifndef GUARD_DUNGEON_TURN_EFFECTS_H
#define GUARD_DUNGEON_TURN_EFFECTS_H

#include "structs/dungeon_entity.h"

void DoEndOfTurnEffects_Async(Entity *entity);
void TickStatusAndHealthRegen(Entity *entity);

#endif
