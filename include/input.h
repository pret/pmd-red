#ifndef GUARD_INPUT_H
#define GUARD_INPUT_H  

struct UnkInputStruct1
{
    /* 0x0 */ u16 held;
    /* 0x2 */ u16 pressed;
    /* 0x4 */ u16 repeated;
    /* 0x6 */ u16 shortPress;
    /* 0x8 */ u16 heldDpad;
    /* 0xA..0xB - padding */
    /* 0xC */ s32 repeatTimerDpad;
};

struct UnkInputStruct2
{
    /* 0x0 */ s16 holdTimerB;
    /* 0x2 */ s16 holdTimerR;
    /* 0x4 */ u16 unk4;
    /* 0x6 */ u16 unk6;
};

struct Input
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
    /* 0x16 */ u16 unk18;
    /* 0x1A */ u16 unk1A;
    /* 0x1C */ u16 unk1C;
    /* 0x1E */ u16 unk1E;
    /* 0x20 */ u32 unk20;
    /* 0x24 */ u16 unk24;
    /* 0x24 */ u16 unk26;
    /* 0x28 */ u8 unk28;
    /* 0x29 */ u8 unk29;
    /* 0x2A */ u8 unk2A;
    /* 0x2B */ u8 padding;
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
void sub_8004914(void);
void UpdateInput(void);

#endif // GUARD_INPUT_H
