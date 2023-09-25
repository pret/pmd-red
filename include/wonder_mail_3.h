#ifndef GUARD_WONDER_MAIL_3_H
#define GUARD_WONDER_MAIL_3_H

#include "code_802C39C.h"
#include "input.h"
#include "structs/menu.h"
#include "structs/str_text.h"
#include "wonder_mail.h"

// size: 0xB4
typedef struct unkStruct_803B344
{
    /* 0x0 */ WonderMail mail;
    u8 *unk14;
    u8 *unk18;
    u8 fill1C[0x3C - 0x1C];
    u8 unk3C[0xB4 - 0x3C];
} unkStruct_803B344;

// size: 0xA0
typedef struct unkStruct_203B2F4
{
    MenuInputStruct input;
    u32 unk34;
    UnkTextStruct2 *unk38;
    UnkTextStruct2 unk3C[4];
    u8 unk9C[4];
} unkStruct_203B2F4;

// size: 0x1C
typedef struct unkSubStruct_203B2F8
{
    /* 0x0 */ WonderMail wonderMail;
    /* 0x14 */ u8 *unk14;
    /* 0x18 */ u8 *unk18;
} unkSubStruct_203B2F8;

// size: 0x208
typedef struct unkStruct_203B2F8
{
    /* 0x0 */ s32 state;
    /* 0x4 */ s32 fallbackState;
    /* 0x8 */ u8 wonderMailAccepted;
    /* 0x9 */ bool8 unk9;
    /* 0xA */ u8 dungeonID;
    u8 unkB;
    /* 0xC */ unkSubStruct_203B2F8 *mail;
    /* 0x10 */ u8 jobSlotIndex;
    unkStruct_802C39C unk14;
    /* 0x6C */ u32 menuAction1;
    /* 0x70 */ u32 menuAction2;
    /* 0x74 */ u32 menuAction3;
    /* 0x78 */ MenuStruct unk78;
    /* 0xC8 */ MenuStruct unkC8;
    MenuItem unk118[8];
    MenuItem unk158[8];
    u16 unk198[8];
    UnkTextStruct2 unk1A8[4];
} unkStruct_203B2F8;

enum WonderMailRescueStates
{
    INITIAL_WONDER_MAIL_CHECK = 0,
    // 1
    WONDER_MAIL_EXIT = 2,
    DUPLICATE_WONDER_MAIL,
    DUPLICATE_WONDER_MAIL_1,
    // 5 - 7
    RECEIVE_WONDER_MAIL = 8,
    // 9
    JOB_LIST_FULL = 10,
    DRAW_JOB_LIST,
    DRAW_JOB_LIST_1,
    // 13 - 16
};

u32 sub_802D098(unkSubStruct_203B2F8 *mail);

#endif // GUARD_WONDER_MAIL_3_H