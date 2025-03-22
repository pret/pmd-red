#ifndef GUARD_THANK_YOU_WONDER_MAIL_H
#define GUARD_THANK_YOU_WONDER_MAIL_H

#include "constants/wonder_mail.h"
#include "structs/menu.h"
#include "structs/str_items.h"
#include "structs/str_mon_portrait.h"
#include "structs/str_text.h"
#include "structs/str_wonder_mail.h"

// size: 0x564
typedef struct WonderMailStruct_203B2C4
{
    /* 0x0 */ u8 state;
    /* 0x4 */ u32 fallbackState; // wonder mail link status??
    /* 0x8 */ u8 passwordBuffer[PASSWORD_BUFFER_SIZE]; // Probably a buffer for entry
    u8 unk3E;
    u32 unk40;
    /* 0x44 */ u32 linkError; // another link status
    u8 filler48[0x1B8 - 0x48];
    unkStruct_203B480 unk1B8;
    unkStruct_203B480 unk1E8;
    /* 0x218 */ s8 mailIndex;
    MenuStruct unk21C[4];
    WindowTemplates unk35C;
    WindowTemplates unk3BC;
    Item unk41C;
    /* 0x420 */ MonPortraitMsg monPortrait;
    u32 unk430;
    /* 0x434 */ u8 formattedString[0x100];
    /* 0x534 */ s32 wonderMailMethod;
    /* 0x538 */ u32 wonderMailMode;
    unkStruct_802F204 unk53C;
} WonderMailStruct_203B2C4;

#endif // GUARD_THANK_YOU_WONDER_MAIL_H
