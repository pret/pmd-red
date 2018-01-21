// ------------------------
// TEXT.C
// Decompiled by PikalaxALT
// ------------------------

#include "global.h"
#include "file_system.h"
#include "code_800558C.h"
#include "code_800B540.h"

struct UnkTextStruct1 {
    u8 fill00[4];
    u16 unk04;
    u8 fill06[2];
    u16 unk08;
    u8 fill04[0x3c];
    u8 unk46;
};

EWRAM_DATA struct UnkTextStruct1 gUnknown_2027370[4];
EWRAM_DATA u8 *gUnknown_2027490[2];
EWRAM_DATA u16 gUnknown_2027498;
EWRAM_DATA u8 gUnknown_20274A5;
EWRAM_DATA u32 gUnknown_20274AC;
EWRAM_DATA vu32 gUnknown_20274B0;
EWRAM_DATA struct OpenedFile *gUnknown_202AFB4[2];
EWRAM_DATA u32 gUnknown_202B020;
EWRAM_DATA u32 gUnknown_202B024;
EWRAM_DATA u32 gUnknown_202B028[2];
EWRAM_DATA u32 gUnknown_202B030;
EWRAM_DATA u8 gUnknown_202B034;
EWRAM_DATA u16 gUnknown_202B038[2][32][32];

u32 xxx_update_some_bg_tiles(u32 a0);

extern const char gUnknown_80B87B4[];
extern const char gUnknown_80B87BC[];
extern const struct FileArchive gUnknown_8300500;
extern const u32 gUnknown_80B87C4[8];
extern const u32 gUnknown_80B87E4[8];

void sub_8006218(void)
{
    int i;
    int j;
    int k;

    gUnknown_20274AC = 0;
    gUnknown_202AFB4[0] = OpenFileAndGetFileDataPtr(gUnknown_80B87B4, &gUnknown_8300500);
    gUnknown_202AFB4[1] = OpenFileAndGetFileDataPtr(gUnknown_80B87BC, &gUnknown_8300500);
    gUnknown_2027490[0] = gUnknown_202AFB4[0]->data;
    gUnknown_2027490[1] = gUnknown_202AFB4[1]->data;
    gUnknown_202B028[0] = 11;
    gUnknown_202B028[1] = 12;
    for (k = 0; k < 4; k++)
    {
        gUnknown_2027370[k].unk04 = 0;
        gUnknown_2027370[k].unk08 = 0;
        gUnknown_2027370[k].unk46 = 0;
    }
    gUnknown_2027498 = 0;
    for (i = 0; i < 20; i++)
    {
        gUnknown_202B038[0][i][0] = 0xf279;
        gUnknown_202B038[1][i][0] = 0xf27a;
        for (j = 1; j < 32; j++)
        {
            gUnknown_202B038[0][i][j] = 0;
            gUnknown_202B038[1][i][j] = 0xf27a;
        }
    }
    gUnknown_202B034 = 1;
    gUnknown_202B030 = 0x88888888;
    gUnknown_203B078 = 0;
    gUnknown_20274A5 = 0;
    gUnknown_202B020 = 1;
    gUnknown_202B024 = 20;
    xxx_update_some_bg_tiles(0);
}

u32 xxx_update_some_bg_tiles(u32 a0)
{
    u32 r5 = gUnknown_20274B0;
    u32 *r4 = (u32 *)(VRAM + 0x4f40);
    const u32 *r2;
    gUnknown_20274B0 = a0;
    if (a0 == 0 || a0 == 2)
    {
        sub_800CDA8(2);
        r2 = gUnknown_80B87C4;
    }
    else
    {
        sub_800CDA8(1);
        r2 = gUnknown_80B87E4;
    }
    gUnknown_202B030 = 0x88888888;
    *r4++ = *r2++;
    *r4++ = *r2++;
    *r4++ = *r2++;
    *r4++ = *r2++;
    *r4++ = *r2++;
    *r4++ = *r2++;
    *r4++ = *r2++;
    *r4++ = *r2++;
    return r5;
}

u32 sub_80063B0(void)
{
    return gUnknown_20274B0;
}

u8 sub_80063BC(u8 a0)
{
    u8 retval = gUnknown_202B034;
    gUnknown_202B034 = a0;
    return retval;
}

void sub_80063CC(u32 a0)
{
    gUnknown_20274AC = a0;
}

void sub_80063D8(int a0)
{
    u32 retval;
    if (a0 == 0)
    {
        gUnknown_20274B0;
        retval = 0x88888888;
    }
    else
    {
        retval = (a0 & 0xf) | ((a0 & 0xf) << 4);
        retval |= ((a0 & 0xf) << 8);
        retval |= ((a0 & 0xf) << 12);
        retval |= ((a0 & 0xf) << 16);
        retval |= ((a0 & 0xf) << 20);
        retval |= ((a0 & 0xf) << 24);
        retval |= ((a0 & 0xf) << 28);
    }
    gUnknown_202B030 = retval;
}
