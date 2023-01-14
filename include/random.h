#ifndef GUARD_RANDOM_H
#define GUARD_RANDOM_H

void SeedRng(u8 *seed);
s32 Rand32Bit(void);
s32 RandInt(s32 cap);
s32 RandRange(s32 a, s32 b);
s32 GetRNGSeed(void);
void SetRNGSeed(s32 state);

#endif // GUARD_RANDOM_H
