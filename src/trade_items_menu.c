#include "global.h"
#include "input.h"
#include "trade_items_menu.h"

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
extern void sub_8035CC0(struct unkData *, u32);
extern void sub_801CCD8();
extern u32 sub_801B410();
extern void sub_801B450();
extern void sub_801CB5C(u32); 
extern void sub_8035CF4(u32 *, u32, u32); 
extern u32 sub_8013BBC(u32 *);
void sub_8036F30();
extern void sub_80369D0();
extern void sub_8012574(u32);
void PrintTradeItemsLinkError(u32);




void sub_803652C();
void sub_8036590();
void sub_80365AC();
void sub_8036674();
void sub_8036788();
void sub_8036728();
extern void sub_8036830();
void sub_803689C();
void sub_80368D4();
void sub_8036934();
void sub_8036950();
extern void sub_8036AA4();
extern void sub_80369FC();
extern void sub_8036A18();
extern void sub_8036A34();
extern void sub_8036A7C();
extern void sub_8036A54();
extern void sub_8036ADC();

// 11 was another saving too?
enum TradeItemsScreens
{
    TRADE_ITEMS_MAIN_MENU,
    TRADE_ITEMS_SEND_ITEM,
    TRADE_ITEMS_SEND_ITEM_SELECTION,
    TRADE_ITEMS_SEND_ITEM_POPUP_MENU,
    TRADE_ITEMS_SEND_ITEM_NUMBER,
    TRADE_ITEMS_ITEM_INFO,
    TRADE_ITEMS_SEND_ITEM_CONFIRM,
    TRADE_ITEMS_RECEIVE_ITEM,
    TRADE_ITEMS_IN_COMMUNICATION = 9,
    TRADE_ITEMS_PREPARE_TRADE_SAVING = 15,
    TRADE_ITEMS_EXIT = 18,
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
      case TRADE_ITEMS_SEND_ITEM:
        sub_8036590();
        break;
      case TRADE_ITEMS_SEND_ITEM_SELECTION:
        sub_80365AC();
        break;
      case TRADE_ITEMS_SEND_ITEM_POPUP_MENU:
        sub_8036674();
        break;
      case TRADE_ITEMS_ITEM_INFO:
        sub_8036728();
        break;
      case TRADE_ITEMS_SEND_ITEM_NUMBER:
        sub_8036788();
        break;
      case TRADE_ITEMS_SEND_ITEM_CONFIRM:
        sub_8036830();
        break;
      case TRADE_ITEMS_RECEIVE_ITEM:
        sub_803689C();
        break;
      case 8:
        sub_80368D4();
        break;
      case TRADE_ITEMS_PREPARE_TRADE_SAVING:
        sub_8036A7C();
        break;
      case TRADE_ITEMS_IN_COMMUNICATION:
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
      case TRADE_ITEMS_EXIT: // when you exit the menu to Main
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
            SetTradeItemMenu(TRADE_ITEMS_EXIT);
      }
  }
}

void sub_8036590(void)
{
  s32 iVar1;
  
  if (sub_80144A4(&iVar1) == 0)
    SetTradeItemMenu(TRADE_ITEMS_SEND_ITEM_SELECTION);
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
        SetTradeItemMenu(TRADE_ITEMS_SEND_ITEM_POPUP_MENU);
        break;
    case 4:
        gUnknown_203B358->unk4 = 2;
        gUnknown_203B358->unk25E = sub_801CB24();
        gUnknown_203B358->unk25D = 1;
        sub_8006518(&gUnknown_203B358->unk1E4);
        ResetUnusedInputStruct();
        sub_800641C(0,1,1);
        sub_801B3C0(&gUnknown_203B358->unk25C);
        SetTradeItemMenu(TRADE_ITEMS_ITEM_INFO);
        break;
  }
}

void sub_8036674(void)
{
  int menuAction;
  
  menuAction = -1;
  sub_801CA08(0);
  if (sub_8012FD8(&gUnknown_203B358->unk134) == '\0') {
    sub_8013114(&gUnknown_203B358->unk134, &menuAction);
  }
  switch(menuAction){
    case 3: // confirm
        SetTradeItemMenu(TRADE_ITEMS_SEND_ITEM_NUMBER);
        break;
    case 4: // Info
        gUnknown_203B358->unk4 = 0x13;
        sub_8006518(&gUnknown_203B358->unk1E4);
        ResetUnusedInputStruct();
        sub_800641C(0,1,1);
        sub_801B3C0(&gUnknown_203B358->unk25C);
        SetTradeItemMenu(TRADE_ITEMS_ITEM_INFO);
        break;
    case 7:
    case 0:
        // Cancel
        sub_8035CC0(gUnknown_203B358->unk184, 3);
        sub_801CCD8();
        SetTradeItemMenu(TRADE_ITEMS_SEND_ITEM_SELECTION);
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
        sub_800641C(&gUnknown_203B358->unk1E4, 1, 1);
        sub_801CB5C(1);
        if (gUnknown_203B358->unk4 == 0x13) {
            sub_8035CF4(&gUnknown_203B358->unk44, 3, 1);
            SetTradeItemMenu(TRADE_ITEMS_SEND_ITEM_POPUP_MENU);
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
        sub_8035CF4(&gUnknown_203B358->unk44, 3, 0);
        sub_8036F30();
        break;
    case 2:
        // If you back out of the # selection
        sub_8035CC0(gUnknown_203B358->unk184, 2);
        sub_801CCD8();
        sub_8035CF4(&gUnknown_203B358->unk44, 3, 1);
        SetTradeItemMenu(TRADE_ITEMS_SEND_ITEM_POPUP_MENU);
        break;
    case 3:
        // Confirm # of item
        gUnknown_203B358->unk25D = gUnknown_203B358->unk14;
        gUnknown_203B358->unk254 = gUnknown_203B358->unk25E;
        gUnknown_203B358->unk258 = gUnknown_203B358->unk14;
        sub_801CBB8();
        SetTradeItemMenu(TRADE_ITEMS_SEND_ITEM_CONFIRM);
        break;
    case 0:
        break;
  }
}

#ifdef NONMATCHING
void sub_8036830(void)
{
  int menuAction;

  if (sub_80144A4(&menuAction) == 0) 
  {
      switch(menuAction){
        case 5:
            sub_801CBB8();
            // TODO: Statements are shifted around but is equivalent
            gUnknown_203B460->unk50[gUnknown_203B358->unk25E] -= gUnknown_203B358->unk14;
            SetTradeItemMenu(0xF);
            sub_8012574(0);
            break;
        case 6:
        case 0:
            SetTradeItemMenu(0);
            break;
        }
  }
}
#else
NAKED
void sub_8036830(void)
{
	asm_unified("\tpush {lr}\n"
	"\tsub sp, 0x4\n"
	"\tmov r0, sp\n"
	"\tbl sub_80144A4\n"
	"\tcmp r0, 0\n"
	"\tbne _08036896\n"
	"\tldr r0, [sp]\n"
	"\tcmp r0, 0x5\n"
	"\tbeq _08036854\n"
	"\tcmp r0, 0x5\n"
	"\tbgt _0803684E\n"
	"\tcmp r0, 0\n"
	"\tbeq _08036890\n"
	"\tb _08036896\n"
"_0803684E:\n"
	"\tcmp r0, 0x6\n"
	"\tbeq _08036890\n"
	"\tb _08036896\n"
"_08036854:\n"
	"\tbl sub_801CBB8\n"
	"\tldr r0, _08036884\n"
	"\tldr r2, [r0]\n"
	"\tldr r0, _08036888\n"
	"\tldr r1, [r0]\n"
	"\tldr r3, _0803688C\n"
	"\tadds r0, r1, r3\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, 1\n"
	"\tadds r2, 0x50\n"
	"\tadds r2, r0\n"
	"\tldrh r0, [r2]\n"
	"\tldr r1, [r1, 0x14]\n"
	"\tsubs r0, r1\n"
	"\tstrh r0, [r2]\n"
	"\tmovs r0, 0xF\n"
	"\tbl SetTradeItemMenu\n"
	"\tmovs r0, 0\n"
	"\tbl sub_8012574\n"
	"\tb _08036896\n"
	"\t.align 2, 0\n"
"_08036884: .4byte gUnknown_203B460\n"
"_08036888: .4byte gUnknown_203B358\n"
"_0803688C: .4byte 0x0000025e\n"
"_08036890:\n"
	"\tmovs r0, 0\n"
	"\tbl SetTradeItemMenu\n"
"_08036896:\n"
	"\tadd sp, 0x4\n"
	"\tpop {r0}\n"
	"\tbx r0");
}
#endif

void sub_803689C(void)
{
  int menuAction;

  if (sub_80144A4(&menuAction) == 0) {
      switch(menuAction){
        case 5:
            SetTradeItemMenu(TRADE_ITEMS_IN_COMMUNICATION);
            break;
        case 7:
        case 0:
            SetTradeItemMenu(TRADE_ITEMS_EXIT);
            break;
    }
  }
}

void sub_80368D4(void)
{
  int menuAction;

  if (sub_80144A4(&menuAction) == 0) {
    switch(menuAction){
        case 5:
            SetTradeItemMenu(TRADE_ITEMS_IN_COMMUNICATION);
            break;
        case 7:
        case 0:
            if ((gUnknown_203B358->unk254 != 0) && (gUnknown_203B358->unk258 != 0))
            {
                sub_80369D0();
                SetTradeItemMenu(0x11);
                sub_8012574(0);
            }
        break;
    }
  }
}

void sub_8036934(void)
{
  s32 iVar1;

  if (sub_80144A4(&iVar1) == 0) {
    SetTradeItemMenu(10);
  }
}

void sub_8036950(void)
{
  s32 iVar1;

  if (sub_80144A4(&iVar1) == 0) {
    if (gUnknown_203B358->linkStatus == 0) {
      switch(gUnknown_203B358->unk8){
        case 0:
          SetTradeItemMenu(0xd);
          break;
        case 1:
          SetTradeItemMenu(0xe);
          break;
        default:
          break;
      }
    }
    else {
      if (((gUnknown_203B358->unk8 == 0) && (gUnknown_203B358->unk254 != 0))
         && (gUnknown_203B358->unk258 != 0)) {
        sub_80369D0();
        SetTradeItemMenu(0xb);
        sub_8012574(0);
      }
      else {
        PrintTradeItemsLinkError(gUnknown_203B358->linkStatus);
        SetTradeItemMenu(0xc);
      }
    }
  }
}
