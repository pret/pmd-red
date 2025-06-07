#ifndef GUARD_CODE_8004AA0_H
#define GUARD_CODE_8004AA0_H

#include "file_system.h"
#include "structs/rgb.h"
#include "structs/str_202EE8C.h"

extern unkStruct_202EE8C gUnknown_202EE8C[32];

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
