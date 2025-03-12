#include "global.h"
#include "bg_palette_buffer.h"
#include "code_8009804.h"
#include "cpu.h"
#include "file_system.h"
#include "text.h"
#include "code_800558C.h"

extern const u8 gUnknown_80B88CC[];
extern const struct FileArchive gSystemFileArchive; // 8300500

EWRAM_DATA RGB gFontPalette[128] = {0};
EWRAM_DATA static u8 gUnknown_202D238[4] = {0};
EWRAM_DATA static s32 gUnknown_202D23C = 0;
EWRAM_DATA static struct unkStruct_202D240 gUnknown_202D240[8] = {0};
EWRAM_DATA u32 gUnknown_202D2A0 = 0;

void InitFontPalette(void)
{
    OpenedFile *fontpalFile;
    s32 i;
    RGB *ptr;

    fontpalFile = OpenFileAndGetFileDataPtr(gUnknown_80B88CC, &gSystemFileArchive); // fontpal
    CpuCopy(gFontPalette, fontpalFile->data, sizeof(gFontPalette));

    if (sub_80063B0() == 1)
        ptr = &gFontPalette[0];
    else
        ptr = &gFontPalette[16];

    for (i = 0; i < 16; ptr++, i++)
        SetBGPaletteBufferColorArray(i + 240, ptr);

    CloseFile(fontpalFile);
}

void vram_related_8009804(void)
{
    u32 i;
    u32 *dest;

    dest = (u32 *)VRAM;
    for (i = 0; i < 0x13C0; i++)
        *dest++ = 0;

    dest = (u32 *)(VRAM + 0x7000);
    for (i = 0; i < 0x400; i++)
        *dest++ = 0;

    dest = (u32 *)(VRAM + 0x8000);
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
    for (i = 0; i < OAM_SIZE / 4; i++)
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
        CpuCopy(BG_SCREEN_ADDR(12), gBgTilemaps[0], BG_SCREEN_SIZE);
    }
    if (gUnknown_202D238[1] != 0) {
        gUnknown_202D238[1] = 0;
        CpuCopy(BG_SCREEN_ADDR(13), gBgTilemaps[1], BG_SCREEN_SIZE);
    }
    if (gUnknown_202D238[2] != 0) {
        gUnknown_202D238[2] = 0;
        CpuCopy(BG_SCREEN_ADDR(14), gBgTilemaps[2], BG_SCREEN_SIZE);
    }
    if (gUnknown_202D238[3] != 0) {
        gUnknown_202D238[3] = 0;
        CpuCopy(BG_SCREEN_ADDR(15), gBgTilemaps[3], BG_SCREEN_SIZE);
    }
}

void sub_80099C0(void)
{
    CpuCopy(BG_SCREEN_ADDR(12), gBgTilemaps[0], BG_SCREEN_SIZE);
    CpuCopy(BG_SCREEN_ADDR(13), gBgTilemaps[1], BG_SCREEN_SIZE);
}

void SetFontsBaseColor(RGB a0)
{
    s32 i;

    for (i = 0; i < 8; i++)
        gFontPalette[16 * i + 1] = a0;
}

UNUSED static void sub_8009A10(struct unkStruct_8009A1C_ptr *a0, u32 palId, u32 vramDstOffset, u32 r3)
{
    sub_8009A1C(a0->ptr, palId, vramDstOffset, r3);
}

void sub_8009A1C(const struct EfoFileData *r0, u32 palId, u32 vramDstOffset, u32 r3)
{
    s32 i, palPtrId;
    u32 *dst, *src;

    gUnknown_202D2A0 = r3;
    src = r0->spriteData;
    dst = (void *)(VRAM) + vramDstOffset;

    for (i = 0; i <= r0->animCount; i++) {
        *dst++ = *src++;
        *dst++ = *src++;
        *dst++ = *src++;
        *dst++ = *src++;
        *dst++ = *src++;
        *dst++ = *src++;
        *dst++ = *src++;
        *dst++ = *src++;
    }

    for (i = 0, palPtrId = palId * 64; i < 16; i++) {
        SetBGPaletteBufferColorArray(i + 0xE0, &r0->unk10->pal[i + palId * 16]);
    }
}
