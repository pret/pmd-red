#include "global.h"
#include "save.h"
#include "pokemon.h"
#include "file_system.h"
#include "item.h"
#include "sub_8095228.h"
#include "wonder_mail.h"
#include "memory.h"
#include "menu.h"
#include "input.h"
#include "rescue_password_menu.h"
#include "text.h"
#include "team_inventory.h"
#include "code_800D090.h"

extern struct WonderMailStruct_203B2C4 *gUnknown_203B2C4;

#define THANK_YOU_MAIL_MAIN_MENU 0
#define ANYTHING_ELSE_THANK_YOU_MAIN_MENU 1
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

const struct Item gUnknown_80DED44 =
{
    1, 0, 0
};

extern char gUnknown_202E5D8[0x50];
extern char gAvailablePokemonNames[0x50];


const struct UnkTextStruct2 gUnknown_80DED48 =
{
        0x00, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00,
        0x15, 0x00, 0x04, 0x00,
        0x06, 0x05,
        0x05, 0x00,
        NULL
};

const struct UnkTextStruct2 gUnknown_80DED60 =
{
        0x00, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00,
        0x16, 0x00, 0x07, 0x00,
        0x06, 0x05,
        0x05, 0x00,
        NULL
};

extern const u8 SendItem_Text[];
extern const u8 DontSendItem_Text[];

const struct MenuItem gUnknown_80DED78[3] =
{
    {"Confirm", 0xB},
    {"Info", 0xC},
    {NULL, 0x0},
};

// Unused
const struct UnkTextStruct2 gUnknown_80DEDA0 =
{
        0x00, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,
        0x00, 0x00,
        0x00, 0x00,
        NULL
};


const struct MenuItem gThankYouMailMainMenuItems[4] =
{
    {"Send Thank-You Mail", 0x1},
    {"Get Thank-You Mail", 0x2},
    {"Cancel", 0x0},
    {NULL, 0x0},
};

const struct MenuItem gUnknown_80DEE08[4] =
{
    {"Game Link cable", WONDER_MAIL_GAME_LINK},
    {"Password", WONDER_MAIL_PASSWORD},
    {"Cancel", 0x0},
    {NULL, 0x0},
};

const struct MenuItem gUnknown_80DEE44[3] =
{
    {"Yes", 0x7},
    {"Cancel", 0x0},
    {NULL, 0x0},
};

const struct MenuItem gUnknown_80DEE60[3] =
{
    {"Yes", 0x7},
    {"No", 0x8},
    {NULL, 0x0},
};

const struct MenuItem gUnknown_80DEE7C[4] =
{
    {SendItem_Text, 0x9},
    {DontSendItem_Text, 0xA},
    {"Cancel", 0x0},
    {NULL, 0x0},
};

ALIGNED(4) static const u8 DontSendItem_Text[] =  _("Don{APOSTROPHE}t Send Item");
ALIGNED(4) static const u8 SendItem_Text[] = "Send Item";

const struct MenuItem gUnknown_80DEEBC[3] =
{
    {"Send w/o Item", 0xA},
    {"Cancel", 0x0},
    {NULL, 0x0},
};

const struct MenuItem gUnknown_80DEEE4[4] =
{
    {"Yes", 0x7},
    {"No", 0x8},
    {"Cancel", 0x0},
    {NULL, 0x0},
};

#include "data/thank_you_wonder_mail.h"


extern s32 sub_80953D4(u32);
extern void sub_80141B4(const char *r0, u32, struct OpenedFile **r1, u32);
extern void sub_8014248(const char *r0, u32, u32, const struct MenuItem *r4, u32, u32, u32, struct OpenedFile **r5, u32);
extern u8 sub_8012FD8(u32 *r0);
extern void sub_8035CC0(struct UnkTextStruct2 *r0, u32);
extern void sub_8030810(u32);
extern u32 sub_8095324(u32);
extern u32 sub_8031DCC(void);
extern void sub_8031E00(void);
extern void sub_8095240(u8);
extern u32 sub_802F298();
extern u8 sub_801CF14(u32);
extern u32 sub_8030768(u32);
extern s8 sub_80307EC(void);
extern void sub_8030D40(u8, u32);
extern u32 sub_8030DA0();
extern void sub_8013114(u32 *r0, s32 *r1);
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
extern void sub_8030DE4();
extern void sub_801B450();
extern void sub_803084C();
extern void sub_801CBB8();
extern void sub_80155F0();
extern void sub_8031E10();
extern void sub_802F2C0();
extern u32 sub_80144A4(s32 *r0);
extern void SetThankYouMailMenuState(u32);
extern struct PokemonStruct *GetPlayerPokemonStruct(void);
extern void SetMenuItems(void *menu, struct UnkTextStruct2 *, u32, const struct UnkTextStruct2 *, const struct MenuItem *entries, u32, u32, u32);
extern void sub_80922B4(u8 *, u8 *, u32);
extern void sub_802F204(struct unkStruct_802F204 *, u32);
extern void sub_80151C0(u32, u8 *);
extern void xxx_call_start_bg_music(void);
extern void sub_803092C(void);
extern void sub_801CCD8(void);
extern void sub_8011830(void);
extern void nullsub_23(u32);
extern s32 sub_8037B28(u32);
extern u32 sub_8030894(void);
extern u32 sub_801D008(void);
extern void sub_80306A8(u32, u32, u32, u32);
extern s32 sub_8037D64(u32, void *, void *);
extern s32 sub_80381F4(u32, void *, void *);
extern void sub_801C8C4(u32, u32, s32 * , u32);
extern u8 sub_809539C(u32, u32);
extern u8 sub_800D588(void);
extern u32 GetDungeonTeamRankPts(struct DungeonLocation *, u32);
extern void sub_8031D70(u8, u32);

extern void sub_803092C(void);
extern void sub_8035CF4(u32 *, u32, u32);
extern u32 sub_801CA08(u32);
extern void sub_801CBB8(void);
extern void sub_801B3C0(struct Item *);
extern u8 sub_801CB24(void);
extern void sub_801B450(void);
extern u32 sub_801B410(void);
extern void sub_801CB5C(u32);
extern void sub_801CCD8(void);
extern void sub_8011C28(u32);
extern u32 sub_80154F0(void);
extern u32 sub_8039068(u32, u8 *r1, struct unkStruct_8095228 *r0);
extern u8 sub_809539C(u32, u32);


u32 CreateThankYouMailPelipper(void)
{
  char *monName;
  struct OpenedFile *faceFile;
  s32 uVar2;
  int counter;
  struct unkStruct_8095228 *temp;

  ResetUnusedInputStruct();
  sub_800641C(0,1,1);
  gUnknown_203B2C4 = MemoryAlloc(sizeof(struct WonderMailStruct_203B2C4), 8);
  MemoryFill8((u8 *)gUnknown_203B2C4, 0, sizeof(struct WonderMailStruct_203B2C4));

  CopyYellowMonsterNametoBuffer(gUnknown_202E5D8, MONSTER_PELIPPER);
  monName = GetMonSpecies(MONSTER_PELIPPER);
  strcpy(gAvailablePokemonNames, monName);
  faceFile = GetDialogueSpriteDataPtr(MONSTER_PELIPPER);

  gUnknown_203B2C4->faceFile = faceFile;
  gUnknown_203B2C4->faceData = faceFile->data;
  gUnknown_203B2C4->unk42C = 0;
  gUnknown_203B2C4->unk42D = 0;
  gUnknown_203B2C4->unk42E = 0;
  gUnknown_203B2C4->unk428 = 2;
  gUnknown_203B2C4->unk42A = 8;

  for(counter = 0; counter < PASSWORD_BUFFER_SIZE; counter++){
    gUnknown_203B2C4->passwordBuffer[counter] = 0;
  }

  gUnknown_203B2C4->wonderMailMethod = WONDER_MAIL_GAME_LINK;
  gUnknown_203B2C4->wonderMailMode = WONDER_MAIL_MODE_SEND;

  uVar2 = sub_80953D4(6);
  if (uVar2 != -1) {
    temp = sub_8095228(uVar2);
    gUnknown_203B2C4->unk41C = temp->unk20;
    gUnknown_203B2C4->unk218 = uVar2;
    gUnknown_203B2C4->unk430 = temp->unk10;
    SetThankYouMailMenuState(5);
  }
  else {
    gUnknown_203B2C4->unk41C = gUnknown_80DED44;
    gUnknown_203B2C4->unk218 = -1;
    SetThankYouMailMenuState(THANK_YOU_MAIL_MAIN_MENU);
  }
  gUnknown_203B2C4->fallbackState = 0x2b;
  return 1;
}

u32 ThankYouMailPelipperCallback(void)
{

  switch(gUnknown_203B2C4->state) {
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
    case 2:
        sub_802AAC8();
        break;
    case EXIT_THANK_YOU_MAIL:
        return 3;
  }
  return 0;
}

void CleanThankYouMailPelipper(void)
{
    if(gUnknown_203B2C4 != NULL)
    {
        CloseFile(gUnknown_203B2C4->faceFile);
        MemoryFree(gUnknown_203B2C4);
        gUnknown_203B2C4 = NULL;
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
    case WONDER_MAIL_INCORRECT_NUM_SYSTEMS:
        sub_80141B4(gUnknown_80DEF28, 0, &gUnknown_203B2C4->faceFile, 0x10d);
        break;
    case WONDER_MAIL_DIFFERENT_MODES:
        sub_80141B4(gUnknown_80DEF80, 0, &gUnknown_203B2C4->faceFile, 0x10d);
        break;
    case WONDER_MAIL_NO_ROOM_STORAGE:
        sub_80141B4(gUnknown_80DEFDC, 0, &gUnknown_203B2C4->faceFile, 0x10d);
        break;
    case WONDER_MAIL_DUPLICATE_MAIL:
        sub_80141B4(gUnknown_80DF044, 0, &gUnknown_203B2C4->faceFile, 0x10d);
        break;
    case WONDER_MAIL_NOT_ELIGIBLE_1:
        sub_80141B4(gUnknown_80DF0A0, 0, &gUnknown_203B2C4->faceFile, 0x10d);
        break;
    case WONDER_MAIL_NOT_ELIGIBLE_2:
        sub_80141B4(gUnknown_80DF0A0, 0, &gUnknown_203B2C4->faceFile, 0x10d);
        break;
    case WONDER_MAIL_NO_ROOM_MAIL:
        sub_80141B4(gUnknown_80DF0E0, 0, &gUnknown_203B2C4->faceFile, 0x10d);
        break;
    case 1:
    case WONDER_MAIL_NO_RESPONSE:
    case 5:
    case 14:
        sub_80141B4(gUnknown_80DEF04, 0, &gUnknown_203B2C4->faceFile, 0x10d);
        break;
    case WONDER_MAIL_NOT_READY:
        sub_80141B4(gUnknown_80DF138, 0, &gUnknown_203B2C4->faceFile, 0x10d);
        break;
    case WONDER_MAIL_GOOD:
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
  MemoryFill8((u8 *)&gUnknown_203B2C4->unk41C, 0, sizeof(struct Item));
  gUnknown_203B2C4->unk41C.id = 0;
  gUnknown_203B2C4->unk41C.quantity = 1;
  gUnknown_203B2C4->unk41C.flags = 0;
  if (gUnknown_203B2C4->linkError == 0) {
      switch(gUnknown_203B2C4->unk40)
        {
            case 6:
                switch(gUnknown_203B2C4->wonderMailMethod)
                {
                    case WONDER_MAIL_GAME_LINK:
                    case WONDER_MAIL_PASSWORD:
                    case 6:
                        // "Thank-You Mail has been sent"
                        sub_80141B4(gUnknown_80DF194, 0, &gUnknown_203B2C4->faceFile, 0x10d);
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
      PrintThankYouMailLinkError(gUnknown_203B2C4->linkError);
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
            sub_800641C(gUnknown_203B2C4->unk3BC, 1, 1);
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
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        switch(temp)
        {
            case 7:
                SetThankYouMailMenuState(SELECT_THANK_YOU_MAIL_COMMS);
                break;
            case 8:
            case 0:
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
        gUnknown_203B2C4->unk218 = sub_80307EC();
        SetThankYouMailMenuState(0x11);
        break;
    case 4:
        gUnknown_203B2C4->fallbackState = 0x10;
        gUnknown_203B2C4->unk218 = sub_80307EC();
        sub_8006518(gUnknown_203B2C4->unk3BC);
        ResetUnusedInputStruct();
        sub_800641C(0,1,1);
        sub_8030D40(gUnknown_203B2C4->unk218,0);
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
  if (sub_8012FD8(&gUnknown_203B2C4->unk30C) == 0) {
    sub_8013114(&gUnknown_203B2C4->unk30C, &menuAction);
  }

  switch(menuAction)
  {
      case 0xB:
        sub_803084C();
        SetThankYouMailMenuState(0xe);
        break;
      case 0xC:
        gUnknown_203B2C4->fallbackState = 0x2b;
        sub_8006518(gUnknown_203B2C4->unk3BC);
        ResetUnusedInputStruct();
        sub_800641C(0,1,1);
        sub_8030D40(gUnknown_203B2C4->unk218,0);
        SetThankYouMailMenuState(0x12);
        break;
      case 0:
      case 0xD:
        sub_8035CC0(gUnknown_203B2C4->unk35C,2);
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
        sub_800641C(gUnknown_203B2C4->unk3BC, 1, 1);
        sub_803092C();
        if (gUnknown_203B2C4->fallbackState == 0x2b) {
            sub_8035CF4(&gUnknown_203B2C4->unk21C, 3, 1);
            SetThankYouMailMenuState(0x11);
        }
        else {
            SetThankYouMailMenuState(gUnknown_203B2C4->fallbackState);
        }
        break;
    default:
        break;
  }
}

void sub_802A28C(void)
{

  gUnknown_203B2C4->unk41C.id = 0;
  gUnknown_203B2C4->unk41C.quantity = 1;
  gUnknown_203B2C4->unk41C.flags = 0;

  switch(sub_801CA08(1))
  {
    case 2:
        sub_801CBB8();
        SetThankYouMailMenuState(ANYTHING_ELSE_THANK_YOU_MAIN_MENU);
        break;
    case 3:
        gUnknown_203B2C4->unk41C.id = sub_801CB24();
        SetThankYouMailMenuState(0x14);
        break;
    case 4:
        gUnknown_203B2C4->fallbackState = 0x13;
        gUnknown_203B2C4->unk41C.id = sub_801CB24();
        sub_8006518(gUnknown_203B2C4->unk3BC);
        ResetUnusedInputStruct();
        sub_800641C(0,1,1);
        sub_801B3C0(&gUnknown_203B2C4->unk41C);
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
        sub_800641C(gUnknown_203B2C4->unk3BC,1,1);
        sub_801CB5C(1);
        if (gUnknown_203B2C4->fallbackState == 0x2b) {
            sub_8035CF4(&gUnknown_203B2C4->unk21C,3,1);
            SetThankYouMailMenuState(0x14);
        }
        else {
            SetThankYouMailMenuState(gUnknown_203B2C4->fallbackState);
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
  sub_801CA08(0);
  if (sub_8012FD8(&gUnknown_203B2C4->unk30C) == 0) {
    sub_8013114(&gUnknown_203B2C4->unk30C, &menuAction);
  }

  switch(menuAction)
  {
      case 0xB:
            sub_801CBB8();
            SetThankYouMailMenuState(CONFIRM_ITEM_TO_SEND);
            break;
      case 0xC:
            gUnknown_203B2C4->fallbackState = 0x2b;
            sub_8006518(gUnknown_203B2C4->unk3BC);
            ResetUnusedInputStruct();
            sub_800641C(0,1,1);
            sub_801B3C0(&gUnknown_203B2C4->unk41C);
            SetThankYouMailMenuState(SHOW_ITEM_TO_SEND_INFO);
            break;
      case 0:
      case 0xD:
            sub_8035CC0(gUnknown_203B2C4->unk35C, 3);
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
  u8 uVar1;
  struct unkStruct_8095228 *puVar5;
  u32 return_var;
  struct unkStruct_8095228 temp;

  return_var = sub_80154F0();
  MemoryFill8((u8 *)&temp, 0, sizeof(struct unkStruct_8095228));
  switch(return_var)
  {
    case 3:
        switch(sub_8039068(PASSWORD_ENTRY_THANK_YOU_MAIL_MODE,gUnknown_203B2C4->passwordBuffer,&temp))
        {
            case PASSWORD_ENTRY_INCORRECT_PASSWORD:
                sub_8014248(gUnknown_80DF1C0, 0, 7, gUnknown_80DEE44, 0, 4, 0, &gUnknown_203B2C4->faceFile, 0xc);
                SetThankYouMailMenuState(THANK_YOU_PASSWORD_WRONG);
                break;
            case PASSWORD_ENTRY_NOT_THANK_YOU_MAIL:
                sub_80141B4(gUnknown_80DF208, 0, &gUnknown_203B2C4->faceFile, 0x10d);
                SetThankYouMailMenuState(PRINT_THANK_YOU_ERROR);
                break;
            case PASSWORD_ENTRY_DUPLICATE_THANK_YOU_MAIL:
                sub_80141B4(gUnknown_80DF0A0, 0, &gUnknown_203B2C4->faceFile, 0x10d);
                SetThankYouMailMenuState(PRINT_THANK_YOU_ERROR);
                break;
            case PASSWORD_ENTRY_THANK_YOU_MAIL_SUCCESS:
                uVar1 = sub_809539C(4,temp.unk10);
                puVar5 = sub_8095228(uVar1);
                *puVar5 = temp;
                puVar5->mailType = 6;
                gUnknown_203B2C4->unk430 = temp.unk10;
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
    sub_800641C(gUnknown_203B2C4->unk3BC, 1, 1);
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
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        switch(temp)
        {
            case 7:
                // NOTE: if statement is needed to match
                if(gUnknown_203B2C4->wonderMailMode)
                    SetThankYouMailMenuState(COMMUNICATING_THANK_YOU_MAIL);
                else
                    SetThankYouMailMenuState(COMMUNICATING_THANK_YOU_MAIL);
                break;
            case 0:
                SetThankYouMailMenuState(ANYTHING_ELSE_THANK_YOU_MAIN_MENU);
                break;
        }
    }
}

void HandleConfirmItemtoSendMenu(void)
{
    s32 temp;
    struct unkStruct_8095228 *return_var;
    if(sub_80144A4(&temp) == 0)
    {
        switch(temp)
        {
            case 7:
                return_var = sub_8095228(gUnknown_203B2C4->unk218);
                if(gUnknown_203B2C4->unk41C.id != 0)
                {
                    return_var->unk20 = gUnknown_203B2C4->unk41C;
                }
                gTeamInventory_203B460->teamStorage[gUnknown_203B2C4->unk41C.id]--;
                SetThankYouMailMenuState(0x29);
                break;
            case 8:
                SetThankYouMailMenuState(PROMPT_ITEM_TO_SEND);
                break;
            case 0:
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
            switch(gUnknown_203B2C4->wonderMailMethod)
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
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        switch(temp)
        {
            case 0xA:
                switch(gUnknown_203B2C4->wonderMailMethod)
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
            case 0:
                SetThankYouMailMenuState(ANYTHING_ELSE_THANK_YOU_MAIN_MENU);
                break;
        }
    }
}

void sub_802A910(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        switch(temp)
        {
            case 9:
                if(sub_801CF14(0) != 0)
                {
                    SetThankYouMailMenuState(THANK_YOU_MAIL_STORAGE_EMPTY);
                }
                else
                {
                    SetThankYouMailMenuState(PROMPT_ITEM_TO_SEND);
                }
                break;
            case 0xA:
                switch(gUnknown_203B2C4->wonderMailMethod)
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
            case 0:
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
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        switch(temp)
        {
            case 0x7:
                switch(gUnknown_203B2C4->wonderMailMethod)
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
            case 0:
                SetThankYouMailMenuState(ANYTHING_ELSE_THANK_YOU_MAIN_MENU);
                break;
        }
    }
}

void sub_802A9FC(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        switch(temp)
        {
            case 0x7:
                SetThankYouMailMenuState(PROMPT_THANK_YOU_PASSWORD);
                break;
            case 0:
                SetThankYouMailMenuState(ANYTHING_ELSE_THANK_YOU_MAIN_MENU);
                break;
        }
    }
}

void HandleMailCommunicationMenu(void)
{
    s32 temp;
    struct unkStruct_8095228 *return_var;
    if(sub_80144A4(&temp) == 0)
    {
        switch(temp)
        {
            case WONDER_MAIL_GAME_LINK:
            case 4:
            case WONDER_MAIL_PASSWORD:
                gUnknown_203B2C4->wonderMailMethod = temp;
                switch(gUnknown_203B2C4->wonderMailMode)
                {
                    case WONDER_MAIL_MODE_SEND:
                        return_var = sub_8095228(sub_80953D4(5));
                        if(return_var->unk20.id != 0)
                        {
                            SetThankYouMailMenuState(ITEM_EXISTS_ON_THANK_YOU_MAIL);
                        }
                        else
                        {
                            SetThankYouMailMenuState(PROMPT_REWARD_ITEM_TO_SEND);
                        }
                        break;
                    default:
                        if(gUnknown_203B2C4->wonderMailMethod == WONDER_MAIL_PASSWORD)
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
            case 0:
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
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        switch(temp)
        {
            case 1:
                gUnknown_203B2C4->unk40 = 6;
                gUnknown_203B2C4->wonderMailMode = WONDER_MAIL_MODE_SEND;
                if(sub_8095324(5) == 0)
                {
                    SetThankYouMailMenuState(NO_THANK_YOU_MAIL);
                }
                else
                {
                    SetThankYouMailMenuState(PROMPT_THANK_YOU_TO_SEND);
                }
                break;
            case 2:
                gUnknown_203B2C4->unk40 = 7;
                gUnknown_203B2C4->wonderMailMode = WONDER_MAIL_MODE_RECEIVE;
                SetThankYouMailMenuState(SELECT_THANK_YOU_MAIL_COMMS);
                break;
            case 0:
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
            sub_8095240(sub_809539C(6, gUnknown_203B2C4->unk430));
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
  char cVar1;
  char *monName;
  u8 auStack180 [80];
  u8 auStack100 [80];
  u8 uVar2;
  struct PokemonStruct *pokeStruct;
  struct PokemonStruct *pokeStruct2;
  s32 linkStatus;
  struct unkStruct_8095228 *puVar4;

  switch(gUnknown_203B2C4->state) {
    case 5:
        pokeStruct = GetPlayerPokemonStruct();
        sub_80922B4(auStack180,pokeStruct->name, POKEMON_NAME_LENGTH);
        sprintfStatic(gUnknown_203B2C4->formattedString,gUnknown_80DF250,auStack180);
        sub_80141B4(gUnknown_203B2C4->formattedString,0,&gUnknown_203B2C4->faceFile,0x10d);
        break;
    case 0xe:
        // Is it OK to send this Thank-You Mail?
        sub_8014248(gUnknown_80DF304,0,7,gUnknown_80DEE60,0,4,0,&gUnknown_203B2C4->faceFile,0xc);
        break;
    case PROMPT_THANK_YOU_TO_SEND:
        // Please choose the Thank-You Mail that you want to send to your friend
        sub_80141B4(gUnknown_80DF330,0,&gUnknown_203B2C4->faceFile,0x10d);
        break;
    case 0x10:
        if (sub_8030894() != 0)
            break;
        ResetUnusedInputStruct();
        sub_800641C(0,1,1);
        sub_80306A8(5,0,0,6);
        break;
    case 0x11:
        sub_8006518(gUnknown_203B2C4->unk35C);
        SetMenuItems(&gUnknown_203B2C4->unk21C,gUnknown_203B2C4->unk35C,3,&gUnknown_80DED60,gUnknown_80DED78,1,0,0);
        sub_803092C();
        sub_8035CF4(&gUnknown_203B2C4->unk21C,3,1);
        break;
    case 0x13:
        if (sub_801D008() != 0)
            break;
        ResetUnusedInputStruct();
        sub_800641C(0,1,1);
        // TODO: Probably a macro - Pika
        {
        struct {u16 a; u16 b;} local_x = {3, 2};
        sub_801C8C4(0, 1, (s32 *)&local_x, 9);
        }
        break;
    case 0x14:
        sub_8006518(gUnknown_203B2C4->unk35C);
        SetMenuItems(&gUnknown_203B2C4->unk21C,gUnknown_203B2C4->unk35C,3,&gUnknown_80DED48,gUnknown_80DED78,1,0,0);
        sub_801CCD8();
        sub_8035CF4(&gUnknown_203B2C4->unk21C,3,1);
        break;
    case THANK_YOU_MAIL_COMMS_FINISHED:
        gUnknown_203B2C4->linkError = 0;
        sub_8011830();
        linkStatus = sub_8037B28(gUnknown_203B2C4->unk40);
        gUnknown_203B2C4->linkError = linkStatus;
        if (linkStatus == 0)
        {
            switch(gUnknown_203B2C4->unk40)
            {
                case 6:
                    MemoryFill8((u8 *)&gUnknown_203B2C4->unk1B8,0, sizeof(struct unkStruct_8095228));
                    gUnknown_203B2C4->unk1B8 = *sub_8095228(gUnknown_203B2C4->unk218);
                    gUnknown_203B2C4->linkError = sub_8037D64(gUnknown_203B2C4->unk40,&gUnknown_203B2C4->unk1B8,&gUnknown_203B2C4->unk1E8);
                    break;
                case 7:
                    MemoryFill8((u8 *)&gUnknown_203B2C4->unk1B8,0, sizeof(struct unkStruct_8095228));
                    MemoryFill8((u8 *)&gUnknown_203B2C4->unk1E8,0, sizeof(struct unkStruct_8095228));
                    gUnknown_203B2C4->linkError = sub_8037D64(gUnknown_203B2C4->unk40,&gUnknown_203B2C4->unk1B8,&gUnknown_203B2C4->unk1E8);
                    break;
            }
            if (gUnknown_203B2C4->linkError == 0){
                switch(gUnknown_203B2C4->unk40){
                    case 6:
                    case 7:
                        gUnknown_203B2C4->linkError = sub_80381F4(gUnknown_203B2C4->unk40,&gUnknown_203B2C4->unk1B8,&gUnknown_203B2C4->unk1E8);
                        if ( sub_800D588() != '\0') {
                            gUnknown_203B2C4->unk430 = gUnknown_203B2C4->unk1E8.unk10;
                        }
                        else {
                            gUnknown_203B2C4->unk430 = gUnknown_203B2C4->unk1B8.unk10;
                        }
                    break;
                }
            }
        }
        xxx_call_start_bg_music();
        break;
    case PROMPT_THANK_YOU_PASSWORD:
        // OK. Please enter the Thank-You Mail Password
        sub_80141B4(gUnknown_80DF380,0,&gUnknown_203B2C4->faceFile,0x10d);
        break;
    case PROCESS_THANK_YOU_PASSWORD:
        sub_8006518(gUnknown_203B2C4->unk3BC);
        ResetUnusedInputStruct();
        sub_800641C(0,1,1);
        sub_80151C0(4,gUnknown_203B2C4->passwordBuffer);
        break;
    case 0x1a:
        sub_8006518(gUnknown_203B2C4->unk3BC);
        ResetUnusedInputStruct();
        sub_800641C(0,1,1);
        sub_8031D70(gUnknown_203B2C4->unk218,0);
        break;
    case 0x1b:
        // Please give this password to the friend that rescued your team. I also must save your adventure
        sub_80141B4(gUnknown_80DF3B4,0,&gUnknown_203B2C4->faceFile,0x10d);
        break;
    case DISPLAY_THANK_YOU_PASSWORD:
        // Ok. Here is your Thank You Mail Password
        sub_80141B4(gUnknown_80DF418,0,&gUnknown_203B2C4->faceFile,0x10d);
        break;
    case 0x24:
        // I need to save your adventure
        sub_80141B4(gUnknown_80DF44C,0,&gUnknown_203B2C4->faceFile,0x10d);
        break;
    case 0x20:
        // There we go. I'm all done.
        sub_80141B4(gUnknown_80DF46C,0,&gUnknown_203B2C4->faceFile,0x10d);
        break;
    case THANK_YOU_PASSWORD_SUCCESS:
        switch(gUnknown_203B2C4->wonderMailMethod)
        {
            case WONDER_MAIL_GAME_LINK:
            case WONDER_MAIL_PASSWORD:
            case 6:
                // A Thank You Mail has arrived from your friend
                sub_80141B4(gUnknown_80DF4F4,0,&gUnknown_203B2C4->faceFile,0x10d);
                break;
            case 4:
                break;
        }
        break;
    case 0x22:
        monName = GetMonSpecies(MONSTER_PELIPPER);
        strcpy(gUnknown_203B2C4->unk53C.clientName,monName); // 0x53C
        gUnknown_203B2C4->unk53C.unk14 = MONSTER_PELIPPER; // 0x550
        gUnknown_203B2C4->unk53C.unk16 = 2; // 0x552
        gUnknown_203B2C4->unk53C.moneyReward = 0; // 0x554
        uVar2 = sub_809539C(6,gUnknown_203B2C4->unk430);
        puVar4 = sub_8095228(uVar2);
        cVar1 = puVar4->unk20.id;
        if (cVar1 != '\0')
            gUnknown_203B2C4->unk53C.itemRewards[0] = cVar1; // unk558
        else
            gUnknown_203B2C4->unk53C.itemRewards[0] = 0; // unk558
        gUnknown_203B2C4->unk53C.quantity = 1; // unk55B
        gUnknown_203B2C4->unk53C.teamRankPtsReward = GetDungeonTeamRankPts(&puVar4->dungeon, 0); // unk560
        gUnknown_203B2C4->unk53C.itemRewards[1] = 0; // unk559
        gUnknown_203B2C4->unk53C.itemRewards[2] = 0; // unk55A
        gUnknown_203B2C4->unk53C.friendAreaReward = 0; // unk55C
        sub_802F204(&gUnknown_203B2C4->unk53C,0); // unk53C
        break;
    case COMMUNICATING_THANK_YOU_MAIL:
        // Communicating..
        nullsub_23(0);
        sub_80141B4(gUnknown_80DF544,0,0,0);
        break;
    case 0x17:
        // There. I've sent your thank-you mail. I need to save your adventure.
        sub_80141B4(gUnknown_80DF594,0,&gUnknown_203B2C4->faceFile,0x10d);
        break;
    case PROMPT_CONNECT_GAME_LINK:
        // Please connect the GBA systems with a Game Link Cable
        sub_8014248(gUnknown_80DF5E4,0,7,gUnknown_80DEE44,0,4,0,&gUnknown_203B2C4->faceFile,0xc);
        break;
    case THANK_YOU_MAIL_COMMS_CLEANUP:
        pokeStruct2 = GetPlayerPokemonStruct();
        sub_80922B4(auStack100, pokeStruct2->name, POKEMON_NAME_LENGTH);
        sprintfStatic(gUnknown_203B2C4->formattedString,gUnknown_80DF63C,auStack100);
        sub_80141B4(gUnknown_203B2C4->formattedString,0,&gUnknown_203B2C4->faceFile,0x10d);
        break;
    case CONFIRM_ITEM_TO_SEND:
        // The item you've chosen can't be exchanged later. Is that OK?
        sub_8014248(gUnknown_80DF694,0,7,gUnknown_80DEEE4,0,4,0,&gUnknown_203B2C4->faceFile,0xc);
        break;
    case 0x29:
        // I need to save your adventure
        sub_80141B4(gUnknown_80DF44C,0,&gUnknown_203B2C4->faceFile,0x10d);
        break;
    case 0x2a:
        // I've saved your adventure
        sub_80141B4(gUnknown_80DF6F0,0,&gUnknown_203B2C4->faceFile,0x10d);
        break;
    case PROMPT_ITEM_TO_SEND:
        // Ok, please choose the item to be sent
        sub_80141B4(gUnknown_80DF710,0,&gUnknown_203B2C4->faceFile,0x10d);
        break;
    case THANK_YOU_MAIL_STORAGE_EMPTY:
        // Oh? Your storage space is empty
        sub_8014248(gUnknown_80DF73C,0,0,gUnknown_80DEEBC,0,4,0,&gUnknown_203B2C4->faceFile,0xc);
        break;
    case PROMPT_REWARD_ITEM_TO_SEND:
        // Would you like to choose a reward item from storage and send it with your mail?
        sub_8014248(gUnknown_80DF77C,0,0,gUnknown_80DEE7C,0,4,0,&gUnknown_203B2C4->faceFile,0xc);
        break;
    case ITEM_EXISTS_ON_THANK_YOU_MAIL:
        // Oh? You've already attached a reward item on this mail.
        sub_80141B4(gUnknown_80DF7D4,0,&gUnknown_203B2C4->faceFile,0x10d);
        break;
    case PROMPT_RESEND_WITH_ATTACHED_ITEM:
        // Would you like to send it again with the item you chose before?
        sub_8014248(gUnknown_80DF870,0,7,gUnknown_80DEE44,0,4,0,&gUnknown_203B2C4->faceFile,0xc);
        break;
    case NO_THANK_YOU_MAIL:
        // You don't seem to have a Thank-You Mail
        sub_80141B4(gUnknown_80DF8B4,0,&gUnknown_203B2C4->faceFile,0x10d);
        break;
    case THANK_YOU_MAIL_MAIN_MENU:
        // Hello. I handle Thank You Mail. How may I help You?
        sub_8014248(gUnknown_80DF8EC,0,1,gThankYouMailMainMenuItems,0,4,0,&gUnknown_203B2C4->faceFile,0xc);
        break;
    case ANYTHING_ELSE_THANK_YOU_MAIN_MENU:
        // May I help you with anything else?
        sub_8014248(gUnknown_80DF928,0,1,gThankYouMailMainMenuItems,0,4,0,&gUnknown_203B2C4->faceFile,0xc);
        break;
    case 2:
        // Please come see me anytime
        sub_80141B4(gUnknown_80DF94C,0,&gUnknown_203B2C4->faceFile,0x10d);
        break;
    case SELECT_THANK_YOU_MAIL_COMMS:
        switch(gUnknown_203B2C4->wonderMailMode){
            case WONDER_MAIL_MODE_SEND:
                // How would you like to send your thank you mail?
                sub_8014248(gUnknown_80DF96C,0,3,gUnknown_80DEE08,0,4,0,&gUnknown_203B2C4->faceFile,0xc);
                break;
            case WONDER_MAIL_MODE_RECEIVE:
                // How would you like to recieve your friend's thank you mail?
                sub_8014248(gUnknown_80DF9A4,0,3,gUnknown_80DEE08,0,4,0,&gUnknown_203B2C4->faceFile,0xc);
                break;
        }
        break;
  }
}

void SetThankYouMailMenuState(u32 newState)
{
    gUnknown_203B2C4->state = newState;
    nullsub_131();
    UpdateThankYouMailText();
}
