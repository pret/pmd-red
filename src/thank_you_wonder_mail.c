#include "global.h"
#include "globaldata.h"
#include "code_800D090.h"
#include "code_80118A4.h"
#include "code_80130A8.h"
#include "code_801B3C0.h"
#include "code_801C8C4.h"
#include "code_802F204.h"
#include "code_8094F88.h"
#include "constants/communication_error_codes.h"
#include "cpu.h"
#include "input.h"
#include "items.h"
#include "main_menu1.h"
#include "memory.h"
#include "menu_input.h"
#include "other_menus2.h"
#include "pokemon.h"
#include "rescue_password_menu.h"
#include "save.h"
#include "save_write.h"
#include "text_util.h"
#include "text1.h"
#include "text2.h"
#include "thank_you_wonder_mail.h"
#include "wonder_mail_4.h"
#include "wonder_mail_5.h"

static EWRAM_DATA_2 WonderMailStruct_203B2C4 *sUnknown_203B2C4 = {0};

#define THANK_YOU_MAIL_MAIN_MENU 0
#define ANYTHING_ELSE_THANK_YOU_MAIN_MENU 1
#define EXIT_THANK_YOU_MAIL_PRE 2
#define EXIT_THANK_YOU_MAIL 3
#define NO_THANK_YOU_MAIL 4
#define SELECT_THANK_YOU_MAIL_COMMS 6
#define ITEM_EXISTS_ON_THANK_YOU_MAIL 7
#define PROMPT_RESEND_WITH_ATTACHED_ITEM 8
#define PROMPT_REWARD_ITEM_TO_SEND 9
#define THANK_YOU_MAIL_STORAGE_EMPTY 0xA
#define PROMPT_ITEM_TO_SEND 0xB
#define CONFIRM_ITEM_TO_SEND 0xC
#define THANK_YOU_MAIL_COMMS_CLEANUP 0xD
#define PROMPT_THANK_YOU_TO_SEND 0xF
#define SHOW_ITEM_TO_SEND_INFO 0x15
#define COMMUNICATING_THANK_YOU_MAIL 0x16

// TODO: verify it is 0x19 and not 0x1A
#define DISPLAY_THANK_YOU_PASSWORD 0x19

#define PROMPT_CONNECT_GAME_LINK 0x1D
#define THANK_YOU_MAIL_COMMS_FINISHED 0x1E
#define PRINT_THANK_YOU_ERROR 0x1F
#define THANK_YOU_PASSWORD_SUCCESS 0x21
#define PROMPT_THANK_YOU_PASSWORD 0x26
#define PROCESS_THANK_YOU_PASSWORD 0x27
#define THANK_YOU_PASSWORD_WRONG 0x28

enum menuActions {
    CANCEL_ACTION,
    SEND_THANK_YOU_MAIL_ACTION,
    GET_THANK_YOU_MAIL_ACTION,
    // 3 - GAME_LINK
    // 4 - ???
    // 5 - PASSWORD
    YES_ACTION = 0x7,
    NO_ACTION,
    SEND_ITEM_ACTION,
    NO_SEND_ITEM_ACTION,
    CONFIRM_ACTION,
    INFO_ACTION,
};

const Item gUnknown_80DED44 =
{
    ITEM_FLAG_EXISTS, 0, ITEM_NOTHING
};

extern char gUnknown_202E5D8[0x50];
extern char gAvailablePokemonNames[0x50];


const UnkTextStruct2 gUnknown_80DED48 =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x15, 0x04,
    0x06, 0x05,
    0x05, 0x00,
    NULL
};

const UnkTextStruct2 gUnknown_80DED60 =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x16, 0x07,
    0x06, 0x05,
    0x05, 0x00,
    NULL
};

extern const u8 SendItem_Text[];
extern const u8 DontSendItem_Text[];

const MenuItem gUnknown_80DED78[3] =
{
    {"Confirm", CONFIRM_ACTION},
    {"Info", INFO_ACTION},
    {NULL, CANCEL_ACTION},
};

// Unused
const UnkTextStruct2 gUnknown_80DEDA0 =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    NULL
};


const MenuItem gThankYouMailMainMenuItems[4] =
{
    {"Send Thank-You Mail", SEND_THANK_YOU_MAIL_ACTION},
    {"Get Thank-You Mail", GET_THANK_YOU_MAIL_ACTION},
    {"Cancel", CANCEL_ACTION},
    {NULL, CANCEL_ACTION},
};

const MenuItem gUnknown_80DEE08[4] =
{
    {"Game Link cable", WONDER_MAIL_GAME_LINK},
    {"Password", WONDER_MAIL_PASSWORD},
    {"Cancel", CANCEL_ACTION},
    {NULL, CANCEL_ACTION},
};

const MenuItem gUnknown_80DEE44[3] =
{
    {"Yes", YES_ACTION},
    {"Cancel", CANCEL_ACTION},
    {NULL, CANCEL_ACTION},
};

const MenuItem gUnknown_80DEE60[3] =
{
    {"Yes", YES_ACTION},
    {"No", NO_ACTION},
    {NULL, CANCEL_ACTION},
};

const MenuItem gUnknown_80DEE7C[4] =
{
    {SendItem_Text, SEND_ITEM_ACTION},
    {DontSendItem_Text, NO_SEND_ITEM_ACTION},
    {"Cancel", CANCEL_ACTION},
    {NULL, CANCEL_ACTION},
};

ALIGNED(4) static const u8 DontSendItem_Text[] =  _("Don{APOSTROPHE}t Send Item");
ALIGNED(4) static const u8 SendItem_Text[] = "Send Item";

const MenuItem gUnknown_80DEEBC[3] =
{
    {"Send w/o Item", NO_SEND_ITEM_ACTION},
    {"Cancel", CANCEL_ACTION},
    {NULL, CANCEL_ACTION},
};

const MenuItem gUnknown_80DEEE4[4] =
{
    {"Yes", YES_ACTION},
    {"No", NO_ACTION},
    {"Cancel", CANCEL_ACTION},
    {NULL, CANCEL_ACTION},
};

#include "data/thank_you_wonder_mail.h"


extern u32 sub_8031DCC(void);
extern void sub_8031E00(void);
extern void HandleThankYouMailPelipperMainMenu();
extern void sub_802AAC8();
extern void ReturnToThankYouMailMainMenu();
extern void sub_802AB7C();
extern void HandleMailCommunicationMenu();
extern void sub_802A98C();
extern void sub_802A9A8();
extern void sub_802A910();
extern void sub_802A8BC();
extern void sub_802A8A0();
extern void HandleConfirmItemtoSendMenu();
extern void ExitThankYouMailMenu1();
extern void sub_802A090();
extern void sub_802A158();
extern void sub_802A0C8();
extern void sub_802A174();
extern void sub_802A230();
extern void sub_802A28C();
extern void sub_802A39C();
extern void sub_802A33C();
extern void sub_802A740();
extern void sub_802A6F0();
extern void sub_802A68C();
extern void sub_802A4D4();
extern void sub_802A050();
extern void sub_802A4AC();
extern void sub_802A458();
extern void sub_802A75C();
extern void DisplayThankYouMailCommsOutcome();
extern void ReturnToThankYouMainFromError();
extern void ExitThankYouMailMenu2();
extern void sub_802AB60();
extern void sub_802AB98();
extern void sub_802A718();
extern void sub_802A6B4();
extern void AdvanceToThankYouPasswordProcessing();
extern void HandleThankYouMailPasswordMenu();
extern void sub_802A9FC();
extern void sub_802A828();
extern void sub_802A850();
extern void sub_8031E10();
extern void SetThankYouMailMenuState(u32);
extern s32 sub_8037B28(u32);
extern u8 sub_800D588(void);
extern u32 GetDungeonTeamRankPts(DungeonLocation *, u32);
extern void sub_8031D70(u8, u32);

extern void sub_8011C28(u32);
extern u32 sub_8039068(u32, u8 *r1, unkStruct_203B480 *r0);


u32 CreateThankYouMailPelipper(void)
{
  char *monName;
  OpenedFile *faceFile;
  s32 index;
  int counter;
  unkStruct_203B480 *mail;

  ResetUnusedInputStruct();
  xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
  sUnknown_203B2C4 = MemoryAlloc(sizeof(WonderMailStruct_203B2C4), 8);
  MemoryFill8((u8 *)sUnknown_203B2C4, 0, sizeof(WonderMailStruct_203B2C4));

  CopyYellowMonsterNametoBuffer(gUnknown_202E5D8, MONSTER_PELIPPER);
  monName = GetMonSpecies(MONSTER_PELIPPER);
  strcpy(gAvailablePokemonNames, monName);
  faceFile = GetDialogueSpriteDataPtr(MONSTER_PELIPPER);

  sUnknown_203B2C4->faceFile = faceFile;
  sUnknown_203B2C4->faceData = faceFile->data;
  sUnknown_203B2C4->unk42C = 0;
  sUnknown_203B2C4->unk42D = 0;
  sUnknown_203B2C4->unk42E = 0;
  sUnknown_203B2C4->unk428 = 2;
  sUnknown_203B2C4->unk42A = 8;

  for(counter = 0; counter < PASSWORD_BUFFER_SIZE; counter++){
    sUnknown_203B2C4->passwordBuffer[counter] = 0;
  }

  sUnknown_203B2C4->wonderMailMethod = WONDER_MAIL_GAME_LINK;
  sUnknown_203B2C4->wonderMailMode = WONDER_MAIL_MODE_SEND;

  index = GetFirstIndexofMailType(6);
  if (index != -1) {
    mail = GetMailatIndex(index);
    sUnknown_203B2C4->unk41C = mail->item;
    sUnknown_203B2C4->mailIndex = index;
    sUnknown_203B2C4->unk430 = mail->unk10.unk10;
    SetThankYouMailMenuState(5);
  }
  else {
    sUnknown_203B2C4->unk41C = gUnknown_80DED44;
    sUnknown_203B2C4->mailIndex = -1;
    SetThankYouMailMenuState(THANK_YOU_MAIL_MAIN_MENU);
  }
  sUnknown_203B2C4->fallbackState = 0x2b;
  return 1;
}

u32 ThankYouMailPelipperCallback(void)
{

  switch(sUnknown_203B2C4->state) {
    case 5:
        sub_802AB7C();
        break;
    case THANK_YOU_MAIL_COMMS_FINISHED:
        DisplayThankYouMailCommsOutcome();
        break;
    case PRINT_THANK_YOU_ERROR:
        ReturnToThankYouMainFromError();
        break;
    case 0xe:
        sub_802A090();
        break;
    case PROMPT_THANK_YOU_TO_SEND:
        sub_802A158();
        break;
    case 0x11:
        sub_802A174();
        break;
    case 0x12:
        sub_802A230();
        break;
    case 0x10:
        sub_802A0C8();
        break;
    case 0x13:
        sub_802A28C();
        break;
    case 0x14:
        sub_802A39C();
        break;
    case SHOW_ITEM_TO_SEND_INFO:
        sub_802A33C();
        break;
    case 0x1c:
        sub_802A458();
        break;
    case 0x1b:
        sub_802A4AC();
        break;
    case DISPLAY_THANK_YOU_PASSWORD:
        sub_802A4D4();
        break;
    case 0x1a:
        sub_802A050();
        break;
    case THANK_YOU_PASSWORD_WRONG:
        sub_802A9FC();
        break;
    case PROMPT_THANK_YOU_PASSWORD:
        AdvanceToThankYouPasswordProcessing();
        break;
    case PROCESS_THANK_YOU_PASSWORD:
        HandleThankYouMailPasswordMenu();
        break;
    case 0x25:
        sub_802A6B4();
        break;
    case 0x24:
        sub_802A718();
        break;
    case THANK_YOU_PASSWORD_SUCCESS:
        sub_802AB60();
        break;
    case 0x22:
        sub_802AB98();
        break;
    case COMMUNICATING_THANK_YOU_MAIL:
        sub_802A740();
        break;
    case 0x18:
        sub_802A68C();
        break;
    case 0x17:
        sub_802A6F0();
        break;
    case PROMPT_CONNECT_GAME_LINK:
        sub_802A75C();
        break;
    case 0x20:
        ExitThankYouMailMenu2();
        break;
    case THANK_YOU_MAIL_COMMS_CLEANUP:
        ExitThankYouMailMenu1();
        break;
    case CONFIRM_ITEM_TO_SEND:
        HandleConfirmItemtoSendMenu();
        break;
    case 0x29:
        sub_802A828();
        break;
    case 0x2a:
        sub_802A850();
        break;
    case PROMPT_ITEM_TO_SEND:
        sub_802A8A0();
        break;
    case THANK_YOU_MAIL_STORAGE_EMPTY:
        sub_802A8BC();
        break;
    case PROMPT_REWARD_ITEM_TO_SEND:
        sub_802A910();
        break;
    case ITEM_EXISTS_ON_THANK_YOU_MAIL:
        sub_802A98C();
        break;
    case PROMPT_RESEND_WITH_ATTACHED_ITEM:
        sub_802A9A8();
        break;
    case SELECT_THANK_YOU_MAIL_COMMS:
        HandleMailCommunicationMenu();
        break;
    case NO_THANK_YOU_MAIL:
        ReturnToThankYouMailMainMenu();
        break;
    case THANK_YOU_MAIL_MAIN_MENU:
    case ANYTHING_ELSE_THANK_YOU_MAIN_MENU:
        HandleThankYouMailPelipperMainMenu();
        break;
    case EXIT_THANK_YOU_MAIL_PRE:
        sub_802AAC8();
        break;
    case EXIT_THANK_YOU_MAIL:
        return 3;
  }
  return 0;
}

void CleanThankYouMailPelipper(void)
{
    if(sUnknown_203B2C4 != NULL)
    {
        CloseFile(sUnknown_203B2C4->faceFile);
        MemoryFree(sUnknown_203B2C4);
        sUnknown_203B2C4 = NULL;
        sub_8030DE4();
        sub_801B450();
        sub_803084C();
        sub_801CBB8();
        sub_80155F0();
        sub_8031E10();
        sub_802F2C0();
    }
}

void ReturnToThankYouMainFromError(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        SetThankYouMailMenuState(ANYTHING_ELSE_THANK_YOU_MAIN_MENU);
    }
}

void PrintThankYouMailLinkError(u32 errorCode)
{
  switch(errorCode) {
    case COMMS_INCORRECT_NUM_SYSTEMS:
        xxx_info_box_80141B4(gUnknown_80DEF28, 0, &sUnknown_203B2C4->faceFile, 0x10d);
        break;
    case COMMS_DIFFERENT_MODES:
        xxx_info_box_80141B4(gUnknown_80DEF80, 0, &sUnknown_203B2C4->faceFile, 0x10d);
        break;
    case COMMS_NO_ROOM_STORAGE:
        xxx_info_box_80141B4(gUnknown_80DEFDC, 0, &sUnknown_203B2C4->faceFile, 0x10d);
        break;
    case COMMS_DUPLICATE_MAIL:
        xxx_info_box_80141B4(gUnknown_80DF044, 0, &sUnknown_203B2C4->faceFile, 0x10d);
        break;
    case COMMS_NOT_ELIGIBLE_1:
        xxx_info_box_80141B4(gUnknown_80DF0A0, 0, &sUnknown_203B2C4->faceFile, 0x10d);
        break;
    case COMMS_NOT_ELIGIBLE_2:
        xxx_info_box_80141B4(gUnknown_80DF0A0, 0, &sUnknown_203B2C4->faceFile, 0x10d);
        break;
    case COMMS_NO_ROOM_MAIL:
        xxx_info_box_80141B4(gUnknown_80DF0E0, 0, &sUnknown_203B2C4->faceFile, 0x10d);
        break;
    case 1:
    case COMMS_NO_RESPONSE:
    case 5:
    case 14:
        xxx_info_box_80141B4(gUnknown_80DEF04, 0, &sUnknown_203B2C4->faceFile, 0x10d);
        break;
    case COMMS_NOT_READY:
        xxx_info_box_80141B4(gUnknown_80DF138, 0, &sUnknown_203B2C4->faceFile, 0x10d);
        break;
    case COMMS_GOOD:
    default:
        break;
  }
}

void DisplayThankYouMailCommsOutcome(void)
{
  s32 auStack20;

  if (sub_80144A4(&auStack20) != 0) {
    return;
  }
  MemoryFill8((u8 *)&sUnknown_203B2C4->unk41C, 0, sizeof(Item));
  sUnknown_203B2C4->unk41C.id = ITEM_NOTHING;
  sUnknown_203B2C4->unk41C.quantity = 1;
  sUnknown_203B2C4->unk41C.flags = 0;
  if (sUnknown_203B2C4->linkError == COMMS_GOOD) {
      switch(sUnknown_203B2C4->unk40)
        {
            case 6:
                switch(sUnknown_203B2C4->wonderMailMethod)
                {
                    case WONDER_MAIL_GAME_LINK:
                    case WONDER_MAIL_PASSWORD:
                    case 6:
                        // "Thank-You Mail has been sent"
                        xxx_info_box_80141B4(gUnknown_80DF194, 0, &sUnknown_203B2C4->faceFile, 0x10d);
                        break;
                    case 4:
                    default:
                        break;
                }
                SetThankYouMailMenuState(THANK_YOU_MAIL_COMMS_CLEANUP);
                break;
            case 7:
                SetThankYouMailMenuState(THANK_YOU_PASSWORD_SUCCESS);
                break;
            default:
                break;
        }
  }
  else
  {
      PrintThankYouMailLinkError(sUnknown_203B2C4->linkError);
      SetThankYouMailMenuState(PRINT_THANK_YOU_ERROR);
  }
}

void sub_802A050(void)
{
    switch(sub_8031DCC())
    {
        case 3:
        case 2:
            sub_8031E10();
            ResetUnusedInputStruct();
            xxx_call_save_unk_text_struct_800641C(sUnknown_203B2C4->unk3BC, TRUE, TRUE);
            SetThankYouMailMenuState(0x1B);
            break;
        case 1:
            sub_8031E00();
            break;
        default:
            return;
    }
}

void sub_802A090(void)
{
    s32 menuAction;
    if(sub_80144A4(&menuAction) == 0)
    {
        switch(menuAction)
        {
            case YES_ACTION:
                SetThankYouMailMenuState(SELECT_THANK_YOU_MAIL_COMMS);
                break;
            case NO_ACTION:
            case CANCEL_ACTION:
                SetThankYouMailMenuState(ANYTHING_ELSE_THANK_YOU_MAIN_MENU);
                break;
            default:
                break;
        }
    }
}

void sub_802A0C8(void)
{
  switch(sub_8030768(1))
  {
    case 2:
        sub_803084C();
        SetThankYouMailMenuState(ANYTHING_ELSE_THANK_YOU_MAIN_MENU);
        break;
    case 3:
        sUnknown_203B2C4->mailIndex = sub_80307EC();
        SetThankYouMailMenuState(0x11);
        break;
    case 4:
        sUnknown_203B2C4->fallbackState = 0x10;
        sUnknown_203B2C4->mailIndex = sub_80307EC();
        RestoreUnkTextStruct_8006518(sUnknown_203B2C4->unk3BC);
        ResetUnusedInputStruct();
        xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
        sub_8030D40(sUnknown_203B2C4->mailIndex,0);
        SetThankYouMailMenuState(0x12);
        break;
  }
}

void sub_802A158(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        SetThankYouMailMenuState(0x10);
    }
}

void sub_802A174(void)
{
  s32 menuAction;

  menuAction = -1;
  sub_8030768(0);
  if (sub_8012FD8(&sUnknown_203B2C4->unk21C[3]) == 0) {
    sub_8013114(&sUnknown_203B2C4->unk21C[3], &menuAction);
  }

  switch(menuAction)
  {
      case CONFIRM_ACTION:
        sub_803084C();
        SetThankYouMailMenuState(0xe);
        break;
      case INFO_ACTION:
        sUnknown_203B2C4->fallbackState = 0x2b;
        RestoreUnkTextStruct_8006518(sUnknown_203B2C4->unk3BC);
        ResetUnusedInputStruct();
        xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
        sub_8030D40(sUnknown_203B2C4->mailIndex,0);
        SetThankYouMailMenuState(0x12);
        break;
      case CANCEL_ACTION:
      case 0xD:
        sub_8035CC0(sUnknown_203B2C4->unk35C,2);
        sub_8030810(1);
        SetThankYouMailMenuState(0x10);
      default:
        break;
  }
}

void sub_802A230(void)
{
  switch(sub_8030DA0())
  {
      case 2:
      case 3:
        sub_8030DE4();
        ResetUnusedInputStruct();
        xxx_call_save_unk_text_struct_800641C(sUnknown_203B2C4->unk3BC, TRUE, TRUE);
        sub_803092C();
        if (sUnknown_203B2C4->fallbackState == 0x2b) {
            sub_8035CF4(sUnknown_203B2C4->unk21C, 3, TRUE);
            SetThankYouMailMenuState(0x11);
        }
        else {
            SetThankYouMailMenuState(sUnknown_203B2C4->fallbackState);
        }
        break;
    default:
        break;
  }
}

void sub_802A28C(void)
{

  sUnknown_203B2C4->unk41C.id = ITEM_NOTHING;
  sUnknown_203B2C4->unk41C.quantity = 1;
  sUnknown_203B2C4->unk41C.flags = 0;

  switch(sub_801CA08(TRUE))
  {
    case 2:
        sub_801CBB8();
        SetThankYouMailMenuState(ANYTHING_ELSE_THANK_YOU_MAIN_MENU);
        break;
    case 3:
        sUnknown_203B2C4->unk41C.id = sub_801CB24();
        SetThankYouMailMenuState(0x14);
        break;
    case 4:
        sUnknown_203B2C4->fallbackState = 0x13;
        sUnknown_203B2C4->unk41C.id = sub_801CB24();
        RestoreUnkTextStruct_8006518(sUnknown_203B2C4->unk3BC);
        ResetUnusedInputStruct();
        xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
        sub_801B3C0(&sUnknown_203B2C4->unk41C);
        SetThankYouMailMenuState(SHOW_ITEM_TO_SEND_INFO);
        break;
  }
}

void sub_802A33C(void)
{
  switch(sub_801B410())
 {
     case 2:
     case 3:
        sub_801B450();
        ResetUnusedInputStruct();
        xxx_call_save_unk_text_struct_800641C(sUnknown_203B2C4->unk3BC, TRUE, TRUE);
        sub_801CB5C(TRUE);
        if (sUnknown_203B2C4->fallbackState == 0x2b) {
            sub_8035CF4(sUnknown_203B2C4->unk21C,3,TRUE);
            SetThankYouMailMenuState(0x14);
        }
        else {
            SetThankYouMailMenuState(sUnknown_203B2C4->fallbackState);
        }
        break;
    case 1:
    default:
        break;
  }
}

void sub_802A39C(void)
{
  s32 menuAction;

  menuAction = -1;
  sub_801CA08(FALSE);
  if (sub_8012FD8(&sUnknown_203B2C4->unk21C[3]) == 0) {
    sub_8013114(&sUnknown_203B2C4->unk21C[3], &menuAction);
  }

  switch(menuAction)
  {
      case CONFIRM_ACTION:
            sub_801CBB8();
            SetThankYouMailMenuState(CONFIRM_ITEM_TO_SEND);
            break;
      case INFO_ACTION:
            sUnknown_203B2C4->fallbackState = 0x2b;
            RestoreUnkTextStruct_8006518(sUnknown_203B2C4->unk3BC);
            ResetUnusedInputStruct();
            xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
            sub_801B3C0(&sUnknown_203B2C4->unk41C);
            SetThankYouMailMenuState(SHOW_ITEM_TO_SEND_INFO);
            break;
      case CANCEL_ACTION:
      case 0xD:
            sub_8035CC0(sUnknown_203B2C4->unk35C, 3);
            sub_801CCD8();
            SetThankYouMailMenuState(0x13);
      default:
        break;
  }
}

void sub_802A458(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        SetThankYouMailMenuState(THANK_YOU_MAIL_COMMS_CLEANUP);
    }
}

void ExitThankYouMailMenu1(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        SetThankYouMailMenuState(EXIT_THANK_YOU_MAIL);
    }
}

void ExitThankYouMailMenu2(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        SetThankYouMailMenuState(EXIT_THANK_YOU_MAIL);
    }
}

void sub_802A4AC(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        SetThankYouMailMenuState(0x18);
        sub_8011C28(1);
        PrepareSavePakWrite(MONSTER_NONE);
    }
}

void sub_802A4D4(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        SetThankYouMailMenuState(0x1A);
    }
}

void AdvanceToThankYouPasswordProcessing(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        SetThankYouMailMenuState(PROCESS_THANK_YOU_PASSWORD);
    }
}

void HandleThankYouMailPasswordMenu(void)
{
  u8 mailIndex;
  unkStruct_203B480 *mail;
  u32 return_var;
  unkStruct_203B480 mail1;

  return_var = sub_80154F0();
  MemoryFill8((u8 *)&mail1, 0, sizeof(unkStruct_203B480));
  switch(return_var)
  {
    case 3:
        switch(sub_8039068(PASSWORD_ENTRY_THANK_YOU_MAIL_MODE,sUnknown_203B2C4->passwordBuffer,&mail1))
        {
            case PASSWORD_ENTRY_INCORRECT_PASSWORD:
                sub_8014248(gUnknown_80DF1C0, 0, 7, gUnknown_80DEE44, 0, 4, 0, &sUnknown_203B2C4->faceFile, 0xc);
                SetThankYouMailMenuState(THANK_YOU_PASSWORD_WRONG);
                break;
            case PASSWORD_ENTRY_NOT_THANK_YOU_MAIL:
                xxx_info_box_80141B4(gUnknown_80DF208, 0, &sUnknown_203B2C4->faceFile, 0x10d);
                SetThankYouMailMenuState(PRINT_THANK_YOU_ERROR);
                break;
            case PASSWORD_ENTRY_DUPLICATE_THANK_YOU_MAIL:
                xxx_info_box_80141B4(gUnknown_80DF0A0, 0, &sUnknown_203B2C4->faceFile, 0x10d);
                SetThankYouMailMenuState(PRINT_THANK_YOU_ERROR);
                break;
            case PASSWORD_ENTRY_THANK_YOU_MAIL_SUCCESS:
                mailIndex = GetMailIndex(4,mail1.unk10.unk10);
                mail = GetMailatIndex(mailIndex);
                *mail = mail1;
                mail->mailType = 6;
                sUnknown_203B2C4->unk430 = mail1.unk10.unk10;
                SetThankYouMailMenuState(THANK_YOU_PASSWORD_SUCCESS);
                break;
            default:
            case 7:
                break;
        }
    sub_80155F0();
    break;
  case 2:
    sub_80155F0();
    ResetUnusedInputStruct();
    xxx_call_save_unk_text_struct_800641C(sUnknown_203B2C4->unk3BC, TRUE, TRUE);
    SetThankYouMailMenuState(ANYTHING_ELSE_THANK_YOU_MAIN_MENU);
    break;
  }
}

void sub_802A68C(void)
{
  s32 temp;

  if (sub_80144A4(&temp) == 0) {
    if (!WriteSavePak()) {
      FinishWriteSavePak();
      SetThankYouMailMenuState(THANK_YOU_MAIL_COMMS_CLEANUP);
    }
  }
}

void sub_802A6B4(void)
{
  int saveStatus;
  u32 temp;

  if (sub_80144A4(&temp) == 0) {
    if (!WriteSavePak()) {
      saveStatus = GetSavePakStatus();
      FinishWriteSavePak();
      if (saveStatus == SAVE_COMPLETED) {
        SetThankYouMailMenuState(0x20);
      }
      else {
        SetThankYouMailMenuState(EXIT_THANK_YOU_MAIL);
      }
    }
  }
}

void sub_802A6F0(void)
{
  s32 temp;

  if (sub_80144A4(&temp) == 0) {
    SetThankYouMailMenuState(0x18);
    sub_8011C28(1);
    PrepareSavePakWrite(MONSTER_NONE);
  }
}

void sub_802A718(void)
{
  s32 temp;

  if (sub_80144A4(&temp) == 0) {
    SetThankYouMailMenuState(0x25);
    sub_8011C28(1);
    PrepareSavePakWrite(MONSTER_NONE);
  }
}

void sub_802A740(void)
{
  s32 temp;

  if (sub_80144A4(&temp) == 0) {
    SetThankYouMailMenuState(THANK_YOU_MAIL_COMMS_FINISHED);
  }
}

void sub_802A75C(void)
{
    s32 menuAction;
    if(sub_80144A4(&menuAction) == 0)
    {
        switch(menuAction)
        {
            case YES_ACTION:
                // NOTE: if statement is needed to match
                if(sUnknown_203B2C4->wonderMailMode)
                    SetThankYouMailMenuState(COMMUNICATING_THANK_YOU_MAIL);
                else
                    SetThankYouMailMenuState(COMMUNICATING_THANK_YOU_MAIL);
                break;
            case CANCEL_ACTION:
                SetThankYouMailMenuState(ANYTHING_ELSE_THANK_YOU_MAIN_MENU);
                break;
        }
    }
}

void HandleConfirmItemtoSendMenu(void)
{
    s32 menuAction;
    unkStruct_203B480 *mail;
    if(sub_80144A4(&menuAction) == 0)
    {
        switch(menuAction)
        {
            case YES_ACTION:
                mail = GetMailatIndex(sUnknown_203B2C4->mailIndex);
                if(sUnknown_203B2C4->unk41C.id != ITEM_NOTHING)
                {
                    mail->item = sUnknown_203B2C4->unk41C;
                }
                gTeamInventoryRef->teamStorage[sUnknown_203B2C4->unk41C.id]--;
                SetThankYouMailMenuState(0x29);
                break;
            case NO_ACTION:
                SetThankYouMailMenuState(PROMPT_ITEM_TO_SEND);
                break;
            case CANCEL_ACTION:
                SetThankYouMailMenuState(ANYTHING_ELSE_THANK_YOU_MAIN_MENU);
                break;
        }
    }
}

void sub_802A828(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        SetThankYouMailMenuState(0x2A);
        sub_8011C28(1);
        PrepareSavePakWrite(MONSTER_NONE);
    }
}

void sub_802A850(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        if(!WriteSavePak())
        {
            FinishWriteSavePak();
            switch(sUnknown_203B2C4->wonderMailMethod)
            {
                case WONDER_MAIL_GAME_LINK:
                case 4:
                    SetThankYouMailMenuState(PROMPT_CONNECT_GAME_LINK);
                    break;
                case WONDER_MAIL_PASSWORD:
                    SetThankYouMailMenuState(DISPLAY_THANK_YOU_PASSWORD);
                    break;
            }
        }
    }
}

void sub_802A8A0(void)
{
  s32 temp;

  if (sub_80144A4(&temp) == 0) {
    SetThankYouMailMenuState(0x13);
  }
}

void sub_802A8BC(void)
{
    s32 menuAction;
    if(sub_80144A4(&menuAction) == 0)
    {
        switch(menuAction)
        {
            case NO_SEND_ITEM_ACTION:
                switch(sUnknown_203B2C4->wonderMailMethod)
                {
                    case WONDER_MAIL_GAME_LINK:
                    case 4:
                        SetThankYouMailMenuState(PROMPT_CONNECT_GAME_LINK);
                        break;
                    case WONDER_MAIL_PASSWORD:
                        SetThankYouMailMenuState(DISPLAY_THANK_YOU_PASSWORD);
                        break;
                }
                break;
            case CANCEL_ACTION:
                SetThankYouMailMenuState(ANYTHING_ELSE_THANK_YOU_MAIN_MENU);
                break;
        }
    }
}

void sub_802A910(void)
{
    s32 menuAction;
    if(sub_80144A4(&menuAction) == 0)
    {
        switch(menuAction)
        {
            case SEND_ITEM_ACTION:
                if(sub_801CF14(0))
                {
                    SetThankYouMailMenuState(THANK_YOU_MAIL_STORAGE_EMPTY);
                }
                else
                {
                    SetThankYouMailMenuState(PROMPT_ITEM_TO_SEND);
                }
                break;
            case NO_SEND_ITEM_ACTION:
                switch(sUnknown_203B2C4->wonderMailMethod)
                {
                    case WONDER_MAIL_GAME_LINK:
                    case 4:
                        SetThankYouMailMenuState(PROMPT_CONNECT_GAME_LINK);
                        break;
                    case WONDER_MAIL_PASSWORD:
                        SetThankYouMailMenuState(DISPLAY_THANK_YOU_PASSWORD);
                        break;
                }
                break;
            case CANCEL_ACTION:
                SetThankYouMailMenuState(ANYTHING_ELSE_THANK_YOU_MAIN_MENU);
                break;
        }
    }
}

void sub_802A98C(void)
{
  s32 temp;

  if (sub_80144A4(&temp) == 0) {
    SetThankYouMailMenuState(PROMPT_RESEND_WITH_ATTACHED_ITEM);
  }
}

void sub_802A9A8(void)
{
    s32 menuAction;
    if(sub_80144A4(&menuAction) == 0)
    {
        switch(menuAction)
        {
            case YES_ACTION:
                switch(sUnknown_203B2C4->wonderMailMethod)
                {
                    case WONDER_MAIL_GAME_LINK:
                    case 4:
                        SetThankYouMailMenuState(PROMPT_CONNECT_GAME_LINK);
                        break;
                    case WONDER_MAIL_PASSWORD:
                        SetThankYouMailMenuState(DISPLAY_THANK_YOU_PASSWORD);
                        break;
                }
                break;
            case CANCEL_ACTION:
                SetThankYouMailMenuState(ANYTHING_ELSE_THANK_YOU_MAIN_MENU);
                break;
        }
    }
}

void sub_802A9FC(void)
{
    s32 menuAction;
    if(sub_80144A4(&menuAction) == 0)
    {
        switch(menuAction)
        {
            case YES_ACTION:
                SetThankYouMailMenuState(PROMPT_THANK_YOU_PASSWORD);
                break;
            case CANCEL_ACTION:
                SetThankYouMailMenuState(ANYTHING_ELSE_THANK_YOU_MAIN_MENU);
                break;
        }
    }
}

void HandleMailCommunicationMenu(void)
{
    s32 menuAction;
    unkStruct_203B480 *mail;
    if(sub_80144A4(&menuAction) == 0)
    {
        switch(menuAction)
        {
            case WONDER_MAIL_GAME_LINK:
            case 4:
            case WONDER_MAIL_PASSWORD:
                sUnknown_203B2C4->wonderMailMethod = menuAction;
                switch(sUnknown_203B2C4->wonderMailMode)
                {
                    case WONDER_MAIL_MODE_SEND:
                        mail = GetMailatIndex(GetFirstIndexofMailType(WONDER_MAIL_TYPE_THANK_YOU));
                        if(mail->item.id != ITEM_NOTHING)
                        {
                            SetThankYouMailMenuState(ITEM_EXISTS_ON_THANK_YOU_MAIL);
                        }
                        else
                        {
                            SetThankYouMailMenuState(PROMPT_REWARD_ITEM_TO_SEND);
                        }
                        break;
                    default:
                        if(sUnknown_203B2C4->wonderMailMethod == WONDER_MAIL_PASSWORD)
                        {
                            SetThankYouMailMenuState(PROMPT_THANK_YOU_PASSWORD);
                        }
                        else
                        {
                            SetThankYouMailMenuState(PROMPT_CONNECT_GAME_LINK);
                        }
                        break;
                }
                break;
            case CANCEL_ACTION:
                SetThankYouMailMenuState(ANYTHING_ELSE_THANK_YOU_MAIN_MENU);
                break;
        }
    }
}

void ReturnToThankYouMailMainMenu(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        SetThankYouMailMenuState(ANYTHING_ELSE_THANK_YOU_MAIN_MENU);
    }
}

void sub_802AAC8(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        SetThankYouMailMenuState(EXIT_THANK_YOU_MAIL);
    }
}

void HandleThankYouMailPelipperMainMenu(void)
{
    s32 menuAction;
    if(sub_80144A4(&menuAction) == 0)
    {
        switch(menuAction)
        {
            case SEND_THANK_YOU_MAIL_ACTION:
                sUnknown_203B2C4->unk40 = 6;
                sUnknown_203B2C4->wonderMailMode = WONDER_MAIL_MODE_SEND;
                if(CountMailType(5) == 0)
                {
                    SetThankYouMailMenuState(NO_THANK_YOU_MAIL);
                }
                else
                {
                    SetThankYouMailMenuState(PROMPT_THANK_YOU_TO_SEND);
                }
                break;
            case GET_THANK_YOU_MAIL_ACTION:
                sUnknown_203B2C4->unk40 = 7;
                sUnknown_203B2C4->wonderMailMode = WONDER_MAIL_MODE_RECEIVE;
                SetThankYouMailMenuState(SELECT_THANK_YOU_MAIL_COMMS);
                break;
            case CANCEL_ACTION:
                SetThankYouMailMenuState(2);
                break;
        }
    }
}

void sub_802AB60(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        SetThankYouMailMenuState(0x22);
    }
}

void sub_802AB7C(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        SetThankYouMailMenuState(0x22);
    }
}


void sub_802AB98(void)
{
    const char *monName;
    switch(sub_802F298())
    {
        case 3:
            sub_802F2C0();
            CopyYellowMonsterNametoBuffer(gUnknown_202E5D8, MONSTER_PELIPPER);
            monName = GetMonSpecies(MONSTER_PELIPPER);
            strcpy(gAvailablePokemonNames, monName);
            DeleteMailAtIndex(GetMailIndex(6, sUnknown_203B2C4->unk430));
            SetThankYouMailMenuState(0x24);
            break;
        default:
            break;
    }
}

void nullsub_131(void)
{
}

void UpdateThankYouMailText(void)
{
  u8 itemIndex;
  char *monName;
  u8 buffer1 [80];
  u8 buffer2 [80];
  u8 mailIndex;
  PokemonStruct1 *pokeStruct;
  PokemonStruct1 *pokeStruct2;
  s32 linkStatus;
  unkStruct_203B480 *mail;

  switch(sUnknown_203B2C4->state) {
    case 5:
        pokeStruct = GetPlayerPokemonStruct();
        sub_80922B4(buffer1,pokeStruct->name, POKEMON_NAME_LENGTH);
        sprintfStatic(sUnknown_203B2C4->formattedString,gUnknown_80DF250,buffer1);
        xxx_info_box_80141B4(sUnknown_203B2C4->formattedString,0,&sUnknown_203B2C4->faceFile,0x10d);
        break;
    case 0xe:
        // Is it OK to send this Thank-You Mail?
        sub_8014248(gUnknown_80DF304,0,7,gUnknown_80DEE60,0,4,0,&sUnknown_203B2C4->faceFile,0xc);
        break;
    case PROMPT_THANK_YOU_TO_SEND:
        // Please choose the Thank-You Mail that you want to send to your friend
        xxx_info_box_80141B4(gUnknown_80DF330,0,&sUnknown_203B2C4->faceFile,0x10d);
        break;
    case 0x10:
        if (sub_8030894() != 0)
            break;
        ResetUnusedInputStruct();
        xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
        sub_80306A8(WONDER_MAIL_TYPE_THANK_YOU,0,0,6);
        break;
    case 0x11:
        RestoreUnkTextStruct_8006518(sUnknown_203B2C4->unk35C);
        SetMenuItems(sUnknown_203B2C4->unk21C,sUnknown_203B2C4->unk35C,3,&gUnknown_80DED60,gUnknown_80DED78,TRUE,0,FALSE);
        sub_803092C();
        sub_8035CF4(sUnknown_203B2C4->unk21C,3,TRUE);
        break;
    case 0x13:
        if (sub_801D008() != NULL)
            break;
        ResetUnusedInputStruct();
        xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
        {
        UnkTextStruct2_sub local_x = {3, 2};
        sub_801C8C4(0, 1, &local_x, 9);
        }
        break;
    case 0x14:
        RestoreUnkTextStruct_8006518(sUnknown_203B2C4->unk35C);
        SetMenuItems(sUnknown_203B2C4->unk21C,sUnknown_203B2C4->unk35C,3,&gUnknown_80DED48,gUnknown_80DED78,TRUE,0,FALSE);
        sub_801CCD8();
        sub_8035CF4(sUnknown_203B2C4->unk21C,3,TRUE);
        break;
    case THANK_YOU_MAIL_COMMS_FINISHED:
        sUnknown_203B2C4->linkError = COMMS_GOOD;
        sub_8011830();
        linkStatus = sub_8037B28(sUnknown_203B2C4->unk40);
        sUnknown_203B2C4->linkError = linkStatus;
        if (linkStatus == COMMS_GOOD)
        {
            switch(sUnknown_203B2C4->unk40)
            {
                case 6:
                    MemoryFill8((u8 *)&sUnknown_203B2C4->unk1B8,0, sizeof(unkStruct_203B480));
                    sUnknown_203B2C4->unk1B8 = *GetMailatIndex(sUnknown_203B2C4->mailIndex);
                    sUnknown_203B2C4->linkError = sub_8037D64(sUnknown_203B2C4->unk40,&sUnknown_203B2C4->unk1B8,&sUnknown_203B2C4->unk1E8);
                    break;
                case 7:
                    MemoryFill8((u8 *)&sUnknown_203B2C4->unk1B8,0, sizeof(unkStruct_203B480));
                    MemoryFill8((u8 *)&sUnknown_203B2C4->unk1E8,0, sizeof(unkStruct_203B480));
                    sUnknown_203B2C4->linkError = sub_8037D64(sUnknown_203B2C4->unk40,&sUnknown_203B2C4->unk1B8,&sUnknown_203B2C4->unk1E8);
                    break;
            }
            if (sUnknown_203B2C4->linkError == COMMS_GOOD){
                switch(sUnknown_203B2C4->unk40){
                    case 6:
                    case 7:
                        sUnknown_203B2C4->linkError = sub_80381F4(sUnknown_203B2C4->unk40,&sUnknown_203B2C4->unk1B8,&sUnknown_203B2C4->unk1E8);
                        if ( sub_800D588() != '\0') {
                            sUnknown_203B2C4->unk430 = sUnknown_203B2C4->unk1E8.unk10.unk10;
                        }
                        else {
                            sUnknown_203B2C4->unk430 = sUnknown_203B2C4->unk1B8.unk10.unk10;
                        }
                    break;
                }
            }
        }
        xxx_call_start_bg_music();
        break;
    case PROMPT_THANK_YOU_PASSWORD:
        // OK. Please enter the Thank-You Mail Password
        xxx_info_box_80141B4(gUnknown_80DF380,0,&sUnknown_203B2C4->faceFile,0x10d);
        break;
    case PROCESS_THANK_YOU_PASSWORD:
        RestoreUnkTextStruct_8006518(sUnknown_203B2C4->unk3BC);
        ResetUnusedInputStruct();
        xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
        sub_80151C0(4,sUnknown_203B2C4->passwordBuffer);
        break;
    case 0x1a:
        RestoreUnkTextStruct_8006518(sUnknown_203B2C4->unk3BC);
        ResetUnusedInputStruct();
        xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
        sub_8031D70(sUnknown_203B2C4->mailIndex,0);
        break;
    case 0x1b:
        // Please give this password to the friend that rescued your team. I also must save your adventure
        xxx_info_box_80141B4(gUnknown_80DF3B4,0,&sUnknown_203B2C4->faceFile,0x10d);
        break;
    case DISPLAY_THANK_YOU_PASSWORD:
        // Ok. Here is your Thank You Mail Password
        xxx_info_box_80141B4(gUnknown_80DF418,0,&sUnknown_203B2C4->faceFile,0x10d);
        break;
    case 0x24:
        // I need to save your adventure
        xxx_info_box_80141B4(gUnknown_80DF44C,0,&sUnknown_203B2C4->faceFile,0x10d);
        break;
    case 0x20:
        // There we go. I'm all done.
        xxx_info_box_80141B4(gUnknown_80DF46C,0,&sUnknown_203B2C4->faceFile,0x10d);
        break;
    case THANK_YOU_PASSWORD_SUCCESS:
        switch(sUnknown_203B2C4->wonderMailMethod)
        {
            case WONDER_MAIL_GAME_LINK:
            case WONDER_MAIL_PASSWORD:
            case 6:
                // A Thank You Mail has arrived from your friend
                xxx_info_box_80141B4(gUnknown_80DF4F4,0,&sUnknown_203B2C4->faceFile,0x10d);
                break;
            case 4:
                break;
        }
        break;
    case 0x22:
        monName = GetMonSpecies(MONSTER_PELIPPER);
        strcpy(sUnknown_203B2C4->unk53C.clientName,monName); // 0x53C
        sUnknown_203B2C4->unk53C.clientSpecies = MONSTER_PELIPPER; // 0x550
        sUnknown_203B2C4->unk53C.unk16 = 2; // 0x552
        sUnknown_203B2C4->unk53C.moneyReward = 0; // 0x554
        mailIndex = GetMailIndex(6,sUnknown_203B2C4->unk430);
        mail = GetMailatIndex(mailIndex);
        itemIndex = mail->item.id;
        if (itemIndex != ITEM_NOTHING)
            sUnknown_203B2C4->unk53C.itemRewards[0] = itemIndex; // unk558
        else
            sUnknown_203B2C4->unk53C.itemRewards[0] = ITEM_NOTHING; // unk558
        sUnknown_203B2C4->unk53C.quantity = 1; // unk55B
        sUnknown_203B2C4->unk53C.teamRankPtsReward = GetDungeonTeamRankPts(&mail->unk4.dungeon, 0); // unk560
        sUnknown_203B2C4->unk53C.itemRewards[1] = 0; // unk559
        sUnknown_203B2C4->unk53C.itemRewards[2] = 0; // unk55A
        sUnknown_203B2C4->unk53C.friendAreaReward = 0; // unk55C
        sub_802F204(&sUnknown_203B2C4->unk53C,0); // unk53C
        break;
    case COMMUNICATING_THANK_YOU_MAIL:
        // Communicating..
        nullsub_23(FALSE);
        xxx_info_box_80141B4(gUnknown_80DF544,0,0,0);
        break;
    case 0x17:
        // There. I've sent your thank-you mail. I need to save your adventure.
        xxx_info_box_80141B4(gUnknown_80DF594,0,&sUnknown_203B2C4->faceFile,0x10d);
        break;
    case PROMPT_CONNECT_GAME_LINK:
        // Please connect the GBA systems with a Game Link Cable
        sub_8014248(gUnknown_80DF5E4,0,7,gUnknown_80DEE44,0,4,0,&sUnknown_203B2C4->faceFile,0xc);
        break;
    case THANK_YOU_MAIL_COMMS_CLEANUP:
        pokeStruct2 = GetPlayerPokemonStruct();
        sub_80922B4(buffer2, pokeStruct2->name, POKEMON_NAME_LENGTH);
        sprintfStatic(sUnknown_203B2C4->formattedString,gUnknown_80DF63C,buffer2);
        xxx_info_box_80141B4(sUnknown_203B2C4->formattedString,0,&sUnknown_203B2C4->faceFile,0x10d);
        break;
    case CONFIRM_ITEM_TO_SEND:
        // The item you've chosen can't be exchanged later. Is that OK?
        sub_8014248(gUnknown_80DF694,0,7,gUnknown_80DEEE4,0,4,0,&sUnknown_203B2C4->faceFile,0xc);
        break;
    case 0x29:
        // I need to save your adventure
        xxx_info_box_80141B4(gUnknown_80DF44C,0,&sUnknown_203B2C4->faceFile,0x10d);
        break;
    case 0x2a:
        // I've saved your adventure
        xxx_info_box_80141B4(gUnknown_80DF6F0,0,&sUnknown_203B2C4->faceFile,0x10d);
        break;
    case PROMPT_ITEM_TO_SEND:
        // Ok, please choose the item to be sent
        xxx_info_box_80141B4(gUnknown_80DF710,0,&sUnknown_203B2C4->faceFile,0x10d);
        break;
    case THANK_YOU_MAIL_STORAGE_EMPTY:
        // Oh? Your storage space is empty
        sub_8014248(gUnknown_80DF73C,0,0,gUnknown_80DEEBC,0,4,0,&sUnknown_203B2C4->faceFile,0xc);
        break;
    case PROMPT_REWARD_ITEM_TO_SEND:
        // Would you like to choose a reward item from storage and send it with your mail?
        sub_8014248(gUnknown_80DF77C,0,0,gUnknown_80DEE7C,0,4,0,&sUnknown_203B2C4->faceFile,0xc);
        break;
    case ITEM_EXISTS_ON_THANK_YOU_MAIL:
        // Oh? You've already attached a reward item on this mail.
        xxx_info_box_80141B4(gUnknown_80DF7D4,0,&sUnknown_203B2C4->faceFile,0x10d);
        break;
    case PROMPT_RESEND_WITH_ATTACHED_ITEM:
        // Would you like to send it again with the item you chose before?
        sub_8014248(gUnknown_80DF870,0,7,gUnknown_80DEE44,0,4,0,&sUnknown_203B2C4->faceFile,0xc);
        break;
    case NO_THANK_YOU_MAIL:
        // You don't seem to have a Thank-You Mail
        xxx_info_box_80141B4(gUnknown_80DF8B4,0,&sUnknown_203B2C4->faceFile,0x10d);
        break;
    case THANK_YOU_MAIL_MAIN_MENU:
        // Hello. I handle Thank You Mail. How may I help You?
        sub_8014248(gUnknown_80DF8EC,0,1,gThankYouMailMainMenuItems,0,4,0,&sUnknown_203B2C4->faceFile,0xc);
        break;
    case ANYTHING_ELSE_THANK_YOU_MAIN_MENU:
        // May I help you with anything else?
        sub_8014248(gUnknown_80DF928,0,1,gThankYouMailMainMenuItems,0,4,0,&sUnknown_203B2C4->faceFile,0xc);
        break;
    case EXIT_THANK_YOU_MAIL_PRE:
        // Please come see me anytime
        xxx_info_box_80141B4(gUnknown_80DF94C,0,&sUnknown_203B2C4->faceFile,0x10d);
        break;
    case SELECT_THANK_YOU_MAIL_COMMS:
        switch(sUnknown_203B2C4->wonderMailMode){
            case WONDER_MAIL_MODE_SEND:
                // How would you like to send your thank you mail?
                sub_8014248(gUnknown_80DF96C,0,3,gUnknown_80DEE08,0,4,0,&sUnknown_203B2C4->faceFile,0xc);
                break;
            case WONDER_MAIL_MODE_RECEIVE:
                // How would you like to recieve your friend's thank you mail?
                sub_8014248(gUnknown_80DF9A4,0,3,gUnknown_80DEE08,0,4,0,&sUnknown_203B2C4->faceFile,0xc);
                break;
        }
        break;
  }
}

void SetThankYouMailMenuState(u32 newState)
{
    sUnknown_203B2C4->state = newState;
    nullsub_131();
    UpdateThankYouMailText();
}
