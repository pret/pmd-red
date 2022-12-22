#include "global.h"
#include "dungeon_movement_1.h"

#include "constants/item.h"
#include "constants/iq_skill.h"
#include "constants/status.h"
#include "dungeon_engine.h"
#include "dungeon_items.h"
#include "dungeon_global_data.h"
#include "dungeon_movement.h"
#include "dungeon_map_access.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_util.h"
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

bool8 sub_807049C(struct DungeonEntity *pokemon, struct Position *pos)
{
  s32 crossableTerrain;
  struct MapTile *tile;
  u16 tileFlags;
  struct DungeonEntityData *entityData;
  
  entityData = pokemon->entityData;
  tile = GetMapTile_1(pos->x, pos->y);
  if ((pos->x >= 0) && (pos->y >= 0) && (DUNGEON_MAX_SIZE_X > pos->x) &&
      (DUNGEON_MAX_SIZE_Y > pos->y && ((tile->tileType & TILE_TYPE_MAP_EDGE) == 0)) &&
     (tile->pokemon == NULL || (GetEntityType(tile->pokemon) == ENTITY_POKEMON))) {
    if (IsFixedDungeon() || (entityData->transformStatus != TRANSFORM_STATUS_MOBILE && !HasItem(pokemon, ITEM_ID_MOBILE_SCARF))) {
      crossableTerrain = GetCrossableTerrain(entityData->entityID);
      tileFlags = tile->tileType & (TILE_TYPE_FLOOR | TILE_TYPE_LIQUID);
      if (HasIQSkill(pokemon, IQ_SKILL_ALL_TERRAIN_HIKER)) {
        crossableTerrain = CROSSABLE_TERRAIN_CREVICE;
      }
      if (HasIQSkill(pokemon, IQ_SKILL_SUPER_MOBILE)) {
        crossableTerrain = CROSSABLE_TERRAIN_WALL;
      }
        switch(crossableTerrain)
        {
            case CROSSABLE_TERRAIN_LIQUID:
                if(tileFlags == TILE_TYPE_LIQUID) return FALSE;
            case CROSSABLE_TERRAIN_REGULAR:
                if(tileFlags == TILE_TYPE_FLOOR) return FALSE;
                break;
            case CROSSABLE_TERRAIN_WALL:
            default:
                return FALSE;
            case CROSSABLE_TERRAIN_CREVICE:
                if(tileFlags != 0) return FALSE;
        }
    }
    else return FALSE;
  }
   return TRUE;
}
