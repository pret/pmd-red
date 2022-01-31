#ifndef GUARD_MAP_H
#define GUARD_MAP_H

#include "dungeon_entity.h"
#include "position.h"

#define MAX_ROOM_COUNT 24 // Empirical max, not sure if the code supports any more.
#define CORRIDOR_ROOM_INDEX 0xFF

enum TileType
{
    TILE_TYPE_FLOOR = 1 << 0,
    TILE_TYPE_LIQUID = 1 << 1, // Water or lava depending on the dungeon.
    TILE_TYPE_UNK_2 = 1 << 2,
    TILE_TYPE_ROOM_EXIT = 1 << 3,
    TILE_TYPE_MAP_EDGE = 1 << 4,
    TILE_TYPE_SHOP = 1 << 5,
    TILE_TYPE_MONSTER_HOUSE = 1 << 6,
    TILE_TYPE_STAIRS = 1 << 9
};

enum CrossableTerrain
{
    CROSSABLE_TERRAIN_REGULAR = 0,
    CROSSABLE_TERRAIN_LIQUID = 1,
    CROSSABLE_TERRAIN_CREVICE = 2,
    CROSSABLE_TERRAIN_WALL = 3,
    NUM_CROSSABLE_TERRAIN
};

struct MapTile
{
    // Uses the TileType bit flags.
    /* 0x0 */ u16 tileType;
    u8 fill2[0x4 - 0x2];
    u16 unk4;
    u16 unk6;
    u8 unk8;
    /* 0x9 */ u8 roomIndex;
    // Bitwise flags for whether Pokémon can move to an adjacent tile. Bits correspond to directions in direction.h.
    // Different sets of flags are used for Pokémon that can cross special terrain, corresponding to Cthe rossableTerrain enum.
    /* 0xA */ u8 canMoveAdjacent[NUM_CROSSABLE_TERRAIN];
    u8 fillE[0x10 - 0xE];
    /* 0x10 */ struct DungeonEntity *pokemon; // Pokémon on the tile.
    /* 0x14 */ struct DungeonEntity *mapObject; // Item or trap on the tile.
};

struct MapRoom
{
    u8 fill0[0x2 - 0x0];
    // All coordinates are inclusive.
    // These are not aligned properly to use the Position struct.
    /* 0x2 */ s16 startX;
    /* 0x4 */ s16 startY;
    /* 0x6 */ s16 endX;
    /* 0x8 */ s16 endY;
    u8 fillA[0x1A - 0xA];
};

#endif
