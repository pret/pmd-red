#include "global.h"
#include "globaldata.h"
#include "text_3.h"
#include "code_800D090.h"
#include "music_util.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "moves.h"
#include "pokemon.h"
#include "text_1.h"
#include "text_2.h"

struct unkStruct_203B274
{
    // size: 0x3e8
    Pokemon *pokeStruct;
    unkStruct_808E218_arg *unk4;
    unkStruct_808E218_arg unk8;
    MenuHeaderWindow s348;
};

EWRAM_INIT struct unkStruct_203B274 *gUnknown_203B274 = {NULL};

static const WindowTemplate sUnknown_80DC2AC = {
    0,
    3,
    0, 0,
    0, 0,
    0, 0,
    NULL
};
static const WindowTemplate sUnknown_80DC2C4 = {
    0,
    6,
    2, 2,
    0xF, 4,
    6, 0,
    NULL
};


ALIGNED(4) const u8 gUnknown_80DC2DC[] = _("Moves Page: %d/%d ");

u32 sub_801F7E4(void);
void sub_801F690(void);
void sub_801F700(void);


bool8 sub_801F428(s16 index, s32 param_2)
{
    s32 index_s32 = index;
    gUnknown_203B274 = MemoryAlloc(sizeof(struct unkStruct_203B274), 0x8);
    gUnknown_203B274->pokeStruct = &gRecruitedPokemonRef->pokemon[index_s32];
    gUnknown_203B274->unk4 = &gUnknown_203B274->unk8;
    gUnknown_203B274->s348.m.menuWinId = param_2;
    gUnknown_203B274->s348.m.menuWindow = &gUnknown_203B274->s348.m.windows.id[gUnknown_203B274->s348.m.menuWinId];
    RestoreSavedWindows(&gUnknown_203B274->s348.m.windows);
    gUnknown_203B274->s348.m.windows.id[gUnknown_203B274->s348.m.menuWinId] = sUnknown_80DC2C4;
    gUnknown_203B274->s348.m.menuWindow->header = &gUnknown_203B274->s348.header;
    gUnknown_203B274->s348.header.count = 1;
    gUnknown_203B274->s348.header.currId = 0;
    gUnknown_203B274->s348.header.width = 0xC;
    gUnknown_203B274->s348.header.f3 = 0;
    ResetUnusedInputStruct();
    ShowWindows(&gUnknown_203B274->s348.m.windows, TRUE, TRUE);
    CreateMenuOnWindow(&gUnknown_203B274->s348.m.input, sub_801F7E4(), 4, param_2);
    sub_801F690();
    sub_801F700();
    return TRUE;
}

u32 sub_801F520(u8 param_1)
{
    if (param_1 == 0) {
        sub_8013660(&gUnknown_203B274->s348.m.input);
        return 0;
    }
    else {
        switch(GetKeyPress(&gUnknown_203B274->s348.m.input))
        {
            case 2:
                PlayMenuSoundEffect(1);
                return 2;
            case 1:
                PlayMenuSoundEffect(0);
                return 3;
            case 4:
                PlayMenuSoundEffect(4);
                return 4;
            default:
                break;
        }
        if (MenuCursorUpdate(&gUnknown_203B274->s348.m.input,1) != 0) {
            sub_801F690();
            sub_801F700();
            return 1;
        }
        else {
            return 0;
        }
    }
}

u16 sub_801F5B4(void)
{
    return gUnknown_203B274->unk4->unk0[GET_CURRENT_MENU_ENTRY(gUnknown_203B274->s348.m.input)];
}

void sub_801F5F0(bool8 r0)
{
    ResetUnusedInputStruct();
    ShowWindows(&gUnknown_203B274->s348.m.windows, FALSE, FALSE);
    MenuUpdatePagesData(&gUnknown_203B274->s348.m.input);
    sub_801F690();
    sub_801F700();
    if(r0)
        AddMenuCursorSprite(&gUnknown_203B274->s348.m.input);
}

void sub_801F63C(void)
{
    if(gUnknown_203B274 != NULL)
    {
        gUnknown_203B274->s348.m.windows.id[gUnknown_203B274->s348.m.menuWinId] = sUnknown_80DC2AC;
        ResetUnusedInputStruct();
        ShowWindows(&gUnknown_203B274->s348.m.windows, TRUE, TRUE);
        MemoryFree(gUnknown_203B274);
        gUnknown_203B274 = NULL;
    }
}

void sub_801F690(void)
{
    UPDATE_MENU_WINDOW_HEIGHT(gUnknown_203B274->s348.m);
}

void sub_801F700(void)
{
    u32 y;
    s32 index;
    u8 buffer2 [48];
    u8 buffer1 [128];

    CallPrepareTextbox_8008C54(gUnknown_203B274->s348.m.menuWinId);
    sub_80073B8(gUnknown_203B274->s348.m.menuWinId);
    sprintfStatic(buffer1,gUnknown_80DC2DC,gUnknown_203B274->s348.m.input.currPage + 1,gUnknown_203B274->s348.m.input.pagesCount); // Moves Page: %d/%d
    PrintStringOnWindow(0x10,0,buffer1,gUnknown_203B274->s348.m.menuWinId,0);
    for(index = 0; index < gUnknown_203B274->s348.m.input.currPageEntries; index++)
    {
        sub_8092C84(buffer2,gUnknown_203B274->unk4->unk0[gUnknown_203B274->s348.m.input.currPage * gUnknown_203B274->s348.m.input.entriesPerPage + index]);
        y = GetMenuEntryYCoord(&gUnknown_203B274->s348.m.input, index);
        PrintStringOnWindow(8,y,buffer2,gUnknown_203B274->s348.m.menuWinId,0);
    }
    sub_80073E0(gUnknown_203B274->s348.m.menuWinId);
}

u32 sub_801F7E4(void)
{
    sub_808E218(gUnknown_203B274->unk4, gUnknown_203B274->pokeStruct);
    return gUnknown_203B274->unk4->count;
}

