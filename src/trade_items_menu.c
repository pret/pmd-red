#include "global.h"
#include "globaldata.h"
#include "code_80118A4.h"
#include "string_format.h"
#include "code_801B3C0.h"
#include "code_801C8C4.h"
#include "constants/communication_error_codes.h"
#include "cpu.h"
#include "input.h"
#include "items.h"
#include "main_menu1.h"
#include "memory.h"
#include "menu_input.h"
#include "other_menus2.h"
#include "save_write.h"
#include "text1.h"
#include "text2.h"
#include "trade_items_menu.h"

static EWRAM_DATA_2 struct TradeItemsMenu *sTradeItemsMenu = {0};

#include "data/trade_items_menu.h"

extern s32 sub_8037B28(u32);

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

s32 CreateTradeItemsMenu(void)
{
  ResetUnusedInputStruct();
  xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
  sTradeItemsMenu = MemoryAlloc(sizeof(struct TradeItemsMenu), 8);
  MemoryFill8(sTradeItemsMenu, 0, sizeof(struct TradeItemsMenu));
  sub_8035C1C();
  sub_8035DA0();
  sTradeItemsMenu->fallbackState = 0x13;
  SetTradeItemMenu(TRADE_ITEMS_MAIN_MENU);
  return 1;
}

s32 UpdateTradeItemsMenu(void)
{
  switch(sTradeItemsMenu->currMenu) {
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
            sTradeItemsMenu->itemMode = TRADE_ITEMS_SEND_ITEM_MODE;
            sTradeItemsMenu->unk10 = 1;
            SetTradeItemMenu(TRADE_ITEMS_SEND_ITEM);
            break;
        case 2:
            // Receive Item
            sTradeItemsMenu->itemMode = TRADE_ITEMS_RECEIVE_ITEM_MODE;
            sTradeItemsMenu->unk10 = 2;
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
  sTradeItemsMenu->itemToSend.id = ITEM_NOTHING;
  sTradeItemsMenu->itemToSend.quantity = 1;
  sTradeItemsMenu->itemToSend.flags = 0;
  switch(sub_801CA08(TRUE)){
    case 2:
        // Cancel
        sub_801CBB8();
        SetTradeItemMenu(TRADE_ITEMS_MAIN_MENU);
        break;
    case 3:
        // Pop up menu with Confirm, Info, Cancel
        sTradeItemsMenu->itemToSend.id = sub_801CB24();
        sTradeItemsMenu->itemToSend.quantity = 1;
        SetTradeItemMenu(TRADE_ITEMS_SEND_ITEM_POPUP_MENU);
        break;
    case 4:
        sTradeItemsMenu->fallbackState = TRADE_ITEMS_SEND_ITEM_SELECTION;
        sTradeItemsMenu->itemToSend.id = sub_801CB24();
        sTradeItemsMenu->itemToSend.quantity = 1;
        RestoreUnkTextStruct_8006518(sTradeItemsMenu->unk1E4);
        ResetUnusedInputStruct();
        xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
        sub_801B3C0(&sTradeItemsMenu->itemToSend);
        SetTradeItemMenu(TRADE_ITEMS_ITEM_INFO);
        break;
  }
}

void sub_8036674(void)
{
  int menuAction;

  menuAction = -1;
  sub_801CA08(FALSE);
  if (sub_8012FD8(&sTradeItemsMenu->unk44[3]) == '\0') {
    sub_8013114(&sTradeItemsMenu->unk44[3], &menuAction);
  }
  switch(menuAction){
    case 3: // confirm
        SetTradeItemMenu(TRADE_ITEMS_SEND_ITEM_NUMBER);
        break;
    case 4: // Info
        sTradeItemsMenu->fallbackState = 0x13;
        RestoreUnkTextStruct_8006518(sTradeItemsMenu->unk1E4);
        ResetUnusedInputStruct();
        xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
        sub_801B3C0(&sTradeItemsMenu->itemToSend);
        SetTradeItemMenu(TRADE_ITEMS_ITEM_INFO);
        break;
    case 7:
    case 0:
        // Cancel
        sub_8035CC0(sTradeItemsMenu->unk184, 3);
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
        xxx_call_save_unk_text_struct_800641C(sTradeItemsMenu->unk1E4, TRUE, TRUE);
        sub_801CB5C(TRUE);
        if (sTradeItemsMenu->fallbackState == 0x13) {
            sub_8035CF4(sTradeItemsMenu->unk44, 3, TRUE);
            SetTradeItemMenu(TRADE_ITEMS_SEND_ITEM_POPUP_MENU);
        }
        else {
            SetTradeItemMenu(sTradeItemsMenu->fallbackState);
        }
    default:
    case 1:
        break;
  }
}

void sub_8036788(void)
{
  sub_8012FD8(&sTradeItemsMenu->unk44[3]);
  sub_801CA08(FALSE);
  switch (sub_8013BBC(&sTradeItemsMenu->unk14)) {
    case 1:
        // When you change the #
        sub_801CCD8();
        sub_8035CF4(sTradeItemsMenu->unk44, 3, FALSE);
        sub_8036F30();
        break;
    case 2:
        // If you back out of the # selection
        sub_8035CC0(sTradeItemsMenu->unk184, 2);
        sub_801CCD8();
        sub_8035CF4(sTradeItemsMenu->unk44, 3, TRUE);
        SetTradeItemMenu(TRADE_ITEMS_SEND_ITEM_POPUP_MENU);
        break;
    case 3:
        // Confirm # of item
        sTradeItemsMenu->itemToSend.quantity = sTradeItemsMenu->unk14.unk0;
        sTradeItemsMenu->sentItem.itemIdx.id = sTradeItemsMenu->itemToSend.id;
        sTradeItemsMenu->sentItem.quantity = sTradeItemsMenu->unk14.unk0;
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
            load = gTeamInventoryRef->teamStorage[sTradeItemsMenu->itemToSend.id];
            load -= sTradeItemsMenu->unk14.unk0;
            gTeamInventoryRef->teamStorage[sTradeItemsMenu->itemToSend.id] = load;
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
            if ((sTradeItemsMenu->sentItem.itemIdx.id != ITEM_NOTHING) && (sTradeItemsMenu->sentItem.quantity != 0))
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
    if (sTradeItemsMenu->linkStatus == COMMS_GOOD) {
      switch(sTradeItemsMenu->itemMode){
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
    else if (((sTradeItemsMenu->itemMode == TRADE_ITEMS_SEND_ITEM_MODE) && (sTradeItemsMenu->sentItem.itemIdx.id != ITEM_NOTHING)) && (sTradeItemsMenu->sentItem.quantity != 0)) {
          // Link Failure
        TradeItem_AddItem(); // Add back the item
        SetTradeItemMenu(0xb);
        PrepareSavePakWrite(MONSTER_NONE);
      }
    else {
        PrintTradeItemsLinkError(sTradeItemsMenu->linkStatus);
        SetTradeItemMenu(0xc);
    }
  }
}

void TradeItem_AddItem(void)
{
    // Use temp var to get correct statements
    u16 load;
    load = gTeamInventoryRef->teamStorage[sTradeItemsMenu->sentItem.itemIdx.id];
    load += sTradeItemsMenu->sentItem.quantity;
    gTeamInventoryRef->teamStorage[sTradeItemsMenu->sentItem.itemIdx.id] = load;
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
            PrintTradeItemsLinkError(sTradeItemsMenu->linkStatus);
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
    if(sTradeItemsMenu != NULL)
    {
        MemoryFree(sTradeItemsMenu);
        sTradeItemsMenu = NULL;
        sub_801CBB8();
    }
}

void nullsub_52(void)
{
}


void sub_8036B28(void)
{
  int linkStatus;
  u32 load_2;
  struct TradeSubStruct *temp;
  struct TradeSubStruct *temp2;
  struct TradeSubStruct *temp3;
  struct TradeSubStruct *temp4;
  s32 r2;
  s32 r3;

  switch(sTradeItemsMenu->currMenu) {
    case TRADE_ITEMS_MAIN_MENU:
        if (sub_801CF14(0)) {
            CreateMenuDialogueBoxAndPortrait(sWhatDoPrompt,0,1,sUnknown_80E60D4,0,4,0,0,0x101);
        }
        else {
            CreateMenuDialogueBoxAndPortrait(sWhatDoPrompt,0,1,sUnknown_80E60A0,0,4,0,0,0x101);
        }
        break;
    case TRADE_ITEMS_SEND_ITEM:
        CreateDialogueBoxAndPortrait(sPleaseChooseItem,0,0,0x101);
        break;
    case TRADE_ITEMS_SEND_ITEM_SELECTION:
        if (sub_801D008() == NULL) {
            ResetUnusedInputStruct();
            xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
            {
            UnkTextStruct2_sub local_10 = {3, 2};
            sub_801C8C4(0,1,&local_10,9);
            }
        }
        break;
    case TRADE_ITEMS_SEND_ITEM_POPUP_MENU:
        RestoreUnkTextStruct_8006518(sTradeItemsMenu->unk184);
        SetMenuItems(sTradeItemsMenu->unk44,sTradeItemsMenu->unk184,3,&sUnknown_80E60EC,
                    sUnknown_80E6104,TRUE,0,FALSE);
        sub_801CCD8();
        sub_8035CF4(sTradeItemsMenu->unk44,3,TRUE);
        break;
    case TRADE_ITEMS_SEND_ITEM_NUMBER:
        sub_8036F74();
        break;
    case TRADE_ITEMS_SEND_ITEM_CONFIRM:
        gFormatArgs[0] = sTradeItemsMenu->unk14.unk0;
        BufferItemName(gFormatBuffer_Items[0],sTradeItemsMenu->itemToSend.id,NULL);
        CreateMenuDialogueBoxAndPortrait(sFmtWillBeSentPrompt,0,5, sUnknown_80E6154,0,4,0,0,0x101);
        break;
    case TRADE_ITEMS_RECEIVE_ITEM:
        CreateMenuDialogueBoxAndPortrait(sFriendWillSendAnItem,0,5,sUnknown_80E618C,0,4,0,0,0x101);
        break;
    case 8:
        CreateMenuDialogueBoxAndPortrait(sPreparingToSendItem,0,5,sUnknown_80E618C,0,4,0,0,0x101);
        break;
    case TRADE_ITEMS_IN_COMMUNICATION:
        nullsub_23(FALSE);
        CreateDialogueBoxAndPortrait(sInCommunication,0,0,0);
        break;
    case 10:
        sTradeItemsMenu->linkStatus = COMMS_GOOD;

#ifndef NONMATCHING
        asm("mov\t%0, #0":"=r"(r2));
        asm("mov\t%0, #0":"=r"(r3));
#else
        r2 = 0;
        r3 = 0;
#endif

        temp4 = &sTradeItemsMenu->unk244;
        temp4->itemIdx.id_u32 = r2;
        temp4->quantity = r3;

        temp3 = &sTradeItemsMenu->unk24C;
        temp3->itemIdx.id_u32 = r2;
        temp3->quantity = r3;

        sub_8011830();
        linkStatus = sub_8037B28(sTradeItemsMenu->itemMode);
        sTradeItemsMenu->linkStatus = linkStatus;
        if(linkStatus == COMMS_GOOD){
            switch(sTradeItemsMenu->itemMode){
                // Fallthrough needed on each case
                case TRADE_ITEMS_SEND_ITEM_MODE:
                    temp = &sTradeItemsMenu->unk244;
                    temp2 = &sTradeItemsMenu->sentItem;
                    load_2 = temp2->quantity;
                    temp->itemIdx.id_u32 = temp2->itemIdx.id_u32;
                    temp->quantity = load_2;
                case TRADE_ITEMS_RECEIVE_ITEM_MODE:
                    sTradeItemsMenu->linkStatus = sub_8037D64(sTradeItemsMenu->itemMode,&sTradeItemsMenu->unk244,&sTradeItemsMenu->unk24C);
                default:
                    break;
            }
        }
        // Needed this check for code generation
        if(sTradeItemsMenu->linkStatus == COMMS_GOOD && sTradeItemsMenu->itemMode <= 1){
            sTradeItemsMenu->linkStatus = sub_80381F4(sTradeItemsMenu->itemMode,&sTradeItemsMenu->unk244,&sTradeItemsMenu->unk24C);
        }
        xxx_call_start_bg_music();
        break;
    case 0xe:
        if (sTradeItemsMenu->unk24C.quantity == 0) {
            gFormatArgs[0] = sTradeItemsMenu->unk244.quantity;
            BufferItemName(gFormatBuffer_Items[0],sTradeItemsMenu->unk244.itemIdx.id,NULL);
        }
        else {
            gFormatArgs[0] = sTradeItemsMenu->unk24C.quantity;
            BufferItemName(gFormatBuffer_Items[0],sTradeItemsMenu->unk24C.itemIdx.id,NULL);
        }
        CreateDialogueBoxAndPortrait(sFmtYouReceived,0,0,0x101);
        break;
    case 0xd:
        gFormatArgs[0] = sTradeItemsMenu->unk14.unk0;
        BufferItemName(gFormatBuffer_Items[0],sTradeItemsMenu->itemToSend.id,NULL);
        CreateDialogueBoxAndPortrait(sFmtYouSent,0,0,0x101);
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
        CreateDialogueBoxAndPortrait(sCommunicationError, 0, 0, 0x101);
        break;
    case COMMS_INCORRECT_NUM_SYSTEMS:
        CreateDialogueBoxAndPortrait(sInvalidGBACount, 0, 0, 0x101);
        break;
    case COMMS_NO_RESPONSE:
        CreateDialogueBoxAndPortrait(sNoResponseSoRedo, 0, 0, 0x101);
        break;
    case COMMS_DIFFERENT_MODES:
        CreateDialogueBoxAndPortrait(sUnequalModes, 0, 0, 0x101);
        break;
    case 5:
        CreateDialogueBoxAndPortrait(sCommunicationError, 0, 0, 0x101);
        break;
    case 0xe:
        CreateDialogueBoxAndPortrait(sCommunicationError, 0, 0, 0x101);
        break;
    case COMMS_NOT_READY:
        CreateDialogueBoxAndPortrait(sNoResponseCheckSenderReceiver, 0, 0, 0x101);
        break;
    default:
        CreateDialogueBoxAndPortrait(sCommunicationError, 0, 0, 0x101);
        break;
  }
}

void sub_8036ECC(u32 index, u32 r1)
{
    sTradeItemsMenu->unk14.unk10 = 3;
    sTradeItemsMenu->unk14.unk4 = 1;
    sTradeItemsMenu->unk14.unk8 = 1;
    sTradeItemsMenu->unk14.unkC = r1;
    sTradeItemsMenu->unk14.unk1C = 0x2c;
    sTradeItemsMenu->unk14.unk20 = 0x12;
    sTradeItemsMenu->unk14.unk14 = index;
    sTradeItemsMenu->unk14.unk18 = &sTradeItemsMenu->unk184[index];
    sub_8013AA0(&sTradeItemsMenu->unk14);
    sTradeItemsMenu->unk184[index] = sUnknown_80E6174;
    ResetUnusedInputStruct();
    xxx_call_save_unk_text_struct_800641C(sTradeItemsMenu->unk184, TRUE, TRUE);
}

void sub_8036F30(void)
{
  u32 uVar1;

  uVar1 = sTradeItemsMenu->unk14.unk14;
  CallPrepareTextbox_8008C54(uVar1);
  sub_80073B8(uVar1);
  PrintStringOnWindow(2, 0, sHowMany, uVar1, 0);
  sub_8013C68(&sTradeItemsMenu->unk14);
  sub_80073E0(uVar1);
}

void sub_8036F74(void)
{
  RestoreUnkTextStruct_8006518(sTradeItemsMenu->unk184);
  sub_8036ECC(2, gTeamInventoryRef->teamStorage[sTradeItemsMenu->itemToSend.id]);
  sub_801CCD8();
  sub_8035CF4(sTradeItemsMenu->unk44, 3, FALSE);
  sub_8036F30();
}

void SetTradeItemMenu(u32 newMenu)
{
    sTradeItemsMenu->currMenu = newMenu;
    nullsub_52();
    sub_8036B28();
}
