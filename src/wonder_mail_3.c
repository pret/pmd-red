#include "constants/mailbox.h"
#include "global.h"
#include "constants/dungeon.h"
#include "constants/input.h"

#include "memory.h"
#include "text.h"
#include "input.h"
#include "mailbox.h"
#include "menu.h"
#include "wonder_mail.h"
#include "wonder_mail_3.h"
#include "menu_input.h"
#include "code_80958E8.h"
#include "wonder_mail_2_1.h"

const struct UnkTextStruct2 gUnknown_80DFDD4 =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    NULL
};

// Unused
const struct UnkTextStruct2 gUnknown_80DFDEC =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x03, 0x03,
    0x07, 0x03,
    0x03, 0x00,
    NULL
};

const struct UnkTextStruct2 gUnknown_80DFE04 =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x15, 0x06,
    0x07, 0x03,
    0x03, 0x00,
    NULL
};
const struct UnkTextStruct2 gUnknown_80DFE1C =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x15, 0x0f,
    0x07, 0x03,
    0x03, 0x00,
    NULL
};

// Unused
const struct UnkTextStruct2 gUnknown_80DFE34 =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x15, 0x0f,
    0x06, 0x03,
    0x03, 0x00,
    NULL
};

ALIGNED(4) const u8 gUnknown_80DFE4C[] = _(
	"Are you sure you want to replace the\n"
	"old  {COLOR_1 LIGHT_BLUE}Wonder Mail{END_COLOR_TEXT_1} with the new one?");

ALIGNED(4) const u8 gUnknown_80DFE9C[] = _(
	"This {COLOR_1 LIGHT_BLUE}Wonder Mail{END_COLOR_TEXT_1} has already been\n"
	"received.");

ALIGNED(4) const u8 gUnknown_80DFED0[] = _(
	"This {COLOR_1 LIGHT_BLUE}Wonder Mail{END_COLOR_TEXT_1} has already been\n"
	"received.\n"
	"You may not receive the same one again.");

ALIGNED(4) const u8 gUnknown_80DFF2C[] = _(
	"Only {COLOR_1 LIGHT_BLUE}one piece{END_COLOR_TEXT_1} of {COLOR_1 LIGHT_BLUE}Wonder Mail{END_COLOR_TEXT_1} can be held.\n"
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

ALIGNED(4) const u8 gReceivedWonderMail[] = _(
	"Received the {COLOR_1 LIGHT_BLUE}Wonder Mail{END_COLOR_TEXT_1}!");

ALIGNED(4) const u8 gUnknown_80E0094[] = _(
	"Only {COLOR_1 LIGHT_BLUE}one piece{END_COLOR_TEXT_1} of {COLOR_1 LIGHT_BLUE}Wonder Mail{END_COLOR_TEXT_1} can be held.\n"
	"Is it OK to replace the old {COLOR_1 LIGHT_BLUE}Wonder Mail{END_COLOR_TEXT_1}\n"
	"with the new one?");

ALIGNED(4) const u8 gUnknown_80E0108[] = _(
	"Your {COLOR_1 LIGHT_BLUE}Job List{END_COLOR_TEXT_1} is full.\n"
	"Please select and delete unwanted mail.");

ALIGNED(4) const u8 gUnknown_80E014C[] = "New Mail";
ALIGNED(4) const u8 gUnknown_80E0158[] = "Old Mail";
static const u8 wonder_mail_3_fill[] = "pksdir0";

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
extern void AdvancetoFallbackWonderMailRescueState();
extern void sub_802D1B8();
extern void sub_802D2A8();


extern bool8 IsMailinJobSlot(struct WonderMail *);
extern u8 sub_8096F50(struct WonderMail *);
extern u8 sub_802DAA8(void);
extern u8 sub_802DADC(void);
extern u8 *sub_8096DD8(void);
extern u8 sub_8096C08(u8 *);
extern void DrawJobListMenu(void);
extern struct WonderMail* GetJobSlotInfo(u8);
extern void sub_803B35C(struct WonderMail *, struct unkStruct_802C39C*);
extern void sub_802DE84(struct unkStruct_802C39C *);
extern void sub_802D73C(void);
extern void sub_802C640(u32);
extern void sub_802C4C8(u32, u32, u32);
extern void sub_8097418(u32, u32);
extern void sub_802D690(void);
extern void sub_8096C80(void);
extern void sub_8096D24(void);
extern void sub_80141B4(const u8 *, u32, u32, u32);
extern u8 *sub_8096DE8(void);
extern void AcceptJob(struct unkSubStruct_203B2F8 *);
extern void sub_8014248(const char *text, u32, u32, struct MenuItem *r0, u32, u32, u32, u32, u32);
struct unkStruct_803B344 *sub_803B344(u8);
extern void sub_8008C54(u32);
extern void sub_80073B8(u32);
extern void sub_80073E0(u32);
extern void CreateRescueTitle(struct unkStruct_802C39C *);
extern u8 gUnknown_80DFDBC[];
extern void sub_802CF5C(void);
extern void sub_802CFD0(void);
extern void PlayMenuSoundEffect(u32);

extern void sub_802DF24(void);
extern void SetJobListState(u32);
extern u32 sub_802DEE0(void);
extern void ResetJobSlot(u8);
extern u8 HasNoAcceptedJobs(void);
u32 sub_802C598(u8 param_1);
extern void sub_802C688(void);
extern void PlaySound(u32);
extern u8 GetPelipperBoardSlotIndex(void);

extern struct UnkTextStruct2 gUnknown_80DFD8C;
extern struct UnkTextStruct2 gUnknown_80DFDA4;

extern struct unkStruct_203B2F0 *gUnknown_203B2F0;

extern u8 *gUnknown_80D4920[];
extern u8 *gUnknown_80D4928[];
extern u8 *gUnknown_80D494C[];
extern u8 *gUnknown_80D4970[];
extern u8 gUnknown_80DFD70[];
extern u8 gUnknown_80DFD7C[];

extern bool8 sub_809693C(struct WonderMail *);
extern bool8 sub_80A2824(u8);

void sub_802CAA4(void) {
    s32 loopMax;
    struct WonderMail *mail;
    s32 index;

    loopMax = 0;
    mail = GetJobSlotInfo(gUnknown_203B2F0->unkC);
    if(gUnknown_203B2F0->unk0 == 0)
    {
        switch(mail->mailType)
        {
            case 5:
                gUnknown_203B2F0->unk10C[loopMax].text = gUnknown_80DFD70; // Take Job
                if(sub_809693C(mail) || !sub_80A2824(mail->dungeon.id))
                {
                    gUnknown_203B2F0->unk10C[loopMax].menuAction = -1;
                }
                else
                {
                    gUnknown_203B2F0->unk10C[loopMax].menuAction = 2;
                }
                loopMax += 1;
                break;
            case 6:
                gUnknown_203B2F0->unk10C[loopMax].text = gUnknown_80DFD7C; // Suspend
                gUnknown_203B2F0->unk10C[loopMax].menuAction = 3;
                loopMax += 1;
                break;
        }
    }
    gUnknown_203B2F0->unk10C[loopMax].text = *gUnknown_80D494C;
    gUnknown_203B2F0->unk10C[loopMax].menuAction = 4;
    loopMax += 1;
    gUnknown_203B2F0->unk10C[loopMax].text = *gUnknown_80D4970;
    gUnknown_203B2F0->unk10C[loopMax].menuAction = 7;
    loopMax += 1;
    gUnknown_203B2F0->unk10C[loopMax].text = NULL;
    gUnknown_203B2F0->unk10C[loopMax].menuAction = 1;

    for(index = 0; index < loopMax; index++)
    {
        if(gUnknown_203B2F0->unk10C[index].menuAction != -1)
        {
            if(gUnknown_203B2F0->unk10C[index].menuAction == gUnknown_203B2F0->menuAction)
                return;
        }
    }
    gUnknown_203B2F0->menuAction = 7;
}

void sub_802CBAC(void)
{
    s32 loopMax;
    loopMax = 0;

    gUnknown_203B2F0->unk14C[loopMax].text = *gUnknown_80D4920;
    gUnknown_203B2F0->unk14C[loopMax].menuAction = 5;
    loopMax += 1;
    gUnknown_203B2F0->unk14C[loopMax].text = *gUnknown_80D4928;
    gUnknown_203B2F0->unk14C[loopMax].menuAction = 6;
    loopMax += 1;
    gUnknown_203B2F0->unk14C[loopMax].text = NULL;
    gUnknown_203B2F0->unk14C[loopMax].menuAction = 1;
}

void sub_802CC00(void)
{
    switch(sub_802C598(1))
    {
        case 3:
            gUnknown_203B2F0->unkC = GetPelipperBoardSlotIndex();
            SetJobListState(2);
            break;
        case 4:
            gUnknown_203B2F0->unkC = GetPelipperBoardSlotIndex();
            SetJobListState(4);
            break;
        case 0:
        case 1:
            break;
        case 2:
            sub_802C688();
            SetJobListState(5);
            break;
    }
}

void sub_802CC70(void)
{
  s32 menuAction;
  struct WonderMail *mail;
  struct WonderMail *mail2;
  
  menuAction = 0;
  sub_802C598(0);
  if (!sub_8012FD8(&gUnknown_203B2F0->unk6C)) {
    sub_8013114(&gUnknown_203B2F0->unk6C,&menuAction);
    if(menuAction != 1) gUnknown_203B2F0->menuAction = menuAction;
  }
  switch(menuAction)
  {
        case 2:
            PlaySound(0x133);
            mail = GetJobSlotInfo(gUnknown_203B2F0->unkC);
            mail->mailType = MAIL_TYPE_TAKEN_JOB;
            SetJobListState(1);
            break;
        case 3:
            PlaySound(0x133);
            mail2 = GetJobSlotInfo(gUnknown_203B2F0->unkC);
            mail2->mailType = MAIL_TYPE_SUSPENDED_JOB;
            SetJobListState(1);
            break;
        case 4:
            SetJobListState(3);
            break;
        case 7:
            SetJobListState(4);
            break;
        case 1:
            SetJobListState(1);
            break;
  }
}

void sub_802CD38(void)
{
  s32 menuAction;
  
  menuAction = 0;
  sub_802C598(0);
  sub_8012FD8(&gUnknown_203B2F0->unk6C);
  if (!sub_8012FD8(&gUnknown_203B2F0->unkBC)) {
    sub_8013114(&gUnknown_203B2F0->unkBC,&menuAction);
  }
  switch(menuAction)
  {
      case 1:
      case 6:
        SetJobListState(1);
        break;
    case 5:
        ResetJobSlot(gUnknown_203B2F0->unkC);
        sub_8096C80();
        if (HasNoAcceptedJobs()) {
          sub_802C688();
          SetJobListState(5);
        }
        else {
          SetJobListState(1);
        }
        break;
  }
}

void sub_802CDB8(void)
{
    switch(sub_802DEE0())
    {
        case 2:
        case 3:
            sub_802DF24();
            SetJobListState(1);
            break;
        case 0:
        case 1:
            break;
    }
}

bool8 sub_802CDD4(u32 r0)
{
    if(gUnknown_203B2F4 == NULL)
    {
        gUnknown_203B2F4 = MemoryAlloc(sizeof(struct unkStruct_203B2F4), 8);
    }
    gUnknown_203B2F4->unk34 = r0;
    gUnknown_203B2F4->unk38 = &gUnknown_203B2F4->unk3C[gUnknown_203B2F4->unk34];
    sub_8006518(gUnknown_203B2F4->unk3C);
    gUnknown_203B2F4->unk3C[gUnknown_203B2F4->unk34] = gUnknown_80DFDA4;
    gUnknown_203B2F4->unk38->unk14 = gUnknown_203B2F4->unk9C;
    sub_8012D34(gUnknown_203B2F4->unk38, 4);
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B2F4->unk3C, 1, 1);
    sub_8013848(&gUnknown_203B2F4->input, 5, 4, r0);
    sub_802CF5C();
    sub_802CFD0();
    return TRUE;
}

u32 sub_802CE5C(u8 r0)
{
    if(r0 == 0)
    {
        sub_8013660(&gUnknown_203B2F4->input);
        return 0;
    }
    else
    {
        switch(GetKeyPress(&gUnknown_203B2F4->input))
        {
            case INPUT_B_BUTTON:
                PlayMenuSoundEffect(1);
                return 2;
            case INPUT_A_BUTTON:
                return 3;
            default:
                if(sub_80138B8(&gUnknown_203B2F4->input, 1) != 0)
                {
                    sub_802CF5C();
                    sub_802CFD0();
                    return 1;
                }
                else
                {
                    return 0;
                }
        }
    }
}

u8 sub_802CEBC(void)
{
    return (gUnknown_203B2F4->input.unk1E * gUnknown_203B2F4->input.unk1C) + gUnknown_203B2F4->input.menuIndex;
}

void sub_802CED8(u8 r0)
{
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B2F4->unk3C, 0, 0);
    sub_8013984(&gUnknown_203B2F4->input);
    sub_802CF5C();
    sub_802CFD0();
    if(r0)
        AddMenuCursorSprite(&gUnknown_203B2F4->input);
}

void sub_802CF14(void)
{
    if(gUnknown_203B2F4)
    {
        gUnknown_203B2F4->unk3C[gUnknown_203B2F4->unk34] = gUnknown_80DFD8C;
        ResetUnusedInputStruct();
        sub_800641C(gUnknown_203B2F4->unk3C, 1, 1);
        MemoryFree(gUnknown_203B2F4);
        gUnknown_203B2F4 = NULL;
    }
}

NAKED
void sub_802CF5C(void)
{
	asm_unified(
    "\tpush {r4,lr}\n"
	"\tldr r4, _0802CFCC\n"
	"\tldr r0, [r4]\n"
	"\tldrh r1, [r0, 0x20]\n"
	"\tadds r0, 0x9C\n"
	"\tmovs r2, 0\n"
	"\tstrb r1, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tldrh r1, [r0, 0x1E]\n"
	"\tadds r0, 0x9D\n"
	"\tstrb r1, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, 0x9E\n"
	"\tmovs r1, 0xC\n"
	"\tstrb r1, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, 0x9F\n"
	"\tstrb r2, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tmovs r1, 0x1A\n"
	"\tldrsh r0, [r0, r1]\n"
	"\tmovs r1, 0x18\n"
	"\tbl sub_8009614\n"
	"\tadds r0, 0x2\n"
	"\tlsls r0, 16\n"
	"\tldr r2, [r4]\n"
	"\tldr r3, [r2, 0x34]\n"
	"\tlsls r1, r3, 1\n"
	"\tadds r1, r3\n"
	"\tlsls r1, 3\n"
	"\tadds r1, r2, r1\n"
	"\tadds r1, 0x4A\n"
	"\tasrs r3, r0, 16\n"
	"\tlsrs r0, 16\n"
	"\tstrh r0, [r1]\n"
	"\tldr r1, [r2, 0x34]\n"
	"\tlsls r0, r1, 1\n"
	"\tadds r0, r1\n"
	"\tlsls r0, 3\n"
	"\tadds r2, r0\n"
	"\tadds r3, 0x2\n"
	"\tadds r2, 0x4C\n"
	"\tstrh r3, [r2]\n"
	"\tbl ResetUnusedInputStruct\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, 0x3C\n"
	"\tmovs r1, 0x1\n"
	"\tmovs r2, 0x1\n"
	"\tbl sub_800641C\n"
	"\tpop {r4}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_0802CFCC: .4byte gUnknown_203B2F4");
}


void sub_802CFD0(void)
{
  struct unkStruct_802C39C local;    
  struct unkStruct_803B344 *iVar1;
  s32 r5;
  s32 r4;
  
  sub_8008C54(gUnknown_203B2F4->unk34);
  sub_80073B8(gUnknown_203B2F4->unk34);
  r5 = r4 = gUnknown_203B2F4->input.unk1E * 8 + 10;
  xxx_call_draw_string(r5,0,gUnknown_80DFDBC,gUnknown_203B2F4->unk34,0); // RESCUE EVENT
  r4 -= 6;
  r5 = r4 + (gUnknown_203B2F4->unk9C[2] * 8);
  sub_8012BC4(r5,0,gUnknown_203B2F4->input.unk1E + 1,2,7,gUnknown_203B2F4->unk34);

  for(r5 = 0; r5 < gUnknown_203B2F4->input.unk1A; r5++)
  {
        iVar1 = sub_803B344(gUnknown_203B2F4->input.unk1E * gUnknown_203B2F4->input.unk1C + r5);
        local.unk0[0] = gUnknown_203B2F4->unk34;
        local.y = sub_8013800(&gUnknown_203B2F4->input, r5);
        sub_803B35C(&iVar1->mail,&local);
        local.unk43 = 1;
        local.unk4C = iVar1->unk14;
        CreateRescueTitle(&local);
  }
  sub_80073E0(gUnknown_203B2F4->unk34);
}

u32 sub_802D098(struct unkSubStruct_203B2F8 *mail)
{
  gUnknown_203B2F8 = MemoryAlloc(0x208,8);
  gUnknown_203B2F8->menuAction1 = 0;
  gUnknown_203B2F8->menuAction2 = 0;
  gUnknown_203B2F8->menuAction3 = 0;
  gUnknown_203B2F8->mail  = mail;
  gUnknown_203B2F8->wonderMailAccepted = FALSE;
  gUnknown_203B2F8->unk9 = sub_8099328(&gUnknown_203B2F8->dungeonID);
  if (sub_8011C1C() != 2) {
    gUnknown_203B2F8->unk9 = FALSE;
  }
  sub_802D1A0(INITIAL_WONDER_MAIL_CHECK);
  return 1;
}

u32 sub_802D0E0(void)
{
  switch(gUnknown_203B2F8->state) {
    case INITIAL_WONDER_MAIL_CHECK:
        break;
    case 1:
        sub_802D7D0();
        break;
    case DRAW_JOB_LIST:
    case DRAW_JOB_LIST_1:
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
    case WONDER_MAIL_EXIT:
        return 3;
    default:
        AdvancetoFallbackWonderMailRescueState();
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
    s32 index;
    sub_8006518(gUnknown_203B2F8->unk1A8);
    switch(gUnknown_203B2F8->state)
    {
        case 0xD:
           sub_802D5A4();
           gUnknown_203B2F8->unk1A8[2] = gUnknown_80DFE04;
           sub_8012CAC(&gUnknown_203B2F8->unk1A8[2], gUnknown_203B2F8->unk118);
           gUnknown_203B2F8->unk1A8[2].unkC = 6;
           break;
        case 0xE:
           sub_802D63C();
           gUnknown_203B2F8->unk1A8[3] = gUnknown_80DFE1C;
           sub_8012CAC(&gUnknown_203B2F8->unk1A8[3], gUnknown_203B2F8->unk158);
           gUnknown_203B2F8->unk1A8[3].unkC = 6;
           break;
        default:
           for(index = 0; index < 4; index++)
           {
               gUnknown_203B2F8->unk1A8[index] = gUnknown_80DFDD4;
           }
           break;
        case WONDER_MAIL_EXIT:
           break;
    }
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B2F8->unk1A8, 1, 1);
}

void sub_802D2A8(void)
{
  
  switch(gUnknown_203B2F8->state) {
      case INITIAL_WONDER_MAIL_CHECK:
        if (IsMailinJobSlot(&gUnknown_203B2F8->mail->wonderMail)) {
            sub_802D1A0(DUPLICATE_WONDER_MAIL);
        }
        else if (sub_8096F50(&gUnknown_203B2F8->mail->wonderMail) != 0) {
            sub_802D1A0(DUPLICATE_WONDER_MAIL_1);
        }
        else if ((gUnknown_203B2F8->mail->wonderMail.unk2 == 4) && (sub_8096C08(&gUnknown_203B2F8->jobSlotIndex) != 0)) {
            if (sub_802DAA8() != 0) {
                sub_802D1A0(9);
            }
            else {
                sub_802D1A0(5);
            }
        }
        else if (GetNumAcceptedJobs() >= MAX_ACCEPTED_JOBS) {
            if (sub_802DADC() != 0) {
                sub_802D1A0(JOB_LIST_FULL);
            }
            else {
                sub_802D1A0(6);
            }
        }
        else
            sub_802D1A0(RECEIVE_WONDER_MAIL);
        break;
      case 1:
        sub_802D73C();
        sub_8014248(gUnknown_80DFE4C,0,gUnknown_203B2F8->menuAction2,gUnknown_203B2F8->unk158,0,4,0,0,0);
        break;
      case DUPLICATE_WONDER_MAIL:
        gUnknown_203B2F8->fallbackState = WONDER_MAIL_EXIT;
        sub_80141B4(gUnknown_80DFE9C,0,0,0x101);
        break;
      case DUPLICATE_WONDER_MAIL_1:
        gUnknown_203B2F8->fallbackState = WONDER_MAIL_EXIT;
        sub_80141B4(gUnknown_80DFED0,0,0,0x101);
        break;
      case 5:
        gUnknown_203B2F8->fallbackState = WONDER_MAIL_EXIT;
        sub_80141B4(gUnknown_80DFF2C,0,0,0x101);
        break;
      case 6:
        gUnknown_203B2F8->fallbackState = WONDER_MAIL_EXIT;
        sub_80141B4(gUnknown_80DFFA4,0,0,0x101);
        break;
      case 7:
        gUnknown_203B2F8->fallbackState = DRAW_JOB_LIST_1;
        sub_80141B4(gUnknown_80E0010,0,0,0x101);
        break;
      case RECEIVE_WONDER_MAIL:
        gUnknown_203B2F8->wonderMailAccepted = TRUE;
        AcceptJob(gUnknown_203B2F8->mail);
        sub_8096C80();
        sub_8096D24();
        if (gUnknown_203B2F8->mail->wonderMail.unk2 == 4) {
          MemoryCopy8(sub_8096DD8(),gUnknown_203B2F8->mail->unk14,0x28);
          MemoryCopy8(sub_8096DE8(),gUnknown_203B2F8->mail->unk18,0x78);
        }
        switch(gUnknown_203B2F8->mail->wonderMail.dungeon.id)
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
        gUnknown_203B2F8->fallbackState = WONDER_MAIL_EXIT;
        sub_80141B4(gReceivedWonderMail,0,0,0x101);
        break;
      case 9:
        sub_802D690();
        sub_8014248(gUnknown_80E0094,0,gUnknown_203B2F8->menuAction3,gUnknown_203B2F8->unk158,0,4,0,0,0);
        break;
      case JOB_LIST_FULL:
        gUnknown_203B2F8->fallbackState = DRAW_JOB_LIST;
        sub_80141B4(gUnknown_80E0108,0,0,0x101);
        break;
      case DRAW_JOB_LIST:
        sub_802C4C8(0,0,4);
        break;
      case DRAW_JOB_LIST_1:
        sub_802C640(1);
        break;
      case 0xd:
        DrawJobListMenu();
        sub_8012D60(&gUnknown_203B2F8->unk78,gUnknown_203B2F8->unk118,0,gUnknown_203B2F8->unk198,
                    gUnknown_203B2F8->menuAction1,2);
        break;
      case 0xe:
        DrawJobListMenu();
        sub_8012EA4(&gUnknown_203B2F8->unk78,0);
        sub_8012D60(&gUnknown_203B2F8->unkC8,gUnknown_203B2F8->unk158,0,0,4,3);
        break;
      case 0xf:
        sub_803B35C(GetJobSlotInfo(gUnknown_203B2F8->jobSlotIndex),&gUnknown_203B2F8->unk14);
        gUnknown_203B2F8->unk14.unk0[0] = 3;
        sub_802DE84(&gUnknown_203B2F8->unk14);
        break;
      case 0x10:
        sub_803B35C(&gUnknown_203B2F8->mail->wonderMail,&gUnknown_203B2F8->unk14);
        gUnknown_203B2F8->unk14.unk0[0] = 3;
        gUnknown_203B2F8->unk14.unk44 = 0;
        gUnknown_203B2F8->unk14.unk50[0] = gUnknown_203B2F8->mail->unk18;
        sub_802DE84(&gUnknown_203B2F8->unk14);
        break;
  }
}

void sub_802D5A4(void) {
    s32 loopMax;
    s32 index;

    loopMax = 0;
    MemoryFill16(gUnknown_203B2F8->unk198, 0, sizeof(gUnknown_203B2F8->unk198));
    gUnknown_203B2F8->unk118[loopMax].text = *gUnknown_80D494C;
    gUnknown_203B2F8->unk118[loopMax].menuAction = 2;
    loopMax += 1;
    gUnknown_203B2F8->unk118[loopMax].text = *gUnknown_80D4970;
    gUnknown_203B2F8->unk118[loopMax].menuAction = 5;
    loopMax += 1;
    gUnknown_203B2F8->unk118[loopMax].text = NULL;
    gUnknown_203B2F8->unk118[loopMax].menuAction = 1;

    for(index = 0; index < loopMax; index++)
    {
        if (gUnknown_203B2F8->unk198[index] == 0) {
            if(gUnknown_203B2F8->unk118[index].menuAction == gUnknown_203B2F8->menuAction1)
                return;
        }
    }
    gUnknown_203B2F8->menuAction1 = 2;
}

void sub_802D63C(void) {
    s32 loopMax = 0;
    gUnknown_203B2F8->unk158[loopMax].text = *gUnknown_80D4920;
    gUnknown_203B2F8->unk158[loopMax].menuAction = 3;
    loopMax += 1;
    gUnknown_203B2F8->unk158[loopMax].text = *gUnknown_80D4928;
    gUnknown_203B2F8->unk158[loopMax].menuAction = 4;
    loopMax += 1;
    gUnknown_203B2F8->unk158[loopMax].text = NULL;
    gUnknown_203B2F8->unk158[loopMax].menuAction = 1;
}

void sub_802D690(void) {
    s32 loopMax;
    s32 index;

    loopMax = 0;
    gUnknown_203B2F8->unk158[loopMax].text = *gUnknown_80D4920;
    gUnknown_203B2F8->unk158[loopMax].menuAction = 3;
    loopMax += 1;
    gUnknown_203B2F8->unk158[loopMax].text = *gUnknown_80D4928;
    gUnknown_203B2F8->unk158[loopMax].menuAction = 4;
    loopMax += 1;
    gUnknown_203B2F8->unk158[loopMax].text = gUnknown_80E014C;
    gUnknown_203B2F8->unk158[loopMax].menuAction = 6;
    loopMax += 1;
    gUnknown_203B2F8->unk158[loopMax].text = gUnknown_80E0158;
    gUnknown_203B2F8->unk158[loopMax].menuAction = 7;
    loopMax += 1;
    gUnknown_203B2F8->unk158[loopMax].text = NULL;
    gUnknown_203B2F8->unk158[loopMax].menuAction = 1;

    for(index = 0; index < loopMax; index++)
    {
        if(gUnknown_203B2F8->unk158[index].menuAction == gUnknown_203B2F8->menuAction3)
            return;
    }
    gUnknown_203B2F8->menuAction3 = 4;
}

void sub_802D73C(void) {
    s32 loopMax;
    s32 index;

    loopMax = 0;
    gUnknown_203B2F8->unk158[loopMax].text = *gUnknown_80D4920;
    gUnknown_203B2F8->unk158[loopMax].menuAction = 3;
    loopMax += 1;
    gUnknown_203B2F8->unk158[loopMax].text = *gUnknown_80D4928;
    gUnknown_203B2F8->unk158[loopMax].menuAction = 4;
    loopMax += 1;
    gUnknown_203B2F8->unk158[loopMax].text = gUnknown_80E014C;
    gUnknown_203B2F8->unk158[loopMax].menuAction = 6;
    loopMax += 1;
    gUnknown_203B2F8->unk158[loopMax].text = NULL;
    gUnknown_203B2F8->unk158[loopMax].menuAction = 1;

    for(index = 0; index < loopMax; index++)
    {
        if(gUnknown_203B2F8->unk158[index].menuAction == gUnknown_203B2F8->menuAction2)
            return;
    }
    gUnknown_203B2F8->menuAction2 = 4;
}

extern s32 sub_80144A4(s32 *);


void sub_802D7D0(void)
{
  s32 menuAction;

  if (sub_80144A4(&menuAction) == 0) {
    if (menuAction != 1) {
      gUnknown_203B2F8->menuAction2 = menuAction;
    }
    switch(menuAction) {
        // Yes
        case 3:
            sub_802D1A0(WONDER_MAIL_EXIT);
            break;
        // New Mail
        case 6:
            gUnknown_203B2F8->fallbackState = 1;
            sub_802D1A0(0x10);
            break;
        // No
        case 4:
        case 2:
        default:
            sub_802D1A0(INITIAL_WONDER_MAIL_CHECK);
            break;
    }
  }
}

void sub_802D82C(void)
{
  s32 menuAction;

  if (sub_80144A4(&menuAction) == 0) {
    if (menuAction != 1) {
      gUnknown_203B2F8->menuAction3 = menuAction;
    }
    switch(menuAction) {
        // Yes
        case 3:
            ResetJobSlot(gUnknown_203B2F8->jobSlotIndex);
            sub_8096C80();
            sub_802D1A0(RECEIVE_WONDER_MAIL);
            break;
        // New Mail
        case 6:
            gUnknown_203B2F8->fallbackState = 9;
            sub_802D1A0(0x10);
            break;
        // Old Mail
        case 7:
            gUnknown_203B2F8->fallbackState = 9;
            sub_802D1A0(0xf);
            break;
        // No
        default:
        case 1:
        case 2:
        case 4:
            sub_802D1A0(1);
            break;
    }
  }
}

void sub_802D8CC(void)
{
  switch(sub_802C598(1)) {
    case 0:
    case 1:
        break;
    case 3:
        gUnknown_203B2F8->jobSlotIndex = GetPelipperBoardSlotIndex();
        sub_802D1A0(0xd);
        break;
    case 4:
        gUnknown_203B2F8->jobSlotIndex = GetPelipperBoardSlotIndex();
        gUnknown_203B2F8->fallbackState = DRAW_JOB_LIST_1;
        sub_802D1A0(0xf);
        break;
    case 2:
        sub_802C688();
        sub_802D1A0(1);
        break;
  }
}

void sub_802D940(void)
{
  struct WonderMail *mail;
  s32 menuAction;
  
  menuAction = 0;
  sub_802C598(0);
  if ((sub_8012FD8(&gUnknown_203B2F8->unk78) == 0) && (sub_8013114(&gUnknown_203B2F8->unk78,&menuAction), menuAction != 1)) {
    gUnknown_203B2F8->menuAction1 = menuAction;
  }

  switch(menuAction)
  {
    // Delete
    case 2:
        if ((gUnknown_203B2F8->unk9) && (((mail = &gUnknown_203B490->jobSlots[gUnknown_203B2F8->jobSlotIndex]), mail->mailType > MAIL_TYPE_SUSPENDED_JOB) && (gUnknown_203B2F8->dungeonID == mail->dungeon.id)))
        {
            sub_802D1A0(7);
        }
        else {
            sub_802D1A0(0xE);
        }
        break;
    // Info
    case 5:
        gUnknown_203B2F8->fallbackState = DRAW_JOB_LIST_1;
        sub_802D1A0(0xf);
        break;
    case 1:
        sub_802D1A0(DRAW_JOB_LIST_1);
        break;
  }
}

void sub_802D9F0(void)
{
  s32 menuAction;
  
  menuAction = 0;
  sub_802C598(0);
  sub_8012FD8(&gUnknown_203B2F8->unk78);
  if (sub_8012FD8(&gUnknown_203B2F8->unkC8) == 0) {
    sub_8013114(&gUnknown_203B2F8->unkC8,&menuAction);
  }

  switch(menuAction)
  {
    // No
    case 1:
    case 4:
        sub_802D1A0(DRAW_JOB_LIST_1);
        break;
    // Yes
    case 3:
        sub_802C688();
        ResetJobSlot(gUnknown_203B2F8->jobSlotIndex);
        sub_8096C80();
        sub_802D1A0(RECEIVE_WONDER_MAIL);
        break;
  }
}

void sub_802DA60(void)
{
    switch(sub_802DEE0())
    {
        case 2:
        case 3:
            sub_802DF24();
            sub_802D1A0(gUnknown_203B2F8->fallbackState);
            break;
        case 0:
        case 1:
            break;
    }
}

void AdvancetoFallbackWonderMailRescueState(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        sub_802D1A0(gUnknown_203B2F8->fallbackState);
    }
}

bool8 sub_802DAA8(void)
{
  struct WonderMail *mail;
  
  mail = GetJobSlotInfo(gUnknown_203B2F8->jobSlotIndex);
  if (!gUnknown_203B2F8->unk9) {
    return TRUE;
  }
  else {
    if ( (mail->mailType != WONDER_MAIL_TYPE_THANK_YOU) && (gUnknown_203B2F8->dungeonID == mail->dungeon.id)) return FALSE;
    return TRUE;
  }
}

bool8 sub_802DADC(void)
{
  u8 mailType;
  struct WonderMail *mail;
  s32 counter;
  
  if (!gUnknown_203B2F8->unk9) {
_0802DAE8:
    return TRUE;
  }
  else {
    for( mail = &gUnknown_203B490->jobSlots[0], counter = 0; counter < MAX_ACCEPTED_JOBS; mail++, counter++)
    {
      mailType = mail->mailType;
      if (((mailType == 0) || (mailType == WONDER_MAIL_TYPE_THANK_YOU)) ||
         ((WONDER_MAIL_TYPE_THANK_YOU < mailType && (gUnknown_203B2F8->dungeonID != mail->dungeon.id)))) goto _0802DAE8;
    }
    return FALSE;
  }
}

