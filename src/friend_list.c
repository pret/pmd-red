#include "global.h"
#include "globaldata.h"
#include "friend_list.h"
#include "code_800D090.h"
#include "music_util.h"
#include "pokemon.h"
#include "structs/str_text.h"
#include "text_util.h"
#include "text_1.h"
#include "text_2.h"
#include "text_3.h"
#include "event_flag.h"
#include "menu_input.h"
#include "rescue_team_info.h"
#include "input.h"
#include "memory.h"
#include "ground_map_1.h"
#include "constants/input.h"

extern bool8 sub_808D750(s32 index_);

static IWRAM_INIT struct unkStruct_3001B60 *sFriendList = {NULL};

static void SortbyAlphabetNo(s32, s32);
static void SortbyInternalNo(s32, s32);
static void SortbyName(s32, s32);
static bool8 MonHasFriendArea(Pokemon *pokemon, u8 area);
static void SortNames(void);
static void SetUpWindowHeader(void);
static s32 sub_8023BD8(void);
static s32 sub_8023F8C(void);

extern s32 gUnknown_203B2A0;
extern s32 gUnknown_203B2A4;
extern u16 gUnknown_203B2A8;
extern u16 gUnknown_203B2AA;

static const WindowTemplate sDummyWinTemplate = WIN_TEMPLATE_DUMMY;

static const WindowTemplate sUnknown_80DC968 = {
    .unk0 = 0,
    .type = WINDOW_TYPE_WITH_HEADER,
    .pos = {2, 2},
    .width = 15,
    .height = 14,
    .unk10 = 14,
    .unk12 = 0,
    .header = NULL
};

bool8 FriendList_Init(u32 r5, u32 windowId, DungeonPos *pos, u32 r10)
{
    if (sub_8024108(r5)) {
        return FALSE;
    }

    if (sFriendList == NULL) {
        sFriendList = MemoryAlloc(sizeof(*sFriendList), 8);
    }

    sFriendList->unk0 = r5;
    if (gUnknown_203B2A0 != r5) {
        sFriendList->sortMethod = 1;
    }
    else {
        sFriendList->sortMethod = gUnknown_203B2A4;
    }

    sFriendList->unk14 = 0;
    sFriendList->unk15 = 0;
    sFriendList->unk16 = 0;
    sFriendList->unk17 = 0;
    sFriendList->unk18 = 0;
    switch (sFriendList->unk0) {
        case 0:
            break;
        case 1:
            sFriendList->unk18 = 1;
            break;
        case 2:
            sFriendList->unk14 = 1;
            break;
        case 3:
            sFriendList->unk17 = 1;
            sFriendList->unk15 = 1;
            sFriendList->unk16 = 1;
            break;
        case 4:
            sFriendList->unk18 = 1;
            sFriendList->unk15 = 1;
            if (!sub_80023E4(9)) {
                sFriendList->unk16 = 1;
            }
            break;
    }

    if (sFriendList->unk0 == 4) {
        sFriendList->unk354 = sub_8002658(sub_80A5728());
    }
    else {
        sFriendList->unk354 = 0;
    }

    sFriendList->unk358.m.menuWinId = windowId;
    sFriendList->unk358.m.menuWindow = &sFriendList->unk358.m.windows.id[windowId];
    RestoreSavedWindows(&sFriendList->unk358.m.windows);
    sFriendList->unk358.m.windows.id[sFriendList->unk358.m.menuWinId] = sUnknown_80DC968;
    sFriendList->unk358.m.menuWindow->header = &sFriendList->unk358.header;
    if (pos != NULL) {
        sFriendList->unk358.m.windows.id[sFriendList->unk358.m.menuWinId].pos = *pos;
    }
    sub_8012D08(sFriendList->unk358.m.menuWindow, r10);
    ResetUnusedInputStruct();
    ShowWindows(&sFriendList->unk358.m.windows, TRUE, TRUE);
    CreateMenuOnWindow(&sFriendList->unk358.m.input, sub_8023F8C(), r10, windowId);
    if (gUnknown_203B2A0 == sFriendList->unk0) {
        sFriendList->unk358.m.input.menuIndex = gUnknown_203B2A8;
        sFriendList->unk358.m.input.currPage = gUnknown_203B2AA;
        MenuUpdatePagesData(&sFriendList->unk358.m.input);
    }
    SetUpWindowHeader();
    FriendList_ShowWindow();
    return TRUE;
}

u32 FriendList_HandleInput(bool8 a0)
{
    if (!a0) {
        sub_8013660(&sFriendList->unk358.m.input);
        return 0;
    }

    switch (GetKeyPress(&sFriendList->unk358.m.input)) {
        case INPUT_B_BUTTON:
            PlayMenuSoundEffect(1);
            return 2;
        case INPUT_START_BUTTON:
            PlayMenuSoundEffect(4);
            return 4;
        case INPUT_A_BUTTON:
            PlayMenuSoundEffect(0);
            return 3;
        case INPUT_SELECT_BUTTON:
            PlayMenuSoundEffect(5);
            sFriendList->sortMethod = (sFriendList->sortMethod < 3) ? sFriendList->sortMethod + 1 : 1;
            sub_8023F8C();
            SetUpWindowHeader();
            FriendList_ShowWindow();
            return 1;
        default:
            if (MenuCursorUpdate(&sFriendList->unk358.m.input, TRUE)) {
                SetUpWindowHeader();
                FriendList_ShowWindow();
                return 1;
            }
            return 0;
    }
}

s32 FriendList_GetCurrId(void)
{
    return sFriendList->unk1A[GET_CURRENT_MENU_ENTRY(sFriendList->unk358.m.input)];
}

void sub_8023B7C(bool8 addCursor)
{
    ResetUnusedInputStruct();
    ShowWindows(&sFriendList->unk358.m.windows, FALSE, FALSE);
    sFriendList->unk358.m.input.totalEntriesCount = sub_8023BD8();
    MenuUpdatePagesData(&sFriendList->unk358.m.input);
    SetUpWindowHeader();
    FriendList_ShowWindow();
    if (addCursor) {
        AddMenuCursorSprite(&sFriendList->unk358.m.input);
    }
}

static s32 sub_8023BD8(void)
{
    s32 i, j;

    for (i = 0; i < sFriendList->unk8; i++) {
        s32 id = sFriendList->unk1A[i];
        if (!PokemonExists(&gRecruitedPokemonRef->pokemon[id])) {
            sFriendList->unk8--;
            for (j = i; j < sFriendList->unk8; j++) {
                sFriendList->unk1A[j] = sFriendList->unk1A[j + 1];
            }
        }
    }

    return sFriendList->unk8;
}

void FriendList_Free(void)
{
    if (sFriendList != NULL) {
        gUnknown_203B2A0 = sFriendList->unk0;
        gUnknown_203B2A4 = sFriendList->sortMethod;
        gUnknown_203B2A8 = sFriendList->unk358.m.input.menuIndex;
        gUnknown_203B2AA = sFriendList->unk358.m.input.currPage;
        sFriendList->unk358.m.windows.id[sFriendList->unk358.m.menuWinId] = sDummyWinTemplate;
        ResetUnusedInputStruct();
        ShowWindows(&sFriendList->unk358.m.windows, TRUE, TRUE);
        MemoryFree(sFriendList);
        sFriendList = NULL;
    }
}

struct unkStruct_3001B60 *FriendList_GetPtr(void)
{
    return sFriendList;
}

static void SetUpWindowHeader(void)
{
    sFriendList->unk358.header.count = 1;
    sFriendList->unk358.header.currId = 0;
    sFriendList->unk358.header.f3 = 0;
    switch (sFriendList->unk0) {
        case 2:
            sFriendList->unk358.header.width = 12;
            break;
        case 4:
            sFriendList->unk358.header.width = 12;
            break;
        default:
            sFriendList->unk358.header.width = 12;
            break;
    }

    UPDATE_MENU_WINDOW_HEIGHT_2(sFriendList->unk358.m);
}

void FriendList_ShowWindow(void)
{
    s32 i, x;
    u8 winTxtBuff[40];
    u8 nameTxtBuff[POKEMON_NAME_LENGTH * 2];
    u8 txtBuff3[20];

    CallPrepareTextbox_8008C54(sFriendList->unk358.m.menuWinId);
    sub_80073B8(sFriendList->unk358.m.menuWinId);
    switch (sFriendList->unk0) {
        case 2:
            sub_80920D8(winTxtBuff);
            PrintStringOnWindow(10, 0, winTxtBuff, sFriendList->unk358.m.menuWinId, '\0');
            break;
        case 4:
            PrintStringOnWindow(10, 0, "Friends", sFriendList->unk358.m.menuWinId, '\0');
            x = (sFriendList->unk358.header.width * 8) + 4;
            PrintNumOnWindow(x, 0, sFriendList->unk358.m.input.currPage + 1, 2, 7, sFriendList->unk358.m.menuWinId);
            break;
        default:
            PrintStringOnWindow(10, 0, _("Pokémon Friends"), sFriendList->unk358.m.menuWinId, '\0');
            x = (sFriendList->unk358.header.width * 8) + 4;
            PrintNumOnWindow(x, 0, sFriendList->unk358.m.input.currPage + 1, 2, 7, sFriendList->unk358.m.menuWinId);
            break;
    }

    for (i = 0; i < sFriendList->unk358.m.input.currPageEntries; i++) {
        s32 id = sFriendList->unk1A[(sFriendList->unk358.m.input.currPage * sFriendList->unk358.m.input.entriesPerPage) + i];
        Pokemon *pokePtr = &gRecruitedPokemonRef->pokemon[id];
        u8 color = 7;

        if (PokemonFlag2(pokePtr)) {
            if (IsMonPartner(pokePtr)) {
                color = 6;
            }
            if (IsMonLeader(pokePtr)) {
                color = 6;
            }
            if (pokePtr->isTeamLeader) {
                color = 5;
            }
        }
        else if (sFriendList->unk18) {
            if (sub_808D750(id)) {
                color = 4;
            }
            else {
                color = 2;
            }
        }

        // This code doesn't do anything, but it's needed to match.
        if (sFriendList->unk0 == 4 && MonHasFriendArea(pokePtr, sFriendList->unk354)) {
            ;
        }
        else if (sFriendList->unk0 == 2) {
            ;
        }

        StrncpyCustom(nameTxtBuff, pokePtr->name, POKEMON_NAME_LENGTH);
        sub_808D930(txtBuff3, pokePtr->speciesNum);
        sprintfStatic(winTxtBuff, _("{color}%c%s{reset}"), color, nameTxtBuff);
        PrintStringOnWindow(8, GetMenuEntryYCoord(&sFriendList->unk358.m.input, i), winTxtBuff, sFriendList->unk358.m.menuWinId, '\0');
    }
    sub_80073E0(sFriendList->unk358.m.menuWinId);
}

static s32 sub_8023F8C(void)
{
    s32 i;
    Pokemon *pokeStruct;

    sFriendList->unk8 = 0;
    if (!sFriendList->unk15) {
        for (i = 0; i < NUM_MONSTERS; i++) {
            pokeStruct = &gRecruitedPokemonRef->pokemon[i];
            if (pokeStruct->isTeamLeader && PokemonExists(pokeStruct)) {
                sFriendList->unk1A[sFriendList->unk8++] = i;
                break;
            }
        }
    }

    if (!sFriendList->unk16) {
        for (i = 0; i < NUM_MONSTERS; i++) {
            pokeStruct = &gRecruitedPokemonRef->pokemon[i];
            if (IsMonPartner(pokeStruct) && !pokeStruct->isTeamLeader && PokemonFlag2(pokeStruct) && PokemonExists(pokeStruct)) {
                sFriendList->unk1A[sFriendList->unk8++] = i;
                break;
            }
        }
    }
    sFriendList->unkC = sFriendList->unk8;

    if (!sFriendList->unk17) {
        for (i = 0; i < NUM_MONSTERS; i++) {
            pokeStruct = &gRecruitedPokemonRef->pokemon[i];
            if (PokemonFlag2(pokeStruct) && PokemonExists(pokeStruct) && !pokeStruct->isTeamLeader && !IsMonPartner(pokeStruct)) {
                sFriendList->unk1A[sFriendList->unk8++] = i;
                if (sFriendList->unk8 >= 4) {
                    break;
                }
            }
        }
    }
    sFriendList->unk10 = sFriendList->unk8;

    if (!sFriendList->unk14) {
        for (i = 0; i < NUM_MONSTERS; i++) {
            pokeStruct = &gRecruitedPokemonRef->pokemon[i];
            if (PokemonExists(pokeStruct) && !PokemonFlag2(&gRecruitedPokemonRef->pokemon[i])) {
                sFriendList->unk1A[sFriendList->unk8++] = i;
            }
        }
    }

    SortNames();
    return sFriendList->unk8;
}

bool8 sub_8024108(s32 param_1)
{
    s32 i;

    for (i = 0; i < NUM_MONSTERS; i++) {
        Pokemon *pokeStruct = &gRecruitedPokemonRef->pokemon[i];
        if (PokemonExists(pokeStruct)) {
            if (param_1 == 2) {
                if (!PokemonFlag2(pokeStruct)) continue;
            }
            else if (param_1 == 3) {
                if (PokemonFlag2(pokeStruct)) continue;
            }
            else if (param_1 == 4) {
                if (pokeStruct->isTeamLeader) continue;
                if (!sub_80023E4(9)) {
                    if (!IsMonPartner(pokeStruct)) return FALSE;
                    if (PokemonFlag2(pokeStruct)) continue;
                }
            }
            return FALSE;
        }
    }
    return TRUE;
}

static bool8 MonHasFriendArea(Pokemon *pokemon, u8 area)
{
    if (area == GetFriendArea(pokemon->speciesNum))
        return TRUE;
    return FALSE;
}

static void SortNames(void)
{
    switch (sFriendList->sortMethod) {
        case 2:
            if (sFriendList->unkC != sFriendList->unk10)
                SortbyAlphabetNo(sFriendList->unkC, sFriendList->unk10);

            if (sFriendList->unk10 != sFriendList->unk8)
                SortbyAlphabetNo(sFriendList->unk10, sFriendList->unk8);
            break;
        case 3:
            if (sFriendList->unkC != sFriendList->unk10)
                SortbyName(sFriendList->unkC, sFriendList->unk10);

            if (sFriendList->unk10 != sFriendList->unk8)
                SortbyName(sFriendList->unk10, sFriendList->unk8);
            break;
        case 1:
            if (sFriendList->unkC != sFriendList->unk10)
                SortbyInternalNo(sFriendList->unkC, sFriendList->unk10);

            if (sFriendList->unk10 != sFriendList->unk8)
                SortbyInternalNo(sFriendList->unk10, sFriendList->unk8);
            break;
    }
}

static void SortbyInternalNo(s32 startId, s32 arrId)
{
    s32 temp;
    s32 i, j;
    s16 *arrPtr = &sFriendList->unk1A[arrId - 1];

    for (i = startId; i < arrId - 1; i++) {
        s16 *curr = arrPtr;
        for (j = arrId - 1; j > i; j--) {
            if (GetInternalNo(gRecruitedPokemonRef->pokemon[curr[-1]].speciesNum) > GetInternalNo(gRecruitedPokemonRef->pokemon[curr[0]].speciesNum)) {
                SWAP(curr[0], curr[-1], temp);
            }
            curr--;
        }
    }
}

static void SortbyAlphabetNo(s32 startId, s32 arrId)
{
    s32 temp;
    s32 i, j;
    s16 *arrPtr = &sFriendList->unk1A[arrId - 1];

    for (i = startId; i < arrId - 1; i++) {
        s16 *curr = arrPtr;
        for (j = arrId - 1; j > i; j--) {
            if (GetAlphabetParentNo(gRecruitedPokemonRef->pokemon[curr[-1]].speciesNum, 0) > GetAlphabetParentNo(gRecruitedPokemonRef->pokemon[curr[0]].speciesNum, 0)) {
                SWAP(curr[0], curr[-1], temp);
            }
            curr--;
        }
    }
}

static void SortbyName(s32 startId, s32 arrId)
{
    s32 temp;
    s32 i, j;
    s16 *arrPtr = &sFriendList->unk1A[arrId - 1];

    for (i = startId; i < arrId - 1; i++) {
        s16 * currPtr = arrPtr;
        for (j = arrId - 1; j > i; j--) {
            s16 *belowPtr = currPtr - 1;
            if (ComparePokemonNames(*belowPtr, *currPtr)) {
                SWAP(*currPtr, *belowPtr, temp);
            }
            currPtr--;
        }
    }
}

UNUSED static Pokemon *sub_80243E8(void)
{
    u8 buffer[40];
    u8 nameBuffer[20];
    Pokemon *pokeStruct = &gRecruitedPokemonRef->pokemon[sFriendList->unk1A[GET_CURRENT_MENU_ENTRY(sFriendList->unk358.m.input)]];

    StrncpyCustom(nameBuffer, pokeStruct->name, POKEMON_NAME_LENGTH);
    sprintfStatic(buffer, "%s", nameBuffer);
    return pokeStruct;
}
