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
    u16 unk4;
    u16 unk6;
} InputTimers;

// size: 0x2C
typedef struct UnusedInputStruct
{
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u16 unk8;
    u16 unkA;
    u16 unkC;
    u16 unkE;
    u16 unk10;
    u16 unk12;
    u16 unk14;
    u16 unk16;
    u16 unk18;
    u16 unk1A;
    u16 unk1C;
    u16 unk1E;
    u32 unk20;
    u16 unk24;
    u16 unk26;
    u8 unk28;
    u8 unk29;
} UnusedInputStruct;

// size: 0xC
typedef struct MenuInputStructSub
{
    u8 unk0;
    /* 0x1 */ u8 a_button;
    /* 0x2 */ u8 b_button;
    /* 0x3 */ u8 dpad_right;
    /* 0x4 */ u8 dpad_left;
    u8 fill5[3];
    u16 unk8;
    s16 unkA;
} MenuInputStructSub;

// size: 0x34
typedef struct MenuInputStruct
{
    s32 unk0;
    u16 unk4;
    s16 unk6;
    s16 unk8; // Maybe Position
    s16 unkA;
    s16 unkC; // Maybe Position
    s16 unkE;
    u32 unk10;
    s16 unk14; // Maybe Position
    s16 unk16;
    /* 0x18 */ s16 menuIndex;
    s16 unk1A;
    s16 unk1C;
    s16 unk1E;
    s16 unk20;
    s16 unk22;
    u16 unk24;
    u16 unk26;
    MenuInputStructSub unk28;
} MenuInputStruct;

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