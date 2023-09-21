#ifndef GUARD_WONDER_MAIL_2_1_H
#define GUARD_WONDER_MAIL_2_1_H

#include "code_802C39C.h"
#include "constants/mailbox.h"
#include "input.h"
#include "menu.h"
#include "structs/str_text.h"

// size: 0xA8
struct unkStruct_203B2E8
{
    u8 pelipperBoardSlots[MAX_ACCEPTED_JOBS];
    MenuInputStruct input;
    u32 unk3C;
    UnkTextStruct2 *unk40;
    UnkTextStruct2 unk44[4];
    u8 unkA4[4];
};

// size: 0x1FC
struct unkStruct_203B2F0
{
    u32 unk0;
    u32 state;
    u8 unk8[0xC - 0x8];
    u8 unkC;
    unkStruct_802C39C unk10;
    u32 menuAction;
    MenuStruct unk6C;
    MenuStruct unkBC;
    MenuItem unk10C[8];
    MenuItem unk14C[8];
    u8 fill18C[0x19C - 0x18C];
    UnkTextStruct2 unk19C[4];
};

bool8 HasNoAcceptedJobs(void);
bool8 InitializeJobListMenu(u32);

u32 sub_802C898(void);
void sub_802C8F4(void);

#endif // GUARD_WONDER_MAIL_2_1_H