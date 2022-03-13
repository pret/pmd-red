#include "global.h"
#include "dungeon_ai_targeting.h"

#include "constants/iq_skill.h"
#include "constants/item.h"
#include "constants/status.h"
#include "dungeon_engine.h"
#include "dungeon_global_data.h"
#include "dungeon_items.h"
#include "dungeon_map_access.h"
#include "dungeon_movement.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_util.h"
#include "map.h"
#include "tile_types.h"

const u8 gDirectionBitMasks_2[] = {0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80};
const u8 gDirectionBitMasks_3[] = {0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80};

bool8 CanAttackInFront(struct DungeonEntity *pokemon, s32 direction)
{
    u8 crossableTerrain = GetCrossableTerrain(pokemon->entityData->entityID);
    struct MapTile *tile;
    if (crossableTerrain < CROSSABLE_TERRAIN_CREVICE)
    {
        crossableTerrain = CROSSABLE_TERRAIN_CREVICE;
    }
    tile = GetMapTile_1(pokemon->posWorld.x + gAdjacentTileOffsets[direction].x,
        pokemon->posWorld.y + gAdjacentTileOffsets[direction].y);
    if (!(tile->tileType & TILE_TYPE_MAP_EDGE) &&
        (tile->pokemon == NULL || GetEntityType(tile->pokemon) == ENTITY_POKEMON))
    {
        if (!IsFixedDungeon())
        {
            if (pokemon->entityData->transformStatus == TRANSFORM_STATUS_MOBILE ||
                HasItem(pokemon, ITEM_ID_MOBILE_SCARF))
            {
                crossableTerrain = CROSSABLE_TERRAIN_WALL;
            }
            else if (HasIQSkill(pokemon, IQ_SKILL_ALL_TERRAIN_HIKER))
            {
                // BUG: If the Pokémon is a Ghost type that can normally attack through walls,
                // All-Terrain Hiker/Super Mobile may make the AI think it can't attack through walls.
                crossableTerrain = CROSSABLE_TERRAIN_CREVICE;
            }
            else if (HasIQSkill(pokemon, IQ_SKILL_SUPER_MOBILE))
            {
                if ((direction & 1) != 0)
                {
                    crossableTerrain = CROSSABLE_TERRAIN_CREVICE;
                }
                else
                {
                    crossableTerrain = CROSSABLE_TERRAIN_WALL;
                }
            }
        }
        tile = GetMapTile_1(pokemon->posWorld.x, pokemon->posWorld.y);
        if (tile->canMoveAdjacent[crossableTerrain] & gDirectionBitMasks_2[direction & DIRECTION_MASK])
        {
            return TRUE;
        }
    }
    return FALSE;
}

bool8 CanMoveForward(struct DungeonEntity *pokemon, s32 direction, bool8 *pokemonInFront)
{
    u8 crossableTerrain = GetCrossableTerrain(pokemon->entityData->entityID);
    struct MapTile *frontTile, *currentTile;
    *pokemonInFront = FALSE;
    frontTile = GetMapTile_1(pokemon->posWorld.x + gAdjacentTileOffsets[direction].x,
        pokemon->posWorld.y + gAdjacentTileOffsets[direction].y);
    if (frontTile->tileType & TILE_TYPE_MAP_EDGE)
    {
        return FALSE;
    }
    if (frontTile->tileType & TILE_TYPE_MONSTER_HOUSE &&
        !gDungeonGlobalData->monsterHouseActive &&
        HasIQSkill(pokemon, IQ_SKILL_HOUSE_AVOIDER))
    {
        return FALSE;
    }
    if (frontTile->mapObject != NULL &&
        HasIQSkill(pokemon, IQ_SKILL_TRAP_AVOIDER) &&
        GetEntityType(frontTile->mapObject) == ENTITY_TRAP &&
        (frontTile->mapObject->visible || pokemon->entityData->eyesightStatus == EYESIGHT_STATUS_EYEDROPS))
    {
        return FALSE;
    }
    if ((frontTile->tileType & (TILE_TYPE_FLOOR | TILE_TYPE_LIQUID)) == TILE_TYPE_LIQUID &&
        gDungeonWaterType[gDungeonGlobalData->tileset] == DUNGEON_WATER_TYPE_LAVA &&
        HasIQSkill(pokemon, IQ_SKILL_LAVA_EVADER))
    {
        return FALSE;
    }
    if (!IsFixedDungeon())
    {
        if (pokemon->entityData->transformStatus == TRANSFORM_STATUS_MOBILE ||
            HasItem(pokemon, ITEM_ID_MOBILE_SCARF))
        {
            crossableTerrain = CROSSABLE_TERRAIN_WALL;
        }
        else if (HasIQSkill(pokemon, IQ_SKILL_ALL_TERRAIN_HIKER))
        {
            // BUG: If the Pokémon is a Ghost type that can normally move through walls,
            // All-Terrain Hiker/Super Mobile may make the AI think it can't move through walls.
            crossableTerrain = CROSSABLE_TERRAIN_CREVICE;
        }
        else if (HasIQSkill(pokemon, IQ_SKILL_SUPER_MOBILE))
        {
            if ((direction & 1) != 0)
            {
                crossableTerrain = CROSSABLE_TERRAIN_CREVICE;
            }
            else
            {
                crossableTerrain = CROSSABLE_TERRAIN_WALL;
            }
        }
    }
    currentTile = GetMapTile_1(pokemon->posWorld.x, pokemon->posWorld.y);
    if (currentTile->canMoveAdjacent[crossableTerrain] & gDirectionBitMasks_3[direction & DIRECTION_MASK])
    {
        if (frontTile->pokemon == NULL)
        {
            return TRUE;
        }
        else
        {
            *pokemonInFront = TRUE;
        }
    }
    return FALSE;
}
