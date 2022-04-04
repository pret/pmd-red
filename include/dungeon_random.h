#ifndef GUARD_DUNGEON_RANDOM_H
#define GUARD_DUNGEON_RANDOM_H

s32 DungeonRandom(void);
s32 DungeonRandomCapped(s32 cap);
s32 DungeonRandomRange(s32 low, s32 high);
bool8 RollPercentChance(s32 percentChance);
bool8 RollPercentChance_2(s32 percentChance);
#endif
