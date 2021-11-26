#include "global.h"
#include "memory.h"
#include "text.h"
#include "input.h"
#include "menu.h"
#include "constants/dungeon.h"
#include "wonder_mail.h"

struct unkSubStruct_203B2F8
{
    struct WonderMail wonderMail;
    u8 *unk14;
    u8 *unk18;
};

struct unkStruct_203B2F8
{
    // size: 0x208
    s32 state; // state
    u32 unk4;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    struct unkSubStruct_203B2F8 *unkC;
    u8 unk10;
    u8 fill11[0x14 - 0x11];
    u32 unk14;
    u8 fill18[0x58 - 0x18];
    u8 unk58;
    u8 fill59[0x64 - 0x59];
    u8 *unk64;
    u32 unk68;
    u32 unk6C;
    u32 unk70;
    u32 unk74;
    u8 unk78[0xC8 - 0x78];
    u8 unkC8[4];
    u8 fillCC[0x118 - 0xCC];
    struct MenuItem unk118[8];
    struct MenuItem unk158[8];
    u16 unk198[8];
    struct UnkTextStruct2 unk1A8[4];
    u32 unk1E4;
};
extern struct unkStruct_203B2F8 *gUnknown_203B2F8;
extern struct UnkTextStruct2 gUnknown_80DFE04;
extern struct UnkTextStruct2 gUnknown_80DFE1C;
extern struct UnkTextStruct2 gUnknown_80DFDD4;
extern void sub_8012CAC(struct UnkTextStruct2 *, struct MenuItem *);
extern void sub_802D63C(void);
extern void sub_802D5A4(void);

extern u8 sub_8099328(u8 *);
extern u32 sub_8011C1C();
extern void sub_802D1A0(u32);

extern void sub_802D7D0();
extern void sub_802D8CC();
extern void sub_802D940();
extern void sub_802D9F0();
extern void sub_802DA60();
extern void sub_802D82C();
extern void sub_802DA84();
extern void sub_802D1B8();
extern void sub_802D2A8();

extern u8 gWonderMailText_QuicksavedCannotDeleteMail[];
extern u8 gWonderMailText_QuicksavedCompleteMissionFirst[];
extern u8 gWonderMailText_ReceiveAfterMissions[];
extern u8 gWonderMailText_AlreadyReceivedLong[];
extern u8 gWonderMailText_AlreadyReceivedShort[];
extern u8 gUnknown_80DFE4C[];
extern u8 gWonderMailText_JobListFullDeleteMail[];
extern u8 gWonderMailText_OnlyOneOKToReplace[];
extern u8 gWonderMailText_ReceivedTheWonderMail[];

extern u8 sub_80968B0(void *);
extern u8 sub_8096F50(void *);
extern u8 sub_802DAA8(void);
extern u8 sub_802DADC(void);
extern u8 *sub_8096DD8(void);
extern u8 sub_8096C08(u8 *);
extern void sub_802C750(void);
extern s32 GetNumAcceptedJobs(void);
extern void sub_802D1A0(u32);
extern void sub_8012EA4(u8 *, u32);
extern void* sub_8096AB4(u8);
extern void sub_803B35C(void *, u32*);
extern void sub_802DE84(u32 *);
extern void sub_802D73C(void);
extern void sub_802C640(u32);
extern void sub_802C4C8(u32, u32, u32);
extern void sub_8097418(u32, u32);
extern void sub_802D690(void);
extern void sub_8096C80(void);
extern void sub_8096D24(void);
extern void sub_80141B4(u8 *, u32, u32, u32);
extern void sub_8012D60(u8 *, struct MenuItem *, u32, u16 *, u32, u32);
extern u8 *sub_8096DE8(void);
extern void sub_8096A78(struct unkSubStruct_203B2F8 *);
extern void sub_8014248(const char *text, u32, u32, struct MenuItem *r0, u32, u32, u32, u32, u32);


u32 sub_802D098(struct unkSubStruct_203B2F8 *param_1)
{
  gUnknown_203B2F8 = MemoryAlloc(0x208,8);
  gUnknown_203B2F8->unk6C = 0;
  gUnknown_203B2F8->unk70 = 0;
  gUnknown_203B2F8->unk74 = 0;
  gUnknown_203B2F8->unkC  = param_1;
  gUnknown_203B2F8->unk8 = 0;
  gUnknown_203B2F8->unk9 = sub_8099328(&gUnknown_203B2F8->unkA);
  if (sub_8011C1C() != 2) {
    gUnknown_203B2F8->unk9 = 0;
  }
  sub_802D1A0(0);
  return 1;
}

u32 sub_802D0E0(void)
{
  switch(gUnknown_203B2F8->state) {
    case 0:
        break;
    case 1:
        sub_802D7D0();
        break;
    case 0xb:
    case 0xc:
        sub_802D8CC();
        break;
    case 0xd:
        sub_802D940();
        break;
    case 0xe:
        sub_802D9F0();
        break;
    case 0xf:
    case 0x10:
        sub_802DA60();
        break;
    case 9:
        sub_802D82C();
        break;
    case 2:
        return 3;
    default:
        sub_802DA84();
        break;
  }
  return 0;
}

u8 sub_802D178(void)
{
    return gUnknown_203B2F8->unk8;
}

void sub_802D184(void)
{
    if(gUnknown_203B2F8 != NULL)
    {
        MemoryFree(gUnknown_203B2F8);
        gUnknown_203B2F8 = NULL;
    }
}

void sub_802D1A0(u32 newState)
{
    gUnknown_203B2F8->state = newState;
    sub_802D1B8();
    sub_802D2A8();
}

void sub_802D1B8(void)
{
    s32 iVar2;
    sub_8006518(gUnknown_203B2F8->unk1A8);
    switch(gUnknown_203B2F8->state)
    {
        case 0xD:
           sub_802D5A4();
           gUnknown_203B2F8->unk1A8[2] = gUnknown_80DFE04;
           sub_8012CAC(&gUnknown_203B2F8->unk1A8[2], gUnknown_203B2F8->unk118);
           gUnknown_203B2F8->unk1A8[2].unk0c = 6;
           break;
        case 0xE:
           sub_802D63C();
           gUnknown_203B2F8->unk1A8[3] = gUnknown_80DFE1C;
           sub_8012CAC(&gUnknown_203B2F8->unk1A8[3], gUnknown_203B2F8->unk158);
           gUnknown_203B2F8->unk1A8[3].unk0c = 6;
           break;
        default:
           for(iVar2 = 0; iVar2 < 4; iVar2++)
           {
               gUnknown_203B2F8->unk1A8[iVar2] = gUnknown_80DFDD4;
           }
           break;
        case 2:
           break;
    }
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B2F8->unk1A8, 1, 1);
}

void sub_802D2A8(void)
{
  
  switch(gUnknown_203B2F8->state) {
  case 0:
    if (sub_80968B0(gUnknown_203B2F8->unkC) != 0) {
        sub_802D1A0(3);
    }
    else
    {
      if (sub_8096F50(gUnknown_203B2F8->unkC) != 0) {
        sub_802D1A0(4);
      }
      else
      {
        if ((gUnknown_203B2F8->unkC->wonderMail.unk2 == 4) && (sub_8096C08(&gUnknown_203B2F8->unk10) != 0)) {
          if (sub_802DAA8() != 0) {
              sub_802D1A0(9);
          }
          else {
              sub_802D1A0(5);
          }
        }
        else {
          if (GetNumAcceptedJobs() >= 8) {
            if (sub_802DADC() != 0) {
                sub_802D1A0(10);
            }
            else {
               sub_802D1A0(6);
            }
          }
          else
          {
              sub_802D1A0(8);
          }
        }
      }
    }
    break;
  case 1:
    sub_802D73C();
    sub_8014248(gUnknown_80DFE4C,0,gUnknown_203B2F8->unk70,gUnknown_203B2F8->unk158,0,4,0,0,0);
    break;
  case 3:
    gUnknown_203B2F8->unk4 = 2;
    sub_80141B4(gWonderMailText_AlreadyReceivedShort,0,0,0x101);
    break;
  case 4:
    gUnknown_203B2F8->unk4 = 2;
    sub_80141B4(gWonderMailText_AlreadyReceivedLong,0,0,0x101);
    break;
  case 5:
    gUnknown_203B2F8->unk4 = 2;
    sub_80141B4(gWonderMailText_ReceiveAfterMissions,0,0,0x101);
    break;
  case 6:
    gUnknown_203B2F8->unk4 = 2;
    sub_80141B4(gWonderMailText_QuicksavedCompleteMissionFirst,0,0,0x101);
    break;
  case 7:
    gUnknown_203B2F8->unk4 = 0xc;
    sub_80141B4(gWonderMailText_QuicksavedCannotDeleteMail,0,0,0x101);
    break;
  case 8:
    gUnknown_203B2F8->unk8 = 1;
    sub_8096A78(gUnknown_203B2F8->unkC);
    sub_8096C80();
    sub_8096D24();
    if (gUnknown_203B2F8->unkC->wonderMail.unk2 == 4) {
      MemoryCopy8(sub_8096DD8(),gUnknown_203B2F8->unkC->unk14,0x28);
      MemoryCopy8(sub_8096DE8(),gUnknown_203B2F8->unkC->unk18,0x78);
    }
    switch(gUnknown_203B2F8->unkC->wonderMail.dungeon)
    {
        // NOTE: subtract 1 from each of the case as the input??
        case DUNGEON_ODDITY_CAVE: // 0x2B
            sub_8097418(0x2A, 1);
            break;
        case DUNGEON_REMAINS_ISLAND:
            sub_8097418(0x2B, 1);
            break;
        case DUNGEON_MARVELOUS_SEA:
            sub_8097418(0x2C, 1);
            break;
        case DUNGEON_FANTASY_STRAIT: // 0x2E
            sub_8097418(0x2D, 1);
            break;
    }
    gUnknown_203B2F8->unk4 = 2;
    sub_80141B4(gWonderMailText_ReceivedTheWonderMail,0,0,0x101);
    break;
  case 9:
    sub_802D690();
    sub_8014248(gWonderMailText_OnlyOneOKToReplace,0,gUnknown_203B2F8->unk74,gUnknown_203B2F8->unk158,0,4,0,0,0);
    break;
  case 10:
    gUnknown_203B2F8->unk4 = 0xb;
    sub_80141B4(gWonderMailText_JobListFullDeleteMail,0,0,0x101);
    break;
  case 0xb:
    sub_802C4C8(0,0,4);
    break;
  case 0xc:
    sub_802C640(1);
    break;
  case 0xd:
    sub_802C750();
    sub_8012D60(gUnknown_203B2F8->unk78,gUnknown_203B2F8->unk118,0,gUnknown_203B2F8->unk198,
                gUnknown_203B2F8->unk6C,2);
    break;
  case 0xe:
    sub_802C750();
    sub_8012EA4(gUnknown_203B2F8->unk78,0);
    sub_8012D60(gUnknown_203B2F8->unkC8,gUnknown_203B2F8->unk158,0,0,4,3);
    break;
  case 0xf:
    sub_803B35C(sub_8096AB4(gUnknown_203B2F8->unk10),&gUnknown_203B2F8->unk14);
    gUnknown_203B2F8->unk14 = 3;
    sub_802DE84(&gUnknown_203B2F8->unk14);
    break;
  case 0x10:
    sub_803B35C(gUnknown_203B2F8->unkC,&gUnknown_203B2F8->unk14);
    gUnknown_203B2F8->unk14 = 3;
    gUnknown_203B2F8->unk58 = 0;
    gUnknown_203B2F8->unk64 = gUnknown_203B2F8->unkC->unk18;
    sub_802DE84(&gUnknown_203B2F8->unk14);
  }
}
