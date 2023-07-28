#include "global.h"
#include "text.h"

extern struct UnkTextStruct2 gUnknown_202AFC0[4];
extern u32 gUnknown_80B8814[];

void nullsub_152(void)
{
}

void sub_8006518(struct UnkTextStruct2 *unkData)
{
    s32 iVar2;
    for (iVar2 = 0; iVar2 < 4; iVar2++)
        unkData[iVar2] = gUnknown_202AFC0[iVar2];
}

void nullsub_153(void)
{
}

u32 sub_8006544(u32 index)
{
    return gUnknown_80B8814[index];
}