#include "global.h"
#include "globaldata.h"
#include "event_flag.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "music_util.h"
#include "pokemon.h"
#include "pokemon_summary_window.h"
#include "recruited_mon_summary_menu.h"
#include "text_1.h"

// Size: R=0x14C | B=?
typedef struct RecruitedMonSummaryMenuWork
{
    /* R=0x000 | B=0x000 */ MenuInputStruct input;
    /* R=0x034 | B=0x030 */ u32 summaryTabs[3];
    /* R=0x040 | B=0x03C */ u8 unk40[0x48 - 0x40]; // Unused? Or part of the above array (5 length)?
    /* R=0x048 | B=????? */ s16 speciesNum;
    /* R=0x04C | B=????? */ MonSummaryInfo monInfo;
    /* R=0x0B0 | B=????? */ UnkInfoTabStruct unkB0;
    /* R=0x0E0 | B=????? */ u32 windowID;
    /* R=0x0E4 | B=????? */ WindowTemplate *activeWinTemplate;
    /* R=0x0E8 | B=????? */ WindowTemplates winTemplates;
    /* R=0x148 | B=????? */ WindowHeader winHeader;
} RecruitedMonSummaryMenuWork;

static EWRAM_INIT RecruitedMonSummaryMenuWork *sMenuWork = { NULL };

#include "data/recruited_mon_summary_menu.h"

static void RecruitedMonSummaryMenu_InitSummaryMenu(void);
static void RecruitedMonSummaryMenu_ResetAndShowWindows(void);
static void RecruitedMonSummaryMenu_ShowSummaryWindow(void);

bool8 RecruitedMonSummaryMenu_Create(s32 speciesNum, s32 windowID)
{
    s32 speciesNum_ = (s16)speciesNum;

    sMenuWork = MemoryAlloc(sizeof(RecruitedMonSummaryMenuWork), MEMALLOC_GROUP_8);
    sMenuWork->speciesNum = speciesNum_;
    sMenuWork->windowID = windowID;
    sMenuWork->activeWinTemplate = &sMenuWork->winTemplates.id[windowID];

    RestoreSavedWindows(&sMenuWork->winTemplates);
    sMenuWork->winTemplates.id[sMenuWork->windowID] = sSummaryWinTemplate;
    sMenuWork->activeWinTemplate->header = &sMenuWork->winHeader;
    sMenuWork->winHeader.width = 10;

    RecruitedMonSummaryMenu_InitSummaryMenu();
    RecruitedMonSummaryMenu_SetupAndShowWindows();
    MenuUpdatePagesData(&sMenuWork->input);
    return TRUE;
}

u32 RecruitedMonSummaryMenu_Input(void)
{
    switch (GetKeyPress(&sMenuWork->input)) {
        case INPUT_B_BUTTON: {
            PlayMenuSoundEffect(MENU_SFX_BACK);
            return RecruitedMonSummaryMenu_INPUTRET_BACK;
        }
        case INPUT_A_BUTTON: {
            PlayMenuSoundEffect(MENU_SFX_ACCEPT);
            return RecruitedMonSummaryMenu_INPUTRET_ACCEPT;
        }
        default: {
            if (MenuCursorUpdateOnlyLeftRight(&sMenuWork->input)) {
                RecruitedMonSummaryMenu_SetupAndShowWindows();
                return RecruitedMonSummaryMenu_INPUTRET_LEFTRIGHT;
            }
            return RecruitedMonSummaryMenu_INPUTRET_NONE;
        }
    }
}

void RecruitedMonSummaryMenu_SetupAndShowWindows(void)
{
    RecruitedMonSummaryMenu_ResetAndShowWindows();
    RecruitedMonSummaryMenu_ShowSummaryWindow();
}

void RecruitedMonSummaryMenu_Destroy(void)
{
    if (sMenuWork != NULL) {
        sMenuWork->winTemplates.id[sMenuWork->windowID] = sDummyWinTemplate;
        ResetUnusedInputStruct();
        ShowWindows(&sMenuWork->winTemplates, TRUE, TRUE);
        MemoryFree(sMenuWork);
        sMenuWork = NULL;
    }
}

static void RecruitedMonSummaryMenu_ResetAndShowWindows(void)
{
    sMenuWork->winHeader.count = sMenuWork->input.pagesCount;
    sMenuWork->winHeader.currId = sMenuWork->input.currPage;
    sMenuWork->winHeader.f3 = 0;
    ResetUnusedInputStruct();
    ShowWindows(&sMenuWork->winTemplates, TRUE, TRUE);
}

static void RecruitedMonSummaryMenu_ShowSummaryWindow(void)
{
    ShowPokemonSummaryWindow(sMenuWork->summaryTabs[sMenuWork->input.currPage], sMenuWork->input.currPage, &sMenuWork->monInfo, &sMenuWork->unkB0, sMenuWork->windowID);
}

static void RecruitedMonSummaryMenu_InitSummaryMenu(void)
{
    MonSummaryInfo *dstInfo;
    Pokemon *summaryMon;
    s32 i = 0;

    sMenuWork->summaryTabs[i++] = SUB_WINDOW_STATS;
    sMenuWork->summaryTabs[i++] = SUB_WINDOW_FEATURES;
    sMenuWork->summaryTabs[i++] = SUB_WINDOW_INFO;

    CreateMenuOnWindow(&sMenuWork->input, i, 1, sMenuWork->windowID);
    dstInfo = &sMenuWork->monInfo;
    summaryMon = &gRecruitedPokemonRef->pokemon[sMenuWork->speciesNum];
    SetMonSummaryInfo(dstInfo, summaryMon, CheckQuest(QUEST_UNLOCKED_EVOLUTIONS));
}
