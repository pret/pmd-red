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

bool8 CanCrossWalls(struct Entity *pokemon)
{
    struct EntityInfo *pokemonInfo = pokemon->info;
    struct EntityInfo *pokemonInfo2 = pokemonInfo;
    if (pokemonInfo2->transformStatus == STATUS_MOBILE)
    {
        return TRUE;
    }
    if (HasHeldItem(pokemon, ITEM_MOBILE_SCARF))
    {
        return TRUE;
    }
    if (GetCrossableTerrain(pokemonInfo2->id) == CROSSABLE_TERRAIN_WALL)
    {
        return TRUE;
    }
    return FALSE;
}

bool8 sub_807049C(struct Entity *pokemon, struct Position *pos)
{
  s32 crossableTerrain;
  struct Tile *tile;
  u16 tileFlags;
  struct EntityInfo *entityData;
  
  entityData = pokemon->info;
  tile = GetTile(pos->x, pos->y);
  if ((pos->x >= 0) && (pos->y >= 0) && (DUNGEON_MAX_SIZE_X > pos->x) &&
      (DUNGEON_MAX_SIZE_Y > pos->y && ((tile->terrainType & TERRAIN_TYPE_IMPASSABLE_WALL) == 0)) &&
     (tile->monster == NULL || (GetEntityType(tile->monster) == ENTITY_MONSTER))) {
    if (IsCurrentFixedRoomBossFight() || (entityData->transformStatus != STATUS_MOBILE && !HasHeldItem(pokemon, ITEM_MOBILE_SCARF))) {
      crossableTerrain = GetCrossableTerrain(entityData->id);
      tileFlags = tile->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);
      if (IQSkillIsEnabled(pokemon, IQ_ALL_TERRAIN_HIKER)) {
        crossableTerrain = CROSSABLE_TERRAIN_CREVICE;
      }
      if (IQSkillIsEnabled(pokemon, IQ_SUPER_MOBILE)) {
        crossableTerrain = CROSSABLE_TERRAIN_WALL;
      }
        switch(crossableTerrain)
        {
            case CROSSABLE_TERRAIN_LIQUID:
                if(tileFlags == TERRAIN_TYPE_SECONDARY) return FALSE;
            case CROSSABLE_TERRAIN_REGULAR:
                if(tileFlags == TERRAIN_TYPE_NORMAL) return FALSE;
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
