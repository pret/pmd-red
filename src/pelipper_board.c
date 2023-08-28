#include "global.h"
#include "mailbox.h"
#include "pokemon.h"
#include "item.h"
#include "memory.h"
#include "text1.h"
#include "text2.h"
#include "menu.h"
#include "input.h"
#include "wonder_mail.h"
#include "menu_input.h"
#include "team_inventory.h"
#include "pelipper_board.h"
#include "code_80118A4.h"

EWRAM_DATA_2 struct unkStruct_203B308 *gPelipperBoard = {0};

const struct UnkTextStruct2 gUnknown_80E0330 =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    NULL
};

const struct UnkTextStruct2 gUnknown_80E0348 =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x03, 0x03,
    0x07, 0x03,
    0x03, 0x00,
    NULL
};

const struct UnkTextStruct2 gUnknown_80E0360 =
{
    0x00, 0x00, 0x00, 0x00,
    0x04,
    0x15, 0x06,
    0x07, 0x03,
    0x03, 0x00,
    NULL
};

const struct UnkTextStruct2 gUnknown_80E0378 =
{
    0x00, 0x00, 0x00, 0x00,
    0x04,
    0x15, 0x0f,
    0x06, 0x03,
    0x03, 0x00,
    NULL
};

const u8 gPelipperBoard_BulletinBoard[] = "Bulletin Board";
const u8 gPelipperBoard_JobList[] = "Job List";
const u8 gPelipperBoard_Accepted[] = "Accepted";
const u8 gPelipperStatusSlash[] = "/";
static const u8 sPelipperfill[] = "pksdir0";

extern void sub_802ECB4(void);
extern void nullsub_134(void);
extern void sub_802ED4C(void);
extern void sub_802EDBC(void);
extern void sub_802EEA0(void);
extern void sub_802EEBC(void);
extern void sub_802E94C(void);
extern void sub_802EA58(void);
extern void CreatePelipperBoardMenu(void);
extern void sub_802EC10(void);

extern void sub_802C10C(u32, u32, u32);
extern void sub_802C28C(u32);
extern void DrawPelipperBoardJobMenu(void);
extern void CreatePelipperAcceptedStatusBox(u32);
extern void sub_803B35C(struct WonderMail *, struct unkStruct_802C39C *);
extern void sub_802DE84(struct unkStruct_802C39C *);
extern void InitializeJobListMenu(u32);

extern u32 sub_802C898(void);
extern void sub_802C8F4(void);
extern u32 sub_802DEE0(void);
extern void sub_802DF24(void);
extern struct WonderMail *GetPelipperBoardSlotInfo(u8);
extern u8 HasNoPelipperBoardJobs(void);
extern void sub_8096C80(void);
extern void sub_8096D24(void);
extern void AcceptJob(struct WonderMail*);
extern void ResetPelipperBoardSlot(u8);
extern void sub_80965F4(void);
extern void sub_802C2D4(void);
extern u32 sub_802C1E4(u32);
extern u8 sub_802C26C(void);
extern u8 HasNoAcceptedJobs(void);
extern bool8 IsMailinJobSlot(struct WonderMail *mail);

extern u8 *gUnknown_80D4990[];
extern u8 *gUnknown_80D4970[];

void SetPelipperBoardState(u32);

u32 sub_802E864(void)
{
    gPelipperBoard = MemoryAlloc(sizeof(struct unkStruct_203B308), 8);
    gPelipperBoard->menuAction1 = 0;
    gPelipperBoard->menuAction2 = 0;
    gPelipperBoard->unk4 = 0;
    SetPelipperBoardState(INITIALIZE_PELIPPER_BOARD);
    return 1;
}

u32 sub_802E890(void)
{
    switch(gPelipperBoard->state)
    {
        case INITIALIZE_PELIPPER_BOARD:
            SetPelipperBoardState(MAIN_PELIPPER_BOARD_MENU);
            break;
        case MAIN_PELIPPER_BOARD_MENU:
            sub_802ECB4();
            break;
        case 2:
            nullsub_134();
            break;
        case 4:
        case 5:
            sub_802ED4C();
            break;
        case 6:
            sub_802EDBC();
            break;
        case PELIPPER_JOB_INFO:
            sub_802EEA0();
            break;
        case PELIPPER_JOB_LIST_MENU:
            sub_802EEBC();
            break;
        case PELIPPER_BOARD_EXIT:
        default:
            return 3;
    }
    return 0;
}

u32 sub_802E90C(void)
{
    return gPelipperBoard->unk4;
}

void sub_802E918(void)
{
    if(gPelipperBoard != NULL)
    {
        MemoryFree(gPelipperBoard);
        gPelipperBoard = NULL;
    }
}

void SetPelipperBoardState(u32 newState)
{
    gPelipperBoard->state = newState;
    sub_802E94C();
    sub_802EA58();
}

void sub_802E94C(void)
{
    s32 index;
    sub_8006518(gPelipperBoard->unk10C);
    switch(gPelipperBoard->state)
    {
        case MAIN_PELIPPER_BOARD_MENU:
            for(index = 0; index < 4; index++)
            {
                gPelipperBoard->unk10C[index] = gUnknown_80E0330;
            }
            CreatePelipperBoardMenu();
            gPelipperBoard->unk10C[2] = gUnknown_80E0348;
            sub_8012CAC(&gPelipperBoard->unk10C[2], gPelipperBoard->menuItems);
            break;
        case 6:
            sub_802EC10();
            gPelipperBoard->unk10C[2] = gUnknown_80E0360;
            sub_8012CAC(&gPelipperBoard->unk10C[2], gPelipperBoard->menuItems);
            gPelipperBoard->unk10C[2].unkC = 6;
            gPelipperBoard->unk10C[3] = gUnknown_80E0378;
            break;
        default:
            for(index = 0; index < 4; index++)
            {
                gPelipperBoard->unk10C[index] = gUnknown_80E0330;
            }
            break;
    }
    ResetUnusedInputStruct();
    sub_800641C(gPelipperBoard->unk10C, 1, 1);
}

void sub_802EA58(void)
{
    switch(gPelipperBoard->state)
    {
        case MAIN_PELIPPER_BOARD_MENU:
            sub_8012D60(&gPelipperBoard->unk6C, gPelipperBoard->menuItems, 0, gPelipperBoard->unkFC, gPelipperBoard->menuAction1, 2);
            break;
        case 4:
            sub_802C10C(0, 0, 4);
            break;
        case 5:
            sub_802C28C(1);
            break;
        case 6:
            DrawPelipperBoardJobMenu();
            CreatePelipperAcceptedStatusBox(3);
            sub_8012D60(&gPelipperBoard->unk6C, gPelipperBoard->menuItems, 0, 0, gPelipperBoard->menuAction2, 2);
            break;
        case PELIPPER_JOB_INFO:
            sub_803B35C(GetPelipperBoardSlotInfo(gPelipperBoard->jobIndex), &gPelipperBoard->unkC);
            gPelipperBoard->unkC.unk0[0] = 3;
            gPelipperBoard->unkC.unk44 = 0;
            sub_802DE84(&gPelipperBoard->unkC);
            break;
        case PELIPPER_JOB_LIST_MENU:
            InitializeJobListMenu(0);
            break;
        case INITIALIZE_PELIPPER_BOARD:
        case 2:
        case PELIPPER_BOARD_EXIT:
            break;
    }
}

void CreatePelipperBoardMenu(void)
{
  int index;
  s32 loopMax;

  loopMax = 0;
  MemoryFill16(gPelipperBoard->unkFC,0,sizeof(gPelipperBoard->unkFC));
  gPelipperBoard->menuItems[0].text = gPelipperBoard_BulletinBoard;
  gPelipperBoard->menuItems[0].menuAction = 2;
  if ((HasNoPelipperBoardJobs())) {
    gPelipperBoard->unkFC[0] = 1;
  }
  loopMax += 1;
  gPelipperBoard->menuItems[loopMax].text = gPelipperBoard_JobList;
  gPelipperBoard->menuItems[loopMax].menuAction = 3;

  if(HasNoAcceptedJobs())
  {
      gPelipperBoard->unkFC[loopMax] = 1;
  }
    
  loopMax += 1;
  gPelipperBoard->menuItems[loopMax].text = NULL;
  gPelipperBoard->menuItems[loopMax].menuAction = 1;

  for(index = 0; index < loopMax; index++)
  {
      if (gPelipperBoard->unkFC[index] == 0) {
        if(gPelipperBoard->menuItems[index].menuAction == gPelipperBoard->menuAction1)
            return;
      }
  }

  for(index = 0; index < loopMax; index++)
  {
      if (gPelipperBoard->unkFC[index] == 0) {
        gPelipperBoard->menuAction1 = gPelipperBoard->menuItems[index].menuAction;
        break;
      }
  }
}

void sub_802EC10(void) {

    s32 index;
    s32 loopMax = 0; 
    gPelipperBoard->menuItems[loopMax].text = *gUnknown_80D4990;
    gPelipperBoard->menuItems[loopMax].menuAction = 4;

    if((IsMailinJobSlot(GetPelipperBoardSlotInfo(gPelipperBoard->jobIndex))) || (GetNumAcceptedJobs() >= MAX_ACCEPTED_JOBS))
    {
        gPelipperBoard->menuItems[loopMax].menuAction = -1;
    }

    loopMax += 1;
    gPelipperBoard->menuItems[loopMax].text = *gUnknown_80D4970;
    gPelipperBoard->menuItems[loopMax].menuAction = 5;
    loopMax += 1;
    gPelipperBoard->menuItems[loopMax].text = NULL;
    gPelipperBoard->menuItems[loopMax].menuAction = 1;

    for(index = 0; index < loopMax; index++)
    {
        if(gPelipperBoard->menuItems[index].menuAction != -1)
            if(gPelipperBoard->menuItems[index].menuAction == gPelipperBoard->menuAction2)
                return;
    }

    gPelipperBoard->menuAction2 = 5;
}

void sub_802ECB4(void)
{
    s32 menuAction = 0;

    if(!sub_8012FD8(&gPelipperBoard->unk6C))
    {
        sub_8013114(&gPelipperBoard->unk6C, &menuAction);
        if(menuAction != 1) gPelipperBoard->menuAction1 = menuAction;
    }

    switch(menuAction)
    {
        // Bulletin Board
        case 2:
            if(!HasNoPelipperBoardJobs())
                SetPelipperBoardState(4);
            else
                sub_8012EA4(&gPelipperBoard->unk6C, 1);
            break;
        // Job List
        case 3:
            if(!HasNoAcceptedJobs())
                SetPelipperBoardState(PELIPPER_JOB_LIST_MENU);
            else
                sub_8012EA4(&gPelipperBoard->unk6C, 1);
            break;
        case 5:
            SetPelipperBoardState(2);
            break;
        case 1:
            SetPelipperBoardState(PELIPPER_BOARD_EXIT);
            break;
    }
}

void sub_802ED4C(void)
{
    switch(sub_802C1E4(1))
    {
        case 3:
            gPelipperBoard->jobIndex = sub_802C26C();
            SetPelipperBoardState(6);
            break;
        case 4:
            gPelipperBoard->jobIndex = sub_802C26C();
            SetPelipperBoardState(7);
            break;
        case 2:
            sub_802C2D4();
            SetPelipperBoardState(MAIN_PELIPPER_BOARD_MENU);
            break;
        case 0:
        case 1:
            break;
    }
}

void sub_802EDBC(void)
{
    struct WonderMail *mail;
    s32 menuAction = 0;

    sub_802C1E4(0);
    if(!sub_8012FD8(&gPelipperBoard->unk6C))
    {
        sub_8013114(&gPelipperBoard->unk6C, &menuAction);
        if(menuAction != 1) gPelipperBoard->menuAction2 = menuAction;
    }
    switch(menuAction)
    {
        // Accept
        case 4:
            PlaySound(0x133);
            mail = GetPelipperBoardSlotInfo(gPelipperBoard->jobIndex);
            switch(mail->mailType)
            {
                case MAIL_TYPE_UNK2:
                    gPelipperBoard->unk4 = 1;
                    ResetPelipperBoardSlot(gPelipperBoard->jobIndex);
                    sub_80965F4();
                    sub_802C2D4();
                    SetPelipperBoardState(PELIPPER_BOARD_EXIT);
                    break;
                case MAIL_TYPE_UNK3:
                    gPelipperBoard->unk4 = 2;
                    ResetPelipperBoardSlot(gPelipperBoard->jobIndex);
                    sub_80965F4();
                    sub_802C2D4();
                    SetPelipperBoardState(PELIPPER_BOARD_EXIT);
                    break;
                case MAIL_TYPE_UNK4:
                    gPelipperBoard->unk4 = 3;
                    ResetPelipperBoardSlot(gPelipperBoard->jobIndex);
                    sub_80965F4();
                    sub_802C2D4();
                    SetPelipperBoardState(PELIPPER_BOARD_EXIT);
                    break;
                default:
                    AcceptJob(mail);
                    sub_8096C80();
                    sub_8096D24();
                    if(HasNoPelipperBoardJobs())
                    {
                        sub_802C2D4();
                        SetPelipperBoardState(MAIN_PELIPPER_BOARD_MENU);
                    }
                    else
                        SetPelipperBoardState(5);
                    break;
            }
            break;
        // Info
        case 5:
            SetPelipperBoardState(PELIPPER_JOB_INFO);
            break;
        case 1:
            SetPelipperBoardState(5);
            break;
    }
}

void sub_802EEA0(void)
{
    switch(sub_802DEE0())
    {
        case 2:
        case 3:
            sub_802DF24();
            SetPelipperBoardState(5);
        case 0:
        case 1:
            break;
    }
}

void sub_802EEBC(void)
{
    switch(sub_802C898())
    {
        case 2:
        case 3:
            sub_802C8F4();
            SetPelipperBoardState(MAIN_PELIPPER_BOARD_MENU);
        case 0:
        case 1:
            break;
    }
}


void nullsub_134(void)
{
}

void CreatePelipperAcceptedStatusBox(u32 r0)
{
    sub_8008C54(r0);
    sub_80073B8(r0);
    xxx_call_draw_string(3, 0, gPelipperBoard_Accepted, r0, 0);
    sub_8012BC4(0x12, 0xD, GetNumAcceptedJobs(), 2, 7, r0);
    xxx_call_draw_string(0x16, 0xD, gPelipperStatusSlash, r0, 0); // "/"
    sub_8012BC4(0x23, 0xD, MAX_ACCEPTED_JOBS, 2, 7, r0);
    sub_80073E0(r0);
}