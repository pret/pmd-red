#include "global.h"
#include "input.h"
#include "random.h"
#include "reg_control.h"

void sub_800BA5C();

extern u32 gUnknown_203B0B8;
extern u16 gRawKeyInput;

void sub_800CB20(void)
{
    sub_800BA5C();
    gUnknown_203B0B8++;
    if((gRawKeyInput & (A_BUTTON | SELECT_BUTTON)) != 0)
    {
        Rand32Bit();
    }
    Rand32Bit();
}

// Unused
u32 sub_800CB50(void)
{
    return gUnknown_203B0B8;
}

void nullsub_180(void)
{
}

void xxx_call_update_bg_sound_input(void)
{
    xxx_update_bg_sound_input();
}

void nullsub_181(void)
{
}

u32 sub_800CB70(void)
{
    return 0;
}

void ReadKeyInput(struct Inputs *r0)
{
    u16 keyInput = REG_KEYINPUT ^ KEYS_MASK;
    r0->held = 0;

    if((keyInput & DPAD_UP) != 0)
        r0->held = DPAD_UP;

    if((keyInput & DPAD_DOWN) != 0)
        r0->held |= DPAD_DOWN;

    if((keyInput & DPAD_LEFT) != 0)
        r0->held |= DPAD_LEFT;

    if((keyInput & DPAD_RIGHT) != 0)
        r0->held |= DPAD_RIGHT;

    if((keyInput & A_BUTTON) != 0)
        r0->held |= A_BUTTON;

    if((keyInput & B_BUTTON) != 0)
        r0->held |= B_BUTTON;

    if((keyInput & START_BUTTON) != 0)
        r0->held |= START_BUTTON;

    if((keyInput & SELECT_BUTTON) != 0)
        r0->held |= SELECT_BUTTON;

    if((keyInput & R_BUTTON) != 0)
        r0->held |= R_BUTTON;

    if((keyInput & L_BUTTON) != 0)
        r0->held |= L_BUTTON;

    gRawKeyInput = keyInput;
}

