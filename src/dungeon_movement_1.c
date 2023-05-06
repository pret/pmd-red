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


u8 sub_80703A0(struct Entity *pokemon, struct Position *pos)
{
    u8 crossableTerrain;
    struct Tile *tile;
    u16 tileFlags;
    struct EntityInfo *entityInfo;

    entityInfo = pokemon->info;
    tile = GetTile(pos->x,pos->y);
    if ((pos->x >= 0) && (pos->y >= 0) && (DUNGEON_MAX_SIZE_X > pos->x) &&
        (DUNGEON_MAX_SIZE_Y > pos->y) && (tile->monster == NULL) && ((tile->terrainType & TERRAIN_TYPE_IMPASSABLE_WALL) == 0)) {
        if ((IsCurrentFixedRoomBossFight()) || ((entityInfo->transformStatus != STATUS_MOBILE && (!HasHeldItem(pokemon, ITEM_MOBILE_SCARF))))) {
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
    struct EntityInfo *entityInfo;

    entityInfo = pokemon->info;
    tile = GetTile(pos->x, pos->y);
    if ((pos->x >= 0) && (pos->y >= 0) && (DUNGEON_MAX_SIZE_X > pos->x) &&
        (DUNGEON_MAX_SIZE_Y > pos->y && ((tile->terrainType & TERRAIN_TYPE_IMPASSABLE_WALL) == 0)) &&
        (tile->monster == NULL || (GetEntityType(tile->monster) == ENTITY_MONSTER))) {
        if (IsCurrentFixedRoomBossFight() || (entityInfo->transformStatus != STATUS_MOBILE && !HasHeldItem(pokemon, ITEM_MOBILE_SCARF))) {
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

bool8 sub_8070564(struct Entity *pokemon, struct Position *pos)
{
    u8 crossableTerrain;
    struct Tile *tile;
    u16 tileFlags;
    struct EntityInfo *entityInfo;
#ifndef NONMATCHING
    register s32 tileFlags_0 asm("r0");
    register s32 crossableTerrain2 asm("r3");
#else
    s32 tileFlags_0;
    s32 crossableTerrain2;
#endif

    entityInfo = pokemon->info;
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

bool8 sub_80705F0(struct Entity *pokemon, struct Position *pos)
{
    s32 crossableTerrain;
    struct Tile *tile;
    u16 tileFlags;
    struct EntityInfo *entityInfo;

    entityInfo = pokemon->info;
    tile = GetTile(pos->x, pos->y);
    if ((pos->x >= 0) && (pos->y >= 0) && (DUNGEON_MAX_SIZE_X > pos->x) &&
        (DUNGEON_MAX_SIZE_Y > pos->y && ((tile->terrainType & TERRAIN_TYPE_IMPASSABLE_WALL) == 0)) &&
        ((tile->monster == NULL) || ((GetEntityType(tile->monster) == ENTITY_MONSTER)))) {
        if (IsCurrentFixedRoomBossFight() || (entityInfo->transformStatus != STATUS_MOBILE && !HasHeldItem(pokemon, ITEM_MOBILE_SCARF))) {
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

bool8 sub_80706A4(struct Entity *pokemon, struct Position *pos)
{
    s32 crossableTerrain;
    struct Tile *tile;
    u16 tileFlags;
    struct EntityInfo *entityInfo;

    entityInfo = pokemon->info;
    tile = GetTile(pos->x, pos->y);
    if ((pos->x >= 0) && (pos->y >= 0) && (DUNGEON_MAX_SIZE_X > pos->x) &&
        (DUNGEON_MAX_SIZE_Y > pos->y && ((tile->terrainType & TERRAIN_TYPE_IMPASSABLE_WALL) == 0)) &&
        ((tile->monster == NULL) || ((GetEntityType(tile->monster) == ENTITY_MONSTER) && (tile->monster->info == entityInfo)))) {
        if (IsCurrentFixedRoomBossFight() || (entityInfo->transformStatus != STATUS_MOBILE && !HasHeldItem(pokemon, ITEM_MOBILE_SCARF))) {
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

s32 CalcSpeedStage(struct Entity *pokemon)
{
  s32 index;
  s32 speed;
  struct EntityInfo * entityInfo;
  
  entityInfo = pokemon->info;
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

  if (entityInfo->nonVolatileStatus == STATUS_PARALYSIS) {
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
