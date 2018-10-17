#include "global.h"

extern u32 gUnknown_203B17C;
extern u32 gUnknown_203B180;
extern u32 gUnknown_202DE28;

u32 sub_8011C1C(void)
{
    return gUnknown_203B17C;
}

void sub_8011C28(u32 in)
{
    gUnknown_203B17C = in;
}

u32 sub_8011C34(void)
{
    return gUnknown_202DE28;
}

void sub_8011C40(u32 in)
{
    gUnknown_202DE28 = in;
}

u32 sub_8011C4C(void)
{
    return gUnknown_203B180;
}

void sub_8011C58(u32 *out, u32 len)
{
    u32 sum = 0;
    s32 i = len / 4;
    if (i > 1)
    {
        u32 *ptr = &out[1];
        --i;
        do
            sum += *ptr++;
        while (--i);
    }
    *out = sum;
}