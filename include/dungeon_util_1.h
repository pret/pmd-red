#ifndef GUARD_DUNGEON_UTIL_1_H
#define GUARD_DUNGEON_UTIL_1_H

#include "structs/dungeon_entity.h"

Entity *xxx_call_GetLeader(void);
Entity *GetPartnerEntity(void);
void sub_80854D4(void);
Entity *GetEntityFromClientType(u8 entityType);
void sub_80856C8(Entity * pokemon, s32 x, s32 y);
void sub_80856E0(Entity * pokemon, s32 direction);
void sub_8085764(void);
void sub_8085860(s32 x, s32 y);
void sub_8085890(s32 x, s32 y);
void ShiftCameraToPosition(Position32 *posStruct, s32 cameraSteps);
void SetFacingDirection(Entity *pokemon, s32 direction);
void sub_8085930(s32 direction);
void sub_80859F0(s32 direction);
bool8 IsMovingClient(Entity *entity);
void sub_8085B0C(Entity *pokemon);

#endif
