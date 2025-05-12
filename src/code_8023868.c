#include "global.h"
#include "globaldata.h"
#include "code_800D090.h"
#include "code_8023868.h"
#include "code_80118A4.h"
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

extern const u8 sUnknown_80DC988[];
extern const u8 sUnknown_80DC980[];
extern const u8 sUnknown_80DC998[];

extern bool8 sub_808D750(s32 index_);

//static // MAKE STATIC WHEN code_8023868.s IS DONE
IWRAM_INIT struct unkStruct_3001B60 *gUnknown_3001B60 = {NULL};

#include "data/code_8023868.h"

static void SortbyAlphabetNo(s32, s32);
static void SortbyInternalNo(s32, s32);
static void SortbyName(s32, s32);
s32 sub_8023BD8(void);
bool8 sub_8024184(PokemonStruct1 *pokemon, u8 area);
void sub_80241A8(void);
void sub_8023CF4(void);
void sub_8023DA4(void);
s32 sub_8023F8C(void);
bool8 sub_8024108(s32 param_1);

extern s32 gUnknown_203B2A0;
extern s32 gUnknown_203B2A4;
extern u16 gUnknown_203B2A8;
extern u16 gUnknown_203B2AA;

// THE REMAINING CODE FROM THIS FILE IS IN code_8023868.s STARTING WITH sub_8023868

bool8 sub_8023868(u32 r5, u32 windowId, DungeonPos *pos, u32 r10)
{
    if (sub_8024108(r5)) {
        return FALSE;
    }

    if (gUnknown_3001B60 == NULL) {
        gUnknown_3001B60 = MemoryAlloc(sizeof(*gUnknown_3001B60), 8);
    }

    gUnknown_3001B60->unk0 = r5;
    if (gUnknown_203B2A0 != r5) {
        gUnknown_3001B60->sortMethod = 1;
    }
    else {
        gUnknown_3001B60->sortMethod = gUnknown_203B2A4;
    }

    gUnknown_3001B60->unk14 = 0;
    gUnknown_3001B60->unk15 = 0;
    gUnknown_3001B60->unk16 = 0;
    gUnknown_3001B60->unk17 = 0;
    gUnknown_3001B60->unk18 = 0;
    switch (gUnknown_3001B60->unk0) {
        case 0:
            break;
        case 1:
            gUnknown_3001B60->unk18 = 1;
            break;
        case 2:
            gUnknown_3001B60->unk14 = 1;
            break;
        case 3:
            gUnknown_3001B60->unk17 = 1;
            gUnknown_3001B60->unk15 = 1;
            gUnknown_3001B60->unk16 = 1;
            break;
        case 4:
            gUnknown_3001B60->unk18 = 1;
            gUnknown_3001B60->unk15 = 1;
            if (!sub_80023E4(9)) {
                gUnknown_3001B60->unk16 = 1;
            }
            break;
    }

    if (gUnknown_3001B60->unk0 == 4) {
        gUnknown_3001B60->unk354 = sub_8002658(sub_80A5728());
    }
    else {
        gUnknown_3001B60->unk354 = 0;
    }

    gUnknown_3001B60->unk358.s0.winId = windowId;
    gUnknown_3001B60->unk358.s0.unk38 = &gUnknown_3001B60->unk358.s0.windows.id[windowId];
    RestoreSavedWindows(&gUnknown_3001B60->unk358.s0.windows);
    gUnknown_3001B60->unk358.s0.windows.id[gUnknown_3001B60->unk358.s0.winId] = sUnknown_80DC968;
    gUnknown_3001B60->unk358.s0.unk38->header = &gUnknown_3001B60->unk358.header;
    if (pos != NULL) {
        gUnknown_3001B60->unk358.s0.windows.id[gUnknown_3001B60->unk358.s0.winId].pos = *pos;
    }
    sub_8012D08(gUnknown_3001B60->unk358.s0.unk38, r10);
    ResetUnusedInputStruct();
    ShowWindows(&gUnknown_3001B60->unk358.s0.windows, TRUE, TRUE);
    sub_8013818(&gUnknown_3001B60->unk358.s0.input, sub_8023F8C(), r10, windowId);
    if (gUnknown_203B2A0 == gUnknown_3001B60->unk0) {
        gUnknown_3001B60->unk358.s0.input.menuIndex = gUnknown_203B2A8;
        gUnknown_3001B60->unk358.s0.input.unk1E = gUnknown_203B2AA;
        sub_8013984(&gUnknown_3001B60->unk358.s0.input);
    }
    sub_8023CF4();
    sub_8023DA4();
    return TRUE;
}

u32 sub_8023A94(bool8 a0)
{
    if (!a0) {
        sub_8013660(&gUnknown_3001B60->unk358.s0.input);
        return 0;
    }

    switch (GetKeyPress(&gUnknown_3001B60->unk358.s0.input)) {
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
            gUnknown_3001B60->sortMethod = (gUnknown_3001B60->sortMethod < 3) ? gUnknown_3001B60->sortMethod + 1 : 1;
            sub_8023F8C();
            sub_8023CF4();
            sub_8023DA4();
            return 1;
        default:
            if (sub_80138B8(&gUnknown_3001B60->unk358.s0.input, TRUE)) {
                sub_8023CF4();
                sub_8023DA4();
                return 1;
            }
            return 0;
    }
}

s32 sub_8023B44(void)
{
    return gUnknown_3001B60->unk1A[(gUnknown_3001B60->unk358.s0.input.unk1E * gUnknown_3001B60->unk358.s0.input.unk1C) + gUnknown_3001B60->unk358.s0.input.menuIndex];
}

void sub_8023B7C(bool8 addCursor)
{
    ResetUnusedInputStruct();
    ShowWindows(&gUnknown_3001B60->unk358.s0.windows, FALSE, FALSE);
    gUnknown_3001B60->unk358.s0.input.unk22 = sub_8023BD8();
    sub_8013984(&gUnknown_3001B60->unk358.s0.input);
    sub_8023CF4();
    sub_8023DA4();
    if (addCursor) {
        AddMenuCursorSprite(&gUnknown_3001B60->unk358.s0.input);
    }
}

s32 sub_8023BD8(void)
{
    s32 i, j;

    for (i = 0; i < gUnknown_3001B60->unk8; i++) {
        s32 id = gUnknown_3001B60->unk1A[i];
        if (!PokemonFlag1(&gRecruitedPokemonRef->pokemon[id])) {
            gUnknown_3001B60->unk8--;
            for (j = i; j < gUnknown_3001B60->unk8; j++) {
                gUnknown_3001B60->unk1A[j] = gUnknown_3001B60->unk1A[j + 1];
            }
        }
    }

    return gUnknown_3001B60->unk8;
}

void sub_8023C60(void)
{
    if (gUnknown_3001B60 != NULL) {
        gUnknown_203B2A0 = gUnknown_3001B60->unk0;
        gUnknown_203B2A4 = gUnknown_3001B60->sortMethod;
        gUnknown_203B2A8 = gUnknown_3001B60->unk358.s0.input.menuIndex;
        gUnknown_203B2AA = gUnknown_3001B60->unk358.s0.input.unk1E;
        gUnknown_3001B60->unk358.s0.windows.id[gUnknown_3001B60->unk358.s0.winId] = sUnknown_80DC950;
        ResetUnusedInputStruct();
        ShowWindows(&gUnknown_3001B60->unk358.s0.windows, TRUE, TRUE);
        MemoryFree(gUnknown_3001B60);
        gUnknown_3001B60 = NULL;
    }
}

struct unkStruct_3001B60 *sub_8023CE8(void)
{
    return gUnknown_3001B60;
}

void sub_8023CF4(void)
{
    gUnknown_3001B60->unk358.header.count = 1;
    gUnknown_3001B60->unk358.header.currId = 0;
    gUnknown_3001B60->unk358.header.f3 = 0;
    switch (gUnknown_3001B60->unk0) {
        case 2:
            gUnknown_3001B60->unk358.header.width = 12;
            break;
        case 4:
            gUnknown_3001B60->unk358.header.width = 12;
            break;
        default:
            gUnknown_3001B60->unk358.header.width = 12;
            break;
    }

    SUB_80095E4_CALL_2(gUnknown_3001B60->unk358.s0);
}

void sub_8023DA4(void)
{
    s32 i, x;
    u8 winTxtBuff[40];
    u8 nameTxtBuff[20];
    u8 txtBuff3[20];

    CallPrepareTextbox_8008C54(gUnknown_3001B60->unk358.s0.winId);
    sub_80073B8(gUnknown_3001B60->unk358.s0.winId);
    switch (gUnknown_3001B60->unk0) {
        case 2:
            sub_80920D8(winTxtBuff);
            PrintStringOnWindow(10, 0, winTxtBuff, gUnknown_3001B60->unk358.s0.winId, '\0');
            break;
        case 4:
            PrintStringOnWindow(10, 0, sUnknown_80DC980, gUnknown_3001B60->unk358.s0.winId, '\0');
            x = (gUnknown_3001B60->unk358.header.width * 8) + 4;
            sub_8012BC4(x, 0, gUnknown_3001B60->unk358.s0.input.unk1E + 1, 2, 7, gUnknown_3001B60->unk358.s0.winId);
            break;
        default:
            PrintStringOnWindow(10, 0, sUnknown_80DC988, gUnknown_3001B60->unk358.s0.winId, '\0');
            x = (gUnknown_3001B60->unk358.header.width * 8) + 4;
            sub_8012BC4(x, 0, gUnknown_3001B60->unk358.s0.input.unk1E + 1, 2, 7, gUnknown_3001B60->unk358.s0.winId);
            break;
    }

    for (i = 0; i < gUnknown_3001B60->unk358.s0.input.unk1A; i++) {
        s32 id = gUnknown_3001B60->unk1A[(gUnknown_3001B60->unk358.s0.input.unk1E * gUnknown_3001B60->unk358.s0.input.unk1C) + i];
        PokemonStruct1 *pokePtr = &gRecruitedPokemonRef->pokemon[id];
        s32 r6 = 7;

        if (PokemonFlag2(pokePtr)) {
            if (IsMonPartner(pokePtr)) {
                r6 = 6;
            }
            if (IsMonLeader(pokePtr)) {
                r6 = 6;
            }
            if (pokePtr->isTeamLeader) {
                r6 = 5;
            }
        }
        else if (gUnknown_3001B60->unk18) {
            if (sub_808D750(id)) {
                r6 = 4;
            }
            else {
                r6 = 2;
            }
        }

        if (gUnknown_3001B60->unk0 == 4) {
            sub_8024184(pokePtr, gUnknown_3001B60->unk354);
        }
        // Needed to match. agbcc moment
        else if (gUnknown_3001B60->unk0 == 2) {

        }

        sub_80922B4(nameTxtBuff, pokePtr->name, POKEMON_NAME_LENGTH);
        sub_808D930(txtBuff3, pokePtr->speciesNum);
        sprintfStatic(winTxtBuff, sUnknown_80DC998, r6, nameTxtBuff);
        PrintStringOnWindow(8, GetMenuEntryYCoord(&gUnknown_3001B60->unk358.s0.input, i), winTxtBuff, gUnknown_3001B60->unk358.s0.winId, '\0');
    }
    sub_80073E0(gUnknown_3001B60->unk358.s0.winId);
}

s32 sub_8023F8C(void)
{
    s32 i;
    PokemonStruct1 *pokeStruct;

    gUnknown_3001B60->unk8 = 0;
    if (!gUnknown_3001B60->unk15) {
        for (i = 0; i < NUM_MONSTERS; i++) {
            pokeStruct = &gRecruitedPokemonRef->pokemon[i];
            if (pokeStruct->isTeamLeader && PokemonFlag1(pokeStruct)) {
                gUnknown_3001B60->unk1A[gUnknown_3001B60->unk8++] = i;
                break;
            }
        }
    }

    if (!gUnknown_3001B60->unk16) {
        for (i = 0; i < NUM_MONSTERS; i++) {
            pokeStruct = &gRecruitedPokemonRef->pokemon[i];
            if (IsMonPartner(pokeStruct) && !pokeStruct->isTeamLeader && PokemonFlag2(pokeStruct) && PokemonFlag1(pokeStruct)) {
                gUnknown_3001B60->unk1A[gUnknown_3001B60->unk8++] = i;
                break;
            }
        }
    }
    gUnknown_3001B60->unkC = gUnknown_3001B60->unk8;

    if (!gUnknown_3001B60->unk17) {
        for (i = 0; i < NUM_MONSTERS; i++) {
            pokeStruct = &gRecruitedPokemonRef->pokemon[i];
            if (PokemonFlag2(pokeStruct) && PokemonFlag1(pokeStruct) && !pokeStruct->isTeamLeader && !IsMonPartner(pokeStruct)) {
                gUnknown_3001B60->unk1A[gUnknown_3001B60->unk8++] = i;
                if (gUnknown_3001B60->unk8 >= 4) {
                    break;
                }
            }
        }
    }
    gUnknown_3001B60->unk10 = gUnknown_3001B60->unk8;

    if (!gUnknown_3001B60->unk14) {
        for (i = 0; i < NUM_MONSTERS; i++) {
            pokeStruct = &gRecruitedPokemonRef->pokemon[i];
            if (PokemonFlag1(pokeStruct) && !PokemonFlag2(&gRecruitedPokemonRef->pokemon[i])) {
                gUnknown_3001B60->unk1A[gUnknown_3001B60->unk8++] = i;
            }
        }
    }

    sub_80241A8();
    return gUnknown_3001B60->unk8;
}

bool8 sub_8024108(s32 param_1)
{
    s32 i;

    for (i = 0; i < NUM_MONSTERS; i++) {
        PokemonStruct1 *pokeStruct = &gRecruitedPokemonRef->pokemon[i];
        if (PokemonFlag1(pokeStruct)) {
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

//static // MAKE STATIC WHEN code_8023868.s IS DONE
bool8 sub_8024184(PokemonStruct1 *pokemon, u8 area)
{
    if (area == GetFriendArea(pokemon->speciesNum))
        return TRUE;
    return FALSE;
}

//static // MAKE STATIC WHEN code_8023868.s IS DONE
void sub_80241A8(void)
{
    switch (gUnknown_3001B60->sortMethod) {
        case 2:
            if (gUnknown_3001B60->unkC != gUnknown_3001B60->unk10)
                SortbyAlphabetNo(gUnknown_3001B60->unkC, gUnknown_3001B60->unk10);

            if (gUnknown_3001B60->unk10 != gUnknown_3001B60->unk8)
                SortbyAlphabetNo(gUnknown_3001B60->unk10, gUnknown_3001B60->unk8);
            break;
        case 3:
            if (gUnknown_3001B60->unkC != gUnknown_3001B60->unk10)
                SortbyName(gUnknown_3001B60->unkC, gUnknown_3001B60->unk10);

            if (gUnknown_3001B60->unk10 != gUnknown_3001B60->unk8)
                SortbyName(gUnknown_3001B60->unk10, gUnknown_3001B60->unk8);
            break;
        case 1:
            if (gUnknown_3001B60->unkC != gUnknown_3001B60->unk10)
                SortbyInternalNo(gUnknown_3001B60->unkC, gUnknown_3001B60->unk10);

            if (gUnknown_3001B60->unk10 != gUnknown_3001B60->unk8)
                SortbyInternalNo(gUnknown_3001B60->unk10, gUnknown_3001B60->unk8);
            break;
    }
}

static void SortbyInternalNo(s32 startId, s32 arrId)
{
    s32 temp;
    s32 i, j;
    s16 *arrPtr = &gUnknown_3001B60->unk1A[arrId - 1];

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
    s16 *arrPtr = &gUnknown_3001B60->unk1A[arrId - 1];

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
    s16 *arrPtr = &gUnknown_3001B60->unk1A[arrId - 1];

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

UNUSED static PokemonStruct1 *sub_80243E8(void)
{
    u8 buffer[40];
    u8 nameBuffer[20];
    PokemonStruct1 *pokeStruct = &gRecruitedPokemonRef->pokemon[gUnknown_3001B60->unk1A[(gUnknown_3001B60->unk358.s0.input.unk1E * gUnknown_3001B60->unk358.s0.input.unk1C) + gUnknown_3001B60->unk358.s0.input.menuIndex]];

    sub_80922B4(nameBuffer, pokeStruct->name, POKEMON_NAME_LENGTH);
    sprintfStatic(buffer, sUnknown_80DC9A4, nameBuffer);
    return pokeStruct;
}
