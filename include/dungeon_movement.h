#ifndef GUARD_DUNGEON_MOVEMENT
#define GUARD_DUNGEON_MOVEMENT

#include "structs/dungeon_entity.h"
#include "structs/map.h"

extern u8 gWalkableTileToCrossableTerrain[8];

u8 GetCrossableTerrain(s16 species);
u8 sub_807034C(s16 id, const Tile *tile);
u8 sub_80703A0(Entity *pokemon, DungeonPos *pos);
bool8 CanCrossWalls(Entity *pokemon);
bool8 sub_807049C(Entity *pokemon, DungeonPos *pos);
bool8 sub_8070564(Entity *pokemon, DungeonPos *pos);
bool8 sub_80705F0(Entity *pokemon, DungeonPos *pos);
bool8 sub_80706A4(Entity *pokemon, DungeonPos *pos);
s32 CalcSpeedStage(Entity *pokemon);

#endif
