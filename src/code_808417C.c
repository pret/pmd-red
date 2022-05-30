#include "global.h"
#include "constants/ability.h"
#include "constants/iq_skill.h"
#include "dungeon_entity.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_random.h"
#include "dungeon_util.h"

s32 CalculateStatusTurns(struct DungeonEntity *target, s16 *turnRange, bool8 factorCurerSkills)
{
  s32 numTurns;
  
  numTurns = DungeonRandomRange(turnRange[0],turnRange[1]);
  if (EntityExists(target) && (GetEntityType(target) == ENTITY_POKEMON) && (factorCurerSkills)) {
    if (HasIQSkill(target, IQ_SKILL_SELF_CURER) && (numTurns != 0x7f)) {
      numTurns /= 2;
    }
    if (HasAbility(target, ABILITY_NATURAL_CURE) && (numTurns != 0x7f) && (4 < numTurns)) {
      numTurns = 5;
    }
  }
  if (numTurns < 1) {
    numTurns = 1;
  }
  return numTurns;
}
