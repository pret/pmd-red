#ifndef GUARD_INPUT_H
#define GUARD_INPUT_H  

struct Inputs
{
    /* 0x0 */ u16 held;
    /* 0x2 */ u16 pressed;
    /* 0x4 */ u16 repeated;
    /* 0x6 */ u16 shortPress;
    /* 0x8 */ u16 heldDpad;
    /* 0xA..0xB - padding */
    /* 0xC */ s32 repeatTimerDpad;
};

extern struct Inputs gRealInputs;

struct InputTimers
{
    /* 0x0 */ s16 holdTimerB;
    /* 0x2 */ s16 holdTimerR;
    /* 0x4 */ u16 unk4;
    /* 0x6 */ u16 unk6;
};

struct UnusedInputStruct
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
    /* 0x24 */ u16 unk26;
    /* 0x28 */ u8 unk28;
    /* 0x29 */ u8 unk29;
    /* 0x2A..0x2B - padding */
};

struct UnkInputStruct
{
    /* 0x0 */ u8 unk0;
    /* 0x1 */ u8 unk1;
    /* 0x2 */ u8 unk2;
    /* 0x3 */ u8 unk3;
    /* 0x4 */ u8 unk4;
    /* 0x5 */ u32 unk5;
    /* 0x9 */ u32 unk9;
    /* 0xD */ u32 unkD;
    /* 0x12 */ u32 unk11;
    /* 0x16 */ u32 unk15;
    /* 0x1A */ u32 unk19;
    /* 0x1E */ u32 unk1D;
    /* 0x24 */ u32 unk24;
    /* 0x28 */ u8 unk28;
    /* 0x29 */ u8 a_button;
    /* 0x2A */ u8 b_button;
    /* 0x2B */ u8 dpad_right;
    /* 0x2C */ u8 dpad_left;
};


void InitInput(void);
void LoadBufferedInputs(void);
u8 sub_80048B8(void);
u8 sub_80048BC(void);
u8 sub_80048C0(void);
u8 sub_80048C4(void);
u8 sub_80048C8(void);
u8 sub_80048CC(void);
void ResetRepeatTimers(void);
void UnpressButtons(void);
void ResetUnusedInputStruct(void);
void UpdateInput(void);

#endif // GUARD_INPUT_H
