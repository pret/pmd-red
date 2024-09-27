#include "global.h"
#include "code_803E46C.h"
#include "code_803E668.h"
#include "code_8045A00.h"
#include "constants/ability.h"
#include "constants/move_id.h"
#include "constants/status.h"
#include "constants/type.h"
#include "constants/weather.h"
#include "dungeon_map_access.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "game_options.h"
#include "move_effects_target.h"
#include "pokemon.h"
#include "structs/dungeon_entity.h"
#include "structs/str_dungeon.h"
#include "text_util.h"
#include "weather.h"

struct unkStruct_80F520C
{
    u8 unk0;
    u8 unk1;
    s16 unk2;
};

extern struct unkStruct_80F520C gUnknown_80F520C[];

extern u8 gAvailablePokemonNames[];
extern u8 gFormatItems[];
extern u8 gUnknown_80F51E4[];
extern u8 *gUnknown_80FCC7C[];
extern u8 *gUnknown_80FCCAC[];
extern u8 *gUnknown_80FDCC8[];

void sub_80522F4(Entity *r0, Entity *r1, const char r2[]);
extern void sub_8042900(Entity *r0);
extern void sub_8042968(Entity *r0);
extern void sub_806ABAC(Entity *, Entity *);
void sub_8041BBC(Entity *r0);
extern bool8 sub_8045888(Entity *);
extern void sub_806A2BC(Entity *, u8);
extern void sub_804178C(u32);
extern void sub_803F508(Entity *);

void sub_8069E0C(Entity *pokemon)
{
  s32 index;
  EntityInfo *entityInfo;

  entityInfo = pokemon->axObj.info;
  if (HasAbility(pokemon, ABILITY_FORECAST)) {
    entityInfo->types[0] = gUnknown_80F520C[GetApparentWeather(pokemon)].unk0;
    entityInfo->types[1] = TYPE_NONE;
  }
  else {
    for(index = 0; index < 2; index++)
      entityInfo->types[index] = GetPokemonType(entityInfo->id, index);
  }
  for(index = 0; index < 2; index++)
    entityInfo->abilities[index] = GetPokemonAbility(entityInfo->id, index);
  gDungeon->unkC = 1;
}

void TriggerWeatherAbilities(void)
{
  Entity *entity;
  s32 index;

  if (gDungeon->unkC != 0) {
    gDungeon->unkC = 0;
    gDungeon->weather.nullifyWeather = FALSE;

    for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
    {
      entity = gDungeon->allPokemon[index];
      if (EntityExists(entity)) {
        if (HasAbility(entity, ABILITY_DRIZZLE)) {
            gDungeon->weather.naturalWeather[WEATHER_RAIN] = 1;
        }
        else if (HasAbility(entity, ABILITY_SAND_STREAM)) {
            gDungeon->weather.naturalWeather[WEATHER_SANDSTORM] = 1;
        }
        else if (HasAbility(entity, ABILITY_DROUGHT)) {
            gDungeon->weather.naturalWeather[WEATHER_SUNNY] = 1;
        }
        if ((HasAbility(entity, ABILITY_AIR_LOCK)) || (HasAbility(entity, ABILITY_CLOUD_NINE))) {
            gDungeon->weather.nullifyWeather = TRUE;
        }
      }
    }
  }
}

s32 sub_8069F54(Entity *pokemon, s16 param_2)
{
  if ((((param_2 * 0x10000) + 0xfe880000U) >> 0x10) < 4) {
    if (HasAbility(pokemon, ABILITY_FORECAST)) {
        return gUnknown_80F520C[GetApparentWeather(pokemon)].unk2;
    }
    else {
        return 0x178;
    }
  }
  return param_2;
}

static inline u8 sub_8069F9C_sub(Entity *pokemon)
{
    u32 weather;
    weather = GetApparentWeather(pokemon);
    return gUnknown_80F51E4[weather];
}

void sub_8069F9C(Entity *pokemon,Entity * target,Move *move)
{
  u8 type;
  u8 ability;
  const char *__src;
#ifndef NONMATCHING
  register s32 abilityCounter asm("r1"); // r1
#else
  s32 abilityCounter;
#endif
  int randomIndex;
  int abilityIndex;
  EntityInfo *iVar6; // r7
  EntityInfo *iVar7; // r2
  EntityInfo *iVar8;
  u8 local_20 [4];

  if (!EntityExists(pokemon)) {
    return;
  }
  if (!EntityExists(target)) {
    return;
  }
  if (pokemon == target) {
    return;
  }

  iVar7 = pokemon->axObj.info;
  iVar8 = iVar7;
  iVar6 = target->axObj.info;
  abilityIndex = -1;
  if (iVar6->abilities[0] == ABILITY_TRACE) {
    abilityIndex = 0;
  }
  if (iVar6->abilities[1] == ABILITY_TRACE) {
    abilityIndex = 1;
  }
  if (-1 < abilityIndex) {
    abilityCounter = 0;
    ability = iVar7->abilities[0];
    if (ability != ABILITY_UNKNOWN) {
      local_20[0] = ability;
      abilityCounter = 1;
    }
    ability = iVar8->abilities[1];
    if (ability != ABILITY_UNKNOWN) {
      local_20[abilityCounter] = ability;
      abilityCounter++;
    }
    if (abilityCounter != 0) {
      if (abilityCounter == 1) {
        randomIndex = 0;
      }
      else {
        randomIndex = DungeonRandInt(abilityCounter);
        if (randomIndex < 0) goto _0806A068;
      }
      iVar6->abilities[abilityIndex] = local_20[randomIndex];
      gDungeon->unkC = 1;
      SetMessageArgument(gAvailablePokemonNames,target,0);
      sub_80522F4(pokemon,target,*gUnknown_80FCC7C);
      sub_8042900(target);
      sub_806ABAC(pokemon,target);
    }
  }
_0806A068:
  if (iVar6->unk15A != 0) {
    iVar6->unk15A = 0;
    if (HasAbility(target, ABILITY_COLOR_CHANGE)) {
      type = GetMoveTypeForMonster(pokemon,move);
      if (move->id == MOVE_WEATHER_BALL) {
        type = sub_8069F9C_sub(pokemon);
      }
      if ((type != TYPE_NONE) && (!MonsterIsType(target,type))) {
        iVar6->types[0] = type;
        iVar6->types[1] = TYPE_NONE;
        iVar6->isColorChanged = TRUE;
        SetMessageArgument(gAvailablePokemonNames,target,0);
        __src = GetUnformattedTypeString(iVar6->types[0]);
        strcpy(gFormatItems,__src);
        sub_80522F4(pokemon,target,*gUnknown_80FCCAC);
        sub_8042968(target);
      }
    }
  }
}

void sub_806A120(Entity * pokemon, Entity * target, Move* move)
{
  u32 uVar2_u32;
  u8 moveType;
  const char *typeString;
  EntityInfo *entityInfo;

  if ((((EntityExists(pokemon)) && (EntityExists(target))) && (pokemon != target))
     && (entityInfo = target->axObj.info, entityInfo->protection.protectionStatus == STATUS_CONVERSION2)) {
    moveType = GetMoveTypeForMonster(pokemon, move);
    uVar2_u32 = sub_8092364(moveType);
    if (uVar2_u32 != TYPE_NONE) {
      entityInfo->types[0] = uVar2_u32;
      entityInfo->types[1] = 0;
      sub_8041BBC(target);
      SetMessageArgument(gAvailablePokemonNames,target,0);
      typeString = GetUnformattedTypeString(uVar2_u32);
      strcpy(gFormatItems,typeString);
      sub_80522F4(pokemon,target,*gUnknown_80FDCC8);
    }
  }
}

void sub_806A1B0(Entity *pokemon)
{
  if ((EntityExists(pokemon)) && (HasAbility(pokemon, ABILITY_TRUANT))) {
    PausedStatusTarget(pokemon,pokemon,0,1,0);
  }
}

void sub_806A1E8(Entity *pokemon)
{
  bool8 bVar3;
  EntityInfo *entityInfo;

  bVar3 = FALSE;
  if (EntityExists(pokemon)) {
    if (GetEntityType(pokemon) == ENTITY_MONSTER) {
      entityInfo = pokemon->axObj.info;
      bVar3 = (!entityInfo->isNotTeamMember);
    }
    if (gGameOptionsRef->FarOffPals == '\0') {
      bVar3 = FALSE;
    }
    if (bVar3 && (!sub_8045888(pokemon))) {
      sub_806A2BC(pokemon,1);
    }
  }
}

void sub_806A240(Entity *pokemon, Entity *target)
{
  bool8 isNotTeamMember;
  EntityInfo *entityInfo;

  isNotTeamMember = FALSE;
  if (EntityExists(pokemon)){
    if (GetEntityType(pokemon) == ENTITY_MONSTER) {
        entityInfo = pokemon->axObj.info;
        isNotTeamMember = (!entityInfo->isNotTeamMember);
    }
    if (isNotTeamMember && (!sub_8045888(pokemon))) {
        sub_806A2BC(pokemon,1);
        return;
    }
    else if (GetEntityType(target) == ENTITY_MONSTER) {
        entityInfo = target->axObj.info;
        isNotTeamMember = (!entityInfo->isNotTeamMember);
    }
    if (isNotTeamMember && (!sub_8045888(target))) {
        sub_806A2BC(target,1);
    }
  }
}

void sub_806A2BC(Entity *pokemon, u8 param_2)
{
  if ((EntityExists(pokemon)) && (GetEntityType(pokemon) == ENTITY_MONSTER) && (gDungeon->unk181e8.cameraTarget != pokemon)) {
    if (param_2 != '\0') {
      sub_804178C(1);
      while (gDungeon->unk12 < 0x3c) {
        sub_803E46C(0x34);
      }
    }
    sub_803E708(4,0x44);
    sub_803F508(pokemon);
    sub_804AC20(&pokemon->pos);
    gDungeon->unk12 = 0;
  }
}

void nullsub_95(void)
{}
