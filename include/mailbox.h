#ifndef GUARD_MAILBOX_H
#define GUARD_MAILBOX_H

#include "structs/menu.h"
#include "structs/str_text.h"
#include "constants/mailbox.h"
#include "structs/str_802C39C.h"

struct unkStruct_203B304
{
    // size: 0xB6 << 1
    u32 state;
    u32 fallbackState;
    u8 mailboxIndex;
    u8 mailIndex;
    unkStruct_802C39C unkC;
    u32 menuAction1;
    u32 menuAction2;
    MenuStruct unk6C;
    MenuItem menuItems[8];
    u16 unkFC[8];
    WindowTemplates unk10C;
};

enum MailBoxStates
{
    INITIALIZE_MAILBOX,
    MAIN_MAILBOX_MENU,
    // 2
    MAILBOX_EXIT = 3,
    MAIL_MENU,
    MAIL_MENU_1,
    MAIL_ACTION_MENU,
    MAIL_INFO,
    JOB_LIST_MENU,
    PKMN_NEWS_MENU,
    PKMN_NEWS_MENU_1,
    DISPLAY_SEL_PKMN_NEWS,
};

void SetMailboxState(u32);
u8 sub_802DFB0(void);
u32 sub_802DFD8(void);
void sub_802E06C(void);

#endif // GUARD_MAILBOX_H
