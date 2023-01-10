#include "global.h"
#include "dungeon_movement_1.h"

#include "constants/item.h"
#include "constants/iq_skill.h"
#include "constants/status.h"
#include "constants/type.h"
#include "constants/weather.h"
#include "dungeon_engine.h"
#include "dungeon_items.h"
#include "dungeon_global_data.h"
#include "dungeon_movement.h"
#include "dungeon_map_access.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_util.h"
#include "map.h"
#include "pokemon.h"
#include "weather.h"

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

bool8 sub_8070564(struct DungeonEntity *pokemon, struct Position *pos)
{
  u8 crossableTerrain;
  struct MapTile *tile;
  u16 tileFlags;
  struct DungeonEntityData *entityData;
#ifndef NONMATCHING
  register s32 tileFlags_0 asm("r0");
  register s32 crossableTerrain2 asm("r3");
#else
  s32 tileFlags_0;
  s32 crossableTerrain2;
#endif
  
  entityData = pokemon->entityData;
  tile = GetMapTile_1(pos->x, pos->y);
  if ((pos->x >= 0) && (pos->y >= 0) && (DUNGEON_MAX_SIZE_X > pos->x) &&
      (DUNGEON_MAX_SIZE_Y > pos->y && ((tile->tileType & TILE_TYPE_MAP_EDGE) == 0)) &&
     (tile->pokemon == NULL || (GetEntityType(tile->pokemon) == ENTITY_POKEMON))) {
        crossableTerrain2 = crossableTerrain = GetCrossableTerrain(entityData->entityID);
        tileFlags_0 = tileFlags = tile->tileType & (TILE_TYPE_FLOOR | TILE_TYPE_LIQUID);
        switch(crossableTerrain)
        {
            case CROSSABLE_TERRAIN_WALL: // 3
            case CROSSABLE_TERRAIN_CREVICE: // 2
            case 4 ... INT_MAX:
                if (crossableTerrain2 > CROSSABLE_TERRAIN_WALL) return FALSE;
                if(tileFlags != 0)
                    return FALSE;
                break;
            case CROSSABLE_TERRAIN_REGULAR: // 0
                if(tileFlags == TILE_TYPE_FLOOR)
            default:
                    return FALSE;
                break;
            case CROSSABLE_TERRAIN_LIQUID: // 1
                if(tileFlags == TILE_TYPE_LIQUID) return FALSE;
                if (tileFlags_0 == TILE_TYPE_FLOOR) return FALSE;
                return TRUE;
        }
    }
   return TRUE;
}

bool8 sub_80705F0(struct DungeonEntity *pokemon, struct Position *pos)
{
  s32 crossableTerrain;
  struct MapTile *tile;
  u16 tileFlags;
  struct DungeonEntityData *entityData;
  
  entityData = pokemon->entityData;
  tile = GetMapTile_1(pos->x, pos->y);
  if ((pos->x >= 0) && (pos->y >= 0) && (DUNGEON_MAX_SIZE_X > pos->x) &&
      (DUNGEON_MAX_SIZE_Y > pos->y && ((tile->tileType & TILE_TYPE_MAP_EDGE) == 0)) &&
     ((tile->pokemon == NULL) || ((GetEntityType(tile->pokemon) == ENTITY_POKEMON)))) {
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
            case CROSSABLE_TERRAIN_WALL:
            default:
                return FALSE;
            case CROSSABLE_TERRAIN_REGULAR:
            case CROSSABLE_TERRAIN_LIQUID:
            case CROSSABLE_TERRAIN_CREVICE:
                if(tileFlags != 0) return FALSE;
        }
    }
    else return FALSE;
  }
   return TRUE;
}

bool8 sub_80706A4(struct DungeonEntity *pokemon, struct Position *pos)
{
  s32 crossableTerrain;
  struct MapTile *tile;
  u16 tileFlags;
  struct DungeonEntityData *entityData;
  
  entityData = pokemon->entityData;
  tile = GetMapTile_1(pos->x, pos->y);
  if ((pos->x >= 0) && (pos->y >= 0) && (DUNGEON_MAX_SIZE_X > pos->x) &&
      (DUNGEON_MAX_SIZE_Y > pos->y && ((tile->tileType & TILE_TYPE_MAP_EDGE) == 0)) &&
     ((tile->pokemon == NULL) || ((GetEntityType(tile->pokemon) == ENTITY_POKEMON) && (tile->pokemon->entityData == entityData)))) {
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

s32 GetMovementSpeed(struct DungeonEntity *pokemon)
{
  s32 index;
  s32 speed;
  struct DungeonEntityData * entityData;
  
  entityData = pokemon->entityData;
  speed = 0;

  for(index = 0; index < NUM_SPEED_TURN_COUNTERS; index++)
  {
    if (entityData->speedUpTurnsLeft[index + NUM_SPEED_TURN_COUNTERS] != 0) {
      speed--;
    }
    if (entityData->speedUpTurnsLeft[index] != 0) {
      speed++;
    }
  }

  if (entityData->nonVolatileStatus == NON_VOLATILE_STATUS_PARALYZED) {
    speed--;
  }

  speed += GetMoveSpeed(entityData->entityID);
  if ((HasType(pokemon, TYPE_ICE)) && (GetWeather(pokemon) == WEATHER_SNOW)) {
    speed++;
  }
  if (entityData->transformSpecies == SPECIES_DEOXYS_SPEED) {
    speed++;
  }
  if ((entityData->entityID == SPECIES_KECLEON) && entityData->isEnemy &&
     gDungeonGlobalData->unk66E) {
    speed++;
  }
  if (speed < 0) {
    speed = 0;
  }
  if (MAX_MOVEMENT_SPEED < speed) {
    speed = MAX_MOVEMENT_SPEED;
  }
  entityData->movementSpeed = speed;
  return speed;
}
