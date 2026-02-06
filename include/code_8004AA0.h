#ifndef GUARD_CODE_8004AA0_H
#define GUARD_CODE_8004AA0_H

#include "structs/str_202EE8C.h"
#include "structs/str_file_system.h"

extern unkStruct_202EE8C gUnknown_202EE8C[32];

// size: Variable
typedef struct unkDataFor8004AA4
{
    /* 0x0 */ s16 colorCount;
    s16 unk2;
    /* 0x4 */ RGB_Struct colors[0];
} unkDataFor8004AA4;

void nullsub_6(void);
void sub_8004AA4(unkStruct_202EE8C *, OpenedFile *, s32);
bool8 sub_8004AF0(bool8, unkStruct_202EE8C *, s32, s32, s32, const RGB_Struct *);
bool8 sub_8004C00(unkStruct_202EE8C *a0, s32 a1, s32 a2, s32 brightness, const RGB_Struct *ramp, RGB_Struct16 *a5);
bool8 sub_8004D14(unkStruct_202EE8C *, s32);
bool8 sub_8004D40(unkStruct_202EE8C *, s32);

#endif // GUARD_CODE_8004AA0_H
