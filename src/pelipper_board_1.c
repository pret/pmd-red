#include "global.h"
#include "mailbox.h"
#include "pokemon.h"
#include "item.h"
#include "memory.h"
#include "menu.h"
#include "text.h"
#include "team_inventory.h"
#include "wonder_mail.h"
#include "menu_input.h"
#include "pelipper_board.h"

extern u8 gPelipperBoard_Accepted[];
extern u8 gPelipperStatusSlash[];
extern void xxx_call_draw_string(s32 x, u32 y, u8 *, u32 , u32);
extern void sub_8008C54(u32);
extern void sub_80073B8(u32);
extern void sub_80073E0(u32);
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
extern void PlaySound(u32);
extern void SetPelipperBoardState(u32);
extern u8 sub_802C26C(void);
extern u8 HasNoAcceptedJobs(void);

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
                case 2:
                    gPelipperBoard->unk4 = 1;
                    ResetPelipperBoardSlot(gPelipperBoard->jobIndex);
                    sub_80965F4();
                    sub_802C2D4();
                    SetPelipperBoardState(PELIPPER_BOARD_EXIT);
                    break;
                case 3:
                    gPelipperBoard->unk4 = 2;
                    ResetPelipperBoardSlot(gPelipperBoard->jobIndex);
                    sub_80965F4();
                    sub_802C2D4();
                    SetPelipperBoardState(PELIPPER_BOARD_EXIT);
                    break;
                case 4:
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
