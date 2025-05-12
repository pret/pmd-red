#ifndef GUARD_CODE_8023868_H
#define GUARD_CODE_8023868_H

#include "structs/struct_sub80095e4.h"

struct unkStruct_3001B60
{
    u32 unk0;
    u32 sortMethod;
    s32 unk8;
    u32 unkC;
    u32 unk10;
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
    u8 unk18;
    s16 unk1A[413];
    u8 unk354;
    struct_Sub80095E4_2 unk358;
};

// code_8023868.s
bool8 sub_8023868(u32 r5, u32 windowId, DungeonPos *pos, u32 r10);
extern u32 sub_8023A94(bool8);
extern s32 sub_8023B44(void);
void sub_8023B7C(bool8 addCursor);
extern void sub_8023C60(void);
extern void sub_8023DA4(void);
extern bool8 sub_8024108(s32);

#endif // GUARD_CODE_8023868_H
