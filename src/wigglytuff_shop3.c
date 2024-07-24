#include "global.h"
#include "globaldata.h"
#include "code_80118A4.h"
#include "code_80130A8.h"
#include "code_8023144.h"
#include "code_8098BDC.h"
#include "common_strings.h"
#include "event_flag.h"
#include "felicity_bank.h"
#include "friend_area.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "pokemon.h"
#include "text1.h"
#include "text2.h"
#include "wigglytuff_shop1.h"
#include "wigglytuff_shop2.h"
#include "wigglytuff_shop3.h"

extern u32 gFormatData_202DE30[2];
extern u8 gAvailablePokemonNames[]; // 202DF98
extern u8 gUnknown_202E1C8[];
extern u8 gUnknown_202E5D8[];
extern u8 gUnknown_202E628[];

static EWRAM_DATA_2 WigglytuffShop3Work *sWigglytuffShop3Work = {0};

#include "data/wigglytuff_shop3.h"

enum menuActions {
    CANCEL_ACTION = 1,
    BUY_ACTION,
    CHECK_ACTION,
    INFO_ACTION,
    YES_ACTION,
    NO_ACTION
};

static void CreateWigglytuffConfirmFriendAreaMenu(void);
static void HandleWigglytuffConfirmFriendAreaMenu(void);
static void SetWigglytuffState(s32 newState);
static void UpdateWigglytuffDialogue(void);

static void sub_8021D5C(void);
static void sub_80222C8(void);
static void sub_8022380(void);
static void sub_8022460(void);
static void sub_8022538(void);
static void sub_80225C8(void);
static void sub_8022668(void);
static void sub_8022684(void);
static void WigglytuffShop_GoToFallbackState(void);
static void sub_80226F0(void);
static void sub_8022790(void);

bool8 CreateWigglytuffShop(u32 mode)
{
    u8 *str;
    OpenedFile *file;

    ResetUnusedInputStruct();
    sub_800641C(NULL, TRUE, TRUE);

    sWigglytuffShop3Work = MemoryAlloc(sizeof(WigglytuffShop3Work), 8);
    sWigglytuffShop3Work->menuAction1 = 0;
    sWigglytuffShop3Work->menuAction2 = 0;
    sWigglytuffShop3Work->mode = mode;
    CopyYellowMonsterNametoBuffer(gUnknown_202E5D8, MONSTER_WIGGLYTUFF);
    CopyYellowMonsterNametoBuffer(gUnknown_202E1C8, MONSTER_WIGGLYTUFF);
    str = GetMonSpecies(MONSTER_WIGGLYTUFF);
    strcpy(gUnknown_202E1C8 - 80, str);

    if (sWigglytuffShop3Work->mode == 1)
        sWigglytuffShop3Work->unkCC = NULL;
    else
        sWigglytuffShop3Work->unkCC = &sWigglytuffShop3Work->faceFile;

    file = GetDialogueSpriteDataPtr(MONSTER_WIGGLYTUFF);
    sWigglytuffShop3Work->faceFile = file;
    sWigglytuffShop3Work->faceData = file->data;
    sWigglytuffShop3Work->unkC8 = 0;
    sWigglytuffShop3Work->unkC9 = 0;
    sWigglytuffShop3Work->unkCA = 0;
    sWigglytuffShop3Work->unkC4 = 2;
    sWigglytuffShop3Work->unkC6 = 8;
    SetWigglytuffState(WIGGLYTUFF_INIT);
    return TRUE;
}

u32 sub_8021C5C(void)
{
    switch (sWigglytuffShop3Work->state) {
        case WIGGLYTUFF_INIT:
        case WIGGLYTUFF_MAIN_MENU:
            sub_8022460();
            break;
        case WIGGLYTUFF_UNK9:
        case WIGGLYTUFF_UNKA:
            sub_8022538();
            break;
        case WIGGLYTUFF_UNKB:
            sub_80225C8();
            break;
        case BUY_FRIEND_AREA:
            HandleWigglytuffConfirmFriendAreaMenu();
            break;
        case WIGGLYTUFF_UNKD:
            sub_80226F0();
            break;
        case WIGGLYTUFF_UNKE:
            sub_8022790();
            break;
        case FRIEND_AREA_INFO:
            sub_8022668();
            break;
        case WIGGLYTUFF_UNK16:
        case WIGGLYTUFF_UNK17:
            sub_8022684();
            break;
        case WIGGLYTUFF_EXIT:
            return 3;
        default:
            WigglytuffShop_GoToFallbackState();
            break;
    }
    return 0;
}

void CleanWigglytuffShop(void)
{
    if (sWigglytuffShop3Work) {
        CloseFile(sWigglytuffShop3Work->faceFile);
        MemoryFree(sWigglytuffShop3Work);
        sWigglytuffShop3Work = NULL;
    }
}

static void SetWigglytuffState(s32 newState)
{
    sWigglytuffShop3Work->state = newState;
    sub_8021D5C();
    UpdateWigglytuffDialogue();
}

static void sub_8021D5C(void)
{
    s32 i;

    sub_8006518(sWigglytuffShop3Work->unkD0);

    switch (sWigglytuffShop3Work->state) {
        case WIGGLYTUFF_UNK9:
        case WIGGLYTUFF_UNKA:
            sWigglytuffShop3Work->unkD0[0] = sUnknown_80DC534;
            sWigglytuffShop3Work->unkD0[2] = sUnknown_80DC534;
            sWigglytuffShop3Work->unkD0[1] = sUnknown_80DC564;
            break;
        case WIGGLYTUFF_UNKB:
            sWigglytuffShop3Work->unkD0[2] = sUnknown_80DC54C;
            break;
        default:
            for (i = 0; i < 4; i++)
                sWigglytuffShop3Work->unkD0[i] = sUnknown_80DC534;
            break;
    }

    ResetUnusedInputStruct();
    sub_800641C(sWigglytuffShop3Work->unkD0, TRUE, TRUE);
}

static void UpdateWigglytuffDialogue(void)
{
    u8 *string;
    unkStruct_8092638 uStack_14;

    switch (sWigglytuffShop3Work->state) {
        case WIGGLYTUFF_INIT:
            sub_80222C8();
            sub_8014248(gCommonWigglytuff[sWigglytuffShop3Work->mode][WIGGLY_DLG_00], 0, sWigglytuffShop3Work->menuAction1, sWigglytuffShop3Work->unk1C, sWigglytuffShop3Work->unk5C, 4, 0, sWigglytuffShop3Work->unkCC, 12);
            break;
        case WIGGLYTUFF_MAIN_MENU:
            sub_80222C8();
            sub_8014248(gCommonWigglytuff[sWigglytuffShop3Work->mode][WIGGLY_DLG_01], 0, sWigglytuffShop3Work->menuAction1, sWigglytuffShop3Work->unk1C, sWigglytuffShop3Work->unk5C, 4, 0, sWigglytuffShop3Work->unkCC, 12);
            break;
        case FRIEND_AREA_SELECT_BUY:
            sWigglytuffShop3Work->fallbackState = WIGGLYTUFF_UNK9;
            sub_80141B4(gCommonWigglytuff[sWigglytuffShop3Work->mode][WIGGLY_DLG_03], 0, sWigglytuffShop3Work->unkCC, 0x10d);
            break;
        case FRIEND_AREA_SELECT_BUY_AGAIN:
            sWigglytuffShop3Work->fallbackState = WIGGLYTUFF_UNKA;
            sub_80141B4(gCommonWigglytuff[sWigglytuffShop3Work->mode][WIGGLY_DLG_04], 0, sWigglytuffShop3Work->unkCC, 0x10d);
            break;
        case WIGGLYTUFF_INFO:
            sWigglytuffShop3Work->fallbackState = WIGGLYTUFF_MAIN_MENU;
            sub_80141B4(gCommonWigglytuff[sWigglytuffShop3Work->mode][WIGGLY_DLG_19], 0, sWigglytuffShop3Work->unkCC, 0x10d);
            break;
        case WIGGLYTUFF_PRE_EXIT:
            sWigglytuffShop3Work->fallbackState = WIGGLYTUFF_EXIT;
            sub_80141B4(gCommonWigglytuff[sWigglytuffShop3Work->mode][WIGGLY_DLG_02], 0, sWigglytuffShop3Work->unkCC, 0x30d);
            break;
        default:
            break;
        case WIGGLYTUFF_CANT_ADD_FRIEND_AREA:
            sWigglytuffShop3Work->fallbackState = WIGGLYTUFF_PRE_EXIT;
            sub_80141B4(gCommonWigglytuff[sWigglytuffShop3Work->mode][WIGGLY_DLG_08], 0, sWigglytuffShop3Work->unkCC, 0x10d);
            break;
        case NO_MONEY:
            sWigglytuffShop3Work->fallbackState = WIGGLYTUFF_UNKA;
            sub_80141B4(gCommonWigglytuff[sWigglytuffShop3Work->mode][WIGGLY_DLG_09], 0, sWigglytuffShop3Work->unkCC, 0x10d);
            break;
        case NO_FRIEND_AREAS:
            sWigglytuffShop3Work->fallbackState = WIGGLYTUFF_PRE_EXIT;
            sub_80141B4(gCommonWigglytuff[sWigglytuffShop3Work->mode][WIGGLY_DLG_10], 0, sWigglytuffShop3Work->unkCC, 0x10d);
            break;
        case NOT_ENOUGH_MONEY:
            sWigglytuffShop3Work->fallbackState = WIGGLYTUFF_UNKA;
            sub_80141B4(gCommonWigglytuff[sWigglytuffShop3Work->mode][WIGGLY_DLG_11], 0, sWigglytuffShop3Work->unkCC, 0x10d);
            break;
        case WIGGLYTUFF_UNK9:
            sub_80211AC(2, 3);
            DrawTeamMoneyBox(1);
            break;
        case WIGGLYTUFF_UNKA:
            sub_8021354(TRUE);
            DrawTeamMoneyBox(1);
            break;
        case WIGGLYTUFF_UNKB:
            sub_8021494();
            DrawTeamMoneyBox(1);
            sub_8022380();
            sub_8012D60(&sWigglytuffShop3Work->unk6C, sWigglytuffShop3Work->unk1C, 0, sWigglytuffShop3Work->unk5C, sWigglytuffShop3Work->menuAction2, 2);
            break;
        case BUY_FRIEND_AREA:
            CreateWigglytuffConfirmFriendAreaMenu();
            sub_8092578(gUnknown_202E628, sWigglytuffShop3Work->chosenFriendArea, FALSE);
            gFormatData_202DE30[0] = sWigglytuffShop3Work->friendAreaPrice;
            sub_8014248(gCommonWigglytuff[sWigglytuffShop3Work->mode][WIGGLY_DLG_05], 0, 5, sWigglytuffShop3Work->unk1C, 0, 4, 0, sWigglytuffShop3Work->unkCC, 12);
            break;
        case FRIEND_AREA_INFO:
            CreateWigglytuffShopFriendAreaMenu(sWigglytuffShop3Work->chosenFriendArea, FALSE, 2);
            break;
        case CONFIRM_BUY_FRIEND_AREA:
            sWigglytuffShop3Work->fallbackState = WIGGLYTUFF_UNKD;
            sub_8092578(gUnknown_202E628, sWigglytuffShop3Work->chosenFriendArea, FALSE);
            sub_80141B4(gCommonWigglytuff[sWigglytuffShop3Work->mode][WIGGLY_DLG_06], 0, sWigglytuffShop3Work->unkCC, 0x10d);
            break;
        case WIGGLYTUFF_UNKD:
            sWigglytuffShop3Work->fallbackState = WIGGLYTUFF_UNKE;
            PlaySound(603);
            sWigglytuffShop3Work->unk130 = 1;
            break;
        case WIGGLYTUFF_UNKE:
            sWigglytuffShop3Work->fallbackState = FRIEND_AREA_UNLOCKED;
            sWigglytuffShop3Work->unk134 = 30;
            break;
        case FRIEND_AREA_UNLOCKED:
            if (sub_8021700(2)) {
                sub_80213A0();
                sWigglytuffShop3Work->fallbackState = NO_FRIEND_AREAS;
            }
            else
                sWigglytuffShop3Work->fallbackState = FRIEND_AREA_SELECT_BUY_AGAIN;

            PlaySound(206);
            sub_80141B4(gCommonWigglytuff[sWigglytuffShop3Work->mode][WIGGLY_DLG_07], 0, sWigglytuffShop3Work->unkCC, 0x10d);
            break;
        case WIGGLYTUFF_CHECK:
            sWigglytuffShop3Work->fallbackState = WIGGLYTUFF_UNK16;
            sub_80141B4(gCommonWigglytuff[sWigglytuffShop3Work->mode][WIGGLY_DLG_12], 0, sWigglytuffShop3Work->unkCC, 0x10d);
            break;
        case WIGGLYTUFF_CHECK_AGAIN:
            sWigglytuffShop3Work->fallbackState = WIGGLYTUFF_UNK17;
            sub_80141B4(gCommonWigglytuff[sWigglytuffShop3Work->mode][WIGGLY_DLG_13], 0, sWigglytuffShop3Work->unkCC, 0x10d);
            break;
        case WIGGLYTUFF_UNK16:
            sub_8023144(0, 3, 0, 10);
            break;
        case WIGGLYTUFF_UNK17:
            sub_8023354(TRUE);
            break;
        case DISPLAY_POKEMON_FRIEND_AREA_INFO:
            sub_8092638(sWigglytuffShop3Work->chosenFriendArea, &uStack_14, FALSE, FALSE);

            if (uStack_14.hasFriendArea)
                sWigglytuffShop3Work->fallbackState = WIGGLYTUFF_CHECK_HAS_FRIEND_AREA;
            else {
                switch (GetFriendAreaUnlockCondition(sWigglytuffShop3Work->chosenFriendArea)) {
                    case UNLOCK_SHOP_POST_GAME:
                        if (sub_80023E4(6) != 0)
                            sWigglytuffShop3Work->fallbackState = WIGGLYTUFF_CHECK_AGAIN;
                        else
                            sWigglytuffShop3Work->fallbackState = WIGGLYTUFF_CHECK_POST_GAME;
                        break;
                    case UNLOCK_WONDER_MAIL:
                        sWigglytuffShop3Work->fallbackState = WIGGLYTUFF_CHECK_WONDER_MAIL;
                        break;
                    case UNLOCK_LEGENDARY_REQUEST:
                        sWigglytuffShop3Work->fallbackState = WIGGLYTUFF_CHECK_LEGENDARY;
                        break;
                    default:
                        sWigglytuffShop3Work->fallbackState = WIGGLYTUFF_CHECK_AGAIN;
                        break;
                }
            }

            string = GetMonSpecies(sWigglytuffShop3Work->chosenSpecies);
            strcpy(gAvailablePokemonNames, string);
            sub_8092578(gUnknown_202E628, sWigglytuffShop3Work->chosenFriendArea, FALSE);
            sub_80141B4(gCommonWigglytuff[sWigglytuffShop3Work->mode][WIGGLY_DLG_14], 0, sWigglytuffShop3Work->unkCC, 0x10d);
            break;
        case WIGGLYTUFF_CHECK_HAS_FRIEND_AREA:
            sWigglytuffShop3Work->fallbackState = WIGGLYTUFF_CHECK_AGAIN;
            sub_80141B4(gCommonWigglytuff[sWigglytuffShop3Work->mode][WIGGLY_DLG_15], 0, sWigglytuffShop3Work->unkCC, 0x10d);
            break;
        case WIGGLYTUFF_CHECK_POST_GAME:
            sWigglytuffShop3Work->fallbackState = WIGGLYTUFF_CHECK_AGAIN;
            sub_80141B4(gCommonWigglytuff[sWigglytuffShop3Work->mode][WIGGLY_DLG_16], 0, sWigglytuffShop3Work->unkCC, 0x10d);
            break;
        case WIGGLYTUFF_CHECK_WONDER_MAIL:
            sWigglytuffShop3Work->fallbackState = WIGGLYTUFF_CHECK_AGAIN;
            sub_80141B4(gCommonWigglytuff[sWigglytuffShop3Work->mode][WIGGLY_DLG_17], 0, sWigglytuffShop3Work->unkCC, 0x10d);
            break;
        case WIGGLYTUFF_CHECK_LEGENDARY:
            sWigglytuffShop3Work->fallbackState = WIGGLYTUFF_CHECK_AGAIN;
            sub_80141B4(gCommonWigglytuff[sWigglytuffShop3Work->mode][WIGGLY_DLG_18], 0, sWigglytuffShop3Work->unkCC, 0x10d);
            break;
    }
}

static void sub_80222C8(void)
{
    s32 i;
    s32 index = 0;

    MemoryFill16(sWigglytuffShop3Work->unk5C, 0, sizeof(sWigglytuffShop3Work->unk5C));

    sWigglytuffShop3Work->unk1C[index].text = gCommonBuy[0];
    sWigglytuffShop3Work->unk1C[index].menuAction = BUY_ACTION;

    index++;
    sWigglytuffShop3Work->unk1C[index].text = gCommonCheck[0];
    sWigglytuffShop3Work->unk1C[index].menuAction = CHECK_ACTION;

    index++;
    sWigglytuffShop3Work->unk1C[index].text = gCommonInfo[0];
    sWigglytuffShop3Work->unk1C[index].menuAction = INFO_ACTION;

    index++;
    sWigglytuffShop3Work->unk1C[index].text = gCommonCancel[0];
    sWigglytuffShop3Work->unk1C[index].menuAction = CANCEL_ACTION;

    index++;
    sWigglytuffShop3Work->unk1C[index].text = NULL;
    sWigglytuffShop3Work->unk1C[index].menuAction = CANCEL_ACTION;

    for (i = 0; i < index; i++) {
        if (sWigglytuffShop3Work->unk5C[i] == 0 && sWigglytuffShop3Work->unk1C[i].menuAction == sWigglytuffShop3Work->menuAction1)
            return;
    }

    for (i = 0; i < index; i++) {
        if (sWigglytuffShop3Work->unk5C[i] == 0) {
            sWigglytuffShop3Work->menuAction1 = sWigglytuffShop3Work->unk1C[i].menuAction;
            break;
        }
    }
}

static void sub_8022380(void)
{
    s32 i;
    s32 index = 0;

    MemoryFill16(sWigglytuffShop3Work->unk5C, 0, sizeof(sWigglytuffShop3Work->unk5C));

    sWigglytuffShop3Work->unk1C[index].text = gCommonBuy[0];
    sWigglytuffShop3Work->unk1C[index].menuAction = BUY_ACTION;

    index++;
    sWigglytuffShop3Work->unk1C[index].text = gCommonInfo[0];
    sWigglytuffShop3Work->unk1C[index].menuAction = INFO_ACTION;

    index++;
    sWigglytuffShop3Work->unk1C[index].text = NULL;
    sWigglytuffShop3Work->unk1C[index].menuAction = CANCEL_ACTION;

    for (i = 0; i < index; i++) {
        if (sWigglytuffShop3Work->unk5C[i] == 0 && sWigglytuffShop3Work->unk1C[i].menuAction == sWigglytuffShop3Work->menuAction2)
            return;
    }

    for (i = 0; i < index; i++) {
        if (sWigglytuffShop3Work->unk5C[i] == 0) {
            sWigglytuffShop3Work->menuAction2 = sWigglytuffShop3Work->unk1C[i].menuAction;
            break;
        }
    }
}

static void CreateWigglytuffConfirmFriendAreaMenu(void)
{
    s32 index = 0;

    MemoryFill16(sWigglytuffShop3Work->unk5C, 0, sizeof(sWigglytuffShop3Work->unk5C));

    sWigglytuffShop3Work->unk1C[index].text = gCommonYes[0];
    sWigglytuffShop3Work->unk1C[index].menuAction = YES_ACTION;

    index++;
    sWigglytuffShop3Work->unk1C[index].text = gCommonNo[0];
    sWigglytuffShop3Work->unk1C[index].menuAction = NO_ACTION;

    index++;
    sWigglytuffShop3Work->unk1C[index].text = NULL;
    sWigglytuffShop3Work->unk1C[index].menuAction = CANCEL_ACTION;
}

static void sub_8022460(void)
{
    s32 menuAction;

    if (sub_80144A4(&menuAction) != 0)
        return;

    if (menuAction != CANCEL_ACTION)
        sWigglytuffShop3Work->menuAction1 = menuAction;

    switch (menuAction) {
        case BUY_ACTION:
            if (sub_8021700(2))
                SetWigglytuffState(WIGGLYTUFF_CANT_ADD_FRIEND_AREA);
            else
                SetWigglytuffState(FRIEND_AREA_SELECT_BUY);
            break;
        case CHECK_ACTION:
            SetWigglytuffState(WIGGLYTUFF_CHECK);
            break;
        case INFO_ACTION:
            SetWigglytuffState(WIGGLYTUFF_INFO);
            break;
        case CANCEL_ACTION:
            SetWigglytuffState(WIGGLYTUFF_PRE_EXIT);
            break;
    }
}

static void HandleWigglytuffConfirmFriendAreaMenu(void)
{
    s32 menuAction;

    if (sub_80144A4(&menuAction) != 0)
        return;

    switch (menuAction) {
        case YES_ACTION:
            gTeamInventoryRef->teamMoney -= sWigglytuffShop3Work->friendAreaPrice;
            UnlockFriendArea(sWigglytuffShop3Work->chosenFriendArea);
            PlaySound(332);
            SetWigglytuffState(CONFIRM_BUY_FRIEND_AREA);
            break;
        case CANCEL_ACTION:
        case NO_ACTION:
            SetWigglytuffState(WIGGLYTUFF_UNKA);
            break;
    }
}

static void sub_8022538(void)
{
    switch (sub_8021274(TRUE)) {
        case 3:
            sWigglytuffShop3Work->chosenFriendArea = sub_802132C();
            sWigglytuffShop3Work->friendAreaPrice = GetFriendAreaPrice(sWigglytuffShop3Work->chosenFriendArea);
            SetWigglytuffState(WIGGLYTUFF_UNKB);
            break;
        case 4:
            sWigglytuffShop3Work->chosenFriendArea = sub_802132C();
            sWigglytuffShop3Work->friendAreaPrice = GetFriendAreaPrice(sWigglytuffShop3Work->chosenFriendArea);
            SetWigglytuffState(FRIEND_AREA_INFO);
            break;
        case 0:
            break;
        case 2:
            sub_80213A0();
            SetWigglytuffState(WIGGLYTUFF_MAIN_MENU);
            break;
        case 1:
        default:
            DrawTeamMoneyBox(1);
            break;
    }
}

static void sub_80225C8(void)
{
    s32 menuAction = 0;

    sub_8021274(FALSE);

    if (sub_8012FD8(&sWigglytuffShop3Work->unk6C) == 0) {
        sub_8013114(&sWigglytuffShop3Work->unk6C, &menuAction);

        if (menuAction != 1)
            sWigglytuffShop3Work->menuAction2 = menuAction;
    }

    switch (menuAction) {
        case BUY_ACTION:
            if (gTeamInventoryRef->teamMoney == 0)
                SetWigglytuffState(NO_MONEY);
            else if (sWigglytuffShop3Work->friendAreaPrice > gTeamInventoryRef->teamMoney)
                SetWigglytuffState(NOT_ENOUGH_MONEY);
            else
                SetWigglytuffState(BUY_FRIEND_AREA);
            break;
        case INFO_ACTION:
            SetWigglytuffState(FRIEND_AREA_INFO);
            break;
        case CANCEL_ACTION:
            SetWigglytuffState(WIGGLYTUFF_UNKA);
            break;
    }
}

static void sub_8022668(void)
{
    switch (HandleWigglytuffShopFriendAreaMenuInput()) {
        case 2:
        case 3:
            CleanWigglytuffShopFriendAreaInfoMenu();
            SetWigglytuffState(WIGGLYTUFF_UNKA);
            break;
        case 0:
        case 1:
            break;
    }
}

static void sub_8022684(void)
{
    switch (sub_8023278(TRUE)) {
        case 3:
            sWigglytuffShop3Work->chosenSpecies = sub_802331C();
            sWigglytuffShop3Work->chosenFriendArea = GetFriendArea(sWigglytuffShop3Work->chosenSpecies);
            SetWigglytuffState(DISPLAY_POKEMON_FRIEND_AREA_INFO);
            break;
        case 2:
            sub_80233A0();
            SetWigglytuffState(WIGGLYTUFF_MAIN_MENU);
            break;
        case 0:
        case 1:
            break;
    }
}

static void WigglytuffShop_GoToFallbackState(void)
{
    s32 temp;

    if (sub_80144A4(&temp) == 0)
        SetWigglytuffState(sWigglytuffShop3Work->fallbackState);
}

static void sub_80226F0(void)
{
    union {
        vu32 a;
        vu8 b[4];
    } temp;

    vu8 *ptr = temp.b;
    u32 r2 = 0;
    ptr[0] = 0x80;
    ptr[1] = 0x80;
    ptr[2] = 0x10;
    ptr[3] = r2;

    if (sub_8099B94())
        return;

    switch (sWigglytuffShop3Work->unk130) {
        case 1:
        case 3:
            sub_8099AFC(5, 2, temp.a);
            break;
        case 2:
        case 4:
            sub_8099A5C(5, 2, temp.a);
            break;
        case 0:
        default:
            SetWigglytuffState(sWigglytuffShop3Work->fallbackState);
            sWigglytuffShop3Work->unk130 = 0;
            break;
    }

    sWigglytuffShop3Work->unk130++;
}

static void sub_8022790(void)
{
    if (sWigglytuffShop3Work->unk134 != 0)
        sWigglytuffShop3Work->unk134--;
    else
        SetWigglytuffState(sWigglytuffShop3Work->fallbackState);
}
