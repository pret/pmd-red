#ifndef GUARD_DUNGEON_TURN_EFFECTS_H
#define GUARD_DUNGEON_TURN_EFFECTS_H

#include "structs/dungeon_entity.h"

void ApplyEndOfTurnEffects(Entity *entity);
void TickStatusAndHealthRegen(Entity *entity);

#endif
