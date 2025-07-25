#include "global.h"
#include "globaldata.h"
#include "code_801EE10_mid.h"
#include "common_strings.h"
#include "debug_menu3.h"
#include "friend_area.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "pokemon.h"
#include "text_1.h"
#include "wigglytuff_shop1.h"
#include "wigglytuff_shop2.h"

EWRAM_INIT static unkStruct_203B3F4 *sUnknown_203B3F4 = {NULL};

#include "data/debug_menu3.h"

enum menuActions {
    CANCEL_ACTION = 1,
    OPEN_ACTION,
    CLOSE_ACTION,
    INFO_ACTION
};

static void sub_803A924(u32 newState);
static void sub_803A93C(void);
static void sub_803A9AC(void);
static void sub_803AA34(void);
static void sub_803AAC4(void);
static void sub_803AB34(void);
static void sub_803ABAC(void);
static bool8 sub_803ABC8(void);

UNUSED static bool8 sub_803A888(void)
{
    ResetUnusedInputStruct();
    ShowWindows(NULL, TRUE, TRUE);
    sUnknown_203B3F4 = MemoryAlloc(sizeof(unkStruct_203B3F4), 8);
    sub_803A924(0);
    return TRUE;
}

UNUSED static u32 sub_803A8B8(void)
{
    switch (sUnknown_203B3F4->state) {
        case 0:
        case 1:
            sub_803AAC4();
            break;
        case 2:
            sub_803AB34();
            break;
        case 3:
            sub_803ABAC();
            break;
        case 4:
            return 3;
    }
    return 0;
}

UNUSED static void sub_803A908(void)
{
    if (sUnknown_203B3F4 != NULL) {
        MemoryFree(sUnknown_203B3F4);
        sUnknown_203B3F4 = NULL;
    }
}

static void sub_803A924(u32 newState)
{
    sUnknown_203B3F4->state = newState;
    sub_803A93C();
    sub_803A9AC();
}

static void sub_803A93C(void)
{
    s32 i;

    RestoreSavedWindows(&sUnknown_203B3F4->unk9C);

    if (sUnknown_203B3F4->state == 2)
        sUnknown_203B3F4->unk9C.id[2] = sUnknown_80E7EA4;
    else {
        for(i = 0; i < 4; i++)
            sUnknown_203B3F4->unk9C.id[i] = sUnknown_80E7E8C;
    }

    ResetUnusedInputStruct();
    ShowWindows(&sUnknown_203B3F4->unk9C, TRUE, TRUE);
}

static void sub_803A9AC(void)
{
    switch (sUnknown_203B3F4->state) {
        case 0:
            sub_80211AC(0, 3);
            break;
        case 1:
            sub_8021354(TRUE);
            break;
        case 2:
            sub_8021494();
            sub_803AA34();
            sub_8012D60(&sUnknown_203B3F4->unk4C, sUnknown_203B3F4->menuItems, 0, 0, sUnknown_203B3F4->menuAction, 2);
            break;
        case 3:
            CreateWigglytuffShopFriendAreaMenu(sUnknown_203B3F4->friendArea, TRUE, 0);
            break;
        case 4:
            break;
    }
}

static void sub_803AA34(void)
{
    s32 index;
    u8 *friendAreas;

    index = 0;

    friendAreas = gFriendAreas;

    if (friendAreas[sUnknown_203B3F4->friendArea]) {
        sUnknown_203B3F4->menuItems[0].text = sClose;

        if (sub_803ABC8())
            sUnknown_203B3F4->menuItems[0].menuAction = CLOSE_ACTION;
        else
            sUnknown_203B3F4->menuItems[0].menuAction = -1;
    }
    else {
        sUnknown_203B3F4->menuItems[0].text = sOpen;
        sUnknown_203B3F4->menuItems[0].menuAction = OPEN_ACTION;
    }

    index++;
    sUnknown_203B3F4->menuItems[index].text = gCommonInfo[0];
    sUnknown_203B3F4->menuItems[index].menuAction = INFO_ACTION;

    index++;
    sUnknown_203B3F4->menuItems[index].text = NULL;
    sUnknown_203B3F4->menuItems[index].menuAction = CANCEL_ACTION;

    sUnknown_203B3F4->menuAction = sUnknown_203B3F4->menuItems[0].menuAction;
}

static void sub_803AAC4(void)
{
    switch (sub_8021274(TRUE)) {
        case 0:
        case 1:
            break;
        case 3:
            sUnknown_203B3F4->friendArea = sub_802132C();
            sub_803A924(2);
            break;
        case 4:
            sUnknown_203B3F4->friendArea = sub_802132C();
            sub_803A924(3);
            break;
        case 2:
            sub_80213A0();
            sub_803A924(4);
            break;
   }
}

static void sub_803AB34(void)
{
    s32 menuAction;

    menuAction = 0;

    sub_8021274(0);

    if (!sub_8012FD8(&sUnknown_203B3F4->unk4C))
        sub_8013114(&sUnknown_203B3F4->unk4C, &menuAction);

    switch (menuAction) {
        case OPEN_ACTION:
            UnlockFriendArea(sUnknown_203B3F4->friendArea);
            sub_803A924(1);
            break;
        case CLOSE_ACTION:
            sub_809249C(sUnknown_203B3F4->friendArea, 1);
            sub_803A924(1);
            break;
        case INFO_ACTION:
            sub_803A924(3);
            break;
        case CANCEL_ACTION:
            sub_803A924(1);
            break;
    }
}

static void sub_803ABAC(void)
{
    switch (HandleWigglytuffShopFriendAreaMenuInput()) {
        case 2:
        case 3:
            CleanWigglytuffShopFriendAreaInfoMenu();
            sub_803A924(1);
            break;
        case 0:
        case 1:
            break;
    }
}

static bool8 sub_803ABC8(void)
{
    s32 i;

    for (i = 0; i < NUM_MONSTERS; i++) {
        Pokemon *mon = &gRecruitedPokemonRef->pokemon[i];

        if (PokemonExists(mon)
            && PokemonFlag2(mon)
            && sUnknown_203B3F4->friendArea == GetFriendArea(mon->speciesNum))
            return FALSE;

    }
    return TRUE;
}
