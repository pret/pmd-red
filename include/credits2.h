#ifndef GUARD_CREDITS2_H
#define GUARD_CREDITS2_H

// size: 0x8
typedef struct Credits2Work
{
    /* 0x0 */ u32 state;
    u32 unk4; // timer for not holding any inputs
} Credits2Work;

bool8 sub_8035678(void);
u32 sub_80356A0(void);
void sub_8035758(void);

#endif // GUARD_CREDITS2_H
