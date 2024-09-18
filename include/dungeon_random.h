#ifndef GUARD_DUNGEON_RANDOM_H
#define GUARD_DUNGEON_RANDOM_H

void sub_808408C(u32 param_1);
u32 YetAnotherRandom24(void);
void InitDungeonRNG(u32 value);
s32 DungeonRand16Bit(void);
s32 DungeonRandInt(s32 cap);
s32 DungeonRandRange(s32 low, s32 high);
bool8 DungeonRandOutcome(s32 percentChance);
bool8 DungeonRandOutcome_2(s32 percentChance);
#endif
