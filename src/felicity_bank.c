#include "global.h"
#include "globaldata.h"
#include "code_80118A4.h"
#include "string_format.h"
#include "common_strings.h"
#include "felicity_bank.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "pokemon.h"
#include "text1.h"
#include "text2.h"

static EWRAM_DATA_2 FelicityBankWork *sFelicityBankWork = {0};

extern u8 gSpeakerNameBuffer[];

#include "data/felicity_bank.h"

static void CreateFelicityBankShopMenu(void);
static void CreateFelicityMoneySavingsHeader(u32);
static void Felicity_DepositMoney(void);
static void Felicity_WithdrawMoney(void);
static void UpdateFelicityBankDialogue(void);
static void UpdateFelicityBankState(u32 newState);

static void sub_801645C(void);
static void HandleFelicityBankShopMenu(void);
static void sub_8016B00(void);
static void sub_8016B24(void);
static void sub_8016B48(u8 action);

enum MenuActions {
    CANCEL_ACTION = 1,
    STORE_ACTION,
    TAKE_ACTION,
    INFO_ACTION
};

enum FelicityBankStates {
    FELICITY_BANK_INIT,
    FELICITY_BANK_INFO = 3,
    FELICITY_BANK_EXIT = 6,
    FELICITY_BANK_STORE,
    FELICITY_BANK_STORE_HOW_MUCH,
    FELICITY_BANK_STORE_RECEIPT,
    FELICITY_BANK_TAKE,
    FELICITY_BANK_TAKE_HOW_MUCH,
    FELICITY_BANK_TAKE_DEPOSIT,
};

bool8 CreateFelicityBank(s32 mode)
{
    u8 *monName;
    OpenedFile *faceFile;

    ResetUnusedInputStruct();
    xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
    sFelicityBankWork = MemoryAlloc(sizeof(FelicityBankWork), 8);
    sFelicityBankWork->menuAction = 0;
    sFelicityBankWork->mode = mode;
    CopyYellowMonsterNametoBuffer(gSpeakerNameBuffer, MONSTER_PERSIAN);
    CopyYellowMonsterNametoBuffer(gFormatBuffer_Monsters[7], MONSTER_PERSIAN);
    monName = GetMonSpecies(MONSTER_PERSIAN);
    strcpy(gFormatBuffer_Monsters[6], monName);

    if (sFelicityBankWork->mode == FEL_MODE_ASLEEP)
        sFelicityBankWork->monPortraitPtr = NULL;
    else
        sFelicityBankWork->monPortraitPtr = &sFelicityBankWork->monPortrait;

    faceFile = GetDialogueSpriteDataPtr(MONSTER_PERSIAN);
    sFelicityBankWork->monPortrait.faceFile = faceFile;
    sFelicityBankWork->monPortrait.faceData = (struct PortraitGfx *) faceFile->data;
    sFelicityBankWork->monPortrait.spriteId = 0;
    sFelicityBankWork->monPortrait.flip = FALSE;
    sFelicityBankWork->monPortrait.unkE = 0;
    sFelicityBankWork->monPortrait.pos.x = 2;
    sFelicityBankWork->monPortrait.pos.y = 8;
    UpdateFelicityBankState(FELICITY_BANK_INIT);
    return TRUE;
}

u32 FelicityBankCallback(void)
{
    switch (sFelicityBankWork->currState) {
        case 1:
            sub_8016B24();
            break;
        case 2:
            HandleFelicityBankShopMenu();
            break;
        case FELICITY_BANK_STORE_HOW_MUCH:
            Felicity_DepositMoney();
            break;
        case FELICITY_BANK_TAKE_HOW_MUCH:
            Felicity_WithdrawMoney();
            break;
        case FELICITY_BANK_EXIT:
            return 3;
        case FELICITY_BANK_INIT:
        case FELICITY_BANK_INFO:
        case 4:
        case 5:
        case FELICITY_BANK_STORE:
        case FELICITY_BANK_STORE_RECEIPT:
        case FELICITY_BANK_TAKE:
        case FELICITY_BANK_TAKE_DEPOSIT:
        default:
            sub_8016B00();
            break;
    }
    return 0;
}

void DestroyFelicityBank(void)
{
    if (sFelicityBankWork != NULL) {
        CloseFile(sFelicityBankWork->monPortrait.faceFile);
        MemoryFree(sFelicityBankWork);
        sFelicityBankWork = NULL;
    }
}

static void UpdateFelicityBankState(u32 newState)
{
    sFelicityBankWork->currState = newState;
    sub_801645C();
    UpdateFelicityBankDialogue();
}

static void sub_801645C(void)
{
    s32 i;

    RestoreUnkTextStruct_8006518(sFelicityBankWork->unkA8);

    switch (sFelicityBankWork->currState) {
        case 2:
            sFelicityBankWork->unkA8[0].unk0 = 0x80;
            sFelicityBankWork->unkA8[1].unk0 = 0x80;
            sFelicityBankWork->unkA8[2].unk0 = 0x80;
            sFelicityBankWork->unkA8[3] = sUnknown_80DB6F4;
            ResetUnusedInputStruct();
            xxx_call_save_unk_text_struct_800641C(sFelicityBankWork->unkA8, TRUE, FALSE);
            break;
        case FELICITY_BANK_STORE_HOW_MUCH:
        case FELICITY_BANK_TAKE_HOW_MUCH:
            sFelicityBankWork->unkA8[0].unk0 = 0x80;
            sFelicityBankWork->unkA8[1].unk0 = 0x80;
            sFelicityBankWork->unkA8[3] = sUnknown_80DB6F4;
            sFelicityBankWork->unkA8[2] = sUnknown_80DB70C;
            ResetUnusedInputStruct();
            xxx_call_save_unk_text_struct_800641C(sFelicityBankWork->unkA8, TRUE, FALSE);
            break;
        default:
            for (i = 0; i < 4; i++)
                sFelicityBankWork->unkA8[i] = sUnknown_80DB6DC;

            ResetUnusedInputStruct();
            xxx_call_save_unk_text_struct_800641C(sFelicityBankWork->unkA8, TRUE, TRUE);
            break;
    }
}

static void UpdateFelicityBankDialogue(void)
{
    switch (sFelicityBankWork->currState) {
        case FELICITY_BANK_INIT:
            sFelicityBankWork->fallbackState = 1;
            CreateDialogueBoxAndPortrait(gCommonFelicity[sFelicityBankWork->mode][FEL_DLG_WELCOME], 0, sFelicityBankWork->monPortraitPtr, 0x10D);
            break;
        case 1:
            CreateFelicityBankShopMenu();
            sFelicityBankWork->fallbackState = 2;
            if (gTeamInventoryRef->teamSavings == 0)
                CreateMenuDialogueBoxAndPortrait(gCommonFelicity[sFelicityBankWork->mode][FEL_DLG_HOW_MAY_I_SERVE__NO_MONEY], 0, sFelicityBankWork->menuAction,
                    sFelicityBankWork->unk14, sFelicityBankWork->unk54, 4, 0, sFelicityBankWork->monPortraitPtr, 0xC);
            else {
                gFormatArgs[0] = gTeamInventoryRef->teamSavings;
                CreateMenuDialogueBoxAndPortrait(gCommonFelicity[sFelicityBankWork->mode][FEL_DLG_HOW_MAY_I_SERVE__HAS_MONEY], 0, sFelicityBankWork->menuAction,
                    sFelicityBankWork->unk14, sFelicityBankWork->unk54, 4, 0, sFelicityBankWork->monPortraitPtr, 0xC);
            }
            break;
        case FELICITY_BANK_INFO:
            sFelicityBankWork->fallbackState = 1;
            CreateDialogueBoxAndPortrait(gCommonFelicity[sFelicityBankWork->mode][FEL_DLG_HOW_IT_WORKS], 0, sFelicityBankWork->monPortraitPtr, 0x10D);
            break;
        case 4:
            sFelicityBankWork->fallbackState = FELICITY_BANK_EXIT;
            if (gTeamInventoryRef->teamSavings == 0)
                CreateDialogueBoxAndPortrait(gCommonFelicity[sFelicityBankWork->mode][FEL_DLG_BYE__NO_MONEY], 0, sFelicityBankWork->monPortraitPtr, 0x10D);
            else {
                gFormatArgs[0] = gTeamInventoryRef->teamSavings;
                CreateDialogueBoxAndPortrait(gCommonFelicity[sFelicityBankWork->mode][FEL_DLG_BYE__HAS_MONEY], 0, sFelicityBankWork->monPortraitPtr, 0x10D);
            }
            break;
        case 5:
            sFelicityBankWork->fallbackState = 1;
            CreateDialogueBoxAndPortrait(gCommonFelicity[sFelicityBankWork->mode][FEL_DLG_VERY_WELL], 0, sFelicityBankWork->monPortraitPtr, 0x10D);
            break;
        case FELICITY_BANK_STORE:
            if (gTeamInventoryRef->teamMoney == 0) {
                sFelicityBankWork->fallbackState = 1;
                CreateDialogueBoxAndPortrait(gCommonFelicity[sFelicityBankWork->mode][FEL_DLG_DEPOSIT__NO_MONEY], 0, sFelicityBankWork->monPortraitPtr, 0x10D);
            }
            else if (gTeamInventoryRef->teamSavings >= MAX_TEAM_SAVINGS) {
                sFelicityBankWork->fallbackState = 1;
                CreateDialogueBoxAndPortrait(gCommonFelicity[sFelicityBankWork->mode][FEL_DLG_DEPOSIT__BANK_FULL], 0, sFelicityBankWork->monPortraitPtr, 0x10D);
            }
            else {
                sFelicityBankWork->fallbackState = FELICITY_BANK_STORE_HOW_MUCH;
                CreateDialogueBoxAndPortrait(gCommonFelicity[sFelicityBankWork->mode][FEL_DLG_DEPOSIT__HOW_MUCH], 0, sFelicityBankWork->monPortraitPtr, 0x10D);
            }
            break;
        case FELICITY_BANK_STORE_HOW_MUCH:
            sFelicityBankWork->unk64.unkC = MAX_TEAM_SAVINGS - gTeamInventoryRef->teamSavings;
            if (sFelicityBankWork->unk64.unkC > gTeamInventoryRef->teamMoney)
                sFelicityBankWork->unk64.unkC = gTeamInventoryRef->teamMoney;
            sFelicityBankWork->unk64.unk4 = sFelicityBankWork->unk64.unkC;
            sFelicityBankWork->unk64.unk8 = 1;
            sFelicityBankWork->unk64.unk10 = 5;
            sFelicityBankWork->unk64.unk14 = 2;
            sFelicityBankWork->unk64.unk18 = &sFelicityBankWork->unkA8[2];
            sFelicityBankWork->unk64.unk1C = 0x50;
            sFelicityBankWork->unk64.unk20 = 0x12;
            sub_8013AA0(&sFelicityBankWork->unk64);
            sub_8016B48(FELICITY_BANK_ACTION_DEPOSIT);
            CreateFelicityMoneySavingsHeader(3);
            break;
        case FELICITY_BANK_STORE_RECEIPT:
            sFelicityBankWork->fallbackState = 1;
            gFormatArgs[0] = sFelicityBankWork->chosenAmount;
            CreateDialogueBoxAndPortrait(gCommonFelicity[sFelicityBankWork->mode][FEL_DLG_DEPOSIT__RECEIPT], 0, sFelicityBankWork->monPortraitPtr, 0x10D);
            break;
        case FELICITY_BANK_TAKE:
            if (gTeamInventoryRef->teamMoney >= MAX_TEAM_MONEY) {
                sFelicityBankWork->fallbackState = 1;
                CreateDialogueBoxAndPortrait(gCommonFelicity[sFelicityBankWork->mode][FEL_DLG_WITHDRAW__WALLET_FULL], 0, sFelicityBankWork->monPortraitPtr, 0x10D);
            }
            else if (gTeamInventoryRef->teamSavings == 0) {
                sFelicityBankWork->fallbackState = 1;
                CreateDialogueBoxAndPortrait(gCommonFelicity[sFelicityBankWork->mode][FEL_DLG_WITHDRAW__NO_MONEY], 0, sFelicityBankWork->monPortraitPtr, 0x10D);
            }
            else {
                sFelicityBankWork->fallbackState = FELICITY_BANK_TAKE_HOW_MUCH;
                gFormatArgs[0] = gTeamInventoryRef->teamSavings;
                CreateDialogueBoxAndPortrait(gCommonFelicity[sFelicityBankWork->mode][FEL_DLG_WITHDRAW__HOW_MUCH], 0, sFelicityBankWork->monPortraitPtr, 0x10D);
            }
            break;
        case FELICITY_BANK_TAKE_HOW_MUCH:
            sFelicityBankWork->unk64.unkC = MAX_TEAM_MONEY - gTeamInventoryRef->teamMoney;
            if (sFelicityBankWork->unk64.unkC > gTeamInventoryRef->teamSavings)
                sFelicityBankWork->unk64.unkC = gTeamInventoryRef->teamSavings;
            sFelicityBankWork->unk64.unk4 = sFelicityBankWork->unk64.unkC;
            sFelicityBankWork->unk64.unk8 = 1;
            sFelicityBankWork->unk64.unk10 = 5;
            sFelicityBankWork->unk64.unk14 = 2;
            sFelicityBankWork->unk64.unk18 = &sFelicityBankWork->unkA8[2];
            sFelicityBankWork->unk64.unk1C = 0x50;
            sFelicityBankWork->unk64.unk20 = 0x12;
            sub_8013AA0(&sFelicityBankWork->unk64);
            sub_8016B48(FELICITY_BANK_ACTION_WITHDRAW);
            CreateFelicityMoneySavingsHeader(3);
            break;
        case 2:
            CreateFelicityMoneySavingsHeader(3);
            break;
        case FELICITY_BANK_TAKE_DEPOSIT:
            sFelicityBankWork->fallbackState = 1;
            gFormatArgs[0] = sFelicityBankWork->chosenAmount;
            CreateDialogueBoxAndPortrait(gCommonFelicity[sFelicityBankWork->mode][FEL_DLG_WITHDRAW__RECEIPT], 0, sFelicityBankWork->monPortraitPtr, 0x10D);
            break;
    }
}

static void CreateFelicityBankShopMenu(void)
{
    s32 loopMax;
    s32 i;

    loopMax = 0;

    MemoryFill16(sFelicityBankWork->unk54, 0, sizeof(sFelicityBankWork->unk54));

    sFelicityBankWork->unk14[loopMax].text = gCommonStore[0];
    sFelicityBankWork->unk14[loopMax].menuAction = STORE_ACTION;

    loopMax++;
    sFelicityBankWork->unk14[loopMax].text = gCommonTake[0];
    sFelicityBankWork->unk14[loopMax].menuAction = TAKE_ACTION;

    loopMax++;
    sFelicityBankWork->unk14[loopMax].text = gCommonInfo[0];
    sFelicityBankWork->unk14[loopMax].menuAction = INFO_ACTION;

    loopMax++;
    sFelicityBankWork->unk14[loopMax].text = gCommonCancel[0];
    sFelicityBankWork->unk14[loopMax].menuAction = CANCEL_ACTION;

    loopMax++;
    sFelicityBankWork->unk14[loopMax].text = NULL;
    sFelicityBankWork->unk14[loopMax].menuAction = CANCEL_ACTION;

    for (i = 0; i < loopMax; i++) {
        if (sFelicityBankWork->unk54[i] == 0 && sFelicityBankWork->unk14[i].menuAction == sFelicityBankWork->menuAction)
            return;
    }
    for (i = 0; i < loopMax; i++) {
        if (sFelicityBankWork->unk54[i] == 0) {
            sFelicityBankWork->menuAction = sFelicityBankWork->unk14[i].menuAction;
            break;
        }
    }
}

static void HandleFelicityBankShopMenu(void)
{
    s32 menuAction;

    if (sub_80144A4(&menuAction))
        return;

    sFelicityBankWork->menuAction = menuAction;
    switch (menuAction) {
        case STORE_ACTION:
            UpdateFelicityBankState(FELICITY_BANK_STORE);
            break;
        case TAKE_ACTION:
            UpdateFelicityBankState(FELICITY_BANK_TAKE);
            break;
        case INFO_ACTION:
            UpdateFelicityBankState(FELICITY_BANK_INFO);
            break;
        case CANCEL_ACTION:
            UpdateFelicityBankState(4);
            break;
    }
}

static void Felicity_DepositMoney(void)
{
    switch (sub_8013BBC(&sFelicityBankWork->unk64)) {
        case 1:
            sub_8016B48(FELICITY_BANK_ACTION_DEPOSIT);
            break;
        case 3:
            sFelicityBankWork->chosenAmount = sFelicityBankWork->unk64.unk0;
            gTeamInventoryRef->teamSavings += sFelicityBankWork->chosenAmount;
            gTeamInventoryRef->teamMoney -= sFelicityBankWork->chosenAmount;
            PlaySound(332);
            UpdateFelicityBankState(FELICITY_BANK_STORE_RECEIPT);
            break;
        case 2:
            UpdateFelicityBankState(5);
            break;
        case 0:
            break;
    }
}

static void Felicity_WithdrawMoney(void)
{
    switch (sub_8013BBC(&sFelicityBankWork->unk64)) {
        case 1:
            sub_8016B48(FELICITY_BANK_ACTION_WITHDRAW);
            break;
        case 3:
            sFelicityBankWork->chosenAmount = sFelicityBankWork->unk64.unk0;
            gTeamInventoryRef->teamMoney += sFelicityBankWork->chosenAmount;
            gTeamInventoryRef->teamSavings -= sFelicityBankWork->chosenAmount;
            PlaySound(332);
            UpdateFelicityBankState(FELICITY_BANK_TAKE_DEPOSIT);
            break;
        case 2:
            UpdateFelicityBankState(5);
            break;
        case 0:
            break;
    }
}

static void sub_8016B00(void)
{
    s32 auStack8;

    if (sub_80144A4(&auStack8) == 0)
        UpdateFelicityBankState(sFelicityBankWork->fallbackState);
}

static void sub_8016B24(void)
{
    s32 auStack8;

    if (sub_80144A4(&auStack8) == 4)
        UpdateFelicityBankState(sFelicityBankWork->fallbackState);
}

static void sub_8016B48(u8 action)
{
    CallPrepareTextbox_8008C54(sFelicityBankWork->unk64.unk14);
    sub_80073B8(sFelicityBankWork->unk64.unk14);

    if (action != FELICITY_BANK_ACTION_WITHDRAW)
        PrintStringOnWindow(12, 0, gCommonDepositPrompt[0], sFelicityBankWork->unk64.unk14, 0);
    else
        PrintStringOnWindow(12, 0, gCommonWithdrawPrompt[0], sFelicityBankWork->unk64.unk14, 0);

    sub_8013C68(&sFelicityBankWork->unk64);
    sub_80073E0(sFelicityBankWork->unk64.unk14);
}

static void CreateFelicityMoneySavingsHeader(u32 param_1)
{
    CallPrepareTextbox_8008C54(param_1);
    sub_80073B8(param_1);
    PrintStringOnWindow(16, 4, sDisplayMoney, param_1, 0);
    sub_8012BC4(96, 4, gTeamInventoryRef->teamMoney, 5, 5, param_1);
    PrintStringOnWindow(112, 4, sDisplaySavings, param_1, 0);
    sub_8012BC4(200, 4, gTeamInventoryRef->teamSavings, 7, 5, param_1);
    sub_80073E0(param_1);
}

void DrawTeamMoneyBox(u32 param_1)
{
    CallPrepareTextbox_8008C54(param_1);
    sub_80073B8(param_1);
    PrintStringOnWindow(6, 0, sMoney, param_1, 0);
    sub_8012BC4(42, 12, gTeamInventoryRef->teamMoney, 5, 5, param_1);
    sub_80073E0(param_1);
}
