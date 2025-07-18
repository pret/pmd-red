#include "global.h"
#include "globaldata.h"
#include "constants/input.h"
#include "constants/wonder_mail.h"
#include "structs/str_802C39C.h"
#include "text_3.h"
#include "music_util.h"
#include "code_8094F88.h"
#include "input.h"
#include "items.h"
#include "memory.h"
#include "menu_input.h"
#include "pokemon.h"
#include "pokemon_mail.h"
#include "text_1.h"
#include "text_2.h"
#include "wonder_mail_4.h"

struct unkStruct_203B320
{
    // size: 0xC4
    u8 unk0[0x20];
    u32 wonderMailType;
    MenuHeaderWindow s28;
};
static EWRAM_INIT struct unkStruct_203B320 *gUnknown_203B320 = {NULL};

extern unkStruct_203B480 *gUnknown_203B480;

const WindowTemplate gUnknown_80E083C = {
    0,
    0x03,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    NULL
};

const WindowTemplate gUnknown_80E0854 = {
    0,
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

ALIGNED(4) const u8 OkdRescue[] = _("OK'd Rescues");
ALIGNED(4) const u8 CompletedJobs[] = "Completed Jobs";
ALIGNED(4) const u8 ThanksList[] = "Thanks List";
ALIGNED(4) const u8 AOKMail[] = "A-OK Mail";
ALIGNED(4) const u8 ToDoList[] = "To-Do List";
ALIGNED(4) const u8 SOSMail[] = "SOS Mail";
ALIGNED(4) const u8 RequestList[] = "Request List";
ALIGNED(4) const u8 SOSList[] = "SOS List";

s32 sub_8030A74(void);
void sub_80308A0(void);

u32 sub_80306A8(u32 wonderMailType, u32 r1, DungeonPos *r2, u32 r3)
{
    if (HasNoWonderMailType(wonderMailType))
        return 0;

    gUnknown_203B320 = MemoryAlloc(sizeof(struct unkStruct_203B320), 8);
    gUnknown_203B320->wonderMailType = wonderMailType;
    gUnknown_203B320->s28.m.menuWinId = r1;

    gUnknown_203B320->s28.m.menuWindow = &gUnknown_203B320->s28.m.windows.id[gUnknown_203B320->s28.m.menuWinId];
    RestoreSavedWindows(&gUnknown_203B320->s28.m.windows);

    gUnknown_203B320->s28.m.windows.id[gUnknown_203B320->s28.m.menuWinId] = gUnknown_80E0854;
    gUnknown_203B320->s28.m.menuWindow->header = &gUnknown_203B320->s28.header;

    if (r2 != 0)
        gUnknown_203B320->s28.m.windows.id[gUnknown_203B320->s28.m.menuWinId].pos = *r2;

    sub_8012D08(gUnknown_203B320->s28.m.menuWindow, r3);
    ResetUnusedInputStruct();
    ShowWindows(&gUnknown_203B320->s28.m.windows, TRUE, TRUE);
    CreateMenuOnWindow(&gUnknown_203B320->s28.m.input, sub_8030A74(), r3, r1);
    sub_80308A0();
    sub_803092C();
    return 1;
}

u32 sub_8030768(u8 r0)
{
    if(r0 == 0)
    {
        sub_8013660(&gUnknown_203B320->s28.m.input);
        return 0;
    }
    switch(GetKeyPress(&gUnknown_203B320->s28.m.input))
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
            if(MenuCursorUpdate(&gUnknown_203B320->s28.m.input, TRUE) != 0)
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
    return gUnknown_203B320->unk0[GET_CURRENT_MENU_ENTRY(gUnknown_203B320->s28.m.input)];
}

void sub_8030810(u8 r0)
{
    gUnknown_203B320->s28.m.input.totalEntriesCount = sub_8030A74();
    MenuUpdatePagesData(&gUnknown_203B320->s28.m.input);

    sub_80308A0();
    sub_803092C();
    if(r0 != 0)
        AddMenuCursorSprite(&gUnknown_203B320->s28.m.input);
}

void sub_803084C(void)
{
    if(gUnknown_203B320 != NULL)
    {
        gUnknown_203B320->s28.m.windows.id[gUnknown_203B320->s28.m.menuWinId] = gUnknown_80E083C;
        ResetUnusedInputStruct();
        ShowWindows(&gUnknown_203B320->s28.m.windows, TRUE, TRUE);
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
    gUnknown_203B320->s28.header.count = gUnknown_203B320->s28.m.input.pagesCount;
    gUnknown_203B320->s28.header.currId = gUnknown_203B320->s28.m.input.currPage;
    gUnknown_203B320->s28.header.width = 12;
    gUnknown_203B320->s28.header.f3 = 0;
    ResetUnusedInputStruct();
    ShowWindows(&gUnknown_203B320->s28.m.windows, TRUE, TRUE);

    UPDATE_MENU_WINDOW_HEIGHT(gUnknown_203B320->s28.m);
}

void sub_803092C(void)
{
  unkStruct_203B480 *mail;
  s32 r4;
  s32 r5;
  s32 index;
  unkStruct_802C39C local;

  CallPrepareTextbox_8008C54(gUnknown_203B320->s28.m.menuWinId);
  sub_80073B8(gUnknown_203B320->s28.m.menuWinId);
  r4 = gUnknown_203B320->s28.m.input.currPage * 8;
  r5 = r4;
  r5 += 10;
  PrintStringOnWindow(r5,0,gUnknown_80E086C[gUnknown_203B320->wonderMailType],gUnknown_203B320->s28.m.menuWinId,0);
  r4 += 4;
  r5 = r4 + gUnknown_203B320->s28.header.width * 8;
  PrintNumOnWindow(r5,0,gUnknown_203B320->s28.m.input.currPage + 1,1,7,gUnknown_203B320->s28.m.menuWinId);

  for (index = 0; index < gUnknown_203B320->s28.m.input.currPageEntries; index++) {
      mail = GetMailatIndex(gUnknown_203B320->unk0[(gUnknown_203B320->s28.m.input.currPage * gUnknown_203B320->s28.m.input.entriesPerPage) + index]);
      local.unk0[0] = gUnknown_203B320->s28.m.menuWinId;
      local.y = GetMenuEntryYCoord(&gUnknown_203B320->s28.m.input,index);
      local.mailTitleType = 7;
      local.mailMissionType = MISSION_TYPE_FRIEND_RESCUE;
      local.mailStatus = MAIL_STATUS_SUSPENDED;

      local.dungeonSeed = &mail->dungeonSeed;
      local.playerName = mail->playerName;

      local.clientSpecies = mail->clientSpecies;
      local.targetSpecies = mail->clientSpecies;
      local.targetItem = ITEM_NOTHING;
      local.unk18.rewardType = MONEY1;

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
  sub_80073E0(gUnknown_203B320->s28.m.menuWinId);
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
