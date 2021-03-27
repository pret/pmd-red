#include "global.h"
#include "input.h"

struct TradeItemsMenu
{
    // size: 0x3A0
    u32 currMenu;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14; // item #
    u8 fill18[0x44 - 0x18];
    u32 unk44;
    u8 fill8[0x134 - 0x48];
    u32 unk134;
    u8 fill138[0x184 - 0x138];
    u32 unk184;
    u8 fill188[0x1E4 - 0x188];
    u32 unk1E4;
    u8 fill1E8[0x254 - 0x1E8];
    u8 unk254;
    u8 fill255[3];
    u32 unk258;
    u8 unk25C;
    u8 unk25D;
    u8 unk25E;
    u8 fill25F[0x3A0 - 0x25F];
};

extern struct TradeItemsMenu *gUnknown_203B358;

extern void *MemoryAlloc(u32, u32);
extern void MemoryFill8(u8 *, u32, u32);
extern void sub_800641C(u32 *, u32, u32);
extern void sub_8035C1C();
extern void sub_8035DA0();
extern void SetTradeItemMenu(u32);
extern s32 sub_80144A4(s32 *);
extern u32 sub_801CA08(u32);
extern void sub_801CBB8();
extern u8 sub_801CB24();
extern void sub_8006518(u32 *);
extern void sub_801B3C0(u8 *);
extern u8 sub_8012FD8(u32 *);
extern void sub_8013114(u32 *, s32 *);
extern void sub_8035CC0(u32 *, u32);
extern void sub_801CCD8();
extern u32 sub_801B410();
extern void sub_801B450();
extern void sub_801CB5C(u32); 
extern void sub_8035CF4(u32 *, u32, u32); 
extern u32 sub_8013BBC(u32 *);
extern void sub_8036F30();

void sub_803652C();
void sub_8036590();
extern void sub_80365AC();
extern void sub_8036674();
extern void sub_8036788();
extern void sub_8036728();
extern void sub_8036830();
extern void sub_803689C();
extern void sub_80368D4();
extern void sub_8036934();
extern void sub_8036950();
extern void sub_8036AA4();
extern void sub_80369FC();
extern void sub_8036A18();
extern void sub_8036A34();
extern void sub_8036A7C();
extern void sub_8036A54();
extern void sub_8036ADC();

enum TradeItemsScreens
{
    TRADE_ITEMS_MAIN_MENU,
    TRADE_ITEMS_SEND_ITEM,
    TRADE_ITEMS_RECEIVE_ITEM = 7,
};


u32 CreateTradeItemsMenu(void)
{
  
  ResetUnusedInputStruct();
  sub_800641C(0,1,1);
  gUnknown_203B358 = MemoryAlloc(sizeof(struct TradeItemsMenu), 8);
  MemoryFill8((u8 *)gUnknown_203B358, 0, sizeof(struct TradeItemsMenu));
  sub_8035C1C();
  sub_8035DA0();
  gUnknown_203B358->unk4 = 0x13;
  SetTradeItemMenu(TRADE_ITEMS_MAIN_MENU);
  return 1;
}

u32 UpdateTradeItemsMenu(void)
{
  
  switch(gUnknown_203B358->currMenu) {
      case TRADE_ITEMS_MAIN_MENU:
        sub_803652C();
        break;
      case 1:
        sub_8036590();
        break;
      case 2:
        sub_80365AC();
        break;
      case 3:
        sub_8036674();
        break;
      case 5:
        sub_8036728();
        break;
      case 4:
        sub_8036788();
        break;
      case 6:
        sub_8036830();
        break;
      case 7:
        sub_803689C();
        break;
      case 8:
        sub_80368D4();
        break;
      case 0xf:
        sub_8036A7C();
        break;
      case 9:
        sub_8036934();
        break;
      case 10:
        sub_8036950();
        break;
      case 0xb:
        sub_8036AA4();
        break;
      case 0xc:
        sub_80369FC();
        break;
      case 0xe:
        sub_8036A34();
        break;
      case 0x10:
        sub_8036A54();
        break;
      case 0xd:
        sub_8036A18();
        break;
      case 0x11:
        sub_8036ADC();
        break;
      case 0x12: // when you exit the menu to Main
        return 3;
  }
  return 0;
}

void sub_803652C(void)
{
  s32 menuAction;
  
  if (sub_80144A4(&menuAction) == 0) {
      switch(menuAction)
      {
        case 1:
            // Send Item
            gUnknown_203B358->unk8 = 0;
            gUnknown_203B358->unk10 = 1;
            SetTradeItemMenu(TRADE_ITEMS_SEND_ITEM);
            break;
        case 2:
            // Receive Item
            gUnknown_203B358->unk8 = 1;
            gUnknown_203B358->unk10 = 2;
            SetTradeItemMenu(TRADE_ITEMS_RECEIVE_ITEM);
            break;
        case 0:
        case 7:
            // Cancel
            SetTradeItemMenu(0x12);
      }
  }
}

void sub_8036590(void)
{
  s32 iVar1;
  
  if (sub_80144A4(&iVar1) == 0)
    SetTradeItemMenu(2);
}

void sub_80365AC(void)
{ 
  gUnknown_203B358->unk25E = 0;
  gUnknown_203B358->unk25D = 1;
  gUnknown_203B358->unk25C = 0;
  switch(sub_801CA08(1)){
    case 2:
        // Cancel
        sub_801CBB8();
        SetTradeItemMenu(TRADE_ITEMS_MAIN_MENU);
        break;
    case 3:
        // Pop up menu with Confirm, Info, Cancel
        gUnknown_203B358->unk25E = sub_801CB24();
        gUnknown_203B358->unk25D = 1;
        SetTradeItemMenu(3);
        break;
    case 4:
        gUnknown_203B358->unk4 = 2;
        gUnknown_203B358->unk25E = sub_801CB24();
        gUnknown_203B358->unk25D = 1;
        sub_8006518(&gUnknown_203B358->unk1E4);
        ResetUnusedInputStruct();
        sub_800641C(0,1,1);
        sub_801B3C0(&gUnknown_203B358->unk25C);
        SetTradeItemMenu(5);
        break;
  }
}

void sub_8036674(void)
{
  int local_c;
  
  local_c = -1;
  sub_801CA08(0);
  if (sub_8012FD8(&gUnknown_203B358->unk134) == '\0') {
    sub_8013114(&gUnknown_203B358->unk134, &local_c);
  }
  switch(local_c){
    case 3: // confirm
        SetTradeItemMenu(4);
        break;
    case 4: // Info
        gUnknown_203B358->unk4 = 0x13;
        sub_8006518(&gUnknown_203B358->unk1E4);
        ResetUnusedInputStruct();
        sub_800641C(0,1,1);
        sub_801B3C0(&gUnknown_203B358->unk25C);
        SetTradeItemMenu(5);
        break;
    case 7:
    case 0:
        // Cancel
        sub_8035CC0(&gUnknown_203B358->unk184, 3);
        sub_801CCD8();
        SetTradeItemMenu(2);
        break;
  }
}

void sub_8036728(void)
{
  switch(sub_801B410())
  {
      case 2:
      case 3:
        sub_801B450();
        ResetUnusedInputStruct();
        sub_800641C(&gUnknown_203B358->unk1E4,1,1);
        sub_801CB5C(1);
        if (gUnknown_203B358->unk4 == 0x13) {
            sub_8035CF4(&gUnknown_203B358->unk44,3,1);
            SetTradeItemMenu(3);
        }
        else {
            SetTradeItemMenu(gUnknown_203B358->unk4);
        }
    default:
    case 1:
        break;
  }
}

void sub_8036788(void)
{ 
  sub_8012FD8(&gUnknown_203B358->unk134);
  sub_801CA08(0);
  switch(sub_8013BBC(&gUnknown_203B358->unk14)){
    case 1:
        // When you change the #
        sub_801CCD8();
        sub_8035CF4(&gUnknown_203B358->unk44,3,0);
        sub_8036F30();
        break;
    case 2:
        // If you back out of the # selection
        sub_8035CC0(&gUnknown_203B358->unk184,2);
        sub_801CCD8();
        sub_8035CF4(&gUnknown_203B358->unk44,3,1);
        SetTradeItemMenu(3);
        break;
    case 3:
        // Confirm # of item
        gUnknown_203B358->unk25D = gUnknown_203B358->unk14;
        gUnknown_203B358->unk254 = gUnknown_203B358->unk25E;
        gUnknown_203B358->unk258 = gUnknown_203B358->unk14;
        sub_801CBB8();
        SetTradeItemMenu(6);
        break;
    case 0:
        break;
  }
}
