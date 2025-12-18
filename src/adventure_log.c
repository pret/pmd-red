#include "global.h"
#include "globaldata.h"
#include "constants/input.h"
#include "text_3.h"
#include "adventure_log.h"
#include "music_util.h"
#include "adventure_info.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "string_format.h"
#include "text_1.h"
#include "text_2.h"

static EWRAM_INIT MenuHeaderWindow *sAdventureLog = { NULL };

#include "data/adventure_log.h"

static void DisplayAdventureLog();
static void sub_8032084();

bool8 CreateAdventureLogScreen(u32 kind)
{
    sAdventureLog = MemoryAlloc(sizeof(*sAdventureLog), MEMALLOC_GROUP_8);
    sAdventureLog->m.menuWinId = kind;
    sAdventureLog->m.menuWindow = &sAdventureLog->m.windows.id[kind];
    RestoreSavedWindows(&sAdventureLog->m.windows);
    sAdventureLog->m.windows.id[sAdventureLog->m.menuWinId] = sUnknown_80E2008;
    sAdventureLog->m.menuWindow->header = &sAdventureLog->header;

    ResetUnusedInputStruct();
    ShowWindows(&sAdventureLog->m.windows, TRUE, TRUE);
    CreateMenuOnWindow(&sAdventureLog->m.input, 0x20, 8, kind);
    sub_8032084();
    DisplayAdventureLog();
    return TRUE;
}

u32 HandleAdventureLogInput(bool8 a0)
{
    if (!a0) {
        sub_8013660(&sAdventureLog->m.input);
        return 0;
    }

    switch (GetKeyPress(&sAdventureLog->m.input)) {
        case INPUT_B_BUTTON:
            PlayMenuSoundEffect(MENU_SFX_BACK);
            return 2;
        case INPUT_A_BUTTON:
            PlayMenuSoundEffect(MENU_SFX_ACCEPT);
            return 3;
        default:
            if (MenuCursorUpdateOnlyLeftRight(&sAdventureLog->m.input)) {
                sub_8032084();
                DisplayAdventureLog();
                return 1;
            }
            return 0;
    }
}

void CleanAdventureLogScreen(void)
{
    if (sAdventureLog != NULL) {
        sAdventureLog->m.windows.id[sAdventureLog->m.menuWinId] = sUnknown_80E1FF0;
        ResetUnusedInputStruct();
        ShowWindows(&sAdventureLog->m.windows, TRUE, TRUE);
        MemoryFree(sAdventureLog);
        sAdventureLog = NULL;
    }
}

static void sub_8032084(void)
{
    sAdventureLog->header.count = sAdventureLog->m.input.pagesCount;
    sAdventureLog->header.currId = sAdventureLog->m.input.currPage;
    sAdventureLog->header.width = 11;
    sAdventureLog->header.f3 = 0;

    UPDATE_MENU_WINDOW_HEIGHT(sAdventureLog->m);
}

static void DisplayAdventureLog(void)
{
    s32 i;
    s32 r4; // r4
    s32 r6; // r6
    u8 aa;

    CallPrepareTextbox_8008C54(sAdventureLog->m.menuWinId);
    sub_80073B8(sAdventureLog->m.menuWinId);
    r4 = sAdventureLog->m.input.currPage * 8;
    r6 = r4;
    r6 += 10;
    PrintStringOnWindow(r6, 0, sAdventureLogText, sAdventureLog->m.menuWinId, 0);

    r4 += 4;
    r6 = r4 + (sAdventureLog->header.width * 8);
    PrintNumOnWindow(r6, 0, sAdventureLog->m.input.currPage + 1, 1, 7, sAdventureLog->m.menuWinId);

    for (i = 0; i < sAdventureLog->m.input.currPageEntries; i++) {
        aa = (sAdventureLog->m.input.currPage * sAdventureLog->m.input.entriesPerPage) + i;

        if (GetAdventureAchievement(aa)) {
            switch (aa) {
                case AA_NUM_FLOORS_EXPLORED: {
                    s32 v1 = GetAdventureFloorsExplored();
                    gFormatArgs[0] = (s16)v1;
                    PrintFormattedStringOnWindow(8, GetMenuEntryYCoord(&sAdventureLog->m.input, i), GetAdventureLogLine(aa), sAdventureLog->m.menuWinId, 0);
                    break;
                }
                case AA_NUM_MOVES_LEARNED: {
                    s32 v2 = GetAdventureMovesLearned();
                    gFormatArgs[0] = (s16)v2;
                    PrintFormattedStringOnWindow(8, GetMenuEntryYCoord(&sAdventureLog->m.input, i), GetAdventureLogLine(aa), sAdventureLog->m.menuWinId, 0);
                    break;
                }
                case AA_NUM_THIEVING_SUCCESSES: {
                    s32 v3 = GetThievingSuccesses();
                    gFormatArgs[0] = (s16)v3;
                    PrintFormattedStringOnWindow(8, GetMenuEntryYCoord(&sAdventureLog->m.input, i), GetAdventureLogLine(aa), sAdventureLog->m.menuWinId, 0);
                    break;
                }
                case AA_NUM_FRIEND_RESCUE_SUCCESSES: {
                    s32 v4 = GetFriendRescueSuccesses();
                    gFormatArgs[0] = v4;
                    PrintFormattedStringOnWindow(8, GetMenuEntryYCoord(&sAdventureLog->m.input, i), GetAdventureLogLine(aa), sAdventureLog->m.menuWinId, 0);
                    break;
                }
                case AA_NUM_POKEMON_EVOLVED: {
                    s32 v5 = GetAdventureNumEvolved();
                    gFormatArgs[0] = v5;
                    PrintFormattedStringOnWindow(8, GetMenuEntryYCoord(&sAdventureLog->m.input, i), GetAdventureLogLine(aa), sAdventureLog->m.menuWinId, 0);
                    break;
                }
                case AA_NUM_POKEMON_JOINED: {
                    s32 v6 = GetAdventureNumJoined();
                    gFormatArgs[0] = (s16)v6;
                    // fallthrough
                }
                default: {
                    PrintFormattedStringOnWindow(8, GetMenuEntryYCoord(&sAdventureLog->m.input, i), GetAdventureLogLine(aa), sAdventureLog->m.menuWinId, 0);
                    break;
                }
            }
        }
        else
            PrintStringOnWindow(8, GetMenuEntryYCoord(&sAdventureLog->m.input, i), sPlaceholder, sAdventureLog->m.menuWinId, 0);
    }

    sub_80073E0(sAdventureLog->m.menuWinId);
}
