#include "global.h"
#include "constants/ability.h"
#include "constants/move_id.h"
#include "constants/type.h"
#include "constants/weather.h"
#include "dungeon_entity.h"
#include "dungeon_global_data.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "pokemon.h"
#include "weather.h"
#include "game_options.h"
#include "text_util.h"

extern struct GameOptions *gGameOptions;

struct unkStruct_80F520C
{
    u8 unk0;
    u8 unk1;
    s16 unk2;
};

extern struct unkStruct_80F520C gUnknown_80F520C[];

extern u8 gAvailablePokemonNames[];
extern u8 gUnknown_202DE58[];
extern u8 gUnknown_80F51E4[];
extern u8 *gUnknown_80FCC7C[];
extern u8 *gUnknown_80FCCAC[];
extern u8 *gUnknown_80FDCC8[];

extern void SetMessageArgument(char[], struct DungeonEntity*, u32);
void sub_80522F4(struct DungeonEntity *r0, struct DungeonEntity *r1, const char r2[]);
extern void sub_8042900(struct DungeonEntity *r0);
extern void sub_8042968(struct DungeonEntity *r0);
extern void sub_806ABAC(struct DungeonEntity *, struct DungeonEntity *);
extern void PausedStatusTarget(struct DungeonEntity *, struct DungeonEntity *,u32,u32,u32);
void sub_8041BBC(struct DungeonEntity *r0);
extern u8 sub_8045888(struct DungeonEntity *);
extern void sub_806A2BC(struct DungeonEntity *, u8);
extern void sub_804178C(u32);
extern void sub_803F508(struct DungeonEntity *);
extern void sub_804AC20(struct Position *);
extern u8 sub_8092364(u8);
extern void sub_803E46C(u32);
extern void sub_803E708(u32 r0, u32 r1);

void sub_8069E0C(struct DungeonEntity *pokemon)
{
  s32 index;
  struct DungeonEntityData *entityData;

  entityData = pokemon->entityData;
  if (HasAbility(pokemon, ABILITY_FORECAST)) {
    entityData->types[0] = gUnknown_80F520C[GetWeather(pokemon)].unk0;
    entityData->types[1] = TYPE_NONE;
  }
  else {
    for(index = 0; index < 2; index++)
      entityData->types[index] = GetPokemonType(entityData->entityID, index);
  }
  for(index = 0; index < 2; index++)
    entityData->abilities[index] = GetPokemonAbility(entityData->entityID, index);
  gDungeonGlobalData->unkC = 1;
}

void TriggerWeatherAbilities(void)
{
  struct DungeonEntity *entity;
  s32 index;

  if (gDungeonGlobalData->unkC != 0) {
    gDungeonGlobalData->unkC = 0;
    gDungeonGlobalData->negateWeatherEffects = FALSE;

    for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
    {
      entity = gDungeonGlobalData->allPokemon[index];
      if (EntityExists(entity)) {
        if (HasAbility(entity, ABILITY_DRIZZLE)) {
            gDungeonGlobalData->startingWeather[WEATHER_RAIN] = 1;
        }
        else if (HasAbility(entity, ABILITY_SAND_STREAM)) {
            gDungeonGlobalData->startingWeather[WEATHER_SANDSTORM] = 1;
        }
        else if (HasAbility(entity, ABILITY_DROUGHT)) {
            gDungeonGlobalData->startingWeather[WEATHER_SUNNY] = 1;
        }
        if ((HasAbility(entity, ABILITY_AIR_LOCK)) || (HasAbility(entity, ABILITY_CLOUD_NINE))) {
            gDungeonGlobalData->negateWeatherEffects = TRUE;
        }
      }
    }
  }
}

s32 sub_8069F54(struct DungeonEntity *pokemon, s16 param_2)
{
  if ((((param_2 * 0x10000) + 0xfe880000U) >> 0x10) < 4) {
    if (HasAbility(pokemon, ABILITY_FORECAST)) {
        return gUnknown_80F520C[GetWeather(pokemon)].unk2;
    }
    else {
        return 0x178;
    }
  }
  return param_2;
}

static inline u8 sub_8069F9C_sub(struct DungeonEntity *pokemon)
{
    u32 weather;
    weather = GetWeather(pokemon);
    return gUnknown_80F51E4[weather];
}

void sub_8069F9C(struct DungeonEntity *pokemon,struct DungeonEntity * target,struct PokemonMove *move)
{
  u8 type;
  u8 ability;
  const char *__src;
  register s32 abilityCounter asm("r1"); // r1
  int randomIndex;
  int abilityIndex;
  struct DungeonEntityData *iVar6; // r7
  struct DungeonEntityData *iVar7; // r2
  struct DungeonEntityData *iVar8;
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

  iVar7 = pokemon->entityData;
  iVar8 = iVar7;
  iVar6 = target->entityData;
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
    if (ability != ABILITY_NONE) {
      local_20[0] = ability;
      abilityCounter = 1;
    }
    ability = iVar8->abilities[1];
    if (ability != ABILITY_NONE) {
      local_20[abilityCounter] = ability;
      abilityCounter++;
    }
    if (abilityCounter != 0) {
      if (abilityCounter == 1) {
        randomIndex = 0;
      }
      else {
        randomIndex = DungeonRandomCapped(abilityCounter);
        if (randomIndex < 0) goto _0806A068;
      }
      iVar6->abilities[abilityIndex] = local_20[randomIndex];
      gDungeonGlobalData->unkC = 1;
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
      type = GetMoveTypeForPokemon(pokemon,move);
      if (move->moveID == MOVE_WEATHER_BALL) {
        type = sub_8069F9C_sub(pokemon);
      }
      if ((type != TYPE_NONE) && (!HasType(target,type))) {
        iVar6->types[0] = type;
        iVar6->types[1] = TYPE_NONE;
        iVar6->isColorChanged = TRUE;
        SetMessageArgument(gAvailablePokemonNames,target,0);
        __src = GetUnformattedTypeString(iVar6->types[0]);
        strcpy(gUnknown_202DE58,__src);
        sub_80522F4(pokemon,target,*gUnknown_80FCCAC);
        sub_8042968(target);
      }
    }
  }
}

void sub_806A120(struct DungeonEntity * pokemon, struct DungeonEntity * target, struct PokemonMove* move)
{
  u32 uVar2_u32;
  u8 moveType;
  const char *typeString;
  struct DungeonEntityData *entityData;

  if ((((EntityExists(pokemon)) && (EntityExists(target))) && (pokemon != target))
     && (entityData = target->entityData, entityData->protectionStatus == 0xC)) {
    moveType = GetMoveTypeForPokemon(pokemon, move);
    uVar2_u32 = sub_8092364(moveType);
    if (uVar2_u32 != TYPE_NONE) {
      entityData->types[0] = uVar2_u32;
      entityData->types[1] = 0;
      sub_8041BBC(target);
      SetMessageArgument(gAvailablePokemonNames,target,0);
      typeString = GetUnformattedTypeString(uVar2_u32);
      strcpy(gUnknown_202DE58,typeString);
      sub_80522F4(pokemon,target,*gUnknown_80FDCC8);
    }
  }
}

void sub_806A1B0(struct DungeonEntity *pokemon)
{ 
  if ((EntityExists(pokemon)) && (HasAbility(pokemon, ABILITY_TRUANT))) {
    PausedStatusTarget(pokemon,pokemon,0,1,0);
  }
}

void sub_806A1E8(struct DungeonEntity *pokemon)
{
  bool8 bVar3;
  struct DungeonEntityData *entityData;
  
  bVar3 = FALSE;
  if (EntityExists(pokemon)) {
    if (GetEntityType(pokemon) == ENTITY_POKEMON) {
      entityData = pokemon->entityData;
      bVar3 = (!entityData->isEnemy);
    }
    if (gGameOptions->FarOffPals == '\0') {
      bVar3 = FALSE;
    }
    if (bVar3 && (sub_8045888(pokemon) == '\0')) {
      sub_806A2BC(pokemon,1);
    }
  }
}

void sub_806A240(struct DungeonEntity *pokemon, struct DungeonEntity *target)
{
  bool8 isEnemy;
  struct DungeonEntityData *entityData;
  
  isEnemy = FALSE;
  if (EntityExists(pokemon)){
    if (GetEntityType(pokemon) == ENTITY_POKEMON) {
        entityData = pokemon->entityData;
        isEnemy = (!entityData->isEnemy);
    }
    if (isEnemy && (sub_8045888(pokemon) == '\0')) {
        sub_806A2BC(pokemon,1);
        return;
    }
    else if (GetEntityType(target) == ENTITY_POKEMON) {
        entityData = target->entityData;
        isEnemy = (!entityData->isEnemy);
    }
    if (isEnemy && (sub_8045888(target) == '\0')) {
        sub_806A2BC(target,1);
    }
  }
}

void sub_806A2BC(struct DungeonEntity *pokemon, u8 param_2)
{
  if ((EntityExists(pokemon)) && (GetEntityType(pokemon) == ENTITY_POKEMON) && (gDungeonGlobalData->leader != pokemon)) {
    if (param_2 != '\0') {
      sub_804178C(1);
      while (gDungeonGlobalData->unk12 < 0x3c) {
        sub_803E46C(0x34);
      }
    }
    sub_803E708(4,0x44);
    sub_803F508(pokemon);
    sub_804AC20(&pokemon->posWorld);
    gDungeonGlobalData->unk12 = 0;
  }
}

void nullsub_95(void)
{}
