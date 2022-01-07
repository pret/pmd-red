#include "global.h"
#include "save.h"
#include "memory.h"
#include "text.h"
#include "input.h"
#include "sub_8095228.h"
#include "wonder_mail.h"
#include "menu.h"

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

#include "data/menus/wonder_mail_main_menu.h"
#include "data/wonder_mail_main_menu.h"

const struct MenuItem WonderMailMainUnused[3] =
{
    {Yes_80E7D2C, 1},
    {Cancel_80E7D24, 0},
    {NULL, 0},
};

ALIGNED(4) const char Cancel_80E7D24[] = "Cancel";
ALIGNED(4) const char Yes_80E7D2C[] = "Yes";

ALIGNED(4) const char wonder_mail_main_fill1[] = "pksdir0";
ALIGNED(4) const char wonder_mail_main_fill2[] = "pksdir0";


struct unkStruct_803B344
{
    // size: 0xB4
    struct WonderMail unk0;
    u8* unk14;
    u8* unk18;
    u8 fill1C[0x3C - 0x1C];
    u8 unk3C[0x78];
};

struct unkStruct_203B3E8
{
    // size: 0x49C
    u8 state; // state variable?
    u8 PasswordEntryBuffer[PASSWORD_BUFFER_SIZE]; // Wonder Mail Buffer...
    union UNK38
    {
        struct WonderMail decodedMail; // 0x14
        u8 unk38_u8[0x30]; // idk why it fills to 0x30 instead...
    } UNK38;
    u8 fill68[0x1EC - 0x68];
    struct UnkTextStruct2 unk1EC[4];
    u32 unk24C;
    u32 wonderMailStatus;

    struct unkStruct_803B344 unk254;

    struct unkStruct_803B344 unk308;
    u8 unk3BC;
    u8 fill3BD[0x3C0 - 0x3BD];

    struct unkStruct_803B344 unk3C0;

    struct WonderMail unk474;
    u8 **unk488;
    u8 *unk48C;
    s32 wonderMailMethod;
    u32 wonderMailMode;
    u8 unk498;
};

EWRAM_DATA struct unkStruct_203B3E8 *gUnknown_203B3E8;

extern u32 sub_8095324(u32);
extern u32 sub_80144A4(s32 *);
extern u32 sub_8011C1C(void);
extern void SetWonderMailMainMenuState(u8);
extern void sub_8030DE4(void);
extern void sub_801B450(void);
extern void sub_803084C(void);
extern void sub_801CBB8(void);
extern void sub_80155F0(void);
extern void sub_8031E10(void);

extern u8 sub_800D588(void);
extern s32 sub_8037D64(u32, void *, void *);
extern s32 sub_80381F4(u32, void *, void *);
extern void sub_8011830(void);
extern void sub_80151C0(u32, u8 *);
extern void xxx_call_start_bg_music(void);
extern void sub_8014248(const char *, u32, u32, const struct MenuItem *, u32, u32, u32, u32, u32);
extern void nullsub_23(u32);
extern void sub_802EF48(void);
extern void sub_802D098(struct WonderMail *);


extern struct unkStruct_803B344 *sub_803B344(u8);



extern s32 sub_8037B28(u32);

extern u32 sub_802D0E0();
extern u8 sub_802D178();
extern void sub_802D184();

extern s32 sub_80154F0();
extern bool8 DecodeWonderMailPassword(u8 *, struct WonderMail *);
extern bool8 IsValidWonderMail(struct WonderMail *WonderMailData);
extern void sub_80141B4(const char *r0, u32, u32 *r1, u32);

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


bool8 sub_8039880(void)
{
  return (sub_8095324(1) != 0 || sub_8095324(7) != 0 || sub_8011C1C() == 2);
}

bool8 CreateWonderMailMenu(void)
{
  int iVar2;

  ResetUnusedInputStruct();
  sub_800641C(0,1,1);

  gUnknown_203B3E8 = MemoryAlloc(sizeof(struct unkStruct_203B3E8), 8);
  MemoryFill8((u8 *)gUnknown_203B3E8, 0, sizeof(struct unkStruct_203B3E8));

  for(iVar2 = 0; iVar2 < PASSWORD_BUFFER_SIZE; iVar2++){
    gUnknown_203B3E8->PasswordEntryBuffer[iVar2] = 0;
  }

  gUnknown_203B3E8->wonderMailMethod = WONDER_MAIL_GAME_LINK;
  gUnknown_203B3E8->wonderMailMode = WONDER_MAIL_MODE_RECEIVE;
  gUnknown_203B3E8->unk498 = 1;
  gUnknown_203B3E8->wonderMailMethod = WONDER_MAIL_PASSWORD; // ??? Why?
  SetWonderMailMainMenuState(PROMPT_PASSWORD_ENTRY); // -> Display "Enter Wonder Mail Password"
  return 1;
}

u8 UpdateWonderMailMenu(void)
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
        case 3:
        case 4:
            gUnknown_203B3E8->wonderMailMethod = WONDER_MAIL_GAME_LINK;
            SetWonderMailMainMenuState(GAME_LINK_CABLE_MENU);
            break;
        case 5:
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
    if (gUnknown_203B3E8->wonderMailStatus == 0) {
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
        case 0:
            break;
        case 1:
            // "Communication Error"
            sub_80141B4(gUnknown_80E7914, 0, 0, 0x101);
            break;
        case 3:
            // Incorrect number of GBA Systems
            sub_80141B4(gUnknown_80E7938, 0, 0, 0x101);
            break;
        case 2:
            // No response from friend. Redo from start
            sub_80141B4(gUnknown_80E7994, 0, 0, 0x101);
            break;
        case 4:
            // Sender and receiver in different modes
            sub_80141B4(gUnknown_80E79E4, 0, 0, 0x101);
            break;
        case 5:
            // "Communication Error"
            sub_80141B4(gUnknown_80E7914, 0, 0, 0x101);
            break;
        case 14:
            // "Communication Error"
            sub_80141B4(gUnknown_80E7914, 0, 0, 0x101);
            break;
        case 15: // "No response from your friend. Make sure sender and receiver are ready"
            sub_80141B4(gUnknown_80E7A48, 0, 0, 0x101);
            break;
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        default:
            // "Communication Error"
            sub_80141B4(gUnknown_80E7914, 0, 0, 0x101);
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
      sub_800641C(gUnknown_203B3E8->unk1EC,1,1);
      if ( !DecodeWonderMailPassword(gUnknown_203B3E8->PasswordEntryBuffer, &gUnknown_203B3E8->UNK38.decodedMail) || !IsValidWonderMail(&gUnknown_203B3E8->UNK38.decodedMail) )
      {
        // Invalid password
        SetWonderMailMainMenuState(PASSWORD_INVALID);
      }
      else {
        // Successful password
        // Copy the decoded data to another buffer?
        gUnknown_203B3E8->unk3C0.unk0 = gUnknown_203B3E8->UNK38.decodedMail;

        gUnknown_203B3E8->unk498 = 1;
        SetWonderMailMainMenuState(PASSWORD_SUCCESS);
      }
      break;
    case 2:
        sub_80155F0();
        ResetUnusedInputStruct();
        sub_800641C(gUnknown_203B3E8->unk1EC,1,1);
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
    gUnknown_203B3E8->unk498 = sub_802D178();
    sub_802D184();
    if (gUnknown_203B3E8->unk498 != 0) {
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
      PrepareSavePakWrite(SPECIES_NONE); // "Saving Adventure.."
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
  int iVar2;
  struct unkStruct_803B344 *temp;

  switch(gUnknown_203B3E8->state) {
    case SELECT_WONDER_MAIL_MODE_MAIN_SCREEN:
        sub_8014248(gUnknown_80E7AC4,0,1,gSelectWonderMailModeMainMenuItems,0,4,0,0,0x101);
        break;
    case SEND_WONDER_MAIL_MAIN_SCREEN:
        sub_8014248(gUnknown_80E7AE0,0,3,gSendWonderMailMainMenuItems,0,4,0,0,0x101);
        break;
    case 3:
        ResetUnusedInputStruct();
        sub_800641C(0,1,1);
        sub_802EF48();
        break;
    case RECEIVE_WONDER_MAIL_MAIN_SCREEN:
        sub_8014248(gUnknown_80E7B14,0,3,gReceiveWonderMailMainMenuItems,0,4,0,0,0x101);
        break;
    case PASSWORD_SUCCESS:
        gUnknown_203B3E8->unk474 = gUnknown_203B3E8->unk3C0.unk0;
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
        sub_802D098(&gUnknown_203B3E8->unk474);
        break;
    case PREPARE_SAVE:
        if(gUnknown_203B3E8->unk498 != 0)
        {
            switch(gUnknown_203B3E8->wonderMailMethod)
            {
                case WONDER_MAIL_GAME_LINK:
                case WONDER_MAIL_PASSWORD:
                    sub_80141B4(gUnknown_80E7B48,0,0,0x101);
                    break;
                case 4:
                    break;
            }
        }
        else
            sub_80141B4(gUnknown_80E7B48,0,0,0x101);
        break;
    case WONDER_MAIL_SENT:
        sub_80141B4(gUnknown_80E7B68,0,0,0x101);
        break;
    case WONDER_MAIL_ADDED:
        if (gUnknown_203B3E8->unk498 != '\0') {
            sub_80141B4(gUnknown_80E7B88,0,0,0x101);
        }
        else {
            // Wonder Mail was refused
            sub_80141B4(gUnknown_80E7BC8,0,0,0x101);
        }
        break;
    case GAME_LINK_CABLE_MENU:
        sub_8014248(gUnknown_80E7BEC,0,6,gUnknown_80E78F8,0,4,0,0,0x101);
        break;
    case 6:
        nullsub_23(0);
        sub_80141B4(gUnknown_80E7C48,0,0,0);
        break;
    case 9:
        gUnknown_203B3E8->wonderMailStatus = 0;
        sub_8011830();
        iVar2 = sub_8037B28(gUnknown_203B3E8->unk24C);
        gUnknown_203B3E8->wonderMailStatus = iVar2;
        if (iVar2 == 0) {
            switch(gUnknown_203B3E8->unk24C)
            {
                case 9:
                    MemoryFill8((u8 *)&gUnknown_203B3E8->unk254,0,0xb4);
                    temp = sub_803B344(gUnknown_203B3E8->unk3BC);
                    if(temp->unk14 != NULL){
                        MemoryCopy8((u8 *)&gUnknown_203B3E8->unk254.unk14,temp->unk14,0x28);
                        MemoryCopy8((u8 *)&gUnknown_203B3E8->unk254.unk3C,temp->unk18,0x78);
                    }
                    gUnknown_203B3E8->unk254.unk0 = temp->unk0;
                    gUnknown_203B3E8->wonderMailStatus = sub_8037D64(gUnknown_203B3E8->unk24C,&gUnknown_203B3E8->unk254,&gUnknown_203B3E8->unk308);
                    break;
                case 10:
                    MemoryFill8((u8 *)&gUnknown_203B3E8->unk254,0,0xb4);
                    MemoryFill8((u8 *)&gUnknown_203B3E8->unk308,0,0xb4);
                    gUnknown_203B3E8->wonderMailStatus = sub_8037D64(gUnknown_203B3E8->unk24C,&gUnknown_203B3E8->unk254,&gUnknown_203B3E8->unk308);
                    break;
            }
            if (gUnknown_203B3E8->wonderMailStatus == 0)
            {
                switch(gUnknown_203B3E8->unk24C)
                {
                    case 9:
                    case 10:
                        gUnknown_203B3E8->wonderMailStatus = sub_80381F4(gUnknown_203B3E8->unk24C,&gUnknown_203B3E8->unk254,&gUnknown_203B3E8->unk308);
                        if (sub_800D588() != '\0') {
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
        sub_80141B4(gUnknown_80E7C98,0,0,0x101);
        break;
    case PASSWORD_ENTRY_SCREEN:
        sub_8006518(gUnknown_203B3E8->unk1EC);
        ResetUnusedInputStruct();
        sub_800641C(0,1,1);
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
