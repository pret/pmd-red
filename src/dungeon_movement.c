#include "global.h"
#include "dungeon_movement.h"
#include "map.h"
#include "pokemon.h"

extern u8 gWalkableTileToCrossableTerrain[8];

u8 GetCrossableTerrain(s16 species)
{
    u8 walkableTiles = GetWalkableTiles(species);
    if (walkableTiles >= NUM_CROSSABLE_TERRAIN)
    {
        // Pokémon that can cross water or lava have a walkable tile value of 4 (WALKABLE_TILE_LAVA) or 5 (WALKABLE_TILE_WATER), respectively.
        // Indices 4 and 5 in this array are assigned either CROSSABLE_TERRAIN_REGULAR or CROSSABLE_TERRAIN_LIQUID
        // depending on whether the dungeon's liquid is water or lava.
        // For example, a lava dungeon like Mt. Blaze would have these values:
        //   gWalkableTileToCrossableTerrain[WALKABLE_TILE_LAVA]: CROSSABLE_TERRAIN_LIQUID
        //   gWalkableTileToCrossableTerrain[WALKABLE_TILE_WATER]: CROSSABLE_TERRAIN_REGULAR
        // This means a Fire-type can cross the dungeon's liquid, while a Water-type cannot.
        return gWalkableTileToCrossableTerrain[walkableTiles];
    }
    else
    {
        return walkableTiles;
    }
}
