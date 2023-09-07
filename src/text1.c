#include "global.h"
#include "code_800558C.h"
#include "cpu.h"
#include "file_system.h"
#include "text1.h"
#include "text2.h"

extern UnkTextStruct1 gUnknown_2027370[4];
extern u8 *gCharmaps[2];
extern s16 gCharacterSpacing;
extern u8 gUnknown_20274A5;
extern u32 gCurrentCharmap;
extern vu32 gUnknown_20274B0;
extern u32 gUnknown_20274B4[0xEC0];
extern OpenedFile *gCharmapFiles[2]; // 202AFB4
// u32 unused // 202AFBC
extern UnkTextStruct2 gUnknown_202AFC0[4];
extern u32 gUnknown_202B020;
extern u32 gUnknown_202B024;
extern u32 gUnknown_202B028[2];
extern u32 gUnknown_202B030; // Some text color info is stored; retrieve via "& 0xF"
extern u8 gUnknown_202B034;
extern u16 gUnknown_202B038[4][32][32];

// ?
extern s16 gUnknown_3000E94[];

// data.s
extern const UnkTextStruct2 gUnknown_80B857C[4];
extern const u32 gUnknown_80B87C4[8];
extern const u32 gUnknown_80B87E4[8];
extern const u32 gUnknown_80B8804[4];
extern const u32 gUnknown_80B8814[];
extern const char gKanjiA_file_string[];
extern const char gKanjiB_file_string[];
// system_sbin.s
extern const struct FileArchive gSystemFileArchive;

static void sub_8006438(const UnkTextStruct2 *, bool8, bool8, UnkTextStruct2_sub *);

void LoadCharmaps(void)
{
    int i;
    int j;
    int k;

    gCurrentCharmap = 0;
    gCharmapFiles[0] = OpenFileAndGetFileDataPtr(gKanjiA_file_string, &gSystemFileArchive);
    gCharmapFiles[1] = OpenFileAndGetFileDataPtr(gKanjiB_file_string, &gSystemFileArchive);
    gCharmaps[0] = gCharmapFiles[0]->data;
    gCharmaps[1] = gCharmapFiles[1]->data;
    gUnknown_202B028[0] = 11;
    gUnknown_202B028[1] = 12;

    for (k = 0; k < 4; k++) {
        gUnknown_2027370[k].unk4 = 0;
        gUnknown_2027370[k].unk8 = 0;
        gUnknown_2027370[k].unk46 = 0;
    }

    gCharacterSpacing = 0;

    for (i = 0; i < 20; i++) {
        gUnknown_202B038[0][i][0] = 0xf279;
        gUnknown_202B038[1][i][0] = 0xf27a;

        for (j = 1; j < 32; j++) {
            gUnknown_202B038[0][i][j] = 0;
            gUnknown_202B038[1][i][j] = 0xf27a;
        }
    }

    gUnknown_202B034 = 1;
    gUnknown_202B030 = 0x88888888;
    gUnknown_203B078 = NULL;
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

    if (a0 == 0 || a0 == 2) {
        sub_800CDA8(2);
        r2 = gUnknown_80B87C4;
    }
    else {
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

void SelectCharmap(u32 a0)
{
    gCurrentCharmap = a0;
}

void sub_80063D8(int a0)
{
    u32 retval;
    if (a0 == 0) {
        gUnknown_20274B0;
        retval = 0x88888888;
    }
    else {
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

// TODO: Move sub_800641C and sub_8006438 to text2.c ?
void sub_800641C(UnkTextStruct2 *a0, bool8 a1, bool8 a2)
{
    UnkTextStruct2_sub r3 = {0, 0};
    sub_8006438(a0, a1, a2, &r3);
}

static void sub_8006438(const UnkTextStruct2 *a0, bool8 a1, bool8 a2, UnkTextStruct2_sub *a3)
{
    s32 i;
    u32 r9;
    #if NONMATCHING // Simple regswap: https://decomp.me/scratch/EN6n0 99.79%
    s16 **ptr2; // r2
    #else
    register s16 **ptr2 asm("r2");
    #endif
    s16 *ptr0; // r0
    u8 *ptr1; // r1

    r9 = 2;

    if (a0 == NULL)
        a0 = gUnknown_80B857C;
    if (a2)
        sub_8009388();

    sub_800898C();

    for (i = 0; i < 4; i++) {
        gUnknown_202AFC0[i] = a0[i];

        if (a0[i].unkC) {
            sub_8006554(gUnknown_2027370, (u32 *)VRAM, gUnknown_20274B4, &gUnknown_202B038[0][0][0], gUnknown_80B8804[i], a0 + i, a1, r9, a3, 0);
            sub_80089AC(a0 + i, a3);
            r9 += a0[i].unkC * a0[i].unk10;
        }
    }

    ptr2 = &gUnknown_203B078;
    ptr0 = gUnknown_3000E94;
    ptr1 = &gUnknown_20274A5;
    *ptr2 = ptr0;
    *ptr1 = 1;
}