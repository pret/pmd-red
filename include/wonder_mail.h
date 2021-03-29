#ifndef GUARD_WONDER_MAIL_H
#define GUARD_WONDER_MAIL_H

#include "file_system.h"

struct WonderMailStruct_203B2C0
{
    u32 unk0;
    u32 unk4;
    u8 unk8[0x36];
    u8 unk3E;
    u32 unk40;
    u32 linkError;
    u16 unk48[232];
    u8 unk218;
    u8 padding7[3];
    u32 unk21C;
    u8 padding[0x7C];
    u32 unk29C;
    u8 padding6[0x6C];
    u32 unk30C;
    u8 padding8[0x4C];
    u32 unk35C;
    u8 padding5[0x5C];
    u32 unk3BC;
    u8 padding4[0x60];
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

void sub_8028B04(u32 r0);


#endif
