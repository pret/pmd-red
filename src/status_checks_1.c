#include "global.h"
#include "status_checks_1.h"

#include "constants/ability.h"
#include "constants/iq_skill.h"
#include "constants/status.h"
#include "constants/type.h"
#include "constants/weather.h"
#include "dungeon_engine.h"
#include "dungeon_global_data.h"
#include "dungeon_items.h"
#include "dungeon_movement.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_map_access.h"
#include "dungeon_util.h"
#include "code_800D090.h"
#include "code_80521D0.h"
#include "pokemon.h"
#include "weather.h"

extern void sub_80429B4(struct Entity *r0);

extern u8 *gUnknown_80FEE80[];
extern u8 *gUnknown_80F8974[];
extern u8 *gUnknown_80F8994[];
extern u8 *gUnknown_80F8968[];
extern u8 *gUnknown_80F8988[];
extern u8 gUnknown_8106FA4[];

bool8 sub_80705F0(struct Entity *pokemon, struct Position *pos)
{
  s32 crossableTerrain;
  struct Tile *tile;
  u16 tileFlags;
  struct EntityInfo *entityData;
  
  entityData = pokemon->info;
  tile = GetTile(pos->x, pos->y);
  if ((pos->x >= 0) && (pos->y >= 0) && (DUNGEON_MAX_SIZE_X > pos->x) &&
      (DUNGEON_MAX_SIZE_Y > pos->y && ((tile->terrainType & TERRAIN_TYPE_IMPASSABLE_WALL) == 0)) &&
     ((tile->monster == NULL) || ((GetEntityType(tile->monster) == ENTITY_MONSTER)))) {
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
  struct EntityInfo *entityData;
  
  entityData = pokemon->info;
  tile = GetTile(pos->x, pos->y);
  if ((pos->x >= 0) && (pos->y >= 0) && (DUNGEON_MAX_SIZE_X > pos->x) &&
      (DUNGEON_MAX_SIZE_Y > pos->y && ((tile->terrainType & TERRAIN_TYPE_IMPASSABLE_WALL) == 0)) &&
     ((tile->monster == NULL) || ((GetEntityType(tile->monster) == ENTITY_MONSTER) && (tile->monster->info == entityData)))) {
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

s32 GetSpeedStatus(struct Entity *pokemon)
{
  s32 index;
  s32 speed;
  struct EntityInfo * entityData;
  
  entityData = pokemon->info;
  speed = 0;

  for(index = 0; index < NUM_SPEED_TURN_COUNTERS; index++)
  {
    if (entityData->speedUpCounters[index + NUM_SPEED_TURN_COUNTERS] != 0) {
      speed--;
    }
    if (entityData->speedUpCounters[index] != 0) {
      speed++;
    }
  }

  if (entityData->nonVolatileStatus == STATUS_PARALYSIS) {
    speed--;
  }

  speed += GetMovementSpeed(entityData->id);
  if ((MonsterIsType(pokemon, TYPE_ICE)) && (GetApparentWeather(pokemon) == WEATHER_SNOW)) {
    speed++;
  }
  if (entityData->apparentID == MONSTER_DEOXYS_SPEED) {
    speed++;
  }
  if ((entityData->id == MONSTER_KECLEON) && entityData->isNotTeamMember &&
     gDungeon->unk66E) {
    speed++;
  }
  if (speed < 0) {
    speed = 0;
  }
  if (MAX_SPEED_STAGE < speed) {
    speed = MAX_SPEED_STAGE;
  }
  entityData->speedStage = speed;
  return speed;
}

u8 sub_8070828(struct Entity *pokemon, bool8 displayMessage)
{
    bool8 flag;

    flag = FALSE;
    if (!EntityExists(pokemon)) {
        return 0;
    }
    else {
        if ((HasAbility(pokemon, ABILITY_SWIFT_SWIM)) && (GetApparentWeather(pokemon) == WEATHER_RAIN)) {
            flag = TRUE;
        }
        if ((HasAbility(pokemon, ABILITY_CHLOROPHYLL)) && (GetApparentWeather(pokemon) == WEATHER_SUNNY)) {
            flag = TRUE;
        }
        if (displayMessage && SetVisualFlags(pokemon->info, 0x40, flag)) {
            sub_80429B4(pokemon);
            SendMessage(pokemon, *gUnknown_80FEE80);
        }
        if (flag) {
            return 2;
        }
        else {
            return 1;
        }
    }
}

void SetMessageArgument_2(u8 *buffer, struct EntityInfo *param_2, s32 colorNum)
{
    if (((gDungeon->blinded ||
        gDungeon->hallucinating) ||
        (param_2->transformStatus == STATUS_INVISIBLE)) &&
        (param_2->isNotTeamMember))
    {
        strcpy(buffer, *gUnknown_80F8988);
    }
    else
    {
        if (param_2->waitingStatus == STATUS_DECOY) {
            strcpy(buffer, *gUnknown_80F8968);
        }
        else
        {
            if (param_2->isNotTeamMember) {
                if ((param_2->joinedAt == 0x4A) || (param_2->clientType == CLIENT_TYPE_CLIENT)) {
                    CopyYellowMonsterNametoBuffer(buffer, param_2->apparentID);
                }
                else
                CopyCyanMonsterNametoBuffer(buffer, param_2->apparentID);
            }
            else
            {
                sub_808D9DC(buffer, &gRecruitedPokemonRef->pokemon2[param_2->teamIndex],colorNum);
            }
        }
    }
}

void sub_8070968(u8 *buffer, struct EntityInfo *entityData, s32 colorNum)
{
    if (entityData->waitingStatus == STATUS_DECOY) {
        sprintfStatic(buffer, gUnknown_8106FA4, colorNum + 0x30, *gUnknown_80F8974);
    }
    else if (entityData->isNotTeamMember) {
        CopyCyanMonsterNametoBuffer(buffer, entityData->apparentID);
    }
    else {
        sub_808D9DC(buffer, &gRecruitedPokemonRef->pokemon2[entityData->teamIndex], colorNum);
    }
}

void sub_80709C8(u8 *buffer, struct EntityInfo *entityData)
{
    if (((gDungeon->blinded ||
          gDungeon->hallucinating) ||
          (entityData->transformStatus == STATUS_INVISIBLE)) &&
          (entityData->isNotTeamMember))
    {
            strcpy(buffer, *gUnknown_80F8994);
    }
    else
    {
        if (entityData->waitingStatus == STATUS_DECOY) {
            strcpy(buffer, *gUnknown_80F8974);
        }
        else
        {
            if (entityData->isNotTeamMember) {
                CopyMonsterNametoBuffer(buffer, entityData->apparentID);
            }
            else
            {
                sub_808DA0C(buffer, &gRecruitedPokemonRef->pokemon2[entityData->teamIndex]);
            }
        }
    }
}

bool8 HasNegativeStatus(struct Entity *pokemon)
{
    struct EntityInfo *pokemonInfo = pokemon->info;
    s32 i;
    if (pokemonInfo->sleep == STATUS_SLEEP ||
        pokemonInfo->sleep == STATUS_NIGHTMARE ||
        pokemonInfo->sleep == STATUS_YAWNING ||
        pokemonInfo->nonVolatileStatus != STATUS_NONE ||
        (pokemonInfo->immobilizeStatus != STATUS_INGRAIN && pokemonInfo->immobilizeStatus != STATUS_NONE) ||
        pokemonInfo->volatileStatus != STATUS_NONE ||
        pokemonInfo->waitingStatus == STATUS_CURSED ||
        pokemonInfo->waitingStatus == STATUS_DECOY ||
        pokemonInfo->linkedStatus == STATUS_LEECH_SEED ||
        pokemonInfo->moveStatus == STATUS_WHIFFER ||
        pokemonInfo->eyesightStatus == STATUS_BLINKER ||
        pokemonInfo->eyesightStatus == STATUS_CROSS_EYED ||
        pokemonInfo->muzzled == TRUE ||
        pokemonInfo->exposed ||
        pokemonInfo->perishSongTurns != 0)
    {
        return TRUE;
    }
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        struct Move *moves = pokemonInfo->moves;
        if (moves[i].moveFlags & MOVE_FLAG_EXISTS && moves[i].moveFlags2 & MOVE_FLAG_SEALED)
        {
            return TRUE;
        }
    }
    for (i = 0; i < NUM_SPEED_TURN_COUNTERS; i++)
    {
        if (pokemonInfo->speedDownCounters[i] != 0)
        {
            return TRUE;
        }
    }
    return FALSE;
}

bool8 IsSleeping(struct Entity *pokemon)
{
    if (pokemon->info->sleep != STATUS_SLEEP &&
        pokemon->info->sleep != STATUS_NAPPING &&
        pokemon->info->sleep != STATUS_NIGHTMARE)
    {
        return FALSE;
    }
    return TRUE;
}

bool8 HasLowHealth(struct Entity *pokemon)
{
    struct EntityInfo *pokemonInfo = pokemon->info;
    struct EntityInfo *pokemonInfo2 = pokemon->info;
    s32 maxHPStat = pokemonInfo->maxHPStat;
    if (maxHPStat < 0)
    {
        maxHPStat += 3;
    }
    if (pokemonInfo2->HP <= maxHPStat >> 2)
    {
        return TRUE;
    }
    return FALSE;
}
