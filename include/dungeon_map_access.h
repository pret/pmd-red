#ifndef GUARD_DUNGEON_MAP_ACCESS_H
#define GUARD_DUNGEON_MAP_ACCESS_H

#include "map.h"

struct unkStruct_202F190
{
    struct MapTile* unk0[6];
};

// 0x4954C
struct MapTile* GetMapTile_1(s32 x, s32 y);
// 0x49590
struct MapTile* GetMapTile_2(s32 x, s32 y);

#endif
