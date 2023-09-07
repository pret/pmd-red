#include "global.h"
#include "code_800C9CC.h"
#include "input.h"

EWRAM_DATA Inputs gRealInputs = {0}; // 20255F0
static EWRAM_DATA UnusedInputStruct sUnusedInputsRelated = {0}; // 2025600
static EWRAM_DATA u32 sUnusedScrambledInputJunk[3] = {0}; // 202562C
static EWRAM_DATA Inputs sBufferedInputs = {0}; // 2025638
static EWRAM_DATA Inputs sCurrentInputs = {0}; // 2025648
static EWRAM_DATA Inputs sPrevInputs = {0}; // 2025658
static EWRAM_DATA InputTimers sInputTimers = {0}; // 2025668

void InitInput(void)
{
    gRealInputs.held = 0;
    gRealInputs.pressed = 0;
    gRealInputs.repeated = 0;
    gRealInputs.shortPress = 0;

    sBufferedInputs.held = 0;
    sBufferedInputs.pressed = 0;
    sBufferedInputs.repeated = 0;
    sBufferedInputs.shortPress = 0;

    sUnusedScrambledInputJunk[0] = 0x4A14C1; // seems like random keyboard mashing (see UpdateInput)

    sUnusedInputsRelated.unk20 = 0;
    sUnusedInputsRelated.unk0 = 0xFFFF; // probably a mask
    sUnusedInputsRelated.unk2 = -1;
    sUnusedInputsRelated.unk4 = -1;
    sUnusedInputsRelated.unk6 = -1;
    sUnusedInputsRelated.unk1C = -1;
    sUnusedInputsRelated.unk1E = -1;
    sUnusedInputsRelated.unk8 = -1;
    sUnusedInputsRelated.unkA = -1;
    sUnusedInputsRelated.unkC = -1;
    sUnusedInputsRelated.unkE = -1;
    sUnusedInputsRelated.unk10 = -1;
    sUnusedInputsRelated.unk12 = -1;
    sUnusedInputsRelated.unk14 = -1;
    sUnusedInputsRelated.unk16 = -1;
    sUnusedInputsRelated.unk28 = 0;
    sUnusedInputsRelated.unk29 = 0;

    sInputTimers.holdTimerB = 0;
    sInputTimers.holdTimerR = 0;
}

void LoadBufferedInputs(void)
{
    gRealInputs = sBufferedInputs;

    sBufferedInputs.held = 0;
    sBufferedInputs.pressed = 0;
    sBufferedInputs.repeated = 0;
    sBufferedInputs.shortPress = 0;

    sUnusedInputsRelated.unk0 = 0xFFFF;
    sUnusedInputsRelated.unk2 = -1;
    sUnusedInputsRelated.unk4 = -1;
    sUnusedInputsRelated.unk6 = -1;
    sUnusedInputsRelated.unk8 = -1;
    sUnusedInputsRelated.unkA = -1;
    sUnusedInputsRelated.unkC = -1;
    sUnusedInputsRelated.unkE = -1;
    sUnusedInputsRelated.unk10 = -1;
    sUnusedInputsRelated.unk12 = -1;
    sUnusedInputsRelated.unk14 = -1;
    sUnusedInputsRelated.unk16 = -1;

    sUnusedInputsRelated.unk28 = 0;
    sUnusedInputsRelated.unk29 = 0;
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
    sCurrentInputs.repeatTimerDpad = 0;
    sCurrentInputs.heldDpad = 0;
    sInputTimers.holdTimerB = 999;
    sInputTimers.holdTimerR = 999;
}

void UnpressButtons(void)
{
    gRealInputs.pressed = 0;
    sBufferedInputs.pressed = 0;
    sCurrentInputs.pressed = 0;
}

void ResetUnusedInputStruct(void)
{
    sUnusedInputsRelated.unk20 = 5;
    sUnusedInputsRelated.unk24 = 0;
    sUnusedInputsRelated.unk0 = 0xFFFF;
    sUnusedInputsRelated.unk2 = -1;
    sUnusedInputsRelated.unk4 = -1;
    sUnusedInputsRelated.unk6 = -1;
    sUnusedInputsRelated.unk8 = -1;
    sUnusedInputsRelated.unkA = -1;
    sUnusedInputsRelated.unkC = -1;
    sUnusedInputsRelated.unkE = -1;
    sUnusedInputsRelated.unk10 = -1;
    sUnusedInputsRelated.unk12 = -1;
    sUnusedInputsRelated.unk14 = -1;
    sUnusedInputsRelated.unk16 = -1;

    sUnusedInputsRelated.unk28 = 0;
    sUnusedInputsRelated.unk29 = 0;
}

void UpdateInput(void)
{
    sPrevInputs = sCurrentInputs;

    ReadKeyInput(&sCurrentInputs);

    sCurrentInputs.pressed = (sPrevInputs.held ^ sCurrentInputs.held) & sCurrentInputs.held;

    if (sCurrentInputs.held) {
        if ((sCurrentInputs.heldDpad & DPAD_ANY) == (sCurrentInputs.held & DPAD_ANY)) {
            if (sCurrentInputs.repeatTimerDpad < 50)
                sCurrentInputs.repeatTimerDpad++;
        }
        else {
            sCurrentInputs.heldDpad = sCurrentInputs.held & DPAD_ANY;
            sCurrentInputs.repeatTimerDpad = 1;
        }
    }
    else {
        sCurrentInputs.repeatTimerDpad = 0;
        sCurrentInputs.heldDpad = 0;
    }

    if (sCurrentInputs.repeatTimerDpad == 1) {
        sCurrentInputs.repeated = (sCurrentInputs.heldDpad & DPAD_ANY) | sCurrentInputs.pressed;
    }
    else if (sCurrentInputs.repeatTimerDpad == 48) {
        sCurrentInputs.repeatTimerDpad = 43;
        sCurrentInputs.repeated = (sCurrentInputs.heldDpad & DPAD_ANY) | sCurrentInputs.pressed;
    }
    else
        sCurrentInputs.repeated = 0;

    sCurrentInputs.shortPress = 0;

    if (sCurrentInputs.held & B_BUTTON) {
        if (sInputTimers.holdTimerB < 100)
            sInputTimers.holdTimerB++;
    }
    else if (1 < sInputTimers.holdTimerB && sInputTimers.holdTimerB < 12) {
        sCurrentInputs.shortPress = B_BUTTON;
        sInputTimers.holdTimerB = 0;
    }
    else
        sInputTimers.holdTimerB = 0;

    if (sCurrentInputs.held & R_BUTTON) {
        if (sInputTimers.holdTimerR < 100)
            sInputTimers.holdTimerR++;
    }
    else if (1 < sInputTimers.holdTimerR && sInputTimers.holdTimerR < 12) {
        sCurrentInputs.shortPress |= R_BUTTON;
        sInputTimers.holdTimerR = 0;
    }
    else
        sInputTimers.holdTimerR = 0;

    sBufferedInputs.held |= sCurrentInputs.held;
    sBufferedInputs.pressed |= sCurrentInputs.pressed;
    sBufferedInputs.repeated |= sCurrentInputs.repeated;
    sBufferedInputs.shortPress |= sCurrentInputs.shortPress;

    sUnusedScrambledInputJunk[0] *= sCurrentInputs.held | 0x54A1C41; // very similar to odd constant in InitInput - probably keymashing
}