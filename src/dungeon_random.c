#include "global.h"
#include "globaldata.h"
#include "dungeon_random.h"
#include "constants/ability.h"
#include "constants/iq_skill.h"
#include "structs/dungeon_entity.h"
#include "dungeon_logic.h"
#include "dungeon_random.h"
#include "dungeon_util.h"

EWRAM_INIT u32 gDungeonRngState = {1};
EWRAM_INIT u32 gUnknown_203B458 = {1};

void sub_808408C(u32 param_1)
{
    gUnknown_203B458 = (1 | param_1) & 0xffffff;
}

u32 YetAnotherRandom24(void)
{
    u32 r0;
    u32 r1;

    r1 = gUnknown_203B458 * 0x5d588b65;
    r1++;
    r0 = r1 >> 16;
    r1 *= 0x5d588b65;
    r1++;
    gUnknown_203B458 = r1;
    r1 &= 0xffff0000;
    r0 |= r1;
    r0 &= 0x0ffffff;
    r0 |= 1;
    return r0;
}

void InitDungeonRNG(u32 value)
{
    gDungeonRngState = (value | 1);
}

s32 DungeonRand16Bit(void)
{
    gDungeonRngState = 1566083941 * gDungeonRngState + 1;
    return gDungeonRngState >> 16;
}

s32 DungeonRandInt(s32 cap)
{
    return (((DungeonRand16Bit() & 0xFFFF) * cap) >> 16) & 0xFFFF;
}

s32 DungeonRandRange(s32 low, s32 high)
{
    if(low == high)
        return low;
    else if(low < high)
    {
        return (DungeonRandInt(high - low) + low);
    }
    else
    {
        return (DungeonRandInt(low - high) + high);
    }
}

bool8 DungeonRandOutcome(s32 percentChance)
{
    if (DungeonRandInt(100) < percentChance)
    {
        return TRUE;
    }
    return FALSE;
}

bool8 DungeonRandOutcome_2(s32 percentChance)
{
    if (DungeonRandInt(100) < percentChance)
    {
        return TRUE;
    }
    return FALSE;
}

s32 CalculateStatusTurns(Entity *target, const s16 *turnRange, bool8 factorCurerSkills)
{
  s32 numTurns;

  numTurns = DungeonRandRange(turnRange[0],turnRange[1]);
  if (EntityIsValid(target) && (GetEntityType(target) == ENTITY_MONSTER) && (factorCurerSkills)) {
    if (IqSkillIsEnabled(target, IQ_SELF_CURER) && (numTurns != 0x7f)) {
      numTurns /= 2;
    }
    if (AbilityIsActive(target, ABILITY_NATURAL_CURE) && (numTurns != 0x7f) && (4 < numTurns)) {
      numTurns = 5;
    }
  }
  if (numTurns < 1) {
    numTurns = 1;
  }
  return numTurns;
}
