#ifndef GUARD_CODE_801D9E4_H
#define GUARD_CODE_801D9E4_H

#include "menu.h"
#include "structs/str_text.h"

// size: 0xA0
struct unkStruct_203B258
{
    /* 0x0 */ MenuInputStruct input;
    u32 unk34;
    UnkTextStruct2 *unk38;
    UnkTextStruct2 unk3C[4];
    u8 unk9C[4];
};

// size: 0x1C
struct unkStruct_81188F0
{
    /* 0x0 */ u8 *text1;
    /* 0x4 */ u8 *text2;
    /* 0x8 */ u8 *text3;
    /* 0xC */ u8 *text4;
    /* 0x10 */ u32 unk1;
    /* 0x14 */ u32 unk2;
    /* 0x18 */ u32 unk3;
};

bool8 sub_801D9E4(void);
void sub_801DA58(s16);
u32 sub_801DA78(void);
s16 sub_801DAC0(void);
void sub_801DB0C(void);

#endif // GUARD_CODE_801D9E4_H