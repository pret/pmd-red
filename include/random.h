#ifndef GUARD_RANDOM_H
#define GUARD_RANDOM_H

void SeedRng(u8 seed[6]);
s32 Rand32Bit(void);
// Returns a random number [0, maxExclusive)
s32 RandInt(s32 maxExclusive);
// Returns a random number [minInclusive, maxExclusive)
s32 RandRange(s32 minInclusive, s32 maxExclusive);
s32 GetRNGState(void);
void SetRNGSeed(s32 state);

#endif // GUARD_RANDOM_H