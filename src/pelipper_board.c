#include "global.h"
#include "globaldata.h"
#include "code_802DE84.h"
#include "mailbox.h"
#include "pokemon.h"
#include "items.h"
#include "memory.h"
#include "text1.h"
#include "text2.h"
#include "structs/menu.h"
#include "input.h"
#include "menu_input.h"
#include "common_strings.h"
#include "pelipper_board.h"
#include "code_80118A4.h"
#include "wonder_mail_802C10C.h"
#include "code_80958E8.h"
#include "code_803B050.h"
#include "wonder_mail_802C4C8.h"
#include "wonder_mail_802C860.h"

EWRAM_DATA_2 struct unkStruct_203B308 *gPelipperBoard = {0};

const UnkTextStruct2 gUnknown_80E0330 =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    NULL
};

const UnkTextStruct2 gUnknown_80E0348 =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x03, 0x03,
    0x07, 0x03,
    0x03, 0x00,
    NULL
};

const UnkTextStruct2 gUnknown_80E0360 =
{
    0x00, 0x00, 0x00, 0x00,
    0x04,
    0x15, 0x06,
    0x07, 0x03,
    0x03, 0x00,
    NULL
};

const UnkTextStruct2 gUnknown_80E0378 =
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

static void sub_802ECB4(void);
static void nullsub_134(void);
static void sub_802ED4C(void);
static void sub_802EDBC(void);
static void sub_802EEA0(void);
static void sub_802EEBC(void);
static void sub_802E94C(void);
static void sub_802EA58(void);
static void CreatePelipperBoardMenu(void);
static void sub_802EC10(void);
static void CreatePelipperAcceptedStatusBox(u32);
static void SetPelipperBoardState(u32);

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
    RestoreUnkTextStruct_8006518(gPelipperBoard->unk10C);
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
    xxx_call_save_unk_text_struct_800641C(gPelipperBoard->unk10C, TRUE, TRUE);
}

void sub_802EA58(void)
{
    switch(gPelipperBoard->state)
    {
        case MAIN_PELIPPER_BOARD_MENU:
            sub_8012D60(&gPelipperBoard->unk6C, gPelipperBoard->menuItems, 0, gPelipperBoard->unkFC, gPelipperBoard->menuAction1, 2);
            break;
        case 4:
            sub_802C10C(0, NULL, 4);
            break;
        case 5:
            sub_802C28C(TRUE);
            break;
        case 6:
            DrawPelipperBoardJobMenu();
            CreatePelipperAcceptedStatusBox(3);
            sub_8012D60(&gPelipperBoard->unk6C, gPelipperBoard->menuItems, 0, 0, gPelipperBoard->menuAction2, 2);
            break;
        case PELIPPER_JOB_INFO:
            sub_803B35C(GetPelipperBoardSlotInfo(gPelipperBoard->jobIndex), &gPelipperBoard->unkC);
            gPelipperBoard->unkC.unk0[0] = 3;
            gPelipperBoard->unkC.mailStatus = MAIL_STATUS_SUSPENDED;
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
  gPelipperBoard->menuItems[0].menuAction = PELIPPER_BOARD_BULLETIN_BOARD;
  if ((HasNoPelipperBoardJobs())) {
    gPelipperBoard->unkFC[0] = 1;
  }
  loopMax += 1;
  gPelipperBoard->menuItems[loopMax].text = gPelipperBoard_JobList;
  gPelipperBoard->menuItems[loopMax].menuAction = PELIPPER_BOARD_JOB_LIST;

  if(HasNoAcceptedJobs())
  {
      gPelipperBoard->unkFC[loopMax] = 1;
  }
    
  loopMax += 1;
  gPelipperBoard->menuItems[loopMax].text = NULL;
  gPelipperBoard->menuItems[loopMax].menuAction = PELIPPER_BOARD_NULL;

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
    gPelipperBoard->menuItems[loopMax].text = gCommonAccept[0];
    gPelipperBoard->menuItems[loopMax].menuAction = PELIPPER_BOARD_ACCEPT;

    if((IsMailinJobSlot(GetPelipperBoardSlotInfo(gPelipperBoard->jobIndex))) || (GetNumAcceptedJobs() >= MAX_ACCEPTED_JOBS))
    {
        gPelipperBoard->menuItems[loopMax].menuAction = -1;
    }

    loopMax += 1;
    gPelipperBoard->menuItems[loopMax].text = gCommonInfo[0];
    gPelipperBoard->menuItems[loopMax].menuAction = PELIPPER_BOARD_INFO;
    loopMax += 1;
    gPelipperBoard->menuItems[loopMax].text = NULL;
    gPelipperBoard->menuItems[loopMax].menuAction = PELIPPER_BOARD_NULL;

    for(index = 0; index < loopMax; index++)
    {
        if(gPelipperBoard->menuItems[index].menuAction != -1)
            if(gPelipperBoard->menuItems[index].menuAction == gPelipperBoard->menuAction2)
                return;
    }

    gPelipperBoard->menuAction2 = PELIPPER_BOARD_INFO;
}

void sub_802ECB4(void)
{
    s32 menuAction = 0;

    if(!sub_8012FD8(&gPelipperBoard->unk6C))
    {
        sub_8013114(&gPelipperBoard->unk6C, &menuAction);
        if(menuAction != PELIPPER_BOARD_NULL) gPelipperBoard->menuAction1 = menuAction;
    }

    switch(menuAction)
    {
        case PELIPPER_BOARD_BULLETIN_BOARD:
            if(!HasNoPelipperBoardJobs())
                SetPelipperBoardState(4);
            else
                sub_8012EA4(&gPelipperBoard->unk6C, 1);
            break;
        case PELIPPER_BOARD_JOB_LIST:
            if(!HasNoAcceptedJobs())
                SetPelipperBoardState(PELIPPER_JOB_LIST_MENU);
            else
                sub_8012EA4(&gPelipperBoard->unk6C, 1);
            break;
        case PELIPPER_BOARD_INFO:
            SetPelipperBoardState(2);
            break;
        case PELIPPER_BOARD_NULL:
            SetPelipperBoardState(PELIPPER_BOARD_EXIT);
            break;
    }
}

void sub_802ED4C(void)
{
    switch(sub_802C1E4(TRUE))
    {
        case 3: // A button
            gPelipperBoard->jobIndex = sub_802C26C();
            SetPelipperBoardState(6);
            break;
        case 4: // Start button
            gPelipperBoard->jobIndex = sub_802C26C();
            SetPelipperBoardState(7);
            break;
        case 2: // B button
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
    WonderMail *mail;
    s32 menuAction = 0;

    sub_802C1E4(FALSE);
    if(!sub_8012FD8(&gPelipperBoard->unk6C))
    {
        sub_8013114(&gPelipperBoard->unk6C, &menuAction);
        if(menuAction != PELIPPER_BOARD_NULL) gPelipperBoard->menuAction2 = menuAction;
    }
    switch(menuAction)
    {
        case PELIPPER_BOARD_ACCEPT:
            PlaySound(0x133);
            mail = GetPelipperBoardSlotInfo(gPelipperBoard->jobIndex);
            switch(mail->mailType)
            {
                case MAIL_TYPE_UNK2:
                    gPelipperBoard->unk4 = 1;
                    ResetPelipperBoardSlot(gPelipperBoard->jobIndex);
                    ShiftPelipperJobsDown();
                    sub_802C2D4();
                    SetPelipperBoardState(PELIPPER_BOARD_EXIT);
                    break;
                case MAIL_TYPE_UNK3:
                    gPelipperBoard->unk4 = 2;
                    ResetPelipperBoardSlot(gPelipperBoard->jobIndex);
                    ShiftPelipperJobsDown();
                    sub_802C2D4();
                    SetPelipperBoardState(PELIPPER_BOARD_EXIT);
                    break;
                case MAIL_TYPE_UNK4:
                    gPelipperBoard->unk4 = 3;
                    ResetPelipperBoardSlot(gPelipperBoard->jobIndex);
                    ShiftPelipperJobsDown();
                    sub_802C2D4();
                    SetPelipperBoardState(PELIPPER_BOARD_EXIT);
                    break;
                default:
                    AcceptJob(mail);
                    ShiftJobSlotsDown();
                    SortJobSlots();
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
        case PELIPPER_BOARD_INFO:
            SetPelipperBoardState(PELIPPER_JOB_INFO);
            break;
        case PELIPPER_BOARD_NULL:
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
    CallPrepareTextbox_8008C54(r0);
    sub_80073B8(r0);
    PrintStringOnWindow(3, 0, gPelipperBoard_Accepted, r0, 0);
    sub_8012BC4(0x12, 0xD, GetNumAcceptedJobs(), 2, 7, r0);
    PrintStringOnWindow(0x16, 0xD, gPelipperStatusSlash, r0, 0); // "/"
    sub_8012BC4(0x23, 0xD, MAX_ACCEPTED_JOBS, 2, 7, r0);
    sub_80073E0(r0);
}
