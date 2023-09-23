#ifndef GUARD_MAILBOX_8095F8C_H
#define GUARD_MAILBOX_8095F8C_H

#include "wonder_mail.h"

WonderMail *GetMailboxSlotInfo(u8 index);
bool8 IsMailSlotEmpty(u8 index);
void ResetMailboxSlot(u8 index);

#endif // GUARD_MAILBOX_8095F8C_H