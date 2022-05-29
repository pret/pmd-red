#include "global.h"
#include "constants/ability.h"
#include "constants/move_id.h"
#include "constants/type.h"
#include "dungeon_entity.h"
#include "dungeon_global_data.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "pokemon.h"
#include "weather.h"
#include "gUnknown_203B46C.h"

extern struct UnkSaveStruct1 *gUnknown_203B46C;

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

extern u8* GetUnformattedTypeString(s16);
extern void SetMessageArgument(char[], struct DungeonEntity*, u32);
void sub_80522F4(struct DungeonEntity *r0, struct DungeonEntity *r1, const char r2[]);
extern void sub_8042900(struct DungeonEntity *r0);
extern void sub_8042968(struct DungeonEntity *r0);
extern void sub_806ABAC(struct DungeonEntity *, struct DungeonEntity *);
extern void sub_8076090(struct DungeonEntity *, struct DungeonEntity *,u32,u32,u32);
void sub_8041BBC(struct DungeonEntity *r0);
extern u8 sub_8045888(struct DungeonEntity *);
extern void sub_806A2BC(struct DungeonEntity *, u8);
extern void sub_804178C(u32);
extern void sub_803F508(struct DungeonEntity *);
extern void sub_804AC20(struct Position *);
extern u8 sub_8092364(u8);
extern void sub_803E46C(u32);
extern void sub_803E708(u32 r0, u32 r1);

void sub_8069E0C(struct DungeonEntity *param_1)
{
  s32 index;
  struct DungeonEntityData *iVar4;

  iVar4 = param_1->entityData;
  if (HasAbility(param_1, ABILITY_FORECAST)) {
    iVar4->types[0] = gUnknown_80F520C[GetWeather(param_1)].unk0;
    iVar4->types[1] = TYPE_NONE;
  }
  else {
    for(index = 0; index < 2; index++)
      iVar4->types[index] = GetPokemonType(iVar4->entityID, index);
  }
  for(index = 0; index < 2; index++)
    iVar4->abilities[index] = GetPokemonAbility(iVar4->entityID, index);
  gDungeonGlobalData->unkC = 1;
}

void TriggerWeatherAbilities(void)
{
  struct DungeonEntity *uVar4;
  s32 iVar5;

  if (gDungeonGlobalData->unkC != 0) {
    gDungeonGlobalData->unkC = 0;
    gDungeonGlobalData->negateWeatherEffects = FALSE;

    for(iVar5 = 0; iVar5 < DUNGEON_MAX_POKEMON; iVar5++)
    {
      uVar4 = gDungeonGlobalData->allPokemon[iVar5];
      if (EntityExists(uVar4)) {
        if (HasAbility(uVar4, ABILITY_DRIZZLE)) {
            gDungeonGlobalData->startingWeather[4] = 1;
        }
        else if (HasAbility(uVar4, ABILITY_SAND_STREAM)) {
            gDungeonGlobalData->startingWeather[2] = 1;
        }
        else if (HasAbility(uVar4, ABILITY_DROUGHT)) {
            gDungeonGlobalData->startingWeather[1] = 1;
        }
        if ((HasAbility(uVar4, ABILITY_AIR_LOCK)) || (HasAbility(uVar4, ABILITY_CLOUD_NINE))) {
            gDungeonGlobalData->negateWeatherEffects = TRUE;
        }
      }
    }
  }
}

s32 sub_8069F54(struct DungeonEntity *param_1, s16 param_2)
{
  if ((((param_2 * 0x10000) + 0xfe880000U) >> 0x10) < 4) {
    if (HasAbility(param_1, ABILITY_FORECAST)) {
        return gUnknown_80F520C[GetWeather(param_1)].unk2;
    }
    else {
        return 0x178;
    }
  }
  return param_2;
}

static inline u8 sub_8069F9C_sub(struct DungeonEntity *param_1)
{
    u32 uVar3;
    uVar3 = GetWeather(param_1);
    return gUnknown_80F51E4[uVar3];
}

void sub_8069F9C(struct DungeonEntity *param_1,struct DungeonEntity * param_2,struct PokemonMove *param_3)
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

  if (!EntityExists(param_1)) {
    return;
  }
  if (!EntityExists(param_2)) {
    return;
  }
  if (param_1 == param_2) {
    return;
  }

  iVar7 = param_1->entityData;
  iVar8 = iVar7;
  iVar6 = param_2->entityData;
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
      SetMessageArgument(gAvailablePokemonNames,param_2,0);
      sub_80522F4(param_1,param_2,*gUnknown_80FCC7C);
      sub_8042900(param_2);
      sub_806ABAC(param_1,param_2);
    }
  }
_0806A068:
  if (iVar6->unk15A != 0) {
    iVar6->unk15A = 0;
    if (HasAbility(param_2, ABILITY_COLOR_CHANGE)) {
      type = GetMoveTypeForPokemon(param_1,param_3);
      if (param_3->moveID == MOVE_WEATHER_BALL) {
        type = sub_8069F9C_sub(param_1);
      }
      if ((type != TYPE_NONE) && (!HasType(param_2,type))) {
        iVar6->types[0] = type;
        iVar6->types[1] = TYPE_NONE;
        iVar6->isColorChanged = TRUE;
        SetMessageArgument(gAvailablePokemonNames,param_2,0);
        __src = GetUnformattedTypeString(iVar6->types[0]);
        strcpy(gUnknown_202DE58,__src);
        sub_80522F4(param_1,param_2,*gUnknown_80FCCAC);
        sub_8042968(param_2);
      }
    }
  }
}

void sub_806A120(struct DungeonEntity * param_1, struct DungeonEntity * param_2, struct PokemonMove* move)
{
  u32 uVar2_u32;
  u8 uVar2;
  const char *__src;
  struct DungeonEntityData *iVar3;

  if ((((EntityExists(param_1)) && (EntityExists(param_2))) && (param_1 != param_2))
     && (iVar3 = param_2->entityData, iVar3->protectionStatus == 0xC)) {
    uVar2 = GetMoveTypeForPokemon(param_1, move);
    uVar2_u32 = sub_8092364(uVar2);
    if (uVar2_u32 != TYPE_NONE) {
      iVar3->types[0] = uVar2_u32;
      iVar3->types[1] = 0;
      sub_8041BBC(param_2);
      SetMessageArgument(gAvailablePokemonNames,param_2,0);
      __src = GetUnformattedTypeString(uVar2_u32);
      strcpy(gUnknown_202DE58,__src);
      sub_80522F4(param_1,param_2,*gUnknown_80FDCC8);
    }
  }
}

void sub_806A1B0(struct DungeonEntity *param_1)
{ 
  if ((EntityExists(param_1)) && (HasAbility(param_1,0x2a))) {
    sub_8076090(param_1,param_1,0,1,0);
  }
}

void sub_806A1E8(struct DungeonEntity *param_1)
{
  bool8 bVar3;
  struct DungeonEntityData *iVar1;
  
  bVar3 = FALSE;
  if (EntityExists(param_1)) {
    if (GetEntityType(param_1) == ENTITY_POKEMON) {
      iVar1 = param_1->entityData;
      bVar3 = (!iVar1->isEnemy);
    }
    if (gUnknown_203B46C->unk1 == '\0') {
      bVar3 = FALSE;
    }
    if (bVar3 && (sub_8045888(param_1) == '\0')) {
      sub_806A2BC(param_1,1);
    }
  }
}

void sub_806A240(struct DungeonEntity *param_1, struct DungeonEntity *param_2)
{
  bool8 bVar3;
  struct DungeonEntityData *iVar1;
  
  bVar3 = FALSE;
  if (EntityExists(param_1)){
    if (GetEntityType(param_1) == ENTITY_POKEMON) {
        iVar1 = param_1->entityData;
        bVar3 = (!iVar1->isEnemy);
    }
    if (bVar3 && (sub_8045888(param_1) == '\0')) {
        sub_806A2BC(param_1,1);
        return;
    }
    else if (GetEntityType(param_2) == ENTITY_POKEMON) {
        iVar1 = param_2->entityData;
        bVar3 = (!iVar1->isEnemy);
    }
    if (bVar3 && (sub_8045888(param_2) == '\0')) {
        sub_806A2BC(param_2,1);
    }
  }
}

void sub_806A2BC(struct DungeonEntity *param_1, u8 param_2)
{
  if ((EntityExists(param_1)) && (GetEntityType(param_1) == ENTITY_POKEMON) && (gDungeonGlobalData->leader != param_1)) {
    if (param_2 != '\0') {
      sub_804178C(1);
      while (gDungeonGlobalData->unk12 < 0x3c) {
        sub_803E46C(0x34);
      }
    }
    sub_803E708(4,0x44);
    sub_803F508(param_1);
    sub_804AC20(&param_1->posWorld);
    gDungeonGlobalData->unk12 = 0;
  }
}

void nullsub_95(void)
{}
