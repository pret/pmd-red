#include "global.h"
#include "globaldata.h"
#include "code_801B3C0.h"
#include "code_801C8C4.h"
#include "common_strings.h"
#include "debug_menu2.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "string_format.h"
#include "text_1.h"
#include "text_2.h"

static EWRAM_INIT unkStruct_203B3F0 *sUnknown_203B3F0 = {NULL};

#include "data/debug_menu2.h"

enum menuActions {
    CANCEL_ACTION = 1,
    NUMBER_ACTION,
    INFO_ACTION
};

static void sub_803A504(u32 newState);
static void sub_803A51C(void);
static void sub_803A5A0(void);
static void sub_803A690(void);
static void sub_803A6F0(void);
static void sub_803A740(void);
static void sub_803A7B0(void);
static void sub_803A810(void);
static void sub_803A86C(void);

UNUSED static bool8 sub_803A45C(void)
{
    ResetUnusedInputStruct();
    ShowWindows(NULL, TRUE, TRUE);
    sUnknown_203B3F0 = MemoryAlloc(sizeof(unkStruct_203B3F0), 8);
    sub_803A504(0);
    return TRUE;
}

UNUSED static u32 sub_803A48C(void)
{
    switch (sUnknown_203B3F0->state) {
        case 0:
        case 1:
            sub_803A740();
            break;
        case 2:
            sub_803A7B0();
            break;
        case 3:
            sub_803A810();
            break;
        case 4:
            sub_803A86C();
            break;
        case 5:
            return 3;
    }
    return 0;
}

UNUSED static void sub_803A4E8(void)
{
    if (sUnknown_203B3F0 != NULL) {
        MemoryFree(sUnknown_203B3F0);
        sUnknown_203B3F0 = NULL;
    }
}

static void sub_803A504(u32 newState)
{
    sUnknown_203B3F0->state = newState;
    sub_803A51C();
    sub_803A5A0();
}

static void sub_803A51C(void)
{
    s32 i;

    RestoreSavedWindows(&sUnknown_203B3F0->unkD8);

    switch (sUnknown_203B3F0->state) {
        case 3:
            sUnknown_203B3F0->unkD8.id[1] = sUnknown_80E7E64;
            break;
        case 2:
            sUnknown_203B3F0->unkD8.id[2] = sUnknown_80E7E4C;
            break;
        default:
            for (i = 0; i < 4; i++)
                sUnknown_203B3F0->unkD8.id[i] = sUnknown_80E7E34;
            break;
    }

    ResetUnusedInputStruct();
    ShowWindows(&sUnknown_203B3F0->unkD8, TRUE, TRUE);
}

static void sub_803A5A0(void)
{
    Item item;

    switch (sUnknown_203B3F0->state) {
        case 0:
            sub_801C8C4(2, 3, 0, 10);
            break;
        case 1:
            sub_801CB5C(TRUE);
            break;
        case 2:
            sub_801CCD8();
            sub_803A6F0();
            sub_8012D60(&sUnknown_203B3F0->unk4C, sUnknown_203B3F0->menuItems, 0, 0, sUnknown_203B3F0->menuAction, 2);
            break;
        case 3:
            sUnknown_203B3F0->unk9C.unk10 = 3;
            sUnknown_203B3F0->unk9C.unk8 = 0;
            sUnknown_203B3F0->unk9C.unkC = 999;
            sUnknown_203B3F0->unk9C.unk4 = gTeamInventoryRef->teamStorage[sUnknown_203B3F0->id];
            sUnknown_203B3F0->unk9C.unk14 = 1;
            sUnknown_203B3F0->unk9C.unk18 = &sUnknown_203B3F0->unkD8.id[1];
            sUnknown_203B3F0->unk9C.unk1C = 44;
            sUnknown_203B3F0->unk9C.unk20 = 18;
            sub_8013AA0(&sUnknown_203B3F0->unk9C);
            sub_803A690();
            break;
        case 4:
            ItemIdToSlot(&item, sUnknown_203B3F0->id, 0);
            InitItemDescriptionWindow(&item);
            break;
        case 5:
            break;
    }
}

static void sub_803A690(void)
{
    CallPrepareTextbox_8008C54(sUnknown_203B3F0->unk9C.unk14);
    sub_80073B8(sUnknown_203B3F0->unk9C.unk14);
    PrintStringOnWindow(4, 0, sNumberPrompt, sUnknown_203B3F0->unk9C.unk14, 0);
    sub_8013C68(&sUnknown_203B3F0->unk9C);
    sub_80073E0(sUnknown_203B3F0->unk9C.unk14);
    sub_801CCD8();
    sub_8012EA4(&sUnknown_203B3F0->unk4C, 0);
}

static void sub_803A6F0(void)
{
    s32 loopMax = 0;

    sUnknown_203B3F0->menuItems[loopMax].text = sNumberPrompt;
    sUnknown_203B3F0->menuItems[loopMax].menuAction = NUMBER_ACTION;
    sUnknown_203B3F0->menuAction = NUMBER_ACTION;
    if (!IsNotMoneyOrUsedTMItem(sUnknown_203B3F0->id)) {
        sUnknown_203B3F0->menuItems[loopMax].menuAction = -1;
        sUnknown_203B3F0->menuAction = INFO_ACTION;
    }

    loopMax++;
    sUnknown_203B3F0->menuItems[loopMax].text = gCommonInfo[0];
    sUnknown_203B3F0->menuItems[loopMax].menuAction = INFO_ACTION;

    loopMax++;
    sUnknown_203B3F0->menuItems[loopMax].text = NULL;
    sUnknown_203B3F0->menuItems[loopMax].menuAction = CANCEL_ACTION;
}

static void sub_803A740(void)
{
    switch (sub_801CA08(TRUE)) {
        case 0:
        case 1:
            break;
        case 3:
            sUnknown_203B3F0->id = sub_801CB24();
            sub_803A504(2);
            break;
        case 4:
            sUnknown_203B3F0->id = sub_801CB24();
            sub_803A504(4);
            break;
        case 2:
            sub_801CBB8();
            sub_803A504(5);
            break;
    }
}

static void sub_803A7B0(void)
{
    s32 menuAction;

    menuAction = 0;

    sub_801CA08(FALSE);

    if (sub_8012FD8(&sUnknown_203B3F0->unk4C) == 0)
        sub_8013114(&sUnknown_203B3F0->unk4C, &menuAction);

    switch (menuAction) {
        case NUMBER_ACTION:
            sub_803A504(3);
            break;
        case INFO_ACTION:
            sub_803A504(4);
            break;
        case CANCEL_ACTION:
            sub_803A504(1);
            break;
    }
}

static void sub_803A810(void)
{
    sub_801CA08(FALSE);
    sub_8012FD8(&sUnknown_203B3F0->unk4C);

    switch (sub_8013BBC(&sUnknown_203B3F0->unk9C)) {
        case 3:
            gTeamInventoryRef->teamStorage[sUnknown_203B3F0->id] = sUnknown_203B3F0->unk9C.unk0;
            // Fallthrough needed to match
        case 2:
            sub_803A504(1);
            break;
        case 1:
            sub_803A690();
            break;
    }
}

static void sub_803A86C(void)
{
    switch (sub_801B410()) {
        case 1:
        case 0:
            break;
        case 2:
        case 3:
            FreeItemDescriptionWindow();
            sub_803A504(1);
            break;
    }
}
