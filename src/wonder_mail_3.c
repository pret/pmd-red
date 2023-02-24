#include "global.h"
#include "memory.h"
#include "text.h"
#include "input.h"
#include "mailbox.h"
#include "menu.h"
#include "constants/dungeon.h"
#include "wonder_mail.h"
#include "wonder_mail_3.h"
#include "code_802C39C.h"

const struct UnkTextStruct2 gUnknown_80DFDD4 =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    NULL
};

// Unused
const struct UnkTextStruct2 gUnknown_80DFDEC =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x03, 0x00, 0x03, 0x00,
    0x07, 0x03,
    0x03, 0x00,
    NULL
};

const struct UnkTextStruct2 gUnknown_80DFE04 =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x15, 0x00, 0x06, 0x00,
    0x07, 0x03,
    0x03, 0x00,
    NULL
};
const struct UnkTextStruct2 gUnknown_80DFE1C =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x15, 0x00, 0x0f, 0x00,
    0x07, 0x03,
    0x03, 0x00,
    NULL
};

// Unused
const struct UnkTextStruct2 gUnknown_80DFE34 =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x15, 0x00, 0x0f, 0x00,
    0x06, 0x03,
    0x03, 0x00,
    NULL
};

ALIGNED(4) const u8 gUnknown_80DFE4C[] = _(
	"Are you sure you want to replace the\n"
	"old  {COLOR_1 LIGHT_BLUE_2}Wonder Mail{END_COLOR_TEXT_1} with the new one?");

ALIGNED(4) const u8 gUnknown_80DFE9C[] = _(
	"This {COLOR_1 LIGHT_BLUE_2}Wonder Mail{END_COLOR_TEXT_1} has already been\n"
	"received.");

ALIGNED(4) const u8 gUnknown_80DFED0[] = _(
	"This {COLOR_1 LIGHT_BLUE_2}Wonder Mail{END_COLOR_TEXT_1} has already been\n"
	"received.\n"
	"You may not receive the same one again.");

ALIGNED(4) const u8 gUnknown_80DFF2C[] = _(
	"Only {COLOR_1 LIGHT_BLUE_2}one piece{END_COLOR_TEXT_1} of {COLOR_1 LIGHT_BLUE_2}Wonder Mail{END_COLOR_TEXT_1} can be held.\n"
	"Please receive it after completing any\n"
	"rescue mission in progress.");

ALIGNED(4) const u8 gUnknown_80DFFA4[] = 
	"The rescue team has quicksaved in\n"
	"a dungeon with a mission in progress.\n"
	"Please complete the mission first.";

ALIGNED(4) const u8 gUnknown_80E0010[] =
	"The rescue team has quicksaved in\n"
	"a dungeon with a mission in progress.\n"
	"Mail cannot be deleted now.";

ALIGNED(4) const u8 gUnknown_80E0074[] = _(
	"Received the {COLOR_1 LIGHT_BLUE_2}Wonder Mail{END_COLOR_TEXT_1}!");

ALIGNED(4) const u8 gUnknown_80E0094[] = _(
	"Only {COLOR_1 LIGHT_BLUE_2}one piece{END_COLOR_TEXT_1} of {COLOR_1 LIGHT_BLUE_2}Wonder Mail{END_COLOR_TEXT_1} can be held.\n"
	"Is it OK to replace the old {COLOR_1 LIGHT_BLUE_2}Wonder Mail{END_COLOR_TEXT_1}\n"
	"with the new one?");

ALIGNED(4) const u8 gUnknown_80E0108[] = _(
	"Your {COLOR_1 LIGHT_BLUE_2}Job List{END_COLOR_TEXT_1} is full.\n"
	"Please select and delete unwanted mail.");

ALIGNED(4) const u8 gUnknown_80E014C[] = "New Mail";
ALIGNED(4) const u8 gUnknown_80E0158[] = "Old Mail";
static const u8 wonder_mail_3_fill[] = "pksdir0";

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


extern bool8 IsMailinJobSlot(struct WonderMail *);
extern u8 sub_8096F50(struct WonderMail *);
extern u8 sub_802DAA8(void);
extern u8 sub_802DADC(void);
extern u8 *sub_8096DD8(void);
extern u8 sub_8096C08(u8 *);
extern void sub_802C750(void);
extern void sub_802D1A0(u32);
extern void sub_8012EA4(u8 *, u32);
extern struct WonderMail* GetJobSlotInfo(u8);
extern void sub_803B35C(void *, u32*);
extern void sub_802DE84(u32 *);
extern void sub_802D73C(void);
extern void sub_802C640(u32);
extern void sub_802C4C8(u32, u32, u32);
extern void sub_8097418(u32, u32);
extern void sub_802D690(void);
extern void sub_8096C80(void);
extern void sub_8096D24(void);
extern void sub_80141B4(const u8 *, u32, u32, u32);
extern void sub_8012D60(u8 *, struct MenuItem *, u32, u16 *, u32, u32);
extern u8 *sub_8096DE8(void);
extern void sub_8096A78(struct unkSubStruct_203B2F8 *);
extern void sub_8014248(const char *text, u32, u32, struct MenuItem *r0, u32, u32, u32, u32, u32);
struct unkStruct_803B344 *sub_803B344(u8);
extern void xxx_call_draw_string(u32, u32, const u8 *, u32, u32);
extern void sub_8012BC4(u32 x, u32 y, u32, u32, u32, u32);
extern void sub_8008C54(u32);
extern void sub_80073B8(u32);
extern void sub_80073E0(u32);
extern void CreateRescueTitle(void *);
extern s32 sub_8013800(void *, u32);
extern u8 gUnknown_80DFDBC[];


void sub_802CFD0(void)
{
  struct unkStruct_802C39C local;    
  struct unkStruct_803B344 *iVar1;
  s32 r5;
  s32 r4;
  
  sub_8008C54(gUnknown_203B2F4->unk34);
  sub_80073B8(gUnknown_203B2F4->unk34);
  r5 = r4 = gUnknown_203B2F4->unk1E * 8 + 10;
  xxx_call_draw_string(r5,0,gUnknown_80DFDBC,gUnknown_203B2F4->unk34,0); // RESCUE EVENT
  r4 -= 6;
  r5 = r4 + (gUnknown_203B2F4->unk9C[2] * 8);
  sub_8012BC4(r5,0,gUnknown_203B2F4->unk1E + 1,2,7,gUnknown_203B2F4->unk34);

  r5 = 0;
  
  if(r5 < gUnknown_203B2F4->unk1A)
  {
    while(r5 < gUnknown_203B2F4->unk1A) {
        iVar1 = sub_803B344(gUnknown_203B2F4->unk1E * gUnknown_203B2F4->unk1C + r5);
        local.unk0[0] = gUnknown_203B2F4->unk34;
        local.y = sub_8013800(gUnknown_203B2F4,r5);
        sub_803B35C(iVar1,local.unk0);
        local.unk43 = 1;
        local.unk4C = iVar1->unk14;
        CreateRescueTitle(&local);
        r5++;
    }
  }
  sub_80073E0(gUnknown_203B2F4->unk34);
}

u32 sub_802D098(struct unkSubStruct_203B2F8 *param_1)
{
  gUnknown_203B2F8 = MemoryAlloc(0x208,8);
  gUnknown_203B2F8->unk6C = 0;
  gUnknown_203B2F8->unk70 = 0;
  gUnknown_203B2F8->unk74 = 0;
  gUnknown_203B2F8->unkC  = param_1;
  gUnknown_203B2F8->wonderMailAccepted = FALSE;
  gUnknown_203B2F8->unk9 = sub_8099328(&gUnknown_203B2F8->dungeonID);
  if (sub_8011C1C() != 2) {
    gUnknown_203B2F8->unk9 = FALSE;
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

bool8 GetWonderMailAccepted(void)
{
    return gUnknown_203B2F8->wonderMailAccepted;
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
        if (IsMailinJobSlot(&gUnknown_203B2F8->unkC->wonderMail)) {
            sub_802D1A0(3);
        }
        else if (sub_8096F50(&gUnknown_203B2F8->unkC->wonderMail) != 0) {
            sub_802D1A0(4);
        }
        else if ((gUnknown_203B2F8->unkC->wonderMail.unk2 == 4) && (sub_8096C08(&gUnknown_203B2F8->jobSlotIndex) != 0)) {
            if (sub_802DAA8() != 0) {
                sub_802D1A0(9);
            }
            else {
                sub_802D1A0(5);
            }
        }
        else if (GetNumAcceptedJobs() >= MAX_ACCEPTED_JOBS) {
            if (sub_802DADC() != 0) {
                sub_802D1A0(10);
            }
            else {
                sub_802D1A0(6);
            }
        }
        else
            sub_802D1A0(8);
        break;
      case 1:
        sub_802D73C();
        sub_8014248(gUnknown_80DFE4C,0,gUnknown_203B2F8->unk70,gUnknown_203B2F8->unk158,0,4,0,0,0);
        break;
      case 3:
        gUnknown_203B2F8->fallbackState = 2;
        sub_80141B4(gUnknown_80DFE9C,0,0,0x101);
        break;
      case 4:
        gUnknown_203B2F8->fallbackState = 2;
        sub_80141B4(gUnknown_80DFED0,0,0,0x101);
        break;
      case 5:
        gUnknown_203B2F8->fallbackState = 2;
        sub_80141B4(gUnknown_80DFF2C,0,0,0x101);
        break;
      case 6:
        gUnknown_203B2F8->fallbackState = 2;
        sub_80141B4(gUnknown_80DFFA4,0,0,0x101);
        break;
      case 7:
        gUnknown_203B2F8->fallbackState = 0xc;
        sub_80141B4(gUnknown_80E0010,0,0,0x101);
        break;
      case 8:
        gUnknown_203B2F8->wonderMailAccepted = TRUE;
        sub_8096A78(gUnknown_203B2F8->unkC);
        sub_8096C80();
        sub_8096D24();
        if (gUnknown_203B2F8->unkC->wonderMail.unk2 == 4) {
          MemoryCopy8(sub_8096DD8(),gUnknown_203B2F8->unkC->unk14,0x28);
          MemoryCopy8(sub_8096DE8(),gUnknown_203B2F8->unkC->unk18,0x78);
        }
        switch(gUnknown_203B2F8->unkC->wonderMail.dungeon.id)
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
        gUnknown_203B2F8->fallbackState = 2;
        sub_80141B4(gUnknown_80E0074,0,0,0x101);
        break;
      case 9:
        sub_802D690();
        sub_8014248(gUnknown_80E0094,0,gUnknown_203B2F8->unk74,gUnknown_203B2F8->unk158,0,4,0,0,0);
        break;
      case 10:
        gUnknown_203B2F8->fallbackState = 0xb;
        sub_80141B4(gUnknown_80E0108,0,0,0x101);
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
        sub_803B35C(GetJobSlotInfo(gUnknown_203B2F8->jobSlotIndex),&gUnknown_203B2F8->unk14);
        gUnknown_203B2F8->unk14 = 3;
        sub_802DE84(&gUnknown_203B2F8->unk14);
        break;
      case 0x10:
        sub_803B35C(gUnknown_203B2F8->unkC,&gUnknown_203B2F8->unk14);
        gUnknown_203B2F8->unk14 = 3;
        gUnknown_203B2F8->unk58 = 0;
        gUnknown_203B2F8->unk64 = gUnknown_203B2F8->unkC->unk18;
        sub_802DE84(&gUnknown_203B2F8->unk14);
        break;
  }
}
