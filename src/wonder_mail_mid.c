#include "global.h"
#include "file_system.h"

struct unkStruct_203B2C4
{
    // size: 0x564
    u8 unk0;
    u8 padding[3];
    u32 unk4; // wonder mail link status??
    u8 unk8[0x36];
    u8 unk3E;
    u32 unk40;
    u32 unk44; // another link status
    u8 filler48[0x218 - 0x48];
    s8 unk218;
    u32 unk21C;
    u8 filler220[0x30C - 0x220];
    u32 unk30C;
    u8 filler310[0x35C - 0x310];
    u32 unk35C;
    u8 filler360[0x3BC - 0x360];
    u32 unk3BC;
    u8 filler3C0[0x41C - 0x3C0];
    u8 unk41C[4]; // TODO: unify this with wonder_mail.c
    struct OpenedFile *faceFile;
    u8 *faceData;
    u16 unk428;
    u16 unk42A;
    u8 unk42C;
    u8 unk42D;
    u8 unk42E;
    u32 unk430;
    u8 filler434[0x534 - 0x434];
    s32 unk534;
    u32 unk538;
};
extern struct unkStruct_203B2C4 *gUnknown_203B2C4;


extern u16 gUnknown_80E5990[];
extern s32 sub_8001658(u32, u32);
extern u32 gUnknown_80E4A40[];
extern u8 sub_8099B94();

extern void sub_8099A5C(u32, u32, u32*);
extern void sub_8099AFC(u32, u32, u32*);
extern void sub_800641C(void *, u32, u32);
extern void ResetUnusedInputStruct();
extern void sub_8099690(u32);
extern void sub_80141B4(u32 *r0, u32, u32 *r1, u32);


extern void MemoryFill8(u8 *dest, u8 value, s32 size);
extern u32 gUnknown_80DF194;
extern void sub_8029EC4(u32 param_1);

extern void sub_802B2BC(u32);
extern u32 sub_80144A4(s32 *r0);
extern u32 sub_8031DCC(void);
extern void sub_8031E00(void);
extern void sub_8031E10(void);
extern void sub_8030D40(u8, u32);
extern u32 sub_8030768(u32);
extern void sub_803084C(void);
extern s8 sub_80307EC(void);
extern void sub_8006518(u32 *);
extern u8 sub_8012FD8(u32 *r0);
extern void sub_8013114(u32 *, s32 *);
extern void sub_8035CC0(u32 *, u32);
extern void sub_8030810(u32);
extern u32 sub_8030DA0();
extern void sub_8030DE4();
extern void sub_803092C();
extern void sub_8035CF4(u32 *, u32, u32);
extern u32 sub_801CA08(u32);
extern void sub_801CBB8();
extern void sub_801B3C0(u8 *);
extern u8 sub_801CB24();
extern void sub_801B450();
extern u32 sub_801B410();
extern void sub_801CB5C(u32);
extern void sub_801CCD8();
extern void sub_8011C28(u32);
extern void sub_8012574(u32);

void sub_8029F98(void)
{
  s32 auStack20;

  if (sub_80144A4(&auStack20) != 0) {
    return;
  }
  MemoryFill8(gUnknown_203B2C4->unk41C, 0, 4);
  gUnknown_203B2C4->unk41C[2] = 0;
  gUnknown_203B2C4->unk41C[1] = 1;
  gUnknown_203B2C4->unk41C[0] = 0;
  if (gUnknown_203B2C4->unk44 == 0) {
      switch(gUnknown_203B2C4->unk40) 
        {
            case 6:
                switch(gUnknown_203B2C4->unk534)
                {
                    case 3:
                    case 5:
                    case 6:
                        sub_80141B4(&gUnknown_80DF194, 0, (u32 *)&gUnknown_203B2C4->faceFile, 0x10d);
                        break;
                    case 4:
                    default:
                        break;
                }
                sub_802B2BC(0xD);
                return;
            case 7:
                sub_802B2BC(0x21);
                return;
            default:
                return;
        }
  }
  else
  {
      sub_8029EC4(gUnknown_203B2C4->unk44);
      sub_802B2BC(0x1F);
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
            sub_800641C(&gUnknown_203B2C4->unk3BC, 1, 1);
            sub_802B2BC(0x1B);
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
                sub_802B2BC(6);
                break;
            case 8:
            case 0:
                sub_802B2BC(1);
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
        sub_802B2BC(1);
        break;
    case 3:
        gUnknown_203B2C4->unk218 = sub_80307EC();
        sub_802B2BC(0x11);
        break;
    case 4:
            gUnknown_203B2C4->unk4 = 0x10;
            gUnknown_203B2C4->unk218 = sub_80307EC();
            sub_8006518(&gUnknown_203B2C4->unk3BC);
            ResetUnusedInputStruct();
            sub_800641C(0,1,1);
            sub_8030D40(gUnknown_203B2C4->unk218,0);
            sub_802B2BC(0x12);
  }
}

void sub_802A158(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        sub_802B2BC(0x10);
    }
}

void sub_802A174(void)
{
  s32 temp;

  temp = -1;
  sub_8030768(0);
  if (sub_8012FD8(&gUnknown_203B2C4->unk30C) == 0) {
    sub_8013114(&gUnknown_203B2C4->unk30C, &temp);
  }
  
  switch(temp)
  {
      case 0xB:
            sub_803084C();
            sub_802B2BC(0xe);
            break;
      case 0xC:
            gUnknown_203B2C4->unk4 = 0x2b;
            sub_8006518(&gUnknown_203B2C4->unk3BC);
            ResetUnusedInputStruct();
            sub_800641C(0,1,1);
            sub_8030D40(gUnknown_203B2C4->unk218,0);
            sub_802B2BC(0x12);
            break;
      case 0:
      case 0xD:
            sub_8035CC0(&gUnknown_203B2C4->unk35C,2);
            sub_8030810(1);
            sub_802B2BC(0x10);
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
        sub_800641C(&gUnknown_203B2C4->unk3BC, 1, 1);
        sub_803092C();
        if (gUnknown_203B2C4->unk4 == 0x2b) {
            sub_8035CF4(&gUnknown_203B2C4->unk21C, 3, 1);
            sub_802B2BC(0x11);
        }
        else {
            sub_802B2BC(gUnknown_203B2C4->unk4);
        }
        break;
    default:
        break;
  }
}

void sub_802A28C(void)
{

  gUnknown_203B2C4->unk41C[2] = 0;
  gUnknown_203B2C4->unk41C[1] = 1;
  gUnknown_203B2C4->unk41C[0] = 0;

  switch(sub_801CA08(1))
  {
    case 2:
        sub_801CBB8();
        sub_802B2BC(1);
        break;
    case 3:
        gUnknown_203B2C4->unk41C[2] = sub_801CB24();
        sub_802B2BC(0x14);
        break;
    case 4:
        gUnknown_203B2C4->unk4 = 0x13;
        gUnknown_203B2C4->unk41C[2] = sub_801CB24();
        sub_8006518(&gUnknown_203B2C4->unk3BC);
        ResetUnusedInputStruct();
        sub_800641C(0,1,1);
        sub_801B3C0(gUnknown_203B2C4->unk41C);
        sub_802B2BC(0x15);
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
        sub_800641C(&gUnknown_203B2C4->unk3BC,1,1);
        sub_801CB5C(1);
        if (gUnknown_203B2C4->unk4 == 0x2b) {
            sub_8035CF4(&gUnknown_203B2C4->unk21C,3,1);
            sub_802B2BC(0x14);
        }
        else {
            sub_802B2BC(gUnknown_203B2C4->unk4);
        }
        break;
    case 1:
    default:
        break;
  }
}

void sub_802A39C(void)
{
  s32 temp;

  temp = -1;
  sub_801CA08(0);
  if (sub_8012FD8(&gUnknown_203B2C4->unk30C) == 0) {
    sub_8013114(&gUnknown_203B2C4->unk30C, &temp);
  }

  switch(temp)
  {
      case 0xB:
            sub_801CBB8();
            sub_802B2BC(0xC);
            break;
      case 0xC:
            gUnknown_203B2C4->unk4 = 0x2b;
            sub_8006518(&gUnknown_203B2C4->unk3BC);
            ResetUnusedInputStruct();
            sub_800641C(0,1,1);
            sub_801B3C0(gUnknown_203B2C4->unk41C);
            sub_802B2BC(0x15);
            break;
      case 0:
      case 0xD:
            sub_8035CC0(&gUnknown_203B2C4->unk35C, 3);
            sub_801CCD8();
            sub_802B2BC(0x13);
      default:
        break;
  }
}

void sub_802A458(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        sub_802B2BC(0xD);
    }
}

void sub_802A474(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        sub_802B2BC(0x3);
    }
}

void sub_802A490(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        sub_802B2BC(0x3);
    }
}

void sub_802A4AC(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        sub_802B2BC(0x18);
        sub_8011C28(1);
        sub_8012574(0);
    }
}

void sub_802A4D4(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        sub_802B2BC(0x1A);
    }
}

void sub_802A4F0(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        sub_802B2BC(0x27);
    }
}
