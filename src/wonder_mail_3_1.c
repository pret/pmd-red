#include "global.h"
#include "code_80A26CC.h"

bool8 sub_802FCF0(void)
{
    s32 i;

    for (i = 0; i < 0x2E; i++) {
        if (sub_80A27CC(i))
            return FALSE;
    }

    return TRUE;
}