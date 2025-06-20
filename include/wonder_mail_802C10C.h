#ifndef GUARD_WONDER_MAIL_802C10C_H
#define GUARD_WONDER_MAIL_802C10C_H

#include "constants/mailbox.h"
#include "structs/menu.h"
#include "text_3.h"

// size: 0xA8
struct unkStruct_203B2E0
{
    u8 pelipperBoardSlots[MAX_ACCEPTED_JOBS];
    /* 0x8 */ MenuHeaderWindow unk8;
};

void DrawPelipperBoardJobMenu(void);
bool8 HasNoPelipperBoardJobs(void);

bool8 sub_802C10C(s32, DungeonPos *, s32);
u32 sub_802C1E4(bool8);
u8 sub_802C26C(void);
void sub_802C28C(bool8 cursorSprite);
void sub_802C2D4(void);

#endif // GUARD_WONDER_MAIL_802C10C_H
