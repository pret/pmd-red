#ifndef GUARD_WONDER_MAIL_802C4C8_H
#define GUARD_WONDER_MAIL_802C4C8_H

#include "constants/mailbox.h"
#include "structs/menu.h"
#include "structs/str_text.h"

// size: 0xA8
struct unkStruct_203B2E8
{
    /* 0x0 */ u8 pelipperBoardSlots[MAX_ACCEPTED_JOBS];
    /* 0x8 */ MenuInputStruct input;
    u32 unk3C;
    UnkTextStruct2 *unk40;
    UnkTextStruct2 unk44[4];
    u8 unkA4[4];
};

void DrawJobListMenu(void);
bool8 HasNoAcceptedJobs(void);
u8 GetPelipperBoardSlotIndex(void);

bool8 sub_802C4C8(s32, UnkTextStruct2_sub *, u32);
u32 sub_802C598(bool8);
void sub_802C640(bool8 cursorSprite);
void sub_802C688(void);

#endif // GUARD_WONDER_MAIL_802C4C8_H