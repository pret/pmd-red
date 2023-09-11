#include "global.h"
#include "code_80118A4.h"
#include "code_80130A8.h"
#include "code_801B3C0.h"
#include "code_8098BDC.h"
#include "common_strings.h"
#include "felicity_bank.h"
#include "items.h"
#include "kecleon_bros1.h"
#include "kecleon_bros2.h"
#include "kecleon_bros3.h"
#include "kecleon_bros4.h"
#include "memory.h"
#include "menu_input.h"
#include "pokemon.h"
#include "text1.h"
#include "text2.h"

extern u32 gUnknown_202DE30;
extern u8 gUnknown_202DE58[];
extern u8 gUnknown_202E1C8[];
extern u8 gUnknown_202E5D8[];

static EWRAM_DATA_2 KecleonBrosWork1 *sKecleonBrosWork1 = {0};

#include "data/kecleon_bros1.h"

static u32 CountKecleonItems(void);
static void SetKecleonBrosState(u32);
static void UpdateKecleonStoreDialogue(void);

static void sub_8018D30(void);
static void sub_80194F8(void);
static void sub_80195C0(void);
static void sub_8019660(void);
static void sub_8019700(void);
static void sub_8019730(void);
static void sub_8019850(void);
static void sub_80198E8(void);
static void sub_8019944(void);
static void sub_80199CC(void);
static void sub_8019B08(void);
static void sub_8019BBC(void);
static void sub_8019C78(void);
static void sub_8019D30(void);
static void sub_8019D4C(void);
static void sub_8019D68(void);
static void sub_8019DAC(void);
static void sub_8019E04(bool32);

bool8 CreateKecleonBros(u32 mode)
{
    u8 *monName;
    OpenedFile *faceFile;

    sKecleonBrosWork1 = MemoryAlloc(sizeof(KecleonBrosWork1), 8);
    sKecleonBrosWork1->menuAction1 = 0;
    sKecleonBrosWork1->menuAction2 = 0;
    sKecleonBrosWork1->menuAction3 = 0;
    sKecleonBrosWork1->mode = mode;

    switch (mode) {
        case KECLEON_BROS_MODE_ITEMS_AWAKE:
            sKecleonBrosWork1->isKecleonItemShop = TRUE;
            sKecleonBrosWork1->unkE4 = &sKecleonBrosWork1->faceFile;
            CopyYellowMonsterNametoBuffer(gUnknown_202E5D8, MONSTER_KECLEON);
            CopyYellowMonsterNametoBuffer(gUnknown_202E1C8, MONSTER_KECLEON);
            monName = GetMonSpecies(MONSTER_KECLEON);
            strcpy(gUnknown_202E1C8 - 0x50, monName);
            break;
        case KECLEON_BROS_MODE_ITEMS_ASLEEP:
            sKecleonBrosWork1->isKecleonItemShop = TRUE;
            sKecleonBrosWork1->unkE4 = NULL;
            CopyYellowMonsterNametoBuffer(gUnknown_202E5D8, MONSTER_KECLEON);
            CopyYellowMonsterNametoBuffer(gUnknown_202E1C8, MONSTER_KECLEON);
            monName = GetMonSpecies(MONSTER_KECLEON);
            strcpy(gUnknown_202E1C8 - 0x50, monName);
            break;
        case KECLEON_BROS_MODE_WARES_AWAKE:
            sKecleonBrosWork1->isKecleonItemShop = FALSE;
            sKecleonBrosWork1->unkE4 = &sKecleonBrosWork1->faceFile;
            CopyYellowMonsterNametoBuffer(gUnknown_202E5D8, MONSTER_KECLEON);
            CopyYellowMonsterNametoBuffer(gUnknown_202E1C8, MONSTER_KECLEON);
            monName = GetMonSpecies(MONSTER_KECLEON);
            strcpy(gUnknown_202E1C8 - 0x50, monName);
            break;
        case KECLEON_BROS_MODE_WARES_ASLEEP:
            sKecleonBrosWork1->isKecleonItemShop = FALSE;
            sKecleonBrosWork1->unkE4 = NULL;
            CopyYellowMonsterNametoBuffer(gUnknown_202E5D8, MONSTER_KECLEON);
            CopyYellowMonsterNametoBuffer(gUnknown_202E1C8, MONSTER_KECLEON);
            monName = GetMonSpecies(MONSTER_KECLEON);
            strcpy(gUnknown_202E1C8 - 0x50, monName);
            break;
        default:
            break;
    }

    faceFile = GetDialogueSpriteDataPtr(MONSTER_KECLEON);
    sKecleonBrosWork1->faceFile = faceFile;
    sKecleonBrosWork1->faceData = faceFile->data;
    sKecleonBrosWork1->unkE0 = 0;
    sKecleonBrosWork1->unkE1 = 0;
    sKecleonBrosWork1->unkE2 = 0;
    sKecleonBrosWork1->unkDC = 2;
    sKecleonBrosWork1->unkDE = 8;
    SetKecleonBrosState(KECLEON_STORE_INIT);
    return TRUE;
}

u32 KecleonBrosCallback(void)
{
    switch (sKecleonBrosWork1->currState) {
        case KECLEON_STORE_INIT:
        case KECLEON_STORE_MAIN_MENU:
            sub_8019730();
            break;
        case 0x12:
        case 0x13:
            sub_80199CC();
            break;
        case 0x1a:
        case 0x1b:
            sub_8019B08();
            break;
        case 0x14:
            sub_8019BBC();
            break;
        case 0x1c:
            sub_8019C78();
            break;
        case 0x16:
            sub_8019850();
            break;
        case 0x1e:
            sub_80198E8();
            break;
        case 0x1f:
            sub_8019944();
            break;
        case 0x15:
            sub_8019D30();
            break;
        case 0x1d:
            sub_8019D4C();
            break;
        case KECLEON_STORE_EXIT:
            return 3;
        default:
            sub_8019D68();
            break;
    }
    return 0;
}

void DeleteKecleonBros(void)
{
    if (sKecleonBrosWork1 != NULL) {
        CloseFile(sKecleonBrosWork1->faceFile);
        MemoryFree(sKecleonBrosWork1);
        sKecleonBrosWork1 = NULL;
    }
}

static void SetKecleonBrosState(u32 newState)
{
    sKecleonBrosWork1->currState = newState;
    sub_8018D30();
    UpdateKecleonStoreDialogue();
}

static void sub_8018D30(void)
{
    s32 i;

    sub_8006518(sKecleonBrosWork1->unkE8);

    switch (sKecleonBrosWork1->currState) {
        case 18:
        case 19:
            sKecleonBrosWork1->unkE8[0] = sUnknown_80DB840;
            sKecleonBrosWork1->unkE8[2] = sUnknown_80DB840;
            sKecleonBrosWork1->unkE8[0] = sUnknown_80DB870;
            sKecleonBrosWork1->unkE8[1] = sUnknown_80DB888;
            break;
        case 26:
        case 27:
            sKecleonBrosWork1->unkE8[0] = sUnknown_80DB840;
            sKecleonBrosWork1->unkE8[1] = sUnknown_80DB840;
            sKecleonBrosWork1->unkE8[2] = sUnknown_80DB840;
            sKecleonBrosWork1->unkE8[1] = sUnknown_80DB888;
            break;
        case 20:
        case 28:
            sKecleonBrosWork1->unkE8[2] = sUnknown_80DB858;
            break;
        default:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
            for (i = 0; i < 4; i++)
                sKecleonBrosWork1->unkE8[i] = sUnknown_80DB840;
            break;
    }

    ResetUnusedInputStruct();
    sub_800641C(sKecleonBrosWork1->unkE8, TRUE, TRUE);
}

static void UpdateKecleonStoreDialogue(void)
{
    switch (sKecleonBrosWork1->currState) {
        case 0:
            sub_8019DAC();
            sub_80194F8();
            sub_8019E04(FALSE);
            sub_8014248(gCommonKecleonBros[sKecleonBrosWork1->mode][0], 0, sKecleonBrosWork1->menuAction1,
                sKecleonBrosWork1->menuItems, sKecleonBrosWork1->unk74, 4, 0, sKecleonBrosWork1->unkE4, 12);
            break;
        case 1:
            sub_8019DAC();
            sub_80194F8();
            sub_8019E04(FALSE);
            sub_8014248(gCommonKecleonBros[sKecleonBrosWork1->mode][1], 0, sKecleonBrosWork1->menuAction1,
                sKecleonBrosWork1->menuItems, sKecleonBrosWork1->unk74, 4, 0, sKecleonBrosWork1->unkE4, 12);
            break;
        case 2:
            sKecleonBrosWork1->fallbackState = 1;
            sub_8019E04(FALSE);
            sub_80141B4(gCommonKecleonBros[sKecleonBrosWork1->mode][22], 0, sKecleonBrosWork1->unkE4, 0x10D);
            break;
        case 3:         
            sKecleonBrosWork1->fallbackState = 4;
            sub_8019E04(FALSE);
            sub_80141B4(gCommonKecleonBros[sKecleonBrosWork1->mode][2], 0, sKecleonBrosWork1->unkE4, 0x30D);
            break;
        case 5:
            sKecleonBrosWork1->fallbackState = 1;
            sub_8019E04(FALSE);
            sub_80141B4(gCommonKecleonBros[sKecleonBrosWork1->mode][12], 0, sKecleonBrosWork1->unkE4, 0x10D);
            break;
        case 6:
            sKecleonBrosWork1->fallbackState = 16;
            sub_8019E04(TRUE);
            sub_80141B4(gCommonKecleonBros[sKecleonBrosWork1->mode][13], 0, sKecleonBrosWork1->unkE4, 0x10D);
            break;
        case 7:
            sKecleonBrosWork1->fallbackState = 1;
            sub_8019E04(TRUE);
            sub_80141B4(gCommonKecleonBros[sKecleonBrosWork1->mode][14], 0, sKecleonBrosWork1->unkE4, 0x10D);
            break;
        case 8:
            sKecleonBrosWork1->fallbackState = 1;
            sub_8019E04(TRUE);
            sub_80141B4(gCommonKecleonBros[sKecleonBrosWork1->mode][15], 0, sKecleonBrosWork1->unkE4, 0x10D);
            break;
        case 9:
            sKecleonBrosWork1->fallbackState = 1;
            sub_8019E04(TRUE);
            sub_80141B4(gCommonKecleonBros[sKecleonBrosWork1->mode][16], 0, sKecleonBrosWork1->unkE4, 0x10D);
            break;
        case 10:
            sKecleonBrosWork1->fallbackState = 1;
            sub_8019E04(TRUE);
            sub_80141B4(gCommonKecleonBros[sKecleonBrosWork1->mode][17], 0, sKecleonBrosWork1->unkE4, 0x10D);
            break;
        case 11:
            sKecleonBrosWork1->fallbackState = 1;
            sub_8019E04(FALSE);
            sub_80141B4(gCommonKecleonBros[sKecleonBrosWork1->mode][18], 0, sKecleonBrosWork1->unkE4, 0x10D);
            break;
        case 12:
            sKecleonBrosWork1->fallbackState = 16;
            sub_8019E04(TRUE);
            sub_80141B4(gCommonKecleonBros[sKecleonBrosWork1->mode][19], 0, sKecleonBrosWork1->unkE4, 0x10D);
            break;
        case 13:
            sub_8090E14(gUnknown_202DE58, &sKecleonBrosWork1->soldItem, NULL);
            sKecleonBrosWork1->fallbackState = 24;
            sub_8019E04(TRUE);
            sub_80141B4(gCommonKecleonBros[sKecleonBrosWork1->mode][20], 0, sKecleonBrosWork1->unkE4, 0x10D);
            break;
        case 14:
            sKecleonBrosWork1->fallbackState = 24;
            sub_8019E04(TRUE);
            sub_80141B4(gCommonKecleonBros[sKecleonBrosWork1->mode][21], 0, sKecleonBrosWork1->unkE4, 0x10D);
            break;
        case 15:
            sKecleonBrosWork1->fallbackState = 18;
            sub_8019E04(FALSE);
            sub_80141B4(gCommonKecleonBros[sKecleonBrosWork1->mode][3], 0, sKecleonBrosWork1->unkE4, 0x10D);
            break;
        case 16:
            sKecleonBrosWork1->fallbackState = 19;
            sub_8019E04(FALSE);
            sub_80141B4(gCommonKecleonBros[sKecleonBrosWork1->mode][4], 0, sKecleonBrosWork1->unkE4, 0x10D);
            break;
        case 18:
            if (sKecleonBrosWork1->isKecleonItemShop)
                sub_8019E40(3);
            else
                sub_801A20C(3);

            sub_801AD34(0);
            DrawTeamMoneyBox(1);
            break;
        case 19:
            if (sKecleonBrosWork1->isKecleonItemShop)
                sub_8019FCC(TRUE);
            else
                sub_801A398(TRUE);

            sub_801AD34(0);
            DrawTeamMoneyBox(1);
            break;
        case 20:
            if (sKecleonBrosWork1->isKecleonItemShop)
                sub_801A0D8();
            else
                sub_801A4A4();

            sub_801AD34(0);
            DrawTeamMoneyBox(1);
            sub_80195C0();
            sub_8012D60(&sKecleonBrosWork1->menu, sKecleonBrosWork1->menuItems, 0, sKecleonBrosWork1->unk74, sKecleonBrosWork1->menuAction3, 2);
            break;
        case 22:
            sub_8019700();
            sub_8090E14(gUnknown_202DE58, &sKecleonBrosWork1->soldItem, 0);
            gUnknown_202DE30 = sKecleonBrosWork1->itemSellPrice;
            sub_8019E04(FALSE);
            sub_8014248(gCommonKecleonBros[sKecleonBrosWork1->mode][5], 0, 5,sKecleonBrosWork1->menuItems, NULL, 4, 0, sKecleonBrosWork1->unkE4, 12);
            break;
        case 17:
            if (CountKecleonItems() == 0) {
                if (sKecleonBrosWork1->isKecleonItemShop != FALSE)
                    sub_801A010();
                else
                    sub_801A3DC();
                sKecleonBrosWork1->fallbackState = 11;
            }
            else {
                if (GetNumberOfFilledInventorySlots() >= INVENTORY_SIZE) {
                    if (sKecleonBrosWork1->isKecleonItemShop != FALSE)
                        sub_801A010();
                    else
                        sub_801A3DC();
                    sKecleonBrosWork1->fallbackState = 1;
                }
                else
                    sKecleonBrosWork1->fallbackState = 16;
            }
            sub_8019E04(FALSE);
            sub_80141B4(gCommonKecleonBros[sKecleonBrosWork1->mode][6], 0, sKecleonBrosWork1->unkE4, 0x10D);
            break;
        case 23:
            sKecleonBrosWork1->fallbackState = 26;
            sub_8019E04(FALSE);
            sub_80141B4(gCommonKecleonBros[sKecleonBrosWork1->mode][7], 0, sKecleonBrosWork1->unkE4, 0x10D);
            break;
        case 24:
            sKecleonBrosWork1->fallbackState = 27;
            sub_8019E04(FALSE);
            sub_80141B4(gCommonKecleonBros[sKecleonBrosWork1->mode][8], 0, sKecleonBrosWork1->unkE4, 0x10D);
            break;
        case 26:
            sub_801A5D8(4, 3, NULL, 10);
            DrawTeamMoneyBox(1);
            break;
        case 27:
            sub_801A8D0(TRUE);
            DrawTeamMoneyBox(1);
            break;
        case 28:
            sub_801A9E0();
            DrawTeamMoneyBox(1);
            sub_8019660();
            sub_8012D60(&sKecleonBrosWork1->menu, sKecleonBrosWork1->menuItems, 0, sKecleonBrosWork1->unk74, sKecleonBrosWork1->menuAction2, 2);
            break;
        case 30:
            sub_8019700();
            sub_8090E14(gUnknown_202DE58, &sKecleonBrosWork1->soldItem, NULL);
            gUnknown_202DE30 = sKecleonBrosWork1->itemSellPrice;
            sub_8019E04(FALSE);
            sub_8014248(gCommonKecleonBros[sKecleonBrosWork1->mode][9], 0, 5, sKecleonBrosWork1->menuItems, NULL, 4, 0, sKecleonBrosWork1->unkE4, 12);
            break;
        case 21:
        case 29:
            sub_801B3C0(&sKecleonBrosWork1->soldItem);
            break;
        case 25:
            if (GetNumberOfFilledInventorySlots() == 0 || gTeamInventoryRef->teamMoney >= MAX_TEAM_MONEY) {
                sub_801A928();
                sKecleonBrosWork1->fallbackState = 1;
            }
            else
                sKecleonBrosWork1->fallbackState = 24;

            sub_8019E04(FALSE);
            sub_80141B4(gCommonKecleonBros[sKecleonBrosWork1->mode][11], 0, sKecleonBrosWork1->unkE4, 0x10D);
            break;
        case 31:
            sub_8019700();
            gUnknown_202DE30 = sKecleonBrosWork1->inventoryItemSellPrice;
            sub_8019E04(FALSE);
            sub_8014248(gCommonKecleonBros[sKecleonBrosWork1->mode][10], 0, 5, sKecleonBrosWork1->menuItems, NULL, 4, 0, sKecleonBrosWork1->unkE4, 12);
            break;
        case 32:
            sKecleonBrosWork1->fallbackState = 1;
            sub_8019E04(FALSE);
            sub_80141B4(gCommonKecleonBros[sKecleonBrosWork1->mode][11], 0, sKecleonBrosWork1->unkE4, 0x10D);
            break;
    }
}

static void sub_80194F8(void)
{
    s32 i;
    s32 loopMax;

    MemoryFill16(sKecleonBrosWork1->unk74, 0, sizeof(sKecleonBrosWork1->unk74));

    loopMax = 0;
    sKecleonBrosWork1->menuItems[loopMax].text = *gCommonBuy;
    sKecleonBrosWork1->menuItems[loopMax].menuAction = 2;

    loopMax += 1;
    sKecleonBrosWork1->menuItems[loopMax].text = *gCommonSell;
    sKecleonBrosWork1->menuItems[loopMax].menuAction = 3;

    loopMax += 1;
    sKecleonBrosWork1->menuItems[loopMax].text = sSellAll;
    sKecleonBrosWork1->menuItems[loopMax].menuAction = 4;

    loopMax += 1;
    sKecleonBrosWork1->menuItems[loopMax].text = *gCommonInfo;
    sKecleonBrosWork1->menuItems[loopMax].menuAction = 7;

    loopMax += 1;
    sKecleonBrosWork1->menuItems[loopMax].text = *gCommonCancel;
    sKecleonBrosWork1->menuItems[loopMax].menuAction = 1;

    loopMax += 1;
    sKecleonBrosWork1->menuItems[loopMax].text = NULL;
    sKecleonBrosWork1->menuItems[loopMax].menuAction = 1;

    for (i = 0; i < loopMax; i++) {
        if (sKecleonBrosWork1->unk74[i] == 0) {
            if (sKecleonBrosWork1->menuItems[i].menuAction == sKecleonBrosWork1->menuAction1)
                return;
        }
    }

    for (i = 0; i < loopMax; i++) {
        if (sKecleonBrosWork1->unk74[i] == 0) {
            sKecleonBrosWork1->menuAction1 =  sKecleonBrosWork1->menuItems[i].menuAction;
            break;
        }
    }
}

static void sub_80195C0(void)
{
    s32 i;
    s32 loopMax;

    MemoryFill16(sKecleonBrosWork1->unk74, 0, sizeof(sKecleonBrosWork1->unk74));

    loopMax = 0;
    sKecleonBrosWork1->menuItems[loopMax].text = *gCommonBuy;
    sKecleonBrosWork1->menuItems[loopMax].menuAction = 2;

    loopMax += 1;
    sKecleonBrosWork1->menuItems[loopMax].text = *gCommonInfo;
    sKecleonBrosWork1->menuItems[loopMax].menuAction = 7;

    loopMax += 1;
    sKecleonBrosWork1->menuItems[loopMax].text = NULL;
    sKecleonBrosWork1->menuItems[loopMax].menuAction = 1;

    for (i = 0; i < loopMax; i++) {
        if (sKecleonBrosWork1->unk74[i] == 0) {
            if (sKecleonBrosWork1->menuItems[i].menuAction == sKecleonBrosWork1->menuAction3)
                return;
        }
    }

    for (i = 0; i < loopMax; i++) {
        if (sKecleonBrosWork1->unk74[i] == 0) {
            sKecleonBrosWork1->menuAction3 = sKecleonBrosWork1->menuItems[i].menuAction;
            break;
        }
    }
}

static void sub_8019660(void)
{
    s32 i;
    s32 loopMax;

    MemoryFill16(sKecleonBrosWork1->unk74, 0, sizeof(sKecleonBrosWork1->unk74));

    loopMax = 0;
    sKecleonBrosWork1->menuItems[loopMax].text = *gCommonSell;
    sKecleonBrosWork1->menuItems[loopMax].menuAction = 3;

    loopMax += 1;
    sKecleonBrosWork1->menuItems[loopMax].text = *gCommonInfo;
    sKecleonBrosWork1->menuItems[loopMax].menuAction = 7;

    loopMax += 1;
    sKecleonBrosWork1->menuItems[loopMax].text = NULL;
    sKecleonBrosWork1->menuItems[loopMax].menuAction = 1;

    for (i = 0; i < loopMax; i++) {
        if (sKecleonBrosWork1->unk74[i] == 0) {
            if (sKecleonBrosWork1->menuItems[i].menuAction == sKecleonBrosWork1->menuAction2)
                return;
        }
    }

    for (i = 0; i < loopMax; i++) {
        if (sKecleonBrosWork1->unk74[i] == 0) {
            sKecleonBrosWork1->menuAction2 =  sKecleonBrosWork1->menuItems[i].menuAction;
            break;
        }
    }
}

static void sub_8019700(void)
{
    s32 loopMax = 0;
    sKecleonBrosWork1->menuItems[loopMax].text = *gCommonYes;
    sKecleonBrosWork1->menuItems[loopMax].menuAction = 5;

    loopMax += 1;
    sKecleonBrosWork1->menuItems[loopMax].text = *gCommonNo;
    sKecleonBrosWork1->menuItems[loopMax].menuAction = 6;

    loopMax += 1;
    sKecleonBrosWork1->menuItems[loopMax].text = NULL;
    sKecleonBrosWork1->menuItems[loopMax].menuAction = 1;
}

static void sub_8019730(void)
{
    s32 menuAction;

    if (sub_80144A4(&menuAction) != 0)
        return;

    if (menuAction != 1)
        sKecleonBrosWork1->menuAction1 = menuAction;

    switch (menuAction) {
        case 2:
            if (CountKecleonItems() == 0)
                SetKecleonBrosState(KECLEON_STORE_NO_STORE_ITEMS);
            else if (GetNumberOfFilledInventorySlots() >= INVENTORY_SIZE)
                SetKecleonBrosState(KECLEON_STORE_TOO_MANY_ITEMS);
            else
                SetKecleonBrosState(15);
            break;
        case 3:
            if (GetNumberOfFilledInventorySlots() == 0)
                SetKecleonBrosState(KECLEON_STORE_NO_ITEMS_TO_SELL);
            else if (sKecleonBrosWork1->numInventoryItemToSell == 0)
                SetKecleonBrosState(8);
            else if (gTeamInventoryRef->teamMoney < MAX_TEAM_MONEY)
                SetKecleonBrosState(23);
            else
                SetKecleonBrosState(7);
            break;
        case 4:
            if (GetNumberOfFilledInventorySlots() == 0)
                SetKecleonBrosState(KECLEON_STORE_NO_ITEMS_TO_SELL);
            else if (sKecleonBrosWork1->numInventoryItemToSell == 0)
                SetKecleonBrosState(8);
            else if (sKecleonBrosWork1->inventoryItemSellPrice + gTeamInventoryRef->teamMoney > MAX_TEAM_MONEY)
                SetKecleonBrosState(7);
            else
                SetKecleonBrosState(31);
            break;
        case 7:
            SetKecleonBrosState(2);
            break;
        case 1:
            SetKecleonBrosState(3);
            break;
    }
}

static void sub_8019850(void)
{
    s32 menuAction;

    if (sub_80144A4(&menuAction) == 0) {
        switch (menuAction) {
            case 5:
                AddToTeamMoney(-sKecleonBrosWork1->itemSellPrice);

                if (sKecleonBrosWork1->isKecleonItemShop) {
                    AddHeldItemToInventory(GetKecleonShopItem(sKecleonBrosWork1->itemShopItemIndex));
                    InitKecleonShopItem(sKecleonBrosWork1->itemShopItemIndex);
                    FillKecleonShopGaps();
                }
                else {
                    AddHeldItemToInventory(GetKecleonWareItem(sKecleonBrosWork1->wareShopItemIndex));
                    InitKecleonWareItem(sKecleonBrosWork1->wareShopItemIndex);
                    FillKecleonWareGaps();
                }

                PlaySound(332);
                SetKecleonBrosState(17);
                break;
            case 6:
            case 1:
                SetKecleonBrosState(16);
                break;
        }
    }
}

static void sub_80198E8(void)
{
    s32 menuAction;

    if (sub_80144A4(&menuAction) == 0) {
        switch (menuAction) {
            case 5:
                AddToTeamMoney(sKecleonBrosWork1->itemSellPrice);
                ShiftItemsDownFrom(sKecleonBrosWork1->soldItemInventoryIndex);
                PlaySound(332);
                SetKecleonBrosState(25);
                break;
            case 6:
            case 1:
                SetKecleonBrosState(24);
                break;
        }
    }
}

static void sub_8019944(void)
{
    s32 slotIndex;
    s32 menuAction;
    Item *item;

    if (sub_80144A4(&menuAction) == 0) {
        switch (menuAction) {
            case 5:
                for (slotIndex = 0; slotIndex < INVENTORY_SIZE; slotIndex++) {
                    item = &gTeamInventoryRef->teamItems[slotIndex];

                    if ((item->flags & ITEM_FLAG_EXISTS) && CanSellItem(item->id))
                        ClearItemSlotAt(slotIndex);
                }

                FillInventoryGaps();
                AddToTeamMoney(sKecleonBrosWork1->inventoryItemSellPrice);
                PlaySound(0x14c);
                SetKecleonBrosState(32);
                break;
            case 1:
            case 6:
                SetKecleonBrosState(KECLEON_STORE_MAIN_MENU);
                break;
        }
    }
}

static void sub_80199CC(void)
{
    u32 menuAction;
    BulkItem *item;

    if (sKecleonBrosWork1->isKecleonItemShop)
        menuAction = sub_8019EDC(TRUE);
    else
        menuAction = sub_801A2A8(TRUE);

    switch (menuAction) {
        case 3:
            if (sKecleonBrosWork1->isKecleonItemShop) {
                sKecleonBrosWork1->itemShopItemIndex = sub_8019FB0();
                item = GetKecleonShopItem(sKecleonBrosWork1->itemShopItemIndex);
            }
            else {
                sKecleonBrosWork1->wareShopItemIndex = sub_801A37C();
                item = GetKecleonWareItem(sKecleonBrosWork1->wareShopItemIndex);
            }

            xxx_init_itemslot_8090A8C(&sKecleonBrosWork1->soldItem, item->id, 0);
            sKecleonBrosWork1->soldItem.quantity = item->quantity;
            sKecleonBrosWork1->itemSellPrice = GetStackBuyPrice(&sKecleonBrosWork1->soldItem);
            SetKecleonBrosState(20);
            break;
        case 4:
            if (sKecleonBrosWork1->isKecleonItemShop) {
                sKecleonBrosWork1->itemShopItemIndex = sub_8019FB0();
                item = GetKecleonShopItem(sKecleonBrosWork1->itemShopItemIndex);
            }
            else {
                sKecleonBrosWork1->wareShopItemIndex = sub_801A37C();
                item = GetKecleonWareItem(sKecleonBrosWork1->wareShopItemIndex);
            }

            xxx_init_itemslot_8090A8C(&sKecleonBrosWork1->soldItem, item->id, 0);
            sKecleonBrosWork1->soldItem.quantity = item->quantity;
            sKecleonBrosWork1->itemSellPrice = GetStackBuyPrice(&sKecleonBrosWork1->soldItem);
            SetKecleonBrosState(21);
            break;
        case 2:
            if (sKecleonBrosWork1->isKecleonItemShop)
                sub_801A010();
            else
                sub_801A3DC();

            SetKecleonBrosState(KECLEON_STORE_MAIN_MENU);
            break;
        case 1:
            sub_801AD34(0);
            DrawTeamMoneyBox(1);
            break;
    }
}

static void sub_8019B08(void)
{
    switch (sub_801A6E8(TRUE)) {
        case 0:
            break;
        case 3:
            sKecleonBrosWork1->soldItemInventoryIndex = sub_801A8AC();
            sKecleonBrosWork1->soldItem = gTeamInventoryRef->teamItems[sKecleonBrosWork1->soldItemInventoryIndex];
            sKecleonBrosWork1->itemSellPrice = GetStackSellPrice(&sKecleonBrosWork1->soldItem);
            SetKecleonBrosState(28);
            break;
        case 4:
            sKecleonBrosWork1->soldItemInventoryIndex = sub_801A8AC();
            sKecleonBrosWork1->soldItem = gTeamInventoryRef->teamItems[sKecleonBrosWork1->soldItemInventoryIndex];
            sKecleonBrosWork1->itemSellPrice = GetStackSellPrice(&sKecleonBrosWork1->soldItem);
            sub_8099690(0);
            SetKecleonBrosState(29);
            break;
        case 2:
            sub_801A928();
            SetKecleonBrosState(KECLEON_STORE_MAIN_MENU);
            break;
        case 1:
        default:
            DrawTeamMoneyBox(1);
            break;
    }
}

static void sub_8019BBC(void)
{
    s32 menuAction;

    menuAction = 0;

    if (sKecleonBrosWork1->isKecleonItemShop)
        sub_8019EDC(FALSE);
    else
        sub_801A2A8(FALSE);

    if (sub_8012FD8(&sKecleonBrosWork1->menu) == 0 && (sub_8013114(&sKecleonBrosWork1->menu, &menuAction), menuAction != 1))
        sKecleonBrosWork1->menuAction3 = menuAction;

    switch (menuAction) {
        case 2:
            if (gTeamInventoryRef->teamMoney == 0)
                SetKecleonBrosState(KECLEON_STORE_NO_MONEY);
            else if (sKecleonBrosWork1->itemSellPrice > gTeamInventoryRef->teamMoney)
                SetKecleonBrosState(KECLEON_STORE_NOT_ENOUGH_MONEY);
            else
                SetKecleonBrosState(22);
            break;
        case 7:
            SetKecleonBrosState(21);
            break;
        case 1:
            SetKecleonBrosState(19);
            break;
    }
}

static void sub_8019C78(void)
{
    s32 menuAction;

    menuAction = 0;
    sub_801A6E8(FALSE);

    if (sub_8012FD8(&sKecleonBrosWork1->menu) == FALSE && (sub_8013114(&sKecleonBrosWork1->menu, &menuAction), menuAction != 1))
        sKecleonBrosWork1->menuAction2 = menuAction;

    switch (menuAction) {
        case 3:
            sub_8099690(0);

            if (!CanSellItem(sKecleonBrosWork1->soldItem.id))
                SetKecleonBrosState(KECLEON_STORE_CANT_SELL_ITEM);
            else if (sKecleonBrosWork1->itemSellPrice + gTeamInventoryRef->teamMoney > MAX_TEAM_MONEY)
                SetKecleonBrosState(14);
            else
                SetKecleonBrosState(30);
            break;
        case 7:
            sub_8099690(0);
            SetKecleonBrosState(29);
            break;
        case 1:
            SetKecleonBrosState(27);
            break;
    }
}

static void sub_8019D30(void)
{
    switch (sub_801B410()) {
        case 2:
        case 3:
            sub_801B450();
            SetKecleonBrosState(19);
            break;
        case 0:
        case 1:
            break;
    }
}

static void sub_8019D4C(void)
{
    switch (sub_801B410()) {
        case 2:
        case 3:
            sub_801B450();
            SetKecleonBrosState(27);
            break;
        case 0:
        case 1:
            break;
    }
}

static void sub_8019D68(void)
{
    s32 temp;

    if (sub_80144A4(&temp) == 0)
        SetKecleonBrosState(sKecleonBrosWork1->fallbackState);
}

static u32 CountKecleonItems(void)
{
    if (sKecleonBrosWork1->isKecleonItemShop)
        return CountKecleonShopItems();
    else
        return CountKecleonWareItems();
}

static void sub_8019DAC(void)
{
    s32 sellPrice;
    Item *item;
    s32 index;

    sKecleonBrosWork1->numInventoryItemToSell = 0;
    sKecleonBrosWork1->inventoryItemSellPrice = 0;
    for (index = 0; index < INVENTORY_SIZE; index++) {
        item = &gTeamInventoryRef->teamItems[index];

        if ((item->flags & ITEM_FLAG_EXISTS) != 0 && CanSellItem(item->id)) {
            sellPrice = GetStackSellPrice(item);
            sKecleonBrosWork1->inventoryItemSellPrice += sellPrice;
            sKecleonBrosWork1->numInventoryItemToSell++;
        }
    }
}

static void sub_8019E04(bool32 a0)
{
    if (sKecleonBrosWork1->isKecleonItemShop) {
        if (a0 == TRUE)
            sKecleonBrosWork1->unkE0 = 1;
        else
            sKecleonBrosWork1->unkE0 = 0;
    }
    else {
        if (a0 == TRUE)
            sKecleonBrosWork1->unkE0 = 7;
        else
            sKecleonBrosWork1->unkE0  = 6;
    }
}