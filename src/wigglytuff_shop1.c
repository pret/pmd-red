#include "global.h"
#include "globaldata.h"
#include "constants/input.h"
#include "code_800D090.h"
#include "music_util.h"
#include "event_flag.h"
#include "friend_area.h"
#include "input.h"
#include "items.h"
#include "memory.h"
#include "menu_input.h"
#include "text_1.h"
#include "text_2.h"
#include "wigglytuff_shop1.h"

static EWRAM_INIT WigglytuffShop1Work *sWigglytuffShop1Work = {NULL};
static EWRAM_INIT u32 sUnknown_203B284 = {0};
static EWRAM_INIT u16 sUnknown_203B288 = {0};
static EWRAM_INIT u16 sUnknown_203B28A = {0};

#include "data/wigglytuff_shop1.h"

static void sub_8021410(void);
static s32 sub_8021664(void);

bool8 sub_80211AC(u32 mode, u32 a1)
{
    if (sub_8021700(mode))
        return FALSE;

    sWigglytuffShop1Work = MemoryAlloc(sizeof(WigglytuffShop1Work), MEMALLOC_GROUP_8);
    sWigglytuffShop1Work->mode = mode;
    sWigglytuffShop1Work->s40.m.menuWinId = a1;
    sWigglytuffShop1Work->s40.m.menuWindow = &sWigglytuffShop1Work->s40.m.windows.id[sWigglytuffShop1Work->s40.m.menuWinId];
    RestoreSavedWindows(&sWigglytuffShop1Work->s40.m.windows);
    sWigglytuffShop1Work->s40.m.windows.id[sWigglytuffShop1Work->s40.m.menuWinId] = sUnknown_80DC47C;
    sWigglytuffShop1Work->s40.m.menuWindow->header = &sWigglytuffShop1Work->s40.header;
    ResetUnusedInputStruct();
    ShowWindows(&sWigglytuffShop1Work->s40.m.windows, TRUE, TRUE);
    CreateMenuOnWindow(&sWigglytuffShop1Work->s40.m.input, sub_8021664(), 10, a1);

    if (sUnknown_203B284 == sWigglytuffShop1Work->mode) {
        sWigglytuffShop1Work->s40.m.input.menuIndex = sUnknown_203B288;
        sWigglytuffShop1Work->s40.m.input.currPage = sUnknown_203B28A;
        MenuUpdatePagesData(&sWigglytuffShop1Work->s40.m.input);
    }

    sub_8021410();
    sub_8021494();
    return TRUE;
}

u32 sub_8021274(bool8 a0)
{
    if (!a0) {
        sub_8013660(&sWigglytuffShop1Work->s40.m.input);
        return 0;
    }

    switch (GetKeyPress(&sWigglytuffShop1Work->s40.m.input)) {
        case INPUT_B_BUTTON:
            PlayMenuSoundEffect(MENU_SFX_BACK);
            return 2;
        case INPUT_A_BUTTON:
            if (sWigglytuffShop1Work->mode == 2 && GetFriendAreaPrice(sub_802132C()) > gTeamInventoryRef->teamMoney)
                PlayMenuSoundEffect(MENU_SFX_FAIL);
            else
                PlayMenuSoundEffect(MENU_SFX_ACCEPT);
            return 3;
        case INPUT_START_BUTTON:
            PlayMenuSoundEffect(MENU_SFX_INFO);
            return 4;
        default:
            if (MenuCursorUpdate(&sWigglytuffShop1Work->s40.m.input, 1) != 0) {
                sub_8021410();
                sub_8021494();
                return 1;
            }
            return 0;
    }
}

u8 sub_802132C(void)
{
    return sWigglytuffShop1Work->friendAreas[GET_CURRENT_MENU_ENTRY(sWigglytuffShop1Work->s40.m.input)];
}

void sub_8021354(bool8 cursorSprite)
{
    ResetUnusedInputStruct();
    ShowWindows(&sWigglytuffShop1Work->s40.m.windows, FALSE, FALSE);
    sWigglytuffShop1Work->s40.m.input.totalEntriesCount = sub_8021664();
    MenuUpdatePagesData(&sWigglytuffShop1Work->s40.m.input);
    sub_8021410();
    sub_8021494();

    if (cursorSprite)
        AddMenuCursorSprite(&sWigglytuffShop1Work->s40.m.input);
}

void sub_80213A0(void)
{
    if (sWigglytuffShop1Work) {
        sUnknown_203B284 = sWigglytuffShop1Work->mode;
        sUnknown_203B288 = sWigglytuffShop1Work->s40.m.input.menuIndex;
        sUnknown_203B28A = sWigglytuffShop1Work->s40.m.input.currPage;
        sWigglytuffShop1Work->s40.m.windows.id[sWigglytuffShop1Work->s40.m.menuWinId] = sUnknown_80DC464;
        ResetUnusedInputStruct();
        ShowWindows(&sWigglytuffShop1Work->s40.m.windows, TRUE, TRUE);
        MemoryFree(sWigglytuffShop1Work);
        sWigglytuffShop1Work = NULL;
    }
}

static void sub_8021410(void)
{
    sWigglytuffShop1Work->s40.header.count = 1;
    sWigglytuffShop1Work->s40.header.currId = 0;
    sWigglytuffShop1Work->s40.header.width = 12;
    sWigglytuffShop1Work->s40.header.f3 = 0;
    ResetUnusedInputStruct();
    ShowWindows(&sWigglytuffShop1Work->s40.m.windows, TRUE, TRUE);

    UPDATE_MENU_WINDOW_HEIGHT(sWigglytuffShop1Work->s40.m);
}

void sub_8021494(void)
{
    u8 friendAreaIndex;
    s32 i;
    u8 buffer1[80];
    u8 buffer2[80];

    CallPrepareTextbox_8008C54(sWigglytuffShop1Work->s40.m.menuWinId);
    sub_80073B8(sWigglytuffShop1Work->s40.m.menuWinId);
    PrintStringOnWindow(10, 0, sFriendAreas, sWigglytuffShop1Work->s40.m.menuWinId, 0);

    PrintNumOnWindow((sWigglytuffShop1Work->s40.header.width * 8) + 4, 0, sWigglytuffShop1Work->s40.m.input.currPage + 1, 1, 7, sWigglytuffShop1Work->s40.m.menuWinId);

    for (i = 0; i < sWigglytuffShop1Work->s40.m.input.currPageEntries; i++) {
        friendAreaIndex = sWigglytuffShop1Work->friendAreas[(sWigglytuffShop1Work->s40.m.input.currPage * sWigglytuffShop1Work->s40.m.input.entriesPerPage) + i];

        if (sWigglytuffShop1Work->mode == 2) {
            WriteFriendAreaName(buffer1, friendAreaIndex, TRUE);

            if (GetFriendAreaPrice(friendAreaIndex) <= gTeamInventoryRef->teamMoney)
                PrintStringOnWindow(8,GetMenuEntryYCoord(&sWigglytuffShop1Work->s40.m.input, i), buffer1, sWigglytuffShop1Work->s40.m.menuWinId, 0);
            else {
                sprintfStatic(buffer2, sFmtRedString, buffer1);
                PrintStringOnWindow(8, GetMenuEntryYCoord(&sWigglytuffShop1Work->s40.m.input, i), buffer2, sWigglytuffShop1Work->s40.m.menuWinId, 0);
            }
        }
        else if (sWigglytuffShop1Work->mode == 0) {
            if (gFriendAreas[friendAreaIndex] == TRUE)
                PrintStringOnWindow(8, GetMenuEntryYCoord(&sWigglytuffShop1Work->s40.m.input, i), GetFriendAreaName(friendAreaIndex), sWigglytuffShop1Work->s40.m.menuWinId, 0);
            else {
                sprintfStatic(buffer2, sFmtGreenString, GetFriendAreaName(friendAreaIndex));
                PrintStringOnWindow(8, GetMenuEntryYCoord(&sWigglytuffShop1Work->s40.m.input, i), buffer2, sWigglytuffShop1Work->s40.m.menuWinId, 0);
            }
        }
        else
            PrintStringOnWindow(8, GetMenuEntryYCoord(&sWigglytuffShop1Work->s40.m.input, i), GetFriendAreaName(friendAreaIndex), sWigglytuffShop1Work->s40.m.menuWinId, 0);
    }

    sub_80073E0(sWigglytuffShop1Work->s40.m.menuWinId);
}

static s32 sub_8021664(void)
{
    s32 i;
    s32 counter;

    counter = 0;

    switch (sWigglytuffShop1Work->mode) {
        case 0:
            for (i = FRIEND_AREA_BOUNTIFUL_SEA; i < FRIEND_AREA_COUNT; i++) {
                sWigglytuffShop1Work->friendAreas[counter] = i;
                counter++;
            }
            break;
        case 1:
            for (i = FRIEND_AREA_BOUNTIFUL_SEA; i < FRIEND_AREA_COUNT; i++) {
                if (gFriendAreas[i]) {
                    sWigglytuffShop1Work->friendAreas[counter] = i;
                    counter++;
                }
            }
            break;
        case 2:
            for (i = FRIEND_AREA_BOUNTIFUL_SEA; i < FRIEND_AREA_COUNT; i++) {
                if (gFriendAreas[i])
                    continue;

                switch (GetFriendAreaUnlockCondition(i)) {
                    case UNLOCK_SHOP_STORY:
                        sWigglytuffShop1Work->friendAreas[counter] = i;
                        counter++;
                        break;
                    case UNLOCK_SHOP_POST_GAME:
                        if (CheckQuest(QUEST_REACHED_POSTGAME)) {
                            sWigglytuffShop1Work->friendAreas[counter] = i;
                            counter++;
                        }
                        break;
                }
            }
            break;
    }

    return counter;
}

bool8 sub_8021700(u32 kind)
{
    s32 i;

    switch (kind) {
        case 0:
            return FALSE;
        case 1:
            for (i = FRIEND_AREA_BOUNTIFUL_SEA; i < FRIEND_AREA_COUNT; i++) {
                if (gFriendAreas[i])
                    return FALSE;
            }
            break;
        case 2:
            for (i = FRIEND_AREA_BOUNTIFUL_SEA; i < FRIEND_AREA_COUNT; i++) {
                if (gFriendAreas[i])
                    continue;

                switch (GetFriendAreaUnlockCondition(i)) {
                    case UNLOCK_SHOP_STORY:
                        return FALSE;
                    case UNLOCK_SHOP_POST_GAME:
                        if (CheckQuest(QUEST_REACHED_POSTGAME))
                            return FALSE;
                        break;
                }
            }
            break;
    }

    return TRUE;
}
