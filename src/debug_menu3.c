#include "global.h"
#include "code_801EE10_mid.h"
#include "code_8021774.h"
#include "code_8021774_pre.h"
#include "common_strings.h"
#include "debug_menu3.h"
#include "friend_area.h"
#include "memory.h"
#include "menu_input.h"
#include "pokemon.h"
#include "text1.h"
#include "text2.h"

static EWRAM_DATA_2 unkStruct_203B3F4 *sUnknown_203B3F4 = {0};

static const UnkTextStruct2 sUnknown_80E7E8C =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    NULL
};
static const UnkTextStruct2 sUnknown_80E7EA4 =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x15, 0x04,
    0x06, 0x03,
    0x03, 0x00,
    NULL
};

ALIGNED(4) static const u8 sClose[] = "CLOSE";
ALIGNED(4) static const u8 sOpen[] = "OPEN";
ALIGNED(4) static const u8 sFill[] = "pksdir0";

void sub_803A924(u32);
void sub_803A93C(void);
void sub_803A9AC(void);
void sub_803AA34(void);
void sub_803AAC4(void);
void sub_803AB34(void);
void sub_803ABAC(void);
bool8 sub_803ABC8(void);

// Unused
u32 sub_803A888(void)
{
    ResetUnusedInputStruct();
    sub_800641C(NULL, TRUE, TRUE);
    sUnknown_203B3F4 = MemoryAlloc(sizeof(unkStruct_203B3F4), 8);
    sub_803A924(0);
    return 1;
}

// Unused
u32 sub_803A8B8(void)
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

// Unused
void sub_803A908(void)
{
    if (sUnknown_203B3F4 != NULL) {
        MemoryFree(sUnknown_203B3F4);
        sUnknown_203B3F4 = NULL;
    }
}

void sub_803A924(u32 newState)
{
    sUnknown_203B3F4->state = newState;
    sub_803A93C();
    sub_803A9AC();
}

void sub_803A93C(void)
{
    s32 i;

    sub_8006518(sUnknown_203B3F4->unk9C);

    if (sUnknown_203B3F4->state == 2)
        sUnknown_203B3F4->unk9C[2] = sUnknown_80E7EA4;
    else {
        for(i = 0; i < 4; i++)
            sUnknown_203B3F4->unk9C[i] = sUnknown_80E7E8C;
    }

    ResetUnusedInputStruct();
    sub_800641C(sUnknown_203B3F4->unk9C, TRUE, TRUE);
}

void sub_803A9AC(void)
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
            sub_8021774(sUnknown_203B3F4->friendArea, 1, 0);
            break;
        case 4:
            break;
    }
}

void sub_803AA34(void)
{
    s32 index;
    u8 *FriendAreas;

    index = 0;

    // So dumb that it matches...
    FriendAreas = gFriendAreas;

    if (FriendAreas[sUnknown_203B3F4->friendArea]) {
        sUnknown_203B3F4->menuItems[0].text = sClose;

        if (sub_803ABC8())
            sUnknown_203B3F4->menuItems[0].menuAction = 3;
        else
            sUnknown_203B3F4->menuItems[0].menuAction = -1;
    }
    else {
        sUnknown_203B3F4->menuItems[0].text = sOpen;
        sUnknown_203B3F4->menuItems[0].menuAction = 2;
    }

    index++;
    sUnknown_203B3F4->menuItems[index].text = *gCommonInfo;
    sUnknown_203B3F4->menuItems[index].menuAction = 4;

    index++;
    sUnknown_203B3F4->menuItems[index].text = NULL;
    sUnknown_203B3F4->menuItems[index].menuAction = 1;

    sUnknown_203B3F4->menuAction = sUnknown_203B3F4->menuItems[0].menuAction;
}

void sub_803AAC4(void)
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

void sub_803AB34(void)
{
    s32 menuAction;

    menuAction = 0;

    sub_8021274(0);

    if (!sub_8012FD8(&sUnknown_203B3F4->unk4C))
        sub_8013114(&sUnknown_203B3F4->unk4C, &menuAction);

    switch (menuAction) {
        case 2:
            UnlockFriendArea(sUnknown_203B3F4->friendArea);
            sub_803A924(1);
            break;
        case 3:
            sub_809249C(sUnknown_203B3F4->friendArea, 1);
            sub_803A924(1);
            break;
        case 4:
            sub_803A924(3);
            break;
        case 1:
            sub_803A924(1);
            break;
    }
}

void sub_803ABAC(void)
{
    switch (sub_80217EC()) {
        case 2:
        case 3:
            sub_8021830();
            sub_803A924(1);
            break;
        case 0:
        case 1:
            break;
    }
}

bool8 sub_803ABC8(void)
{
    PokemonStruct1 *mon;
    s32 i;
    s32 mask;
    
    for (i = 0, mask = 1; i < NUM_MONSTERS; i++) {
        // Some check was optimized out. Needed for matching. Thanks kaz
        if (i) {
            u8 unk = -unk;
        }

        mon = &gRecruitedPokemonRef->pokemon[i];

        if ((mask & mon->unk0) != 0
            && ((mon->unk0 >> 1) & mask) != 0
            && sUnknown_203B3F4->friendArea == GetFriendArea(mon->speciesNum))
            return FALSE;

    }
    return TRUE;
}