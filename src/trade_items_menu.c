#include "global.h"
#include "input.h"
#include "trade_items_menu.h"

extern struct TradeItemsMenu *gUnknown_203B358;

struct unkStruct_203B460
{
    u8 unk0[0x50];
    u16 unk50[10];
};


extern struct unkStruct_203B460 *gUnknown_203B460; // TODO unify this
extern u32 gUnknown_202DE30;
extern u32 gUnknown_202DE58;
extern struct unkData gUnknown_80E6174;

// Trade Items Menu Link Error Messages
extern u32 gTradeItemsCommunicationError;
extern u32 gUnknown_80E639C;
extern u32 gUnknown_80E63F8;
extern u32 gUnknown_80E6448;
extern u32 gUnknown_80E64AC;
extern u32 gTradeItemsHowManyText;
extern u32 gUnknown_80E60A0;
extern u32 gUnknown_80E60D4;
extern u32 gUnknown_80E61A4;
extern u32 gUnknown_80E61C0;
extern u32 gUnknown_80E60EC;
extern u32 gUnknown_80E6104;
extern u32 gUnknown_80E6154;
extern u32 gUnknown_80E61E4;

extern u32 gUnknown_80E6214;
extern u32 gUnknown_80E618C;
extern u32 gUnknown_80E6268;
extern u32 gUnknown_80E62C4;
extern u32 gUnknown_80E6358;
extern u32 gUnknown_80E6314;

extern void sub_8013AA0(u32 *);

extern void *MemoryAlloc(u32, u32);
extern void MemoryFill8(u8 *, u32, u32);
extern void MemoryFree(void *);
extern void sub_800641C(u32 *, u32, u32);
extern void sub_8035C1C();
extern void sub_8035DA0();
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
extern void sub_80141B4(u32 *, u32, u32, u32);

extern void sub_8012574(u32);
extern u8 sub_8012600(void);
extern void sub_8012750();

extern void sub_8008C54(u32);
extern void sub_80073B8(u32);
extern void sub_8013C68(u32 *);
extern void sub_80073E0(u32);
extern void xxx_call_draw_string(u32, u32, u32 *, u32, u32);
extern u8 sub_801CF14(u32);
extern u32 sub_801D008();
extern void sub_8090DC4(u32 *, u8, u32);
extern void sub_801C8C4(u32, u32, s32 *, u32);




void SetTradeItemMenu(u32);
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
void sub_8036AA4();
void sub_80369FC();
void sub_8036A18();
void sub_8036A34();
void sub_8036A7C();
void sub_8036A54();
void sub_8036ADC();

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
        gUnknown_203B358->unk254.unk0 = gUnknown_203B358->unk25E;
        gUnknown_203B358->unk254.unk4 = gUnknown_203B358->unk14;
        sub_801CBB8();
        SetTradeItemMenu(TRADE_ITEMS_SEND_ITEM_CONFIRM);
        break;
    case 0:
        break;
  }
}

void sub_8036830(void)
{
  int menuAction;
  u16 load;

  if (sub_80144A4(&menuAction) == 0) 
  {
      switch(menuAction){
        case 5:
            sub_801CBB8();
            // Used temp var to get correct statements
            load = gUnknown_203B460->unk50[gUnknown_203B358->unk25E];
            load -= gUnknown_203B358->unk14;
            gUnknown_203B460->unk50[gUnknown_203B358->unk25E] = load;
            SetTradeItemMenu(TRADE_ITEMS_PREPARE_TRADE_SAVING);
            sub_8012574(0);
            break;
        case 6:
        case 0:
            SetTradeItemMenu(TRADE_ITEMS_MAIN_MENU);
            break;
        }
  }
}

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
            if ((gUnknown_203B358->unk254.unk0 != 0) && (gUnknown_203B358->unk254.unk4 != 0))
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
      if (((gUnknown_203B358->unk8 == 0) && (gUnknown_203B358->unk254.unk0 != 0))
         && (gUnknown_203B358->unk254.unk4 != 0)) {
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

void sub_80369D0(void)
{
    // Use temp var to get correct statements 
    u16 load;
    load = gUnknown_203B460->unk50[gUnknown_203B358->unk254.unk0];
    load += gUnknown_203B358->unk254.unk4;
    gUnknown_203B460->unk50[gUnknown_203B358->unk254.unk0] = load;
}

void sub_80369FC(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        SetTradeItemMenu(TRADE_ITEMS_MAIN_MENU);
    }
}


void sub_8036A18(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        SetTradeItemMenu(TRADE_ITEMS_EXIT);
    }
}

void sub_8036A34(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        SetTradeItemMenu(0x10);
        sub_8012574(0);
    }
}

void sub_8036A54(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        if(sub_8012600() == 0)
        {
            sub_8012750();
            SetTradeItemMenu(TRADE_ITEMS_EXIT);
        }
    }
}

void sub_8036A7C(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        if(sub_8012600() == 0)
        {
            sub_8012750(); // cleans up from Save Message
            SetTradeItemMenu(0x8);
        }
    }
}

void sub_8036AA4(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        if(sub_8012600() == 0)
        {
            sub_8012750();
            PrintTradeItemsLinkError(gUnknown_203B358->linkStatus);
            SetTradeItemMenu(0xC);
        }
    }
}

void sub_8036ADC(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        if(sub_8012600() == 0)
        {
            sub_8012750();
            SetTradeItemMenu(TRADE_ITEMS_EXIT);
        }
    }
}

void CleanTradeItemsMenu(void)
{
    if(gUnknown_203B358 != NULL)
    {
        MemoryFree(gUnknown_203B358);
        gUnknown_203B358 = NULL;
        sub_801CBB8();
    }
}

void nullsub_52(void)
{
}

#ifdef NONMATCHING
void sub_8036B28(void)
{
  int iVar3;
  u32 uVar4;
  s32 local_10;
  u32 load_1;
  u32 load_2;
  struct TradeSubStruct *temp;
  struct TradeSubStruct *temp2;
  
  switch(gUnknown_203B358->currMenu) {
    case 0:
        if (sub_801CF14(0) != '\0') {
            sub_8014248(&gUnknown_80E61A4,0,1,&gUnknown_80E60D4,0,4,0,0,0x101);
        }
        else {
            sub_8014248(&gUnknown_80E61A4,0,1,&gUnknown_80E60A0,0,4,0,0,0x101);
        }
        break;
    case 1:
        sub_80141B4(&gUnknown_80E61C0,0,0,0x101);
        break;
    case 2:
        if (sub_801D008() == 0) {
            ResetUnusedInputStruct();
            sub_800641C(0,1,1);
            local_10 = 0x20003;
            sub_801C8C4(0,1,&local_10,9);
        }
        break;
    case 3:
        sub_8006518(gUnknown_203B358->unk184);
        SetMenuItems(&gUnknown_203B358->unk44,gUnknown_203B358->unk184,3,&gUnknown_80E60EC,
                    &gUnknown_80E6104,1,0,0);
        sub_801CCD8();
        sub_8035CF4(&gUnknown_203B358->unk44,3,1);
        break;
    case 4:
        sub_8036F74();
        break;
    case 6:
        gUnknown_202DE30 = gUnknown_203B358->unk14;
        sub_8090DC4(&gUnknown_202DE58,gUnknown_203B358->unk25E,0);
        sub_8014248(&gUnknown_80E61E4,0,5, &gUnknown_80E6154,0,4,0,0,0x101);
        break;
    case 7:
        sub_8014248(&gUnknown_80E6214,0,5,&gUnknown_80E618C,0,4,0,0,0x101);
        break;
    case 8:
        sub_8014248(&gUnknown_80E6268,0,5,&gUnknown_80E618C,0,4,0,0,0x101);
        break;
    case 9:
        nullsub_23(0);
        sub_80141B4(&gUnknown_80E62C4,0,0,0);
        break;
    case 10:
        gUnknown_203B358->linkStatus = 0;
    // TODO
    // Regs mess up here
    // Needs a mov r2, 0
    // and     mov r3, 0
        temp = &gUnknown_203B358->unk244;
        temp->unk0 = 0;
        temp->unk4 = 0;

        temp += 1; // move to unk24C

        temp->unk0 = 0;
        temp->unk4 = 0;
    // Regs are fixed back up after

        sub_8011830();
        iVar3 = sub_8037B28(gUnknown_203B358->unk8);
        gUnknown_203B358->linkStatus = iVar3;
        if(iVar3 == 0){
        switch(gUnknown_203B358->unk8){
            // Fallthrough needed on each case
            case 0:
                temp = &gUnknown_203B358->unk244;
                temp2 = &gUnknown_203B358->unk254;
                load_2 = temp2->unk4;
                temp->unk0 = temp2->unk0;
                temp->unk4 = load_2;
            case 1:
                gUnknown_203B358->linkStatus = sub_8037D64(gUnknown_203B358->unk8,&gUnknown_203B358->unk244,&gUnknown_203B358->unk24C);
            default:
                break;
        }
        }
        // Needed this check for code generation
        if(gUnknown_203B358->linkStatus == 0 && gUnknown_203B358->unk8 <= 1){
            gUnknown_203B358->linkStatus = sub_80381F4(gUnknown_203B358->unk8,&gUnknown_203B358->unk244,&gUnknown_203B358->unk24C);
        }
        xxx_call_start_bg_music();
        break;
    case 0xe:
        if (gUnknown_203B358->unk24C.unk4 == 0) {
            gUnknown_202DE30 = gUnknown_203B358->unk244.unk4;
            // Cast is needed
            sub_8090DC4(&gUnknown_202DE58,(u8)gUnknown_203B358->unk244.unk0,0);
        }
        else {
            gUnknown_202DE30 = gUnknown_203B358->unk24C.unk4;
            // Cast is needed
            sub_8090DC4(&gUnknown_202DE58,(u8)gUnknown_203B358->unk24C.unk0,0);
        }
        sub_80141B4(&gUnknown_80E6314,0,0,0x101);
        break;
    case 0xd:
        gUnknown_202DE30 = gUnknown_203B358->unk14;
        sub_8090DC4(&gUnknown_202DE58,gUnknown_203B358->unk25E,0);
        sub_80141B4(&gUnknown_80E6358,0,0,0x101);
        break;
    case 0xB:
    case 0xC:
    case 0xF:
    case 0x10:
    case 0x11:
    case 0x12:
    default:
        break;
  }
}
#else
NAKED
void sub_8036B28(void)
{
	asm_unified("\tpush {r4,r5,lr}\n"
	"\tsub sp, 0x18\n"
	"\tldr r1, _08036B44\n"
	"\tldr r0, [r1]\n"
	"\tldr r0, [r0]\n"
	"\tadds r5, r1, 0\n"
	"\tcmp r0, 0x12\n"
	"\tbls _08036B3A\n"
	"\tb _08036DFA\n"
"_08036B3A:\n"
	"\tlsls r0, 2\n"
	"\tldr r1, _08036B48\n"
	"\tadds r0, r1\n"
	"\tldr r0, [r0]\n"
	"\tmov pc, r0\n"
	"\t.align 2, 0\n"
"_08036B44: .4byte gUnknown_203B358\n"
"_08036B48: .4byte _08036B4C\n"
	"\t.align 2, 0\n"
"_08036B4C:\n"
	"\t.4byte _08036B98\n"
	"\t.4byte _08036BDC\n"
	"\t.4byte _08036BE4\n"
	"\t.4byte _08036C14\n"
	"\t.4byte _08036C58\n"
	"\t.4byte _08036DFA\n"
	"\t.4byte _08036C5E\n"
	"\t.4byte _08036C90\n"
	"\t.4byte _08036C98\n"
	"\t.4byte _08036CC0\n"
	"\t.4byte _08036CD8\n"
	"\t.4byte _08036DFA\n"
	"\t.4byte _08036DFA\n"
	"\t.4byte _08036DD8\n"
	"\t.4byte _08036D70\n"
	"\t.4byte _08036DFA\n"
	"\t.4byte _08036DFA\n"
	"\t.4byte _08036DFA\n"
	"\t.4byte _08036DFA\n"
"_08036B98:\n"
	"\tmovs r0, 0\n"
	"\tbl sub_801CF14\n"
	"\tlsls r0, 24\n"
	"\tlsrs r2, r0, 24\n"
	"\tcmp r2, 0\n"
	"\tbeq _08036BB8\n"
	"\tldr r0, _08036BB0\n"
	"\tldr r3, _08036BB4\n"
	"\tmovs r2, 0\n"
	"\tb _08036BBC\n"
	"\t.align 2, 0\n"
"_08036BB0: .4byte gUnknown_80E61A4\n"
"_08036BB4: .4byte gUnknown_80E60D4\n"
"_08036BB8:\n"
	"\tldr r0, _08036BD4\n"
	"\tldr r3, _08036BD8\n"
"_08036BBC:\n"
	"\tstr r2, [sp]\n"
	"\tmovs r1, 0x4\n"
	"\tstr r1, [sp, 0x4]\n"
	"\tstr r2, [sp, 0x8]\n"
	"\tstr r2, [sp, 0xC]\n"
	"\tadds r1, 0xFD\n"
	"\tstr r1, [sp, 0x10]\n"
	"\tmovs r1, 0\n"
	"\tmovs r2, 0x1\n"
	"\tbl sub_8014248\n"
	"\tb _08036DFA\n"
	"\t.align 2, 0\n"
"_08036BD4: .4byte gUnknown_80E61A4\n"
"_08036BD8: .4byte gUnknown_80E60A0\n"
"_08036BDC:\n"
	"\tldr r0, _08036BE0\n"
	"\tb _08036DBA\n"
	"\t.align 2, 0\n"
"_08036BE0: .4byte gUnknown_80E61C0\n"
"_08036BE4:\n"
	"\tbl sub_801D008\n"
	"\tcmp r0, 0\n"
	"\tbeq _08036BEE\n"
	"\tb _08036DFA\n"
"_08036BEE:\n"
	"\tbl ResetUnusedInputStruct\n"
	"\tmovs r0, 0\n"
	"\tmovs r1, 0x1\n"
	"\tmovs r2, 0x1\n"
	"\tbl sub_800641C\n"
	"\tldr r0, _08036C10\n"
	"\tstr r0, [sp, 0x14]\n"
	"\tmovs r0, 0\n"
	"\tmovs r1, 0x1\n"
	"\tadd r2, sp, 0x14\n"
	"\tmovs r3, 0x9\n"
	"\tbl sub_801C8C4\n"
	"\tb _08036DFA\n"
	"\t.align 2, 0\n"
"_08036C10: .4byte 0x00020003\n"
"_08036C14:\n"
	"\tldr r0, [r5]\n"
	"\tmovs r4, 0xC2\n"
	"\tlsls r4, 1\n"
	"\tadds r0, r4\n"
	"\tbl sub_8006518\n"
	"\tldr r1, [r5]\n"
	"\tadds r0, r1, 0\n"
	"\tadds r0, 0x44\n"
	"\tadds r1, r4\n"
	"\tldr r3, _08036C50\n"
	"\tldr r2, _08036C54\n"
	"\tstr r2, [sp]\n"
	"\tmovs r2, 0x1\n"
	"\tstr r2, [sp, 0x4]\n"
	"\tmovs r2, 0\n"
	"\tstr r2, [sp, 0x8]\n"
	"\tstr r2, [sp, 0xC]\n"
	"\tmovs r2, 0x3\n"
	"\tbl SetMenuItems\n"
	"\tbl sub_801CCD8\n"
	"\tldr r0, [r5]\n"
	"\tadds r0, 0x44\n"
	"\tmovs r1, 0x3\n"
	"\tmovs r2, 0x1\n"
	"\tbl sub_8035CF4\n"
	"\tb _08036DFA\n"
	"\t.align 2, 0\n"
"_08036C50: .4byte gUnknown_80E60EC\n"
"_08036C54: .4byte gUnknown_80E6104\n"
"_08036C58:\n"
	"\tbl sub_8036F74\n"
	"\tb _08036DFA\n"
"_08036C5E:\n"
	"\tldr r2, _08036C7C\n"
	"\tldr r1, [r5]\n"
	"\tldr r0, [r1, 0x14]\n"
	"\tstr r0, [r2]\n"
	"\tldr r0, _08036C80\n"
	"\tldr r2, _08036C84\n"
	"\tadds r1, r2\n"
	"\tldrb r1, [r1]\n"
	"\tmovs r2, 0\n"
	"\tbl sub_8090DC4\n"
	"\tldr r0, _08036C88\n"
	"\tldr r3, _08036C8C\n"
	"\tb _08036C9C\n"
	"\t.align 2, 0\n"
"_08036C7C: .4byte gUnknown_202DE30\n"
"_08036C80: .4byte gUnknown_202DE58\n"
"_08036C84: .4byte 0x0000025e\n"
"_08036C88: .4byte gUnknown_80E61E4\n"
"_08036C8C: .4byte gUnknown_80E6154\n"
"_08036C90:\n"
	"\tldr r0, _08036C94\n"
	"\tb _08036C9A\n"
	"\t.align 2, 0\n"
"_08036C94: .4byte gUnknown_80E6214\n"
"_08036C98:\n"
	"\tldr r0, _08036CB8\n"
"_08036C9A:\n"
	"\tldr r3, _08036CBC\n"
"_08036C9C:\n"
	"\tmovs r2, 0\n"
	"\tstr r2, [sp]\n"
	"\tmovs r1, 0x4\n"
	"\tstr r1, [sp, 0x4]\n"
	"\tstr r2, [sp, 0x8]\n"
	"\tstr r2, [sp, 0xC]\n"
	"\tadds r1, 0xFD\n"
	"\tstr r1, [sp, 0x10]\n"
	"\tmovs r1, 0\n"
	"\tmovs r2, 0x5\n"
	"\tbl sub_8014248\n"
	"\tb _08036DFA\n"
	"\t.align 2, 0\n"
"_08036CB8: .4byte gUnknown_80E6268\n"
"_08036CBC: .4byte gUnknown_80E618C\n"
"_08036CC0:\n"
	"\tmovs r0, 0\n"
	"\tbl nullsub_23\n"
	"\tldr r0, _08036CD4\n"
	"\tmovs r1, 0\n"
	"\tmovs r2, 0\n"
	"\tmovs r3, 0\n"
	"\tbl sub_80141B4\n"
	"\tb _08036DFA\n"
	"\t.align 2, 0\n"
"_08036CD4: .4byte gUnknown_80E62C4\n"
"_08036CD8:\n"
	"\tldr r4, _08036D18\n"
	"\tldr r1, [r4]\n"
	"\tmovs r0, 0\n"
	"\tstr r0, [r1, 0xC]\n"
	"\tmovs r2, 0\n"
	"\tmovs r3, 0\n"
	"\tmovs r5, 0x91\n"
	"\tlsls r5, 2\n"
	"\tadds r0, r1, r5\n"
	"\tstr r2, [r0]\n"
	"\tstr r3, [r0, 0x4]\n"
	"\tmovs r0, 0x93\n"
	"\tlsls r0, 2\n"
	"\tadds r1, r0\n"
	"\tstr r2, [r1]\n"
	"\tstr r3, [r1, 0x4]\n"
	"\tbl sub_8011830\n"
	"\tldr r0, [r4]\n"
	"\tldr r0, [r0, 0x8]\n"
	"\tbl sub_8037B28\n"
	"\tldr r4, [r4]\n"
	"\tstr r0, [r4, 0xC]\n"
	"\tcmp r0, 0\n"
	"\tbne _08036D44\n"
	"\tldr r0, [r4, 0x8]\n"
	"\tcmp r0, 0\n"
	"\tbeq _08036D1C\n"
	"\tcmp r0, 0x1\n"
	"\tbeq _08036D2C\n"
	"\tb _08036D44\n"
	"\t.align 2, 0\n"
"_08036D18: .4byte gUnknown_203B358\n"
"_08036D1C:\n"
	"\tadds r2, r4, r5\n"
	"\tmovs r1, 0x95\n"
	"\tlsls r1, 2\n"
	"\tadds r0, r4, r1\n"
	"\tldr r1, [r0, 0x4]\n"
	"\tldr r0, [r0]\n"
	"\tstr r0, [r2]\n"
	"\tstr r1, [r2, 0x4]\n"
"_08036D2C:\n"
	"\tldr r4, _08036D6C\n"
	"\tldr r2, [r4]\n"
	"\tldr r0, [r2, 0x8]\n"
	"\tmovs r3, 0x91\n"
	"\tlsls r3, 2\n"
	"\tadds r1, r2, r3\n"
	"\tadds r3, 0x8\n"
	"\tadds r2, r3\n"
	"\tbl sub_8037D64\n"
	"\tldr r1, [r4]\n"
	"\tstr r0, [r1, 0xC]\n"
"_08036D44:\n"
	"\tldr r4, _08036D6C\n"
	"\tldr r2, [r4]\n"
	"\tldr r0, [r2, 0xC]\n"
	"\tcmp r0, 0\n"
	"\tbne _08036D66\n"
	"\tldr r0, [r2, 0x8]\n"
	"\tcmp r0, 0x1\n"
	"\tbhi _08036D66\n"
	"\tmovs r3, 0x91\n"
	"\tlsls r3, 2\n"
	"\tadds r1, r2, r3\n"
	"\tadds r3, 0x8\n"
	"\tadds r2, r3\n"
	"\tbl sub_80381F4\n"
	"\tldr r1, [r4]\n"
	"\tstr r0, [r1, 0xC]\n"
"_08036D66:\n"
	"\tbl xxx_call_start_bg_music\n"
	"\tb _08036DFA\n"
	"\t.align 2, 0\n"
"_08036D6C: .4byte gUnknown_203B358\n"
"_08036D70:\n"
	"\tldr r2, [r5]\n"
	"\tmovs r1, 0x94\n"
	"\tlsls r1, 2\n"
	"\tadds r0, r2, r1\n"
	"\tldr r1, [r0]\n"
	"\tcmp r1, 0\n"
	"\tbne _08036DA4\n"
	"\tldr r1, _08036D9C\n"
	"\tmovs r3, 0x92\n"
	"\tlsls r3, 2\n"
	"\tadds r0, r2, r3\n"
	"\tldr r0, [r0]\n"
	"\tstr r0, [r1]\n"
	"\tldr r0, _08036DA0\n"
	"\tsubs r3, 0x4\n"
	"\tadds r1, r2, r3\n"
	"\tldrb r1, [r1]\n"
	"\tmovs r2, 0\n"
	"\tbl sub_8090DC4\n"
	"\tb _08036DB8\n"
	"\t.align 2, 0\n"
"_08036D9C: .4byte gUnknown_202DE30\n"
"_08036DA0: .4byte gUnknown_202DE58\n"
"_08036DA4:\n"
	"\tldr r0, _08036DC8\n"
	"\tstr r1, [r0]\n"
	"\tldr r0, _08036DCC\n"
	"\tmovs r3, 0x93\n"
	"\tlsls r3, 2\n"
	"\tadds r1, r2, r3\n"
	"\tldrb r1, [r1]\n"
	"\tmovs r2, 0\n"
	"\tbl sub_8090DC4\n"
"_08036DB8:\n"
	"\tldr r0, _08036DD0\n"
"_08036DBA:\n"
	"\tldr r3, _08036DD4\n"
	"\tmovs r1, 0\n"
	"\tmovs r2, 0\n"
	"\tbl sub_80141B4\n"
	"\tb _08036DFA\n"
	"\t.align 2, 0\n"
"_08036DC8: .4byte gUnknown_202DE30\n"
"_08036DCC: .4byte gUnknown_202DE58\n"
"_08036DD0: .4byte gUnknown_80E6314\n"
"_08036DD4: .4byte 0x00000101\n"
"_08036DD8:\n"
	"\tldr r2, _08036E04\n"
	"\tldr r1, [r5]\n"
	"\tldr r0, [r1, 0x14]\n"
	"\tstr r0, [r2]\n"
	"\tldr r0, _08036E08\n"
	"\tldr r2, _08036E0C\n"
	"\tadds r1, r2\n"
	"\tldrb r1, [r1]\n"
	"\tmovs r2, 0\n"
	"\tbl sub_8090DC4\n"
	"\tldr r0, _08036E10\n"
	"\tldr r3, _08036E14\n"
	"\tmovs r1, 0\n"
	"\tmovs r2, 0\n"
	"\tbl sub_80141B4\n"
"_08036DFA:\n"
	"\tadd sp, 0x18\n"
	"\tpop {r4,r5}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_08036E04: .4byte gUnknown_202DE30\n"
"_08036E08: .4byte gUnknown_202DE58\n"
"_08036E0C: .4byte 0x0000025e\n"
"_08036E10: .4byte gUnknown_80E6358\n"
"_08036E14: .4byte 0x00000101");
}
#endif

void PrintTradeItemsLinkError(u32 errorNum)
{
  switch(errorNum) {
    case 0:
        break;
    case 1:
        sub_80141B4(&gTradeItemsCommunicationError, 0, 0, 0x101);
        break;
    case 3:
        sub_80141B4(&gUnknown_80E639C, 0, 0, 0x101);
        break;
    case 2:
        sub_80141B4(&gUnknown_80E63F8, 0, 0, 0x101);
        break;
    case 4:
        sub_80141B4(&gUnknown_80E6448, 0, 0, 0x101);
        break;
    case 5:
        sub_80141B4(&gTradeItemsCommunicationError, 0, 0, 0x101);
        break;
    case 0xe:
        sub_80141B4(&gTradeItemsCommunicationError, 0, 0, 0x101);
        break;
    case 0xf:
        sub_80141B4(&gUnknown_80E64AC, 0, 0, 0x101);
        break;
    default:
    case 0x6:
    case 0x7:
    case 0x8:
    case 0x9:
    case 0xA:
    case 0xB:
    case 0xC:
    case 0xD:
        sub_80141B4(&gTradeItemsCommunicationError, 0, 0, 0x101);
        break;
  }
}

void sub_8036ECC(u32 index, u32 r1)
{
  gUnknown_203B358->unk24 = 3;
  gUnknown_203B358->unk18 = 1;
  gUnknown_203B358->unk1C = 1;
  gUnknown_203B358->unk20 = r1;
  gUnknown_203B358->unk30 = 0x2c;
  gUnknown_203B358->unk34 = 0x12;
  gUnknown_203B358->unk28 = index;
  gUnknown_203B358->unk2C = &gUnknown_203B358->unk184[index];
  sub_8013AA0(&gUnknown_203B358->unk14);
  gUnknown_203B358->unk184[index] = gUnknown_80E6174;
  ResetUnusedInputStruct();
  sub_800641C((u32 *)&gUnknown_203B358->unk184, 1, 1);
}

void sub_8036F30(void)
{
  u32 uVar1;

  uVar1 = gUnknown_203B358->unk28;
  sub_8008C54(uVar1);
  sub_80073B8(uVar1);
  // Draw "How many?"
  xxx_call_draw_string(2, 0, &gTradeItemsHowManyText, uVar1, 0);
  sub_8013C68(&gUnknown_203B358->unk14);
  sub_80073E0(uVar1);
}

void sub_8036F74(void)
{
  sub_8006518((u32 *)&gUnknown_203B358->unk184);
  sub_8036ECC(2, gUnknown_203B460->unk50[gUnknown_203B358->unk25E]);
  sub_801CCD8();
  sub_8035CF4(&gUnknown_203B358->unk44, 3, 0);
  sub_8036F30();
}

void SetTradeItemMenu(u32 newMenu)
{
    gUnknown_203B358->currMenu = newMenu;
    nullsub_52();
    sub_8036B28();
}
