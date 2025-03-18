#include "global.h"
#include "globaldata.h"
#include "bg_palette_buffer.h"
#include "code_800558C.h"
#include "code_8009804.h"
#include "cpu.h"
#include "def_filearchives.h"
#include "file_system.h"
#include "text.h"

struct FontData
{
    s32 size;
    u8 dataArray[0];
};

EWRAM_DATA RGB gFontPalette[128] = {0};
static EWRAM_DATA u8 sUnknown_202D238[4] = {0};
static EWRAM_DATA s32 sUnknown_202D23C = 0;
static EWRAM_DATA struct unkStruct_202D240 sUnknown_202D240[8] = {0};
/*static [.s file not finished yet]*/ EWRAM_DATA u32 gUnknown_202D2A0 = 0;

static EWRAM_INIT bool8 sUnknown_203B090 = FALSE; // Only written to.

#define OAM_DUMMY 0xA000A0 // y set to 160 (DISPLAY_HEIGHT)

// arm9.bin::0200A178
void InitGraphics(void)
{
    s32 i;
    OpenedFile *file;
    u32 *dest;
    const RGB *rgbColors;
    struct FontData *font;
    #ifdef NONMATCHING
    const FileArchive *sysFileArchieve;
    #else
    register const FileArchive *sysFileArchieve asm("r4");
    #endif // NONMATCHING

    sUnknown_203B090 = TRUE;
    dest = (u32 *)VRAM;
    for (i = 0; i < VRAM_SIZE / sizeof(*dest); i++) {
        *dest++ = 0;
    }

    dest = (u32 *)PLTT;
    for (i = 0; i < PLTT_SIZE / sizeof(*dest); i++) {
        *dest++ = 0;
    }

    dest = (u32 *)OAM;
    for (i = 0; i < OAM_SIZE / sizeof(*dest); i++) {
         *dest++ = OAM_DUMMY;
    }

    sysFileArchieve = &gSystemFileArchive;
    file = OpenFileAndGetFileDataPtr("font", sysFileArchieve);
    font = (struct FontData *)(file->data);
    i = font->size;
    CpuCopy((u32 *)(VRAM + 0x4f00), font->dataArray, i * 32);
    CloseFile(file);

    file = OpenFileAndGetFileDataPtr("fontsp", sysFileArchieve);
    font = (struct FontData *)(file->data);
    i = font->size;
    CpuCopy((u32 *)(VRAM + 0x17e00), font->dataArray, i * 32);
    CloseFile(file);

    // TODO: Lots missing here from NDS.

    InitFontPalette();
    file = OpenFileAndGetFileDataPtr("fontsppa", sysFileArchieve);
    rgbColors = (RGB *)file->data;

    for (i = 0; i < 16; rgbColors++, i++) {
        SetBGPaletteBufferColorArray(0x1F0 + i, rgbColors);
    }
    CloseFile(file);
    TransferBGPaletteBuffer();
}

// arm9.bin::0200A100
void InitFontPalette(void)
{
    OpenedFile *fontpalFile;
    s32 i;
    RGB *ptr;

    fontpalFile = OpenFileAndGetFileDataPtr("fontpal", &gSystemFileArchive);
    CpuCopy(gFontPalette, fontpalFile->data, sizeof(gFontPalette));

    if (sub_80063B0() == 1)
        ptr = &gFontPalette[0];
    else
        ptr = &gFontPalette[16];

    for (i = 0; i < 16; ptr++, i++)
        SetBGPaletteBufferColorArray(i + 240, ptr);

    CloseFile(fontpalFile);
}

// arm9.bin::0200A00C
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
    for (i = 0; i < OAM_SIZE / sizeof(*dest); i++)
        *dest++ = OAM_DUMMY;
}

// Extra func in NDS here:
// arm9.bin::02009FC4

// arm9.bin::02009F70
void sub_80098A0(void)
{
    sUnknown_202D23C = 0;
    sUnknown_202D238[0] = 0;
    sUnknown_202D238[1] = 0;
    sUnknown_202D238[2] = 0;
    sUnknown_202D238[3] = 0;
}

// arm9.bin::02009F18
void sub_80098BC(u32 *r0, const u32 *r1, u32 r2)
{
    if (sUnknown_202D23C < 8) {
        sUnknown_202D240[sUnknown_202D23C].unk0 = r0;
        sUnknown_202D240[sUnknown_202D23C].unk4 = r1;
        sUnknown_202D240[sUnknown_202D23C].size = r2;
        sUnknown_202D23C++;
    }
}

// The below func has a sibling in the NDS version.
// arm9.bin::02009F04 and arm9.bin::02009EF0

void sub_80098F8(u32 r0)
{
    sUnknown_202D238[r0] = 1;
}

void sub_8009908(void)
{
    s32 i;

    for (i = 0; i < sUnknown_202D23C; i++)
        CpuCopy(sUnknown_202D240[i].unk0, sUnknown_202D240[i].unk4, sUnknown_202D240[i].size);

    sUnknown_202D23C = 0;
    if (sUnknown_202D238[0] != 0) {
        sUnknown_202D238[0] = 0;
        CpuCopy(BG_SCREEN_ADDR(12), gBgTilemaps[0], BG_SCREEN_SIZE);
    }
    if (sUnknown_202D238[1] != 0) {
        sUnknown_202D238[1] = 0;
        CpuCopy(BG_SCREEN_ADDR(13), gBgTilemaps[1], BG_SCREEN_SIZE);
    }
    if (sUnknown_202D238[2] != 0) {
        sUnknown_202D238[2] = 0;
        CpuCopy(BG_SCREEN_ADDR(14), gBgTilemaps[2], BG_SCREEN_SIZE);
    }
    if (sUnknown_202D238[3] != 0) {
        sUnknown_202D238[3] = 0;
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
    s32 i;
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

    for (i = 0; i < 16; i++) {
        SetBGPaletteBufferColorArray(i + 0xE0, &r0->unk10->pal[i + palId * 16]);
    }
}
