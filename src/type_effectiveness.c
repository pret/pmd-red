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

u32 gTypeEffectivenessMultipliers[] = {0, 1, 2, 4};


struct unkStruct_806D010
{   
    s32 unk0;
    u32 unk4;
    u32 unk8;
    u8 unkC;
    u8 unkD;
    u8 unkE;
    u8 unkF;
};

struct dumb_struct 
{
    u32 *unk0[4];
};
extern struct dumb_struct gUnknown_8106F54;


extern u32 gUnknown_8106F0C;
extern u32 gUnknown_8106F1C;
extern u32 gUnknown_8106F14;
extern u32 gUnknown_8106F64;
extern u32 gUnknown_8106EFC[2];

extern u8 *gUnknown_80FEDE8[];
extern u8 *gUnknown_80FEDC8[];
extern u8 *gUnknown_80FEDA8[];
extern u8 *gUnknown_80FED88[];

extern s32 gUnknown_80F54B4[2][4];

void sub_80522F4(Entity *, Entity *, u8 *);
void sub_80428D8(Entity *);
void sub_8042978(Entity *);
void sub_804298C(Entity *);
u8 sub_800A2A0(s32 *);
void sub_800A34C(s32 *, s32 *, s32 *);
void sub_800A020(s32 *, u32);
void sub_80428EC(Entity *);

bool8 sub_806E100(s32 *param_1, Entity *pokemon, Entity *target, u8 type, struct unkStruct_806D010 *param_5)
{
  bool8 bVar1;
  bool8 bVar2;
  bool8 bVar3;
  bool8 bVar5;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  bool8 bVar4;
  EntityInfo *targetInfo;
  s32 effectiveness;
  s32 index;
  struct dumb_struct local_48;
  s32 local_38 [2];
  s32 local_2c;
  s32 local_28;
  EntityInfo *pokemonInfo;
  u8 weather;
  s32 temp;

  bVar4 = FALSE;
  local_28 = FALSE;
  pokemonInfo = pokemon->info;
  targetInfo = target->info;
  sub_800A020(param_1,1);
  param_5->unkD = 0;
  param_5->unkE = 0;
  local_2c = FALSE;
  if (!EntityExists(target)) {
    return TRUE;
  }
  else {
    if ((type == TYPE_NORMAL) || (type == TYPE_FIGHTING)) {
      local_28 = TRUE;
    }
    if ((HasAbility(target, ABILITY_WONDER_GUARD)) && (type != TYPE_NONE)) {
      local_2c = TRUE;
    }
    param_5->unk8 = 2;
    for (index = 0; index < 2; index++) {
      local_48 = gUnknown_8106F54;
      if (sub_800A2A0(param_1) != '\0') break;
      if (((local_28) && (targetInfo->types[index] == TYPE_GHOST)) && (targetInfo->exposed == FALSE)) {
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

    param_5->unk8 = gUnknown_80F54B4[local_38[0]][local_38[1]];
    bVar4 = TRUE;
    if ((param_5->unk8 != 3) && (bVar4 = FALSE, local_2c != 0)) {
      temp = gUnknown_8106EFC[1];
      param_1[0] = gUnknown_8106EFC[0];
      param_1[1] = temp;
    }
      
    if (((type == TYPE_FIRE) || (type == TYPE_ICE)) && (HasAbility(target,ABILITY_THICK_FAT))) {
      gDungeon->unk16D = TRUE;
      sub_800A34C(param_1,param_1,&gUnknown_8106F1C);
    }
    if ((type == TYPE_FIRE) && (GetFlashFireStatus(target) != '\0')) {
      gDungeon->fill16E[0] = TRUE;
      sub_800A020(param_1,0);
      param_5->unk8 = 0;
      param_5->unkD = 0;
      param_5->unkE = 1;
      bVar4 = '\0';
    }
    if ((type == TYPE_GROUND) && (HasAbility(target, ABILITY_LEVITATE))) {
      gDungeon->fill16E[1] = TRUE;
      sub_800A020(param_1,0);
      param_5->unk8 = 0;
      param_5->unkD = 0;
      param_5->unkE = 1;
      bVar4 = '\0';
    }
    if ((type == TYPE_WATER) && (HasAbility(pokemon, ABILITY_TORRENT))) {
      bVar1 = pokemonInfo->maxHPStat / 4 >= pokemonInfo->HP;
      cVar3 = SetVisualFlags(pokemonInfo,0x80,bVar1);
      if (bVar1) {
        gDungeon->fill16E[2] = TRUE;
        sub_800A34C(param_1,param_1,&gUnknown_8106F0C);
      }
      if (cVar3 != '\0') {
        sub_80428EC(pokemon);
        sub_80522F4(pokemon,target,*gUnknown_80FEDA8);
      }
    }
    if ((type == TYPE_GRASS) && (HasAbility(pokemon, ABILITY_OVERGROW))) {
      bVar2 = pokemonInfo->maxHPStat / 4 >= pokemonInfo->HP;
      cVar4 = SetVisualFlags(pokemonInfo,2,bVar2);
      if (bVar2) {
        gDungeon->fill16E[3] = TRUE;
        sub_800A34C(param_1,param_1,&gUnknown_8106F0C);
      }
      if (cVar4 != '\0') {
        sub_80428D8(pokemon);
        sub_80522F4(pokemon,target,*gUnknown_80FED88);
      }
    }
    if ((type == TYPE_BUG) && (HasAbility(pokemon, ABILITY_SWARM))) {
      bVar3 = pokemonInfo->maxHPStat / 4 >= pokemonInfo->HP;
      cVar5 = SetVisualFlags(pokemonInfo,0x10,bVar3);
      if (bVar3) {
        gDungeon->fill16E[4] = TRUE;
        sub_800A34C(param_1,param_1,&gUnknown_8106F0C);
      }
      if (cVar5 != '\0') {
        sub_8042978(pokemon);
        sub_80522F4(pokemon,target,*gUnknown_80FEDC8);
      }
    }
    if ((type == TYPE_FIRE) && (HasAbility(pokemon, ABILITY_BLAZE))) {
      bVar5 = pokemonInfo->maxHPStat / 4 >= pokemonInfo->HP;
      cVar6 = SetVisualFlags(pokemonInfo,0x20,bVar5);
      if (bVar5) {
        gDungeon->fill16E[5] = TRUE;
        sub_800A34C(param_1,param_1,&gUnknown_8106F0C);
      }
      if (cVar6 != '\0') {
        sub_804298C(pokemon);
        sub_80522F4(pokemon,target,*gUnknown_80FEDE8);
      }
    }
    if ((sub_800A2A0(param_1) == '\0') && (MonsterIsType(pokemon, type))) {
      gDungeon->fill16E[6] = TRUE;
      sub_800A34C(param_1,param_1,&gUnknown_8106F14);
    }
    weather = GetApparentWeather(pokemon);      
    if (weather == WEATHER_SUNNY) {
      if (type == TYPE_FIRE) {
        gDungeon->unk16C = TRUE;
        sub_800A34C(param_1,param_1,&gUnknown_8106F14);
      }
      else if (type == TYPE_WATER) {
        gDungeon->unk16C = TRUE;
        sub_800A34C(param_1,param_1,&gUnknown_8106F1C);
      }
    }
    if (weather == WEATHER_RAIN) {
      if (type == TYPE_FIRE) {
        gDungeon->unk16B = TRUE;
        sub_800A34C(param_1,param_1,&gUnknown_8106F1C);
      }
      else if (type == TYPE_WATER) {
        gDungeon->unk16B = TRUE;
        sub_800A34C(param_1,param_1,&gUnknown_8106F14);
      }
    }
    if ((weather == WEATHER_CLOUDY) && (type != TYPE_NORMAL)) {
      sub_800A34C(param_1,param_1,&gUnknown_8106F64);
      gDungeon->unk16A = TRUE;
    }
    if (((gDungeon->mudSportTurns != 0) || (weather == WEATHER_FOG)) && (type == TYPE_ELECTRIC)) {
      gDungeon->fill16E[7] = TRUE;
      sub_800A34C(param_1,param_1,&gUnknown_8106F1C);
    }
    if ((gDungeon->waterSportTurns != 0) && (type == TYPE_FIRE)) {
      gDungeon->fill16E[8] = TRUE;
      sub_800A34C(param_1,param_1,&gUnknown_8106F1C);
    }
    if ((type == TYPE_ELECTRIC) && (pokemonInfo->charging.chargingStatus == STATUS_CHARGING)) {
      gDungeon->fill16E[9] = TRUE;
      sub_800A34C(param_1,param_1,&gUnknown_8106F0C);
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
    userData = user->info;
    targetData = target->info;
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
    if (gDungeon->mudSportTurns != 0 && moveType == TYPE_ELECTRIC)
    {
        return 2;
    }
    if (gDungeon->waterSportTurns != 0 && moveType == TYPE_FIRE)
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
