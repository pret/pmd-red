#ifndef GUARD_RANDOM_H
#define GUARD_RANDOM_H

void SeedRng(u8 *seed);
s32 Random(void);
s32 RandomCapped(s32 cap);
s32 RandomRange(s32 a, s32 b);
s32 GetRngState(void);
void SetRngState(s32 state);

#endif // GUARD_RANDOM_H
