#ifndef GUARD_DUNGEON_MONSTER_HOUSE_H
#define GUARD_DUNGEON_MONSTER_HOUSE_H

#include "structs/dungeon_entity.h"

void TryWakeSleepingWildPokemon(void);
void TriggerMonsterHouse_Async(Entity *entity, bool8 forcedMonsterHouse);

#endif // GUARD_DUNGEON_MONSTER_HOUSE_H
