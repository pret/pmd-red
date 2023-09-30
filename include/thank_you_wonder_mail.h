#ifndef GUARD_THANK_YOU_WONDER_MAIL_H
#define GUARD_THANK_YOU_WONDER_MAIL_H

#include "constants/wonder_mail.h"
#include "file_system.h"
#include "structs/menu.h"
#include "structs/str_items.h"
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
    UnkTextStruct2 unk35C[4];
    UnkTextStruct2 unk3BC[4];
    Item unk41C;
    /* 0x420 */ OpenedFile *faceFile;
    /* 0x424 */ u8 *faceData;
    u16 unk428;
    u16 unk42A;
    u8 unk42C;
    u8 unk42D;
    u8 unk42E;
    u32 unk430;
    /* 0x434 */ u8 formattedString[0x100];
    /* 0x534 */ s32 wonderMailMethod;
    /* 0x538 */ u32 wonderMailMode;
    unkStruct_802F204 unk53C;
} WonderMailStruct_203B2C4;

#endif // GUARD_THANK_YOU_WONDER_MAIL_H