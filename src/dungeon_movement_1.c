#include "global.h"
#include "dungeon_movement_1.h"

#include "constants/item.h"
#include "constants/status.h"
#include "dungeon_items.h"
#include "dungeon_movement.h"
#include "map.h"

bool8 CanCrossWalls(struct DungeonEntity *pokemon)
{
    struct DungeonEntityData *pokemonData = pokemon->entityData;
    struct DungeonEntityData *pokemonData2 = pokemonData;
    if (pokemonData2->transformStatus == TRANSFORM_STATUS_MOBILE)
    {
        return TRUE;
    }
    if (HasItem(pokemon, ITEM_ID_MOBILE_SCARF))
    {
        return TRUE;
    }
    if (GetCrossableTerrain(pokemonData2->entityID) == CROSSABLE_TERRAIN_WALL)
    {
        return TRUE;
    }
    return FALSE;
}
