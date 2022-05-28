#include "global.h"
#include "constants/ability.h"
#include "constants/iq_skill.h"
#include "dungeon_entity.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_random.h"
#include "dungeon_util.h"

s32 sub_808417C(struct DungeonEntity *param_1, s16 *param_2, u8 param_3)
{
  s32 iVar2;
  
  iVar2 = DungeonRandomRange(param_2[0],param_2[1]);
  if (EntityExists(param_1) && (GetEntityType(param_1) == ENTITY_POKEMON) && (param_3 != 0)) {
    if (HasIQSkill(param_1, IQ_SKILL_SELF_CURER) && (iVar2 != 0x7f)) {
      iVar2 /= 2;
    }
    if (HasAbility(param_1, ABILITY_NATURAL_CURE) && (iVar2 != 0x7f) && (4 < iVar2)) {
      iVar2 = 5;
    }
  }
  if (iVar2 < 1) {
    iVar2 = 1;
  }
  return iVar2;
}
