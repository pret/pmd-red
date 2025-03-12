#include "global.h"
#include "globaldata.h"
#include "code_80118A4.h"
#include "string_format.h"
#include "code_801B3C0.h"
#include "code_8099360.h"
#include "common_strings.h"
#include "felicity_bank.h"
#include "input.h"
#include "items.h"
#include "kecleon_bros1.h"
#include "kecleon_bros2.h"
#include "kecleon_bros3.h"
#include "kecleon_bros4.h"
#include "memory.h"
#include "menu_input.h"
#include "pokemon.h"
#include "text.h"

static EWRAM_INIT KecleonBrosWork1 *sKecleonBrosWork1 = {NULL};

#include "data/kecleon_bros1.h"

static u32 CountKecleonItems(void);
static void SetKecleonBrosState(u32);
static void UpdateKecleonStoreDialogue(void);

static void sub_8018D30(void);
static void BuildKecleonBrosMainMenu(void);
static void BuildKecleonBrosBuyItemMenu(void);
static void BuildKecleonBrosSellItemMenu(void);
static void BuildKecleonBrosYesNoMenu(void);
static void HandleKecleonBrosMainMenu(void);
static void HandleKecleonBrosBuyItemYesNoMenu(void);
static void HandleKecleonBrosSellItemYesNoMenu(void);
static void HandleKecleonBrosSellAllItemsMenu(void);
static void sub_80199CC(void);
static void sub_8019B08(void);
static void HandleKecleonBrosBuyItemMenu(void);
static void HandleKecleonBrosSellItemMenu(void);
static void sub_8019D30(void);
static void sub_8019D4C(void);
static void ProceedToKecleonBros1FallbackState(void);
static void KecleonCalcSellPriceForAllItems(void);
static void SetKecleonPortraitSpriteId(bool32 angrySprite);

enum MenuActions {
    CANCEL_ACTION = 1,
    BUY_ACTION,
    SELL_ACTION,
    SELL_ALL_ACTION,
    YES_ACTION,
    NO_ACTION,
    INFO_ACTION
};

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
            sKecleonBrosWork1->monPortraitPtr = &sKecleonBrosWork1->monPortrait;
            CopyYellowMonsterNametoBuffer(gSpeakerNameBuffer, MONSTER_KECLEON);
            CopyYellowMonsterNametoBuffer(gFormatBuffer_Monsters[7], MONSTER_KECLEON);
            monName = GetMonSpecies(MONSTER_KECLEON);
            strcpy(gFormatBuffer_Monsters[6], monName);
            break;
        case KECLEON_BROS_MODE_ITEMS_ASLEEP:
            sKecleonBrosWork1->isKecleonItemShop = TRUE;
            sKecleonBrosWork1->monPortraitPtr = NULL;
            CopyYellowMonsterNametoBuffer(gSpeakerNameBuffer, MONSTER_KECLEON);
            CopyYellowMonsterNametoBuffer(gFormatBuffer_Monsters[7], MONSTER_KECLEON);
            monName = GetMonSpecies(MONSTER_KECLEON);
            strcpy(gFormatBuffer_Monsters[6], monName);
            break;
        case KECLEON_BROS_MODE_WARES_AWAKE:
            sKecleonBrosWork1->isKecleonItemShop = FALSE;
            sKecleonBrosWork1->monPortraitPtr = &sKecleonBrosWork1->monPortrait;
            CopyYellowMonsterNametoBuffer(gSpeakerNameBuffer, MONSTER_KECLEON);
            CopyYellowMonsterNametoBuffer(gFormatBuffer_Monsters[7], MONSTER_KECLEON);
            monName = GetMonSpecies(MONSTER_KECLEON);
            strcpy(gFormatBuffer_Monsters[6], monName);
            break;
        case KECLEON_BROS_MODE_WARES_ASLEEP:
            sKecleonBrosWork1->isKecleonItemShop = FALSE;
            sKecleonBrosWork1->monPortraitPtr = NULL;
            CopyYellowMonsterNametoBuffer(gSpeakerNameBuffer, MONSTER_KECLEON);
            CopyYellowMonsterNametoBuffer(gFormatBuffer_Monsters[7], MONSTER_KECLEON);
            monName = GetMonSpecies(MONSTER_KECLEON);
            strcpy(gFormatBuffer_Monsters[6], monName);
            break;
        default:
            break;
    }

    faceFile = GetDialogueSpriteDataPtr(MONSTER_KECLEON);
    sKecleonBrosWork1->monPortrait.faceFile = faceFile;
    sKecleonBrosWork1->monPortrait.faceData = (struct PortraitGfx *) faceFile->data;
    sKecleonBrosWork1->monPortrait.spriteId = 0;
    sKecleonBrosWork1->monPortrait.flip = FALSE;
    sKecleonBrosWork1->monPortrait.unkE = 0;
    sKecleonBrosWork1->monPortrait.pos.x = 2;
    sKecleonBrosWork1->monPortrait.pos.y = 8;
    SetKecleonBrosState(KECLEON_STORE_INIT);
    return TRUE;
}

u32 KecleonBrosCallback(void)
{
    switch (sKecleonBrosWork1->currState) {
        case KECLEON_STORE_INIT:
        case KECLEON_STORE_MAIN_MENU:
            HandleKecleonBrosMainMenu();
            break;
        case 18:
        case 19:
            sub_80199CC();
            break;
        case 26:
        case 27:
            sub_8019B08();
            break;
        case 20:
            HandleKecleonBrosBuyItemMenu();
            break;
        case 28:
            HandleKecleonBrosSellItemMenu();
            break;
        case KECLEON_STORE_BUY_ITEM:
            HandleKecleonBrosBuyItemYesNoMenu();
            break;
        case KECLEON_STORE_SELL_ITEM:
            HandleKecleonBrosSellItemYesNoMenu();
            break;
        case KECLEON_STORE_SELL_ALL_ITEMS:
            HandleKecleonBrosSellAllItemsMenu();
            break;
        case KECLEON_STORE_BUY_ITEM_INFO:
            sub_8019D30();
            break;
        case KECLEON_STORE_SELL_ITEM_INFO:
            sub_8019D4C();
            break;
        case KECLEON_STORE_EXIT:
            return 3;
        default:
            ProceedToKecleonBros1FallbackState();
            break;
    }
    return 0;
}

void DeleteKecleonBros(void)
{
    if (sKecleonBrosWork1 != NULL) {
        CloseFile(sKecleonBrosWork1->monPortrait.faceFile);
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

    RestoreUnkTextStruct_8006518(&sKecleonBrosWork1->unkE8);

    switch (sKecleonBrosWork1->currState) {
        case 18:
        case 19:
            sKecleonBrosWork1->unkE8.id[0] = sUnknown_80DB840;
            sKecleonBrosWork1->unkE8.id[2] = sUnknown_80DB840;
            sKecleonBrosWork1->unkE8.id[0] = sUnknown_80DB870;
            sKecleonBrosWork1->unkE8.id[1] = sUnknown_80DB888;
            break;
        case 26:
        case 27:
            sKecleonBrosWork1->unkE8.id[0] = sUnknown_80DB840;
            sKecleonBrosWork1->unkE8.id[1] = sUnknown_80DB840;
            sKecleonBrosWork1->unkE8.id[2] = sUnknown_80DB840;
            sKecleonBrosWork1->unkE8.id[1] = sUnknown_80DB888;
            break;
        case 20:
        case 28:
            sKecleonBrosWork1->unkE8.id[2] = sUnknown_80DB858;
            break;
        default:
        case KECLEON_STORE_BUY_ITEM_INFO:
        case KECLEON_STORE_BUY_ITEM:
        case 23:
        case KECLEON_STORE_SELL_ITEM_MENU:
        case KECLEON_STORE_SELL_ITEM_RECEIPT:
            for (i = 0; i < 4; i++)
                sKecleonBrosWork1->unkE8.id[i] = sUnknown_80DB840;
            break;
    }

    ResetUnusedInputStruct();
    ShowWindows(&sKecleonBrosWork1->unkE8, TRUE, TRUE);
}

static void UpdateKecleonStoreDialogue(void)
{
    switch (sKecleonBrosWork1->currState) {
        case KECLEON_STORE_INIT:
            KecleonCalcSellPriceForAllItems();
            BuildKecleonBrosMainMenu();
            SetKecleonPortraitSpriteId(FALSE);
            CreateMenuDialogueBoxAndPortrait(gCommonKecleonBros[sKecleonBrosWork1->mode][KECLEON_DLG_00], 0, sKecleonBrosWork1->menuAction1,
                sKecleonBrosWork1->menuItems, sKecleonBrosWork1->unk74, 4, 0, sKecleonBrosWork1->monPortraitPtr, 12);
            break;
        case KECLEON_STORE_MAIN_MENU:
            KecleonCalcSellPriceForAllItems();
            BuildKecleonBrosMainMenu();
            SetKecleonPortraitSpriteId(FALSE);
            CreateMenuDialogueBoxAndPortrait(gCommonKecleonBros[sKecleonBrosWork1->mode][KECLEON_DLG_01], 0, sKecleonBrosWork1->menuAction1,
                sKecleonBrosWork1->menuItems, sKecleonBrosWork1->unk74, 4, 0, sKecleonBrosWork1->monPortraitPtr, 12);
            break;
        case KECLEON_STORE_INFO:
            sKecleonBrosWork1->fallbackState = KECLEON_STORE_MAIN_MENU;
            SetKecleonPortraitSpriteId(FALSE);
            CreateDialogueBoxAndPortrait(gCommonKecleonBros[sKecleonBrosWork1->mode][KECLEON_DLG_22], 0, sKecleonBrosWork1->monPortraitPtr, 0x10D);
            break;
        case 3:
            sKecleonBrosWork1->fallbackState = KECLEON_STORE_EXIT;
            SetKecleonPortraitSpriteId(FALSE);
            CreateDialogueBoxAndPortrait(gCommonKecleonBros[sKecleonBrosWork1->mode][KECLEON_DLG_02], 0, sKecleonBrosWork1->monPortraitPtr, 0x30D);
            break;
        case KECLEON_STORE_NO_STORE_ITEMS:
            sKecleonBrosWork1->fallbackState = KECLEON_STORE_MAIN_MENU;
            SetKecleonPortraitSpriteId(FALSE);
            CreateDialogueBoxAndPortrait(gCommonKecleonBros[sKecleonBrosWork1->mode][KECLEON_DLG_12], 0, sKecleonBrosWork1->monPortraitPtr, 0x10D);
            break;
        case KECLEON_STORE_NO_MONEY:
            sKecleonBrosWork1->fallbackState = KECLEON_STORE_BUY_ITEM_MENU;
            SetKecleonPortraitSpriteId(TRUE);
            CreateDialogueBoxAndPortrait(gCommonKecleonBros[sKecleonBrosWork1->mode][KECLEON_DLG_13], 0, sKecleonBrosWork1->monPortraitPtr, 0x10D);
            break;
        case KECLEON_STORE_TOO_MUCH_MONEY:
            sKecleonBrosWork1->fallbackState = KECLEON_STORE_MAIN_MENU;
            SetKecleonPortraitSpriteId(TRUE);
            CreateDialogueBoxAndPortrait(gCommonKecleonBros[sKecleonBrosWork1->mode][KECLEON_DLG_14], 0, sKecleonBrosWork1->monPortraitPtr, 0x10D);
            break;
        case KECLEON_STORE_NO_ITEMS_TO_SELL:
            sKecleonBrosWork1->fallbackState = KECLEON_STORE_MAIN_MENU;
            SetKecleonPortraitSpriteId(TRUE);
            CreateDialogueBoxAndPortrait(gCommonKecleonBros[sKecleonBrosWork1->mode][KECLEON_DLG_15], 0, sKecleonBrosWork1->monPortraitPtr, 0x10D);
            break;
        case KECLEON_STORE_NO_ITEMS:
            sKecleonBrosWork1->fallbackState = KECLEON_STORE_MAIN_MENU;
            SetKecleonPortraitSpriteId(TRUE);
            CreateDialogueBoxAndPortrait(gCommonKecleonBros[sKecleonBrosWork1->mode][KECLEON_DLG_16], 0, sKecleonBrosWork1->monPortraitPtr, 0x10D);
            break;
        case KECLEON_STORE_TOO_MANY_ITEMS:
            sKecleonBrosWork1->fallbackState = KECLEON_STORE_MAIN_MENU;
            SetKecleonPortraitSpriteId(TRUE);
            CreateDialogueBoxAndPortrait(gCommonKecleonBros[sKecleonBrosWork1->mode][KECLEON_DLG_17], 0, sKecleonBrosWork1->monPortraitPtr, 0x10D);
            break;
        case 11:
            sKecleonBrosWork1->fallbackState = KECLEON_STORE_MAIN_MENU;
            SetKecleonPortraitSpriteId(FALSE);
            CreateDialogueBoxAndPortrait(gCommonKecleonBros[sKecleonBrosWork1->mode][KECLEON_DLG_18], 0, sKecleonBrosWork1->monPortraitPtr, 0x10D);
            break;
        case KECLEON_STORE_NOT_ENOUGH_MONEY:
            sKecleonBrosWork1->fallbackState = KECLEON_STORE_BUY_ITEM_MENU;
            SetKecleonPortraitSpriteId(TRUE);
            CreateDialogueBoxAndPortrait(gCommonKecleonBros[sKecleonBrosWork1->mode][KECLEON_DLG_19], 0, sKecleonBrosWork1->monPortraitPtr, 0x10D);
            break;
        case KECLEON_STORE_CANT_SELL_ITEM:
            sub_8090E14(gFormatBuffer_Items[0], &sKecleonBrosWork1->soldItem, NULL);
            sKecleonBrosWork1->fallbackState = KECLEON_STORE_SELL_ITEM_MENU;
            SetKecleonPortraitSpriteId(TRUE);
            CreateDialogueBoxAndPortrait(gCommonKecleonBros[sKecleonBrosWork1->mode][KECLEON_DLG_20], 0, sKecleonBrosWork1->monPortraitPtr, 0x10D);
            break;
        case KECLEON_STORE_SELL_ITEM_TOO_MUCH_MONEY:
            sKecleonBrosWork1->fallbackState = KECLEON_STORE_SELL_ITEM_MENU;
            SetKecleonPortraitSpriteId(TRUE);
            CreateDialogueBoxAndPortrait(gCommonKecleonBros[sKecleonBrosWork1->mode][KECLEON_DLG_21], 0, sKecleonBrosWork1->monPortraitPtr, 0x10D);
            break;
        case 15:
            sKecleonBrosWork1->fallbackState = 18;
            SetKecleonPortraitSpriteId(FALSE);
            CreateDialogueBoxAndPortrait(gCommonKecleonBros[sKecleonBrosWork1->mode][KECLEON_DLG_03], 0, sKecleonBrosWork1->monPortraitPtr, 0x10D);
            break;
        case KECLEON_STORE_BUY_ITEM_MENU:
            sKecleonBrosWork1->fallbackState = 19;
            SetKecleonPortraitSpriteId(FALSE);
            CreateDialogueBoxAndPortrait(gCommonKecleonBros[sKecleonBrosWork1->mode][KECLEON_DLG_04], 0, sKecleonBrosWork1->monPortraitPtr, 0x10D);
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
            BuildKecleonBrosBuyItemMenu();
            sub_8012D60(&sKecleonBrosWork1->menu, sKecleonBrosWork1->menuItems, 0, sKecleonBrosWork1->unk74, sKecleonBrosWork1->menuAction3, 2);
            break;
        case KECLEON_STORE_BUY_ITEM:
            BuildKecleonBrosYesNoMenu();
            sub_8090E14(gFormatBuffer_Items[0], &sKecleonBrosWork1->soldItem, 0);
            gFormatArgs[0] = sKecleonBrosWork1->itemSellPrice;
            SetKecleonPortraitSpriteId(FALSE);
            CreateMenuDialogueBoxAndPortrait(gCommonKecleonBros[sKecleonBrosWork1->mode][KECLEON_DLG_05], 0, 5,sKecleonBrosWork1->menuItems, NULL, 4, 0, sKecleonBrosWork1->monPortraitPtr, 12);
            break;
        case KECLEON_STORE_BUY_ITEM_RECEIPT:
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
                    sKecleonBrosWork1->fallbackState = KECLEON_STORE_MAIN_MENU;
                }
                else
                    sKecleonBrosWork1->fallbackState = KECLEON_STORE_BUY_ITEM_MENU;
            }
            SetKecleonPortraitSpriteId(FALSE);
            CreateDialogueBoxAndPortrait(gCommonKecleonBros[sKecleonBrosWork1->mode][KECLEON_DLG_06], 0, sKecleonBrosWork1->monPortraitPtr, 0x10D);
            break;
        case 23:
            sKecleonBrosWork1->fallbackState = 26;
            SetKecleonPortraitSpriteId(FALSE);
            CreateDialogueBoxAndPortrait(gCommonKecleonBros[sKecleonBrosWork1->mode][KECLEON_DLG_07], 0, sKecleonBrosWork1->monPortraitPtr, 0x10D);
            break;
        case KECLEON_STORE_SELL_ITEM_MENU:
            sKecleonBrosWork1->fallbackState = 27;
            SetKecleonPortraitSpriteId(FALSE);
            CreateDialogueBoxAndPortrait(gCommonKecleonBros[sKecleonBrosWork1->mode][KECLEON_DLG_08], 0, sKecleonBrosWork1->monPortraitPtr, 0x10D);
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
            BuildKecleonBrosSellItemMenu();
            sub_8012D60(&sKecleonBrosWork1->menu, sKecleonBrosWork1->menuItems, 0, sKecleonBrosWork1->unk74, sKecleonBrosWork1->menuAction2, 2);
            break;
        case KECLEON_STORE_SELL_ITEM:
            BuildKecleonBrosYesNoMenu();
            sub_8090E14(gFormatBuffer_Items[0], &sKecleonBrosWork1->soldItem, NULL);
            gFormatArgs[0] = sKecleonBrosWork1->itemSellPrice;
            SetKecleonPortraitSpriteId(FALSE);
            CreateMenuDialogueBoxAndPortrait(gCommonKecleonBros[sKecleonBrosWork1->mode][KECLEON_DLG_09], 0, 5, sKecleonBrosWork1->menuItems, NULL, 4, 0, sKecleonBrosWork1->monPortraitPtr, 12);
            break;
        case KECLEON_STORE_BUY_ITEM_INFO:
        case KECLEON_STORE_SELL_ITEM_INFO:
            InitItemDescriptionWindow(&sKecleonBrosWork1->soldItem);
            break;
        case KECLEON_STORE_SELL_ITEM_RECEIPT:
            if (GetNumberOfFilledInventorySlots() == 0 || gTeamInventoryRef->teamMoney >= MAX_TEAM_MONEY) {
                sub_801A928();
                sKecleonBrosWork1->fallbackState = KECLEON_STORE_MAIN_MENU;
            }
            else
                sKecleonBrosWork1->fallbackState = KECLEON_STORE_SELL_ITEM_MENU;

            SetKecleonPortraitSpriteId(FALSE);
            CreateDialogueBoxAndPortrait(gCommonKecleonBros[sKecleonBrosWork1->mode][KECLEON_DLG_11], 0, sKecleonBrosWork1->monPortraitPtr, 0x10D);
            break;
        case KECLEON_STORE_SELL_ALL_ITEMS:
            BuildKecleonBrosYesNoMenu();
            gFormatArgs[0] = sKecleonBrosWork1->inventoryItemSellPrice;
            SetKecleonPortraitSpriteId(FALSE);
            CreateMenuDialogueBoxAndPortrait(gCommonKecleonBros[sKecleonBrosWork1->mode][KECLEON_DLG_10], 0, 5, sKecleonBrosWork1->menuItems, NULL, 4, 0, sKecleonBrosWork1->monPortraitPtr, 12);
            break;
        case KECLEON_STORE_SELL_ALL_ITEMS_RECEIPT:
            sKecleonBrosWork1->fallbackState = KECLEON_STORE_MAIN_MENU;
            SetKecleonPortraitSpriteId(FALSE);
            CreateDialogueBoxAndPortrait(gCommonKecleonBros[sKecleonBrosWork1->mode][KECLEON_DLG_11], 0, sKecleonBrosWork1->monPortraitPtr, 0x10D);
            break;
    }
}

static void BuildKecleonBrosMainMenu(void)
{
    s32 i;
    s32 loopMax;

    MemoryFill16(sKecleonBrosWork1->unk74, 0, sizeof(sKecleonBrosWork1->unk74));

    loopMax = 0;
    sKecleonBrosWork1->menuItems[loopMax].text = gCommonBuy[0];
    sKecleonBrosWork1->menuItems[loopMax].menuAction = BUY_ACTION;

    loopMax++;
    sKecleonBrosWork1->menuItems[loopMax].text = gCommonSell[0];
    sKecleonBrosWork1->menuItems[loopMax].menuAction = SELL_ACTION;

    loopMax++;
    sKecleonBrosWork1->menuItems[loopMax].text = sSellAll;
    sKecleonBrosWork1->menuItems[loopMax].menuAction = SELL_ALL_ACTION;

    loopMax++;
    sKecleonBrosWork1->menuItems[loopMax].text = gCommonInfo[0];
    sKecleonBrosWork1->menuItems[loopMax].menuAction = INFO_ACTION;

    loopMax++;
    sKecleonBrosWork1->menuItems[loopMax].text = gCommonCancel[0];
    sKecleonBrosWork1->menuItems[loopMax].menuAction = CANCEL_ACTION;

    loopMax++;
    sKecleonBrosWork1->menuItems[loopMax].text = NULL;
    sKecleonBrosWork1->menuItems[loopMax].menuAction = CANCEL_ACTION;

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

static void BuildKecleonBrosBuyItemMenu(void)
{
    s32 i;
    s32 loopMax;

    MemoryFill16(sKecleonBrosWork1->unk74, 0, sizeof(sKecleonBrosWork1->unk74));

    loopMax = 0;
    sKecleonBrosWork1->menuItems[loopMax].text = gCommonBuy[0];
    sKecleonBrosWork1->menuItems[loopMax].menuAction = BUY_ACTION;

    loopMax++;
    sKecleonBrosWork1->menuItems[loopMax].text = gCommonInfo[0];
    sKecleonBrosWork1->menuItems[loopMax].menuAction = INFO_ACTION;

    loopMax++;
    sKecleonBrosWork1->menuItems[loopMax].text = NULL;
    sKecleonBrosWork1->menuItems[loopMax].menuAction = CANCEL_ACTION;

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

static void BuildKecleonBrosSellItemMenu(void)
{
    s32 i;
    s32 loopMax;

    MemoryFill16(sKecleonBrosWork1->unk74, 0, sizeof(sKecleonBrosWork1->unk74));

    loopMax = 0;
    sKecleonBrosWork1->menuItems[loopMax].text = gCommonSell[0];
    sKecleonBrosWork1->menuItems[loopMax].menuAction = SELL_ACTION;

    loopMax++;
    sKecleonBrosWork1->menuItems[loopMax].text = gCommonInfo[0];
    sKecleonBrosWork1->menuItems[loopMax].menuAction = INFO_ACTION;

    loopMax++;
    sKecleonBrosWork1->menuItems[loopMax].text = NULL;
    sKecleonBrosWork1->menuItems[loopMax].menuAction = CANCEL_ACTION;

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

static void BuildKecleonBrosYesNoMenu(void)
{
    s32 loopMax = 0;
    sKecleonBrosWork1->menuItems[loopMax].text = gCommonYes[0];
    sKecleonBrosWork1->menuItems[loopMax].menuAction = YES_ACTION;

    loopMax++;
    sKecleonBrosWork1->menuItems[loopMax].text = gCommonNo[0];
    sKecleonBrosWork1->menuItems[loopMax].menuAction = NO_ACTION;

    loopMax++;
    sKecleonBrosWork1->menuItems[loopMax].text = NULL;
    sKecleonBrosWork1->menuItems[loopMax].menuAction = CANCEL_ACTION;
}

static void HandleKecleonBrosMainMenu(void)
{
    s32 menuAction;

    if (sub_80144A4(&menuAction) != 0)
        return;

    if (menuAction != CANCEL_ACTION)
        sKecleonBrosWork1->menuAction1 = menuAction;

    switch (menuAction) {
        case BUY_ACTION:
            if (CountKecleonItems() == 0)
                SetKecleonBrosState(KECLEON_STORE_NO_STORE_ITEMS);
            else if (GetNumberOfFilledInventorySlots() >= INVENTORY_SIZE)
                SetKecleonBrosState(KECLEON_STORE_TOO_MANY_ITEMS);
            else
                SetKecleonBrosState(15);
            break;
        case SELL_ACTION:
            if (GetNumberOfFilledInventorySlots() == 0)
                SetKecleonBrosState(KECLEON_STORE_NO_ITEMS);
            else if (sKecleonBrosWork1->numInventoryItemToSell == 0)
                SetKecleonBrosState(KECLEON_STORE_NO_ITEMS_TO_SELL);
            else if (gTeamInventoryRef->teamMoney < MAX_TEAM_MONEY)
                SetKecleonBrosState(23);
            else
                SetKecleonBrosState(KECLEON_STORE_TOO_MUCH_MONEY);
            break;
        case SELL_ALL_ACTION:
            if (GetNumberOfFilledInventorySlots() == 0)
                SetKecleonBrosState(KECLEON_STORE_NO_ITEMS);
            else if (sKecleonBrosWork1->numInventoryItemToSell == 0)
                SetKecleonBrosState(KECLEON_STORE_NO_ITEMS_TO_SELL);
            else if (sKecleonBrosWork1->inventoryItemSellPrice + gTeamInventoryRef->teamMoney > MAX_TEAM_MONEY)
                SetKecleonBrosState(KECLEON_STORE_TOO_MUCH_MONEY);
            else
                SetKecleonBrosState(KECLEON_STORE_SELL_ALL_ITEMS);
            break;
        case INFO_ACTION:
            SetKecleonBrosState(KECLEON_STORE_INFO);
            break;
        case CANCEL_ACTION:
            SetKecleonBrosState(3);
            break;
    }
}

static void HandleKecleonBrosBuyItemYesNoMenu(void)
{
    s32 menuAction;

    if (sub_80144A4(&menuAction) == 0) {
        switch (menuAction) {
            case YES_ACTION:
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
                SetKecleonBrosState(KECLEON_STORE_BUY_ITEM_RECEIPT);
                break;
            case NO_ACTION:
            case CANCEL_ACTION:
                SetKecleonBrosState(KECLEON_STORE_BUY_ITEM_MENU);
                break;
        }
    }
}

static void HandleKecleonBrosSellItemYesNoMenu(void)
{
    s32 menuAction;

    if (sub_80144A4(&menuAction) == 0) {
        switch (menuAction) {
            case YES_ACTION:
                AddToTeamMoney(sKecleonBrosWork1->itemSellPrice);
                ShiftItemsDownFrom(sKecleonBrosWork1->soldItemInventoryIndex);
                PlaySound(332);
                SetKecleonBrosState(KECLEON_STORE_SELL_ITEM_RECEIPT);
                break;
            case NO_ACTION:
            case CANCEL_ACTION:
                SetKecleonBrosState(KECLEON_STORE_SELL_ITEM_MENU);
                break;
        }
    }
}

static void HandleKecleonBrosSellAllItemsMenu(void)
{
    s32 slotIndex;
    s32 menuAction;
    Item *item;

    if (sub_80144A4(&menuAction) == 0) {
        switch (menuAction) {
            case YES_ACTION:
                for (slotIndex = 0; slotIndex < INVENTORY_SIZE; slotIndex++) {
                    item = &gTeamInventoryRef->teamItems[slotIndex];

                    if ((item->flags & ITEM_FLAG_EXISTS) && CanSellItem(item->id))
                        ClearItemSlotAt(slotIndex);
                }

                FillInventoryGaps();
                AddToTeamMoney(sKecleonBrosWork1->inventoryItemSellPrice);
                PlaySound(0x14c);
                SetKecleonBrosState(KECLEON_STORE_SELL_ALL_ITEMS_RECEIPT);
                break;
            case CANCEL_ACTION:
            case NO_ACTION:
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

            ItemIdToSlot(&sKecleonBrosWork1->soldItem, item->id, 0);
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

            ItemIdToSlot(&sKecleonBrosWork1->soldItem, item->id, 0);
            sKecleonBrosWork1->soldItem.quantity = item->quantity;
            sKecleonBrosWork1->itemSellPrice = GetStackBuyPrice(&sKecleonBrosWork1->soldItem);
            SetKecleonBrosState(KECLEON_STORE_BUY_ITEM_INFO);
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
            SetKecleonBrosState(KECLEON_STORE_SELL_ITEM_INFO);
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

static void HandleKecleonBrosBuyItemMenu(void)
{
    s32 menuAction;

    menuAction = 0;

    if (sKecleonBrosWork1->isKecleonItemShop)
        sub_8019EDC(FALSE);
    else
        sub_801A2A8(FALSE);

    if (sub_8012FD8(&sKecleonBrosWork1->menu) == 0 && (sub_8013114(&sKecleonBrosWork1->menu, &menuAction), menuAction != CANCEL_ACTION))
        sKecleonBrosWork1->menuAction3 = menuAction;

    switch (menuAction) {
        case BUY_ACTION:
            if (gTeamInventoryRef->teamMoney == 0)
                SetKecleonBrosState(KECLEON_STORE_NO_MONEY);
            else if (sKecleonBrosWork1->itemSellPrice > gTeamInventoryRef->teamMoney)
                SetKecleonBrosState(KECLEON_STORE_NOT_ENOUGH_MONEY);
            else
                SetKecleonBrosState(KECLEON_STORE_BUY_ITEM);
            break;
        case INFO_ACTION:
            SetKecleonBrosState(KECLEON_STORE_BUY_ITEM_INFO);
            break;
        case CANCEL_ACTION:
            SetKecleonBrosState(19);
            break;
    }
}

static void HandleKecleonBrosSellItemMenu(void)
{
    s32 menuAction;

    menuAction = 0;
    sub_801A6E8(FALSE);

    if (sub_8012FD8(&sKecleonBrosWork1->menu) == FALSE && (sub_8013114(&sKecleonBrosWork1->menu, &menuAction), menuAction != 1))
        sKecleonBrosWork1->menuAction2 = menuAction;

    switch (menuAction) {
        case SELL_ACTION:
            sub_8099690(0);

            if (!CanSellItem(sKecleonBrosWork1->soldItem.id))
                SetKecleonBrosState(KECLEON_STORE_CANT_SELL_ITEM);
            else if (sKecleonBrosWork1->itemSellPrice + gTeamInventoryRef->teamMoney > MAX_TEAM_MONEY)
                SetKecleonBrosState(KECLEON_STORE_SELL_ITEM_TOO_MUCH_MONEY);
            else
                SetKecleonBrosState(KECLEON_STORE_SELL_ITEM);
            break;
        case INFO_ACTION:
            sub_8099690(0);
            SetKecleonBrosState(KECLEON_STORE_SELL_ITEM_INFO);
            break;
        case CANCEL_ACTION:
            SetKecleonBrosState(27);
            break;
    }
}

static void sub_8019D30(void)
{
    switch (sub_801B410()) {
        case 2:
        case 3:
            FreeItemDescriptionWindow();
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
            FreeItemDescriptionWindow();
            SetKecleonBrosState(27);
            break;
        case 0:
        case 1:
            break;
    }
}

static void ProceedToKecleonBros1FallbackState(void)
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

static void KecleonCalcSellPriceForAllItems(void)
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

static void SetKecleonPortraitSpriteId(bool32 angrySprite)
{
    if (sKecleonBrosWork1->isKecleonItemShop) {
        if (angrySprite == TRUE)
            sKecleonBrosWork1->monPortrait.spriteId = 1;
        else
            sKecleonBrosWork1->monPortrait.spriteId = 0;
    }
    else {
        if (angrySprite == TRUE)
            sKecleonBrosWork1->monPortrait.spriteId = 7;
        else
            sKecleonBrosWork1->monPortrait.spriteId = 6;
    }
}
