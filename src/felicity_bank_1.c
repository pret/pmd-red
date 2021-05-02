#include "global.h"
#include "gUnknown_203B460.h"
#include "felicity_bank.h"

extern struct unkStruct_203B460 *gUnknown_203B460;
extern struct unkStruct_203B204 *gUnknown_203B204;

extern u8 gUnknown_80DB738;
extern u8 gFelicityMoney[];
extern u8 gFelicitySavings[];
extern u8 *gFelicityWithdraw;
extern u8 *gFelicityDeposit;

extern void sub_8008C54(u32);
extern void sub_80073B8(u32);
extern void xxx_call_draw_string(s32 x, u32 y, u8 *, u32 , u32);
extern void sub_8012BC4(u32 x, u32 y, u32, u32, u32, u32);
extern void sub_80073E0(u32);
extern void sub_8013C68(u32 *);
extern s32 sub_80144A4(s32 *);
extern void UpdateFelicityBankState(u32);
extern void PlaySound(u32);

extern u32 sub_8013BBC(u32 *);
void sub_8016B48(u8 action);

#define FELICITY_BANK_ACTION_WITHDRAW 0
#define FELICITY_BANK_ACTION_DEPOSIT 1

void sub_80169BC(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        gUnknown_203B204->unk10  = temp;
        switch(temp)
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
  switch(sub_8013BBC(&gUnknown_203B204->unk64))
  {
      case 1:
        sub_8016B48(FELICITY_BANK_ACTION_DEPOSIT);
        break;
      case 3:
          gUnknown_203B204->chosenAmount = gUnknown_203B204->unk64;
          gUnknown_203B460->teamSavings += gUnknown_203B204->chosenAmount;
          gUnknown_203B460->teamMoney -= gUnknown_203B204->chosenAmount;
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
  switch(sub_8013BBC(&gUnknown_203B204->unk64))
  {
      case 1:
        sub_8016B48(FELICITY_BANK_ACTION_WITHDRAW);
        break;
      case 3:
          gUnknown_203B204->chosenAmount = gUnknown_203B204->unk64;
          gUnknown_203B460->teamMoney += gUnknown_203B204->chosenAmount;
          gUnknown_203B460->teamSavings -= gUnknown_203B204->chosenAmount;
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
  
  if (sub_80144A4(&auStack8) == 0) {
    UpdateFelicityBankState(gUnknown_203B204->unk8);
  }
}

void sub_8016B24(void)
{
  s32 auStack8;
  
  if (sub_80144A4(&auStack8) == 4) {
    UpdateFelicityBankState(gUnknown_203B204->unk8);
  }
}

void sub_8016B48(u8 action)
{
  
  sub_8008C54(gUnknown_203B204->unk78);
  sub_80073B8(gUnknown_203B204->unk78);
  if (action != FELICITY_BANK_ACTION_WITHDRAW) {
     xxx_call_draw_string(12,0,gFelicityDeposit,gUnknown_203B204->unk78,0);
  }
  else {
     xxx_call_draw_string(12,0,gFelicityWithdraw,gUnknown_203B204->unk78,0);
  }
  sub_8013C68(&gUnknown_203B204->unk64);
  sub_80073E0(gUnknown_203B204->unk78);
}

void CreateFelicityMoneySavingsHeader(u32 param_1)
{
  sub_8008C54(param_1);
  sub_80073B8(param_1);
  xxx_call_draw_string(16, 4, gFelicityMoney, param_1, 0);
  sub_8012BC4(96, 4, gUnknown_203B460->teamMoney, 5, 5, param_1);
  xxx_call_draw_string(112, 4, gFelicitySavings, param_1, 0);
  sub_8012BC4(200,4,gUnknown_203B460->teamSavings,7,5,param_1);
  sub_80073E0(param_1);
}

void sub_8016C40(u32 param_1)
{ 
  sub_8008C54(param_1);
  sub_80073B8(param_1);
  xxx_call_draw_string(6, 0, &gUnknown_80DB738,param_1, 0); // Money
  sub_8012BC4(42, 12, gUnknown_203B460->teamMoney, 5, 5, param_1);
  sub_80073E0(param_1);
}
