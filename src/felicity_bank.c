#include "global.h"
#include "code_80118A4.h"
#include "code_80130A8.h"
#include "common_strings.h"
#include "felicity_bank.h"
#include "memory.h"
#include "menu_input.h"
#include "pokemon.h"
#include "text1.h"
#include "text2.h"

static EWRAM_DATA_2 FelicityBankWork *sFelicityBankWork = {0};

extern u32 gUnknown_202DE30;
extern u8 gUnknown_202E1C8[];
extern u8 gUnknown_202E5D8[];

#include "data/felicity_bank.h"

static void CreateFelicityBankShopMenu(void);
static void CreateFelicityMoneySavingsHeader(u32);
static void Felicity_DepositMoney(void);
static void Felicity_WithdrawMoney(void);
static void UpdateFelicityBankDialogue(void);
static void UpdateFelicityBankState(u32 newState);

static void sub_801645C(void);
static void sub_80169BC(void);
static void sub_8016B00(void);
static void sub_8016B24(void);
static void sub_8016B48(u8 action);

bool8 CreateFelicityBank(s32 mode)
{
    u8 *monName;
    OpenedFile *faceFile;

    ResetUnusedInputStruct();
    sub_800641C(NULL, TRUE, TRUE);
    sFelicityBankWork = MemoryAlloc(sizeof(FelicityBankWork), 8);
    sFelicityBankWork->menuAction = 0;
    sFelicityBankWork->mode = mode;
    CopyYellowMonsterNametoBuffer(gUnknown_202E5D8, MONSTER_PERSIAN);
    CopyYellowMonsterNametoBuffer(gUnknown_202E1C8, MONSTER_PERSIAN);
    monName = GetMonSpecies(MONSTER_PERSIAN);
    strcpy(gUnknown_202E1C8 - 80, monName);

    if (sFelicityBankWork->mode == FEL_MODE_ASLEEP)
        sFelicityBankWork->unkA4 = NULL;
    else
        sFelicityBankWork->unkA4 = &sFelicityBankWork->faceFile;

    faceFile = GetDialogueSpriteDataPtr(MONSTER_PERSIAN);
    sFelicityBankWork->faceFile = faceFile;
    sFelicityBankWork->faceData = faceFile->data;
    sFelicityBankWork->unkA0 = 0;
    sFelicityBankWork->unkA1 = 0;
    sFelicityBankWork->unkA2 = 0;
    sFelicityBankWork->unk9C = 2;
    sFelicityBankWork->unk9E = 8;
    UpdateFelicityBankState(0);
    return TRUE;
}

u32 FelicityBankCallback(void)
{
    switch (sFelicityBankWork->currState) {
        case 1:
            sub_8016B24();
            break;
        case 2:
            sub_80169BC();
            break;
        case 8:
            Felicity_DepositMoney();
            break;
        case 11:
            Felicity_WithdrawMoney();
            break;
        case 6:
            return 3;
        case 0:
        case 3:
        case 4:
        case 5:
        case 7:
        case 9:
        case 10:
        case 12:
        default:
            sub_8016B00();
            break;
    }
    return 0;
}

void DestroyFelicityBank(void)
{
    if (sFelicityBankWork != NULL) {
        CloseFile(sFelicityBankWork->faceFile);
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

    sub_8006518(sFelicityBankWork->unkA8);

    switch (sFelicityBankWork->currState) {
        case 2:
            sFelicityBankWork->unkA8[0].unk0 = 0x80;
            sFelicityBankWork->unkA8[1].unk0 = 0x80;
            sFelicityBankWork->unkA8[2].unk0 = 0x80;
            sFelicityBankWork->unkA8[3] = sUnknown_80DB6F4;
            ResetUnusedInputStruct();
            sub_800641C(sFelicityBankWork->unkA8, TRUE, FALSE);
            break;
        case 8:
        case 11:
            sFelicityBankWork->unkA8[0].unk0 = 0x80;
            sFelicityBankWork->unkA8[1].unk0 = 0x80;
            sFelicityBankWork->unkA8[3] = sUnknown_80DB6F4;
            sFelicityBankWork->unkA8[2] = sUnknown_80DB70C;
            ResetUnusedInputStruct();
            sub_800641C(sFelicityBankWork->unkA8, TRUE, FALSE);
            break;
        default:
            for (i = 0; i < 4; i++)
                sFelicityBankWork->unkA8[i] = sUnknown_80DB6DC;

            ResetUnusedInputStruct();
            sub_800641C(sFelicityBankWork->unkA8, TRUE, TRUE);
            break;
    }
}

static void UpdateFelicityBankDialogue(void)
{
    switch (sFelicityBankWork->currState) {
        case 0:
            sFelicityBankWork->fallbackState = 1;
            sub_80141B4(gCommonFelicity[sFelicityBankWork->mode][FEL_DLG_WELCOME], 0, sFelicityBankWork->unkA4, 0x10D);
            break;
        case 1:
            CreateFelicityBankShopMenu();
            sFelicityBankWork->fallbackState = 2;
            if (gTeamInventoryRef->teamSavings == 0)
                sub_8014248(gCommonFelicity[sFelicityBankWork->mode][FEL_DLG_HOW_MAY_I_SERVE__NO_MONEY], 0, sFelicityBankWork->menuAction,
                    sFelicityBankWork->unk14, sFelicityBankWork->unk54, 4, 0, sFelicityBankWork->unkA4, 0xC);
            else {
                gUnknown_202DE30 = gTeamInventoryRef->teamSavings;
                sub_8014248(gCommonFelicity[sFelicityBankWork->mode][FEL_DLG_HOW_MAY_I_SERVE__HAS_MONEY], 0, sFelicityBankWork->menuAction,
                    sFelicityBankWork->unk14, sFelicityBankWork->unk54, 4, 0, sFelicityBankWork->unkA4, 0xC);
            }
            break;
        case 3:
            sFelicityBankWork->fallbackState = 1;
            sub_80141B4(gCommonFelicity[sFelicityBankWork->mode][FEL_DLG_HOW_IT_WORKS], 0, sFelicityBankWork->unkA4, 0x10D);
            break;
        case 4:
            sFelicityBankWork->fallbackState = 6;
            if (gTeamInventoryRef->teamSavings == 0)
                sub_80141B4(gCommonFelicity[sFelicityBankWork->mode][FEL_DLG_BYE__NO_MONEY], 0, sFelicityBankWork->unkA4, 0x10D);
            else {
                gUnknown_202DE30 = gTeamInventoryRef->teamSavings;
                sub_80141B4(gCommonFelicity[sFelicityBankWork->mode][FEL_DLG_BYE__HAS_MONEY], 0, sFelicityBankWork->unkA4, 0x10D);
            }
            break;
        case 5:
            sFelicityBankWork->fallbackState = 1;
            sub_80141B4(gCommonFelicity[sFelicityBankWork->mode][FEL_DLG_VERY_WELL], 0, sFelicityBankWork->unkA4, 0x10D);
            break;
        case 7:
            if (gTeamInventoryRef->teamMoney == 0) {
                sFelicityBankWork->fallbackState = 1;
                sub_80141B4(gCommonFelicity[sFelicityBankWork->mode][FEL_DLG_DEPOSIT__NO_MONEY], 0, sFelicityBankWork->unkA4, 0x10D);
            }
            else if (gTeamInventoryRef->teamSavings >= MAX_TEAM_SAVINGS) {
                sFelicityBankWork->fallbackState = 1;
                sub_80141B4(gCommonFelicity[sFelicityBankWork->mode][FEL_DLG_DEPOSIT__BANK_FULL], 0, sFelicityBankWork->unkA4, 0x10D);
            }
            else {
                sFelicityBankWork->fallbackState = 8;
                sub_80141B4(gCommonFelicity[sFelicityBankWork->mode][FEL_DLG_DEPOSIT__HOW_MUCH], 0, sFelicityBankWork->unkA4, 0x10D);
            }
            break;
        case 8:
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
        case 9:
            sFelicityBankWork->fallbackState = 1;
            gUnknown_202DE30 = sFelicityBankWork->chosenAmount;
            sub_80141B4(gCommonFelicity[sFelicityBankWork->mode][FEL_DLG_DEPOSIT__RECEIPT], 0, sFelicityBankWork->unkA4, 0x10D);
            break;
        case 10:
            if (gTeamInventoryRef->teamMoney >= MAX_TEAM_MONEY) {
                sFelicityBankWork->fallbackState = 1;
                sub_80141B4(gCommonFelicity[sFelicityBankWork->mode][FEL_DLG_WITHDRAW__WALLET_FULL], 0, sFelicityBankWork->unkA4, 0x10D);
            }
            else if (gTeamInventoryRef->teamSavings == 0) {
                sFelicityBankWork->fallbackState = 1;
                sub_80141B4(gCommonFelicity[sFelicityBankWork->mode][FEL_DLG_WITHDRAW__NO_MONEY], 0, sFelicityBankWork->unkA4, 0x10D);
            }
            else {
                sFelicityBankWork->fallbackState = 11;
                gUnknown_202DE30 = gTeamInventoryRef->teamSavings;
                sub_80141B4(gCommonFelicity[sFelicityBankWork->mode][FEL_DLG_WITHDRAW__HOW_MUCH], 0, sFelicityBankWork->unkA4, 0x10D);
            }
            break;
        case 11:
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
        case 12:
            sFelicityBankWork->fallbackState = 1;
            gUnknown_202DE30 = sFelicityBankWork->chosenAmount;
            sub_80141B4(gCommonFelicity[sFelicityBankWork->mode][FEL_DLG_WITHDRAW__RECEIPT], 0, sFelicityBankWork->unkA4, 0x10D);
            break;
    }
}

static void CreateFelicityBankShopMenu(void)
{
    s32 loopMax;
    s32 i;

    loopMax = 0;

    MemoryFill16(sFelicityBankWork->unk54, 0, sizeof(sFelicityBankWork->unk54));

    sFelicityBankWork->unk14[loopMax].text = *gCommonStore;
    sFelicityBankWork->unk14[loopMax].menuAction = 2;

    loopMax++;
    sFelicityBankWork->unk14[loopMax].text = *gCommonTake;
    sFelicityBankWork->unk14[loopMax].menuAction = 3;

    loopMax++;
    sFelicityBankWork->unk14[loopMax].text = *gCommonInfo;
    sFelicityBankWork->unk14[loopMax].menuAction = 4;

    loopMax++;
    sFelicityBankWork->unk14[loopMax].text = *gCommonCancel;
    sFelicityBankWork->unk14[loopMax].menuAction = 1;

    loopMax++;
    sFelicityBankWork->unk14[loopMax].text = NULL;
    sFelicityBankWork->unk14[loopMax].menuAction = 1;

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

static void sub_80169BC(void)
{
    s32 menuAction;

    if (sub_80144A4(&menuAction))
        return;

    sFelicityBankWork->menuAction = menuAction;
    switch (menuAction) {
        case 2:
            UpdateFelicityBankState(7);
            break;
        case 3:
            UpdateFelicityBankState(10);
            break;
        case 4:
            UpdateFelicityBankState(3);
            break;
        case 1:
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
            UpdateFelicityBankState(9);
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
            UpdateFelicityBankState(12);
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
    sub_8008C54(sFelicityBankWork->unk64.unk14);
    sub_80073B8(sFelicityBankWork->unk64.unk14);

    if (action != FELICITY_BANK_ACTION_WITHDRAW)
        xxx_call_draw_string(12, 0, *gCommonDepositPrompt, sFelicityBankWork->unk64.unk14, 0);
    else
        xxx_call_draw_string(12, 0, *gCommonWithdrawPrompt, sFelicityBankWork->unk64.unk14, 0);

    sub_8013C68(&sFelicityBankWork->unk64);
    sub_80073E0(sFelicityBankWork->unk64.unk14);
}

static void CreateFelicityMoneySavingsHeader(u32 param_1)
{
    sub_8008C54(param_1);
    sub_80073B8(param_1);
    xxx_call_draw_string(16, 4, sDisplayMoney, param_1, 0);
    sub_8012BC4(96, 4, gTeamInventoryRef->teamMoney, 5, 5, param_1);
    xxx_call_draw_string(112, 4, sDisplaySavings, param_1, 0);
    sub_8012BC4(200, 4, gTeamInventoryRef->teamSavings, 7, 5, param_1);
    sub_80073E0(param_1);
}

void DrawTeamMoneyBox(u32 param_1)
{ 
    sub_8008C54(param_1);
    sub_80073B8(param_1);
    xxx_call_draw_string(6, 0, sMoney, param_1, 0);
    sub_8012BC4(42, 12, gTeamInventoryRef->teamMoney, 5, 5, param_1);
    sub_80073E0(param_1);
}