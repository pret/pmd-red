#include "global.h"
#include "pokemon.h"
#include "file_system.h"
#include "input.h"
#include "felicity_bank.h"
#include "memory.h"
#include "team_inventory.h"

extern u32 gUnknown_202DE30;
extern u8 gUnknown_202E1C8[];
extern u8 gUnknown_202E5D8[];

extern struct UnkTextStruct2 gUnknown_80DB6DC;
extern struct UnkTextStruct2 gUnknown_80DB6F4;
extern struct UnkTextStruct2 gUnknown_80DB70C;
extern u8 *gFelicityDialogue[2][15];

extern void Felicity_DepositMoney();
extern void Felicity_WithdrawMoney();

extern void sub_8013AA0(u32 *);
extern void sub_80141B4(const u8 *, u32, struct OpenedFile **, u32);
extern void sub_8014248(const u8 *, u32, u32, const struct MenuItem *, void *, u32, u32, struct OpenedFile **, u32);
extern void sub_801645C();
extern void sub_80169BC();
extern void sub_8016B00();
extern void sub_8016B24();

void UpdateFelicityBankDialogue();
void UpdateFelicityBankState(u32);

// TODO: Don't extern these once I merge the files
extern void CreateFelicityBankShopMenu(void);
extern void CreateFelicityMoneySavingsHeader(u32);
extern void sub_8016B48(u8 action);

u32 CreateFelicityBank(s32 isAsleep)
{
  char *monName;
  struct OpenedFile * faceFile;
  
  ResetUnusedInputStruct();
  sub_800641C(0, 1, 1);
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
            gFelicityBankWork->unkA8[0].fill00[0] = 0x80;
            gFelicityBankWork->unkA8[1].fill00[0] = 0x80;
            gFelicityBankWork->unkA8[2].fill00[0] = 0x80;
            gFelicityBankWork->unkA8[3] = gUnknown_80DB6F4;
            ResetUnusedInputStruct();
            sub_800641C(gFelicityBankWork->unkA8, 1, 0);
            break;
        case 8:
        case 11:
            gFelicityBankWork->unkA8[0].fill00[0] = 0x80;
            gFelicityBankWork->unkA8[1].fill00[0] = 0x80;
            gFelicityBankWork->unkA8[3] = gUnknown_80DB6F4;
            gFelicityBankWork->unkA8[2] = gUnknown_80DB70C;
            ResetUnusedInputStruct();
            sub_800641C(gFelicityBankWork->unkA8, 1, 0);
            break;
        default:
            for (index = 0; index < 4; index++) {
                gFelicityBankWork->unkA8[index] = gUnknown_80DB6DC;
            }
            ResetUnusedInputStruct();
            sub_800641C(gFelicityBankWork->unkA8, 1, 1);
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
            if (gTeamInventory_203B460->teamSavings == 0)
                sub_8014248(gFelicityDialogue[gFelicityBankWork->isAsleep][1], 0, gFelicityBankWork->menuAction,
                    gFelicityBankWork->unk14, gFelicityBankWork->unk54, 4, 0, gFelicityBankWork->unkA4, 0xC);
            else {
                gUnknown_202DE30 = gTeamInventory_203B460->teamSavings;
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
            if (gTeamInventory_203B460->teamSavings == 0)
                sub_80141B4(gFelicityDialogue[gFelicityBankWork->isAsleep][4], 0, gFelicityBankWork->unkA4, 0x10D);
            else {
                gUnknown_202DE30 = gTeamInventory_203B460->teamSavings;
                sub_80141B4(gFelicityDialogue[gFelicityBankWork->isAsleep][5], 0, gFelicityBankWork->unkA4, 0x10D);
            }
            break;
        case 0x5:
            gFelicityBankWork->fallbackState = 1;
            sub_80141B4(gFelicityDialogue[gFelicityBankWork->isAsleep][3], 0, gFelicityBankWork->unkA4, 0x10D);
            break;
        case 0x7:
            if (gTeamInventory_203B460->teamMoney == 0) {
                gFelicityBankWork->fallbackState = 1;
                sub_80141B4(gFelicityDialogue[gFelicityBankWork->isAsleep][7], 0, gFelicityBankWork->unkA4, 0x10D);
            }
            else if (gTeamInventory_203B460->teamSavings >= MAX_TEAM_SAVINGS) {
                gFelicityBankWork->fallbackState = 1;
                sub_80141B4(gFelicityDialogue[gFelicityBankWork->isAsleep][8], 0, gFelicityBankWork->unkA4, 0x10D);
            }
            else {
                gFelicityBankWork->fallbackState = 8;
                sub_80141B4(gFelicityDialogue[gFelicityBankWork->isAsleep][6], 0, gFelicityBankWork->unkA4, 0x10D);
            }
            break;
        case 0x8:
            gFelicityBankWork->maximumDepositWithdraw = MAX_TEAM_SAVINGS - gTeamInventory_203B460->teamSavings;
            if (gFelicityBankWork->maximumDepositWithdraw > gTeamInventory_203B460->teamMoney)
                gFelicityBankWork->maximumDepositWithdraw = gTeamInventory_203B460->teamMoney;
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
            if (gTeamInventory_203B460->teamMoney >= MAX_TEAM_MONEY) {
                gFelicityBankWork->fallbackState = 1;
                sub_80141B4(gFelicityDialogue[gFelicityBankWork->isAsleep][12], 0, gFelicityBankWork->unkA4, 0x10D);
            }
            else if (gTeamInventory_203B460->teamSavings == 0) {
                gFelicityBankWork->fallbackState = 1;
                sub_80141B4(gFelicityDialogue[gFelicityBankWork->isAsleep][11], 0, gFelicityBankWork->unkA4, 0x10D);
            }
            else {
                gFelicityBankWork->fallbackState = 11;
                gUnknown_202DE30 = gTeamInventory_203B460->teamSavings;
                sub_80141B4(gFelicityDialogue[gFelicityBankWork->isAsleep][10], 0, gFelicityBankWork->unkA4, 0x10D);
            }
            break;
        case 0xB:
            gFelicityBankWork->maximumDepositWithdraw = MAX_TEAM_MONEY - gTeamInventory_203B460->teamMoney;
            if (gFelicityBankWork->maximumDepositWithdraw > gTeamInventory_203B460->teamSavings)
                gFelicityBankWork->maximumDepositWithdraw = gTeamInventory_203B460->teamSavings;
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