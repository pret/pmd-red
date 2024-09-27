#include "global.h"
#include "type_effectiveness.h"

#include "constants/ability.h"
#include "constants/status.h"
#include "constants/weather.h"
#include "structs/str_dungeon.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_util.h"
#include "status.h"
#include "type_chart.h"
#include "weather.h"


u32 gUnknown_8106EFC[] = { 0x00, 0x00  };
u8 gUnknown_8106F04[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00 };
u8 gUnknown_8106F0C[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00 };
u8 gUnknown_8106F14[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00 };
u8 gUnknown_8106F1C[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00 };
u8 gUnknown_8106F24[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe7, 0x03,
                          0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0xfe, 0x7f, 0x01, 0x00 };
u8 gUnknown_8106F3C[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00};
u8 gUnknown_8106F44[] = {0x00, 0x00, 0x00, 0x00, 0x66, 0xe6, 0x00, 0x00};
u8 gUnknown_8106F4C[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00};


struct dumb_struct 
{
    u8 *unk0[NUM_EFFECTIVENESS];
};

struct dumb_struct gUnknown_8106F54 = {
        gUnknown_8106F3C, // IMMUNE
        gUnknown_8106F44, // RESIST
        gUnknown_8106F04, // NEUTRAL
        gUnknown_8106F4C, // SUPER
};

u8 gUnknown_8106F64[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x00};
u32 gTypeEffectivenessMultipliers[] = {0, 1, 2, 4};


struct unkStruct_806D010
{   
    s32 unk0;
    u32 unk4;
    u32 effectiveness;
    u8 unkC;
    u8 unkD;
    u8 unkE;
    u8 unkF;
};

extern u8 *gUnknown_80FEDE8[];
extern u8 *gUnknown_80FEDC8[];
extern u8 *gUnknown_80FEDA8[];
extern u8 *gUnknown_80FED88[];

extern s32 gUnknown_80F54B4[NUM_EFFECTIVENESS][NUM_EFFECTIVENESS];

void sub_80522F4(Entity *, Entity *, u8 *);
void sub_80428D8(Entity *);
void sub_8042978(Entity *);
void sub_804298C(Entity *);
bool8 sub_800A2A0(s32 *);
void sub_800A34C(s32 *, s32 *, const u8 *);
void sub_800A020(s32 *, u32);
void sub_80428EC(Entity *);

bool8 sub_806E100(s32 *param_1, Entity *pokemon, Entity *target, u8 type, struct unkStruct_806D010 *param_5)
{
  bool8 torrentFlag;
  bool8 overgrowFlag;
  bool8 swarmFlag;
  bool8 blazeFlag;
  bool8 torrentVisualFlag;
  bool8 overgrowVisualFlag;
  bool8 swarmVisualFlag;
  bool8 blazeVisualFlag;
  bool8 bVar4;
  EntityInfo *targetInfo;
  s32 effectiveness;
  s32 index;
  struct dumb_struct local_48;
  s32 local_38 [2];
  s32 hasWonderGuard;
  s32 normalOrFightingType;
  EntityInfo *pokemonInfo;
  u8 weather;
  s32 temp;

  bVar4 = FALSE;
  normalOrFightingType = FALSE;
  pokemonInfo = pokemon->axObj.info;
  targetInfo = target->axObj.info;
  sub_800A020(param_1,1);
  param_5->unkD = 0;
  param_5->unkE = 0;
  hasWonderGuard = FALSE;
  if (!EntityExists(target)) {
    return TRUE;
  }
  else {
    if ((type == TYPE_NORMAL) || (type == TYPE_FIGHTING)) {
      normalOrFightingType = TRUE;
    }
    if ((HasAbility(target, ABILITY_WONDER_GUARD)) && (type != TYPE_NONE)) {
      hasWonderGuard = TRUE;
    }
    param_5->effectiveness = EFFECTIVENESS_NEUTRAL;
    for (index = 0; index < 2; index++) {
      local_48 = gUnknown_8106F54;
      if (sub_800A2A0(param_1)) break;
      if (((normalOrFightingType) && (targetInfo->types[index] == TYPE_GHOST)) && (targetInfo->exposed == FALSE)) {
            effectiveness = EFFECTIVENESS_IMMUNE;
            gDungeon->pokemonExposed = TRUE;
      }
      else {
            effectiveness = gTypeEffectivenessChart[type][targetInfo->types[index]];  
      }
      if (effectiveness != EFFECTIVENESS_NEUTRAL) {
        sub_800A34C(param_1,param_1,local_48.unk0[effectiveness]);
      }
      local_38[index] = effectiveness;
      gDungeon->unk13C[index] = effectiveness;
    }

    param_5->effectiveness = gUnknown_80F54B4[local_38[0]][local_38[1]];
    bVar4 = TRUE;
    if ((param_5->effectiveness != EFFECTIVENESS_SUPER) && (bVar4 = FALSE, hasWonderGuard)) {
      temp = gUnknown_8106EFC[1];
      param_1[0] = gUnknown_8106EFC[0];
      param_1[1] = temp;
    }
      
    if (((type == TYPE_FIRE) || (type == TYPE_ICE)) && (HasAbility(target,ABILITY_THICK_FAT))) {
      gDungeon->unk16D = TRUE;
      sub_800A34C(param_1,param_1,gUnknown_8106F1C);
    }
    if ((type == TYPE_FIRE) && (GetFlashFireStatus(target) != FLASH_FIRE_STATUS_NONE)) {
      gDungeon->fill16E[0] = TRUE;
      sub_800A020(param_1,0);
      param_5->effectiveness = EFFECTIVENESS_IMMUNE;
      param_5->unkD = 0;
      param_5->unkE = 1;
      bVar4 = FALSE;
    }
    if ((type == TYPE_GROUND) && (HasAbility(target, ABILITY_LEVITATE))) {
      gDungeon->fill16E[1] = TRUE;
      sub_800A020(param_1,0);
      param_5->effectiveness = EFFECTIVENESS_IMMUNE;
      param_5->unkD = 0;
      param_5->unkE = 1;
      bVar4 = FALSE;
    }
    if ((type == TYPE_WATER) && (HasAbility(pokemon, ABILITY_TORRENT))) {
      torrentFlag = pokemonInfo->maxHPStat / 4 >= pokemonInfo->HP;
      torrentVisualFlag = SetVisualFlags(pokemonInfo,0x80,torrentFlag);
      if (torrentFlag) {
        gDungeon->fill16E[2] = TRUE;
        sub_800A34C(param_1,param_1,gUnknown_8106F0C);
      }
      if (torrentVisualFlag) {
        sub_80428EC(pokemon);
        sub_80522F4(pokemon,target,*gUnknown_80FEDA8);
      }
    }
    if ((type == TYPE_GRASS) && (HasAbility(pokemon, ABILITY_OVERGROW))) {
      overgrowFlag = pokemonInfo->maxHPStat / 4 >= pokemonInfo->HP;
      overgrowVisualFlag = SetVisualFlags(pokemonInfo,2,overgrowFlag);
      if (overgrowFlag) {
        gDungeon->fill16E[3] = TRUE;
        sub_800A34C(param_1,param_1,gUnknown_8106F0C);
      }
      if (overgrowVisualFlag) {
        sub_80428D8(pokemon);
        sub_80522F4(pokemon,target,*gUnknown_80FED88);
      }
    }
    if ((type == TYPE_BUG) && (HasAbility(pokemon, ABILITY_SWARM))) {
      swarmFlag = pokemonInfo->maxHPStat / 4 >= pokemonInfo->HP;
      swarmVisualFlag = SetVisualFlags(pokemonInfo,0x10,swarmFlag);
      if (swarmFlag) {
        gDungeon->fill16E[4] = TRUE;
        sub_800A34C(param_1,param_1,gUnknown_8106F0C);
      }
      if (swarmVisualFlag) {
        sub_8042978(pokemon);
        sub_80522F4(pokemon,target,*gUnknown_80FEDC8);
      }
    }
    if ((type == TYPE_FIRE) && (HasAbility(pokemon, ABILITY_BLAZE))) {
      blazeFlag = pokemonInfo->maxHPStat / 4 >= pokemonInfo->HP;
      blazeVisualFlag = SetVisualFlags(pokemonInfo,0x20,blazeFlag);
      if (blazeFlag) {
        gDungeon->fill16E[5] = TRUE;
        sub_800A34C(param_1,param_1,gUnknown_8106F0C);
      }
      if (blazeVisualFlag) {
        sub_804298C(pokemon);
        sub_80522F4(pokemon,target,*gUnknown_80FEDE8);
      }
    }
    if (!(sub_800A2A0(param_1)) && (MonsterIsType(pokemon, type))) {
      gDungeon->fill16E[6] = TRUE;
      sub_800A34C(param_1,param_1,gUnknown_8106F14);
    }
    weather = GetApparentWeather(pokemon);      
    if (weather == WEATHER_SUNNY) {
      if (type == TYPE_FIRE) {
        gDungeon->unk16C = TRUE;
        sub_800A34C(param_1,param_1,gUnknown_8106F14);
      }
      else if (type == TYPE_WATER) {
        gDungeon->unk16C = TRUE;
        sub_800A34C(param_1,param_1,gUnknown_8106F1C);
      }
    }
    if (weather == WEATHER_RAIN) {
      if (type == TYPE_FIRE) {
        gDungeon->unk16B = TRUE;
        sub_800A34C(param_1,param_1,gUnknown_8106F1C);
      }
      else if (type == TYPE_WATER) {
        gDungeon->unk16B = TRUE;
        sub_800A34C(param_1,param_1,gUnknown_8106F14);
      }
    }
    if ((weather == WEATHER_CLOUDY) && (type != TYPE_NORMAL)) {
      sub_800A34C(param_1,param_1, gUnknown_8106F64);
      gDungeon->unk16A = TRUE;
    }
    if (((gDungeon->weather.mudSportTurns != 0) || (weather == WEATHER_FOG)) && (type == TYPE_ELECTRIC)) {
      gDungeon->fill16E[7] = TRUE;
      sub_800A34C(param_1,param_1,gUnknown_8106F1C);
    }
    if ((gDungeon->weather.waterSportTurns != 0) && (type == TYPE_FIRE)) {
      gDungeon->fill16E[8] = TRUE;
      sub_800A34C(param_1,param_1,gUnknown_8106F1C);
    }
    if ((type == TYPE_ELECTRIC) && (pokemonInfo->charging.chargingStatus == STATUS_CHARGING)) {
      gDungeon->fill16E[9] = TRUE;
      sub_800A34C(param_1,param_1,gUnknown_8106F0C);
    }
  }
  return bVar4;
}

s32 WeightWeakTypePicker(Entity *user, Entity *target, u8 moveType)
{
    s32 weight = 1;
    bool8 checkExposed = FALSE;
    EntityInfo *userData;
    EntityInfo *targetData;
    u8 *targetTypes;
    u8 *targetType;
    u32 moveTypeOffset;
    if (!EntityExists(target))
    {
        return 1;
    }
    if (moveType == TYPE_NORMAL || moveType == TYPE_FIGHTING)
    {
        checkExposed = TRUE;
    }
    userData = user->axObj.info;
    targetData = target->axObj.info;
    if (moveType == TYPE_FIRE && GetFlashFireStatus(target) != FLASH_FIRE_STATUS_NONE)
    {
        return 0;
    }
    if (moveType == TYPE_ELECTRIC && HasAbility(target, ABILITY_VOLT_ABSORB))
    {
        return 0;
    }
    if (moveType == TYPE_WATER && HasAbility(target, ABILITY_WATER_ABSORB))
    {
        return 0;
    }
    if (moveType == TYPE_GROUND && HasAbility(target, ABILITY_LEVITATE))
    {
        return 1;
    }
    targetTypes = targetData->types;
    moveTypeOffset = moveType * NUM_TYPES * sizeof(s16);
    targetType = targetData->types;
    do
    {
        s32 effectiveness;
        u32 typeEffectivenessMultipliers[NUM_EFFECTIVENESS];
        memcpy(typeEffectivenessMultipliers, gTypeEffectivenessMultipliers, NUM_EFFECTIVENESS * sizeof(u32));
        if (checkExposed && *targetType == TYPE_GHOST && !targetData->exposed)
        {
            effectiveness = 0;
            gDungeon->pokemonExposed = TRUE;
        }
        else
        {
            effectiveness = gTypeEffectivenessChart[moveType][*targetType];
            // Used to swap variable initialization order at the loop start.
            effectiveness = *(s16*)(((s8*) gTypeEffectivenessChart) + moveTypeOffset + *targetType * 2);
        }
        if (weight == 0)
        {
            goto breakLoop;
        }
        weight *= typeEffectivenessMultipliers[effectiveness];
        weight /= 2;
        if (weight == 0)
        {
            // BUG: If the Pokémon's first type resists the move, the second type is ignored.
            // This calculates type effectiveness incorrectly if the first type resists the move and the second type is weak to the move.
            // For example, a Fire-type move is considered not very effective against a Rock/Bug-type like Anorith.
            return 2;
        }
    } while ((s32)(++targetType) <= (s32)(targetTypes + 1));
    breakLoop:
    if ((moveType == TYPE_FIRE || moveType == TYPE_ICE) && HasAbility(target, ABILITY_THICK_FAT))
    {
        return 2;
    }
    if (moveType == TYPE_WATER && HasAbility(user, ABILITY_TORRENT))
    {
        s32 maxHPStat = userData->maxHPStat;
        if (maxHPStat < 0)
        {
            maxHPStat += 3;
        }
        if (maxHPStat >> 2 >= userData->HP)
        {
            weight *= 2;
        }
    }
    if (moveType == TYPE_GRASS && HasAbility(user, ABILITY_OVERGROW))
    {
        s32 maxHPStat = userData->maxHPStat;
        if (maxHPStat < 0)
        {
            maxHPStat += 3;
        }
        if (maxHPStat >> 2 >= userData->HP)
        {
            weight *= 2;
        }
    }
    if (moveType == TYPE_BUG && HasAbility(user, ABILITY_SWARM))
    {
        s32 maxHPStat = userData->maxHPStat;
        if (maxHPStat < 0)
        {
            maxHPStat += 3;
        }
        if (maxHPStat >> 2 >= userData->HP)
        {
            weight *= 2;
        }
    }
    if (moveType == TYPE_FIRE && HasAbility(user, ABILITY_BLAZE))
    {
        s32 maxHPStat = userData->maxHPStat;
        if (maxHPStat < 0)
        {
            maxHPStat += 3;
        }
        if (maxHPStat >> 2 >= userData->HP)
        {
            weight *= 2;
        }
    }
    if (weight == 0)
    {
        return 2;
    }
    if (MonsterIsType(user, moveType))
    {
        weight *= 2;
    }
    targetTypes = targetData->types;
    if (GetApparentWeather(user) == WEATHER_SUNNY)
    {
        if (moveType == TYPE_FIRE)
        {
            weight *= 2;
        }
        else if (moveType == TYPE_WATER)
        {
            return 2;
        }
    }
    if (gDungeon->weather.mudSportTurns != 0 && moveType == TYPE_ELECTRIC)
    {
        return 2;
    }
    if (gDungeon->weather.waterSportTurns != 0 && moveType == TYPE_FIRE)
    {
        return 2;
    }
    if (moveType == TYPE_ELECTRIC && userData->charging.chargingStatus == STATUS_CHARGING)
    {
        weight *= 2;
    }
    if (weight > 2)
    {
        weight = 3;
    }
    return weight + 2;
}
