#ifndef GUARD_MAP_H
#define GUARD_MAP_H

#include "structs/dungeon_entity.h"
#include "structs/str_position.h"

#define MAX_ROOM_COUNT 32 // Empirical max, not sure if the code supports any more.
#define ROOM_0xFE 0xFE // Anchor?
#define CORRIDOR_ROOM 0xFF

enum TerrainType
{
    // These 3 seem to indicate the 'main' type of the terrain. See helper functions for how they're set.
    TERRAIN_TYPE_WALL = 0, // x0 When neither TERRAIN_TYPE_NORMAL nor TERRAIN_TYPE_SECONDARY are set
    TERRAIN_TYPE_NORMAL = 1 << 0, // x1
    TERRAIN_TYPE_SECONDARY = 1 << 1, // Water or lava depending on the dungeon. x2
    // Rest seems to be flags.
    TERRAIN_TYPE_CORNER_CUTTABLE = 1 << 2, // x4 This tile can be corner-cut when walking. Seemingly only used during dungeon generation.
    TERRAIN_TYPE_NATURAL_JUNCTION = 1 << 3, // x8
    TERRAIN_TYPE_IMPASSABLE_WALL = 1 << 4, // x10
    TERRAIN_TYPE_SHOP = 1 << 5, // x20
    TERRAIN_TYPE_IN_MONSTER_HOUSE = 1 << 6, // x40
    TERRAIN_TYPE_UNK_7 = 1 << 7, // x80
    TERRAIN_TYPE_UNBREAKABLE = 1 << 8, // x100 // Cannot be broken by Absolute Mover. Set naturally on key doors.
    TERRAIN_TYPE_STAIRS = 1 << 9, // x200
    TERRAIN_TYPE_UNK_x400 = 1 << 10,
    TERRAIN_TYPE_UNK_x800 = 1 << 11,
    TERRAIN_TYPE_UNK_x1000 = 1 << 12,
    TERRAIN_TYPE_UNREACHABLE_FROM_STAIRS = 1 << 15, // 0x8000
};

enum CrossableTerrain
{
    CROSSABLE_TERRAIN_REGULAR,
    CROSSABLE_TERRAIN_LIQUID,
    CROSSABLE_TERRAIN_CREVICE,
    CROSSABLE_TERRAIN_WALL,
    NUM_CROSSABLE_TERRAIN
};

enum SpawnFlags
{
    SPAWN_FLAG_STAIRS = 1 << 0, // x1 - This tile has the stairs.
    SPAWN_FLAG_ITEM = 1 << 1, // x2 - This tile has an item on it.
    SPAWN_FLAG_TRAP = 1 << 2, // x4 - This tile has a trap on it.
    SPAWN_FLAG_MONSTER = 1 << 3, // x8 - This tile has a monster on it.
    SPAWN_FLAG_SPECIAL_TILE = 1 << 4, // x10 - This is a special tile, such as for Kecleon Shops, items, and traps.
    SPAWN_FLAG_UNK5 = 1 << 5, // 0x20 - Not fully understood field relating to Secondary Structures. Set to true for all tiles in secondary structure rooms except for Cross or Dot rooms.
    SPAWN_FLAG_UNK6 = 1 << 6, // 0x40 - Not fully understood field. In the dungeon algorithm, it is set to true on a Warp tile.
    SPAWN_FLAG_UNK7 = 1 << 7, // 0x80 - Not fully understood field. In the dungeon algorithm, it is set to true for all tiles in a Divider secondary structure room.
};

// size: 0x18
typedef struct Tile
{
    // Uses the TerrainType bit flags.
    /* 0x0 */ u16 terrainType;
    u8 fill2[0x4 - 0x2];
    u16 spawnOrVisibilityFlags; // Tracks the kinds of entities which should be spawned on this tile. See: SpawnFlags
    u16 unk6;
    u8 unk8;
    /* 0x9 */ u8 room;
    // Bitwise flags for whether Pokémon can move to an adjacent tile. Bits correspond to directions in direction.h.
    // Different sets of flags are used for Pokémon that can cross special terrain, corresponding to the CrossableTerrain enum.
    /* 0xA */ u8 walkableNeighborFlags[NUM_CROSSABLE_TERRAIN];
    u8 unkE;
    /* 0x10 */ Entity *monster; // Pokémon on the tile.
    /* 0x14 */ Entity *object; // Item or trap on the tile.
} Tile;

// size: 0x1C
typedef struct RoomData
{
    u8 unk0;
    u8 unk1;
    // All coordinates are inclusive.
    // These are not aligned properly to use the DungeonPos struct.
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

// Helper functions for main terrain types.
static inline void SetTerrainType(Tile *tile, u32 terrainType)
{
    tile->terrainType &= ~(TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);
    tile->terrainType |= terrainType;
}

static inline void SetTerrainNormal(Tile *tile)
{
    SetTerrainType(tile, TERRAIN_TYPE_NORMAL);
}

static inline void SetTerrainSecondary(Tile *tile)
{
    SetTerrainType(tile, TERRAIN_TYPE_SECONDARY);
}

static inline void SetTerrainWall(Tile *tile)
{
    SetTerrainType(tile, TERRAIN_TYPE_WALL);
}

static inline u32 GetTerrainType(const Tile *tile)
{
    return tile->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);
}


#endif // GUARD_MAP_H
