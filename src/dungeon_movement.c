#include "global.h"
#include "structs/map.h"
#include "dungeon_movement.h"

#include "constants/item.h"
#include "constants/iq_skill.h"
#include "constants/status.h"
#include "constants/type.h"
#include "constants/weather.h"
#include "dungeon_engine.h"
#include "dungeon_items.h"
#include "structs/str_dungeon.h"
#include "dungeon_map_access.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_util.h"
#include "pokemon.h"
#include "weather.h"

EWRAM_DATA u8 gWalkableTileToCrossableTerrain[8] = {0};

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

u8 sub_807034C(s16 id, struct Tile *tile)
{
  s32 crossableTerrain;
  u16 tileFlags;
  s32 id_s32;

  id_s32 = id;

  if ((tile->monster == NULL) && ((tile->terrainType & TERRAIN_TYPE_IMPASSABLE_WALL) == 0)) {
      crossableTerrain = GetCrossableTerrain(id_s32);
      tileFlags = tile->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);
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
    return TRUE;
}

u8 sub_80703A0(Entity *pokemon, Position *pos)
{
    u8 crossableTerrain;
    struct Tile *tile;
    u16 tileFlags;
    EntityInfo *entityInfo;

    entityInfo = pokemon->axObj.info;
    tile = GetTile(pos->x,pos->y);
    if ((pos->x >= 0) && (pos->y >= 0) && (DUNGEON_MAX_SIZE_X > pos->x) &&
        (DUNGEON_MAX_SIZE_Y > pos->y) && (tile->monster == NULL) && ((tile->terrainType & TERRAIN_TYPE_IMPASSABLE_WALL) == 0)) {
        if ((IsCurrentFixedRoomBossFight()) || ((entityInfo->transformStatus.transformStatus != STATUS_MOBILE && (!HasHeldItem(pokemon, ITEM_MOBILE_SCARF))))) {
            crossableTerrain = GetCrossableTerrain(entityInfo->id);
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
        } else return FALSE;
    }
    return TRUE;
}

bool8 CanCrossWalls(Entity *pokemon)
{
    EntityInfo *pokemonInfo = pokemon->axObj.info;
    EntityInfo *pokemonInfo2 = pokemonInfo;
    if (pokemonInfo2->transformStatus.transformStatus == STATUS_MOBILE)
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

bool8 sub_807049C(Entity *pokemon, Position *pos)
{
    s32 crossableTerrain;
    struct Tile *tile;
    u16 tileFlags;
    EntityInfo *entityInfo;

    entityInfo = pokemon->axObj.info;
    tile = GetTile(pos->x, pos->y);
    if ((pos->x >= 0) && (pos->y >= 0) && (DUNGEON_MAX_SIZE_X > pos->x) &&
        (DUNGEON_MAX_SIZE_Y > pos->y && ((tile->terrainType & TERRAIN_TYPE_IMPASSABLE_WALL) == 0)) &&
        (tile->monster == NULL || (GetEntityType(tile->monster) == ENTITY_MONSTER))) {
        if (IsCurrentFixedRoomBossFight() || (entityInfo->transformStatus.transformStatus != STATUS_MOBILE && !HasHeldItem(pokemon, ITEM_MOBILE_SCARF))) {
            crossableTerrain = GetCrossableTerrain(entityInfo->id);
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

bool8 sub_8070564(Entity *pokemon, Position *pos)
{
    u8 crossableTerrain;
    struct Tile *tile;
    u16 tileFlags;
    EntityInfo *entityInfo;
#ifndef NONMATCHING
    register s32 tileFlags_0 asm("r0");
    register s32 crossableTerrain2 asm("r3");
#else
    s32 tileFlags_0;
    s32 crossableTerrain2;
#endif

    entityInfo = pokemon->axObj.info;
    tile = GetTile(pos->x, pos->y);
    if ((pos->x >= 0) && (pos->y >= 0) && (DUNGEON_MAX_SIZE_X > pos->x) &&
        (DUNGEON_MAX_SIZE_Y > pos->y && ((tile->terrainType & TERRAIN_TYPE_IMPASSABLE_WALL) == 0)) &&
        (tile->monster == NULL || (GetEntityType(tile->monster) == ENTITY_MONSTER))) {
        crossableTerrain2 = crossableTerrain = GetCrossableTerrain(entityInfo->id);
        tileFlags_0 = tileFlags = tile->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);
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
                if(tileFlags == TERRAIN_TYPE_NORMAL)
                default:
                    return FALSE;
                    break;
            case CROSSABLE_TERRAIN_LIQUID: // 1
                if(tileFlags == TERRAIN_TYPE_SECONDARY) return FALSE;
                if (tileFlags_0 == TERRAIN_TYPE_NORMAL) return FALSE;
                return TRUE;
        }
    }
    return TRUE;
}

bool8 sub_80705F0(Entity *pokemon, Position *pos)
{
    s32 crossableTerrain;
    struct Tile *tile;
    u16 tileFlags;
    EntityInfo *entityInfo;

    entityInfo = pokemon->axObj.info;
    tile = GetTile(pos->x, pos->y);
    if ((pos->x >= 0) && (pos->y >= 0) && (DUNGEON_MAX_SIZE_X > pos->x) &&
        (DUNGEON_MAX_SIZE_Y > pos->y && ((tile->terrainType & TERRAIN_TYPE_IMPASSABLE_WALL) == 0)) &&
        ((tile->monster == NULL) || ((GetEntityType(tile->monster) == ENTITY_MONSTER)))) {
        if (IsCurrentFixedRoomBossFight() || (entityInfo->transformStatus.transformStatus != STATUS_MOBILE && !HasHeldItem(pokemon, ITEM_MOBILE_SCARF))) {
            crossableTerrain = GetCrossableTerrain(entityInfo->id);
            tileFlags = tile->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);
            if (IQSkillIsEnabled(pokemon, IQ_ALL_TERRAIN_HIKER)) {
                crossableTerrain = CROSSABLE_TERRAIN_CREVICE;
            }
            if (IQSkillIsEnabled(pokemon, IQ_SUPER_MOBILE)) {
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

bool8 sub_80706A4(Entity *pokemon, Position *pos)
{
    s32 crossableTerrain;
    struct Tile *tile;
    u16 tileFlags;
    EntityInfo *entityInfo;

    entityInfo = pokemon->axObj.info;
    tile = GetTile(pos->x, pos->y);
    if ((pos->x >= 0) && (pos->y >= 0) && (DUNGEON_MAX_SIZE_X > pos->x) &&
        (DUNGEON_MAX_SIZE_Y > pos->y && ((tile->terrainType & TERRAIN_TYPE_IMPASSABLE_WALL) == 0)) &&
        ((tile->monster == NULL) || ((GetEntityType(tile->monster) == ENTITY_MONSTER) && (tile->monster->axObj.info == entityInfo)))) {
        if (IsCurrentFixedRoomBossFight() || (entityInfo->transformStatus.transformStatus != STATUS_MOBILE && !HasHeldItem(pokemon, ITEM_MOBILE_SCARF))) {
            crossableTerrain = GetCrossableTerrain(entityInfo->id);
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

s32 CalcSpeedStage(Entity *pokemon)
{
  s32 index;
  s32 speed;
  EntityInfo * entityInfo;

  entityInfo = pokemon->axObj.info;
  speed = 0;

  for(index = 0; index < NUM_SPEED_COUNTERS; index++)
  {
    if (entityInfo->speedUpCounters[index + NUM_SPEED_COUNTERS] != 0) {
      speed--;
    }
    if (entityInfo->speedUpCounters[index] != 0) {
      speed++;
    }
  }

  if (entityInfo->nonVolatile.nonVolatileStatus == STATUS_PARALYSIS) {
    speed--;
  }

  speed += GetMovementSpeed(entityInfo->id);
  if ((MonsterIsType(pokemon, TYPE_ICE)) && (GetApparentWeather(pokemon) == WEATHER_SNOW)) {
    speed++;
  }
  if (entityInfo->apparentID == MONSTER_DEOXYS_SPEED) {
    speed++;
  }
  if ((entityInfo->id == MONSTER_KECLEON) && entityInfo->isNotTeamMember &&
     gDungeon->unk66E) {
    speed++;
  }
  if (speed < 0) {
    speed = 0;
  }
  if (MAX_SPEED_STAGE < speed) {
    speed = MAX_SPEED_STAGE;
  }
  entityInfo->speedStage = speed;
  return speed;
}
