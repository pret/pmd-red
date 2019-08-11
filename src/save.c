#include "global.h"

extern u32 gUnknown_203B17C;
extern u32 gUnknown_203B180;
extern vu32 gUnknown_203B184;
extern u32 gUnknown_202DE28;

extern s32 ReadFlashData(s32 sector, u8 *src, s32 size);
extern s32 WriteFlashData(s32 sector, u8 *src, s32 size);
extern bool8 sub_800DAB0(u16, u8*, s32);
extern bool8 sub_800DAB4(u16, u8*, s32);
extern bool8 sub_800DAB8(void);

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

void sub_8011CA8(u32 *out, s32 b)
{
    gUnknown_203B184; // Needed to match
    *out += (b + 0xFFF) / 0x1000;
}

u32 WriteSaveSector(u32 *a, u8 *b, s32 size, u32 d)
{
    u32 r6 = *a;
    u32 num;
    sub_8011CA8(a, size);
    CalculateChecksum(b, size);
    if (!gUnknown_203B184) {
        num = WriteFlashData(r6, b, size);
    }
    else if (sub_800DAB8()) {
        num = sub_800DAB4(r6, b, size) ? 0 : 3;
    }
    else {
        return 2;
    }
    if (num == 4) {
        return 1;
    }
    else if (num) {
        return 2;
    }
    else {
        return 0;
    }
}

u32 ReadSaveSector(u32 *a, u8 *b, s32 size, u32 d)
{
    u32 r6 = *a;
    u32 num;
    sub_8011CA8(a, size);
    if (!gUnknown_203B184) {
        num = ReadFlashData(r6, b, size);
    }
    else if (sub_800DAB8()) {
        if (!sub_800DAB0(r6, b, size)) {
            num = 1;
        }
        else {
            num = 0;
        }
    }
    else {
        return 1;
    }
    if (num) {
        return 1;
    }
    if (ValidateChecksum(b, size)) {
        return 2;
    }
    return 0;    
}
