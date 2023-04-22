#include "global.h"
#include "memory.h"
#include "text.h"
#include "menu.h"
#include "input.h"
#include "mailbox.h"
#include "wonder_mail.h"
#include "menu_input.h"

extern struct unkStruct_203B304 *gUnknown_203B304;

extern u8 gMailAccepted[];
extern u8 gUnknown_80E0324[];

extern void xxx_call_draw_string(s32 x, u32 y, u8 *, u32 , u32);
extern void sub_8008C54(u32);
extern void sub_80073B8(u32);
extern void sub_80073E0(u32);
extern u32 sub_802BA8C(void);
extern void sub_802BACC(void);
extern u8 GetPokemonNewsIndex(void);
extern void sub_802B81C(void);
extern u32 sub_802B720(u32);
extern u32 sub_802C898(void);
extern void sub_802C8F4(void);
extern u32 sub_802DEE0(void);
extern void sub_802DF24(void);
extern struct WonderMail *GetMailboxSlotInfo(u8);
extern u8 HasNoMailinMailbox(void);
extern u32 sub_802BDEC(u32);
extern void AcceptJob(struct WonderMail *);
extern void sub_8096C80(void);
extern void sub_8096D24(void);
extern void ResetMailboxSlot(u8);
extern void ReceivePKMNNews(u8);
extern void sub_8096078(void);
extern void PlayMenuSoundEffect(u32);
extern void PlaySound(u32);
extern void sub_802BEDC(void);
extern u8 sub_802BE74(void);
extern u8 HasNoAcceptedJobs(void);
extern u8 HasNoPKMNNews(void);

void HandleMailboxMenu(void)
{
    s32 menuAction = 0;

    if(!sub_8012FD8(&gUnknown_203B304->unk6C))
    {
        sub_8013114(&gUnknown_203B304->unk6C, &menuAction);
        if(menuAction != 1) gUnknown_203B304->menuAction1 = menuAction;
    }
    switch(menuAction)
    {
        // Check Mail
        case 2:
            if(!HasNoMailinMailbox())
                SetMailboxState(MAIL_MENU);
            else
                sub_8012EA4(&gUnknown_203B304->unk6C, 1);
            break;
        // Job List
        case 3:
            if(!HasNoAcceptedJobs())
                SetMailboxState(JOB_LIST_MENU);
            else
                sub_8012EA4(&gUnknown_203B304->unk6C, 1);
            break;
        case 4:
            if(!HasNoPKMNNews())
                SetMailboxState(PKMN_NEWS_MENU);
            else
                sub_8012EA4(&gUnknown_203B304->unk6C, 1);
            break;
        case 8:
            SetMailboxState(2);
            break;
        case 1:
            SetMailboxState(MAILBOX_EXIT);
            break;
    }
}

void sub_802E578(void)
{
    struct WonderMail *mail;

    switch(sub_802BDEC(1))
    {

        case 3:
            gUnknown_203B304->mailboxIndex = sub_802BE74();
            SetMailboxState(MAIL_ACTION_MENU);
            break;
        case 4:
            gUnknown_203B304->mailboxIndex = sub_802BE74();
            mail = GetMailboxSlotInfo(gUnknown_203B304->mailboxIndex);
            if(mail->mailType == 1)
            {
                gUnknown_203B304->mailIndex = mail->dungeon.floor;
                gUnknown_203B304->fallbackState = MAIL_MENU_1;
                SetMailboxState(DISPLAY_SEL_PKMN_NEWS);
            }
            else
                SetMailboxState(MAIL_INFO);
            break;
        case 2:
            sub_802BEDC();
            SetMailboxState(MAIN_MAILBOX_MENU);
            break;
        case 0:
        case 1:
            break;
    }
}

void HandleMailActionMenu(void)
{
    s32 menuAction = 0;
    struct WonderMail *mail;


    sub_802BDEC(0);
    if(!sub_8012FD8(&gUnknown_203B304->unk6C))
    {
        sub_8013114(&gUnknown_203B304->unk6C, &menuAction);
        if(menuAction != 1) gUnknown_203B304->menuAction2 = menuAction;
    }
    switch(menuAction)
    {
        case 2:
        case 3:
        case 4:
            break;

        // Accept
        case 5:
            PlaySound(0x133);
            AcceptJob(GetMailboxSlotInfo(gUnknown_203B304->mailboxIndex));
            sub_8096C80();
            sub_8096D24();
            ResetMailboxSlot(gUnknown_203B304->mailboxIndex);
            sub_8096078();
            if(HasNoMailinMailbox())
            {
                sub_802BEDC();
                SetMailboxState(MAIN_MAILBOX_MENU);
            }
            else
                SetMailboxState(MAIL_MENU_1);
            break;

        // Info
        case 8:
            SetMailboxState(MAIL_INFO);
            break;

        // Store
        case 6:
            PlaySound(0x133);
            mail = GetMailboxSlotInfo(gUnknown_203B304->mailboxIndex);
            ReceivePKMNNews(mail->dungeon.floor);
            ResetMailboxSlot(gUnknown_203B304->mailboxIndex);
            sub_8096078();
            if(HasNoMailinMailbox())
            {
                sub_802BEDC();
                SetMailboxState(MAIN_MAILBOX_MENU);
            }
            else
                SetMailboxState(MAIL_MENU_1);
            break;

        // Read
        case 7:
            PlayMenuSoundEffect(0);
            mail = GetMailboxSlotInfo(gUnknown_203B304->mailboxIndex);
            gUnknown_203B304->mailIndex = mail->dungeon.floor;
            gUnknown_203B304->fallbackState = MAIL_MENU_1;
            SetMailboxState(DISPLAY_SEL_PKMN_NEWS);
            break;
        case 1:
            SetMailboxState(MAIL_MENU_1);
            break;
    }
}

void sub_802E73C(void)
{
    switch(sub_802DEE0())
    {
        case 2:
        case 3:
            sub_802DF24();
            SetMailboxState(MAIL_MENU_1);
        case 0:
        case 1:
            break;
    }
}

void sub_802E758(void)
{
    switch(sub_802C898())
    {
        case 2:
        case 3:
            sub_802C8F4();
            SetMailboxState(MAIN_MAILBOX_MENU);
        case 0:
        case 1:
            break;
    }
}

void sub_802E774(void)
{
    switch(sub_802B720(1))
    {
        case 0:
        case 1:
            break;
        case 3:
        case 4:
            gUnknown_203B304->mailIndex = GetPokemonNewsIndex();
            gUnknown_203B304->fallbackState = PKMN_NEWS_MENU_1;
            SetMailboxState(DISPLAY_SEL_PKMN_NEWS);
            break;
        case 2:
            sub_802B81C();
            SetMailboxState(MAIN_MAILBOX_MENU);
            break;
    }
}

void sub_802E7D0(void)
{
    switch(sub_802BA8C())
    {
        case 2:
        case 3:
            sub_802BACC();
            SetMailboxState(gUnknown_203B304->fallbackState);
        case 0:
        case 1:
            break;
    }
}

void nullsub_133(void)
{
}

void CreateMailAcceptedStatusBox(u32 r0)
{
    sub_8008C54(r0);
    sub_80073B8(r0);
    xxx_call_draw_string(3, 0, gMailAccepted, r0, 0);
    sub_8012BC4(0x12, 0xD, GetNumAcceptedJobs(), 2, 7, r0);
    xxx_call_draw_string(0x16, 0xD, gUnknown_80E0324, r0, 0); // "/"
    sub_8012BC4(0x23, 0xD, MAX_ACCEPTED_JOBS, 2, 7, r0);
    sub_80073E0(r0);
}
