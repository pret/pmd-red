#ifndef GUARD_DUNGEON_TILEMAP_H
#define GUARD_DUNGEON_TILEMAP_H

#include "structs/str_position.h"
#include "structs/dungeon_entity.h"

void sub_803F27C(bool8 a0);
bool8 sub_803F428(DungeonPos *pos);
void sub_803F4A0(Entity *a0);
void PointCameraToMonster(Entity *a0);
void UpdateCamera(u8 a0);
void sub_803F878(s32 a0, s32 a1);
s32 GetCameraXPos(void);
s32 GetCameraYPos(void);
void sub_803F9CC(void);
void HandleLuminousOrbAction(Entity *pokemon);
void sub_8040094(u8 r0);

#endif // GUARD_DUNGEON_TILEMAP_H
