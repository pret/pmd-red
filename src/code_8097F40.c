#include "global.h"

extern u8 gUnknown_810ACC0[];
extern u8 *gUnknown_203B498;
extern u8 gUnknown_2039840;

bool8 sub_8097F40(u32 r0)
{
    bool8 temp;
    temp = FALSE;
    if(gUnknown_810ACC0[r0] == 2)
    {
        temp = TRUE;
    }
    return temp;

}

void sub_8097F5C(void)
{
    gUnknown_203B498 = &gUnknown_2039840;
}

u8 *sub_8097F6C(void)
{
    return &gUnknown_2039840;
}

