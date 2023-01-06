#include "global.h"
#include "mailbox.h"
#include "pokemon.h"
#include "item.h"
#include "memory.h"
#include "menu.h"
#include "text.h"
#include "team_inventory.h"
#include "wonder_mail.h"

struct unkStruct_203B308
{
    // size: 0xB6 << 1
    u32 state;
    u32 unk4;
    u8 jobIndex;
    u8 fill9[0xC - 9];
    u32 unkC;
    u8 fill10[0x50 - 0x10];
    u8 unk50;
    u8 fill51[0x64 - 0x51];
    u32 unk64;
    u32 unk68;
    u32 unk6C;
    u8 fill70[0xBC - 0x70];
    struct MenuItem unkBC[8];
    u16 unkFC[8];
    struct UnkTextStruct2 unk10C[4];
};
extern struct unkStruct_203B308 *gUnknown_203B308;

extern u8 gPelipperBoard_Accepted[];
extern u8 gPelipperStatusSlash[];
extern void xxx_call_draw_string(s32 x, u32 y, u8 *, u32 , u32);
extern void sub_8012BC4(u32 x, u32 y, u32, u32, u32, u32);
extern void sub_8008C54(u32);
extern void sub_80073B8(u32);
extern void sub_80073E0(u32);
extern u32 sub_802C898(void);
extern void sub_802C8F4(void);
extern u32 sub_802DEE0(void);
extern void sub_802DF24(void);
extern struct WonderMail *GetPelliperBoardSlotInfo(u8);
extern u8 sub_802C4A4(void);
extern void sub_8096C80(void);
extern void sub_8096D24(void);
extern void sub_8096A78(struct WonderMail*);
extern void ResetPelliperBoardSlot(u8);
extern void sub_80965F4(void);
extern void sub_802C2D4(void);
extern u8 sub_8012FD8(u32 *);
extern void sub_8013114(u32 *, s32 *);
extern u32 sub_802C1E4(u32);
extern void PlaySound(u32);
extern void SetPelipperBoardState(u32);
extern u8 sub_802C26C(void);
extern u8 HasNoAcceptedJobs(void);
extern void sub_8012EA4(u32 *, u32);

void sub_802ECB4(void)
{
    s32 menuAction = 0;

    if(!sub_8012FD8(&gUnknown_203B308->unk6C))
    {
        sub_8013114(&gUnknown_203B308->unk6C, &menuAction);
        if(menuAction != 1) gUnknown_203B308->unk64 = menuAction;
    }

    switch(menuAction)
    {
        case 2:
            if(!sub_802C4A4())
                SetPelipperBoardState(4);
            else
                sub_8012EA4(&gUnknown_203B308->unk6C, 1);
            break;
        case 3:
            if(!HasNoAcceptedJobs())
                SetPelipperBoardState(8);
            else
                sub_8012EA4(&gUnknown_203B308->unk6C, 1);
            break;
        case 5:
            SetPelipperBoardState(2);
            break;
        case 1:
            SetPelipperBoardState(3);
            break;
    }
}

void sub_802ED4C(void)
{
    switch(sub_802C1E4(1))
    {
        case 3:
            gUnknown_203B308->jobIndex = sub_802C26C();
            SetPelipperBoardState(6);
            break;
        case 4:
            gUnknown_203B308->jobIndex = sub_802C26C();
            SetPelipperBoardState(7);
            break;
        case 2:
            sub_802C2D4();
            SetPelipperBoardState(1);
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
    if(!sub_8012FD8(&gUnknown_203B308->unk6C))
    {
        sub_8013114(&gUnknown_203B308->unk6C, &menuAction);
        if(menuAction != 1) gUnknown_203B308->unk68 = menuAction;
    }
    switch(menuAction)
    {
        case 4:
            PlaySound(0x133);
            mail = GetPelliperBoardSlotInfo(gUnknown_203B308->jobIndex);
            switch(mail->mailType)
            {
                case 2:
                    gUnknown_203B308->unk4 = 1;
                    ResetPelliperBoardSlot(gUnknown_203B308->jobIndex);
                    sub_80965F4();
                    sub_802C2D4();
                    SetPelipperBoardState(3);
                    break;
                case 3:
                    gUnknown_203B308->unk4 = 2;
                    ResetPelliperBoardSlot(gUnknown_203B308->jobIndex);
                    sub_80965F4();
                    sub_802C2D4();
                    SetPelipperBoardState(3);
                    break;
                case 4:
                    gUnknown_203B308->unk4 = 3;
                    ResetPelliperBoardSlot(gUnknown_203B308->jobIndex);
                    sub_80965F4();
                    sub_802C2D4();
                    SetPelipperBoardState(3);
                    break;
                default:
                    sub_8096A78(mail);
                    sub_8096C80();
                    sub_8096D24();
                    if(sub_802C4A4())
                    {
                        sub_802C2D4();
                        SetPelipperBoardState(1);
                    }
                    else
                        SetPelipperBoardState(5);
                    break;
            }
            break;
        case 5:
            SetPelipperBoardState(7);
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
            SetPelipperBoardState(1);
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
