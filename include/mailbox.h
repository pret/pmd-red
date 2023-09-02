#ifndef GUARD_MAILBOX_H
#define GUARD_MAILBOX_H 

#include "menu.h"
#include "text.h"
#include "constants/mailbox.h"
#include "code_802C39C.h"

struct unkStruct_203B304
{
    // size: 0xB6 << 1
    u32 state;
    u32 fallbackState;
    u8 mailboxIndex;
    u8 mailIndex;
    struct unkStruct_802C39C unkC;
    u32 menuAction1;
    u32 menuAction2;
    MenuStruct unk6C;
    MenuItem menuItems[8];
    u16 unkFC[8];
    UnkTextStruct2 unk10C[4];
};

extern void SetMailboxState(u32);
extern s32 GetNumAcceptedJobs(void);

enum MailBoxStates {
    INITIALIZE_MAILBOX,
    MAIN_MAILBOX_MENU,
    // 2 is ???
    MAILBOX_EXIT = 3,
    MAIL_MENU = 4,
    MAIL_MENU_1 = 5,
    MAIL_ACTION_MENU = 6,
    MAIL_INFO = 7,
    JOB_LIST_MENU = 8,
    PKMN_NEWS_MENU = 0x9,
    PKMN_NEWS_MENU_1 = 0xA,
    DISPLAY_SEL_PKMN_NEWS = 0xB,
};

#endif // GUARD_MAILBOX_H
