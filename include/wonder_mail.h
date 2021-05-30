#ifndef GUARD_WONDER_MAIL_H
#define GUARD_WONDER_MAIL_H

#include "file_system.h"
#include "text.h"

#define PASSWORD_BUFFER_SIZE 0x36


struct WonderMailStruct_203B2C0
{
    // size: 0x548
    u32 unk0;
    u32 state;
    u8 passwordBuffer[PASSWORD_BUFFER_SIZE];
    u8 unk3E;
    u32 unk40;
    u32 linkError;
    u16 unk48[232];
    u8 unk218;
    u32 unk21C;
    u8 padding[0x7C];
    u32 unk29C;
    u8 padding6[0x6C];
    u32 unk30C;
    u8 padding8[0x4C];
    u32 unk35C;
    u8 padding5[0x5C];
    struct UnkTextStruct2 unk3BC[4];
    u32 unkfill; // unkStruct_41C?
    struct OpenedFile *faceFile;
    u8 *faceData;
    u16 unk428;
    u16 unk42A;
    u8 unk42C;
    u8 unk42D;
    u8 unk42E;
    u8 padding3[0x534 - 0x430];
    u32 unk534;
    s32 unk538; // A7 << 3
    u32 unk53C;
    u32 unk540; // A8 << 4
    s16 unk544;

};

struct unkStruct_41C
{
    u8 unk41C;
    u8 unk41D;
    u8 unk41E;
    u8 unk41F;
};

struct WonderMailStruct_203B2C4
{
    // size: 0x564
    u8 unk0;
    u32 unk4; // wonder mail link status??
    u8 passwordBuffer[PASSWORD_BUFFER_SIZE]; // Probably a buffer for entry
    u8 unk3E;
    u32 unk40;
    u32 linkError; // another link status
    u8 filler48[0x218 - 0x48];
    s8 unk218;
    u32 unk21C;
    u8 filler220[0x30C - 0x220];
    u32 unk30C;
    u8 filler310[0x35C - 0x310];
    u32 unk35C;
    u8 filler360[0x3BC - 0x360];
    struct UnkTextStruct2 unk3BC[4];
    struct unkStruct_41C unk41C;
    /* 0x420 */ struct OpenedFile *faceFile;
    /* 0x424 */ u8 *faceData;
    u16 unk428;
    u16 unk42A;
    u8 unk42C;
    u8 unk42D;
    u8 unk42E;
    u32 unk430;
    u8 padding3[0x534 - 0x434];
    s32 unk534;
    u32 unk538;
    u8 fill53C[0x564 - 0x53C];
};

void sub_8028B04(u32 r0);


#endif
