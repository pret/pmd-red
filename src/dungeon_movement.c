#include "global.h"
#include "dungeon_movement.h"
#include "map.h"
#include "pokemon.h"

extern u8 gWalkableTileToCrossableTerrain[8];

u8 GetCrossableTerrain(s16 species)
{
    u8 walkableTiles = GetMovementType(species);
    if (walkableTiles >= NUM_CROSSABLE_TERRAIN)
    {
        // Pokémon that can cross water or lava have a walkable tile value of 4 (MOVEMENT_TYPE_LAVA) or 5 (MOVEMENT_TYPE_WATER), respectively.
        // Indices 4 and 5 in this array are assigned either CROSSABLE_TERRAIN_REGULAR or CROSSABLE_TERRAIN_LIQUID
        // depending on whether the dungeon's liquid is water or lava.
        // For example, a lava dungeon like Mt. Blaze would have these values:
        //   gWalkableTileToCrossableTerrain[MOVEMENT_TYPE_LAVA]: CROSSABLE_TERRAIN_LIQUID
        //   gWalkableTileToCrossableTerrain[MOVEMENT_TYPE_WATER]: CROSSABLE_TERRAIN_REGULAR
        // This means a Fire-type can cross the dungeon's liquid, while a Water-type cannot.
        return gWalkableTileToCrossableTerrain[walkableTiles];
    }
    else
    {
        return walkableTiles;
    }
}
