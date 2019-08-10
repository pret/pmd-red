#include "global.h"

extern u32 gUnknown_203B17C;
extern u32 gUnknown_203B180;
extern u32 *gUnknown_203B184;
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

void CalculateChecksum(u8 *out, u32 size)
{
    u32 checksum = 0;
    s32 i = size / 4;
    if (i > 1)
    {
        u32 *ptr = (u32 *)&out[4];
        --i;
        do
            checksum += *ptr++;
        while (--i);
    }
    *(u32 *)out = checksum;
}

bool8 ValidateChecksum(u8 *in, u32 size)
{
    u32 checksum = 0;
    s32 i = size / 4;
    if (i > 1)
	{
        u32 *ptr = (u32 *)&in[4];
        --i;
        do
            checksum += *ptr++;
        while (--i);
	}
    if (*(u32 *)in != checksum)
        return TRUE;
    return FALSE;
}
