#ifndef GUARD_CODE_8004AA0_H
#define GUARD_CODE_8004AA0_H

#include "file_system.h"

// size: 0x4
struct RGB
{
    // IDK which is R G B
    u8 unk0;
    u8 unk1;
    u8 unk2;
};

// size: 0x18
struct unkStruct_202EE8C
{
    u32 unk0;
    u16 unk4;
    s16 unk6;
    struct RGB *unk8;
    struct RGB *unkC;
    struct RGB *unk10;
    struct RGB unk14;
};

// size: Variable
struct unkDataFor8004AA4
{
    /* 0x0 */ s16 colorCount;
    s16 unk2;
    /* 0x4 */ struct RGB colors[0];
};

void nullsub_6(void);
void sub_8004AA4(struct unkStruct_202EE8C *, struct OpenedFile *, s32);
bool8 sub_8004AF0(bool8, struct unkStruct_202EE8C *, s32, s32, s32, u8 *);
bool8 sub_8004D14(struct unkStruct_202EE8C *, s32);
bool8 sub_8004D40(struct unkStruct_202EE8C *, s32);

#endif // GUARD_CODE_8004AA0_H