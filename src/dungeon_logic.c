#include "global.h"
#include "globaldata.h"
#include "dungeon_logic.h"
#include "structs/map.h"
#include "constants/item.h"
#include "constants/iq_skill.h"
#include "constants/status.h"
#include "constants/type.h"
#include "constants/weather.h"
#include "run_dungeon.h"
#include "dungeon_items.h"
#include "structs/str_dungeon.h"
#include "dungeon_map_access.h"
#include "dungeon_util.h"
#include "pokemon.h"
#include "weather.h"
#include "constants/ability.h"
#include "constants/dungeon.h"
#include "constants/tactic.h"
#include "constants/targeting.h"
#include "dungeon_random.h"
#include "dungeon_move_util.h"
#include "code_800D090.h"
#include "dungeon_message.h"
#include "dungeon_strings.h"
#include "constants/move_id.h"
#include "moves.h"
#include "pokemon_3.h"
#include "pokemon.h"
#include "dungeon_config.h"
#include "dungeon_pos_data.h"

// This file deals with things like controlling movement, walkable tiles, ai targeting, status checks and pokemon attributes.

extern void sub_80429B4(Entity *r0);
extern void ShowVisualFlags(Entity *r0);

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

u8 sub_807034C(s32 id, const Tile *tile)
{
  s32 crossableTerrain;
  u16 tileFlags;
  s32 id_s32;

  id_s32 = SpeciesId(id);

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

u8 sub_80703A0(Entity *pokemon, DungeonPos *pos)
{
    const Tile *tile;
    u8 crossableTerrain;
    u16 tileFlags;
    EntityInfo *entityInfo;

    entityInfo = GetEntInfo(pokemon);
    tile = GetTile(pos->x,pos->y);
    if (pos->x < 0 || pos->y < 0)
        return TRUE;
    if (pos->x >= DUNGEON_MAX_SIZE_X || pos->y >= DUNGEON_MAX_SIZE_Y)
        return TRUE;
    if (tile->monster != NULL)
        return TRUE;
    if (tile->terrainType & TERRAIN_TYPE_IMPASSABLE_WALL)
        return TRUE;

    if ((IsCurrentFixedRoomBossFight()) || ((entityInfo->invisibleClassStatus.status != STATUS_MOBILE && (!HasHeldItem(pokemon, ITEM_MOBILE_SCARF))))) {
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
    else {
        return FALSE;
    }

    return TRUE;
}

bool8 CanCrossWalls(Entity *pokemon)
{
    EntityInfo *pokemonInfo = GetEntInfo(pokemon);
    if (pokemonInfo->invisibleClassStatus.status == STATUS_MOBILE)
    {
        return TRUE;
    }
    if (HasHeldItem(pokemon, ITEM_MOBILE_SCARF))
    {
        return TRUE;
    }
    if (GetCrossableTerrain(pokemonInfo->id) == CROSSABLE_TERRAIN_WALL)
    {
        return TRUE;
    }
    return FALSE;
}

bool8 sub_807049C(Entity *pokemon, DungeonPos *pos)
{
    s32 crossableTerrain;
    const Tile *tile;
    u16 tileFlags;
    EntityInfo *entityInfo;

    entityInfo = GetEntInfo(pokemon);
    tile = GetTile(pos->x,pos->y);
    if (pos->x < 0 || pos->y < 0)
        return TRUE;
    if (pos->x >= DUNGEON_MAX_SIZE_X || pos->y >= DUNGEON_MAX_SIZE_Y)
        return TRUE;
    if (tile->terrainType & TERRAIN_TYPE_IMPASSABLE_WALL)
        return TRUE;
    if (tile->monster != NULL && GetEntityType(tile->monster) != ENTITY_MONSTER)
        return TRUE;

    if (IsCurrentFixedRoomBossFight() || (entityInfo->invisibleClassStatus.status != STATUS_MOBILE && !HasHeldItem(pokemon, ITEM_MOBILE_SCARF))) {
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
    else {
        return FALSE;
    }

    return TRUE;
}

bool8 sub_8070564(Entity *pokemon, DungeonPos *pos)
{
    u16 crossableTerrain;
    u32 tileFlags;

    EntityInfo *entityInfo = GetEntInfo(pokemon);
    const Tile *tile = GetTile(pos->x,pos->y);

    if (pos->x < 0 || pos->y < 0)
        return TRUE;
    if (pos->x >= DUNGEON_MAX_SIZE_X || pos->y >= DUNGEON_MAX_SIZE_Y)
        return TRUE;
    if (tile->terrainType & TERRAIN_TYPE_IMPASSABLE_WALL)
        return TRUE;
    if (tile->monster != NULL && GetEntityType(tile->monster) != ENTITY_MONSTER)
        return TRUE;

    crossableTerrain = GetCrossableTerrain(entityInfo->id);
    tileFlags = GetTerrainType(tile);

    switch (crossableTerrain)
    {
        default:
            return FALSE;
        case CROSSABLE_TERRAIN_WALL:
        case CROSSABLE_TERRAIN_CREVICE:
            if (tileFlags != TERRAIN_TYPE_WALL) return FALSE;
            break;
        case CROSSABLE_TERRAIN_REGULAR:
            if (tileFlags == TERRAIN_TYPE_NORMAL) return FALSE;
            break;
        case CROSSABLE_TERRAIN_LIQUID:
            if (tileFlags == TERRAIN_TYPE_SECONDARY) return FALSE;
            if (tileFlags == TERRAIN_TYPE_NORMAL) return FALSE;
            break;
    }

    return TRUE;
}

bool8 sub_80705F0(Entity *pokemon, DungeonPos *pos)
{
    s32 crossableTerrain;
    const Tile *tile;
    u16 tileFlags;
    EntityInfo *entityInfo;

    entityInfo = GetEntInfo(pokemon);
    tile = GetTile(pos->x,pos->y);
    if (pos->x < 0 || pos->y < 0)
        return TRUE;
    if (pos->x >= DUNGEON_MAX_SIZE_X || pos->y >= DUNGEON_MAX_SIZE_Y)
        return TRUE;
    if (((tile->terrainType & TERRAIN_TYPE_IMPASSABLE_WALL) == 0) && (tile->monster == NULL || (GetEntityType(tile->monster) == ENTITY_MONSTER))) {
        if (IsCurrentFixedRoomBossFight() || (entityInfo->invisibleClassStatus.status != STATUS_MOBILE && !HasHeldItem(pokemon, ITEM_MOBILE_SCARF))) {
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

bool8 sub_80706A4(Entity *pokemon, DungeonPos *pos)
{
    s32 crossableTerrain;
    const Tile *tile;
    u16 tileFlags;
    EntityInfo *entityInfo;

    entityInfo = GetEntInfo(pokemon);
    tile = GetTile(pos->x,pos->y);
    if (pos->x < 0 || pos->y < 0)
        return TRUE;
    if (pos->x >= DUNGEON_MAX_SIZE_X || pos->y >= DUNGEON_MAX_SIZE_Y)
        return TRUE;
    if ((((tile->terrainType & TERRAIN_TYPE_IMPASSABLE_WALL) == 0))
        && (tile->monster == NULL || ((GetEntityType(tile->monster) == ENTITY_MONSTER) && (GetEntInfo(tile->monster) == entityInfo)))) {
        if (IsCurrentFixedRoomBossFight() || (entityInfo->invisibleClassStatus.status != STATUS_MOBILE && !HasHeldItem(pokemon, ITEM_MOBILE_SCARF))) {
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

  entityInfo = GetEntInfo(pokemon);
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

  if (entityInfo->burnClassStatus.status == STATUS_PARALYSIS) {
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
     gDungeon->unk644.unk2A) {
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

s32 sub_8070828(Entity *pokemon, bool8 displayMessage)
{
    bool8 flag;

    flag = FALSE;
    if (!EntityIsValid(pokemon)) {
        return 0;
    }
    else {
        if ((AbilityIsActive(pokemon, ABILITY_SWIFT_SWIM)) && (GetApparentWeather(pokemon) == WEATHER_RAIN)) {
            flag = TRUE;
        }
        if ((AbilityIsActive(pokemon, ABILITY_CHLOROPHYLL)) && (GetApparentWeather(pokemon) == WEATHER_SUNNY)) {
            flag = TRUE;
        }
        if (displayMessage && SetVisualFlags(GetEntInfo(pokemon), 0x40, flag)) {
            sub_80429B4(pokemon);
            LogMessageByIdWithPopupCheckUser(pokemon, gUnknown_80FEE80);
        }
        if (flag) {
            return 2;
        }
        else {
            return 1;
        }
    }
}

void SetMessageArgument_2(u8 *buffer, EntityInfo *param_2, s32 colorNum)
{
    if (((gDungeon->unk181e8.blinded ||
        gDungeon->unk181e8.hallucinating) ||
        (param_2->invisibleClassStatus.status == STATUS_INVISIBLE)) &&
        (param_2->isNotTeamMember))
    {
        strcpy(buffer, gUnknown_80F8988);
    }
    else
    {
        if (param_2->curseClassStatus.status == STATUS_DECOY) {
            strcpy(buffer, gUnknown_80F8968);
        }
        else
        {
            if (param_2->isNotTeamMember) {
                if ((param_2->joinedAt.id == 0x4A) || (param_2->monsterBehavior == BEHAVIOR_RESCUE_TARGET)) {
                    CopyYellowMonsterNametoBuffer(buffer, param_2->apparentID);
                }
                else
                CopyCyanMonsterNametoBuffer(buffer, param_2->apparentID);
            }
            else
            {
                sub_808D9DC(buffer, &gRecruitedPokemonRef->dungeonTeam[param_2->teamIndex],colorNum);
            }
        }
    }
}

void sub_8070968(u8 *buffer, EntityInfo *entityInfo, s32 colorNum)
{
    if (entityInfo->curseClassStatus.status == STATUS_DECOY) {
        sprintfStatic(buffer, _("{color}%c%s{reset}"), colorNum + 0x30, gUnknown_80F8974);
    }
    else if (entityInfo->isNotTeamMember) {
        CopyCyanMonsterNametoBuffer(buffer, entityInfo->apparentID);
    }
    else {
        sub_808D9DC(buffer, &gRecruitedPokemonRef->dungeonTeam[entityInfo->teamIndex], colorNum);
    }
}

void sub_80709C8(u8 *buffer, EntityInfo *entityInfo)
{
    if (((gDungeon->unk181e8.blinded ||
          gDungeon->unk181e8.hallucinating) ||
          (entityInfo->invisibleClassStatus.status == STATUS_INVISIBLE)) &&
          (entityInfo->isNotTeamMember))
    {
        strcpy(buffer, gUnknown_80F8994);
    }
    else
    {
        if (entityInfo->curseClassStatus.status == STATUS_DECOY) {
            strcpy(buffer, gUnknown_80F8974);
        }
        else
        {
            if (entityInfo->isNotTeamMember) {
                CopyMonsterNameToBuffer(buffer, entityInfo->apparentID);
            }
            else
            {
                sub_808DA0C(buffer, &gRecruitedPokemonRef->dungeonTeam[entityInfo->teamIndex]);
            }
        }
    }
}

bool8 HasNegativeStatus(Entity *pokemon)
{
    EntityInfo *pokemonInfo = GetEntInfo(pokemon);
    s32 i;
    if (pokemonInfo->sleepClassStatus.status == STATUS_SLEEP ||
        pokemonInfo->sleepClassStatus.status == STATUS_NIGHTMARE ||
        pokemonInfo->sleepClassStatus.status == STATUS_YAWNING ||
        pokemonInfo->burnClassStatus.status != STATUS_NONE ||
        (pokemonInfo->frozenClassStatus.status != STATUS_INGRAIN && pokemonInfo->frozenClassStatus.status != STATUS_NONE) ||
        pokemonInfo->cringeClassStatus.status != STATUS_NONE ||
        pokemonInfo->curseClassStatus.status == STATUS_CURSED ||
        pokemonInfo->curseClassStatus.status == STATUS_DECOY ||
        pokemonInfo->leechSeedClassStatus.status == STATUS_LEECH_SEED ||
        pokemonInfo->sureShotClassStatus.status == STATUS_WHIFFER ||
        pokemonInfo->blinkerClassStatus.status == STATUS_BLINKER ||
        pokemonInfo->blinkerClassStatus.status == STATUS_CROSS_EYED ||
        pokemonInfo->muzzled.muzzled == TRUE ||
        pokemonInfo->exposed ||
        pokemonInfo->perishSongTurns != 0)
    {
        return TRUE;
    }
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        Move *moves = pokemonInfo->moves.moves;
        if (moves[i].moveFlags & MOVE_FLAG_EXISTS && moves[i].moveFlags2 & MOVE_FLAG_SEALED)
        {
            return TRUE;
        }
    }
    for (i = 0; i < NUM_SPEED_COUNTERS; i++)
    {
        if (pokemonInfo->speedDownCounters[i] != 0)
        {
            return TRUE;
        }
    }
    return FALSE;
}

bool8 IsSleeping(Entity *pokemon)
{
    if (GetEntInfo(pokemon)->sleepClassStatus.status != STATUS_SLEEP &&
        GetEntInfo(pokemon)->sleepClassStatus.status != STATUS_NAPPING &&
        GetEntInfo(pokemon)->sleepClassStatus.status != STATUS_NIGHTMARE)
    {
        return FALSE;
    }
    return TRUE;
}

bool8 HasLowHealth(Entity *pokemon)
{
    EntityInfo *pokemonInfo = GetEntInfo(pokemon);
    if (pokemonInfo->HP <= pokemonInfo->maxHPStat / 4)
    {
        return TRUE;
    }
    return FALSE;
}

// TODO CheckVariousStatuses, CheckVariousStatuses2, CheckVariousConditions all check for different conditions that interfere with a Pokémon's ability to act,
// but I'm not sure what the reason is for each function checking the conditions that they do.
// These functions could use better names if someone figures out a clear pattern/reasoning.
bool8 CheckVariousStatuses2(Entity *pokemon, bool8 checkBlinker)
{
    EntityInfo *pokemonInfo = GetEntInfo(pokemon);

    if ((checkBlinker && pokemonInfo->blinkerClassStatus.status == STATUS_BLINKER))
        return TRUE;
    if (pokemonInfo->sleepClassStatus.status == STATUS_SLEEP || pokemonInfo->sleepClassStatus.status == STATUS_NAPPING || pokemonInfo->sleepClassStatus.status == STATUS_NIGHTMARE)
        return TRUE;
    if (pokemonInfo->cringeClassStatus.status == STATUS_PAUSED || pokemonInfo->cringeClassStatus.status == STATUS_INFATUATED)
        return TRUE;
    if (pokemonInfo->frozenClassStatus.status == STATUS_PETRIFIED)
        return TRUE;
    if (pokemonInfo->terrifiedTurns != 0)
        return TRUE;

    return FALSE;
}

bool8 sub_8070BC0(Entity* entity)
{
    EntityInfo *entityInfo = GetEntInfo(entity);

    if (IsChargingAnyTwoTurnMove(entity, FALSE)
        || entityInfo->sleepClassStatus.status == STATUS_YAWNING
        || entityInfo->sleepClassStatus.status == STATUS_NIGHTMARE
        || ShouldMonsterRunAway(entity)
        || entityInfo->muzzled.muzzled == TRUE
        || entityInfo->frozenClassStatus.status == STATUS_PETRIFIED
        || entityInfo->frozenClassStatus.status == STATUS_FROZEN)
        return FALSE;

    if (entityInfo->cringeClassStatus.status == STATUS_CONFUSED)
        return FALSE;
    if (entityInfo->sleepClassStatus.status == STATUS_SLEEP)
        return FALSE;
    if (entityInfo->invisibleClassStatus.status == STATUS_INVISIBLE
        || entityInfo->sleepClassStatus.status == STATUS_NAPPING)
        return FALSE;
    if (entityInfo->cringeClassStatus.status == STATUS_CRINGE)
        return FALSE;
    if (entityInfo->frozenClassStatus.status == STATUS_WRAP)
        return FALSE;
    if (entityInfo->frozenClassStatus.status == STATUS_WRAPPED
        || entityInfo->blinkerClassStatus.status == STATUS_CROSS_EYED)
        return FALSE;
    if (entityInfo->curseClassStatus.status == STATUS_DECOY)
        return FALSE;
    if (entityInfo->blinkerClassStatus.status == STATUS_BLINKER)
        return FALSE;
    if (entityInfo->cringeClassStatus.status != STATUS_INFATUATED
        && entityInfo->cringeClassStatus.status != STATUS_PAUSED)
        return TRUE;

    return FALSE;
}

bool8 CheckVariousConditions(Entity *pokemon)
{
    EntityInfo *pokemonInfo = GetEntInfo(pokemon);

    if (pokemonInfo->monsterBehavior == BEHAVIOR_RESCUE_TARGET
        || IsExperienceLocked(pokemonInfo->joinedAt.id)
        || (!pokemonInfo->isTeamLeader && ShouldMonsterRunAway(pokemon))
        || CheckVariousStatuses2(pokemon, FALSE)
        || CheckVariousStatuses(pokemon))
        return TRUE;

    if (IsChargingAnyTwoTurnMove(pokemon, FALSE))
        return TRUE;

    return FALSE;
}

bool8 CheckVariousStatuses(Entity *pokemon)
{
    EntityInfo *pokemonInfo = GetEntInfo(pokemon);

    if ((pokemonInfo->sleepClassStatus.status != STATUS_SLEEPLESS && pokemonInfo->sleepClassStatus.status != STATUS_NONE))
        return TRUE;
    if (pokemonInfo->frozenClassStatus.status == STATUS_FROZEN || pokemonInfo->frozenClassStatus.status == STATUS_PETRIFIED)
        return TRUE;
    if (pokemonInfo->bideClassStatus.status == STATUS_BIDE)
        return TRUE;

    return FALSE;
}

bool8 CannotAttack(Entity *pokemon, bool8 skipSleep)
{
  EntityInfo *pokemonInfo = GetEntInfo(pokemon);

  if ((skipSleep ||
      pokemonInfo->sleepClassStatus.status == STATUS_SLEEPLESS ||
      pokemonInfo->sleepClassStatus.status == STATUS_YAWNING ||
      pokemonInfo->sleepClassStatus.status == STATUS_NONE) &&
      pokemonInfo->frozenClassStatus.status != STATUS_FROZEN &&
      pokemonInfo->frozenClassStatus.status != STATUS_WRAP &&
      pokemonInfo->frozenClassStatus.status != STATUS_WRAPPED &&
      pokemonInfo->frozenClassStatus.status != STATUS_PETRIFIED &&
      pokemonInfo->cringeClassStatus.status != STATUS_CRINGE &&
      pokemonInfo->cringeClassStatus.status != STATUS_PAUSED &&
      pokemonInfo->cringeClassStatus.status != STATUS_INFATUATED &&
      pokemonInfo->burnClassStatus.status != STATUS_PARALYSIS &&
      !ShouldMonsterRunAway(pokemon))
      return FALSE;

  return TRUE;
}

static const u8 gDirectionBitMasks_1[] = {0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80};
static const u8 gDirectionBitMasks_2[] = {0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80};
static const u8 gDirectionBitMasks_3[] = {0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80};
static const u8 gDirectionBitMasks_4[] = {0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80};
static const u8 gDirectionBitMasks_5[] = {0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80};
static const u8 gDirectionBitMasks_6[] = {0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80};
static const u8 gDirectionBitMasks_7[] = {0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80};

static const u8 gTreatmentData[3][2][2][2] = {
    {
        {
            {TREATMENT_TREAT_AS_ALLY, TREATMENT_IGNORE},
            {TREATMENT_TREAT_AS_ENEMY, TREATMENT_IGNORE}
        },
        {
            {TREATMENT_TREAT_AS_ENEMY, TREATMENT_IGNORE},
            {TREATMENT_TREAT_AS_ALLY, TREATMENT_IGNORE}
        }
    },
    {
        {
            {TREATMENT_TREAT_AS_ALLY, TREATMENT_IGNORE},
            {TREATMENT_TREAT_AS_ENEMY, TREATMENT_IGNORE}
        },
        {
            {TREATMENT_IGNORE, TREATMENT_TREAT_AS_ENEMY},
            {TREATMENT_IGNORE, TREATMENT_TREAT_AS_ENEMY}
        }
    },
    {
        {
            {TREATMENT_IGNORE, TREATMENT_TREAT_AS_ENEMY},
            {TREATMENT_IGNORE, TREATMENT_TREAT_AS_ENEMY}
        },
        {
            {TREATMENT_TREAT_AS_ENEMY, TREATMENT_IGNORE},
            {TREATMENT_TREAT_AS_ALLY, TREATMENT_IGNORE}
        }
    }
};

bool8 CanMoveInDirection(Entity *pokemon, u32 direction)
{
    u8 crossableTerrain = GetCrossableTerrain(GetEntInfo(pokemon)->id);
    const Tile *currentMapTile = GetTile(pokemon->pos.x + gAdjacentTileOffsets[direction].x,
        pokemon->pos.y + gAdjacentTileOffsets[direction].y);

    if (currentMapTile->terrainType & TERRAIN_TYPE_IMPASSABLE_WALL || currentMapTile->monster != NULL)
        return FALSE;

    if (!IsCurrentFixedRoomBossFight())
    {
        if (GetEntInfo(pokemon)->invisibleClassStatus.status == STATUS_MOBILE || HasHeldItem(pokemon, ITEM_MOBILE_SCARF))
            crossableTerrain = CROSSABLE_TERRAIN_WALL;
        else if (IQSkillIsEnabled(pokemon, IQ_ALL_TERRAIN_HIKER))
            crossableTerrain = CROSSABLE_TERRAIN_CREVICE;
        else if (IQSkillIsEnabled(pokemon, IQ_SUPER_MOBILE)) {
            if (direction & 1)
                // Super Mobile can't break walls diagonally.
                crossableTerrain = CROSSABLE_TERRAIN_CREVICE;
            else
                crossableTerrain = CROSSABLE_TERRAIN_WALL;
        }
    }

    currentMapTile = GetTile(pokemon->pos.x, pokemon->pos.y);
    if (!(currentMapTile->walkableNeighborFlags[crossableTerrain] & gDirectionBitMasks_1[direction & DIRECTION_MASK]))
        return FALSE;

    return TRUE;
}

bool8 sub_8070F3C(Entity * pokemon, DungeonPos *pos, s32 direction)
{
  u8 terrain;
  const Tile *tile;

  terrain = GetCrossableTerrain(GetEntInfo(pokemon)->id);

  tile = GetTile(pos->x + gAdjacentTileOffsets[direction].x, pos->y + gAdjacentTileOffsets[direction].y);
  if ((!(tile->terrainType & TERRAIN_TYPE_IMPASSABLE_WALL)) &&
     (((tile->monster == NULL || (GetEntityType(tile->monster) == ENTITY_MONSTER))))) {
    if (!IsCurrentFixedRoomBossFight())
    {
        if (GetEntInfo(pokemon)->invisibleClassStatus.status == STATUS_MOBILE ||
            HasHeldItem(pokemon, ITEM_MOBILE_SCARF))
        {
            terrain = CROSSABLE_TERRAIN_WALL;
        }
        else if (IQSkillIsEnabled(pokemon, IQ_ALL_TERRAIN_HIKER))
        {
            // BUG: If the Pokémon is a Ghost type that can normally attack through walls,
            // All-Terrain Hiker/Super Mobile may make the AI think it can't attack through walls.
            terrain = CROSSABLE_TERRAIN_CREVICE;
        }
        else if (IQSkillIsEnabled(pokemon, IQ_SUPER_MOBILE))
        {
            if ((direction & 1) != 0)
            {
                terrain = CROSSABLE_TERRAIN_CREVICE;
            }
            else
            {
                terrain = CROSSABLE_TERRAIN_WALL;
            }
        }
    }

    tile = GetTile(pos->x, pos->y);

    if (((tile->walkableNeighborFlags[terrain] & gDirectionBitMasks_2[direction & DIRECTION_MASK]))) {
      return TRUE;
    }
  }
  return FALSE;
}

bool8 sub_8070F14(Entity * pokemon, s32 direction)
{
  const Tile *tile;


  tile = GetTile(pokemon->pos.x + gAdjacentTileOffsets[direction].x, pokemon->pos.y + gAdjacentTileOffsets[direction].y);
  if ((!(tile->terrainType & TERRAIN_TYPE_IMPASSABLE_WALL)) &&
     (((tile->monster == NULL)))) {

    tile = GetTile(pokemon->pos.x, pokemon->pos.y);

    if (((tile->walkableNeighborFlags[0] & gDirectionBitMasks_3[direction & DIRECTION_MASK]))) {
      return TRUE;
    }
  }
  return FALSE;
}

bool8 sub_8070F80(Entity * pokemon, s32 direction)
{
  u8 terrain;
  const Tile *tile;

  terrain = GetCrossableTerrain(GetEntInfo(pokemon)->id);

  tile = GetTile(pokemon->pos.x + gAdjacentTileOffsets[direction].x, pokemon->pos.y + gAdjacentTileOffsets[direction].y);
  if ((!(tile->terrainType & TERRAIN_TYPE_IMPASSABLE_WALL)) &&
     (((tile->monster == NULL || (GetEntityType(tile->monster) == ENTITY_MONSTER))))) {
    if (!IsCurrentFixedRoomBossFight())
    {
        if (GetEntInfo(pokemon)->invisibleClassStatus.status == STATUS_MOBILE ||
            HasHeldItem(pokemon, ITEM_MOBILE_SCARF))
        {
            terrain = CROSSABLE_TERRAIN_WALL;
        }
        else if (IQSkillIsEnabled(pokemon, IQ_ALL_TERRAIN_HIKER))
        {
            // BUG: If the Pokémon is a Ghost type that can normally attack through walls,
            // All-Terrain Hiker/Super Mobile may make the AI think it can't attack through walls.
            terrain = CROSSABLE_TERRAIN_CREVICE;
        }
        else if (IQSkillIsEnabled(pokemon, IQ_SUPER_MOBILE))
        {
            if ((direction & 1) != 0)
            {
                terrain = CROSSABLE_TERRAIN_CREVICE;
            }
            else
            {
                terrain = CROSSABLE_TERRAIN_WALL;
            }
        }
    }

    tile = GetTile(pokemon->pos.x, pokemon->pos.y);

    if (((tile->walkableNeighborFlags[terrain] & gDirectionBitMasks_4[direction & DIRECTION_MASK]))) {
      return TRUE;
    }
  }
  return FALSE;
}

UNUSED static bool8 sub_8071058(Entity * pokemon, s32 direction)
{
  u8 terrain;
  const Tile *tile;

  terrain = GetCrossableTerrain(GetEntInfo(pokemon)->id);

  tile = GetTile(pokemon->pos.x + gAdjacentTileOffsets[direction].x, pokemon->pos.y + gAdjacentTileOffsets[direction].y);
  if ((!(tile->terrainType & TERRAIN_TYPE_IMPASSABLE_WALL)) &&
     (((tile->monster == NULL || (GetEntityType(tile->monster) == ENTITY_MONSTER)) ||
      (!GetEntInfo(tile->monster)->isNotTeamMember)))) {
    if (!IsCurrentFixedRoomBossFight())
    {
        if (GetEntInfo(pokemon)->invisibleClassStatus.status == STATUS_MOBILE ||
            HasHeldItem(pokemon, ITEM_MOBILE_SCARF))
        {
            terrain = CROSSABLE_TERRAIN_WALL;
        }
        else if (IQSkillIsEnabled(pokemon, IQ_ALL_TERRAIN_HIKER))
        {
            // BUG: If the Pokémon is a Ghost type that can normally attack through walls,
            // All-Terrain Hiker/Super Mobile may make the AI think it can't attack through walls.
            terrain = CROSSABLE_TERRAIN_CREVICE;
        }
        else if (IQSkillIsEnabled(pokemon, IQ_SUPER_MOBILE))
        {
            if ((direction & 1) != 0)
            {
                terrain = CROSSABLE_TERRAIN_CREVICE;
            }
            else
            {
                terrain = CROSSABLE_TERRAIN_WALL;
            }
        }
    }
    tile = GetTile(pokemon->pos.x, pokemon->pos.y);

    if (((tile->walkableNeighborFlags[terrain] & gDirectionBitMasks_5[direction & DIRECTION_MASK]))) {
      return TRUE;
    }
  }
  return FALSE;
}

bool8 CanAttackInDirection(Entity *pokemon, s32 direction)
{
    u8 crossableTerrain = GetCrossableTerrain(GetEntInfo(pokemon)->id);
    const Tile *tile;
    if (crossableTerrain < CROSSABLE_TERRAIN_CREVICE)
    {
        crossableTerrain = CROSSABLE_TERRAIN_CREVICE;
    }
    tile = GetTile(pokemon->pos.x + gAdjacentTileOffsets[direction].x,
        pokemon->pos.y + gAdjacentTileOffsets[direction].y);
    if (!(tile->terrainType & TERRAIN_TYPE_IMPASSABLE_WALL) &&
        (tile->monster == NULL || GetEntityType(tile->monster) == ENTITY_MONSTER))
    {
        if (!IsCurrentFixedRoomBossFight())
        {
            if (GetEntInfo(pokemon)->invisibleClassStatus.status == STATUS_MOBILE ||
                HasHeldItem(pokemon, ITEM_MOBILE_SCARF))
            {
                crossableTerrain = CROSSABLE_TERRAIN_WALL;
            }
            else if (IQSkillIsEnabled(pokemon, IQ_ALL_TERRAIN_HIKER))
            {
                // BUG: If the Pokémon is a Ghost type that can normally attack through walls,
                // All-Terrain Hiker/Super Mobile may make the AI think it can't attack through walls.
                crossableTerrain = CROSSABLE_TERRAIN_CREVICE;
            }
            else if (IQSkillIsEnabled(pokemon, IQ_SUPER_MOBILE))
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
        tile = GetTile(pokemon->pos.x, pokemon->pos.y);
        if (tile->walkableNeighborFlags[crossableTerrain] & gDirectionBitMasks_6[direction & DIRECTION_MASK])
        {
            return TRUE;
        }
    }
    return FALSE;
}

bool8 CanAIMonsterMoveInDirection(Entity *pokemon, s32 direction, bool8 *pokemonInFront)
{
    u8 crossableTerrain = GetCrossableTerrain(GetEntInfo(pokemon)->id);
    const Tile *currentTile;
    const Tile *frontTile;
    *pokemonInFront = FALSE;
    frontTile = GetTile(pokemon->pos.x + gAdjacentTileOffsets[direction].x,
        pokemon->pos.y + gAdjacentTileOffsets[direction].y);
    if (frontTile->terrainType & TERRAIN_TYPE_IMPASSABLE_WALL)
    {
        return FALSE;
    }
    if (frontTile->terrainType & TERRAIN_TYPE_IN_MONSTER_HOUSE &&
        !gDungeon->unk644.monsterHouseTriggered &&
        IQSkillIsEnabled(pokemon, IQ_HOUSE_AVOIDER))
    {
        return FALSE;
    }
    if (frontTile->object != NULL &&
        IQSkillIsEnabled(pokemon, IQ_TRAP_AVOIDER) &&
        GetEntityType(frontTile->object) == ENTITY_TRAP &&
        (frontTile->object->isVisible || GetEntInfo(pokemon)->blinkerClassStatus.status == STATUS_EYEDROPS))
    {
        return FALSE;
    }
    if ((frontTile->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)) == TERRAIN_TYPE_SECONDARY &&
        gDungeonWaterType[gDungeon->tileset] == DUNGEON_WATER_TYPE_LAVA &&
        IQSkillIsEnabled(pokemon, IQ_LAVA_EVADER))
    {
        return FALSE;
    }
    if (!IsCurrentFixedRoomBossFight())
    {
        if (GetEntInfo(pokemon)->invisibleClassStatus.status == STATUS_MOBILE ||
            HasHeldItem(pokemon, ITEM_MOBILE_SCARF))
        {
            crossableTerrain = CROSSABLE_TERRAIN_WALL;
        }
        else if (IQSkillIsEnabled(pokemon, IQ_ALL_TERRAIN_HIKER))
        {
            // BUG: If the Pokémon is a Ghost type that can normally move through walls,
            // All-Terrain Hiker/Super Mobile may make the AI think it can't move through walls.
            crossableTerrain = CROSSABLE_TERRAIN_CREVICE;
        }
        else if (IQSkillIsEnabled(pokemon, IQ_SUPER_MOBILE))
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
    currentTile = GetTile(pokemon->pos.x, pokemon->pos.y);
    if (currentTile->walkableNeighborFlags[crossableTerrain] & gDirectionBitMasks_7[direction & DIRECTION_MASK])
    {
        if (frontTile->monster == NULL)
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

bool8 IsAtJunction(Entity *pokemon)
{
    u32 crossableTerrain = GetCrossableTerrain(GetEntInfo(pokemon)->id);
    if (!IsCurrentFixedRoomBossFight())
    {
        if (GetEntInfo(pokemon)->invisibleClassStatus.status == STATUS_MOBILE || HasHeldItem(pokemon, ITEM_MOBILE_SCARF))
        {
            crossableTerrain = CROSSABLE_TERRAIN_WALL;
        }
        else if (IQSkillIsEnabled(pokemon, IQ_ALL_TERRAIN_HIKER))
        {
            crossableTerrain = CROSSABLE_TERRAIN_CREVICE;
        }
        else if (IQSkillIsEnabled(pokemon, IQ_SUPER_MOBILE))
        {
            crossableTerrain = CROSSABLE_TERRAIN_WALL;
        }
    }
    if (crossableTerrain == CROSSABLE_TERRAIN_WALL)
    {
        EntityInfo *pokemonInfo = GetEntInfo(pokemon);
        pokemonInfo->mobileTurnTimer += DungeonRandInt(100);
        if (pokemonInfo->mobileTurnTimer < 200)
        {
            return FALSE;
        }
        else
        {
            pokemonInfo->mobileTurnTimer = 0;
        }
    }
    else
    {
        const Tile *mapTile;
        char walkableNeighborFlags;
        if (gDungeonWaterType[gDungeon->tileset] == DUNGEON_WATER_TYPE_LAVA
           && crossableTerrain == CROSSABLE_TERRAIN_LIQUID
           && IQSkillIsEnabled(pokemon, IQ_LAVA_EVADER))
        {
            crossableTerrain = CROSSABLE_TERRAIN_REGULAR;
        }
        mapTile = GetTile(pokemon->pos.x, pokemon->pos.y);
        walkableNeighborFlags = mapTile->walkableNeighborFlags[crossableTerrain];
        /*
        Check for configurations of open tiles that are considered junctions; i.e., shaped like a 'T' or '+'.
        X=Wall, O=Open

        0x54  0x51  0x45  0x15  0x55
        XOX   XOX   XXX   XOX   XOX
        OOO   OOX   OOO   XOO   OOO
        XXX   XOX   XOX   XOX   XOX
        */
        if (walkableNeighborFlags != 0x54 && walkableNeighborFlags != 0x51 && walkableNeighborFlags != 0x45 && walkableNeighborFlags != 0x15 && walkableNeighborFlags != 0x55)
        {
            return FALSE;
        }
    }
    return TRUE;
}

bool8 ShouldAvoidFirstHit(Entity *pokemon, bool8 forceAvoid)
{
    if (!IsTacticSet(pokemon, TACTIC_AVOID_THE_FIRST_HIT))
        return FALSE;
    if (!forceAvoid)
        return FALSE;
    return TRUE;
}

bool8 ShouldMonsterRunAway(Entity *pokemon)
{
    if (!EntityIsValid(pokemon))
    {
        return FALSE;
    }
    else
    {
        EntityInfo *pokemonInfo = GetEntInfo(pokemon);
        if (pokemonInfo->terrifiedTurns != 0)
        {
            return TRUE;
        }
        if (pokemonInfo->isTeamLeader)
        {
            return FALSE;
        }
        if (AbilityIsActive(pokemon, ABILITY_RUN_AWAY))
        {
            bool8 runAwayActive = pokemonInfo->HP < pokemonInfo->maxHPStat / 2;
            if (runAwayActive)
            {
                return TRUE;
            }
        }
        if (IsTacticSet(pokemon, TACTIC_GET_AWAY) ||
            (IsTacticSet(pokemon, TACTIC_AVOID_TROUBLE) && pokemonInfo->HP <= pokemonInfo->maxHPStat / 2))
        {
            return TRUE;
        }
        return FALSE;
    }
}

bool8 ShouldMonsterRunAwayAndShowEffect(Entity *pokemon, bool8 showRunAwayEffect)
{
    if (ShouldMonsterRunAway(pokemon))
    {
        CheckRunAwayVisualFlag(pokemon, showRunAwayEffect);
        return TRUE;
    }
    return FALSE;
}

void CheckRunAwayVisualFlag(Entity *pokemon, bool8 showRunAwayEffect)
{
  bool8 cVar1;
  EntityInfo *iVar2;
  iVar2 = GetEntInfo(pokemon);

  if (((!iVar2->isTeamLeader) && AbilityIsActive(pokemon,ABILITY_RUN_AWAY) &&
      (cVar1 = SetVisualFlags(iVar2,4,iVar2->HP <= iVar2->maxHPStat / 2), showRunAwayEffect)) &&
     (cVar1)) {
    ShowVisualFlags(pokemon);
  }
}

u8 GetTreatmentBetweenMonsters(Entity *pokemon, Entity *targetPokemon, bool8 ignoreInvisible, bool8 checkPetrified)
{
    EntityInfo *pokemonInfo = GetEntInfo(pokemon);
    EntityInfo *targetData = GetEntInfo(targetPokemon);
    u8 decoyAITracker;
    u8 pokemonTargetingDecoy;
    bool8 pokemonIsEnemy;
    bool8 targetIsEnemy;
    bool8 targetIsDecoy;
    if (pokemon == targetPokemon)
    {
        return TREATMENT_TREAT_AS_ALLY;
    }
    if (pokemonInfo->shopkeeper == SHOPKEEPER_MODE_SHOPKEEPER ||
        targetData->shopkeeper == SHOPKEEPER_MODE_SHOPKEEPER ||
        pokemonInfo->monsterBehavior == BEHAVIOR_DIGLETT ||
        targetData->monsterBehavior == BEHAVIOR_DIGLETT ||
        pokemonInfo->monsterBehavior == BEHAVIOR_RESCUE_TARGET ||
        targetData->monsterBehavior == BEHAVIOR_RESCUE_TARGET ||
        (checkPetrified && !pokemonInfo->isNotTeamMember && targetData->frozenClassStatus.status == STATUS_PETRIFIED) ||
        (!ignoreInvisible && targetData->invisibleClassStatus.status == STATUS_INVISIBLE && !CanSeeInvisibleMonsters(pokemon)))
    {
        return TREATMENT_IGNORE;
    }
    pokemonTargetingDecoy = pokemonInfo->decoyAITracker;
    decoyAITracker = DECOY_AI_NONE;
    if (pokemonTargetingDecoy != DECOY_AI_NONE)
    {
        decoyAITracker = DECOY_AI_WILD;
        if (pokemonTargetingDecoy == DECOY_AI_TEAM)
        {
            decoyAITracker = DECOY_AI_TEAM;
        }
    }
    if (pokemonInfo->shopkeeper != SHOPKEEPER_MODE_NORMAL)
    {
        pokemonIsEnemy = FALSE;
        if (pokemonInfo->shopkeeper == SHOPKEEPER_MODE_ATTACK_TEAM)
        {
            pokemonIsEnemy = TRUE;
        }
    }
    else
    {
        pokemonIsEnemy = pokemonInfo->isNotTeamMember ? TRUE : FALSE;
    }
    if (targetData->shopkeeper != SHOPKEEPER_MODE_NORMAL)
    {
        targetIsEnemy = FALSE;
        if (targetData->shopkeeper == SHOPKEEPER_MODE_ATTACK_TEAM)
        {
            targetIsEnemy = TRUE;
        }
    }
    else
    {
        targetIsEnemy = targetData->isNotTeamMember ? TRUE : FALSE;
    }
    targetIsDecoy = FALSE;
    if (targetData->curseClassStatus.status == STATUS_DECOY)
    {
        targetIsDecoy = TRUE;
    }
    return gTreatmentData[decoyAITracker][pokemonIsEnemy][targetIsEnemy][targetIsDecoy];
}

u8 sub_807167C(Entity * pokemon, Entity * target)
{
  bool8 cannotUseItems;
  EntityInfo * targetEntityInfo;
  EntityInfo * pokemonEntityData;

  pokemonEntityData = GetEntInfo(pokemon);
  targetEntityInfo = GetEntInfo(target);
  if (pokemonEntityData->monsterBehavior != BEHAVIOR_RESCUE_TARGET) {
    cannotUseItems = IsExperienceLocked(pokemonEntityData->joinedAt.id);
    if (!cannotUseItems && (pokemonEntityData->shopkeeper == SHOPKEEPER_MODE_NORMAL) && (targetEntityInfo->monsterBehavior != BEHAVIOR_RESCUE_TARGET)) {
      cannotUseItems = IsExperienceLocked(targetEntityInfo->joinedAt.id);
      if (cannotUseItems || (targetEntityInfo->shopkeeper != SHOPKEEPER_MODE_NORMAL)) {
error:
          return TREATMENT_IGNORE;
      }
      else
      {
        if ((pokemonEntityData->isNotTeamMember) != (targetEntityInfo->isNotTeamMember)) {
          return TREATMENT_TREAT_AS_ENEMY;
        }
        else {
          return TREATMENT_TREAT_AS_ALLY;
        }
      }
    }
  }
  goto error;
}

bool8 HasSafeguardStatus(Entity * pokemon, Entity * target, bool8 displayMessage)
{
  if (GetEntInfo(target)->reflectClassStatus.status == STATUS_SAFEGUARD) {
    if (displayMessage) {
      SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC2FC);
    }
    return TRUE;
  }
  return FALSE;
}

bool8 sub_8071728(Entity * pokemon, Entity * target, bool8 displayMessage)
{
  if (GetEntInfo(target)->reflectClassStatus.status == STATUS_MIST) {
    if (displayMessage) {
      SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], target, 0);
      TryDisplayDungeonLoggableMessage3(pokemon, target, gUnknown_80FC31C);
    }
    return TRUE;
  }
  else {
    if (AbilityIsActive(target, ABILITY_CLEAR_BODY) || AbilityIsActive(target, ABILITY_WHITE_SMOKE)) {
        if (displayMessage) {
            SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], target, 0);
            TryDisplayDungeonLoggableMessage3(pokemon, target, gUnknown_80FCEFC);
        }
        return TRUE;
    }
  }
  return FALSE;
}

bool8 sub_80717A4(Entity *pokemon, u16 moveID)
{
    EntityInfo * entityInfo;
    s32 i;

    entityInfo = GetEntInfo(pokemon);
    if ((entityInfo->sleepClassStatus.status != STATUS_SLEEP) && (entityInfo->sleepClassStatus.status != STATUS_NAPPING) && (entityInfo->sleepClassStatus.status != STATUS_NIGHTMARE)) {
        return FALSE;
    }
    else {
        for (i = 0; i < MAX_MON_MOVES; i++) {
            Move *move = &entityInfo->moves.moves[i];
            if (MoveFlagExists(move)
                && (entityInfo->isTeamLeader || (move->moveFlags & MOVE_FLAG_ENABLED_FOR_AI))
                && sub_805744C(pokemon, move, TRUE)
                && move->PP != 0
                && move->id == moveID)
            {
                return TRUE;
            }
        }
    }

    return FALSE;
}

bool8 AbilityIsActive(Entity *pokemon, u8 ability)
{
    if (!EntityIsValid(pokemon))
    {
        return FALSE;
    }
    else
    {
        EntityInfo *pokemonInfo = GetEntInfo(pokemon);
        if (pokemonInfo->abilities[0] == ability || pokemonInfo->abilities[1] == ability)
        {
            return TRUE;
        }
        return FALSE;
    }
}

bool8 MonsterIsType(Entity *pokemon, u8 type)
{
    EntityInfo *pokemonInfo = pokemonInfo = GetEntInfo(pokemon);
    if (type == TYPE_NONE)
    {
        return FALSE;
    }
    if (pokemonInfo->types[0] == type)
    {
        return TRUE;
    }
    if (pokemonInfo->types[1] == type)
    {
        return TRUE;
    }
    return FALSE;
}

bool8 CanSeeInvisibleMonsters(Entity *pokemon)
{
    EntityInfo *pokemonInfo = GetEntInfo(pokemon);
    if (pokemonInfo->blinkerClassStatus.status != STATUS_EYEDROPS)
    {
        if (!HasHeldItem(pokemon, ITEM_GOGGLE_SPECS))
            return FALSE;
        else
            return TRUE;
    }
    else
        return TRUE;
}

bool8 IsTacticSet(Entity *pokemon, u8 tactic)
{
    EntityInfo *pokemonInfo = GetEntInfo(pokemon);
    if (pokemonInfo->isTeamLeader)
    {
        bool8 isGoTheOtherWay = tactic == TACTIC_GO_THE_OTHER_WAY;
        return isGoTheOtherWay;
    }
    return pokemonInfo->tactic == tactic;
}

bool8 IQSkillIsEnabled(Entity *pokemon, u8 IQSkill)
{
    return IsIQSkillSet(&GetEntInfo(pokemon)->IQSkillFlags, 1 << IQSkill);
}

UNUSED static bool8 IQSkillPairIsEnabled(Entity *pokemon, u8 IQSkill1, u8 IQSkill2)
{
    return IsIQSkillSet(&GetEntInfo(pokemon)->IQSkillFlags, 1 << IQSkill1 | 1 << IQSkill2);
}

void LoadIQSkills(Entity *pokemon)
{
  s32 IQSkill;
  EntityInfo *pokemonInfo;

  pokemonInfo = GetEntInfo(pokemon);
  if (pokemonInfo->isNotTeamMember) {
    IqSkillFlags *iqSkills = &pokemonInfo->IQSkillFlags;
    SetIQSkill(iqSkills, IQ_STATUS_CHECKER);
    SetIQSkill(iqSkills, IQ_PP_CHECKER);
    SetIQSkill(iqSkills, IQ_ITEM_CATCHER);
    if (pokemonInfo->bossFlag)
      SetIQSkill(iqSkills, IQ_SELF_CURER);
    if (pokemonInfo->level >= gIqItemMasterMinWildLevel)
      SetIQSkill(iqSkills, IQ_ITEM_MASTER);
    pokemonInfo->tactic = TACTIC_GO_AFTER_FOES;
  }
  else {
    pokemonInfo->IQSkillFlags.flags[0] = 0;
    pokemonInfo->IQSkillFlags.flags[1] = 0;
    pokemonInfo->IQSkillFlags.flags[2] = 0;
    for(IQSkill = IQ_TYPE_ADVANTAGE_MASTER; IQSkill < NUM_IQ_SKILLS; IQSkill++)
    {
      if (HasIQForSkill(pokemonInfo->IQ,IQSkill) &&
            IsIQSkillSet(&pokemonInfo->IQSkillMenuFlags, 1 << IQSkill))
        {
            SetIQSkill(&pokemonInfo->IQSkillFlags,IQSkill);
      }
    }
  }
}

bool8 CanSeeTeammate(Entity * pokemon)
{
  Entity *teamMember;
  s32 memberIdx;

  if (GetEntInfo(pokemon)->isNotTeamMember) {
      return FALSE;
  }
  else
  {
    for(memberIdx = 0; memberIdx < MAX_TEAM_MEMBERS; memberIdx++)
    {
      teamMember = gDungeon->teamPokemon[memberIdx];
      if (EntityIsValid(pokemon) && (pokemon != teamMember) && (CanSeeTarget(pokemon,teamMember)))
      {
        return TRUE;
      }
    }
    return FALSE;
  }
}

u8 GetMoveTypeForMonster(Entity *pokemon, Move *pokeMove)
{
    if (pokeMove->id == MOVE_HIDDEN_POWER)
        return GetEntInfo(pokemon)->hiddenPower.hiddenPowerType;
    else
        return GetMoveType(pokeMove);
}

s32 GetMovePower(Entity *pokemon, Move *pokeMove)
{
    if(pokeMove->id == MOVE_HIDDEN_POWER)
        return (GetEntInfo(pokemon)->hiddenPower.hiddenPowerBasePower + pokeMove->ginseng);
    else
        return (GetMoveBasePower(pokeMove) + pokeMove->ginseng);
}

bool8 MonsterCanThrowItems(EntityInfo *pokemon)
{
    if(!MonsterIDCanThrowItems(pokemon->id))
        return FALSE;
    return TRUE;
}

bool8 sub_8071A8C(Entity *pokemon)
{
    EntityInfo *pokemonInfo;
    if(EntityIsValid(pokemon))
    {
        pokemonInfo = GetEntInfo(pokemon);
        if(pokemonInfo->monsterBehavior != BEHAVIOR_RESCUE_TARGET)
        {
            if(!IsExperienceLocked(pokemonInfo->joinedAt.id))
                return TRUE;
        }
    }
    return FALSE;
}

bool8 SetVisualFlags(EntityInfo *entityInfo, u16 newFlag, bool8 param_3)
{
  if ((entityInfo->visualFlags & newFlag)) {
    entityInfo->previousVisualFlags = newFlag | entityInfo->previousVisualFlags;
  }
  else {
    entityInfo->previousVisualFlags = entityInfo->previousVisualFlags & ~newFlag;
  }

  if (param_3) {
    entityInfo->visualFlags = newFlag | entityInfo->visualFlags;
  }
  else {
    entityInfo->visualFlags = entityInfo->visualFlags & ~newFlag;
  }
  if ( ((entityInfo->previousVisualFlags & newFlag) == 0) && ((entityInfo->visualFlags & newFlag)) ) {
    return TRUE;
  }
  else {
    return FALSE;
  }
}
