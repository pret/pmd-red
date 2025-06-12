#include "global.h"
#include "globaldata.h"
#include "constants/input.h"
#include "structs/struct_sub80095e4.h"
#include "adventure_log.h"
#include "music_util.h"
#include "code_8097670.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "string_format.h"
#include "text_1.h"
#include "text_2.h"

static EWRAM_INIT struct_Sub80095E4_2 *sAdventureLog = { NULL };

#include "data/adventure_log.h"

static void DisplayAdventureLog();
static void sub_8032084();

bool8 CreateAdventureLogScreen(u32 kind)
{
    sAdventureLog = MemoryAlloc(sizeof(*sAdventureLog), 8);
    sAdventureLog->s0.winId = kind;
    sAdventureLog->s0.unk38 = &sAdventureLog->s0.windows.id[kind];
    RestoreSavedWindows(&sAdventureLog->s0.windows);
    sAdventureLog->s0.windows.id[sAdventureLog->s0.winId] = sUnknown_80E2008;
    sAdventureLog->s0.unk38->header = &sAdventureLog->header;

    ResetUnusedInputStruct();
    ShowWindows(&sAdventureLog->s0.windows, TRUE, TRUE);
    CreateMenuOnWindow(&sAdventureLog->s0.input, 0x20, 8, kind);
    sub_8032084();
    DisplayAdventureLog();
    return TRUE;
}

u32 HandleAdventureLogInput(bool8 a0)
{
    if (!a0) {
        sub_8013660(&sAdventureLog->s0.input);
        return 0;
    }

    switch (GetKeyPress(&sAdventureLog->s0.input)) {
        case INPUT_B_BUTTON:
            PlayMenuSoundEffect(1);
            return 2;
        case INPUT_A_BUTTON:
            PlayMenuSoundEffect(0);
            return 3;
        default:
            if (MenuCursorUpdateOnlyLeftRight(&sAdventureLog->s0.input)) {
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
        sAdventureLog->s0.windows.id[sAdventureLog->s0.winId] = sUnknown_80E1FF0;
        ResetUnusedInputStruct();
        ShowWindows(&sAdventureLog->s0.windows, TRUE, TRUE);
        MemoryFree(sAdventureLog);
        sAdventureLog = NULL;
    }
}

static void sub_8032084(void)
{
    sAdventureLog->header.count = sAdventureLog->s0.input.pagesCount;
    sAdventureLog->header.currId = sAdventureLog->s0.input.currPage;
    sAdventureLog->header.width = 11;
    sAdventureLog->header.f3 = 0;

    SUB_80095E4_CALL(sAdventureLog->s0);
}

static void DisplayAdventureLog(void)
{
    s32 i;
    s32 r4; // r4
    s32 r6; // r6
    u8 aa;

    CallPrepareTextbox_8008C54(sAdventureLog->s0.winId);
    sub_80073B8(sAdventureLog->s0.winId);
    r4 = sAdventureLog->s0.input.currPage * 8;
    r6 = r4;
    r6 += 10;
    PrintStringOnWindow(r6, 0, sAdventureLogText, sAdventureLog->s0.winId, 0);

    r4 += 4;
    r6 = r4 + (sAdventureLog->header.width * 8);
    sub_8012BC4(r6, 0, sAdventureLog->s0.input.currPage + 1, 1, 7, sAdventureLog->s0.winId);

    for (i = 0; i < sAdventureLog->s0.input.currPageEntries; i++) {
        aa = (sAdventureLog->s0.input.currPage * sAdventureLog->s0.input.entriesPerPage) + i;

        if (GetAdventureAchievement(aa)) {
            switch (aa) {
                case AA_NUM_FLOORS_EXPLORED: {
                    s32 v1 = GetAdventureFloorsExplored();
                    gFormatArgs[0] = (s16)v1;
                    PrintFormattedStringOnWindow(8, GetMenuEntryYCoord(&sAdventureLog->s0.input, i), GetAdventureLogLine(aa), sAdventureLog->s0.winId, 0);
                    break;
                }
                case AA_NUM_MOVES_LEARNED: {
                    s32 v2 = GetAdventureMovesLearned();
                    gFormatArgs[0] = (s16)v2;
                    PrintFormattedStringOnWindow(8, GetMenuEntryYCoord(&sAdventureLog->s0.input, i), GetAdventureLogLine(aa), sAdventureLog->s0.winId, 0);
                    break;
                }
                case AA_NUM_THIEVING_SUCCESSES: {
                    s32 v3 = GetThievingSuccesses();
                    gFormatArgs[0] = (s16)v3;
                    PrintFormattedStringOnWindow(8, GetMenuEntryYCoord(&sAdventureLog->s0.input, i), GetAdventureLogLine(aa), sAdventureLog->s0.winId, 0);
                    break;
                }
                case AA_NUM_FRIEND_RESCUE_SUCCESSES: {
                    s32 v4 = GetFriendRescueSuccesses();
                    gFormatArgs[0] = v4;
                    PrintFormattedStringOnWindow(8, GetMenuEntryYCoord(&sAdventureLog->s0.input, i), GetAdventureLogLine(aa), sAdventureLog->s0.winId, 0);
                    break;
                }
                case AA_NUM_POKEMON_EVOLVED: {
                    s32 v5 = GetAdventureNumEvolved();
                    gFormatArgs[0] = v5;
                    PrintFormattedStringOnWindow(8, GetMenuEntryYCoord(&sAdventureLog->s0.input, i), GetAdventureLogLine(aa), sAdventureLog->s0.winId, 0);
                    break;
                }
                case AA_NUM_POKEMON_JOINED: {
                    s32 v6 = GetAdventureNumJoined();
                    gFormatArgs[0] = (s16)v6;
                    // fallthrough
                }
                default: {
                    PrintFormattedStringOnWindow(8, GetMenuEntryYCoord(&sAdventureLog->s0.input, i), GetAdventureLogLine(aa), sAdventureLog->s0.winId, 0);
                    break;
                }
            }
        }
        else
            PrintStringOnWindow(8, GetMenuEntryYCoord(&sAdventureLog->s0.input, i), sPlaceholder, sAdventureLog->s0.winId, 0);
    }

    sub_80073E0(sAdventureLog->s0.winId);
}
