#include "global.h"
#include "globaldata.h"
#include "code_801B3C0.h"
#include "code_801C8C4.h"
#include "code_8099360.h"
#include "common_strings.h"
#include "input.h"
#include "kangaskhan_storage1.h"
#include "kecleon_bros4.h"
#include "memory.h"
#include "menu_input.h"
#include "pokemon.h"
#include "string_format.h"
#include "text_1.h"
#include "text_2.h"

EWRAM_INIT struct KangaskhanStorageWork *gKangaskhanStorageWork = {NULL};

#include "data/kangaskhan_storage1.h" // 80DB748

static void AdvanceToKangaskhanStorageFallbackState(void);
static void UpdateKangaskhanStorageState(u32);

static void sub_8016E80(void);
static void sub_8016FF8(void);
static void sub_8017598(void);
static void BuildKangaskhanMainMenu(void);
static void sub_80176B8(void);
static void sub_8017758(void);
static void sub_80177F8(void);
static void HandleKangaskhanMainMenu(void);
static void sub_80178D0(void);
static void sub_8017928(void);
static void sub_80179A8(void);
static void sub_8017A1C(void);
static void sub_8017AF8(void);
static void sub_8017B88(void);
static void sub_8017C28(void);
static void sub_8017C7C(void);
static void sub_8017D24(void);
static void sub_8017DC0(void);
static void sub_8017DDC(void);

bool8 CreateKangaskhanStorage(u32 mode)
{
    u8 *monName;
    OpenedFile *faceFile;

    ResetUnusedInputStruct();
    ShowWindows(NULL, TRUE, TRUE);
    gKangaskhanStorageWork = MemoryAlloc(sizeof(struct KangaskhanStorageWork), 8);
    gKangaskhanStorageWork->menuAction1 = 0;
    gKangaskhanStorageWork->menuAction2 = 0;
    gKangaskhanStorageWork->menuAction3 = 0;
    gKangaskhanStorageWork->mode = mode;
    CopyYellowMonsterNametoBuffer(gSpeakerNameBuffer, MONSTER_KANGASKHAN);
    CopyYellowMonsterNametoBuffer(gFormatBuffer_Monsters[7], MONSTER_KANGASKHAN);
    monName = GetMonSpecies(MONSTER_KANGASKHAN);
    strcpy(gFormatBuffer_Monsters[6], monName);

    if (gKangaskhanStorageWork->mode == KANG_MODE_ASLEEP)
        gKangaskhanStorageWork->monPortraitPtr = NULL;
    else
        gKangaskhanStorageWork->monPortraitPtr = &gKangaskhanStorageWork->monPortrait;

    faceFile = GetDialogueSpriteDataPtr(MONSTER_KANGASKHAN);
    gKangaskhanStorageWork->monPortrait.faceFile = faceFile;
    gKangaskhanStorageWork->monPortrait.faceData = (PortraitGfx *) faceFile->data;
    gKangaskhanStorageWork->monPortrait.spriteId = FALSE;
    gKangaskhanStorageWork->monPortrait.flip = FALSE;
    gKangaskhanStorageWork->monPortrait.unkE = 0;
    gKangaskhanStorageWork->monPortrait.pos.x = 2;
    gKangaskhanStorageWork->monPortrait.pos.y = 8;
    UpdateKangaskhanStorageState(KANGASKHAN_STORAGE_INIT);
    return TRUE;
}

u32 KangaskhanStorageCallback(void)
{
    switch (gKangaskhanStorageWork->currState) {
        case KANGASKHAN_STORAGE_INIT:
        case KANGASKHAN_STORAGE_MAIN_MENU:
            HandleKangaskhanMainMenu();
            break;
        case 13:
        case 14:
            sub_8017AF8();
            break;
        case 15:
            sub_8017C7C();
            break;
        case 16:
            sub_8017DC0();
            break;
        case 17:
            sub_80178D0();
            break;
        case 18:
            sub_80179A8();
            break;
        case 22:
        case 23:
            sub_8017B88();
            break;
        case 24:
            sub_8017C28();
            break;
        case 25:
            sub_8017D24();
            break;
        case 26:
            sub_8017DDC();
            break;
        case 27:
            sub_8017928();
            break;
        case 28:
            sub_8017A1C();
            break;
        case KANGASKHAN_STORAGE_EXIT:
            return 3;
        default:
            AdvanceToKangaskhanStorageFallbackState();
            break;
    }
    return 0;
}

void DeleteKangaskhanStorage(void)
{
    if (gKangaskhanStorageWork != NULL) {
        CloseFile(gKangaskhanStorageWork->monPortrait.faceFile);
        FREE_AND_SET_NULL(gKangaskhanStorageWork);
    }
}

static void UpdateKangaskhanStorageState(u32 newState)
{
    gKangaskhanStorageWork->currState = newState;
    sub_8016E80();
    sub_8016FF8();
}

static void sub_8016E80(void)
{
    s32 index;

    RestoreSavedWindows(&gKangaskhanStorageWork->unkEC);

    switch (gKangaskhanStorageWork->currState) {
        case 13:
        case 14:
            gKangaskhanStorageWork->unkEC.id[0] = sUnknown_80DB748;
            gKangaskhanStorageWork->unkEC.id[1] = sUnknown_80DB748;
            gKangaskhanStorageWork->unkEC.id[2] = sUnknown_80DB748;
            gKangaskhanStorageWork->unkEC.id[0] = sUnknown_80DB748;
            break;
        case 22:
        case 23:
            gKangaskhanStorageWork->unkEC.id[0] = sUnknown_80DB748;
            gKangaskhanStorageWork->unkEC.id[1] = sUnknown_80DB748;
            gKangaskhanStorageWork->unkEC.id[2] = sUnknown_80DB748;
            gKangaskhanStorageWork->unkEC.id[0] = sUnknown_80DB778;
            break;
        case 24:
            gKangaskhanStorageWork->unkEC.id[1] = sUnknown_80DB790;
            break;
        case 15:
        case 25:
            gKangaskhanStorageWork->unkEC.id[2] = sUnknown_80DB760;
            break;
        default:
            for (index = 0; index < 4; index++)
                gKangaskhanStorageWork->unkEC.id[index] = sUnknown_80DB748;
            break;
    }

    ResetUnusedInputStruct();
    ShowWindows(&gKangaskhanStorageWork->unkEC, TRUE, TRUE);
}

static void sub_8016FF8(void)
{
    switch (gKangaskhanStorageWork->currState) {
        case KANGASKHAN_STORAGE_INIT:
            BuildKangaskhanMainMenu();
            gKangaskhanStorageWork->monPortrait.spriteId = TRUE;
            CreateMenuDialogueBoxAndPortrait(gCommonKangStorage[gKangaskhanStorageWork->mode][KANG_DLG_WELCOME], 0, gKangaskhanStorageWork->menuAction1, gKangaskhanStorageWork->unk24,
                                    gKangaskhanStorageWork->unk4C, 4, 0, gKangaskhanStorageWork->monPortraitPtr, 12);
            break;
        case KANGASKHAN_STORAGE_MAIN_MENU:
            BuildKangaskhanMainMenu();
            gKangaskhanStorageWork->monPortrait.spriteId = FALSE;
            CreateMenuDialogueBoxAndPortrait(gCommonKangStorage[gKangaskhanStorageWork->mode][KANG_DLG_ANYTHING_ELSE], 0, gKangaskhanStorageWork->menuAction1, gKangaskhanStorageWork->unk24,
                                    gKangaskhanStorageWork->unk4C, 4, 0, gKangaskhanStorageWork->monPortraitPtr, 12);
            break;
        case 2:
            gKangaskhanStorageWork->fallbackState = KANGASKHAN_STORAGE_MAIN_MENU;
            gKangaskhanStorageWork->monPortrait.spriteId = FALSE;
            CreateDialogueBoxAndPortrait(gCommonKangStorage[gKangaskhanStorageWork->mode][KANG_DLG_HOW_IT_WORKS], 0, gKangaskhanStorageWork->monPortraitPtr, 0x10D);
            break;
        case 3:
            gKangaskhanStorageWork->fallbackState = KANGASKHAN_STORAGE_EXIT;
            gKangaskhanStorageWork->monPortrait.spriteId = TRUE;
            CreateDialogueBoxAndPortrait(gCommonKangStorage[gKangaskhanStorageWork->mode][KANG_DLG_BYE], 0, gKangaskhanStorageWork->monPortraitPtr, 0x30D);
            break;
        case KANGASKHAN_STORAGE_NO_INV_ITEMS:
            gKangaskhanStorageWork->fallbackState = KANGASKHAN_STORAGE_MAIN_MENU;
            gKangaskhanStorageWork->monPortrait.spriteId = FALSE;
            CreateDialogueBoxAndPortrait(gCommonKangStorage[gKangaskhanStorageWork->mode][KANG_DLG_YOU_HAVE_NOTHING], 0, gKangaskhanStorageWork->monPortraitPtr, 0x10D);
            break;
        case KANGASKHAN_STORAGE_TOO_MANY_ITEMS:
            gKangaskhanStorageWork->fallbackState = KANGASKHAN_STORAGE_MAIN_MENU;
            gKangaskhanStorageWork->monPortrait.spriteId = FALSE;
            CreateDialogueBoxAndPortrait(gCommonKangStorage[gKangaskhanStorageWork->mode][KANG_DLG_YOU_ARE_FULL], 0, gKangaskhanStorageWork->monPortraitPtr, 0x10D);
            break;
        case 7:
            gKangaskhanStorageWork->fallbackState = KANGASKHAN_STORAGE_MAIN_MENU;
            gKangaskhanStorageWork->monPortrait.spriteId = FALSE;
            CreateDialogueBoxAndPortrait(gCommonKangStorage[gKangaskhanStorageWork->mode][KANG_DLG_STORAGE_EMPTY], 0, gKangaskhanStorageWork->monPortraitPtr, 0x10D);
            break;
        case 8:
            gKangaskhanStorageWork->fallbackState = KANGASKHAN_STORAGE_MAIN_MENU;
            gKangaskhanStorageWork->monPortrait.spriteId = FALSE;
            CreateDialogueBoxAndPortrait(gCommonKangStorage[gKangaskhanStorageWork->mode][KANG_DLG_STORAGE_FULL], 0, gKangaskhanStorageWork->monPortraitPtr, 0x10D);
            break;
        case KANGASKHAN_STORAGE_IS_MONEY_USED_TM:
            sub_8090E14(gFormatBuffer_Items[0], &gKangaskhanStorageWork->storedItem, 0);
            gKangaskhanStorageWork->fallbackState = 14;
            gKangaskhanStorageWork->monPortrait.spriteId = FALSE;
            CreateDialogueBoxAndPortrait(gCommonKangStorage[gKangaskhanStorageWork->mode][KANG_DLG_DEPOSIT_INVALID_ITEM], 0, gKangaskhanStorageWork->monPortraitPtr, 0x30D);
            break;
        case 10:
            gKangaskhanStorageWork->fallbackState = 14;
            gKangaskhanStorageWork->monPortrait.spriteId = FALSE;
            CreateDialogueBoxAndPortrait(gCommonKangStorage[gKangaskhanStorageWork->mode][KANG_DLG_DEPOSIT_TOO_MANY_OF_ITEM], 0, gKangaskhanStorageWork->monPortraitPtr, 0x30D);
            break;
        case 11:
            gKangaskhanStorageWork->fallbackState = 13;
            gKangaskhanStorageWork->monPortrait.spriteId = FALSE;
            CreateDialogueBoxAndPortrait(gCommonKangStorage[gKangaskhanStorageWork->mode][KANG_DLG_STORE_WHAT], 0, gKangaskhanStorageWork->monPortraitPtr, 0x30D);
            break;
        case 12:
            gKangaskhanStorageWork->fallbackState = 14;
            gKangaskhanStorageWork->monPortrait.spriteId = FALSE;
            CreateDialogueBoxAndPortrait(gCommonKangStorage[gKangaskhanStorageWork->mode][KANG_DLG_STORE_MORE], 0, gKangaskhanStorageWork->monPortraitPtr, 0x30D);
            break;
        case 13:
            sub_801A5D8(3, 3, NULL, 10);
            break;
        case 14:
            sub_801A8D0(TRUE);
            break;
        case 15:
            sub_801A9E0();
            sub_80176B8();
            sub_8012D60(&gKangaskhanStorageWork->unk58, gKangaskhanStorageWork->unk24, NULL, gKangaskhanStorageWork->unk4C, gKangaskhanStorageWork->menuAction2, 2);
            break;
        case 17:
            sub_80177F8();
            sub_8090E14(gFormatBuffer_Items[0], &gKangaskhanStorageWork->storedItem, 0);
            gKangaskhanStorageWork->monPortrait.spriteId = FALSE;
            CreateMenuDialogueBoxAndPortrait(gCommonKangStorage[gKangaskhanStorageWork->mode][KANG_DLG_DEPOSIT_ONE_PROMPT], 0, 4, gKangaskhanStorageWork->unk24, NULL, 4, 0,
                                    gKangaskhanStorageWork->monPortraitPtr, 12);
            break;
        case 18:
            sub_80177F8();
            gKangaskhanStorageWork->monPortrait.spriteId = FALSE;
            CreateMenuDialogueBoxAndPortrait(gCommonKangStorage[gKangaskhanStorageWork->mode][KANG_DLG_DEPOSIT_MANY_PROMPT], 0, 4, gKangaskhanStorageWork->unk24, NULL, 4, 0,
                                    gKangaskhanStorageWork->monPortraitPtr, 12);
            break;
        case 19:
            if (GetNumberOfFilledInventorySlots() == 0) {
                sub_801A928();
                gKangaskhanStorageWork->fallbackState = KANGASKHAN_STORAGE_MAIN_MENU;
            }
            else
                gKangaskhanStorageWork->fallbackState = 12;

            gKangaskhanStorageWork->monPortrait.spriteId = TRUE;
            CreateDialogueBoxAndPortrait(gCommonKangStorage[gKangaskhanStorageWork->mode][KANG_DLG_DEPOSIT_CONFIRMATION], 0, gKangaskhanStorageWork->monPortraitPtr, 0x10D);
            break;
        case 20:
            gKangaskhanStorageWork->fallbackState = 22;
            gKangaskhanStorageWork->monPortrait.spriteId = FALSE;
            CreateDialogueBoxAndPortrait(gCommonKangStorage[gKangaskhanStorageWork->mode][KANG_DLG_TAKE_WHAT], 0, gKangaskhanStorageWork->monPortraitPtr, 0x30D);
            break;
        case 21:
            gKangaskhanStorageWork->fallbackState = 23;
            gKangaskhanStorageWork->monPortrait.spriteId = FALSE;
            CreateDialogueBoxAndPortrait(gCommonKangStorage[gKangaskhanStorageWork->mode][KANG_DLG_TAKE_MORE], 0, gKangaskhanStorageWork->monPortraitPtr, 0x30D);
            break;
        case 22:
            sub_801C8C4(1, 3, 0, 10);
            sub_801AD34(0);
            break;
        case 23:
            sub_801CB5C(TRUE);
            sub_801AD34(0);
            break;
        case 24:
            gKangaskhanStorageWork->unkA8.unk10 = 2;
            gKangaskhanStorageWork->unkA8.unk8 = 1;

            if (gTeamInventoryRef->teamStorage[gKangaskhanStorageWork->storedItem.id] >= 100)
                gKangaskhanStorageWork->unkA8.unkC = 99;
            else
                gKangaskhanStorageWork->unkA8.unkC = gTeamInventoryRef->teamStorage[gKangaskhanStorageWork->storedItem.id];

            gKangaskhanStorageWork->unkA8.unk4 = gKangaskhanStorageWork->unkA8.unkC;
            gKangaskhanStorageWork->unkA8.unk14 = 1;
            gKangaskhanStorageWork->unkA8.unk18 = &gKangaskhanStorageWork->unkEC.id[1];
            gKangaskhanStorageWork->unkA8.unk1C = 40;
            gKangaskhanStorageWork->unkA8.unk20 = 18;
            sub_8013AA0(&gKangaskhanStorageWork->unkA8);
            sub_8017598();
            break;
        case 25:
            sub_801CCD8();
            sub_801AD34(0);
            sub_8017758();
            sub_8012D60(&gKangaskhanStorageWork->unk58, gKangaskhanStorageWork->unk24, NULL, gKangaskhanStorageWork->unk4C, gKangaskhanStorageWork->menuAction3, 2);
            break;
        case 16:
        case 26:
            InitItemDescriptionWindow(&gKangaskhanStorageWork->storedItem);
            break;
        case 27:
            sub_80177F8();
            sub_8090E14(gFormatBuffer_Items[0], &gKangaskhanStorageWork->storedItem, 0);
            gKangaskhanStorageWork->monPortrait.spriteId = FALSE;
            CreateMenuDialogueBoxAndPortrait(gCommonKangStorage[gKangaskhanStorageWork->mode][KANG_DLG_WITHDRAW_ONE_PROMPT], 0, 4, gKangaskhanStorageWork->unk24, NULL, 4, 0,
                                    gKangaskhanStorageWork->monPortraitPtr, 12);
            break;
        case 28:
            sub_80177F8();
            gKangaskhanStorageWork->monPortrait.spriteId = FALSE;
            CreateMenuDialogueBoxAndPortrait(gCommonKangStorage[gKangaskhanStorageWork->mode][KANG_DLG_WITHDRAW_MANY_PROMPT], 0, 4, gKangaskhanStorageWork->unk24, NULL, 4, 0,
                                    gKangaskhanStorageWork->monPortraitPtr, 12);
            break;
        case 29:
            if (sub_801CF14(1) || GetNumberOfFilledInventorySlots() >= INVENTORY_SIZE) {
                sub_801CBB8();
                gKangaskhanStorageWork->fallbackState = KANGASKHAN_STORAGE_MAIN_MENU;
            }
            else
                gKangaskhanStorageWork->fallbackState = 21;

            gKangaskhanStorageWork->monPortrait.spriteId = TRUE;
            CreateDialogueBoxAndPortrait(gCommonKangStorage[gKangaskhanStorageWork->mode][KANG_DLG_WITHDRAW_CONFIRMATION], 0, gKangaskhanStorageWork->monPortraitPtr, 0x10D);
            break;
    }
}

static void sub_8017598(void)
{
    CallPrepareTextbox_8008C54(gKangaskhanStorageWork->unkA8.unk14);
    sub_80073B8(gKangaskhanStorageWork->unkA8.unk14);
    PrintStringOnWindow(4, 0, sNumber, gKangaskhanStorageWork->unkA8.unk14, 0);
    sub_8013C68(&gKangaskhanStorageWork->unkA8);
    sub_80073E0(gKangaskhanStorageWork->unkA8.unk14);
    sub_801CCD8();
    sub_801AD34(0);
    sub_8012EA4(&gKangaskhanStorageWork->unk58, 0);
}

static void BuildKangaskhanMainMenu(void)
{
    s32 index;
    s32 loopMax;

    MemoryFill16(gKangaskhanStorageWork->unk4C,0, sizeof(gKangaskhanStorageWork->unk4C));
    loopMax = 0;
    gKangaskhanStorageWork->unk24[loopMax].text = gCommonStore[0];
    gKangaskhanStorageWork->unk24[loopMax].menuAction = MENU_STORE;

    loopMax += 1;
    gKangaskhanStorageWork->unk24[loopMax].text = gCommonTake[0];
    gKangaskhanStorageWork->unk24[loopMax].menuAction = MENU_TAKE;

    loopMax += 1;
    gKangaskhanStorageWork->unk24[loopMax].text = gCommonInfo[0];
    gKangaskhanStorageWork->unk24[loopMax].menuAction = MENU_INFO;

    loopMax += 1;
    gKangaskhanStorageWork->unk24[loopMax].text = gCommonCancel[0];
    gKangaskhanStorageWork->unk24[loopMax].menuAction = MENU_CANCEL;

    loopMax += 1;
    gKangaskhanStorageWork->unk24[loopMax].text = NULL;
    gKangaskhanStorageWork->unk24[loopMax].menuAction = MENU_CANCEL;

    for (index = 0; index < loopMax; index++) {
        if (gKangaskhanStorageWork->unk4C[index] == 0) {
            if (gKangaskhanStorageWork->unk24[index].menuAction == gKangaskhanStorageWork->menuAction1)
                return;
        }
    }

    for (index = 0; index < loopMax; index++) {
        if (gKangaskhanStorageWork->unk4C[index] == 0) {
            gKangaskhanStorageWork->menuAction1 = gKangaskhanStorageWork->unk24[index].menuAction;
            break;
        }
    }
}

static void sub_80176B8(void)
{
    s32 index;
    s32 loopMax;

    MemoryFill16(gKangaskhanStorageWork->unk4C, 0, sizeof(gKangaskhanStorageWork->unk4C));
    loopMax = 0;
    gKangaskhanStorageWork->unk24[loopMax].text = gCommonStore[0];
    gKangaskhanStorageWork->unk24[loopMax].menuAction = MENU_STORE;

    loopMax++;
    gKangaskhanStorageWork->unk24[loopMax].text = gCommonInfo[0];
    gKangaskhanStorageWork->unk24[loopMax].menuAction = MENU_INFO;

    loopMax++;
    gKangaskhanStorageWork->unk24[loopMax].text = NULL;
    gKangaskhanStorageWork->unk24[loopMax].menuAction = MENU_CANCEL;

    for (index = 0; index < loopMax; index++) {
        if (gKangaskhanStorageWork->unk4C[index] == 0) {
            if (gKangaskhanStorageWork->unk24[index].menuAction == gKangaskhanStorageWork->menuAction2)
                return;
        }
    }

    for (index = 0; index < loopMax; index++) {
        if (gKangaskhanStorageWork->unk4C[index] == 0) {
            gKangaskhanStorageWork->menuAction2 = gKangaskhanStorageWork->unk24[index].menuAction;
            break;
        }
    }
}

static void sub_8017758(void)
{
    s32 index;
    s32 loopMax;

    MemoryFill16(gKangaskhanStorageWork->unk4C, 0, sizeof(gKangaskhanStorageWork->unk4C));
    loopMax = 0;
    gKangaskhanStorageWork->unk24[loopMax].text = gCommonTake[0];
    gKangaskhanStorageWork->unk24[loopMax].menuAction = MENU_TAKE;

    loopMax++;
    gKangaskhanStorageWork->unk24[loopMax].text = gCommonInfo[0];
    gKangaskhanStorageWork->unk24[loopMax].menuAction = MENU_INFO;

    loopMax++;
    gKangaskhanStorageWork->unk24[loopMax].text = NULL;
    gKangaskhanStorageWork->unk24[loopMax].menuAction = MENU_CANCEL;

    for (index = 0; index < loopMax; index++) {
        if (gKangaskhanStorageWork->unk4C[index] == 0) {
            if (gKangaskhanStorageWork->unk24[index].menuAction == gKangaskhanStorageWork->menuAction3)
                return;
        }
    }

    for (index = 0; index < loopMax; index++) {
        if (gKangaskhanStorageWork->unk4C[index] == 0) {
            gKangaskhanStorageWork->menuAction3 = gKangaskhanStorageWork->unk24[index].menuAction;
            break;
        }
    }
}

static void sub_80177F8(void)
{
    s32 loopMax;

    loopMax = 0;
    gKangaskhanStorageWork->unk24[loopMax].text = gCommonYes[0];
    gKangaskhanStorageWork->unk24[loopMax].menuAction = MENU_YES;

    loopMax++;
    gKangaskhanStorageWork->unk24[loopMax].text = gCommonNo[0];
    gKangaskhanStorageWork->unk24[loopMax].menuAction = MENU_NO;

    loopMax++;
    gKangaskhanStorageWork->unk24[loopMax].text = NULL;
    gKangaskhanStorageWork->unk24[loopMax].menuAction = MENU_CANCEL;
}

static void HandleKangaskhanMainMenu(void)
{
    s32 menuAction;

    if (sub_80144A4(&menuAction))
        return;

    if (menuAction != MENU_CANCEL)
        gKangaskhanStorageWork->menuAction1 = menuAction;

    switch (menuAction) {
        case MENU_STORE:
            if (GetNumberOfFilledInventorySlots() == 0)
                UpdateKangaskhanStorageState(KANGASKHAN_STORAGE_NO_INV_ITEMS);
            else if (sub_801CF50(0))
                UpdateKangaskhanStorageState(8);
            else
                UpdateKangaskhanStorageState(11);
            break;
        case MENU_TAKE:
            if (sub_801CF14(1))
                UpdateKangaskhanStorageState(7);
            else if (GetNumberOfFilledInventorySlots() >= INVENTORY_SIZE)
                UpdateKangaskhanStorageState(KANGASKHAN_STORAGE_TOO_MANY_ITEMS);
            else
                UpdateKangaskhanStorageState(20);
            break;
        case MENU_INFO:
            UpdateKangaskhanStorageState(2);
            break;
        case MENU_CANCEL:
            UpdateKangaskhanStorageState(3);
            break;
    }
}

static void sub_80178D0(void)
{
    s32 menuAction;

    if (sub_80144A4(&menuAction))
        return;

    switch (menuAction) {
        case MENU_YES:
            MoveToStorage(&gKangaskhanStorageWork->storedItem);
            ShiftItemsDownFrom(gKangaskhanStorageWork->itemIndex);
            FillInventoryGaps();
            UpdateKangaskhanStorageState(19);
            break;
        case MENU_CANCEL:
        case MENU_NO:
            UpdateKangaskhanStorageState(14);
            break;
    }
}

static void sub_8017928(void)
{
    s32 menuAction;
    BulkItem item;

    if (sub_80144A4(&menuAction))
        return;

    switch (menuAction) {
        case MENU_YES:
            gTeamInventoryRef->teamStorage[gKangaskhanStorageWork->storedItem.id] -= gKangaskhanStorageWork->storedItem.quantity;
            item.id = gKangaskhanStorageWork->storedItem.id;
            item.quantity = gKangaskhanStorageWork->storedItem.quantity;
            AddHeldItemToInventory(&item);
            UpdateKangaskhanStorageState(29);
            break;
        case MENU_CANCEL:
        case MENU_NO:
            UpdateKangaskhanStorageState(23);
            break;
    }
}

static void sub_80179A8(void)
{
    s32 index;
    s32 menuAction;

    if (sub_80144A4(&menuAction))
        return;

    switch (menuAction) {
        case MENU_YES:
            for (index = 0; index < INVENTORY_SIZE; index++) {
                if (sub_801AED0(index)) {
                    MoveToStorage(&gTeamInventoryRef->teamItems[index]);
                    gTeamInventoryRef->teamItems[index].id = 0;
                    gTeamInventoryRef->teamItems[index].flags = 0;
                }
            }

            FillInventoryGaps();
            sub_801AE84();
            UpdateKangaskhanStorageState(19);
            break;
        case MENU_CANCEL:
        case MENU_NO:
            UpdateKangaskhanStorageState(14);
            break;
    }
}

static void sub_8017A1C(void)
{
    s32 itemID;
    s32 menuAction;
    BulkItem item;

    if (sub_80144A4(&menuAction))
        return;

    switch (menuAction) {
        case MENU_YES:
            for (itemID = 0; itemID < NUMBER_OF_ITEM_IDS; itemID++) {
                if (sub_801CFE0(itemID)) {
                    item.id = itemID;
                    if (IsThrownItem(item.id)) {
                        if (gTeamInventoryRef->teamStorage[item.id] > 99)
                            item.quantity = 99;
                        else
                            item.quantity = gTeamInventoryRef->teamStorage[item.id];
                    }
                    else
                        item.quantity = 1;
                    gTeamInventoryRef->teamStorage[item.id] -= item.quantity;
                    AddHeldItemToInventory(&item);
                }
            }

            FillInventoryGaps();
            sub_801CF94();
            UpdateKangaskhanStorageState(29);
            break;
        case MENU_CANCEL:
        case MENU_NO:
            UpdateKangaskhanStorageState(23);
            break;
    }
}

static void sub_8017AF8(void)
{
    switch (sub_801A6E8(TRUE)) {
        case 3:
            if (sub_801AEA8()) {
                sub_8099690(0);
                UpdateKangaskhanStorageState(18);
            }
            else {
                gKangaskhanStorageWork->itemIndex = sub_801A8AC();
                gKangaskhanStorageWork->storedItem = gTeamInventoryRef->teamItems[gKangaskhanStorageWork->itemIndex];
                UpdateKangaskhanStorageState(15);
            }
            break;
        case 4:
            gKangaskhanStorageWork->itemIndex = sub_801A8AC();
            gKangaskhanStorageWork->storedItem = gTeamInventoryRef->teamItems[gKangaskhanStorageWork->itemIndex];
            UpdateKangaskhanStorageState(16);
            break;
        case 2:
            sub_801A928();
            UpdateKangaskhanStorageState(KANGASKHAN_STORAGE_MAIN_MENU);
            break;
    }
}

static void sub_8017B88(void)
{
    switch (sub_801CA08(TRUE)) {
        case 3:
            if (sub_801CFB8())
                UpdateKangaskhanStorageState(28);
            else {
                gKangaskhanStorageWork->id = sub_801CB24();
                ItemIdToItem(&gKangaskhanStorageWork->storedItem, gKangaskhanStorageWork->id, 0);
                gKangaskhanStorageWork->storedItem.quantity = 1;
                UpdateKangaskhanStorageState(25);
            }
            break;
        case 4:
            gKangaskhanStorageWork->id = sub_801CB24();
            ItemIdToItem(&gKangaskhanStorageWork->storedItem, gKangaskhanStorageWork->id, 0);
            gKangaskhanStorageWork->storedItem.quantity = 1;
            UpdateKangaskhanStorageState(26);
            break;
        case 2:
            sub_801CBB8();
            UpdateKangaskhanStorageState(KANGASKHAN_STORAGE_MAIN_MENU);
            break;
        case 1:
            sub_801AD34(0);
            break;
    }
}

static void sub_8017C28(void)
{
    sub_801CA08(FALSE);
    sub_8012FD8(&gKangaskhanStorageWork->unk58);

    switch (sub_8013BBC(&gKangaskhanStorageWork->unkA8)) {
        case 1:
            sub_8017598();
            break;
        case 3:
            gKangaskhanStorageWork->storedItem.quantity = gKangaskhanStorageWork->unkA8.unk0;
            UpdateKangaskhanStorageState(27);
            break;
        case 2:
            UpdateKangaskhanStorageState(23);
            break;
        case 0:
        default:
            break;
    }
}

static void sub_8017C7C(void)
{
    s32 menuAction;
    menuAction = 0;

    sub_801A6E8(FALSE);
    if (sub_8012FD8(&gKangaskhanStorageWork->unk58) == 0) {
        sub_8013114(&gKangaskhanStorageWork->unk58, &menuAction);
        if (menuAction != MENU_CANCEL)
            gKangaskhanStorageWork->menuAction2 = menuAction;
    }

    switch (menuAction) {
        case MENU_STORE:
            sub_8099690(0);
            if (!IsNotMoneyOrUsedTMItem(gKangaskhanStorageWork->storedItem.id))
                UpdateKangaskhanStorageState(KANGASKHAN_STORAGE_IS_MONEY_USED_TM);
            else if(!sub_801ADA0(gKangaskhanStorageWork->itemIndex))
                UpdateKangaskhanStorageState(10);
            else
                UpdateKangaskhanStorageState(17);
        break;
        case MENU_INFO:
            sub_8099690(0);
            UpdateKangaskhanStorageState(16);
            break;
        case MENU_CANCEL:
            UpdateKangaskhanStorageState(14);
            break;
    }
}

static void sub_8017D24(void)
{
    s32 menuAction;
    menuAction = 0;

    sub_801CA08(FALSE);
    if (sub_8012FD8(&gKangaskhanStorageWork->unk58) == 0) {
        sub_8013114(&gKangaskhanStorageWork->unk58, &menuAction);
        if (menuAction != MENU_CANCEL)
            gKangaskhanStorageWork->menuAction3 = menuAction;
    }

    switch (menuAction) {
        case MENU_TAKE:
            if (GetNumberOfFilledInventorySlots() >= INVENTORY_SIZE) {
                sub_801CBB8();
                UpdateKangaskhanStorageState(KANGASKHAN_STORAGE_TOO_MANY_ITEMS);
            }
            else if (IsThrownItem(gKangaskhanStorageWork->storedItem.id))
                UpdateKangaskhanStorageState(24);
            else
                UpdateKangaskhanStorageState(27);
            break;
        case MENU_INFO:
            UpdateKangaskhanStorageState(26);
            break;
        case MENU_CANCEL:
            UpdateKangaskhanStorageState(23);
            break;
    }
}

static void sub_8017DC0(void)
{
    switch (sub_801B410()) {
        case 0:
        case 1:
        default:
            break;
        case 2:
        case 3:
            FreeItemDescriptionWindow();
            UpdateKangaskhanStorageState(14);
            break;
    }
}

static void sub_8017DDC(void)
{
    switch (sub_801B410()) {
        case 0:
        case 1:
        default:
            break;
        case 2:
        case 3:
            FreeItemDescriptionWindow();
            UpdateKangaskhanStorageState(23);
            break;
    }
}

static void AdvanceToKangaskhanStorageFallbackState(void)
{
    s32 temp;

    if (!sub_80144A4(&temp))
        UpdateKangaskhanStorageState(gKangaskhanStorageWork->fallbackState);
}
