#ifndef GUARD_WONDER_MAIL_802D098_H
#define GUARD_WONDER_MAIL_802D098_H

#include "structs/str_802C39C.h"
#include "structs/menu.h"
#include "structs/str_text.h"
#include "structs/str_wonder_mail.h"

// size: 0x1C
typedef struct unkSubStruct_203B2F8
{
    /* 0x0 */ WonderMail wonderMail;
    u8 *unk14;
    u8 *unk18;
} unkSubStruct_203B2F8;

// size: 0x208
typedef struct unkStruct_203B2F8
{
    /* 0x0 */ s32 state;
    /* 0x4 */ s32 fallbackState;
    /* 0x8 */ u8 wonderMailAccepted;
    bool8 unk9;
    /* 0xA */ u8 dungeonID;
    u8 unkB;
    /* 0xC */ unkSubStruct_203B2F8 *mail;
    /* 0x10 */ u8 jobSlotIndex;
    unkStruct_802C39C unk14;
    /* 0x6C */ u32 menuAction1;
    /* 0x70 */ u32 menuAction2;
    /* 0x74 */ u32 menuAction3;
    MenuStruct unk78;
    MenuStruct unkC8;
    MenuItem unk118[8];
    MenuItem unk158[8];
    u16 unk198[8];
    WindowTemplates unk1A8;
} unkStruct_203B2F8;

bool8 GetWonderMailAccepted(void);

bool8 sub_802D098(unkSubStruct_203B2F8 *mail);
u32 sub_802D0E0(void);
void sub_802D184(void);

#endif // GUARD_WONDER_MAIL_802D098_H