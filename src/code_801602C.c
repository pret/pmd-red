#include "global.h"
#include "globaldata.h"
#include "code_8012A18_1.h"
#include "string_format.h"
#include "code_801602C.h"
#include "common_strings.h"
#include "input.h"
#include "memory.h"
#include "text_util.h"
#include "text.h"

static EWRAM_DATA_2 struct unkStruct_203B200 *sUnknown_203B200 = {0};

#include "data/code_801602C.h"

static void BuildConfirmNameMenu(void);
static void HandleConfirmNameMenu(void);
static bool8 IsNameEmpty(void);
static void nullsub_36(void);

static void SetConfirmNameMenuState(u32 newState);
static void sub_8016110(void);
static void sub_80161F8(void);
static void sub_8016280(void);
static void sub_801629C(void);

u32 CreateConfirmNameMenu(u32 mode, u8 *name)
{
    ResetUnusedInputStruct();
    xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);

    sUnknown_203B200 = MemoryAlloc(sizeof(struct unkStruct_203B200), 8);
    sUnknown_203B200->unk0 = mode;
    sUnknown_203B200->pokeName = name;

    switch (mode) {
        case 0:
            sUnknown_203B200->unk4 = 0;
            break;
        case 1:
            sUnknown_203B200->unk4 = 1;
            break;
        case 2:
            sUnknown_203B200->unk4 = 2;
            break;
        case 3:
            sUnknown_203B200->unk4 = 3;
            break;
        default:
            break;
    }

    SetConfirmNameMenuState(CONFIRM_NAME_MENU_INIT);
    return 1;
}

u32 sub_8016080(void)
{
    switch (sUnknown_203B200->state) {
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
    if (sUnknown_203B200 != NULL) {
        MemoryFree(sUnknown_203B200);
        sUnknown_203B200 = NULL;
    }
}

static void SetConfirmNameMenuState(u32 newState)
{
    sUnknown_203B200->state = newState;
    nullsub_36();
    sub_8016110();
}

static void nullsub_36(void)
{
}

static void sub_8016110(void)
{
    switch (sUnknown_203B200->state) {
        case CONFIRM_NAME_MENU_INIT:
            sub_80151C0(sUnknown_203B200->unk4, sUnknown_203B200->pokeName);
            break;
        case CONFIRM_NAME_MENU_PROMPT:
            BuildConfirmNameMenu();
            if (sUnknown_203B200->unk4 == 1)
                sub_80922B4(gFormatBuffer_Monsters[0], sUnknown_203B200->pokeName, POKEMON_NAME_LENGTH);
            else
                sub_80922B4(gFormatBuffer_Monsters[0], sUnknown_203B200->pokeName, POKEMON_NAME_LENGTH);

            CreateMenuDialogueBoxAndPortrait(sIsNameOKPrompt, 0, 3, sUnknown_203B200->menus, 0, 4, 0, NULL, 32);
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
    sUnknown_203B200->menus[0].text = gCommonYes[0];
    sUnknown_203B200->menus[0].menuAction = MENU_ACTION_YES;

    sUnknown_203B200->menus[1].text = gCommonNo[0];
    sUnknown_203B200->menus[1].menuAction = MENU_ACTION_NO;

    sUnknown_203B200->menus[2].text = NULL;
    sUnknown_203B200->menus[2].menuAction = MENU_ACTION_DEFAULT;
}

static void sub_80161F8(void)
{
    s32 length;
    s32 maxLength;

    if (sub_80154F0() != 3)
        return;

    sub_80155F0();

    if (IsNameEmpty()) {
        SetConfirmNameMenuState(CONFIRM_NAME_MENU_EMPTY);
    }
    else {
        length = sub_8015FEC(sUnknown_203B200->pokeName, POKEMON_NAME_LENGTH);
        maxLength = sub_8016028(); // returns 60
        if (length > maxLength)
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
    u8 character;
    s32 index;
    s32 max;

    max = POKEMON_NAME_LENGTH; // constant needed at top of loop to match
    index = 0;
    do {
        character = sUnknown_203B200->pokeName[index];

        if (character == '\0')
            break;
        if (character != ' ')
            return FALSE;

        index++;
    } while (index < max);

    return TRUE;
}
