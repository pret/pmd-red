#ifndef GUARD_CODE_8096AF8_H
#define GUARD_CODE_8096AF8_H

#include "structs/str_wonder_mail.h"

extern void sub_8096C80(void);
void ReceivePKMNNews(u8 index);
bool8 CheckPKMNNewsSlot(u8 index);
void SortJobSlots(void);
u8 *sub_8096DD8(void);
u8 *sub_8096DE8(void);
u8 sub_8096E2C(void);
void sub_8096EEC(WonderMail *mail);

#endif // GUARD_CODE_8096AF8_H
