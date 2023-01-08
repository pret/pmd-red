#ifndef GUARD_DUNGEON_MAP_ACCESS_H
#define GUARD_DUNGEON_MAP_ACCESS_H

#include "map.h"

struct unkStruct_202F190
{
    struct Tile* unk0[6];
};

struct Tile* GetTile(s32 x, s32 y);
struct Tile* GetTileSafe(s32 x, s32 y);

#endif
