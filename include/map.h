#ifndef GUARD_MAP_H
#define GUARD_MAP_H

#include "dungeon_entity.h"

#define MAX_ROOM_COUNT 24 // Empirical max, not sure if the code supports any more.


struct MapTileBitFlagStair
{
    /* 0x0 */ u8 tileFlags;
    /* 0x1 */ bool8 stairs;
};

struct MapTile
{
    // TODO: can we get rid of the union... is tileFlags a u16 only?
    union MapTileUnion
    {
        struct MapTileBitFlagStair unk0;
        u16 tileFlags_u16;
    } MapTileUnion;
    u16 unk4;
    u16 unk6;
    u8 unk8;
    /* 0x9 */ u8 roomIndex;
    // Bitwise flags for whether Pokémon can move to an adjacent tile. Bits correspond to directions in direction.h.
    // Different sets of flags are used for Pokémon that can cross special terrain.
    /* 0xA */ u8 canMoveAdjacent;
    /* 0xB */ u8 canMoveAdjacentLiquid;
    /* 0xC */ u8 canMoveAdjacentCrevice;
    /* 0xD */ u8 canMoveAdjacentWall;
    u8 fillE[0x10 - 0xE];
    /* 0x10 */ struct DungeonEntity *pokemon; // Pokémon on the tile.
    /* 0x14 */ struct DungeonEntity *mapObject; // Item or trap on the tile.
};

struct MapRoom
{
    u8 fill0[0x2 - 0x0];
    // All coordinates are inclusive.
    /* 0x2 */ s16 startX;
    /* 0x4 */ s16 startY;
    /* 0x6 */ s16 endX;
    /* 0x8 */ s16 endY;
    u8 fillA[0x1C - 0xA];
};

struct RoomExit
{
    s16 x;
    s16 y;
};

enum TileFlag
{
    TILE_TYPE_FLOOR = 1 << 0,
    TILE_TYPE_LIQUID = 1 << 2, // Water or lava depending on the dungeon.
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
};

#endif
