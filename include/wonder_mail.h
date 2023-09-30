#ifndef GUARD_WONDER_MAIL_H
#define GUARD_WONDER_MAIL_H

#include "constants/wonder_mail.h"
#include "file_system.h"
#include "structs/menu.h"
#include "structs/str_wonder_mail.h"

// size: 0x548
typedef struct WonderMailStruct_203B2C0
{
    /* 0x0 */ u32 fallbackState;
    /* 0x4 */ u32 state;
    /* 0x8 */ u8 passwordBuffer[PASSWORD_BUFFER_SIZE];
    u8 unk3E;
    u32 unk40;
    /* 0x44 */ u32 linkError;
    unkStruct_203B480 unk48;
    unkStruct_203B480 unk78;
    WonderMailStruct_203B2C0_sub unkA8;
    WonderMailStruct_203B2C0_sub unk130;
    u8 fill16A[0x218 - 0x1B8];
    /* 0x218 */ u8 mailIndex;
    MenuStruct unk21C[4];
    UnkTextStruct2 unk35C[4];
    UnkTextStruct2 unk3BC[4];
    /* 0x41C */ u32 unkfill; // ItemSlot?
    /* 0x420 */ OpenedFile *faceFile;
    /* 0x424 */ u8 *faceData;
    u16 unk428;
    u16 unk42A;
    u8 unk42C;
    u8 unk42D;
    u8 unk42E;
    /* 0x430 */ u8 padding3[0x534 - 0x430];
    u32 unk534;
    s32 unk538; // A7 << 3
    u32 unk53C;
    /* 0x540 */ u32 mailCount; // A8 << 4
    /* 0x544 */ s16 speciesNum;
} WonderMailStruct_203B2C0;

#endif // GUARD_WONDER_MAIL_H