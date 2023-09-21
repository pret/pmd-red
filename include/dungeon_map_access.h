#ifndef GUARD_DUNGEON_MAP_ACCESS_H
#define GUARD_DUNGEON_MAP_ACCESS_H

#include "structs/map.h"

typedef struct unkStruct_202F190
{
    Tile *unk0[6];
} unkStruct_202F190;

Tile *GetTile(s32 x, s32 y);
Tile *GetTileSafe(s32 x, s32 y);

#endif
