#include "global.h"
#include "memory.h"
#include "text.h"
#include "menu.h"
#include "input.h"
#include "mailbox.h"
#include "wonder_mail.h"
#include "menu_input.h"


extern void HandleMailboxMenu(void);
extern void nullsub_133(void);
extern void sub_802E578(void);
extern void HandleMailActionMenu(void);
extern void sub_802E73C(void);
extern void sub_802E758(void);
extern void sub_802E774(void);
extern void sub_802E7D0(void);


extern void sub_802E0A0(void);
extern void sub_802E1AC(void);

const struct UnkTextStruct2 gUnknown_80E0284 =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    NULL
};

const struct UnkTextStruct2 gUnknown_80E029C =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x03, 0x00, 0x03, 0x00,
    0x07, 0x03,
    0x03, 0x00,
    NULL
};

const struct UnkTextStruct2 gUnknown_80E02B4 =
{
    0x00, 0x00, 0x00, 0x00,
    0x04,
    0x15, 0x00, 0x06, 0x00,
    0x07, 0x03,
    0x03, 0x00,
    NULL
};

const struct UnkTextStruct2 gUnknown_80E02CC =
{
    0x00, 0x00, 0x00, 0x00,
    0x04,
    0x15, 0x00, 0x0f, 0x00,
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
static const u8 mailbox_fill[] = "pksdir0";

extern struct unkStruct_203B304 *gUnknown_203B304;
extern void sub_802E088(u32);
extern void CreateMailboxMenu(void);
extern void CreateMailActionMenu(void);

extern void sub_802BD14(u32, u32, u32);
extern void sub_802BE94(u32);
extern void CreateMailMenu(void);
extern void CreateMailAcceptedStatusBox(u32);
extern struct WonderMail * GetMailboxSlotInfo(u32);
extern void sub_803B35C(struct WonderMail *, u32 *);
extern void sub_802DE84(u32 *);
extern void InitializeJobListMenu(u32);
extern void sub_802B640(u32, u32, u32);
extern void sub_802B7D0(u32);
extern void sub_802B9FC(u8);

u32 sub_802DFB0(void)
{
    gUnknown_203B304 = MemoryAlloc(sizeof(struct unkStruct_203B304), 8);
    gUnknown_203B304->unk64 = 0;
    gUnknown_203B304->unk68 = 0;
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
    sub_8006518(gUnknown_203B304->unk10C);
    switch(gUnknown_203B304->state)
    {
        case MAIN_MAILBOX_MENU:
            for(index = 0; index < 4; index++)
            {
                gUnknown_203B304->unk10C[index] = gUnknown_80E0284;
            }
            CreateMailboxMenu();
            gUnknown_203B304->unk10C[2] = gUnknown_80E029C;
            sub_8012CAC(&gUnknown_203B304->unk10C[2], gUnknown_203B304->unkBC);
            break;
        case MAIL_ACTION_MENU:
            CreateMailActionMenu();
            gUnknown_203B304->unk10C[2] = gUnknown_80E02B4;
            sub_8012CAC(&gUnknown_203B304->unk10C[2], gUnknown_203B304->unkBC);
            gUnknown_203B304->unk10C[2].unkC = 6;
            gUnknown_203B304->unk10C[3] = gUnknown_80E02CC;
            break;
        default:
            for(index = 0; index < 4; index++)
            {
                gUnknown_203B304->unk10C[index] = gUnknown_80E0284;
            }
            break;
    }
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B304->unk10C, 1, 1);
}

void sub_802E1AC(void)
{
    switch(gUnknown_203B304->state)
    {
        case MAIN_MAILBOX_MENU:
            sub_8012D60(&gUnknown_203B304->unk6C, gUnknown_203B304->unkBC, 0, gUnknown_203B304->unkFC, gUnknown_203B304->unk64, 2);
            break;
        case MAIL_MENU:
            sub_802BD14(0, 0, 4);
            break;
        case MAIL_MENU_1:
            sub_802BE94(1);
            break;
        case MAIL_ACTION_MENU:
            CreateMailMenu();
            CreateMailAcceptedStatusBox(3);
            sub_8012D60(&gUnknown_203B304->unk6C, gUnknown_203B304->unkBC, 0, 0, gUnknown_203B304->unk68, 2);
            break;
        case MAIL_INFO:
            sub_803B35C(GetMailboxSlotInfo(gUnknown_203B304->mailboxIndex), &gUnknown_203B304->unkC);
            gUnknown_203B304->unkC = 3;
            gUnknown_203B304->unk50 = 0;
            sub_802DE84(&gUnknown_203B304->unkC);
            break;
        case JOB_LIST_MENU:
            InitializeJobListMenu(0);
            break;
        case PKMN_NEWS_MENU:
            sub_802B640(0, 0, 8);
            break;
        case PKMN_NEWS_MENU_1:
            sub_802B7D0(1);
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
