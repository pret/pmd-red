#include "global.h"

struct unkWonderMailData
{
    u8 unk0[20];
};

struct unkStruct_203B3E8
{
    // size: 0x49C
    u8 unk0; // state variable?
    u8 unk1[0x36];
    struct unkWonderMailData unk38; // 0x30 - 0x14
    u8 unk38_1[0x30 - 20]; // TODO: split for the ldm/stm stuff (fix dumb hack)
    u8 fill68[0x1EC - 0x68];
    u32 unk1EC;
    u8 fill1F0[0x24C - 0x1F0];
    u32 unk24C;
    u32 unk250;
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
extern void* MemoryAlloc(u32, u32);
extern void MemoryFree(void *);
extern void MemoryFill8(u8 *dest, u8 value, s32 size);
extern void sub_803A1C0(u8);
extern void ResetUnusedInputStruct(void);
extern void sub_800641C(void *, u32, u32);
extern void sub_8039A18(void);
extern void sub_8039AA8(void);
extern void sub_8039B14(void);
extern void sub_8039B20(void);
extern void sub_8039B58(void);
extern void sub_8039D88(void);
extern void sub_8039D28(void);
extern void sub_8039D68(void);
extern void sub_8039DA4(void);
extern void sub_8039DCC(void);
extern void sub_8039B3C(void);
extern void sub_8039D0C(void);
extern void sub_8039C60(void);
extern void sub_8039DE8(void);
extern void sub_8030DE4();
extern void sub_801B450();
extern void sub_803084C();
extern void sub_801CBB8();
extern void sub_80155F0();
extern void sub_8031E10();

extern u32 sub_802D0E0();
extern u8 sub_802D178();
extern void sub_802D184();
extern u8 sub_8012600();
extern void sub_8012750();

extern void sub_8012574(u32);

extern s32 sub_80154F0();
extern bool8 sub_803D358(u8 *, void *);
extern bool8 sub_80959C0(void *);
extern void sub_80141B4(u32 *r0, u32, u32 *r1, u32);

void sub_8039BAC(u32);


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
    gUnknown_203B3E8->unk1[iVar2] = 0;
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
    case 5:
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
    case 13:
        sub_8039D28();
        break;
    case 14:
        sub_8039D68();
        break;
    case 15:
        sub_8039DA4();
        break;
    case 16:
        sub_8039DCC();
        break;
    case 10:
        sub_8039B3C();
        break;
    case 17:
        sub_8039D0C();
        break;
    case 18:
        sub_8039C60();
        break;
    case 19:
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
            sub_803A1C0(5);
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
    if (gUnknown_203B3E8->unk250 == 0) {
      switch(gUnknown_203B3E8->unk24C){
        case 9: 
            sub_803A1C0(7);
            break;
        case 10:
            sub_803A1C0(13);
            break;
      }
    }
    else {
      sub_8039BAC(gUnknown_203B3E8->unk250);
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
        case 13:
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
      sub_800641C(&gUnknown_203B3E8->unk1EC,1,1);
      if ( !sub_803D358(gUnknown_203B3E8->unk1,&gUnknown_203B3E8->unk38) || !sub_80959C0(&gUnknown_203B3E8->unk38) ) 
      {
        sub_803A1C0(19);
      }
      else {
        // Copying some data but don't know what or structure
        gUnknown_203B3E8->unk3C0 = gUnknown_203B3E8->unk38;

        gUnknown_203B3E8->unk498 = 1;
        sub_803A1C0(13);
      }
    break;
    case 2:
        sub_80155F0();
        ResetUnusedInputStruct();
        sub_800641C(&gUnknown_203B3E8->unk1EC,1,1);
        sub_803A1C0(5);
        break;
  }
}

void sub_8039D0C(void)
{
  int iVar2;
  if(sub_80144A4(&iVar2) == 0)
  {
      sub_803A1C0(0x12);
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
      sub_8012574(0);
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
      if(!sub_8012600())
      {
          sub_8012750();
          sub_803A1C0(0x10);
      }
  }
}

void sub_8039DCC(void)
{
  int iVar2;
  if(sub_80144A4(&iVar2) == 0)
  {
          sub_803A1C0(5);
  }
}

void sub_8039DE8(void)
{
  int iVar2;
  if(sub_80144A4(&iVar2) == 0)
  {
    switch(iVar2)
    {
        case 6:
            sub_803A1C0(0x11);
            break;
        case 0:
            sub_803A1C0(5);
            break;
    }
  }
}

void nullsub_54(void)
{
}
