#ifndef GUARD_CREDITS1_H
#define GUARD_CREDITS1_H

// size: 0xC
typedef struct CreditsData
{
    /* 0x0 */ s16 type;
    /* 0x2 */ s16 x;
    /* 0x4 */ s16 y;
    /* 0x8 */ const u8 *text;
} CreditsData;

bool8 DrawCredits(s32 creditsCategoryIndex, s32);

u32 sub_8035574(void);
void sub_803565C(void);

#endif // GUARD_CREDITS1_H
