#ifndef GUARD_CODE_8004AA0_H
#define GUARD_CODE_8004AA0_H

#include "file_system.h"
#include "structs/rgb.h"

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

extern unkStruct_202EE8C gUnknown_202EE8C[32];

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

extern struct UnkBgStruct *gUnknown_203B0E4;

// size: Variable
typedef struct unkDataFor8004AA4
{
    /* 0x0 */ s16 colorCount;
    s16 unk2;
    /* 0x4 */ RGB colors[0];
} unkDataFor8004AA4;

void nullsub_6(void);
void sub_8004AA4(unkStruct_202EE8C *, OpenedFile *, s32);
bool8 sub_8004AF0(bool8, unkStruct_202EE8C *, s32, s32, s32, const RGB *);
bool8 sub_8004D14(unkStruct_202EE8C *, s32);
bool8 sub_8004D40(unkStruct_202EE8C *, s32);

#endif // GUARD_CODE_8004AA0_H
