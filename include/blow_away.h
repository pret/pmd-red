#ifndef GUARD_BLOW_AWAY_H
#define GUARD_BLOW_AWAY_H

#include "structs/str_position.h"
#include "structs/dungeon_entity.h"

void BlowAwayTarget(Entity *pokemon, Entity *target, u32 direction);
void sub_807D068(Entity *pokemon, DungeonPos *pos);

#endif // GUARD_BLOW_AWAY_H
