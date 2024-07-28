#ifndef GUARD_WONDER_MAIL_802C4C8_H
#define GUARD_WONDER_MAIL_802C4C8_H

#include "structs/str_text.h"

void DrawJobListMenu(void);
bool8 HasNoAcceptedJobs(void);
u8 GetPelipperBoardSlotIndex(void);

bool8 sub_802C4C8(s32, UnkTextStruct2_sub *, u32);
u32 sub_802C598(bool8);
void sub_802C640(bool8 cursorSprite);
void sub_802C688(void);

#endif // GUARD_WONDER_MAIL_802C4C8_H
