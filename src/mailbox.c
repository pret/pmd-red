#include "global.h"
#include "globaldata.h"
#include "structs/menu.h"
#include "music_util.h"
#include "code_802DE84.h"
#include "code_803B050.h"
#include "code_80958E8.h"
#include "common_strings.h"
#include "input.h"
#include "mailbox.h"
#include "memory.h"
#include "menu_input.h"
#include "pokemon_news1.h"
#include "pokemon_news2.h"
#include "pokemon_news3.h"
#include "text_1.h"
#include "text_2.h"
#include "wonder_mail_802C4C8.h"
#include "wonder_mail_802C860.h"

EWRAM_INIT struct unkStruct_203B304 *gUnknown_203B304 = {NULL};

const WindowTemplate gUnknown_80E0284 =
{
    0,
    0x03,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    NULL
};

const WindowTemplate gUnknown_80E029C =
{
    0,
    0x03,
    0x03, 0x03,
    0x07, 0x03,
    0x03, 0x00,
    NULL
};

const WindowTemplate gUnknown_80E02B4 =
{
    0,
    0x04,
    0x15, 0x06,
    0x07, 0x03,
    0x03, 0x00,
    NULL
};

const WindowTemplate gUnknown_80E02CC =
{
    0,
    0x04,
    0x15, 0x0f,
    0x06, 0x03,
    0x03, 0x00,
    NULL
};

const u8 gMailboxCheckMail[] = "Check Mail";
const u8 gMailboxJobList[] = "Job List";
const u8 gMailboxPKMNNews[] = "PKMN News";
const u8 gMailActionStore[] = "Store";
const u8 gMailActionRead[] = "Read";
const u8 gMailAccepted[] = "Accepted";
const u8 gUnknown_80E0324[] = "/";

void sub_802E578(void);
void HandleMailActionMenu(void);
void HandleMailboxMenu(void);
void nullsub_133(void);
void sub_802E0A0(void);
void sub_802E1AC(void);
void sub_802E73C(void);
void sub_802E758(void);
void sub_802E774(void);
void sub_802E7D0(void);
void CreateMailboxMenu(void);
void CreateMailActionMenu(void);
void CreateMailAcceptedStatusBox(u32);

u8 sub_802DFB0(void)
{
    gUnknown_203B304 = MemoryAlloc(sizeof(struct unkStruct_203B304), MEMALLOC_GROUP_8);
    gUnknown_203B304->menuAction1 = 0;
    gUnknown_203B304->menuAction2 = 0;
    SetMailboxState(INITIALIZE_MAILBOX);
    return 1;
}

u32 sub_802DFD8(void)
{
    switch(gUnknown_203B304->state)
    {
        case INITIALIZE_MAILBOX:
            SetMailboxState(MAIN_MAILBOX_MENU);
            break;
        case MAIN_MAILBOX_MENU:
            HandleMailboxMenu();
            break;
        case 2:
            nullsub_133();
            break;
        case MAIL_MENU:
        case MAIL_MENU_1:
            sub_802E578();
            break;
        case MAIL_ACTION_MENU:
            HandleMailActionMenu();
            break;
        case MAIL_INFO:
            sub_802E73C();
            break;
        case JOB_LIST_MENU:
            sub_802E758();
            break;
        case PKMN_NEWS_MENU:
        case PKMN_NEWS_MENU_1:
            sub_802E774();
            break;
        case DISPLAY_SEL_PKMN_NEWS:
            sub_802E7D0();
            break;
        case MAILBOX_EXIT:
        default:
            return 3;
    }
    return 0;
}

void sub_802E06C(void)
{
    if(gUnknown_203B304 != NULL)
    {
        MemoryFree(gUnknown_203B304);
        gUnknown_203B304 = NULL;
    }
}

void SetMailboxState(u32 newState)
{
    gUnknown_203B304->state = newState;
    sub_802E0A0();
    sub_802E1AC();
}

void sub_802E0A0(void)
{
    s32 index;
    RestoreSavedWindows(&gUnknown_203B304->unk10C);
    switch(gUnknown_203B304->state)
    {
        case MAIN_MAILBOX_MENU:
            for(index = 0; index < 4; index++)
            {
                gUnknown_203B304->unk10C.id[index] = gUnknown_80E0284;
            }
            CreateMailboxMenu();
            gUnknown_203B304->unk10C.id[2] = gUnknown_80E029C;
            sub_8012CAC(&gUnknown_203B304->unk10C.id[2], gUnknown_203B304->menuItems);
            break;
        case MAIL_ACTION_MENU:
            CreateMailActionMenu();
            gUnknown_203B304->unk10C.id[2] = gUnknown_80E02B4;
            sub_8012CAC(&gUnknown_203B304->unk10C.id[2], gUnknown_203B304->menuItems);
            gUnknown_203B304->unk10C.id[2].width = 6;
            gUnknown_203B304->unk10C.id[3] = gUnknown_80E02CC;
            break;
        default:
            for(index = 0; index < 4; index++)
            {
                gUnknown_203B304->unk10C.id[index] = gUnknown_80E0284;
            }
            break;
    }
    ResetUnusedInputStruct();
    ShowWindows(&gUnknown_203B304->unk10C, TRUE, TRUE);
}

void sub_802E1AC(void)
{
    switch(gUnknown_203B304->state)
    {
        case MAIN_MAILBOX_MENU:
            sub_8012D60(&gUnknown_203B304->unk6C, gUnknown_203B304->menuItems, 0, gUnknown_203B304->unkFC, gUnknown_203B304->menuAction1, 2);
            break;
        case MAIL_MENU:
            sub_802BD14(0, NULL, 4);
            break;
        case MAIL_MENU_1:
            sub_802BE94(TRUE);
            break;
        case MAIL_ACTION_MENU:
            CreateMailMenu();
            CreateMailAcceptedStatusBox(3);
            sub_8012D60(&gUnknown_203B304->unk6C, gUnknown_203B304->menuItems, 0, 0, gUnknown_203B304->menuAction2, 2);
            break;
        case MAIL_INFO:
            sub_803B35C(GetMailboxSlotInfo(gUnknown_203B304->mailboxIndex), &gUnknown_203B304->unkC);
            gUnknown_203B304->unkC.unk0[0] = 3;
            gUnknown_203B304->unkC.mailStatus = MAIL_STATUS_SUSPENDED;
            sub_802DE84(&gUnknown_203B304->unkC);
            break;
        case JOB_LIST_MENU:
            InitializeJobListMenu(0);
            break;
        case PKMN_NEWS_MENU:
            sub_802B640(0, NULL, 8);
            break;
        case PKMN_NEWS_MENU_1:
            sub_802B7D0(TRUE);
            break;
        case DISPLAY_SEL_PKMN_NEWS:
            sub_802B9FC(gUnknown_203B304->mailIndex);
            break;
        case INITIALIZE_MAILBOX:
        case 2:
        case MAILBOX_EXIT:
            break;
    }
}

void CreateMailboxMenu(void)
{
    s32 index;
    s32 loopMax;

    loopMax = 0;
    MemoryFill16(gUnknown_203B304->unkFC,0,sizeof(gUnknown_203B304->unkFC));
    gUnknown_203B304->menuItems[0].text = gMailboxCheckMail;
    gUnknown_203B304->menuItems[0].menuAction = 2;
    if ((HasNoMailinMailbox())) {
        gUnknown_203B304->unkFC[0] = 1;
    }
    loopMax += 1;

    gUnknown_203B304->menuItems[loopMax].text = gMailboxJobList;
    gUnknown_203B304->menuItems[loopMax].menuAction = 3;
    if(HasNoAcceptedJobs())
    {
        gUnknown_203B304->unkFC[loopMax] = 1;
    }
    loopMax += 1;

    gUnknown_203B304->menuItems[loopMax].text = gMailboxPKMNNews;
    gUnknown_203B304->menuItems[loopMax].menuAction = 4;
    if(HasNoPKMNNews())
    {
        gUnknown_203B304->unkFC[loopMax] = 1;
    }
    loopMax += 1;

    gUnknown_203B304->menuItems[loopMax].text = NULL;
    gUnknown_203B304->menuItems[loopMax].menuAction = 1;

    for(index = 0; index < loopMax; index++)
    {
        if (gUnknown_203B304->unkFC[index] == 0) {
            if(gUnknown_203B304->menuItems[index].menuAction == gUnknown_203B304->menuAction1)
                return;
        }
    }

    for(index = 0; index < loopMax; index++)
    {
        if (gUnknown_203B304->unkFC[index] == 0) {
            gUnknown_203B304->menuAction1 = gUnknown_203B304->menuItems[index].menuAction;
            break;
        }
    }
}

void CreateMailActionMenu(void) {
    s32 index;
    WonderMail *mail;
    s32 loopMax = 0;
    mail = GetMailboxSlotInfo(gUnknown_203B304->mailboxIndex);
    if(mail->mailType == 1)
    {
        gUnknown_203B304->menuItems[loopMax].text = gMailActionStore;
        gUnknown_203B304->menuItems[loopMax].menuAction = 6;
        loopMax += 1;
        gUnknown_203B304->menuItems[loopMax].text = gMailActionRead;
        gUnknown_203B304->menuItems[loopMax].menuAction = 7;
        loopMax += 1;
    }
    else
    {
        gUnknown_203B304->menuItems[loopMax].text = gCommonAccept[0];
        gUnknown_203B304->menuItems[loopMax].menuAction = 5;

        if(IsMailinJobSlot(mail) || GetNumAcceptedJobs() >= MAX_ACCEPTED_JOBS)
        {
            gUnknown_203B304->menuItems[loopMax].menuAction = -1;
        }
        loopMax += 1;

        gUnknown_203B304->menuItems[loopMax].text = gCommonInfo[0];
        gUnknown_203B304->menuItems[loopMax].menuAction = 8;
        loopMax += 1;
    }
    gUnknown_203B304->menuItems[loopMax].text = NULL;
    gUnknown_203B304->menuItems[loopMax].menuAction = 1;

    for(index = 0; index < loopMax; index++)
    {
        if (gUnknown_203B304->menuItems[index].menuAction != -1) {
            if(gUnknown_203B304->menuItems[index].menuAction == gUnknown_203B304->menuAction2)
                return;
        }
    }
    if(mail->mailType == 1)
        gUnknown_203B304->menuAction2 = 7;
    else
        gUnknown_203B304->menuAction2 = 8;
}

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
    WonderMail *mail;

    switch(sub_802BDEC(TRUE))
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
                gUnknown_203B304->mailIndex = mail->dungeonSeed.location.floor;
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
    WonderMail *mail;


    sub_802BDEC(FALSE);
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
            ShiftJobSlotsDown();
            SortJobSlots();
            ResetMailboxSlot(gUnknown_203B304->mailboxIndex);
            ShiftMailboxSlotsDown();
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
            ReceivePKMNNews(mail->dungeonSeed.location.floor);
            ResetMailboxSlot(gUnknown_203B304->mailboxIndex);
            ShiftMailboxSlotsDown();
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
            PlayMenuSoundEffect(MENU_SFX_ACCEPT);
            mail = GetMailboxSlotInfo(gUnknown_203B304->mailboxIndex);
            gUnknown_203B304->mailIndex = mail->dungeonSeed.location.floor;
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
    switch(sub_802B720(TRUE))
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
    CallPrepareTextbox_8008C54(r0);
    sub_80073B8(r0);
    PrintStringOnWindow(3, 0, gMailAccepted, r0, 0);
    PrintNumOnWindow(0x12, 0xD, GetNumAcceptedJobs(), 2, 7, r0);
    PrintStringOnWindow(0x16, 0xD, gUnknown_80E0324, r0, 0); // "/"
    PrintNumOnWindow(0x23, 0xD, MAX_ACCEPTED_JOBS, 2, 7, r0);
    sub_80073E0(r0);
}

