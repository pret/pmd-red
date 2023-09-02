#include "global.h"
#include "code_80118A4.h"
#include "code_80130A8.h"
#include "felicity_bank.h"
#include "memory.h"
#include "menu_input.h"
#include "pokemon.h"

#include "text1.h"
#include "text2.h"

EWRAM_DATA_2 struct FelicityBankWork *gFelicityBankWork = {0};

extern u32 gUnknown_202DE30;
extern u8 gUnknown_202E1C8[];
extern u8 gUnknown_202E5D8[];

extern u8 *gUnknown_80D4934[];
extern u8 *gUnknown_80D4958[];
extern u8 *gUnknown_80D4964[];
extern u8 *gUnknown_80D4970[];
extern u8 *gFelicityDeposit;
extern u8 *gFelicityWithdraw;
extern u8 *gFelicityDialogue[2][15];
extern UnkTextStruct2 gUnknown_80DB6DC;
extern UnkTextStruct2 gUnknown_80DB6F4;
extern UnkTextStruct2 gUnknown_80DB70C;
extern u8 gFelicitySavings[];
extern u8 gFelicityMoney[];
extern u8 gUnknown_80DB738;

extern void sub_801645C();
extern void sub_80169BC();
extern void sub_8016B00();
extern void sub_8016B24();

void CreateFelicityBankShopMenu(void);
void CreateFelicityMoneySavingsHeader(u32);
void Felicity_DepositMoney();
void Felicity_WithdrawMoney();
void sub_8016B48(u8 action);
void UpdateFelicityBankDialogue();
void UpdateFelicityBankState(u32);

u32 CreateFelicityBank(s32 isAsleep)
{
  char *monName;
  OpenedFile * faceFile;
  
  ResetUnusedInputStruct();
  sub_800641C(NULL, TRUE, TRUE);
  gFelicityBankWork = MemoryAlloc(sizeof(struct FelicityBankWork), 8);
  gFelicityBankWork->menuAction = 0;
  gFelicityBankWork->isAsleep = isAsleep;
  CopyYellowMonsterNametoBuffer(gUnknown_202E5D8, MONSTER_PERSIAN);
  CopyYellowMonsterNametoBuffer(gUnknown_202E1C8, MONSTER_PERSIAN);
  monName = GetMonSpecies(MONSTER_PERSIAN);
  strcpy(gUnknown_202E1C8 - 0x50, monName);

  if (gFelicityBankWork->isAsleep == 1)
    gFelicityBankWork->unkA4 = NULL;
  else
    gFelicityBankWork->unkA4 = &gFelicityBankWork->faceFile;

  faceFile = GetDialogueSpriteDataPtr(MONSTER_PERSIAN);
  gFelicityBankWork->faceFile = faceFile;
  gFelicityBankWork->faceData = faceFile->data;
  gFelicityBankWork->unkA0 = 0;
  gFelicityBankWork->unkA1 = 0;
  gFelicityBankWork->unkA2 = 0;
  gFelicityBankWork->unk9C = 2;
  gFelicityBankWork->unk9E = 8;
  UpdateFelicityBankState(0);
  return 1;
}

u32 FelicityBankCallback(void)
{ 
  switch (gFelicityBankWork->currState) {
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
    if (gFelicityBankWork != NULL) {
        CloseFile(gFelicityBankWork->faceFile);
        MemoryFree(gFelicityBankWork);
        gFelicityBankWork = NULL;
    }
}

void UpdateFelicityBankState(u32 newState)
{
    gFelicityBankWork->currState = newState;
    sub_801645C();
    UpdateFelicityBankDialogue();
}

void sub_801645C(void)
{
    s32 index;

    sub_8006518(gFelicityBankWork->unkA8);
    switch (gFelicityBankWork->currState)
    {
        case 2:
            gFelicityBankWork->unkA8[0].unk0 = 0x80;
            gFelicityBankWork->unkA8[1].unk0 = 0x80;
            gFelicityBankWork->unkA8[2].unk0 = 0x80;
            gFelicityBankWork->unkA8[3] = gUnknown_80DB6F4;
            ResetUnusedInputStruct();
            sub_800641C(gFelicityBankWork->unkA8, TRUE, FALSE);
            break;
        case 8:
        case 11:
            gFelicityBankWork->unkA8[0].unk0 = 0x80;
            gFelicityBankWork->unkA8[1].unk0 = 0x80;
            gFelicityBankWork->unkA8[3] = gUnknown_80DB6F4;
            gFelicityBankWork->unkA8[2] = gUnknown_80DB70C;
            ResetUnusedInputStruct();
            sub_800641C(gFelicityBankWork->unkA8, TRUE, FALSE);
            break;
        default:
            for (index = 0; index < 4; index++) {
                gFelicityBankWork->unkA8[index] = gUnknown_80DB6DC;
            }
            ResetUnusedInputStruct();
            sub_800641C(gFelicityBankWork->unkA8, TRUE, TRUE);
            break;
    }
}

void UpdateFelicityBankDialogue(void)
{
    switch (gFelicityBankWork->currState) {
        case 0x0:
            gFelicityBankWork->fallbackState = 1;
            sub_80141B4(gFelicityDialogue[gFelicityBankWork->isAsleep][0], 0, gFelicityBankWork->unkA4, 0x10D);
            break;
        case 0x1:
            CreateFelicityBankShopMenu();
            gFelicityBankWork->fallbackState = 2;
            if (gTeamInventoryRef->teamSavings == 0)
                sub_8014248(gFelicityDialogue[gFelicityBankWork->isAsleep][1], 0, gFelicityBankWork->menuAction,
                    gFelicityBankWork->unk14, gFelicityBankWork->unk54, 4, 0, gFelicityBankWork->unkA4, 0xC);
            else {
                gUnknown_202DE30 = gTeamInventoryRef->teamSavings;
                sub_8014248(gFelicityDialogue[gFelicityBankWork->isAsleep][2], 0, gFelicityBankWork->menuAction,
                    gFelicityBankWork->unk14, gFelicityBankWork->unk54, 4, 0, gFelicityBankWork->unkA4, 0xC);
            }
            break;
        case 0x3:
            gFelicityBankWork->fallbackState = 1;
            sub_80141B4(gFelicityDialogue[gFelicityBankWork->isAsleep][14], 0, gFelicityBankWork->unkA4, 0x10D);
            break;
        case 0x4:
            gFelicityBankWork->fallbackState = 6;
            if (gTeamInventoryRef->teamSavings == 0)
                sub_80141B4(gFelicityDialogue[gFelicityBankWork->isAsleep][4], 0, gFelicityBankWork->unkA4, 0x10D);
            else {
                gUnknown_202DE30 = gTeamInventoryRef->teamSavings;
                sub_80141B4(gFelicityDialogue[gFelicityBankWork->isAsleep][5], 0, gFelicityBankWork->unkA4, 0x10D);
            }
            break;
        case 0x5:
            gFelicityBankWork->fallbackState = 1;
            sub_80141B4(gFelicityDialogue[gFelicityBankWork->isAsleep][3], 0, gFelicityBankWork->unkA4, 0x10D);
            break;
        case 0x7:
            if (gTeamInventoryRef->teamMoney == 0) {
                gFelicityBankWork->fallbackState = 1;
                sub_80141B4(gFelicityDialogue[gFelicityBankWork->isAsleep][7], 0, gFelicityBankWork->unkA4, 0x10D);
            }
            else if (gTeamInventoryRef->teamSavings >= MAX_TEAM_SAVINGS) {
                gFelicityBankWork->fallbackState = 1;
                sub_80141B4(gFelicityDialogue[gFelicityBankWork->isAsleep][8], 0, gFelicityBankWork->unkA4, 0x10D);
            }
            else {
                gFelicityBankWork->fallbackState = 8;
                sub_80141B4(gFelicityDialogue[gFelicityBankWork->isAsleep][6], 0, gFelicityBankWork->unkA4, 0x10D);
            }
            break;
        case 0x8:
            gFelicityBankWork->maximumDepositWithdraw = MAX_TEAM_SAVINGS - gTeamInventoryRef->teamSavings;
            if (gFelicityBankWork->maximumDepositWithdraw > gTeamInventoryRef->teamMoney)
                gFelicityBankWork->maximumDepositWithdraw = gTeamInventoryRef->teamMoney;
            gFelicityBankWork->unk68 = gFelicityBankWork->maximumDepositWithdraw;
            gFelicityBankWork->unk6C = 1;
            gFelicityBankWork->unk74 = 5;
            gFelicityBankWork->unk78 = 2;
            gFelicityBankWork->unk7C = &gFelicityBankWork->unkA8[2];
            gFelicityBankWork->unk80 = 0x50;
            gFelicityBankWork->unk84 = 0x12;
            sub_8013AA0(&gFelicityBankWork->unk64);
            sub_8016B48(1);
            CreateFelicityMoneySavingsHeader(3);
            break;
        case 0x9:
            gFelicityBankWork->fallbackState = 1;
            gUnknown_202DE30 = gFelicityBankWork->chosenAmount;
            sub_80141B4(gFelicityDialogue[gFelicityBankWork->isAsleep][9], 0, gFelicityBankWork->unkA4, 0x10D);
            break;
        case 0xA:
            if (gTeamInventoryRef->teamMoney >= MAX_TEAM_MONEY) {
                gFelicityBankWork->fallbackState = 1;
                sub_80141B4(gFelicityDialogue[gFelicityBankWork->isAsleep][12], 0, gFelicityBankWork->unkA4, 0x10D);
            }
            else if (gTeamInventoryRef->teamSavings == 0) {
                gFelicityBankWork->fallbackState = 1;
                sub_80141B4(gFelicityDialogue[gFelicityBankWork->isAsleep][11], 0, gFelicityBankWork->unkA4, 0x10D);
            }
            else {
                gFelicityBankWork->fallbackState = 11;
                gUnknown_202DE30 = gTeamInventoryRef->teamSavings;
                sub_80141B4(gFelicityDialogue[gFelicityBankWork->isAsleep][10], 0, gFelicityBankWork->unkA4, 0x10D);
            }
            break;
        case 0xB:
            gFelicityBankWork->maximumDepositWithdraw = MAX_TEAM_MONEY - gTeamInventoryRef->teamMoney;
            if (gFelicityBankWork->maximumDepositWithdraw > gTeamInventoryRef->teamSavings)
                gFelicityBankWork->maximumDepositWithdraw = gTeamInventoryRef->teamSavings;
            gFelicityBankWork->unk68 = gFelicityBankWork->maximumDepositWithdraw;
            gFelicityBankWork->unk6C = 1;
            gFelicityBankWork->unk74 = 5;
            gFelicityBankWork->unk78 = 2;
            gFelicityBankWork->unk7C = &gFelicityBankWork->unkA8[2];
            gFelicityBankWork->unk80 = 0x50;
            gFelicityBankWork->unk84 = 0x12;
            sub_8013AA0(&gFelicityBankWork->unk64);
            sub_8016B48(0);
            CreateFelicityMoneySavingsHeader(3);
            break;
        case 0x2:
            CreateFelicityMoneySavingsHeader(3);
            break;
        case 0xC:
            gFelicityBankWork->fallbackState = 1;
            gUnknown_202DE30 = gFelicityBankWork->chosenAmount;
            sub_80141B4(gFelicityDialogue[gFelicityBankWork->isAsleep][13], 0, gFelicityBankWork->unkA4, 0x10D);
            break;
    }
}

void CreateFelicityBankShopMenu(void)
{
    s32 loopMax;
    s32 i;
    loopMax = 0;
    
    MemoryFill16(gFelicityBankWork->unk54, 0, sizeof(gFelicityBankWork->unk54));

    gFelicityBankWork->unk14[loopMax].text = *gUnknown_80D4958; // Store
    gFelicityBankWork->unk14[loopMax].menuAction = 2;
    loopMax++;
    gFelicityBankWork->unk14[loopMax].text = *gUnknown_80D4964; // Take
    gFelicityBankWork->unk14[loopMax].menuAction = 3;
    loopMax++;
    gFelicityBankWork->unk14[loopMax].text = *gUnknown_80D4970; // Info
    gFelicityBankWork->unk14[loopMax].menuAction = 4;
    loopMax++;
    gFelicityBankWork->unk14[loopMax].text = *gUnknown_80D4934; // Cancel
    gFelicityBankWork->unk14[loopMax].menuAction = 1;
    loopMax++;
    gFelicityBankWork->unk14[loopMax].text = NULL;
    gFelicityBankWork->unk14[loopMax].menuAction = 1;

    for (i = 0; i < loopMax; i++) {
        if (gFelicityBankWork->unk54[i] == 0 && gFelicityBankWork->unk14[i].menuAction == gFelicityBankWork->menuAction)
            return;
    }
    for (i = 0; i < loopMax; i++) {
        if (gFelicityBankWork->unk54[i] == 0) {
            gFelicityBankWork->menuAction = gFelicityBankWork->unk14[i].menuAction;
            break;
        }
    }
}

void sub_80169BC(void)
{
    s32 menuAction;

    if (sub_80144A4(&menuAction) == 0) {
        gFelicityBankWork->menuAction = menuAction;
        switch (menuAction)
        {
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
}

void Felicity_DepositMoney(void)
{
  switch (sub_8013BBC(&gFelicityBankWork->unk64)) {
      case 1:
        sub_8016B48(FELICITY_BANK_ACTION_DEPOSIT);
        break;
      case 3:
          gFelicityBankWork->chosenAmount = gFelicityBankWork->unk64;
          gTeamInventoryRef->teamSavings += gFelicityBankWork->chosenAmount;
          gTeamInventoryRef->teamMoney -= gFelicityBankWork->chosenAmount;
          PlaySound(0x14c);
          UpdateFelicityBankState(9);
          break;
      case 2:
        UpdateFelicityBankState(5);
        break;
      case 0:
        break;
   }
}

void Felicity_WithdrawMoney(void)
{
  switch (sub_8013BBC(&gFelicityBankWork->unk64)) {
      case 1:
        sub_8016B48(FELICITY_BANK_ACTION_WITHDRAW);
        break;
      case 3:
          gFelicityBankWork->chosenAmount = gFelicityBankWork->unk64;
          gTeamInventoryRef->teamMoney += gFelicityBankWork->chosenAmount;
          gTeamInventoryRef->teamSavings -= gFelicityBankWork->chosenAmount;
          PlaySound(0x14c);
          UpdateFelicityBankState(0xc);
          break;
      case 2:
        UpdateFelicityBankState(5);
        break;
      case 0:
        break;
   }
}

void sub_8016B00(void)
{
  s32 auStack8;
  
  if (sub_80144A4(&auStack8) == 0)
    UpdateFelicityBankState(gFelicityBankWork->fallbackState);
}

void sub_8016B24(void)
{
  s32 auStack8;
  
  if (sub_80144A4(&auStack8) == 4)
    UpdateFelicityBankState(gFelicityBankWork->fallbackState);
}

void sub_8016B48(u8 action)
{
  sub_8008C54(gFelicityBankWork->unk78);
  sub_80073B8(gFelicityBankWork->unk78);
  if (action != FELICITY_BANK_ACTION_WITHDRAW)
     xxx_call_draw_string(12, 0, gFelicityDeposit, gFelicityBankWork->unk78, 0);
  else
     xxx_call_draw_string(12, 0, gFelicityWithdraw, gFelicityBankWork->unk78, 0);
  sub_8013C68(&gFelicityBankWork->unk64);
  sub_80073E0(gFelicityBankWork->unk78);
}

void CreateFelicityMoneySavingsHeader(u32 param_1)
{
  sub_8008C54(param_1);
  sub_80073B8(param_1);
  xxx_call_draw_string(16, 4, gFelicityMoney, param_1, 0);
  sub_8012BC4(96, 4, gTeamInventoryRef->teamMoney, 5, 5, param_1);
  xxx_call_draw_string(112, 4, gFelicitySavings, param_1, 0);
  sub_8012BC4(200, 4, gTeamInventoryRef->teamSavings, 7, 5, param_1);
  sub_80073E0(param_1);
}

void DrawTeamMoneyBox(u32 param_1)
{ 
  sub_8008C54(param_1);
  sub_80073B8(param_1);
  xxx_call_draw_string(6, 0, &gUnknown_80DB738, param_1, 0); // Money
  sub_8012BC4(42, 12, gTeamInventoryRef->teamMoney, 5, 5, param_1);
  sub_80073E0(param_1);
}
