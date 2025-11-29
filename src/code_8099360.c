#include "global.h"
#include "globaldata.h"
#include "code_8099360.h"
#include "bg_palette_buffer.h"
#include "graphics_memory.h"
#include "game_options.h"
#include "def_filearchives.h"
#include "event_flag.h"
#include "file_system.h"
#include "palette_fade_util.h"

void sub_8099648(void)
{
    InitPaletteFadeTable();
    sub_809965C();
}

void nullsub_103(void)
{
}

void sub_809965C(void)
{
    OpenedFile *file;
    sub_8099690(0);

    file = OpenFileAndGetFileDataPtr("fontsppa", &gSystemFileArchive);

    sub_800388C(0x1f0, (const RGB_Union *) file->data, 0x10);
    CloseFile(file);
}

void sub_8099690(u32 param_1)
{
    OpenedFile *file;
    RGB_Struct *pal;
    RGB_Struct *var2;
    u8 gender;

    s32 index;

    file = OpenFileAndGetFileDataPtr("fontpal", &gSystemFileArchive);

    switch (param_1) {
        default: {
            gender = gGameOptionsRef->playerGender;
            pal = &gFontPalette[0x10];
            if (gender != MALE)
                pal += 0x40;
            break;
        }
        case 1: {
            pal = &gFontPalette[0x60];
            break;
        }
        case 2: {
            pal = &gFontPalette[0x70];
            break;
        }
    }

    sub_800388C(0xF0, (const RGB_Union *)pal, 0x10);
    var2 = pal;
    for (index = 0; index < 0x10; index++) {
        nullsub_5(index + 0xF0, var2++);
    }

    CloseFile(file);
}

UNUSED static void sub_8099708(u16 a0, RGB_Array a1)
{
    sub_8003810(a0, a1);
}

void sub_809971C(u16 idx, RGB_Array *strPtrs, s32 n)
{
    s32 i;

    for (i = 0; i < n; i++) {
        sub_8003810(idx++, *strPtrs++);
    }
}
