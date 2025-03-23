#ifndef GUARD_INPUT_H
#define GUARD_INPUT_H

// size: 0x10
typedef struct Inputs
{
    /* 0x0 */ u16 held;
    /* 0x2 */ u16 pressed;
    /* 0x4 */ u16 repeated;
    /* 0x6 */ u16 shortPress;
    /* 0x8 */ u16 heldDpad;
    /* 0xC */ s32 repeatTimerDpad;
} Inputs;

// size: 0x8
typedef struct InputTimers
{
    /* 0x0 */ s16 holdTimerB;
    /* 0x2 */ s16 holdTimerR;
    /* 0x4 */ u16 unk4;
    /* 0x6 */ u16 unk6;
} InputTimers;

// size: 0x2C
typedef struct UnusedInputStruct
{
    /* 0x0 */ u16 unk0;
    /* 0x2 */ u16 unk2;
    /* 0x4 */ u16 unk4;
    /* 0x6 */ u16 unk6;
    /* 0x8 */ u16 unk8;
    /* 0xA */ u16 unkA;
    /* 0xC */ u16 unkC;
    /* 0xE */ u16 unkE;
    /* 0x10 */ u16 unk10;
    /* 0x12 */ u16 unk12;
    /* 0x14 */ u16 unk14;
    /* 0x16 */ u16 unk16;
    /* 0x18 */ u16 unk18;
    /* 0x1A */ u16 unk1A;
    /* 0x1C */ u16 unk1C;
    /* 0x1E */ u16 unk1E;
    /* 0x20 */ u32 unk20;
    /* 0x24 */ u16 unk24;
    /* 0x26 */ u16 unk26;
    /* 0x28 */ u8 unk28;
    /* 0x29 */ u8 unk29;
} UnusedInputStruct;

extern Inputs gRealInputs;

void InitInput(void);
void LoadBufferedInputs(void);
void ResetRepeatTimers(void);
void ResetUnusedInputStruct(void);
void UnpressButtons(void);
void UpdateInput(void);

bool8 sub_80048BC(void);
bool8 sub_80048C8(void);

#endif // GUARD_INPUT_H
