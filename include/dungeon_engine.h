#ifndef GUARD_DUNGEON_ENGINE_H
#define GUARD_DUNGEON_ENGINE_H

#include "structs/dungeon_entity.h"

extern const s16 gSpeedTurns[NUM_SPEED_COUNTERS][25];

void RunFractionalTurn(bool8 param_1);
void sub_80444F4(Entity *pokemon);
bool8 IsFloorOver(void);
bool8 sub_8044B84(void);

#endif
