#include "global.h"
#include "globaldata.h"
#include "code_80130A8.h"
#include "code_8098BDC.h"
#include "common_strings.h"
#include "hints_menu1.h"
#include "hints_menu2.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "options_menu1.h"
#include "options_menu2.h"
#include "text1.h"
#include "text2.h"

enum
{
    MENU_OPTION_DEFAULT = 1,
    MENU_OPTION_HINTS,
    MENU_OPTION_GAMEOPTIONS,
    MENU_OPTION_YES,
    MENU_OPTION_NO
};

enum OptionsMenuStates
{
    OPTIONS_MENU_INIT,
    OPTIONS_MENU_MAIN,
    OPTIONS_MENU_EXIT,
    OPTIONS_MENU_PRE_HINT_SELECTION,
    OPTIONS_MENU_HINT_SELECTION,
    OPTIONS_MENU_DISPLAY_HINT,
    OPTIONS_MENU_UNKNOWN_6,
    OPTIONS_MENU_CONFIRM_NEW_OPTIONS,
};

static EWRAM_DATA_2 struct unkStruct_203B25C *sUnknown_203B25C = {0};

#include "data/options_menu1.h"

static void CreateChangeSettingsConfirmMenu(void);
static void CreateOthersMenu(void);
static void HandleChangeSettingsMenu(void);
static void HandleOthersMenu(void);
static void SetOptionsMenuState(u32 newState);

static void sub_801DD84(void);
static void sub_801DED0(void);
static void sub_801E088(void);
static void sub_801E0E0(void);
static void sub_801E0FC(void);

bool8 sub_801DCC4(void)
{
    sUnknown_203B25C = MemoryAlloc(sizeof(struct unkStruct_203B25C), 8);
    SetOptionsMenuState(OPTIONS_MENU_INIT);
    return TRUE;
}

u32 sub_801DCE8(void)
{
    switch (sUnknown_203B25C->state) {
        case OPTIONS_MENU_EXIT:
            return 3;
        case OPTIONS_MENU_INIT:
        case OPTIONS_MENU_MAIN:
            HandleOthersMenu();
            break;
        case OPTIONS_MENU_PRE_HINT_SELECTION:
        case OPTIONS_MENU_HINT_SELECTION:
            sub_801E088();
            break;
        case OPTIONS_MENU_DISPLAY_HINT:
            sub_801E0E0();
            break;
        case 6:
            sub_801E0FC();
            break;
        case OPTIONS_MENU_CONFIRM_NEW_OPTIONS:
            HandleChangeSettingsMenu();
            break;
        default:
            break;
    }

    return 0;
}

void sub_801DD50(void)
{
    if (sUnknown_203B25C != NULL) {
        MemoryFree(sUnknown_203B25C);
        sUnknown_203B25C = NULL;
    }
}

static void SetOptionsMenuState(u32 newState)
{
    sUnknown_203B25C->state = newState;
    sub_801DD84();
    sub_801DED0();
}

static void sub_801DD84(void)
{
    s32 i;

    sub_8006518(sUnknown_203B25C->unkBC);

    switch (sUnknown_203B25C->state) {
        case OPTIONS_MENU_INIT:
            CreateOthersMenu();

            for (i = 0; i < 8; i++) {
                if (sUnknown_203B25C->unkAC[i] == 0) {
                    sUnknown_203B25C->menuAction = sUnknown_203B25C->menuItems[i].menuAction;
                    break;
                }
            }

            for(i = 0; i < 4; i++)
                sUnknown_203B25C->unkBC[i] = sUnknown_80DBFB0;

            sUnknown_203B25C->unkBC[0] = sUnknown_80DBFCC;
            sub_8012CAC(&sUnknown_203B25C->unkBC[0], sUnknown_203B25C->menuItems);
            sUnknown_203B25C->unkBC[0].unkC = 10;
            break;
        case OPTIONS_MENU_MAIN:
            CreateOthersMenu();

            for (i = 0; i < 4; i++)
                sUnknown_203B25C->unkBC[i] = sUnknown_80DBFB0;

            sUnknown_203B25C->unkBC[0] = sUnknown_80DBFCC;
            sub_8012CAC(&sUnknown_203B25C->unkBC[0], sUnknown_203B25C->menuItems);
            sUnknown_203B25C->unkBC[0].unkC = 10;
            break;
        default:
            for (i = 0; i < 4; i++)
                sUnknown_203B25C->unkBC[i] = sUnknown_80DBFB0;
            break;
    }

    ResetUnusedInputStruct();
    sub_800641C(sUnknown_203B25C->unkBC, TRUE, TRUE);
}

static void sub_801DED0(void)
{
    switch (sUnknown_203B25C->state) {
        case OPTIONS_MENU_INIT:
        case OPTIONS_MENU_MAIN:
            sUnknown_203B25C->menu.unk0 = sOthers;
            sub_8012D60(&sUnknown_203B25C->menu, sUnknown_203B25C->menuItems, 0, sUnknown_203B25C->unkAC, sUnknown_203B25C->menuAction, 0);
            break;
        case OPTIONS_MENU_PRE_HINT_SELECTION:
            sub_801E3F0(0);
            break;
        case OPTIONS_MENU_HINT_SELECTION:
            CreateHintSelectionScreen(1);
            break;
        case OPTIONS_MENU_DISPLAY_HINT:
            CreateHintDisplayScreen(sUnknown_203B25C->chosenHintIndex);
            break;
        case 6:
            // Load our current options?
            sUnknown_203B25C->newOptions = *gGameOptionsRef;
            sub_801E198(&sUnknown_203B25C->newOptions);
            break;
        case OPTIONS_MENU_CONFIRM_NEW_OPTIONS:
            CreateChangeSettingsConfirmMenu();
            sub_8014248(sChangeSettingsPrompt, 0, 4, sUnknown_203B25C->menuItems, 0, 4, 0, 0, 32);
            break;
    }
}

static void CreateOthersMenu(void)
{
    s32 loopMax;

    MemoryFill16(sUnknown_203B25C->unkAC, 0, sizeof(sUnknown_203B25C->unkAC));
    loopMax = 0;

    sUnknown_203B25C->menuItems[loopMax].text = sGameOptions;
    sUnknown_203B25C->menuItems[loopMax].menuAction = MENU_OPTION_GAMEOPTIONS;

    loopMax++;
    sUnknown_203B25C->menuItems[loopMax].text = sHints;
    sUnknown_203B25C->menuItems[loopMax].menuAction = MENU_OPTION_HINTS;

    loopMax++;
    sUnknown_203B25C->menuItems[loopMax].text = NULL;
    sUnknown_203B25C->menuItems[loopMax].menuAction = MENU_OPTION_DEFAULT;
}

static void CreateChangeSettingsConfirmMenu(void)
{
    s32 loopMax;

    MemoryFill16(sUnknown_203B25C->unkAC, 0, sizeof(sUnknown_203B25C->unkAC));
    loopMax = 0;

    sUnknown_203B25C->menuItems[loopMax].text = gCommonYes[0];
    sUnknown_203B25C->menuItems[loopMax].menuAction = MENU_OPTION_YES;

    loopMax++;
    sUnknown_203B25C->menuItems[loopMax].text = gCommonNo[0];
    sUnknown_203B25C->menuItems[loopMax].menuAction = MENU_OPTION_NO;

    loopMax++;
    sUnknown_203B25C->menuItems[loopMax].text = NULL;
    sUnknown_203B25C->menuItems[loopMax].menuAction = MENU_OPTION_DEFAULT;
}

static void HandleOthersMenu(void)
{
    s32 menuAction;

    menuAction = 0;

    if (sub_8012FD8(&sUnknown_203B25C->menu) == 0) {
        sub_8013114(&sUnknown_203B25C->menu, &menuAction);
        sUnknown_203B25C->menuAction = menuAction;
    }

    switch (menuAction) {
        case MENU_OPTION_HINTS:
            SetOptionsMenuState(OPTIONS_MENU_PRE_HINT_SELECTION);
            break;
        case MENU_OPTION_GAMEOPTIONS:
            SetOptionsMenuState(6);
            break;
        case MENU_OPTION_DEFAULT:
            SetOptionsMenuState(OPTIONS_MENU_EXIT);
            break;
    }
}

static void sub_801E088(void)
{
    switch (sub_801E474(TRUE)) {
        case 3:
        case 4:
            sUnknown_203B25C->chosenHintIndex = GetChosenHintIndex();
            SetOptionsMenuState(OPTIONS_MENU_DISPLAY_HINT);
            break;
        case 2:
            sub_801E54C();
            SetOptionsMenuState(OPTIONS_MENU_MAIN);
            break;
        case 0:
        case 1:
        default:
            break;
    }
}

static void sub_801E0E0(void)
{
    switch (HandleHintDisplayScreenInput()) {
        case 3:
        case 2:
            DestroyHintDisplayScreen();
            SetOptionsMenuState(OPTIONS_MENU_HINT_SELECTION);
            break;
        case 0:
        case 1:
        default:
            break;
    }
}

static void sub_801E0FC(void)
{
    switch (sub_801E218()) {
        case 2:
        case 3:
            sub_801E2C4();

            // Check to see if the options changed?
            if (GameOptionsNotChange(&sUnknown_203B25C->newOptions))
                SetOptionsMenuState(OPTIONS_MENU_MAIN);
            else
                SetOptionsMenuState(OPTIONS_MENU_CONFIRM_NEW_OPTIONS);
            break;
        case 0:
        case 1:
            break;
    }
}

static void HandleChangeSettingsMenu(void)
{
    s32 menuAction;

    if (sub_80144A4(&menuAction))
        return;

    switch (menuAction) {
        case MENU_OPTION_YES:
            // Save our option changes??
            *gGameOptionsRef = sUnknown_203B25C->newOptions;
            SetWindowBGColor();
            sub_8099690(0);
            SetOptionsMenuState(OPTIONS_MENU_MAIN);
            break;
        case MENU_OPTION_DEFAULT:
        case MENU_OPTION_NO:
            SetOptionsMenuState(OPTIONS_MENU_MAIN);
            break;
    }
}