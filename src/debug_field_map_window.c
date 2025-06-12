#include "global.h"
#include "globaldata.h"
#include "debug_field_map_window.h"
#include "constants/input.h"
#include "structs/struct_sub80095e4.h"
#include "music_util.h"
#include "ground_main.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "text_1.h"
#include "text_2.h"
#include "structs/str_81188F0.h"

EWRAM_INIT static struct struct_Sub80095E4_2 *sDebugWindow = {NULL};

static const WindowTemplate sDummyWinTemplate = WIN_TEMPLATE_DUMMY;

static const WindowTemplate sUnknown_80DBF88 = {
    0,
    6,
    2, 2,
    24, 17,
    17, 0,
    NULL
};

static void sub_801DB54(void);
static void sub_801DBD4(void);

#define WINDOW_ID_DEBUG 3

bool8 DebugFieldMapWindow_Init(void)
{
    sDebugWindow = MemoryAlloc(sizeof(*sDebugWindow), 8);
    sDebugWindow->s0.winId = WINDOW_ID_DEBUG;
    sDebugWindow->s0.unk38 = &sDebugWindow->s0.windows.id[WINDOW_ID_DEBUG];
    RestoreSavedWindows(&sDebugWindow->s0.windows);
    sDebugWindow->s0.windows.id[sDebugWindow->s0.winId] = sUnknown_80DBF88;
    sDebugWindow->s0.unk38->header = &sDebugWindow->header;
    ResetUnusedInputStruct();
    ShowWindows(&sDebugWindow->s0.windows, TRUE, TRUE);
    CreateMenuOnWindow(&sDebugWindow->s0.input, 229, 10, sDebugWindow->s0.winId);
    sub_801DB54();
    sub_801DBD4();
    return TRUE;
}

void sub_801DA58(s16 a0)
{
    s32 cast;
    cast = a0;
    sub_8013878(&sDebugWindow->s0.input, cast);
    sub_801DB54();
    sub_801DBD4();
}

u32 DebugFieldMapWindow_GetInput(void)
{
    switch (GetKeyPress(&sDebugWindow->s0.input)) {
        case INPUT_B_BUTTON:
            PlayMenuSoundEffect(1);
            return DEBUG_INPUT_B_PRESS;
        case INPUT_A_BUTTON:
            return DEBUG_INPUT_A_PRESS;
        default:
            if (MenuCursorUpdate(&sDebugWindow->s0.input, TRUE)) {
                sub_801DB54();
                sub_801DBD4();
                return DEBUG_INPUT_DPAD;
            }
            return DEBUG_INPUT_NOTHING;
    }
}

s16 DebugFieldMapWindow_GetCurrentIndex(void)
{
    return GET_CURRENT_MENU_ENTRY(sDebugWindow->s0.input);
}

UNUSED static void sub_801DADC(bool8 a0)
{
    sDebugWindow->s0.input.totalEntriesCount = 229;
    MenuUpdatePagesData(&sDebugWindow->s0.input);
    sub_801DB54();
    sub_801DBD4();
    if (a0)
        AddMenuCursorSprite(&sDebugWindow->s0.input);
}

void DebugFieldMapWindow_Free(void)
{
    if (sDebugWindow != NULL) {
        sDebugWindow->s0.windows.id[sDebugWindow->s0.winId] = sDummyWinTemplate;
        ResetUnusedInputStruct();
        ShowWindows(&sDebugWindow->s0.windows, TRUE, TRUE);
        FREE_AND_SET_NULL(sDebugWindow);
    }
}

static void sub_801DB54(void)
{
    sDebugWindow->header.count = 1;
    sDebugWindow->header.currId = 0;
    sDebugWindow->header.width = 8;
    sDebugWindow->header.f3 = 0;

    ResetUnusedInputStruct();
    ShowWindows(&sDebugWindow->s0.windows, TRUE, TRUE);

    SUB_80095E4_CALL(sDebugWindow->s0);
}

static void sub_801DBD4(void)
{
    GroundConversionStruct *temp;
    const struct unkStruct_81188F0 *temp2;
    s32 x, y, n;
    s16 index;
    int counter;

    CallPrepareTextbox_8008C54(sDebugWindow->s0.winId);
    sub_80073B8(sDebugWindow->s0.winId);
    PrintStringOnWindow(10, 0, _("Field"), sDebugWindow->s0.winId, 0);

    x = (sDebugWindow->header.width * 8) - 2;
    n = sDebugWindow->s0.input.currPage + 1;
    sub_8012BC4(x, 0, n, 2, 7, sDebugWindow->s0.winId);

    // This line has no real effect. It's a magic 'fakematch' to fool agb into generating the same asm. It can be removed if you don't care about matching.
    if (x) { counter = 0; }

    for (counter = 0; counter < sDebugWindow->s0.input.currPageEntries; counter++) {
        index = (sDebugWindow->s0.input.currPage * sDebugWindow->s0.input.entriesPerPage) + counter;
        temp = &gGroundConversion_811BAF4[index];
        temp2 = &gUnknown_81188F0[temp->unk4];

        y = GetMenuEntryYCoord(&sDebugWindow->s0.input, counter);
        PrintStringOnWindow(8, y, temp2->text1, sDebugWindow->s0.winId, 0);

        y = GetMenuEntryYCoord(&sDebugWindow->s0.input, counter);
        PrintStringOnWindow(62, y, temp->text, sDebugWindow->s0.winId, 0);
    }

    sub_80073E0(sDebugWindow->s0.winId);
}
