#ifndef GUARD_CODE_8010EF0_H
#define GUARD_CODE_8010EF0_H

#include "file_system.h"

// size: 0x4
typedef struct RGB
{
    // IDK which is R G B
    u8 unk0;
    u8 unk1;
    u8 unk2;
} RGB;

// size: 0x18
typedef struct unkStruct_202EE8C
{
    u32 unk0;
    u16 unk4;
    s16 unk6;
    RGB *unk8;
    RGB *unkC;
    RGB *unk10;
    RGB unk14;
} unkStruct_202EE8C;

// size: 0x4DD8
struct UnkBgStruct
{
    OpenedFile *unk0[5];
    u8 padding[0x4C4C - 0x14];
    unkStruct_202EE8C unk4C4C[16];
    u32 unk4DCC;
    u32 unk4DD0;
    /* 0x4DD4 */ s16 xoffset;
    /* 0x4DD6 */ s16 yoffset;
};

void sub_8010EF0(void);

#endif
