#include "global.h"
#include "globaldata.h"
#include "code_801602C.h"
#include "friend_list.h"
#include "debug_menu4.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "string_format.h"
#include "text_1.h"
#include "text_2.h"
#include "text_3.h"

EWRAM_INIT static unkStruct_203B3F8 *sUnknown_203B3F8 = {NULL};

#include "data/debug_menu4.h"

enum menuActions {
    CANCEL_ACTION = 1,
    LEVEL_ACTION = 4,
    NAME_ACTION
};

static void sub_803ACD0(u32 newState);
static void sub_803ACE8(void);
static void sub_803AD88(void);
static void sub_803AE58(void);
static void sub_803AEB0(void);
static void sub_803AF38(void);
static void sub_803AF88(void);
static void sub_803AFE8(void);
static void sub_803B034(void);

UNUSED static bool8 sub_803AC24(void)
{
    sUnknown_203B3F8 = MemoryAlloc(sizeof(unkStruct_203B3F8), 8);
    sub_803ACD0(0);
    return TRUE;
}

UNUSED static u32 sub_803AC48(void)
{
    switch (sUnknown_203B3F8->state) {
        case 0:
            sub_803ACD0(1);
            break;
        case 1:
        case 2:
            sub_803AF38();
            break;
        case 3:
            sub_803AF88();
            break;
        case 5:
            sub_803AFE8();
            break;
        case 6:
            sub_803B034();
            break;
        case 4:
        case 7:
        default:
            return 3;
    }
    return 0;
}

UNUSED static void sub_803ACB4(void)
{
    if (sUnknown_203B3F8 != NULL) {
        MemoryFree(sUnknown_203B3F8);
        sUnknown_203B3F8 = NULL;
    }
}

static void sub_803ACD0(u32 newState)
{
    sUnknown_203B3F8->state = newState;
    sub_803ACE8();
    sub_803AD88();
}

static void sub_803ACE8(void)
{
    s32 i;

    RestoreSavedWindows(&sUnknown_203B3F8->unkE0);

    switch (sUnknown_203B3F8->state) {
        case 3:
            sub_803AEB0();
            sUnknown_203B3F8->unkE0.id[2] = sUnknown_80E7EEC;
            sub_8012CAC(&sUnknown_203B3F8->unkE0.id[2], sUnknown_203B3F8->unk90);
            break;
        case 5:
            sUnknown_203B3F8->unkE0.id[3] = sUnknown_80E7F04;
            break;
        default:
            for (i = 0; i < 4; i++)
                sUnknown_203B3F8->unkE0.id[i] = sUnknown_80E7ED4;
            break;
    }

    ResetUnusedInputStruct();
    ShowWindows(&sUnknown_203B3F8->unkE0, TRUE, TRUE);
}

static void sub_803AD88(void)
{
    switch (sUnknown_203B3F8->state) {
        case 1:
            FriendList_Init(1, 0, 0, 10);
            break;
        case 2:
            sub_8023B7C(1);
            break;
        case 3:
            FriendList_ShowWindow();
            sub_8012D60(&sUnknown_203B3F8->unk10, sUnknown_203B3F8->unk90, 0, sUnknown_203B3F8->unkD0, sUnknown_203B3F8->menuAction, 2);
            break;
        case 5:
            sUnknown_203B3F8->unk60.unk10 = 3;
            sUnknown_203B3F8->unk60.unk8 = 1;
            sUnknown_203B3F8->unk60.unkC = 100;
            sUnknown_203B3F8->unk60.unk4 = sUnknown_203B3F8->pokemon->level;
            sUnknown_203B3F8->unk60.unk14 = 3;
            sUnknown_203B3F8->unk60.unk18 = &sUnknown_203B3F8->unkE0.id[3];
            sUnknown_203B3F8->unk60.unk1C = 44;
            sUnknown_203B3F8->unk60.unk20 = 18;
            sub_8013AA0(&sUnknown_203B3F8->unk60);
            sub_803AE58();
            break;
        case 6:
            CreateConfirmNameMenu(2, sUnknown_203B3F8->pokemon->name);
        case 0:
        case 4:
        case 7:
        default:
            break;

    }
}

static void sub_803AE58(void)
{
    CallPrepareTextbox_8008C54(sUnknown_203B3F8->unk60.unk14);
    sub_80073B8(sUnknown_203B3F8->unk60.unk14);
    PrintStringOnWindow(4, 0, sNumberPrompt, sUnknown_203B3F8->unk60.unk14, 0);
    sub_8013C68(&sUnknown_203B3F8->unk60);
    sub_80073E0(sUnknown_203B3F8->unk60.unk14);
    FriendList_ShowWindow();
    sub_8012EA4(&sUnknown_203B3F8->unk10, 0);
}

static void sub_803AEB0(void)
{
    s32 i;
    s32 loopMax;

    MemoryFill16(sUnknown_203B3F8->unkD0, 0, sizeof(sUnknown_203B3F8->unkD0));

    loopMax = 0;
    sUnknown_203B3F8->unk90[loopMax].text = sLevel;
    sUnknown_203B3F8->unk90[loopMax].menuAction = LEVEL_ACTION;

    loopMax++;
    sUnknown_203B3F8->unk90[loopMax].text = sName;
    sUnknown_203B3F8->unk90[loopMax].menuAction = NAME_ACTION;

    loopMax++;
    sUnknown_203B3F8->unk90[loopMax].text = NULL;
    sUnknown_203B3F8->unk90[loopMax].menuAction = CANCEL_ACTION;

    for (i = 0; i < loopMax; i++) {
        if (sUnknown_203B3F8->unkD0[i] == 0) {
            sUnknown_203B3F8->menuAction = sUnknown_203B3F8->unk90[i].menuAction;
            break;
        }
    }
}

static void sub_803AF38(void)
{
    switch (FriendList_HandleInput(TRUE)) {
        case 3:
            sUnknown_203B3F8->unk4 = FriendList_GetCurrId();
            sUnknown_203B3F8->pokemon = &gRecruitedPokemonRef->pokemon[sUnknown_203B3F8->unk4];
            sub_803ACD0(3);
            break;
        case 2:
            FriendList_Free();
            sub_803ACD0(7);
            break;
        case 1:
        case 0:
            break;
    }
}

static void sub_803AF88(void)
{
    s32 menuAction;

    menuAction = 0;

    FriendList_HandleInput(FALSE);

    if (sub_8012FD8(&sUnknown_203B3F8->unk10) == 0)
        sub_8013114(&sUnknown_203B3F8->unk10, &menuAction);

    switch (menuAction) {
        case LEVEL_ACTION:
            sub_803ACD0(5);
            break;
        case NAME_ACTION:
            sub_803ACD0(6);
            break;
        case CANCEL_ACTION:
            sub_803ACD0(2);
            break;
        default:
            break;
    }
}

static void sub_803AFE8(void)
{
    FriendList_HandleInput(FALSE);
    sub_8012FD8(&sUnknown_203B3F8->unk10);

    switch (sub_8013BBC(&sUnknown_203B3F8->unk60)) {
        default:
            break;
        case 3:
            sUnknown_203B3F8->pokemon->level = sUnknown_203B3F8->unk60.unk0;
            // Fallthrough is needed to match
        case 2:
            sub_803ACD0(2);
            break;
        case 1:
            sub_803AE58();
            break;
    }
}

static void sub_803B034(void)
{
    switch (sub_8016080()) {
        case 2:
        case 3:
            CleanConfirmNameMenu();
            sub_803ACD0(2);
            break;
    }
}
