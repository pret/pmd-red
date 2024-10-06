#include "global.h"
#include "globaldata.h"
#include "code_80118A4.h"
#include "code_8094F88.h"
#include "constants/input.h"
#include "constants/wonder_mail.h"
#include "input.h"
#include "items.h"
#include "memory.h"
#include "menu_input.h"
#include "pokemon.h"
#include "pokemon_mail.h"
#include "structs/str_802C39C.h"
#include "text1.h"
#include "text2.h"
#include "structs/struct_sub80095e4.h"
#include "wonder_mail_4.h"

struct unkStruct_203B320
{
    // size: 0xC4
    u8 unk0[0x20];
    u32 wonderMailType;
    struct_Sub80095E4_2 s28;
};
static EWRAM_DATA_2 struct unkStruct_203B320 *gUnknown_203B320 = {0};

extern unkStruct_203B480 *gUnknown_203B480;

const UnkTextStruct2 gUnknown_80E083C = {
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    NULL
};

const UnkTextStruct2 gUnknown_80E0854 = {
    0x00, 0x00, 0x00, 0x00,
    0x06,
    0x02, 0x02,
    0x18, 0x11,
    0x11, 0x00,
    NULL
};

extern const u8 SOSList[];
extern const u8 RequestList[];
extern const u8 SOSMail[];
extern const u8 ToDoList[];
extern const u8 AOKMail[];
extern const u8 ThanksList[];
extern const u8 CompletedJobs[];
extern const u8 OkdRescue[];

const u8 * const gUnknown_80E086C[MAX_WONDER_MAIL_TYPES] =
{
    SOSList,
    RequestList,
    SOSMail,
    ToDoList,
    AOKMail,
    ThanksList,
    CompletedJobs,
    OkdRescue
};

ALIGNED(4) const u8 OkdRescue[] = _("OK{APOSTROPHE}d Rescues");
ALIGNED(4) const u8 CompletedJobs[] = "Completed Jobs";
ALIGNED(4) const u8 ThanksList[] = "Thanks List";
ALIGNED(4) const u8 AOKMail[] = "A-OK Mail";
ALIGNED(4) const u8 ToDoList[] = "To-Do List";
ALIGNED(4) const u8 SOSMail[] = "SOS Mail";
ALIGNED(4) const u8 RequestList[] = "Request List";
ALIGNED(4) const u8 SOSList[] = "SOS List";

s32 sub_8030A74(void);
void sub_80308A0(void);

u32 sub_80306A8(u32 wonderMailType, u32 r1, UnkTextStruct2_sub *r2, u32 r3)
{
    if (HasNoWonderMailType(wonderMailType))
        return 0;

    gUnknown_203B320 = MemoryAlloc(sizeof(struct unkStruct_203B320), 8);
    gUnknown_203B320->wonderMailType = wonderMailType;
    gUnknown_203B320->s28.s0.unk34 = r1;

    gUnknown_203B320->s28.s0.unk38 = &gUnknown_203B320->s28.s0.unk3C[gUnknown_203B320->s28.s0.unk34];
    RestoreUnkTextStruct_8006518(gUnknown_203B320->s28.s0.unk3C);

    gUnknown_203B320->s28.s0.unk3C[gUnknown_203B320->s28.s0.unk34] = gUnknown_80E0854;
    gUnknown_203B320->s28.s0.unk38->unk14 = &gUnknown_203B320->s28.unk9C;

    if (r2 != 0)
        gUnknown_203B320->s28.s0.unk3C[gUnknown_203B320->s28.s0.unk34].unk8 = *r2;

    sub_8012D08(gUnknown_203B320->s28.s0.unk38, r3);
    ResetUnusedInputStruct();
    xxx_call_save_unk_text_struct_800641C(gUnknown_203B320->s28.s0.unk3C, TRUE, TRUE);
    sub_8013818(&gUnknown_203B320->s28.s0.input, sub_8030A74(), r3, r1);
    sub_80308A0();
    sub_803092C();
    return 1;
}

u32 sub_8030768(u8 r0)
{
    if(r0 == 0)
    {
        sub_8013660(&gUnknown_203B320->s28.s0.input);
        return 0;
    }
    switch(GetKeyPress(&gUnknown_203B320->s28.s0.input))
    {
        case INPUT_START_BUTTON:
            PlayMenuSoundEffect(4);
            return 4;
        case INPUT_B_BUTTON:
            PlayMenuSoundEffect(1);
            return 2;
        case INPUT_A_BUTTON:
            PlayMenuSoundEffect(0);
            return 3;
        default:
            if(sub_80138B8(&gUnknown_203B320->s28.s0.input, TRUE) != 0)
            {
                sub_80308A0();
                sub_803092C();
                return 1;
            }
            else
                return 0;
    }
}

u8 sub_80307EC(void)
{
    return gUnknown_203B320->unk0[(gUnknown_203B320->s28.s0.input.unk1E * gUnknown_203B320->s28.s0.input.unk1C) + gUnknown_203B320->s28.s0.input.menuIndex];
}

void sub_8030810(u8 r0)
{
    gUnknown_203B320->s28.s0.input.unk22 = sub_8030A74();
    sub_8013984(&gUnknown_203B320->s28.s0.input);

    sub_80308A0();
    sub_803092C();
    if(r0 != 0)
        AddMenuCursorSprite(&gUnknown_203B320->s28.s0.input);
}

void sub_803084C(void)
{
    if(gUnknown_203B320 != NULL)
    {
        gUnknown_203B320->s28.s0.unk3C[gUnknown_203B320->s28.s0.unk34] = gUnknown_80E083C;
        ResetUnusedInputStruct();
        xxx_call_save_unk_text_struct_800641C(gUnknown_203B320->s28.s0.unk3C, TRUE, TRUE);
        MemoryFree(gUnknown_203B320);
        gUnknown_203B320 = NULL;
    }
}

u8 *sub_8030894(void)
{
    return gUnknown_203B320->unk0;
}

void sub_80308A0(void)
{
    gUnknown_203B320->s28.unk9C.f0 = gUnknown_203B320->s28.s0.input.unk20;
    gUnknown_203B320->s28.unk9C.f1 = gUnknown_203B320->s28.s0.input.unk1E;
    gUnknown_203B320->s28.unk9C.f2 = 12;
    gUnknown_203B320->s28.unk9C.f3 = 0;
    ResetUnusedInputStruct();
    xxx_call_save_unk_text_struct_800641C(gUnknown_203B320->s28.s0.unk3C, TRUE, TRUE);

    SUB_80095E4_CALL(gUnknown_203B320->s28.s0);
}

void sub_803092C(void)
{
  unkStruct_203B480 *mail;
  s32 r4;
  s32 r5;
  s32 index;
  unkStruct_802C39C local;

  CallPrepareTextbox_8008C54(gUnknown_203B320->s28.s0.unk34);
  sub_80073B8(gUnknown_203B320->s28.s0.unk34);
  r4 = gUnknown_203B320->s28.s0.input.unk1E * 8;
  r5 = r4;
  r5 += 10;
  PrintStringOnWindow(r5,0,gUnknown_80E086C[gUnknown_203B320->wonderMailType],gUnknown_203B320->s28.s0.unk34,0);
  r4 += 4;
  r5 = r4 + gUnknown_203B320->s28.unk9C.f2 * 8;
  sub_8012BC4(r5,0,gUnknown_203B320->s28.s0.input.unk1E + 1,1,7,gUnknown_203B320->s28.s0.unk34);

  for (index = 0; index < gUnknown_203B320->s28.s0.input.unk1A; index++) {
      mail = GetMailatIndex(gUnknown_203B320->unk0[(gUnknown_203B320->s28.s0.input.unk1E * gUnknown_203B320->s28.s0.input.unk1C) + index]);
      local.unk0[0] = gUnknown_203B320->s28.s0.unk34;
      local.y = sub_8013800(&gUnknown_203B320->s28.s0.input,index);
      local.mailTitleType = 7;
      local.mailMissionType = MISSION_TYPE_FRIEND_RESCUE;
      local.mailStatus = MAIL_STATUS_SUSPENDED;

      local.unk8 = &mail->unk4;
      local.playerName = mail->playerName;

      local.clientSpecies = mail->clientSpecies;
      local.targetSpecies = mail->clientSpecies;
      local.targetItem = ITEM_NOTHING;
      local.rewardType = MONEY1;

      switch(mail->mailType)
      {
        case WONDER_MAIL_TYPE_AOK:
            local.unk43 = 3;
            break;
        case WONDER_MAIL_TYPE_THANK_YOU:
            local.unk43 = 4;
            break;
        case WONDER_MAIL_TYPE_SOS:
        case WONDER_MAIL_TYPE_SOS_1:
            local.unk43 = 1;
            break;
        default:
            local.unk43 = 0;
            break;
      }
      CreateRescueTitle(&local);
  }
  sub_80073E0(gUnknown_203B320->s28.s0.unk34);
}

s32 sub_8030A74(void)
{
  s32 index;
  s32 count = 0;
  switch(gUnknown_203B320->wonderMailType) {
    case WONDER_MAIL_TYPE_NONE:
        for (index = 0; index < 0x20; index++)
        {
            unkStruct_203B480 *p = gUnknown_203B480 + index;
            if (p->mailType != WONDER_MAIL_TYPE_NONE) {
                gUnknown_203B320->unk0[count] = index;
                count++;
            }
        }
        break;
    case WONDER_MAIL_TYPE_COMPLETED:
        for (index = 0; index < 0x20; index++)
        {
            unkStruct_203B480 *p = gUnknown_203B480 + index;
            if (p->mailType == WONDER_MAIL_TYPE_COMPLETED) {
                gUnknown_203B320->unk0[count] = index;
                count++;
            }
        }
        break;
    case WONDER_MAIL_TYPE_SOS:
        for (index = 0; index < 0x20; index++)
        {
            unkStruct_203B480 *p = gUnknown_203B480 + index;
            if (p->mailType == WONDER_MAIL_TYPE_SOS) {
                gUnknown_203B320->unk0[count] = index;
                count++;
            }
        }
        break;
    case WONDER_MAIL_TYPE_SOS_1:
        for (index = 0; index < 0x20; index++)
        {
            unkStruct_203B480 *p = gUnknown_203B480 + index;
            if (p->mailType == WONDER_MAIL_TYPE_SOS_1) {
                gUnknown_203B320->unk0[count] = index;
                count++;
            }
        }
        break;
    case WONDER_MAIL_TYPE_AOK:
        for (index = 0; index < 0x20; index++)
        {
            unkStruct_203B480 *p = gUnknown_203B480 + index;
            if (p->mailType == WONDER_MAIL_TYPE_AOK) {
                gUnknown_203B320->unk0[count] = index;
                count++;
            }
        }
        break;
    case 3:
        for (index = 0; index < 0x20; index++)
        {
            unkStruct_203B480 *p = gUnknown_203B480 + index;
            if (p->mailType == 3) {
                gUnknown_203B320->unk0[count] = index;
                count++;
            }
        }
        break;
    case WONDER_MAIL_TYPE_THANK_YOU:
        for (index = 0; index < 0x20; index++)
        {
            unkStruct_203B480 *p = gUnknown_203B480 + index;
            if (p->mailType == WONDER_MAIL_TYPE_THANK_YOU) {
                gUnknown_203B320->unk0[count] = index;
                count++;
            }
        }
        break;

    case WONDER_MAIL_TYPE_OKD:
        for (index = 0; index < 0x20; index++)
        {
            unkStruct_203B480 *p = gUnknown_203B480 + index;
            if (p->mailType == WONDER_MAIL_TYPE_OKD) {
                gUnknown_203B320->unk0[count] = index;
                count++;
            }
        }
        break;
  }
  return count;
}

bool8 HasNoWonderMailType(u32 wonderMailType)
{
  s32 index;

  switch(wonderMailType) {
    case WONDER_MAIL_TYPE_NONE:
        for (index = 0; index < 0x20; index++)
        {
            if (gUnknown_203B480[index].mailType != WONDER_MAIL_TYPE_NONE) {
                return FALSE;
            }
        }
        break;
    case WONDER_MAIL_TYPE_COMPLETED:
        for (index = 0; index < 0x20; index++)
        {
            if (gUnknown_203B480[index].mailType == WONDER_MAIL_TYPE_COMPLETED) {
                return FALSE;
            }
        }
        break;
    case WONDER_MAIL_TYPE_SOS:
        for (index = 0; index < 0x20; index++)
        {
            if (gUnknown_203B480[index].mailType == WONDER_MAIL_TYPE_SOS) {
                return FALSE;
            }
        }
        break;
    case WONDER_MAIL_TYPE_SOS_1:
        for (index = 0; index < 0x20; index++)
        {
            if (gUnknown_203B480[index].mailType == WONDER_MAIL_TYPE_SOS_1) {
                return FALSE;
            }
        }
        break;
    case WONDER_MAIL_TYPE_AOK:
        for (index = 0; index < 0x20; index++)
        {
            if (gUnknown_203B480[index].mailType == WONDER_MAIL_TYPE_AOK) {
                return FALSE;
            }
        }
        break;
    case 3:
        for (index = 0; index < 0x20; index++)
        {
            if (gUnknown_203B480[index].mailType == 3) {
                return FALSE;
            }
        }
        break;

    case WONDER_MAIL_TYPE_THANK_YOU:
        for (index = 0; index < 0x20; index++)
        {
            if (gUnknown_203B480[index].mailType == WONDER_MAIL_TYPE_THANK_YOU) {
                return FALSE;
            }
        }
        break;

    case WONDER_MAIL_TYPE_OKD:
        for (index = 0; index < 0x20; index++)
        {
            if (gUnknown_203B480[index].mailType == WONDER_MAIL_TYPE_OKD) {
                return FALSE;
            }
        }
        break;
  }
  return TRUE;
}
