#include "global.h"
#include "globaldata.h"
#include "constants/input.h"
#include "music_util.h"
#include "code_80958E8.h"
#include "input.h"
#include "pokemon_mail.h"
#include "pokemon_news1.h"
#include "pokemon_news2.h"
#include "memory.h"
#include "menu_input.h"
#include "string_format.h"
#include "text_1.h"
#include "text_2.h"

static EWRAM_INIT struct unkStruct_203B2CC *sUnknown_203B2CC = {NULL};
static EWRAM_INIT u16 sUnknown_203B2D0 = {0};
static EWRAM_INIT u16 sUnknown_203B2D2 = {0};

#include "data/pokemon_news1.h"

static void CreatePKMNNewsMenu(void);
static s32 GetNumPKMNNews(void);

static void sub_802B880(void);

bool8 sub_802B640(u32 a0, DungeonPos *a1, u32 a2)
{
    if (HasNoPKMNNews())
        return FALSE;

    if (sUnknown_203B2CC == NULL)
        sUnknown_203B2CC = MemoryAlloc(sizeof(struct unkStruct_203B2CC), MEMALLOC_GROUP_8);

    sUnknown_203B2CC->s38.menuWinId = a0;
    sUnknown_203B2CC->s38.menuWindow = &sUnknown_203B2CC->s38.windows.id[a0];

    RestoreSavedWindows(&sUnknown_203B2CC->s38.windows);

    sUnknown_203B2CC->s38.windows.id[sUnknown_203B2CC->s38.menuWinId] = sUnknown_80DFBEC;

    if (a1 != NULL)
        sUnknown_203B2CC->s38.windows.id[sUnknown_203B2CC->s38.menuWinId].pos = *a1;

    sub_8012D08(sUnknown_203B2CC->s38.menuWindow, a2);
    ResetUnusedInputStruct();
    ShowWindows(&sUnknown_203B2CC->s38.windows, TRUE, TRUE);

    CreateMenuOnWindow(&sUnknown_203B2CC->s38.input, GetNumPKMNNews(), a2, a0);

    sUnknown_203B2CC->s38.input.menuIndex = sUnknown_203B2D0;
    sUnknown_203B2CC->s38.input.currPage = sUnknown_203B2D2;

    MenuUpdatePagesData(&sUnknown_203B2CC->s38.input);
    sub_802B880();
    CreatePKMNNewsMenu();

    return TRUE;
}

u32 sub_802B720(bool8 a0)
{
    if (!a0) {
        sub_8013660(&sUnknown_203B2CC->s38.input);
        return 0;
    }

    switch (GetKeyPress(&sUnknown_203B2CC->s38.input)) {
        case INPUT_B_BUTTON:
            PlayMenuSoundEffect(MENU_SFX_BACK);
            return 2;
        case INPUT_A_BUTTON:
            PlayMenuSoundEffect(MENU_SFX_ACCEPT);
            return 3;
        case INPUT_START_BUTTON:
            PlayMenuSoundEffect(MENU_SFX_INFO);
            return 4;
    }

    if (MenuCursorUpdate(&sUnknown_203B2CC->s38.input, 1)) {
        sub_802B880();
        CreatePKMNNewsMenu();
        return 1;
    }
    return 0;
}

u8 GetPokemonNewsIndex(void)
{
    return sUnknown_203B2CC->receivedNewsletters[GET_CURRENT_MENU_ENTRY(sUnknown_203B2CC->s38.input)];
}

void sub_802B7D0(bool8 cursorSprite)
{
    ResetUnusedInputStruct();
    ShowWindows(&sUnknown_203B2CC->s38.windows, FALSE, FALSE);

    sUnknown_203B2CC->s38.input.totalEntriesCount = GetNumPKMNNews();
    MenuUpdatePagesData(&sUnknown_203B2CC->s38.input);
    sub_802B880();
    CreatePKMNNewsMenu();

    if (cursorSprite)
        AddMenuCursorSprite(&sUnknown_203B2CC->s38.input);
}

void sub_802B81C(void)
{
    if (sUnknown_203B2CC != NULL) {
        sUnknown_203B2D0 = sUnknown_203B2CC->s38.input.menuIndex;

        sUnknown_203B2D2 = sUnknown_203B2CC->s38.input.currPage;

        sUnknown_203B2CC->s38.windows.id[sUnknown_203B2CC->s38.menuWinId] = sUnknown_80DFBD0;

        ResetUnusedInputStruct();
        ShowWindows(&sUnknown_203B2CC->s38.windows, TRUE, TRUE);

        MemoryFree(sUnknown_203B2CC);
        sUnknown_203B2CC = NULL;
    }
}

static void sub_802B880(void)
{
    UPDATE_MENU_WINDOW_HEIGHT(sUnknown_203B2CC->s38);
}

static void CreatePKMNNewsMenu(void)
{
    s32 index;
    s32 y;
    s32 new_index;
    u8 mailIndex;

    CallPrepareTextbox_8008C54(sUnknown_203B2CC->s38.menuWinId);
    sub_80073B8(sUnknown_203B2CC->s38.menuWinId);
    PrintStringOnWindow(10, 0, sNewsList, sUnknown_203B2CC->s38.menuWinId, 0);

    PrintNumOnWindow((sUnknown_80DFBE8.width * 8) + 4, 0, sUnknown_203B2CC->s38.input.currPage + 1, 2, 7, sUnknown_203B2CC->s38.menuWinId);

    for (index = 0; index < sUnknown_203B2CC->s38.input.currPageEntries; index++) {
        y = GetMenuEntryYCoord(&sUnknown_203B2CC->s38.input, index);
        new_index = (sUnknown_203B2CC->s38.input.currPage * sUnknown_203B2CC->s38.input.entriesPerPage) + index;
        mailIndex = sUnknown_203B2CC->receivedNewsletters[new_index];
        sub_803B6B0(10, y, 6, sUnknown_203B2CC->s38.menuWinId);
        sub_802BC7C();
        PrintFormattedStringOnWindow(21, y, GetPokemonMailHeadline(mailIndex), sUnknown_203B2CC->s38.menuWinId, 0);
    }

    sub_80073E0(sUnknown_203B2CC->s38.menuWinId);
}

static s32 GetNumPKMNNews(void)
{
    s32 i;
    s32 newsCount;

    newsCount = 0;

    for (i = 0; i < NUM_POKEMON_NEWS; i++) {
        if (CheckPKMNNewsSlot(i)) {
            sUnknown_203B2CC->receivedNewsletters[newsCount] = i;
            newsCount++;
        }
    }

    return newsCount;
}

bool8 HasNoPKMNNews(void)
{
    s32 i;

    for (i = 0; i < NUM_POKEMON_NEWS; i++) {
        if (CheckPKMNNewsSlot(i))
            return FALSE;
    }

    return TRUE;
}
