#include "global.h"
#include "globaldata.h"
#include "constants/colors.h"
#include "constants/input.h"
#include "code_80118A4.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "options_menu2.h"
#include "text_1.h"
#include "text_2.h"
#include "text_3.h"

static EWRAM_INIT struct unkStruct_203B260 *sUnknown_203B260 = {NULL};

#include "data/options_menu2.h"

static void CreateOptionsMenu(void);
static void nullsub_38(void);

bool8 sub_801E198(GameOptions *optionsMenu)
{
    sUnknown_203B260 = MemoryAlloc(sizeof(struct unkStruct_203B260), 8);
    sUnknown_203B260->optionsMenu = optionsMenu;
    sub_801317C(&sUnknown_203B260->unk4);
    sUnknown_203B260->unk44 = 0;
    sUnknown_203B260->unk48 = &sUnknown_203B260->unk4C.id[0];
    RestoreSavedWindows(&sUnknown_203B260->unk4C);
    sUnknown_203B260->unk4C.id[sUnknown_203B260->unk44] = sUnknown_80DC03C;
    sub_8012D08(sUnknown_203B260->unk48, 1);
    ResetUnusedInputStruct();
    ShowWindows(&sUnknown_203B260->unk4C, TRUE, TRUE);
    sub_8013818(&sUnknown_203B260->input, 1, 1, sUnknown_203B260->unk44);
    nullsub_38();
    CreateOptionsMenu();
    return TRUE;
}

u32 sub_801E218(void)
{
    bool32 flag;

    flag = FALSE;

    switch (GetMenuInput()) {
        case INPUT_B_BUTTON:
            PlayMenuSoundEffect(1);
            return 2;
        case INPUT_A_BUTTON:
            PlayMenuSoundEffect(0);
            return 3;
        case INPUT_DPAD_LEFT:
            if (sUnknown_203B260->input.menuIndex == 0) {
                if (sUnknown_203B260->optionsMenu->windowColor == WINDOW_COLOR_BLUE)
                    sUnknown_203B260->optionsMenu->windowColor = WINDOW_COLOR_GREEN;
                else
                    sUnknown_203B260->optionsMenu->windowColor--;

                PlayMenuSoundEffect(3);
                flag = TRUE;
            }
            break;
        case INPUT_DPAD_RIGHT:
            if (sUnknown_203B260->input.menuIndex == 0) {
                if (sUnknown_203B260->optionsMenu->windowColor > WINDOW_COLOR_RED)
                    sUnknown_203B260->optionsMenu->windowColor = WINDOW_COLOR_BLUE;
                else
                    sUnknown_203B260->optionsMenu->windowColor++;

                PlayMenuSoundEffect(3);
                flag = TRUE;
            }
            break;
    }

    // == TRUE is needed for matching
    if (sub_80138B8(&sUnknown_203B260->input, 1) || flag == TRUE) {
        nullsub_38();
        CreateOptionsMenu();
        return 1;
    }
    return 0;
}

void sub_801E2C4(void)
{
    if (sUnknown_203B260 != NULL) {
        sUnknown_203B260->unk4C.id[sUnknown_203B260->unk44] = sUnknown_80DC020;
        ResetUnusedInputStruct();
        ShowWindows(&sUnknown_203B260->unk4C, TRUE, TRUE);
        MemoryFree(sUnknown_203B260);
        sUnknown_203B260 = NULL;
    }
}

static void nullsub_38(void)
{
}

static void CreateOptionsMenu(void)
{
    u32 length;
    u32 y;

    CallPrepareTextbox_8008C54(sUnknown_203B260->unk44);
    sub_80073B8(sUnknown_203B260->unk44);
    PrintStringOnWindow(16, 0, sGameOptions,sUnknown_203B260->unk44, 0);

    y = GetMenuEntryYCoord(&sUnknown_203B260->input, 0);
    PrintStringOnWindow(8, y, sUnknown_80DC064, sUnknown_203B260->unk44, 0);

    switch (sUnknown_203B260->optionsMenu->windowColor) {
        case WINDOW_COLOR_BLUE:
            length = GetStringLineWidth(sBlue);
            AddDoubleUnderScoreHighlight(sUnknown_203B260->unk44, (sUnknown_203B260->optionsMenu->windowColor * 40) + 80, y + 10, length, COLOR_WHITE_2);
            break;
        case WINDOW_COLOR_RED:
            length = GetStringLineWidth(sRed);
            AddDoubleUnderScoreHighlight(sUnknown_203B260->unk44, (sUnknown_203B260->optionsMenu->windowColor * 40) + 80, y + 10, length, COLOR_WHITE_2);
            break;
        case WINDOW_COLOR_GREEN:
            length = GetStringLineWidth(sGreen);
            AddDoubleUnderScoreHighlight(sUnknown_203B260->unk44, (sUnknown_203B260->optionsMenu->windowColor * 40) + 80, y + 10, length, COLOR_WHITE_2);
            break;
    }

    sub_80073E0(sUnknown_203B260->unk44);
}
