#include "global.h"
#include "globaldata.h"
#include "effect_sub_2.h"
#include "effect_data.h"
#include "memory.h"
#include "file_system.h"

struct unkStruct_203B0D4
{
    unkStruct_800F18C unk0[2];
};

static EWRAM_INIT struct unkStruct_203B0D4 *gUnknown_203B0D4 = NULL;

void sub_800F034(void)
{
    s32 index;
    if (gUnknown_203B0D4 == NULL) {
        gUnknown_203B0D4 = MemoryAlloc(sizeof(struct unkStruct_203B0D4), MEMALLOC_GROUP_11);
        MemoryClear8(gUnknown_203B0D4, sizeof(struct unkStruct_203B0D4));
    }

    for (index = 0; index < 2; index++) {
        gUnknown_203B0D4->unk0[index].effectID = -1;
        gUnknown_203B0D4->unk0[index].counter = 0;
    }
}

void sub_800F078(void)
{
    TRY_FREE_AND_SET_NULL(gUnknown_203B0D4);
}

void sub_800F094(void)
{
    s32 index;
    for (index = 0; index < 2; index++) {
        gUnknown_203B0D4->unk0[index].effectID = -1;
        gUnknown_203B0D4->unk0[index].counter = 0;
    }
}

UNUSED static s32 sub_800F0C0(s32 animType, s32 effectID)
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

void sub_800F13C(s32 index, OpenedFile *file, const unkStruct_80B9CC4 *r2)
{
    if (gUnknown_203B0D4->unk0[index].counter == 0)
        gUnknown_203B0D4->unk0[index].effectID = r2->effectId;
}

void sub_800F15C(s32 effectID)
{
    s32 index;

    for (index = 0; index < 2; index++) {
        if( gUnknown_203B0D4->unk0[index].effectID == effectID) {
            gUnknown_203B0D4->unk0[index].counter++;
            break;
        }
    }
}

unkStruct_800F18C *sub_800F18C(s32 index)
{
   return &gUnknown_203B0D4->unk0[index];
}

s32 sub_800F19C(s32 index)
{
    if (gUnknown_203B0D4->unk0[index].counter == 0)
        return 0;
    else
        return 1;
}

