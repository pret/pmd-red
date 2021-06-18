#ifndef KANGASKHAN_STORAGE_H
#define KANGASKHAN_STORAGE_H

#include "text.h"
#include "menu.h"

struct unkStruct_203B208
{
    // size: 0x14C
    u32 unk0;
    u32 currState;
    u32 unk8;
    u16 unkC;
    u8 itemIndex;
    u8 unkF;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    struct MenuItem unk24[5];
    u16 unk4C[5];
    u32 unk58;
    u8 unk5C[0xA8 - 0x5C];
    u32 unkA8;
    u8 unkAC[0xBC - 0xAC];
    u32 unkBC;
    u8 unkC0[0xD8 - 0xC0];
    struct OpenedFile *faceFile;
    u8 *faceData;
    u16 unkE0;
    u16 unkE2;
    u8 unkE4;
    u8 unkE5;
    u8 unkE6;
    u8 unkE7;
    struct OpenedFile **unkE8;
    struct UnkTextStruct2 unkEC[4];
};

#endif
