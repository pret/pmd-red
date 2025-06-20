#include "global.h"
#include "globaldata.h"
#include "code_800D090.h"
#include "music_util.h"
#include "code_803D0D8.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "sprite.h"
#include "string_format.h"
#include "text_1.h"
#include "text_2.h"
#include "text_3.h"
#include "text_util.h"
#include "constants/input.h"

struct unkStruct_203B1F8
{
    // size: 0x4B4
    u32 menuAction;
    MenuStruct unk4;
    WindowTemplates windows;
    u8 buffer[0x400];
};

EWRAM_INIT struct unkStruct_203B1F8 *gUnknown_203B1F8 = {NULL};

static const WindowTemplate sWindowTemplateDummy = WIN_TEMPLATE_DUMMY;

const WindowTemplate gUnknown_80DAF88 = {
   0x00,
   0x03,
   0x02, 0x02,
   0x1A, 0x0c,
   0x0c, 0x00,
   NULL
};

const WindowTemplate gUnknown_80DAFA0 = {
   0x00,
   0x03,
   0x16, 0x0F,
   0x06, 0x03,
   0x03, 0x00,
   NULL
};

bool8 sub_8015080(u8 *buffer, const MenuItem *menuItems)
{
    s32 index;

    gUnknown_203B1F8 = MemoryAlloc(sizeof(struct unkStruct_203B1F8), 8);
    gUnknown_203B1F8->menuAction = 0;

    for(index = 0; index < MAX_WINDOWS; index++)
    {
        gUnknown_203B1F8->windows.id[index] = sWindowTemplateDummy;
    }

    gUnknown_203B1F8->windows.id[0] = gUnknown_80DAF88;
    gUnknown_203B1F8->windows.id[2] = gUnknown_80DAFA0;
    sub_8012CAC(&gUnknown_203B1F8->windows.id[2], menuItems);
    ResetUnusedInputStruct();
    ShowWindows(&gUnknown_203B1F8->windows, 1, 1);
    sub_80073B8(0);
    FormatString(buffer, gUnknown_203B1F8->buffer, gUnknown_203B1F8->buffer + 0x400, 0);
    PrintStringOnWindow(4, 4, gUnknown_203B1F8->buffer, 0, 0);
    sub_80073E0(0);
    sub_8012D60(&gUnknown_203B1F8->unk4, menuItems, 0, 0, -1, 2);
    return TRUE;
}

u32 sub_801516C(void)
{
    if(!sub_8012FD8(&gUnknown_203B1F8->unk4)) {
        sub_8013114(&gUnknown_203B1F8->unk4, &gUnknown_203B1F8->menuAction);
        return 3;
    }
    else {
        return 0;
    }
}

u32 sub_8015198(void)
{
    return gUnknown_203B1F8->menuAction;
}

void sub_80151A4(void)
{
    if(gUnknown_203B1F8) {
        MemoryFree(gUnknown_203B1F8);
        gUnknown_203B1F8 = NULL;
    }
}
