#ifndef GUARD_DUNGEON_UTIL_1_H
#define GUARD_DUNGEON_UTIL_1_H

#include "dungeon_entity.h"

struct DungeonEntity *GetEntityFromClientType(u8 entityType);
void sub_80856C8(struct DungeonEntity * pokemon, s32 x, s32 y);
void sub_80856E0(struct DungeonEntity * pokemon, s32 direction);
void sub_8085764(void);
void sub_8085860(s32 x, s32 y);
void sub_8085890(s32 x, s32 y);
void ShiftCameraToPosition(struct Position32 *posStruct, s32 cameraSteps);
void SetFacingDirection(struct DungeonEntity *pokemon, s32 direction);
void sub_8085930(s32 direction);
void sub_80859F0(s32 direction);
bool8 IsMovingClient(struct DungeonEntity *entity);
void sub_8085B0C(struct DungeonEntity *pokemon);

#endif
