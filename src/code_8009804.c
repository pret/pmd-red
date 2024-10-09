#include "global.h"
#include "bg_palette_buffer.h"
#include "code_8009804.h"
#include "cpu.h"
#include "file_system.h"
#include "text1.h"

extern const u8 gUnknown_80B88CC[];
extern const struct FileArchive gSystemFileArchive; // 8300500

extern struct unkStruct_202D038 gFontPalette[8];
extern u8 gUnknown_202D238[4];
extern s32 gUnknown_202D23C;
extern struct unkStruct_202D240 gUnknown_202D240[8];

// code_8009804.s
extern void sub_8009A1C(u32);

void InitFontPalette(void)
{
    OpenedFile *fontpalFile;
    s32 i;
    u32 *ptr;

    fontpalFile = OpenFileAndGetFileDataPtr(gUnknown_80B88CC, &gSystemFileArchive); // fontpal
    CpuCopy(gFontPalette, fontpalFile->data, sizeof(gFontPalette));

    if (sub_80063B0() == 1)
        ptr = &gFontPalette[0].unk0[0];
    else
        ptr = &gFontPalette[1].unk0[0];

    for (i = 0; i < 16; ptr++, i++)
        SetBGPaletteBufferColorArray(i + 240, (u8 *)ptr);

    CloseFile(fontpalFile);
}

void vram_related_8009804(void)
{
    u32 i;
    u32 *dest;

    dest = (u32 *)VRAM;
    for (i = 0; i < 0x13C0; i++)
        *dest++ = 0;

    dest = (u32 *)0x06007000;
    for (i = 0; i < 0x400; i++)
        *dest++ = 0;

    dest = (u32 *)0x06008000;
    for (i = 0; i < 0x2000; i++)
        *dest++ = 0;

    dest = (u32 *)OBJ_VRAM0;
    for (i = 0; i < 0x1F80; i++)
        *dest++ = 0;

    dest = (u32 *)PLTT;
    for (i = 0; i < 120; i++)
        *dest++ = 0;

    dest = (u32 *)OBJ_PLTT;
    for (i = 0; i < 120; i++)
        *dest++ = 0;

    dest = (u32 *)OAM;
    for (i = 0; i < 256; i++)
        *dest++ = 0xA000A0; // TODO: Macro or explanation
}

void sub_80098A0(void)
{
    gUnknown_202D23C = 0;
    gUnknown_202D238[0] = 0;
    gUnknown_202D238[1] = 0;
    gUnknown_202D238[2] = 0;
    gUnknown_202D238[3] = 0;
}

void sub_80098BC(u32 *r0, const u32 *r1, u32 r2)
{
    if (gUnknown_202D23C < 8) {
        gUnknown_202D240[gUnknown_202D23C].unk0 = r0;
        gUnknown_202D240[gUnknown_202D23C].unk4 = r1;
        gUnknown_202D240[gUnknown_202D23C].size = r2;
        gUnknown_202D23C++;
    }
}

void sub_80098F8(u32 r0)
{
    gUnknown_202D238[r0] = 1;
}

void sub_8009908(void)
{
    s32 i;

    for (i = 0; i < gUnknown_202D23C; i++)
        CpuCopy(gUnknown_202D240[i].unk0, gUnknown_202D240[i].unk4, gUnknown_202D240[i].size);

    gUnknown_202D23C = 0;
    if (gUnknown_202D238[0] != 0) {
        gUnknown_202D238[0] = 0;
        CpuCopy(BG_SCREEN_ADDR(12), gUnknown_202B038[0], BG_SCREEN_SIZE);
    }
    if (gUnknown_202D238[1] != 0) {
        gUnknown_202D238[1] = 0;
        CpuCopy(BG_SCREEN_ADDR(13), gUnknown_202B038[1], BG_SCREEN_SIZE);
    }
    if (gUnknown_202D238[2] != 0) {
        gUnknown_202D238[2] = 0;
        CpuCopy(BG_SCREEN_ADDR(14), gUnknown_202B038[2], BG_SCREEN_SIZE);
    }
    if (gUnknown_202D238[3] != 0) {
        gUnknown_202D238[3] = 0;
        CpuCopy(BG_SCREEN_ADDR(15), gUnknown_202B038[3], BG_SCREEN_SIZE);
    }
}

void sub_80099C0(void)
{
    CpuCopy(BG_SCREEN_ADDR(12), gUnknown_202B038[0], BG_SCREEN_SIZE);
    CpuCopy(BG_SCREEN_ADDR(13), gUnknown_202B038[1], BG_SCREEN_SIZE);
}

void sub_80099F0(u32 a0)
{
    s32 i;

    for (i = 0; i < 8; i++)
        gFontPalette[i].unk0[1] = a0;
}

UNUSED static void sub_8009A10(u32 *a0)
{
    sub_8009A1C(a0[1]);
}
