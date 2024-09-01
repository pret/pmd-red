#include "global.h"
#include "code_800E9A8.h"
#include "code_800E9E4.h"

s32 sub_800E2C0(u32);

struct unkStruct_203B0CC *gUnknown_203B0CC;

bool8 sub_800E9A8(s32 a0)
{
    s32 i;
    struct unkStruct_203B0CC_sub *ptr;

    if (a0 == -1)
        return FALSE;

    ptr = gUnknown_203B0CC->unk0;
    for (i = 0; i < 32; i++, ptr++) {
        if (ptr->unk4 == a0) {
            if (ptr->unk54 != 0)
                return FALSE;
            return TRUE;
        }
    }

    return FALSE;
}

bool8 sub_800E9E4(u32 param_1)
{
    if(sub_800E2C0(param_1) != -1)
    {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

bool8 sub_800E9FC(u8 a0)
{
    s32 i;
    struct unkStruct_203B0CC_sub *ptr;


    ptr = gUnknown_203B0CC->unk0;
    for (i = 0; i < 32; i++, ptr++) {
        if (ptr->unk4 != -1) {
            if(a0 != 0)
                return TRUE;
            if (ptr->unk54 == 0)
                return TRUE;
        }
    }

    if(sub_800EC74())
        return TRUE;
    return FALSE;
}
