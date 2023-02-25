#ifndef GUARD_KANGASKHAN_STORAGE_H
#define GUARD_KANGASKHAN_STORAGE_H

#include "text.h"
#include "menu.h"
#include "item.h"

struct unkStruct_203B208
{
    // size: 0x14C
    u32 unk0;
    u32 currState;
    u32 unk8;
    struct Item unkC;
    u32 unk10;
    u8 id; // another id?
    u8 fill15[0x3];
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    struct MenuItem unk24[5];
    u16 unk4C[5];
    struct MenuStruct unk58;
    u32 unkA8;
    u8 unkAC[0xBC - 0xAC];
    u32 unkBC;
    u8 unkC0[0xD4 - 0xC0];
    u32 unkD4;
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

struct unkStruct_203B20C
{
    u32 state;
    u8 unk4[4];
    struct Item unk8;
    u32 unkC;
    u8 id;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    struct MenuItem unk20[8];
    u16 unk60[8];
    struct MenuStruct unk70;
    u32 unkC0;
    u32 unkC4;
    u32 unkC8;
    u32 unkCC;
    u32 unkD0;
    u32 unkD4;
    struct UnkTextStruct2 *unkD8;
    u32 unkDC;
    u32 unkE0;
    u8 fillE4[0xF0 - 0xE4];
    struct UnkTextStruct2 unkF0[4];
};

#endif
