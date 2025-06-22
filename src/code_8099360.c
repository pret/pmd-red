#include "global.h"
#include "globaldata.h"
#include "code_8099360.h"
#include "bg_palette_buffer.h"
#include "graphics_memory.h"
#include "game_options.h"
#include "def_filearchives.h"
#include "event_flag.h"
#include "file_system.h"
#include "structs/str_3000400.h"

extern u8 gUnknown_20398B8;

extern void sub_8003600(void);
extern s32 sub_800388C(u16, const u8 *, u8);
extern void sub_8003810(u16 idx, unkStruct_3000400 param_2);

void sub_8099648(void)
{
    sub_8003600();
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

    sub_800388C(0x1f0, file->data, 0x10);
    CloseFile(file);
}

void sub_8099690(u32 param_1)
{
    OpenedFile *temp;
    RGB *pal;
    RGB *var2;
    u8 gender;

    s32 index;

    temp = OpenFileAndGetFileDataPtr("fontpal", &gSystemFileArchive);

    switch(param_1)
    {
        default:
            gender = gGameOptionsRef->playerGender;
             pal = &gFontPalette[0x10];
            if(gender != 0)
                pal += 0x40;
            break;
        case 1:
            pal = &gFontPalette[0x60];
            break;
        case 2:
            pal = &gFontPalette[0x70];
            break;
    }

    sub_800388C(0xF0, (u8 *)pal, 0x10);
    var2 = pal;
    for(index = 0; index < 0x10; index++)
    {
        nullsub_5(index + 0xF0, var2++);
    }
    CloseFile(temp);
}

UNUSED static void sub_8099708(u16 a0, unkStruct_3000400 a1)
{
    sub_8003810(a0, a1);
}

void sub_809971C(u16 idx, unkStruct_3000400 *strPtrs, s32 n)
{
    s32 i;

    for (i = 0; i < n; i++) {
        sub_8003810(idx++, *strPtrs++);
    }
}
