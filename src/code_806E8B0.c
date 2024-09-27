#include "global.h"
#include "constants/ability.h"
#include "structs/str_dungeon.h"
#include "dungeon_pokemon_attributes.h"
#include "status_checks_1.h"
#include "text_util.h"

extern u8 *gUnknown_80FEE04[];
extern u8 *gUnknown_80FEE2C[];
extern u8 *gUnknown_80FEE54[];

void sub_8042940(Entity *r0);
void sub_80428B0(Entity *r0);
void sub_80428C4(Entity *r0);
void sub_80522F4(Entity *r0, Entity *r1, const char r2[]);

void sub_806E8B0(Entity * pokemon, Entity * target, u8 param_3, s32 *param_4, s32 *param_5, s32 param_6)
{
  bool8 hasNegStatus_pokemon;
  bool8 visFlags_pokemon_1;
  bool8 visFlags_pokemon_2;
  bool8 hasNegStatus_target;
  bool8 visFlags_target;
  s32 iVar3;
  bool32 isNotEnemy;
  EntityInfo * entityInfo;
  EntityInfo * entityInfo_1;
  s32 r7;
  s32 r8;
  s32 r10;
  s32 sp_0x4;
  s32 sp_0x8;
  
  r7 = 1;
  r8 = 1;
  sp_0x4 = 1;
  sp_0x8 = 1;
  r10 = IsTypePhysical(param_3) == 0;
  

  if (HasAbility(pokemon, ABILITY_GUTS)) {
    entityInfo = pokemon->axObj.info;
    hasNegStatus_pokemon = HasNegativeStatus(pokemon);
    visFlags_pokemon_1 = SetVisualFlags(entityInfo,1,hasNegStatus_pokemon);
    if (hasNegStatus_pokemon) {
      r7 = 2;
    }
    if (visFlags_pokemon_1) {
      sub_80428B0(pokemon);
      sub_80522F4(pokemon,target,*gUnknown_80FEE04); // Guts boosted its power
    }
  }

  if ((HasAbility(pokemon, ABILITY_HUGE_POWER)) || (HasAbility(pokemon, ABILITY_PURE_POWER))) {
    entityInfo_1 = pokemon->axObj.info;
    iVar3 = 0;
    if ((param_6 < 0x21) && (!r10)) {
      iVar3 = 1;
    }
    visFlags_pokemon_2 = SetVisualFlags(entityInfo_1,0x100,iVar3);
    if (iVar3 != 0) {
      r7 *= 3;
      r8 <<= 1;
    }
    if (visFlags_pokemon_2) {
      sub_80428C4(pokemon);
      sub_80522F4(pokemon,target,*gUnknown_80FEE2C); // It's special ability boosted Attack
    }
  }

  if ((HasAbility(pokemon, ABILITY_HUSTLE)) && (!r10)) {
    r7 *= 3;
    r8 <<= 1;
  }

  if(pokemon->axObj.info->isNotTeamMember)
  {
      isNotEnemy = FALSE;
  }
  else
  {
      isNotEnemy = TRUE;
  }

  if ((HasAbility(pokemon, ABILITY_PLUS)) && (r10 == 1) && gDungeon->minusIsActive[isNotEnemy]) {
    r7 *= 15;
    r8 *= 10;
  }

  // ABILITY_MINUS
  if ((HasAbility(pokemon, ABILITY_MINUS)) && (r10 == 1) && gDungeon->plusIsActive[isNotEnemy]) {
    r7 *= 15;
    r8 *= 10;
  }

  if (HasAbility(target, ABILITY_INTIMIDATE) && (!r10)) {
    r7 <<= 2;
    r8 *= 5;
  }

  if ((HasAbility(target, ABILITY_MARVEL_SCALE)) && (!r10)) {
    entityInfo = target->axObj.info;
    hasNegStatus_target = HasNegativeStatus(target);
    visFlags_target = SetVisualFlags(entityInfo, 8, hasNegStatus_target);
    if (hasNegStatus_target) {
      sp_0x4 *= 3;
      sp_0x8 <<= 1;
    }
    if (visFlags_target) {
      sub_8042940(target);
      sub_80522F4(pokemon,target,*gUnknown_80FEE54); // Its special ability quickened attacks!
    }
  }

  *param_4 *= r7;
  *param_5 *= sp_0x4;
  if (r8 != 1) {
    *param_4 = *param_4 / r8;
  }
  if (sp_0x8 != 1) {
    *param_5 = *param_5 / sp_0x8;
  }
}
