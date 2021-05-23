#ifndef KECLEON_ITEMS_H
#define KECLEON_ITEMS_H

#include "gUnknown_203B460.h"

struct unkData
{
    u8 unk0[24];
};

struct unkStruct_203B210
{
    // size: 0x148
    u32 unk0;
    u8 unk4;
    u8 fill5[3];
    u32 currState;
    u32 unkC;
    s32 unk10;
    u32 unk14;
    u32 unk18;
    struct ItemStruct_203B460 unk1C;
    u32 unk20;
    u32 unk24;
    u32 unk28;
    u32 unk2C;
    u32 unk30;
    u8 fill34[0x84 - 0x34];
    u32 unk84;
    u8 fill88[0xD4 - 0x88];
    struct OpenedFile *faceFile;
    u8 *unkD8;
    u16 unkDC;
    u16 unkDE;
    u8 unkE0;
    u8 unkE1;
    u8 unkE2;
    u8 unkE3;
    struct OpenedFile **unkE4;
    struct unkData unkE8[4];
};

#endif
