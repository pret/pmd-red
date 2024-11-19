#ifndef GUARD_CODE_80227B8_H
#define GUARD_CODE_80227B8_H

#include "structs/dungeon_entity.h"

Entity *SpawnTrap(u8 trapID, DungeonPos *pos, u8 c);
Entity *sub_8045708(DungeonPos *pos);
void sub_80457DC(Entity* ent);

#endif // GUARD_CODE_80227B8_H
