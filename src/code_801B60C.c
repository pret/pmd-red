#include "global.h"
#include "globaldata.h"
#include "constants/colors.h"
#include "music_util.h"
#include "code_801B3C0.h"
#include "code_801B60C.h"
#include "code_8099360.h"
#include "common_strings.h"
#include "event_flag.h"
#include "input.h"
#include "items.h"
#include "kecleon_bros4.h"
#include "memory.h"
#include "menu_input.h"
#include "pokemon.h"
#include "string_format.h"
#include "text_1.h"

static EWRAM_INIT unkStruct_203B234 *sUnknown_203B234 = { NULL };

#include "data/code_801B60C.h" // 80DBA58

static void sub_801B748(u32);
static void sub_801B760(void);
static void sub_801B874(void);
static void sub_801BB20(void);
static void sub_801BB5C(void);
static void sub_801BC24(void);
static void sub_801BC64(void);
static void sub_801BC94(void);
static void sub_801BCCC(void);
static void sub_801BD80(void);
static void sub_801BE30(void);
static void sub_801BEAC(void);
static void sub_801BEC8(void);

bool8 sub_801B60C(u32 r0, u8 id, u8 quantity)
{
    sUnknown_203B234 = MemoryAlloc(sizeof(unkStruct_203B234), 8);
    sUnknown_203B234->menuAction = 0;
    sUnknown_203B234->unk0 = r0;
    sUnknown_203B234->unk10.id = id;

    if (IsThrowableItem(sUnknown_203B234->unk10.id)) {
        sUnknown_203B234->unk10.quantity = quantity;
        sUnknown_203B234->unkC = quantity;
    }
    else {
        sUnknown_203B234->unk10.quantity = 0;
        sUnknown_203B234->unkC = 1;
    }

    sUnknown_203B234->unk10.flags = ITEM_FLAG_EXISTS;
    sUnknown_203B234->unk14.unk0 = 0;
    sUnknown_203B234->unk14.unk4 = 0;
    sUnknown_203B234->unk14.unk8 = 1;
    PrintColoredPokeNameToBuffer(gFormatBuffer_Monsters[0], GetPlayerPokemonStruct(), COLOR_YELLOW);
    sub_8090E14(gFormatBuffer_Items[0], &sUnknown_203B234->unk10, &sUnknown_203B234->unk14);
    sub_801B748(0);
    return TRUE;
}

u32 sub_801B6AC(void)
{
    switch (sUnknown_203B234->state) {
        case 16:
            return 3;
        case 6:
            sub_801BC64();
            break;
        case 7:
            sub_801BC94();
            break;
        case 8:
        case 9:
            sub_801BCCC();
            break;
        case 10:
            sub_801BD80();
            break;
        case 11:
            sub_801BEAC();
            break;
        case 12:
            sub_801BE30();
            break;
        case 13:
        case 14:
        case 15:
        default:
            sub_801BEC8();
            break;
    }

    return 0;
}

void sub_801B72C(void)
{
    if (sUnknown_203B234 != NULL) {
        MemoryFree(sUnknown_203B234);
        sUnknown_203B234 = NULL;
    }
}

static void sub_801B748(u32 newState)
{
   sUnknown_203B234->state = newState;
   sub_801B760();
   sub_801B874();
}

static void sub_801B760(void)
{
    s32 i;

    switch (sUnknown_203B234->state) {
       case 1:
       case 6:
       case 7:
       case 8:
       case 9:
       case 11:
       case 13:
       case 14:
       case 15:
            RestoreSavedWindows(&sUnknown_203B234->windows);
            for (i = 0; i < 4; i++)
                sUnknown_203B234->windows.id[i] = sUnknown_80DBA58;

            ResetUnusedInputStruct();
            ShowWindows(&sUnknown_203B234->windows, TRUE, TRUE);
            break;
        case 10:
            RestoreSavedWindows(&sUnknown_203B234->windows);
            sub_801BB5C();
            sUnknown_203B234->windows.id[2] = sUnknown_80DBA70;
            sub_8012CAC(&sUnknown_203B234->windows.id[2], sUnknown_203B234->unkCC);
            ResetUnusedInputStruct();
            ShowWindows(&sUnknown_203B234->windows, TRUE, TRUE);
            break;
        case 12:
            RestoreSavedWindows(&sUnknown_203B234->windows);
            sUnknown_203B234->windows.id[1] = sUnknown_80DBA88;
            ResetUnusedInputStruct();
            ShowWindows(&sUnknown_203B234->windows, TRUE, TRUE);
            break;
    }
}

static void sub_801B874(void)
{
    switch (sUnknown_203B234->state) {
        case 0:
            if (sUnknown_203B234->unk10.id == ITEM_WEAVILE_FIG) {
                sUnknown_203B234->fallbackState = 16;

                if (GetScriptVarArrayValue(NULL, EVENT_B01P01, 1)) {
                    AddToTeamMoney(1000);
                    sub_801B748(4);
                }
                else {
                    SetScriptVarArrayValue(NULL, EVENT_B01P01, 1, 1);
                    sub_801B748(3);
                }
            }
            else if (sUnknown_203B234->unk10.id == ITEM_MIME_JR_FIG) {
                sUnknown_203B234->fallbackState = 16;

                if (GetScriptVarArrayValue(NULL, EVENT_B01P01, 0)) {
                    AddToTeamMoney(1000);
                    sub_801B748(4);
                }
                else {
                    SetScriptVarArrayValue(NULL, EVENT_B01P01, 0, 1);
                    sub_801B748(3);
                }
            }
            else {
                if (GetNumberOfFilledInventorySlots() >= INVENTORY_SIZE) {
                    if (IsNotMoneyOrUsedTMItem(sUnknown_203B234->unk10.id)) {
                        if (gTeamInventoryRef->teamStorage[sUnknown_203B234->unk10.id] + sUnknown_203B234->unkC > 999) {
store:
                            sUnknown_203B234->fallbackState = 6;
                        }
                        else {
                            gTeamInventoryRef->teamStorage[sUnknown_203B234->unk10.id] += sUnknown_203B234->unkC;
                            PlaySound(203);
                            sUnknown_203B234->fallbackState = 5;
                        }
                    }
                    else
                        goto store;
                }
                else {
                    AddItemToInventory(&sUnknown_203B234->unk10);
                    FillInventoryGaps();
                    PlaySound(203);
                    sUnknown_203B234->fallbackState = 16;
                }

                if (sUnknown_203B234->unk0 == 1)
                    sub_801B748(2);
                else
                    sub_801B748(1);
            }
            break;
        case 1:
            if (GetUnitSum_808D544(0) < 2)
                CreateDialogueBoxAndPortrait(sFmtReceivedThePromised, 0, 0, 0x101);
            else
                CreateDialogueBoxAndPortrait(sFmtTeamReceivedThePromised, 0, 0, 0x101);
            break;
        case 2:
            CreateDialogueBoxAndPortrait(sFmtTeamAlsoReceived, 0, 0, 0x101);
            break;
        case 3:
            PlaySound(212);
            CreateDialogueBoxAndPortrait(sFmtReceivedStatue, 0, 0, 0x101);
            break;
        case 4:
            CreateDialogueBoxAndPortrait(sFmtReceive1000Instead, 0, 0, 0x101);
            break;
        case 5:
            sUnknown_203B234->fallbackState = 16;
            CreateDialogueBoxAndPortrait(sFmtFullSoSentToStorage, 0, 0, 0x101);
            break;
        case 6:
            sub_801BB20();
            CreateMenuDialogueBoxAndPortrait(sFmtFullSoPrompt, 0, 4, sUnknown_203B234->unkCC, 0, 4, 0, 0, 0);
            break;
        case 7:
            sub_801BC24();
            CreateMenuDialogueBoxAndPortrait(sFmtConfirmThrowAway, 0, 3, sUnknown_203B234->unkCC, 0, 4, 0, 0, 0);
            break;
        case 8:
            sub_801A5D8(1, 3, NULL, 10);
            break;
        case 9:
            sub_801A8D0(TRUE);
            break;
        case 10:
            sub_801A9E0();
            sub_8012D60(&sUnknown_203B234->unk28, sUnknown_203B234->unkCC, 0, 0, sUnknown_203B234->menuAction, 2);
            break;
        case 11:
            InitItemDescriptionWindow(&sUnknown_203B234->unk20);
            break;
        case 12:
            sub_801A9E0();
            sub_8012EA4(&sUnknown_203B234->unk28, 0);
            sub_801BC24();
            sub_8012D60(&sUnknown_203B234->unk78, sUnknown_203B234->unkCC, 0, 0, 3, 1);
            break;
        case 13:
            sUnknown_203B234->fallbackState = 16;
            CreateDialogueBoxAndPortrait(sFmtThrownAway, 0, 0, 0x101);
            break;
        case 14:
            sUnknown_203B234->fallbackState = 16;
            CreateDialogueBoxAndPortrait(sFmtPutInStorageForReceive, 0, 0, 0x101);
            break;
        case 15:
            sUnknown_203B234->fallbackState = 16;
            CreateDialogueBoxAndPortrait(sFmtDiscardedForReceive, 0, 0, 0x101);
            break;
        case 16:
            break;
    }
}

static void sub_801BB20(void)
{
    s32 loopMax;

    loopMax = 0;
    sUnknown_203B234->unkCC[loopMax].text = sTrashToolboxItem;
    sUnknown_203B234->unkCC[loopMax].menuAction = 4;

    loopMax++;
    sUnknown_203B234->unkCC[loopMax].text = sTrashReceivedItem;
    sUnknown_203B234->unkCC[loopMax].menuAction = 5;

    loopMax++;
    sUnknown_203B234->unkCC[loopMax].text = NULL;
    sUnknown_203B234->unkCC[loopMax].menuAction = -1;
}

static void sub_801BB5C(void)
{
    s32 i;
    s32 loopMax = 0;

    sUnknown_203B234->unkCC[loopMax].text = sStorage;
    sUnknown_203B234->unkCC[loopMax].menuAction = 6;
    if (!sub_801ADA0(sUnknown_203B234->unk24))
        sUnknown_203B234->unkCC[loopMax].menuAction = -1;


    loopMax++;
    sUnknown_203B234->unkCC[loopMax].text = sTrash;
    sUnknown_203B234->unkCC[loopMax].menuAction = 7;

    loopMax++;
    sUnknown_203B234->unkCC[loopMax].text = gCommonInfo[0];
    sUnknown_203B234->unkCC[loopMax].menuAction = 8;

    loopMax++;
    sUnknown_203B234->unkCC[loopMax].text = 0;
    sUnknown_203B234->unkCC[loopMax].menuAction = 1;

    for (i = 0; i < loopMax; i++) {
        if (sUnknown_203B234->unkCC[i].menuAction != -1)
            if (sUnknown_203B234->unkCC[i].menuAction == sUnknown_203B234->menuAction)
                return;
    }

    for (i = 0; i < loopMax; i++) {
        if (sUnknown_203B234->unkCC[i].menuAction != -1) {
            sUnknown_203B234->menuAction = sUnknown_203B234->unkCC[i].menuAction;
            break;
        }
    }
}

static void sub_801BC24(void)
{
    s32 loopMax;

    loopMax = 0;
    sUnknown_203B234->unkCC[loopMax].text = gCommonYes[0];
    sUnknown_203B234->unkCC[loopMax].menuAction = 2;

    loopMax++;
    sUnknown_203B234->unkCC[loopMax].text = gCommonNo[0];
    sUnknown_203B234->unkCC[loopMax].menuAction = 3;

    loopMax++;
    sUnknown_203B234->unkCC[loopMax].text = NULL;
    sUnknown_203B234->unkCC[loopMax].menuAction = 1;
}

static void sub_801BC64(void)
{
    s32 temp;

    if (sub_80144A4(&temp))
        return;

    switch (temp) {
        case 4:
            sub_801B748(8);
            break;
        case 5:
            sub_801B748(7);
            break;
    }
}

static void sub_801BC94(void)
{
    s32 temp;

    if (sub_80144A4(&temp))
        return;

    switch (temp) {
        case 2:
            sub_801B748(13);
            break;
        case 1:
        case 3:
            sub_801B748(6);
            break;
    }
}

static void sub_801BCCC(void)
{
    switch (sub_801A6E8(TRUE)) {
        case 0:
        case 1:
            break;
        case 3:
            sUnknown_203B234->unk24 = sub_801A8AC();
            sUnknown_203B234->unk20 = gTeamInventoryRef->teamItems[sUnknown_203B234->unk24];
            sub_8090E14(gFormatBuffer_Items[1], &sUnknown_203B234->unk20, &sUnknown_203B234->unk14);
            sub_801B748(10);
            break;
        case 4:
            sUnknown_203B234->unk24 = sub_801A8AC();
            sUnknown_203B234->unk20 = gTeamInventoryRef->teamItems[sUnknown_203B234->unk24];
            sub_8090E14(gFormatBuffer_Items[1], &sUnknown_203B234->unk20, &sUnknown_203B234->unk14);
            sub_8099690(0);
            sub_801B748(11);
            break;
        case 2:
            sub_801A928();
            sub_801B748(6);
            break;
    }
}

static void sub_801BD80(void)
{
    s32 menuAction;

    menuAction = 0;
    sub_801A6E8(FALSE);
    if (!sub_8012FD8(&sUnknown_203B234->unk28)) {
        sub_8013114(&sUnknown_203B234->unk28, &menuAction);

        if (menuAction != 1)
            sUnknown_203B234->menuAction = menuAction;
    }

    switch (menuAction) {
        case 6:
            MoveToStorage(&sUnknown_203B234->unk20);
            ShiftItemsDownFrom(sUnknown_203B234->unk24);
            AddItemToInventory(&sUnknown_203B234->unk10);
            FillInventoryGaps();
            PlaySound(203);
            sub_8099690(0);
            sub_801A928();
            sub_801B748(14);
            break;
        case 7:
            sub_801B748(12);
            break;
        case 8:
            sub_8099690(0);
            sub_801B748(11);
            break;
        case 1:
            sub_801B748(9);
            break;
    }
}

static void sub_801BE30(void)
{
    s32 menuAction;

    menuAction = 0;
    sub_801A6E8(FALSE);
    sub_8012FD8(&sUnknown_203B234->unk28);

    if (!sub_8012FD8(&sUnknown_203B234->unk78))
        sub_8013114(&sUnknown_203B234->unk78,&menuAction);

    switch (menuAction) {
        case 1:
        case 3:
            sub_801B748(9);
            break;
        case 2:
            ShiftItemsDownFrom(sUnknown_203B234->unk24);
            AddItemToInventory(&sUnknown_203B234->unk10);
            FillInventoryGaps();
            PlaySound(203);
            sub_801A928();
            sub_801B748(15);
            break;
    }
}

static void sub_801BEAC(void)
{
    switch (sub_801B410()) {
        case 2:
        case 3:
            FreeItemDescriptionWindow();
            sub_801B748(9);
        case 0:
        case 1:
            break;
    }
}

static void sub_801BEC8(void)
{
    s32 temp;

    if (!sub_80144A4(&temp))
        sub_801B748(sUnknown_203B234->fallbackState);
}
