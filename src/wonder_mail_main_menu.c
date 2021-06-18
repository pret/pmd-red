#include "global.h"
#include "save.h"
#include "memory.h"
#include "text.h"
#include "input.h"
#include "wonder_mail.h"

#define WONDER_MAIL_MAIN_SCREEN 4
#define EXIT_TO_MAIN_MENU 5
#define COMMUNICATION_ERROR 10
#define PASSWORD_SUCCESS 13
#define PREPARE_SAVE 14
#define SAVE_ADVENTURE 15
#define WONDER_MAIL_ADDED 16
#define PROMPT_PASSWORD_ENTRY 17
#define PASSWORD_INVALID 19
#define PASSWORD_ENTRY_SCREEN 18

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
    u8 fill254[0x3C0 - 0x254];
    struct WonderMail unk3C0;
    u8 fill3D0[0x490 - 0x3D4];
    u32 unk490;
    u32 unk494;
    u8 unk498;
    u8 unk499;
    u8 unk49A;
    u8 unk49B;
};

extern u32 sub_8095324(u32);
extern u32 sub_80144A4(s32 *);
extern u32 sub_8011C1C(void);
extern struct unkStruct_203B3E8 *gUnknown_203B3E8;
extern void SetWonderMailMainMenuState(u8);
extern void sub_8030DE4(void);
extern void sub_801B450(void);
extern void sub_803084C(void);
extern void sub_801CBB8(void);
extern void sub_80155F0(void);
extern void sub_8031E10(void);

extern u32 sub_802D0E0();
extern u8 sub_802D178();
extern void sub_802D184();

extern s32 sub_80154F0();
extern bool8 DecodeWonderMailPassword(u8 *, struct WonderMail *);
extern bool8 IsValidWonderMail(struct WonderMail *WonderMailData);
extern void sub_80141B4(u32 *r0, u32, u32 *r1, u32);

void sub_8039BAC(u32);
void HandleWonderMailMainScreen(void);
void sub_8039AA8(void);
void sub_8039B14(void);
void sub_8039B20(void);
void sub_8039B58(void);
void sub_8039D88(void);
void HandlePasswordSuccess(void);
void HandlePrepareSaveScreen(void);
void HandleSaveAdventureScreen(void);
void HandleWonderMailAddedScreen(void);
void sub_8039B3C(void);
void sub_8039D0C(void);
void HandlePasswordEntryScreen(void);
void HandleInvalidPasswordMenu(void);


extern u32 gUnknown_80E7914;
extern u32 gUnknown_80E7938;
extern u32 gUnknown_80E7994;
extern u32 gUnknown_80E79E4;
extern u32 gUnknown_80E7A48;

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

  gUnknown_203B3E8->unk490 = 3;
  gUnknown_203B3E8->unk494 = 2;
  gUnknown_203B3E8->unk498 = 1;
  gUnknown_203B3E8->unk490 = 5; // ??? Why?
  SetWonderMailMainMenuState(PROMPT_PASSWORD_ENTRY); // -> Display "Enter Wonder Mail Password"
  return 1;
}

u8 UpdateWonderMailMenu(void)
{
  switch(gUnknown_203B3E8->state) {
    case WONDER_MAIL_MAIN_SCREEN:
        HandleWonderMailMainScreen();
        break;
    case EXIT_TO_MAIN_MENU: // When you exit out of the menu
        return 3;
    case 8:
        sub_8039AA8();
        break;
    case 11:
        break;
    case 12:
        sub_8039B14();
        break;
    case 6:
        sub_8039B20();
        break;
    case 9:
        sub_8039B58();
        break;
    case 7:
        sub_8039D88();
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
        sub_8039B3C();
        break;
    case PROMPT_PASSWORD_ENTRY: // "Please enter the Wonder Mail Password" Screen 
        sub_8039D0C();
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
            gUnknown_203B3E8->unk490 = 3;
            SetWonderMailMainMenuState(8);
            break;
        case 5:
            gUnknown_203B3E8->unk490 = 5;
            SetWonderMailMainMenuState(PROMPT_PASSWORD_ENTRY);
            break;
        case 0:
        case 8:
            SetWonderMailMainMenuState(EXIT_TO_MAIN_MENU);
            break;
    }
  }
}

void sub_8039AA8(void)
{
  s32 menuAction;

  if (sub_80144A4(&menuAction) == 0) {
    switch(menuAction){
        case 6:
            if (gUnknown_203B3E8->unk494 == 1) {
                SetWonderMailMainMenuState(2);
            }
            else {
                SetWonderMailMainMenuState(12);
            }
            break;
        case 0:
            if (gUnknown_203B3E8->unk494 == 1) {
                SetWonderMailMainMenuState(1);
            }
            else {
                SetWonderMailMainMenuState(WONDER_MAIL_MAIN_SCREEN);
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

void sub_8039B3C(void)
{
  s32 local_8;

  if (sub_80144A4(&local_8) == 0) {
      SetWonderMailMainMenuState(WONDER_MAIL_MAIN_SCREEN);
  }
}

void sub_8039B58(void)
{
  s32 temp;

  if (sub_80144A4(&temp) == 0) {
    if (gUnknown_203B3E8->wonderMailStatus == 0) {
      switch(gUnknown_203B3E8->unk24C){
        case 9: 
            SetWonderMailMainMenuState(7);
            break;
        case 10:
            SetWonderMailMainMenuState(PASSWORD_SUCCESS);
            break;
      }
    }
    else {
      sub_8039BAC(gUnknown_203B3E8->wonderMailStatus);
      SetWonderMailMainMenuState(COMMUNICATION_ERROR);
    }
  }
}

void sub_8039BAC(u32 arg)
{
    switch(arg)
    {
        case 0:
            break;
        case 1:
            // "Communication Error"
            sub_80141B4(&gUnknown_80E7914, 0, 0, 0x101);
            break;
        case 3:
            // Incorrect number of GBA Systems
            sub_80141B4(&gUnknown_80E7938, 0, 0, 0x101);
            break;
        case 2:
            // No response from friend. Redo from start
            sub_80141B4(&gUnknown_80E7994, 0, 0, 0x101);
            break;
        case 4:
            // Sender and receiver in different modes
            sub_80141B4(&gUnknown_80E79E4, 0, 0, 0x101);
            break;
        case 5:
            // "Communication Error"
            sub_80141B4(&gUnknown_80E7914, 0, 0, 0x101);
            break;
        case 14:
            // "Communication Error"
            sub_80141B4(&gUnknown_80E7914, 0, 0, 0x101);
            break;
        case 15: // "No response from your friend. Make sure sender and receiver are ready"
            sub_80141B4(&gUnknown_80E7A48, 0, 0, 0x101);
            break;
        case 6:
        case 7:
        case 8:
        case 9:
        case COMMUNICATION_ERROR:
        case 11:
        case 12:
        case PASSWORD_SUCCESS:
        default:
            // "Communication Error"
            sub_80141B4(&gUnknown_80E7914, 0, 0, 0x101);
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
        gUnknown_203B3E8->unk3C0 = gUnknown_203B3E8->UNK38.decodedMail;

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

void sub_8039D0C(void)
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

void sub_8039D88(void)
{
  int iVar2;
  if(sub_80144A4(&iVar2) == 0)
  {
      SetWonderMailMainMenuState(8);
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
