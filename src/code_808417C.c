#include "global.h"
#include "constants/ability.h"
#include "constants/iq_skill.h"
#include "structs/dungeon_entity.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_random.h"
#include "dungeon_util.h"

s32 CalculateStatusTurns(Entity *target, s16 *turnRange, bool8 factorCurerSkills)
{
  s32 numTurns;
  
  numTurns = DungeonRandRange(turnRange[0],turnRange[1]);
  if (EntityExists(target) && (GetEntityType(target) == ENTITY_MONSTER) && (factorCurerSkills)) {
    if (IQSkillIsEnabled(target, IQ_SELF_CURER) && (numTurns != 0x7f)) {
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
