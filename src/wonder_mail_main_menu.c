#include "global.h"
#include "globaldata.h"
#include "code_80118A4.h"
#include "code_80130A8.h"
#include "code_801B3C0.h"
#include "code_803B050.h"
#include "code_801C8C4.h"
#include "code_803D0D8.h"
#include "code_8094F88.h"
#include "constants/communication_error_codes.h"
#include "constants/wonder_mail.h"
#include "cpu.h"
#include "input.h"
#include "memory.h"
#include "other_menus2.h"
#include "save.h"
#include "save_write.h"
#include "text1.h"
#include "text2.h"
#include "wonder_mail_802D098.h"
#include "wonder_mail_main_menu.h"
#include "wonder_mail_4.h"
#include "wonder_mail_5.h"

#define SELECT_WONDER_MAIL_MODE_MAIN_SCREEN 0
#define SEND_WONDER_MAIL_MAIN_SCREEN 1
#define SEND_GAME_LINK_CABLE 2
#define RECEIVE_WONDER_MAIL_MAIN_SCREEN 4
#define EXIT_TO_MAIN_MENU 5
#define WONDER_MAIL_SENT 7
#define GAME_LINK_CABLE_MENU 8
#define COMMUNICATION_ERROR 10
#define RECEIVE_GAME_LINK_CABLE 12
#define PASSWORD_SUCCESS 13
#define PREPARE_SAVE 14
#define SAVE_ADVENTURE 15
#define WONDER_MAIL_ADDED 16
#define PROMPT_PASSWORD_ENTRY 17
#define PASSWORD_INVALID 19
#define PASSWORD_ENTRY_SCREEN 18

// size: 0x49C
struct unkStruct_203B3E8
{
    /* 0x0 */ u8 state;
    /* 0x1 */ u8 PasswordEntryBuffer[PASSWORD_BUFFER_SIZE]; // Wonder Mail Buffer...
    union UNK38
    {
        WonderMail decodedMail; // 0x14
        u8 unk38_u8[0x30]; // idk why it fills to 0x30 instead...
    } UNK38;
    u8 fill68[0x1EC - 0x68];
    UnkTextStruct2 unk1EC[4];
    u32 unk24C;
    /* 0x250 */ u32 wonderMailStatus;
    unkStruct_803B344 unk254;
    unkStruct_803B344 unk308;
    u8 unk3BC;
    u8 fill3BD[0x3C0 - 0x3BD];
    unkStruct_803B344 unk3C0;
    WonderMail unk474;
    u8 **unk488;
    u8 *unk48C;
    /* 0x490 */ s32 wonderMailMethod;
    /* 0x494 */ u32 wonderMailMode;
    /* 0x498 */ bool8 wonderMailAccepted;
};

EWRAM_DATA_2 struct unkStruct_203B3E8 *gUnknown_203B3E8 = {0};

#include "data/wonder_mail_main_menu.h"

extern void SetWonderMailMainMenuState(u8);
extern void sub_8031E10(void);
extern u8 sub_800D588(void);
extern void sub_802EF48(void);
extern s32 sub_8037B28(u32);

void PrintWonderMailMainMenuError(u32);
void HandleWonderMailMainScreen(void);
void HandleGameLinkCableMenu(void);
void sub_8039B14(void);
void sub_8039B20(void);
void sub_8039B58(void);
void ReturnToGameLinkCableMenu(void);
void HandlePasswordSuccess(void);
void HandlePrepareSaveScreen(void);
void HandleSaveAdventureScreen(void);
void HandleWonderMailAddedScreen(void);
void ReturnToReceiveWonderMailMainScreen(void);
void AdvanceToPasswordEntryScreen(void);
void HandlePasswordEntryScreen(void);
void HandleInvalidPasswordMenu(void);

bool8 CreateWonderMailMenu(void)
{
  s32 index;

  ResetUnusedInputStruct();
  xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);

  gUnknown_203B3E8 = MemoryAlloc(sizeof(struct unkStruct_203B3E8), 8);
  MemoryFill8((u8 *)gUnknown_203B3E8, 0, sizeof(struct unkStruct_203B3E8));

  for(index = 0; index < PASSWORD_BUFFER_SIZE; index++){
    gUnknown_203B3E8->PasswordEntryBuffer[index] = 0;
  }

  gUnknown_203B3E8->wonderMailMethod = WONDER_MAIL_GAME_LINK;
  gUnknown_203B3E8->wonderMailMode = WONDER_MAIL_MODE_RECEIVE;
  gUnknown_203B3E8->wonderMailAccepted = TRUE;
  gUnknown_203B3E8->wonderMailMethod = WONDER_MAIL_PASSWORD; // ??? Why?
  SetWonderMailMainMenuState(PROMPT_PASSWORD_ENTRY); // -> Display "Enter Wonder Mail Password"
  return 1;
}

u32 UpdateWonderMailMenu(void)
{
  switch(gUnknown_203B3E8->state) {
    case RECEIVE_WONDER_MAIL_MAIN_SCREEN:
        HandleWonderMailMainScreen();
        break;
    case EXIT_TO_MAIN_MENU: // When you exit out of the menu
        return 3;
    case GAME_LINK_CABLE_MENU:
        HandleGameLinkCableMenu();
        break;
    case RECEIVE_GAME_LINK_CABLE:
        sub_8039B14();
        break;
    case 6:
        sub_8039B20();
        break;
    case 9:
        sub_8039B58();
        break;
    case WONDER_MAIL_SENT:
        ReturnToGameLinkCableMenu();
        break;
    case PASSWORD_SUCCESS:
        HandlePasswordSuccess();
        break;
    case PREPARE_SAVE:
        HandlePrepareSaveScreen();
        break;
    case SAVE_ADVENTURE: // Saving adventure
        HandleSaveAdventureScreen();
        break;
    case WONDER_MAIL_ADDED: // Display "Recieved Wonder Mail was added" and go back to main menu
        HandleWonderMailAddedScreen();
        break;
    case COMMUNICATION_ERROR:
        ReturnToReceiveWonderMailMainScreen();
        break;
    case PROMPT_PASSWORD_ENTRY: // "Please enter the Wonder Mail Password" Screen
        AdvanceToPasswordEntryScreen();
        break;
    case PASSWORD_ENTRY_SCREEN: // Password Entry
        HandlePasswordEntryScreen();
        break;
    case PASSWORD_INVALID:
        HandleInvalidPasswordMenu();
  }
  return 0;
}

void CleanWonderMailMenu(void)
{
  if (gUnknown_203B3E8 != NULL) {
    MemoryFree(gUnknown_203B3E8);
    gUnknown_203B3E8 = NULL;
    sub_8030DE4(); // Frees 203B324
    sub_801B450(); // Frees 203B230
    sub_803084C(); // Frees 203B320
    sub_801CBB8(); // Frees 203B244
    sub_80155F0(); // Frees 203B1FC
    sub_8031E10(); // Frees 203B334
  }
}

void HandleWonderMailMainScreen(void)
{
  s32 menuAction;

  if (sub_80144A4(&menuAction) == 0) {
    gUnknown_203B3E8->unk24C = 10;
    switch(menuAction) {
        case WONDER_MAIL_GAME_LINK:
        case 4:
            gUnknown_203B3E8->wonderMailMethod = WONDER_MAIL_GAME_LINK;
            SetWonderMailMainMenuState(GAME_LINK_CABLE_MENU);
            break;
        case WONDER_MAIL_PASSWORD:
            gUnknown_203B3E8->wonderMailMethod = WONDER_MAIL_PASSWORD;
            SetWonderMailMainMenuState(PROMPT_PASSWORD_ENTRY);
            break;
        case 0:
        case 8:
            SetWonderMailMainMenuState(EXIT_TO_MAIN_MENU);
            break;
    }
  }
}

void HandleGameLinkCableMenu(void)
{
  s32 menuAction;

  if (sub_80144A4(&menuAction) == 0) {
    switch(menuAction){
        case 6:
            if (gUnknown_203B3E8->wonderMailMode == WONDER_MAIL_MODE_SEND) {
                SetWonderMailMainMenuState(SEND_GAME_LINK_CABLE);
            }
            else {
                SetWonderMailMainMenuState(RECEIVE_GAME_LINK_CABLE);
            }
            break;
        case 0:
            if (gUnknown_203B3E8->wonderMailMode == WONDER_MAIL_MODE_SEND) {
                SetWonderMailMainMenuState(SEND_WONDER_MAIL_MAIN_SCREEN);
            }
            else {
                SetWonderMailMainMenuState(RECEIVE_WONDER_MAIL_MAIN_SCREEN);
            }
            break;
    }
  }
}

void sub_8039B14(void)
{
    SetWonderMailMainMenuState(6);
}

void sub_8039B20(void)
{
  s32 local_8;

  if (sub_80144A4(&local_8) == 0) {
      SetWonderMailMainMenuState(9);
  }
}

void ReturnToReceiveWonderMailMainScreen(void)
{
  s32 local_8;

  if (sub_80144A4(&local_8) == 0) {
      SetWonderMailMainMenuState(RECEIVE_WONDER_MAIL_MAIN_SCREEN);
  }
}

void sub_8039B58(void)
{
  s32 temp;

  if (sub_80144A4(&temp) == 0) {
    if (gUnknown_203B3E8->wonderMailStatus == COMMS_GOOD) {
      switch(gUnknown_203B3E8->unk24C){
        case 9:
            SetWonderMailMainMenuState(WONDER_MAIL_SENT);
            break;
        case 10:
            SetWonderMailMainMenuState(PASSWORD_SUCCESS);
            break;
      }
    }
    else {
      PrintWonderMailMainMenuError(gUnknown_203B3E8->wonderMailStatus);
      SetWonderMailMainMenuState(COMMUNICATION_ERROR);
    }
  }
}

/* NOTE: I think the error codes for wonder mail are the same across SOS/WONDER */
void PrintWonderMailMainMenuError(u32 status)
{
    switch(status)
    {
        case COMMS_GOOD:
            break;
        case 1:
            // "Communication Error"
            xxx_info_box_80141B4(gUnknown_80E7914, 0, 0, 0x101);
            break;
        case COMMS_INCORRECT_NUM_SYSTEMS:
            // Incorrect number of GBA Systems
            xxx_info_box_80141B4(gUnknown_80E7938, 0, 0, 0x101);
            break;
        case COMMS_NO_RESPONSE:
            // No response from friend. Redo from start
            xxx_info_box_80141B4(gUnknown_80E7994, 0, 0, 0x101);
            break;
        case COMMS_DIFFERENT_MODES:
            // Sender and receiver in different modes
            xxx_info_box_80141B4(gUnknown_80E79E4, 0, 0, 0x101);
            break;
        case 5:
            // "Communication Error"
            xxx_info_box_80141B4(gUnknown_80E7914, 0, 0, 0x101);
            break;
        case 14:
            // "Communication Error"
            xxx_info_box_80141B4(gUnknown_80E7914, 0, 0, 0x101);
            break;
        case COMMS_NOT_READY: // "No response from your friend. Make sure sender and receiver are ready"
            xxx_info_box_80141B4(gUnknown_80E7A48, 0, 0, 0x101);
            break;
        case COMMS_NO_ROOM_STORAGE:
        case COMMS_DUPLICATE_MAIL:
        case COMMS_MAIL_SENT_ALREADY:
        case COMMS_NOT_ELIGIBLE_1:
        case COMMS_FRIEND_NOT_ELIGIBLE:
        case COMMS_NOT_ELIGIBLE_2:
        case COMMS_FRIEND_NOT_ELIGIBLE_2:
        case COMMS_NO_ROOM_MAIL:
        default:
            // "Communication Error"
            xxx_info_box_80141B4(gUnknown_80E7914, 0, 0, 0x101);
            break;

    }
}

void HandlePasswordEntryScreen(void)
{
  int iVar2;

  iVar2 = sub_80154F0();
  MemoryFill8(gUnknown_203B3E8->UNK38.unk38_u8, 0, sizeof(gUnknown_203B3E8->UNK38));
  switch(iVar2){
    case 3:
      sub_80155F0();
      ResetUnusedInputStruct();
      xxx_call_save_unk_text_struct_800641C(gUnknown_203B3E8->unk1EC, TRUE, TRUE);
      if ( !DecodeWonderMailPassword(gUnknown_203B3E8->PasswordEntryBuffer, &gUnknown_203B3E8->UNK38.decodedMail) || !IsValidWonderMail(&gUnknown_203B3E8->UNK38.decodedMail) )
      {
        // Invalid password
        SetWonderMailMainMenuState(PASSWORD_INVALID);
      }
      else {
        // Successful password
        // Copy the decoded data to another buffer?
        gUnknown_203B3E8->unk3C0.mail = gUnknown_203B3E8->UNK38.decodedMail;

        gUnknown_203B3E8->wonderMailAccepted = TRUE;
        SetWonderMailMainMenuState(PASSWORD_SUCCESS);
      }
      break;
    case 2:
        sub_80155F0();
        ResetUnusedInputStruct();
        xxx_call_save_unk_text_struct_800641C(gUnknown_203B3E8->unk1EC, TRUE, TRUE);
        SetWonderMailMainMenuState(EXIT_TO_MAIN_MENU);
        break;
  }
}

void AdvanceToPasswordEntryScreen(void)
{
  int iVar2;
  if(sub_80144A4(&iVar2) == 0)
  {
      SetWonderMailMainMenuState(PASSWORD_ENTRY_SCREEN);
  }
}

void HandlePasswordSuccess(void)
{
  if (sub_802D0E0() == 3) {
    gUnknown_203B3E8->wonderMailAccepted = GetWonderMailAccepted();
    sub_802D184();
    if (gUnknown_203B3E8->wonderMailAccepted) {
        SetWonderMailMainMenuState(PREPARE_SAVE);
    }
    else {
        SetWonderMailMainMenuState(WONDER_MAIL_ADDED);
    }
  }
}

void HandlePrepareSaveScreen(void)
{
  int iVar2;
  if(sub_80144A4(&iVar2) == 0)
  {
      SetWonderMailMainMenuState(SAVE_ADVENTURE);
      PrepareSavePakWrite(MONSTER_NONE); // "Saving Adventure.."
  }
}

void ReturnToGameLinkCableMenu(void)
{
  int iVar2;
  if(sub_80144A4(&iVar2) == 0)
  {
      SetWonderMailMainMenuState(GAME_LINK_CABLE_MENU);
  }
}

void HandleSaveAdventureScreen(void)
{
  int iVar2;
  if(sub_80144A4(&iVar2) == 0)
  {
      if(!WriteSavePak())
      {
          FinishWriteSavePak();
          SetWonderMailMainMenuState(WONDER_MAIL_ADDED);
      }
  }
}

void HandleWonderMailAddedScreen(void)
{
  int iVar2;
  if(sub_80144A4(&iVar2) == 0)
  {
      SetWonderMailMainMenuState(EXIT_TO_MAIN_MENU);
  }
}

void HandleInvalidPasswordMenu(void)
{
  s32 menuAction;

  // Prompt to re-enter password
  if(sub_80144A4(&menuAction) == 0)
  {
    switch(menuAction)
    {
        case 6: // Yes
            SetWonderMailMainMenuState(PROMPT_PASSWORD_ENTRY);
            break;
        case 0: // No
            SetWonderMailMainMenuState(EXIT_TO_MAIN_MENU);
            break;
    }
  }
}

void nullsub_54(void)
{
}

void WonderMailMainMenuCallback(void)
{
  int linkStatus;
  unkStruct_803B344 *temp;

  switch(gUnknown_203B3E8->state) {
    case SELECT_WONDER_MAIL_MODE_MAIN_SCREEN:
        sub_8014248(gUnknown_80E7AC4,0,1,gSelectWonderMailModeMainMenuItems,0,4,0,0,0x101);
        break;
    case SEND_WONDER_MAIL_MAIN_SCREEN:
        sub_8014248(gUnknown_80E7AE0,0,3,gSendWonderMailMainMenuItems,0,4,0,0,0x101);
        break;
    case 3:
        ResetUnusedInputStruct();
        xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
        sub_802EF48();
        break;
    case RECEIVE_WONDER_MAIL_MAIN_SCREEN:
        sub_8014248(gUnknown_80E7B14,0,3,gReceiveWonderMailMainMenuItems,0,4,0,0,0x101);
        break;
    case PASSWORD_SUCCESS:
        gUnknown_203B3E8->unk474 = gUnknown_203B3E8->unk3C0.mail;
        if(gUnknown_203B3E8->unk474.unk2 == 4)
        {
            gUnknown_203B3E8->unk488 = &gUnknown_203B3E8->unk3C0.unk14;
            gUnknown_203B3E8->unk48C = gUnknown_203B3E8->unk3C0.unk3C;
        }
        else
        {
            gUnknown_203B3E8->unk488 = NULL;
            gUnknown_203B3E8->unk48C = NULL;
        }
        sub_802D098((unkSubStruct_203B2F8 *)&gUnknown_203B3E8->unk474);
        break;
    case PREPARE_SAVE:
        if(gUnknown_203B3E8->wonderMailAccepted)
        {
            switch(gUnknown_203B3E8->wonderMailMethod)
            {
                case WONDER_MAIL_GAME_LINK:
                case WONDER_MAIL_PASSWORD:
                    xxx_info_box_80141B4(gUnknown_80E7B48,0,0,0x101);
                    break;
                case 4:
                    break;
            }
        }
        else
            xxx_info_box_80141B4(gUnknown_80E7B48,0,0,0x101);
        break;
    case WONDER_MAIL_SENT:
        xxx_info_box_80141B4(gUnknown_80E7B68,0,0,0x101);
        break;
    case WONDER_MAIL_ADDED:
        if (gUnknown_203B3E8->wonderMailAccepted) {
            xxx_info_box_80141B4(gUnknown_80E7B88,0,0,0x101);
        }
        else {
            // Wonder Mail was refused
            xxx_info_box_80141B4(gUnknown_80E7BC8,0,0,0x101);
        }
        break;
    case GAME_LINK_CABLE_MENU:
        sub_8014248(gUnknown_80E7BEC,0,6,gUnknown_80E78F8,0,4,0,0,0x101);
        break;
    case 6:
        nullsub_23(FALSE);
        xxx_info_box_80141B4(gUnknown_80E7C48,0,0,0);
        break;
    case 9:
        gUnknown_203B3E8->wonderMailStatus = COMMS_GOOD;
        sub_8011830();
        linkStatus = sub_8037B28(gUnknown_203B3E8->unk24C);
        gUnknown_203B3E8->wonderMailStatus = linkStatus;
        if (linkStatus == COMMS_GOOD) {
            switch(gUnknown_203B3E8->unk24C)
            {
                case 9:
                    MemoryFill8((u8 *)&gUnknown_203B3E8->unk254,0,0xb4);
                    temp = sub_803B344(gUnknown_203B3E8->unk3BC);
                    if(temp->unk14 != NULL){
                        MemoryCopy8((u8 *)&gUnknown_203B3E8->unk254.unk14,temp->unk14,0x28);
                        MemoryCopy8((u8 *)&gUnknown_203B3E8->unk254.unk3C,temp->unk18,0x78);
                    }
                    gUnknown_203B3E8->unk254.mail = temp->mail;
                    gUnknown_203B3E8->wonderMailStatus = sub_8037D64(gUnknown_203B3E8->unk24C,&gUnknown_203B3E8->unk254,&gUnknown_203B3E8->unk308);
                    break;
                case 10:
                    MemoryFill8((u8 *)&gUnknown_203B3E8->unk254,0,0xb4);
                    MemoryFill8((u8 *)&gUnknown_203B3E8->unk308,0,0xb4);
                    gUnknown_203B3E8->wonderMailStatus = sub_8037D64(gUnknown_203B3E8->unk24C,&gUnknown_203B3E8->unk254,&gUnknown_203B3E8->unk308);
                    break;
            }
            if (gUnknown_203B3E8->wonderMailStatus == COMMS_GOOD)
            {
                switch(gUnknown_203B3E8->unk24C)
                {
                    case 9:
                    case 10:
                        gUnknown_203B3E8->wonderMailStatus = sub_80381F4(gUnknown_203B3E8->unk24C,&gUnknown_203B3E8->unk254,&gUnknown_203B3E8->unk308);
                        if (sub_800D588() != 0) {
                            gUnknown_203B3E8->unk3C0 = gUnknown_203B3E8->unk308;
                        }
                        else {
                            gUnknown_203B3E8->unk3C0 = gUnknown_203B3E8->unk254;
                        }
                        break;
                }
            }
        }
        xxx_call_start_bg_music();
        break;
    case PROMPT_PASSWORD_ENTRY:
        xxx_info_box_80141B4(gUnknown_80E7C98,0,0,0x101);
        break;
    case PASSWORD_ENTRY_SCREEN:
        RestoreUnkTextStruct_8006518(gUnknown_203B3E8->unk1EC);
        ResetUnusedInputStruct();
        xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
        sub_80151C0(5,gUnknown_203B3E8->PasswordEntryBuffer);
        break;
    case PASSWORD_INVALID:
        sub_8014248(gUnknown_80E7CC4,0,6,gUnknown_80E78F8,0,4,0,0,0x101);
        break;
  }
}

void SetWonderMailMainMenuState(u8 newState)
{
    gUnknown_203B3E8->state = newState;
    nullsub_54();
    WonderMailMainMenuCallback();
}
