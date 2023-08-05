#include "global.h"
#include "constants/communication_error_codes.h"
#include "input.h"
#include "item.h"
#include "main_menu.h"
#include "team_inventory.h"
#include "trade_items_menu.h"
#include "memory.h"
#include "save.h"
#include "menu.h"
#include "menu_input.h"
#include "text1.h"
#include "text2.h"

EWRAM_DATA_2 struct TradeItemsMenu *gTradeItemsMenu = {0};

extern u32 gUnknown_202DE30;
extern u8 gUnknown_202DE58[];

const struct MenuItem gUnknown_80E60A0[3] = {
    {"Send item", 1},
    {"Receive item", 2},
    {NULL, 0},
};

const struct MenuItem gUnknown_80E60D4[3] = {
    {"Send item", -1},
    {"Receive item", 2},
    {NULL, 0},
};

const struct UnkTextStruct2 gUnknown_80E60EC =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x15, 0x04,
    0x06, 0x05,
    0x05, 0x00,
    NULL
};

const struct MenuItem gUnknown_80E6104[4] = {
    {"Confirm", 3},
    {"Info", 4},
    {"Cancel", 7},
    {NULL, 0},
};

static const struct UnkTextStruct2 unused =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x16, 0x09,
    0x05, 0x03,
    0x03, 0x00,
    NULL
};


const struct MenuItem gUnknown_80E6154[3] = {
    {"Yes", 5},
    {"No", 6},
    {NULL, 0},
};

const struct UnkTextStruct2 gUnknown_80E6174 =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x15, 0x0D,
    0x06, 0x04,
    0x04, 0x00,
    NULL
};


const struct MenuItem gUnknown_80E618C[3] = {
    {"Yes", 5},
    {"Cancel", 0},
    {NULL, 0},
};

#include "data/trade_items.h"

extern void sub_8013AA0(u32 *);

extern void sub_8035C1C();
extern s32 sub_80144A4(s32 *);
extern u32 sub_801CA08(u32);
extern void sub_801CBB8();
extern u8 sub_801CB24();
extern void sub_801B3C0(struct Item *);
extern void sub_8035CC0(struct UnkTextStruct2 *, u32);
extern void sub_801CCD8();
extern u32 sub_801B410();
extern void sub_801B450();
extern void sub_801CB5C(u32);
extern void sub_8035CF4(struct MenuStruct *, u32, u32);
extern u32 sub_8013BBC(u32 *);
extern void sub_80141B4(const u8 *, u32, u32, u32);

extern void sub_8008C54(u32);
extern void sub_80073B8(u32);
extern void sub_8013C68(u32 *);
extern void sub_80073E0(u32);
extern u8 sub_801CF14(u32);
extern u32 sub_801D008();
extern void sub_801C8C4(u32, u32, s32 *, u32);
extern s32 sub_8037B28(u32);
extern void sub_8011830(void);
extern void sub_8014248(const char *r0, u32, u32, const struct MenuItem *r4, u32, u32, u32, void *r5, u32);
extern void SetMenuItems(struct MenuStruct *menu, struct UnkTextStruct2 *, u32, const struct UnkTextStruct2 *, const struct MenuItem *entries, u32, u32, u32);
extern void nullsub_23(u32);
extern void xxx_call_start_bg_music(void);
extern s32 sub_80381F4(u32, void *, void *);
extern s32 sub_8037D64(u32, void *, void *);

void sub_8036F74(void);
void sub_8036F30();
void TradeItem_AddItem();
void SetTradeItemMenu(u32);
void PrintTradeItemsLinkError(u32);
void TradeItem_MainMenu();
void sub_8036590();
void sub_80365AC();
void sub_8036674();
void sub_8036788();
void sub_8036728();
void TradeItem_SendItemConfirm();
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
void WriteandExitTradeItemsMenu();

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
    TRADE_ITEMS_PRE_EXIT = 17,
    TRADE_ITEMS_EXIT = 18,
};

enum TradeItemsModes
{
    TRADE_ITEMS_SEND_ITEM_MODE,
    TRADE_ITEMS_RECEIVE_ITEM_MODE
};


s32 CreateTradeItemsMenu(void)
{

  ResetUnusedInputStruct();
  sub_800641C(0,1,1);
  gTradeItemsMenu = MemoryAlloc(sizeof(struct TradeItemsMenu), 8);
  MemoryFill8((u8 *)gTradeItemsMenu, 0, sizeof(struct TradeItemsMenu));
  sub_8035C1C();
  sub_8035DA0();
  gTradeItemsMenu->fallbackState = 0x13;
  SetTradeItemMenu(TRADE_ITEMS_MAIN_MENU);
  return 1;
}

s32 UpdateTradeItemsMenu(void)
{

  switch(gTradeItemsMenu->currMenu) {
      case TRADE_ITEMS_MAIN_MENU:
        TradeItem_MainMenu();
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
        TradeItem_SendItemConfirm();
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
      case TRADE_ITEMS_PRE_EXIT:
        WriteandExitTradeItemsMenu();
        break;
      case TRADE_ITEMS_EXIT: // when you exit the menu to Main
        return 3;
  }
  return 0;
}

void TradeItem_MainMenu(void)
{
  s32 menuAction;

  if (sub_80144A4(&menuAction) == 0) {
      switch(menuAction)
      {
        case 1:
            // Send Item
            gTradeItemsMenu->itemMode = TRADE_ITEMS_SEND_ITEM_MODE;
            gTradeItemsMenu->unk10 = 1;
            SetTradeItemMenu(TRADE_ITEMS_SEND_ITEM);
            break;
        case 2:
            // Receive Item
            gTradeItemsMenu->itemMode = TRADE_ITEMS_RECEIVE_ITEM_MODE;
            gTradeItemsMenu->unk10 = 2;
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
  gTradeItemsMenu->itemToSend.id = ITEM_NOTHING;
  gTradeItemsMenu->itemToSend.quantity = 1;
  gTradeItemsMenu->itemToSend.flags = 0;
  switch(sub_801CA08(1)){
    case 2:
        // Cancel
        sub_801CBB8();
        SetTradeItemMenu(TRADE_ITEMS_MAIN_MENU);
        break;
    case 3:
        // Pop up menu with Confirm, Info, Cancel
        gTradeItemsMenu->itemToSend.id = sub_801CB24();
        gTradeItemsMenu->itemToSend.quantity = 1;
        SetTradeItemMenu(TRADE_ITEMS_SEND_ITEM_POPUP_MENU);
        break;
    case 4:
        gTradeItemsMenu->fallbackState = TRADE_ITEMS_SEND_ITEM_SELECTION;
        gTradeItemsMenu->itemToSend.id = sub_801CB24();
        gTradeItemsMenu->itemToSend.quantity = 1;
        sub_8006518(gTradeItemsMenu->unk1E4);
        ResetUnusedInputStruct();
        sub_800641C(0,1,1);
        sub_801B3C0(&gTradeItemsMenu->itemToSend);
        SetTradeItemMenu(TRADE_ITEMS_ITEM_INFO);
        break;
  }
}

void sub_8036674(void)
{
  int menuAction;

  menuAction = -1;
  sub_801CA08(0);
  if (sub_8012FD8(&gTradeItemsMenu->unk44[3]) == '\0') {
    sub_8013114(&gTradeItemsMenu->unk44[3], &menuAction);
  }
  switch(menuAction){
    case 3: // confirm
        SetTradeItemMenu(TRADE_ITEMS_SEND_ITEM_NUMBER);
        break;
    case 4: // Info
        gTradeItemsMenu->fallbackState = 0x13;
        sub_8006518(gTradeItemsMenu->unk1E4);
        ResetUnusedInputStruct();
        sub_800641C(0,1,1);
        sub_801B3C0(&gTradeItemsMenu->itemToSend);
        SetTradeItemMenu(TRADE_ITEMS_ITEM_INFO);
        break;
    case 7:
    case 0:
        // Cancel
        sub_8035CC0(gTradeItemsMenu->unk184, 3);
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
        sub_800641C(gTradeItemsMenu->unk1E4, 1, 1);
        sub_801CB5C(1);
        if (gTradeItemsMenu->fallbackState == 0x13) {
            sub_8035CF4(gTradeItemsMenu->unk44, 3, 1);
            SetTradeItemMenu(TRADE_ITEMS_SEND_ITEM_POPUP_MENU);
        }
        else {
            SetTradeItemMenu(gTradeItemsMenu->fallbackState);
        }
    default:
    case 1:
        break;
  }
}

void sub_8036788(void)
{
  sub_8012FD8(&gTradeItemsMenu->unk44[3]);
  sub_801CA08(0);
  switch(sub_8013BBC(&gTradeItemsMenu->quantityToSend)){
    case 1:
        // When you change the #
        sub_801CCD8();
        sub_8035CF4(gTradeItemsMenu->unk44, 3, 0);
        sub_8036F30();
        break;
    case 2:
        // If you back out of the # selection
        sub_8035CC0(gTradeItemsMenu->unk184, 2);
        sub_801CCD8();
        sub_8035CF4(gTradeItemsMenu->unk44, 3, 1);
        SetTradeItemMenu(TRADE_ITEMS_SEND_ITEM_POPUP_MENU);
        break;
    case 3:
        // Confirm # of item
        gTradeItemsMenu->itemToSend.quantity = gTradeItemsMenu->quantityToSend;
        gTradeItemsMenu->sentItem.itemIdx.id = gTradeItemsMenu->itemToSend.id;
        gTradeItemsMenu->sentItem.quantity = gTradeItemsMenu->quantityToSend;
        sub_801CBB8();
        SetTradeItemMenu(TRADE_ITEMS_SEND_ITEM_CONFIRM);
        break;
    case 0:
        break;
  }
}

void TradeItem_SendItemConfirm(void)
{
  int menuAction;
  u16 load;

  if (sub_80144A4(&menuAction) == 0)
  {
      switch(menuAction){
        case 5:
            sub_801CBB8();
            // Used temp var to get correct statements
            load = gTeamInventoryRef->teamStorage[gTradeItemsMenu->itemToSend.id];
            load -= gTradeItemsMenu->quantityToSend;
            gTeamInventoryRef->teamStorage[gTradeItemsMenu->itemToSend.id] = load;
            SetTradeItemMenu(TRADE_ITEMS_PREPARE_TRADE_SAVING);
            PrepareSavePakWrite(MONSTER_NONE);
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
            if ((gTradeItemsMenu->sentItem.itemIdx.id != ITEM_NOTHING) && (gTradeItemsMenu->sentItem.quantity != 0))
            {
                TradeItem_AddItem();
                SetTradeItemMenu(TRADE_ITEMS_PRE_EXIT);
                PrepareSavePakWrite(MONSTER_NONE);
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
    if (gTradeItemsMenu->linkStatus == COMMS_GOOD) {
      switch(gTradeItemsMenu->itemMode){
        case TRADE_ITEMS_SEND_ITEM_MODE:
          SetTradeItemMenu(0xd);
          break;
        case TRADE_ITEMS_RECEIVE_ITEM_MODE:
          SetTradeItemMenu(0xe);
          break;
        default:
          break;
      }
    }
    else if (((gTradeItemsMenu->itemMode == TRADE_ITEMS_SEND_ITEM_MODE) && (gTradeItemsMenu->sentItem.itemIdx.id != ITEM_NOTHING)) && (gTradeItemsMenu->sentItem.quantity != 0)) {
          // Link Failure
        TradeItem_AddItem(); // Add back the item
        SetTradeItemMenu(0xb);
        PrepareSavePakWrite(MONSTER_NONE);
      }
    else {
        PrintTradeItemsLinkError(gTradeItemsMenu->linkStatus);
        SetTradeItemMenu(0xc);
    }
  }
}

void TradeItem_AddItem(void)
{
    // Use temp var to get correct statements
    u16 load;
    load = gTeamInventoryRef->teamStorage[gTradeItemsMenu->sentItem.itemIdx.id];
    load += gTradeItemsMenu->sentItem.quantity;
    gTeamInventoryRef->teamStorage[gTradeItemsMenu->sentItem.itemIdx.id] = load;
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
        PrepareSavePakWrite(MONSTER_NONE);
    }
}

void sub_8036A54(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        if(!WriteSavePak())
        {
            FinishWriteSavePak();
            SetTradeItemMenu(TRADE_ITEMS_EXIT);
        }
    }
}

void sub_8036A7C(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        if(!WriteSavePak())
        {
            FinishWriteSavePak(); // cleans up from Save Message
            SetTradeItemMenu(0x8);
        }
    }
}

void sub_8036AA4(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        if(!WriteSavePak())
        {
            FinishWriteSavePak();
            PrintTradeItemsLinkError(gTradeItemsMenu->linkStatus);
            SetTradeItemMenu(0xC);
        }
    }
}

void WriteandExitTradeItemsMenu(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        if(!WriteSavePak())
        {
            FinishWriteSavePak();
            SetTradeItemMenu(TRADE_ITEMS_EXIT);
        }
    }
}

void CleanTradeItemsMenu(void)
{
    if(gTradeItemsMenu != NULL)
    {
        MemoryFree(gTradeItemsMenu);
        gTradeItemsMenu = NULL;
        sub_801CBB8();
    }
}

void nullsub_52(void)
{
}


void sub_8036B28(void)
{
  int linkStatus;
  s32 local_10;
  u32 load_2;
  struct TradeSubStruct *temp;
  struct TradeSubStruct *temp2;
  struct TradeSubStruct *temp3;
  struct TradeSubStruct *temp4;
  s32 r2;
  s32 r3;

  switch(gTradeItemsMenu->currMenu) {
    case TRADE_ITEMS_MAIN_MENU:
        if (sub_801CF14(0) != 0) {
            sub_8014248(gUnknown_80E61A4,0,1,gUnknown_80E60D4,0,4,0,0,0x101);
        }
        else {
            sub_8014248(gUnknown_80E61A4,0,1,gUnknown_80E60A0,0,4,0,0,0x101);
        }
        break;
    case TRADE_ITEMS_SEND_ITEM:
        sub_80141B4(gUnknown_80E61C0,0,0,0x101);
        break;
    case TRADE_ITEMS_SEND_ITEM_SELECTION:
        if (sub_801D008() == 0) {
            ResetUnusedInputStruct();
            sub_800641C(0,1,1);
            local_10 = 0x20003;
            sub_801C8C4(0,1,&local_10,9);
        }
        break;
    case TRADE_ITEMS_SEND_ITEM_POPUP_MENU:
        sub_8006518(gTradeItemsMenu->unk184);
        SetMenuItems(gTradeItemsMenu->unk44,gTradeItemsMenu->unk184,3,&gUnknown_80E60EC,
                    gUnknown_80E6104,1,0,0);
        sub_801CCD8();
        sub_8035CF4(gTradeItemsMenu->unk44,3,1);
        break;
    case TRADE_ITEMS_SEND_ITEM_NUMBER:
        sub_8036F74();
        break;
    case TRADE_ITEMS_SEND_ITEM_CONFIRM:
        gUnknown_202DE30 = gTradeItemsMenu->quantityToSend;
        sub_8090DC4(gUnknown_202DE58,gTradeItemsMenu->itemToSend.id,0);
        sub_8014248(gUnknown_80E61E4,0,5, gUnknown_80E6154,0,4,0,0,0x101);
        break;
    case TRADE_ITEMS_RECEIVE_ITEM:
        sub_8014248(gUnknown_80E6214,0,5,gUnknown_80E618C,0,4,0,0,0x101);
        break;
    case 8:
        sub_8014248(gUnknown_80E6268,0,5,gUnknown_80E618C,0,4,0,0,0x101);
        break;
    case TRADE_ITEMS_IN_COMMUNICATION:
        nullsub_23(0);
        sub_80141B4(gUnknown_80E62C4,0,0,0);
        break;
    case 10:
        gTradeItemsMenu->linkStatus = COMMS_GOOD;

#ifndef NONMATCHING
        asm("mov\t%0, #0":"=r"(r2));
        asm("mov\t%0, #0":"=r"(r3));
#else
        r2 = 0;
        r3 = 0;
#endif

        temp4 = &gTradeItemsMenu->unk244;
        temp4->itemIdx.id_u32 = r2;
        temp4->quantity = r3;

        temp3 = &gTradeItemsMenu->unk24C;
        temp3->itemIdx.id_u32 = r2;
        temp3->quantity = r3;

        sub_8011830();
        linkStatus = sub_8037B28(gTradeItemsMenu->itemMode);
        gTradeItemsMenu->linkStatus = linkStatus;
        if(linkStatus == COMMS_GOOD){
            switch(gTradeItemsMenu->itemMode){
                // Fallthrough needed on each case
                case TRADE_ITEMS_SEND_ITEM_MODE:
                    temp = &gTradeItemsMenu->unk244;
                    temp2 = &gTradeItemsMenu->sentItem;
                    load_2 = temp2->quantity;
                    temp->itemIdx.id_u32 = temp2->itemIdx.id_u32;
                    temp->quantity = load_2;
                case TRADE_ITEMS_RECEIVE_ITEM_MODE:
                    gTradeItemsMenu->linkStatus = sub_8037D64(gTradeItemsMenu->itemMode,&gTradeItemsMenu->unk244,&gTradeItemsMenu->unk24C);
                default:
                    break;
            }
        }
        // Needed this check for code generation
        if(gTradeItemsMenu->linkStatus == COMMS_GOOD && gTradeItemsMenu->itemMode <= 1){
            gTradeItemsMenu->linkStatus = sub_80381F4(gTradeItemsMenu->itemMode,&gTradeItemsMenu->unk244,&gTradeItemsMenu->unk24C);
        }
        xxx_call_start_bg_music();
        break;
    case 0xe:
        if (gTradeItemsMenu->unk24C.quantity == 0) {
            gUnknown_202DE30 = gTradeItemsMenu->unk244.quantity;
            sub_8090DC4(gUnknown_202DE58,gTradeItemsMenu->unk244.itemIdx.id,0);
        }
        else {
            gUnknown_202DE30 = gTradeItemsMenu->unk24C.quantity;
            sub_8090DC4(gUnknown_202DE58,gTradeItemsMenu->unk24C.itemIdx.id,0);
        }
        sub_80141B4(gUnknown_80E6314,0,0,0x101);
        break;
    case 0xd:
        gUnknown_202DE30 = gTradeItemsMenu->quantityToSend;
        sub_8090DC4(gUnknown_202DE58,gTradeItemsMenu->itemToSend.id,0);
        sub_80141B4(gUnknown_80E6358,0,0,0x101);
        break;
    case 0xB:
    case 0xC:
    case 0xF:
    case 0x10:
    case TRADE_ITEMS_PRE_EXIT:
    case TRADE_ITEMS_EXIT:
    default:
        break;
  }
}

void PrintTradeItemsLinkError(u32 errorNum)
{
  switch(errorNum) {
    case COMMS_GOOD:
        break;
    case 1:
        sub_80141B4(gTradeItemsCommunicationError, 0, 0, 0x101);
        break;
    case COMMS_INCORRECT_NUM_SYSTEMS:
        sub_80141B4(gUnknown_80E639C, 0, 0, 0x101);
        break;
    case COMMS_NO_RESPONSE:
        sub_80141B4(gUnknown_80E63F8, 0, 0, 0x101);
        break;
    case COMMS_DIFFERENT_MODES:
        sub_80141B4(gUnknown_80E6448, 0, 0, 0x101);
        break;
    case 5:
        sub_80141B4(gTradeItemsCommunicationError, 0, 0, 0x101);
        break;
    case 0xe:
        sub_80141B4(gTradeItemsCommunicationError, 0, 0, 0x101);
        break;
    case COMMS_NOT_READY:
        sub_80141B4(gUnknown_80E64AC, 0, 0, 0x101);
        break;
    default:
        sub_80141B4(gTradeItemsCommunicationError, 0, 0, 0x101);
        break;
  }
}

void sub_8036ECC(u32 index, u32 r1)
{
  gTradeItemsMenu->unk24 = 3;
  gTradeItemsMenu->unk18 = 1;
  gTradeItemsMenu->unk1C = 1;
  gTradeItemsMenu->unk20 = r1;
  gTradeItemsMenu->unk30 = 0x2c;
  gTradeItemsMenu->unk34 = 0x12;
  gTradeItemsMenu->unk28 = index;
  gTradeItemsMenu->unk2C = &gTradeItemsMenu->unk184[index];
  sub_8013AA0(&gTradeItemsMenu->quantityToSend);
  gTradeItemsMenu->unk184[index] = gUnknown_80E6174;
  ResetUnusedInputStruct();
  sub_800641C(gTradeItemsMenu->unk184, 1, 1);
}

void sub_8036F30(void)
{
  u32 uVar1;

  uVar1 = gTradeItemsMenu->unk28;
  sub_8008C54(uVar1);
  sub_80073B8(uVar1);
  // Draw "How many?"
  xxx_call_draw_string(2, 0, gTradeItemsHowManyText, uVar1, 0);
  sub_8013C68(&gTradeItemsMenu->quantityToSend);
  sub_80073E0(uVar1);
}

void sub_8036F74(void)
{
  sub_8006518(gTradeItemsMenu->unk184);
  sub_8036ECC(2, gTeamInventoryRef->teamStorage[gTradeItemsMenu->itemToSend.id]);
  sub_801CCD8();
  sub_8035CF4(gTradeItemsMenu->unk44, 3, 0);
  sub_8036F30();
}

void SetTradeItemMenu(u32 newMenu)
{
    gTradeItemsMenu->currMenu = newMenu;
    nullsub_52();
    sub_8036B28();
}
