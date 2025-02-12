#ifndef GUARD_STR_3001B64_H
#define GUARD_STR_3001B64_H

#include "file_system.h"

// Maybe Position32?
struct unkStruct_3001B64_sub_sub
{
    s32 a0;
    s32 a4;
};

struct unkStruct_3001B64_sub
{
    // size: 0x24
    s16 unk0;
    /* 0x2 */ s16 speciesID;
    u8 unk4;
    u8 unk5;
    s8 unk6;
    u8 unk7;
    struct unkStruct_3001B64_sub_sub unk8;
    OpenedFile *unk10;
    /* 0x14 */ u8 *faceData;
    u16 unk18;
    u16 unk1A;
    u8 unk1C;
    u8 unk1D;
    u8 unk1E;
    /* 0x20 */ OpenedFile *faceFile;
};

struct unkStruct_3001B64
{
    // size: 0x5A8
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u8 fill10[0x414 - 0x10];
    u32 unk414;
    u32 unk418;
    u32 unk41C;
    u32 unk420;
    u32 unk424;
    u32 unk428;
    u32 unk42C;
    u32 unk430;
    u32 unk434;
    u32 fill438;
    struct unkStruct_3001B64_sub unk43C[10];
    u16 unk5A4;
};

#endif // GUARD_STR_3001B61_H

