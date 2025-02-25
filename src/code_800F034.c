#include "global.h"
#include "globaldata.h"
#include <stdio.h>
#include "code_800E9E4.h"
#include "file_system.h"
#include "memory.h"

struct unkStruct_800F18C
{
    s32 effectID;
    u32 counter;
};

struct unkStruct_203B0D4
{
    struct unkStruct_800F18C unk0[2];
};

extern struct unkStruct_203B0D4 *gUnknown_203B0D4;

ALIGNED(4) static const u8 gUnknown_80CE77C[] = "efob%03d";
ALIGNED(4) static const u8 gUnknown_80CE788[] = "efbg%03d";

extern struct FileArchive gEffectFileArchive;

void sub_800F034(void) {
    s32 index;
    if(gUnknown_203B0D4 == NULL)
    {
        gUnknown_203B0D4 = MemoryAlloc(sizeof(struct unkStruct_203B0D4), 0xB);
        MemoryClear8(gUnknown_203B0D4, sizeof(struct unkStruct_203B0D4));
    }
    for(index = 0; index < 2; index++)
    {
        gUnknown_203B0D4->unk0[index].effectID = -1;
        gUnknown_203B0D4->unk0[index].counter = 0;
    }
}

void sub_800F078(void)
{
    if(gUnknown_203B0D4)
    {
        MemoryFree(gUnknown_203B0D4);
        gUnknown_203B0D4 = NULL;
    }
}

void sub_800F094(void)
{
    s32 index;
    for(index = 0; index < 2; index++)
    {
        gUnknown_203B0D4->unk0[index].effectID = -1;
        gUnknown_203B0D4->unk0[index].counter = 0;
    }
}

s32 sub_800F0C0(s32 animType, s32 effectID)
{
    if (animType == 3) {
        if (gUnknown_203B0D4->unk0[0].effectID == effectID) return 0;
    }
    else {
        if (gUnknown_203B0D4->unk0[1].effectID == effectID) return 1;
    }
    return -3;
}


s32 sub_800F0F4(s32 animType, s32 effectID)
{
    if (animType == 3) {
        if (gUnknown_203B0D4->unk0[0].effectID == effectID) return -2;
        if (gUnknown_203B0D4->unk0[0].counter == 0) return 0;
    }
    else {
        if (gUnknown_203B0D4->unk0[1].effectID == effectID) return -2;
        if (gUnknown_203B0D4->unk0[1].counter == 0) return 1;
    }
    return -1;
}

void sub_800F13C(s32 index, OpenedFile *file, unkStruct_80B9CC4 * r2)
{
    if(gUnknown_203B0D4->unk0[index].counter == 0)
        gUnknown_203B0D4->unk0[index].effectID = r2->effectId;
}

void sub_800F15C(s32 effectID)
{
    s32 index;

    for(index = 0; index < 2; index++)
    {
        if(gUnknown_203B0D4->unk0[index].effectID == effectID)
        {
            gUnknown_203B0D4->unk0[index].counter++;
            break;
        }
    }
}

struct unkStruct_800F18C *sub_800F18C(s32 index)
{
   return &gUnknown_203B0D4->unk0[index];
}

s32 sub_800F19C(s32 index)
{
    if(gUnknown_203B0D4->unk0[index].counter == 0)
        return 0;
    else
        return 1;
}

OpenedFile * sub_800F1C0(u32 animType, s32 effectID)
{
    u8 fileName [8];

    switch(animType)
    {
        case 1:
        case 2:
        case 3:
            sprintf(fileName,gUnknown_80CE77C,effectID); // efob
            break;
        case 4:
            sprintf(fileName,gUnknown_80CE788,effectID); // efbg
            break;

    }
    return Call_OpenFileAndGetFileDataPtr(fileName,&gEffectFileArchive);
}

void sub_800F204(OpenedFile *file)
{
    CloseFile(file);
}

