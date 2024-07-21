#include "global.h"
#include "code_800E9A8.h"

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