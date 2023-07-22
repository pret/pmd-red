#include "global.h"
#include "item.h"
#include "team_inventory.h"
#include "felicity_bank.h"
#include "menu_input.h"

extern struct FelicityBankWork *gFelicityBankWork;

extern u8 gUnknown_80DB738;
extern u8 gFelicityMoney[];
extern u8 gFelicitySavings[];
extern u8 *gFelicityWithdraw;
extern u8 *gFelicityDeposit;

extern void PlaySound(u32);
extern void UpdateFelicityBankState(u32);
extern void xxx_call_draw_string(s32 x, u32 y, u8 *str, u32 , u32);

extern void sub_80073B8(u32);
extern void sub_80073E0(u32);
extern void sub_8008C54(u32);
extern u32 sub_8013BBC(u32 *);
extern void sub_8013C68(u32 *);
extern s32 sub_80144A4(s32 *);

void sub_8016B48(u8 action);

#define FELICITY_BANK_ACTION_WITHDRAW 0
#define FELICITY_BANK_ACTION_DEPOSIT 1

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
          gTeamInventory_203B460->teamSavings += gFelicityBankWork->chosenAmount;
          gTeamInventory_203B460->teamMoney -= gFelicityBankWork->chosenAmount;
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
          gTeamInventory_203B460->teamMoney += gFelicityBankWork->chosenAmount;
          gTeamInventory_203B460->teamSavings -= gFelicityBankWork->chosenAmount;
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
  sub_8012BC4(96, 4, gTeamInventory_203B460->teamMoney, 5, 5, param_1);
  xxx_call_draw_string(112, 4, gFelicitySavings, param_1, 0);
  sub_8012BC4(200, 4, gTeamInventory_203B460->teamSavings, 7, 5, param_1);
  sub_80073E0(param_1);
}

void DrawTeamMoneyBox(u32 param_1)
{ 
  sub_8008C54(param_1);
  sub_80073B8(param_1);
  xxx_call_draw_string(6, 0, &gUnknown_80DB738, param_1, 0); // Money
  sub_8012BC4(42, 12, gTeamInventory_203B460->teamMoney, 5, 5, param_1);
  sub_80073E0(param_1);
}
