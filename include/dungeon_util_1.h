#ifndef GUARD_DUNGEON_UTIL_1_H
#define GUARD_DUNGEON_UTIL_1_H

#include "dungeon_entity.h"

bool8 IsMovingClient(struct DungeonEntity *entity);
void ShiftCameraToPosition(struct Position32 *posStruct, s32 cameraSteps);

#endif
