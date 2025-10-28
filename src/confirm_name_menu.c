#include "global.h"
#include "globaldata.h"
#include "confirm_name_menu.h"
#include "common_strings.h"
#include "input.h"
#include "memory.h"
#include "string_format.h"
#include "text_util.h"
#include "text_1.h"
#include "naming_screen.h"

// size: 0x50
struct ConfirmMenuStruct
{
    u32 unk0;
    u32 unk4;
    /* 0x8 */ u8 *pokeName;
    /* 0xC */ s32 state;
    /* 0x10 */ MenuItem menus[8];
};

EWRAM_INIT static struct ConfirmMenuStruct *sConfirmMenu = {NULL};

enum
{
    MENU_ACTION_DEFAULT = 1,
    MENU_ACTION_YES,
    MENU_ACTION_NO,
};

static void BuildConfirmNameMenu(void);
static void HandleConfirmNameMenu(void);
static bool8 IsNameEmpty(void);
static void nullsub_36(void);
static void SetConfirmNameMenuState(u32 newState);
static void sub_8016110(void);
static void sub_80161F8(void);
static void sub_8016280(void);
static void sub_801629C(void);

enum ConfirmNameMenuStates
{
    CONFIRM_NAME_MENU_INIT,
    CONFIRM_NAME_MENU_PROMPT,
    CONFIRM_NAME_MENU_TOO_LONG,
    CONFIRM_NAME_MENU_EMPTY,
    CONFIRM_NAME_MENU_EXIT = 4
};

UNUSED static const WindowTemplate sUnusedWinTemplate = WIN_TEMPLATE_DUMMY;

ALIGNED(4) static const u8 sIsNameOKPrompt[] = _("Is the name {COLOR CYAN}{POKEMON_0}{RESET} OK?");
ALIGNED(4) static const u8 sNameTooLong[] = _("This name is too long.");
ALIGNED(4) static const u8 sEnterAName[] = _("Please enter a name.");

u32 CreateConfirmNameMenu(u32 mode, u8 *name)
{
    ResetUnusedInputStruct();
    ShowWindows(NULL, TRUE, TRUE);

    sConfirmMenu = MemoryAlloc(sizeof(struct ConfirmMenuStruct), 8);
    sConfirmMenu->unk0 = mode;
    sConfirmMenu->pokeName = name;

    switch (mode) {
        case 0:
            sConfirmMenu->unk4 = 0;
            break;
        case 1:
            sConfirmMenu->unk4 = 1;
            break;
        case 2:
            sConfirmMenu->unk4 = 2;
            break;
        case 3:
            sConfirmMenu->unk4 = 3;
            break;
        default:
            break;
    }

    SetConfirmNameMenuState(CONFIRM_NAME_MENU_INIT);
    return 1;
}

u32 sub_8016080(void)
{
    switch (sConfirmMenu->state) {
        case CONFIRM_NAME_MENU_INIT:
            sub_80161F8();
            break;
        case CONFIRM_NAME_MENU_PROMPT:
            HandleConfirmNameMenu();
            break;
        case CONFIRM_NAME_MENU_TOO_LONG:
            sub_8016280();
            break;
        case CONFIRM_NAME_MENU_EMPTY:
            sub_801629C();
            break;
        case CONFIRM_NAME_MENU_EXIT:
            return 3;
    }
    return 0;
}

void CleanConfirmNameMenu(void)
{
    if (sConfirmMenu != NULL) {
        MemoryFree(sConfirmMenu);
        sConfirmMenu = NULL;
    }
}

static void SetConfirmNameMenuState(u32 newState)
{
    sConfirmMenu->state = newState;
    nullsub_36();
    sub_8016110();
}

static void nullsub_36(void)
{
}

static void sub_8016110(void)
{
    switch (sConfirmMenu->state) {
        case CONFIRM_NAME_MENU_INIT:
            NamingScreen_Init(sConfirmMenu->unk4, sConfirmMenu->pokeName);
            break;
        case CONFIRM_NAME_MENU_PROMPT:
            BuildConfirmNameMenu();
            if (sConfirmMenu->unk4 == 1)
                StrncpyCustom(gFormatBuffer_Monsters[0], sConfirmMenu->pokeName, POKEMON_NAME_LENGTH);
            else
                StrncpyCustom(gFormatBuffer_Monsters[0], sConfirmMenu->pokeName, POKEMON_NAME_LENGTH);

            CreateMenuDialogueBoxAndPortrait(sIsNameOKPrompt, 0, 3, sConfirmMenu->menus, 0, 4, 0, NULL, 32);
            break;

        case CONFIRM_NAME_MENU_TOO_LONG:
            CreateDialogueBoxAndPortrait(sNameTooLong, 0, 0, 0x121);
            break;
        case CONFIRM_NAME_MENU_EMPTY:
            CreateDialogueBoxAndPortrait(sEnterAName, 0, 0, 0x121);
            break;
        default:
            break;
    }
}

static void BuildConfirmNameMenu(void)
{
    sConfirmMenu->menus[0].text = gCommonYes[0];
    sConfirmMenu->menus[0].menuAction = MENU_ACTION_YES;

    sConfirmMenu->menus[1].text = gCommonNo[0];
    sConfirmMenu->menus[1].menuAction = MENU_ACTION_NO;

    sConfirmMenu->menus[2].text = NULL;
    sConfirmMenu->menus[2].menuAction = MENU_ACTION_DEFAULT;
}

static void sub_80161F8(void)
{
    if (NamingScreen_HandleInput() != 3)
        return;

    NamingScreen_Free();
    if (IsNameEmpty()) {
        SetConfirmNameMenuState(CONFIRM_NAME_MENU_EMPTY);
    }
    else {
        s32 width = GetStrWidth(sConfirmMenu->pokeName, POKEMON_NAME_LENGTH);
        s32 maxWidth = GetMaxPokeNameWidth(); // returns 60
        if (width > maxWidth)
            SetConfirmNameMenuState(CONFIRM_NAME_MENU_TOO_LONG);
        else
            SetConfirmNameMenuState(CONFIRM_NAME_MENU_PROMPT);
    }
}

static void HandleConfirmNameMenu(void)
{
    s32 temp;

    if (sub_80144A4(&temp))
        return;

    switch (temp) {
        case MENU_ACTION_YES:
            SetConfirmNameMenuState(CONFIRM_NAME_MENU_EXIT);
            break;
        case MENU_ACTION_NO:
        case MENU_ACTION_DEFAULT:
            SetConfirmNameMenuState(CONFIRM_NAME_MENU_INIT);
            break;
        default:
            break;
    }
}

static void sub_8016280(void)
{
    s32 temp;

    if (sub_80144A4(&temp) == 0)
        SetConfirmNameMenuState(CONFIRM_NAME_MENU_INIT);
}

static void sub_801629C(void)
{
    s32 temp;

    if (sub_80144A4(&temp) == 0)
        SetConfirmNameMenuState(CONFIRM_NAME_MENU_INIT);
}

static bool8 IsNameEmpty(void)
{
    s32 i;
    s32 n = POKEMON_NAME_LENGTH;

    for (i = 0; i < n; i++) {
        u8 character = sConfirmMenu->pokeName[i];

        if (character == '\0')
            return TRUE;
        if (character != ' ')
            return FALSE;
    }

    return TRUE;
}
