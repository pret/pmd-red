#include "global.h"
#include "code_800C9CC.h"
#include "input.h"

EWRAM_DATA Inputs gRealInputs = {0};
EWRAM_DATA UnusedInputStruct gUnusedInputsRelated = {0};
EWRAM_DATA u32 gUnusedScrambledInputJunk = {0};
EWRAM_DATA Inputs gBufferedInputs = {0};
EWRAM_DATA Inputs gCurrentInputs = {0};
EWRAM_DATA Inputs gLastInputs = {0};
EWRAM_DATA InputTimers gInputTimers = {0};

void InitInput(void)
{
    gRealInputs.held = 0;
    gRealInputs.pressed = 0;
    gRealInputs.repeated = 0;
    gRealInputs.shortPress = 0;

    gBufferedInputs.held = 0;
    gBufferedInputs.pressed = 0;
    gBufferedInputs.repeated = 0;
    gBufferedInputs.shortPress = 0;

    gUnusedScrambledInputJunk = 0x4a14c1; // seems like random keyboard mashing (see UpdateInput)

    gUnusedInputsRelated.unk20 = 0;
    gUnusedInputsRelated.unk0 = 0xFFFF; // probably a mask
    gUnusedInputsRelated.unk2 = -1;
    gUnusedInputsRelated.unk4 = -1;
    gUnusedInputsRelated.unk6 = -1;
    gUnusedInputsRelated.unk1C = -1;
    gUnusedInputsRelated.unk1E = -1;
    gUnusedInputsRelated.unk8 = -1;
    gUnusedInputsRelated.unkA = -1;
    gUnusedInputsRelated.unkC = -1;
    gUnusedInputsRelated.unkE = -1;
    gUnusedInputsRelated.unk10 = -1;
    gUnusedInputsRelated.unk12 = -1;
    gUnusedInputsRelated.unk14 = -1;
    gUnusedInputsRelated.unk16 = -1;
    gUnusedInputsRelated.unk28 = 0;
    gUnusedInputsRelated.unk29 = 0;

    gInputTimers.holdTimerB = 0;
    gInputTimers.holdTimerR = 0;
}

void LoadBufferedInputs(void)
{
    gRealInputs = gBufferedInputs;

    gBufferedInputs.held = 0;
    gBufferedInputs.pressed = 0;
    gBufferedInputs.repeated = 0;
    gBufferedInputs.shortPress = 0;

    gUnusedInputsRelated.unk0 = 0xffff;
    gUnusedInputsRelated.unk2 = -1;
    gUnusedInputsRelated.unk4 = -1;
    gUnusedInputsRelated.unk6 = -1;
    gUnusedInputsRelated.unk8 = -1;
    gUnusedInputsRelated.unkA = -1;
    gUnusedInputsRelated.unkC = -1;
    gUnusedInputsRelated.unkE = -1;
    gUnusedInputsRelated.unk10 = -1;
    gUnusedInputsRelated.unk12 = -1;
    gUnusedInputsRelated.unk14 = -1;
    gUnusedInputsRelated.unk16 = -1;

    gUnusedInputsRelated.unk28 = 0;
    gUnusedInputsRelated.unk29 = 0;
}

UNUSED static bool8 sub_80048B8(void)
{
    return FALSE;
}

bool8 sub_80048BC(void)
{
    return FALSE;
}

UNUSED static bool8 sub_80048C0(void)
{
    return FALSE;
}

UNUSED static bool8 sub_80048C4(void)
{
    return FALSE;
}

bool8 sub_80048C8(void)
{
    return FALSE;
}

UNUSED static bool8 sub_80048CC(void)
{
    return FALSE;
}

void ResetRepeatTimers(void)
{
    gRealInputs.repeated = 0;
    gCurrentInputs.repeatTimerDpad = 0;
    gCurrentInputs.heldDpad = 0;
    gInputTimers.holdTimerB = 999;
    gInputTimers.holdTimerR = 999;
}

void UnpressButtons(void)
{
    gRealInputs.pressed = 0;
    gBufferedInputs.pressed = 0;
    gCurrentInputs.pressed = 0;
}

void ResetUnusedInputStruct(void)
{
    gUnusedInputsRelated.unk20 = 5;
    gUnusedInputsRelated.unk24 = 0;
    gUnusedInputsRelated.unk0 = 0xFFFF;
    gUnusedInputsRelated.unk2 = -1;
    gUnusedInputsRelated.unk4 = -1;
    gUnusedInputsRelated.unk6 = -1;
    gUnusedInputsRelated.unk8 = -1;
    gUnusedInputsRelated.unkA = -1;
    gUnusedInputsRelated.unkC = -1;
    gUnusedInputsRelated.unkE = -1;
    gUnusedInputsRelated.unk10 = -1;
    gUnusedInputsRelated.unk12 = -1;
    gUnusedInputsRelated.unk14 = -1;
    gUnusedInputsRelated.unk16 = -1;

    gUnusedInputsRelated.unk28 = 0;
    gUnusedInputsRelated.unk29 = 0;
}

void UpdateInput(void)
{
    gLastInputs = gCurrentInputs;

    ReadKeyInput(&gCurrentInputs);

    gCurrentInputs.pressed = (gLastInputs.held ^ gCurrentInputs.held) & gCurrentInputs.held;

    if (gCurrentInputs.held) {
        if ((gCurrentInputs.heldDpad & DPAD_ANY) == (gCurrentInputs.held & DPAD_ANY)) {
            if (gCurrentInputs.repeatTimerDpad < 50)
                gCurrentInputs.repeatTimerDpad++;
        }
        else {
            gCurrentInputs.heldDpad = gCurrentInputs.held & DPAD_ANY;
            gCurrentInputs.repeatTimerDpad = 1;
        }
    }
    else {
        gCurrentInputs.repeatTimerDpad = 0;
        gCurrentInputs.heldDpad = 0;
    }

    if (gCurrentInputs.repeatTimerDpad == 1) {
        gCurrentInputs.repeated = (gCurrentInputs.heldDpad & DPAD_ANY) | gCurrentInputs.pressed;
    }
    else if (gCurrentInputs.repeatTimerDpad == 48) {
        gCurrentInputs.repeatTimerDpad = 43;
        gCurrentInputs.repeated = (gCurrentInputs.heldDpad & DPAD_ANY) | gCurrentInputs.pressed;
    }
    else
        gCurrentInputs.repeated = 0;

    gCurrentInputs.shortPress = 0;

    if (gCurrentInputs.held & B_BUTTON) {
        if (gInputTimers.holdTimerB < 100)
            gInputTimers.holdTimerB++;
    }
    else if (1 < gInputTimers.holdTimerB && gInputTimers.holdTimerB < 12) {
        gCurrentInputs.shortPress = B_BUTTON;
        gInputTimers.holdTimerB = 0;
    }
    else
        gInputTimers.holdTimerB = 0;

    if (gCurrentInputs.held & R_BUTTON) {
        if (gInputTimers.holdTimerR < 100)
            gInputTimers.holdTimerR++;
    }
    else if (1 < gInputTimers.holdTimerR && gInputTimers.holdTimerR < 12) {
        gCurrentInputs.shortPress |= R_BUTTON;
        gInputTimers.holdTimerR = 0;
    }
    else
        gInputTimers.holdTimerR = 0;

    gBufferedInputs.held |= gCurrentInputs.held;
    gBufferedInputs.pressed |= gCurrentInputs.pressed;
    gBufferedInputs.repeated |= gCurrentInputs.repeated;
    gBufferedInputs.shortPress |= gCurrentInputs.shortPress;

    gUnusedScrambledInputJunk *= gCurrentInputs.held | 0x54a1c41; // very similar to odd constant in InitInput - probably keymashing
}