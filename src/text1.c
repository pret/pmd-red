#include "global.h"
#include "file_system.h"
#include "code_800558C.h"
#include "code_800B540.h"
#include "text1.h"

EWRAM_DATA struct UnkTextStruct1 gUnknown_2027370[4];
EWRAM_DATA u8 *gCharmaps[2];
EWRAM_DATA u16 gCharacterSpacing;
EWRAM_DATA u8 gUnknown_20274A5;
EWRAM_DATA u32 gCurrentCharmap;
EWRAM_DATA vu32 gUnknown_20274B0;
EWRAM_DATA u8 gUnknown_20274B4[0x3b00];
EWRAM_DATA struct OpenedFile *gCharmapFiles[2];
EWRAM_DATA struct UnkTextStruct2 gUnknown_202AFC0[4];
EWRAM_DATA u32 gUnknown_202B020;
EWRAM_DATA u32 gUnknown_202B024;
EWRAM_DATA u32 gUnknown_202B028[2];
EWRAM_DATA u32 gUnknown_202B030;
EWRAM_DATA u8 gUnknown_202B034;
EWRAM_DATA u16 gUnknown_202B038[2][32][32];

// ?
extern char gUnknown_3000E94[];

// data.s
extern const struct UnkTextStruct2 gUnknown_80B857C[4];
extern const u32 gUnknown_80B87C4[8];
extern const u32 gUnknown_80B87E4[8];
extern const u32 gUnknown_80B8804[4];
extern const u32 gUnknown_80B8814[];
extern const char gKanjiA_file_string[];
extern const char gKanjiB_file_string[];
// system_sbin.s
extern const struct FileArchive gSystemFileArchive;

// text.s
extern void sub_800898C(void);
extern void sub_80089AC(const struct UnkTextStruct2 *, struct UnkTextStruct2_sub *);
extern void sub_8009388(void);

void sub_8006438(const struct UnkTextStruct2 *, u8, u8, struct UnkTextStruct2_sub *);

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

void sub_800641C(struct UnkTextStruct2 *a0, u8 a1, u8 a2)
{
    struct UnkTextStruct2_sub r3 = {0, 0};
    sub_8006438(a0, a1, a2, &r3);
}

void sub_8006438(const struct UnkTextStruct2 *a0, u8 a1, u8 a2, struct UnkTextStruct2_sub *a3)
{
    int i;
    u32 r9 = 2;

    if (a0 == NULL)
        a0 = gUnknown_80B857C;
    if (a2)
        sub_8009388();

    sub_800898C();

    for (i = 0; i < 4; i++) {
        gUnknown_202AFC0[i] = a0[i];

        if (a0[i].unkC) {
            sub_8006554(gUnknown_2027370, (void *)VRAM, gUnknown_20274B4, &gUnknown_202B038[0][0][0], gUnknown_80B8804[i], a0 + i, a1, r9, a3, 0);
            sub_80089AC(a0 + i, a3);
            r9 += a0[i].unkC * a0[i].unk10;
        }
    }

#ifdef NONMATCHING
    gUnknown_203B078 = gUnknown_3000E94;
    gUnknown_20274A5 = 1;
#else
    asm_unified("\tldr r2, =gUnknown_203B078\n"
        "\tldr r0, =gUnknown_3000E94\n"
        "\tldr r1, =gUnknown_20274A5\n"
        "\tstr r0, [r2]\n"
        "\tmovs r0, 0x1\n"
        "\tstrb r0, [r1]");
#endif
}