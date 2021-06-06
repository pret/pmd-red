#include "global.h"
#include "save.h"
#include "memory.h"
#include "text.h"
#include "input.h"

#define EXIT_TO_MAIN_MENU 5
#define PASSWORD_SUCCESS 13
#define PASSWORD_INVALID 19
#define PASSWORD_ENTRY_SCREEN 18

struct unkWonderMailData
{
    u8 unk0[20];
};

struct unkStruct_203B3E8
{
    // size: 0x49C
    u8 unk0; // state variable?
    u8 PasswordEntryBuffer[0x36]; // Wonder Mail Buffer...
    struct unkWonderMailData unk38; // 0x30 - 0x14
    u8 unk38_1[0x30 - 20]; // TODO: split for the ldm/stm stuff (fix dumb hack)
    u8 fill68[0x1EC - 0x68];
    struct UnkTextStruct2 unk1EC[4];
    u32 unk24C;
    u32 wonderMailStatus;
    u8 fill254[0x3C0 - 0x254];
    struct unkWonderMailData unk3C0; // 0x3C0 + 0x14
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
extern void sub_803A1C0(u8);
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
extern bool8 sub_803D358(u8 *, void *);
extern bool8 sub_80959C0(void *);
extern void sub_80141B4(u32 *r0, u32, u32 *r1, u32);

void sub_8039BAC(u32);
void sub_8039A18(void);
void sub_8039AA8(void);
void sub_8039B14(void);
void sub_8039B20(void);
void sub_8039B58(void);
void sub_8039D88(void);
void sub_8039D28(void);
void sub_8039D68(void);
void sub_8039DA4(void);
void sub_8039DCC(void);
void sub_8039B3C(void);
void sub_8039D0C(void);
void sub_8039C60(void);
void sub_8039DE8(void);


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

  for(iVar2 = 0; iVar2 < 0x36; iVar2++){
    gUnknown_203B3E8->PasswordEntryBuffer[iVar2] = 0;
  }

  gUnknown_203B3E8->unk490 = 3;
  gUnknown_203B3E8->unk494 = 2;
  gUnknown_203B3E8->unk498 = 1;
  gUnknown_203B3E8->unk490 = 5; // ??? Why?
  sub_803A1C0(0x11); // 0x11 -> Display "Enter Wonder Mail Password"
  return 1;
}

u8 UpdateWonderMailMenu(void)
{
  switch(gUnknown_203B3E8->unk0) {
    case 4:
        sub_8039A18();
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
        sub_8039D28();
        break;
    case 14:
        sub_8039D68();
        break;
    case 15: // Saving adventure
        sub_8039DA4();
        break;
    case 16: // Display "Recieved Wonder Mail was added" and go back to main menu
        sub_8039DCC();
        break;
    case 10:
        sub_8039B3C();
        break;
    case 17: // "Please enter the Wonder Mail Password" Screen 
        sub_8039D0C();
        break;
    case PASSWORD_ENTRY_SCREEN: // Password Entry
        sub_8039C60();
        break;
    case PASSWORD_INVALID:
        sub_8039DE8();
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

void sub_8039A18(void)
{
  s32 local_8;

  if (sub_80144A4(&local_8) == 0) {
    gUnknown_203B3E8->unk24C = 10;
    switch(local_8) {
        case 3:
        case 4:
            gUnknown_203B3E8->unk490 = 3;
            sub_803A1C0(8);
            break;
        case 5:
            gUnknown_203B3E8->unk490 = 5;
            sub_803A1C0(17);
            break;
        case 0:
        case 8:
            sub_803A1C0(EXIT_TO_MAIN_MENU);
            break;
    }
  }
}

void sub_8039AA8(void)
{
  s32 local_8;

  if (sub_80144A4(&local_8) == 0) {
    switch(local_8){
        case 6:
            if (gUnknown_203B3E8->unk494 == 1) {
                sub_803A1C0(2);
            }
            else {
                sub_803A1C0(12);
            }
            break;
        case 0:
            if (gUnknown_203B3E8->unk494 == 1) {
                sub_803A1C0(1);
            }
            else {
                sub_803A1C0(4);
            }
            break;
    }
  }
}

void sub_8039B14(void)
{
    sub_803A1C0(6);
}

void sub_8039B20(void)
{
  s32 local_8;

  if (sub_80144A4(&local_8) == 0) {
      sub_803A1C0(9);
  }
}

void sub_8039B3C(void)
{
  s32 local_8;

  if (sub_80144A4(&local_8) == 0) {
      sub_803A1C0(4);
  }
}

void sub_8039B58(void)
{
  s32 temp;

  if (sub_80144A4(&temp) == 0) {
    if (gUnknown_203B3E8->wonderMailStatus == 0) {
      switch(gUnknown_203B3E8->unk24C){
        case 9: 
            sub_803A1C0(7);
            break;
        case 10:
            sub_803A1C0(PASSWORD_SUCCESS);
            break;
      }
    }
    else {
      sub_8039BAC(gUnknown_203B3E8->wonderMailStatus);
      sub_803A1C0(10);
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
        case 10:
        case 11:
        case 12:
        case PASSWORD_SUCCESS:
        default:
            // "Communication Error"
            sub_80141B4(&gUnknown_80E7914, 0, 0, 0x101);
            break;

    }
}

void sub_8039C60(void)
{
  int iVar2;
  
  iVar2 = sub_80154F0();
  MemoryFill8((u8 *)&gUnknown_203B3E8->unk38, 0, 0x30);
  switch(iVar2){
    case 3:
      sub_80155F0();
      ResetUnusedInputStruct();
      sub_800641C(gUnknown_203B3E8->unk1EC,1,1);
      if ( !sub_803D358(gUnknown_203B3E8->PasswordEntryBuffer, &gUnknown_203B3E8->unk38) || !sub_80959C0(&gUnknown_203B3E8->unk38) ) 
      {
        // Invalid password
        sub_803A1C0(PASSWORD_INVALID);
      }
      else {
        // Successful password
        // Copy the decoded data to another buffer?
        gUnknown_203B3E8->unk3C0 = gUnknown_203B3E8->unk38;

        gUnknown_203B3E8->unk498 = 1;
        sub_803A1C0(PASSWORD_SUCCESS);
      }
    break;
    case 2:
        sub_80155F0();
        ResetUnusedInputStruct();
        sub_800641C(gUnknown_203B3E8->unk1EC,1,1);
        sub_803A1C0(EXIT_TO_MAIN_MENU);
        break;
  }
}

void sub_8039D0C(void)
{
  int iVar2;
  if(sub_80144A4(&iVar2) == 0)
  {
      sub_803A1C0(PASSWORD_ENTRY_SCREEN);
  }
}

void sub_8039D28(void)
{
  if (sub_802D0E0() == 3) {
    gUnknown_203B3E8->unk498 = sub_802D178();
    sub_802D184();
    if (gUnknown_203B3E8->unk498 != 0) {
        sub_803A1C0(0xe);
    }
    else {
        sub_803A1C0(0x10);
    }
  }
}

void sub_8039D68(void)
{
  int iVar2;
  if(sub_80144A4(&iVar2) == 0)
  {
      sub_803A1C0(0xF);
      PrepareSavePakWrite(0); // "Saving Adventure.."
  }
}

void sub_8039D88(void)
{
  int iVar2;
  if(sub_80144A4(&iVar2) == 0)
  {
      sub_803A1C0(8);
  }
}

void sub_8039DA4(void)
{
  int iVar2;
  if(sub_80144A4(&iVar2) == 0)
  {
      if(!WriteSavePak())
      {
          FinishWriteSavePak();
          sub_803A1C0(0x10);
      }
  }
}

void sub_8039DCC(void)
{
  int iVar2;
  if(sub_80144A4(&iVar2) == 0)
  {
      sub_803A1C0(EXIT_TO_MAIN_MENU);
  }
}

void sub_8039DE8(void)
{
  int iVar2;
  
  // Prompt to re-enter password
  if(sub_80144A4(&iVar2) == 0)
  {
    switch(iVar2)
    {
        case 6: // Yes
            sub_803A1C0(0x11);
            break;
        case 0: // No
            sub_803A1C0(EXIT_TO_MAIN_MENU);
            break;
    }
  }
}

void nullsub_54(void)
{
}
