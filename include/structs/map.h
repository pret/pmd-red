#ifndef GUARD_MAP_H
#define GUARD_MAP_H

#include "structs/dungeon_entity.h"
#include "structs/str_position.h"

#define MAX_ROOM_COUNT 24 // Empirical max, not sure if the code supports any more.
#define CORRIDOR_ROOM 0xFF

enum TerrainType
{
    TERRAIN_TYPE_NORMAL = 1 << 0,
    TERRAIN_TYPE_SECONDARY = 1 << 1, // Water or lava depending on the dungeon.
    TERRAIN_TYPE_UNK_2 = 1 << 2,
    TERRAIN_TYPE_NATURAL_JUNCTION = 1 << 3,
    TERRAIN_TYPE_IMPASSABLE_WALL = 1 << 4,
    TERRAIN_TYPE_SHOP = 1 << 5,
    TERRAIN_TYPE_IN_MONSTER_HOUSE = 1 << 6,
    TERRAIN_TYPE_UNK_8 = 1 << 8,
    TERRAIN_TYPE_STAIRS = 1 << 9,
};

enum CrossableTerrain
{
    CROSSABLE_TERRAIN_REGULAR,
    CROSSABLE_TERRAIN_LIQUID,
    CROSSABLE_TERRAIN_CREVICE,
    CROSSABLE_TERRAIN_WALL,
    NUM_CROSSABLE_TERRAIN
};

// size: 0x18
typedef struct Tile
{
    // Uses the TerrainType bit flags.
    /* 0x0 */ u16 terrainType;
    u8 fill2[0x4 - 0x2];
    u16 unk4;
    u16 unk6;
    u8 unk8;
    /* 0x9 */ u8 room;
    // Bitwise flags for whether Pokémon can move to an adjacent tile. Bits correspond to directions in direction.h.
    // Different sets of flags are used for Pokémon that can cross special terrain, corresponding to the CrossableTerrain enum.
    /* 0xA */ u8 walkableNeighborFlags[NUM_CROSSABLE_TERRAIN];
    u8 fillE[0x10 - 0xE];
    /* 0x10 */ Entity *monster; // Pokémon on the tile.
    /* 0x14 */ Entity *object; // Item or trap on the tile.
} Tile;

// size: 0x1C
typedef struct RoomData
{
    u8 unk0;
    u8 unk1;
    // All coordinates are inclusive.
    // These are not aligned properly to use the Position struct.
    /* 0x2 */ s16 bottomRightCornerX;
    /* 0x4 */ s16 bottomRightCornerY;
    /* 0x6 */ s16 topLeftCornerX;
    /* 0x8 */ s16 topLeftCornerY;
    u8 fillA[0xC - 0xA];
    u32 unkC; // bottom right x
    u32 unk10; // bottom right y
    u32 unk14; // top left x
    u32 unk18; // top left y
} RoomData;

#endif // GUARD_MAP_H