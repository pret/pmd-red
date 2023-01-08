#ifndef GUARD_KECLEON_ITEMS_H
#define GUARD_KECLEON_ITEMS_H

#include "team_inventory.h"
#include "text.h"
#include "menu.h"

struct unkStruct_203B210
{
    // size: 0x148
    u32 unk0;
    bool8 unk4;
    u8 fill5[3];
    u32 currState;
    u32 unkC;
    s32 itemSellPrice;
    u32 unk14;
    s32 unk18;
    struct Item unk1C;
    u8 unk20;
    u8 unk21;
    u8 unk22;
    u8 unk23;
    u32 unk24;
    u32 unk28;
    u32 unk2C;
    u32 unk30;
    struct MenuItem unk34[8];
    u16 unk74[8];
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
    struct UnkTextStruct2 unkE8[4];
};

struct unkStruct_203B224
{
    // size: 0xF4
    u32 unk0;

    u32 unk4[INVENTORY_SIZE];
    u32 unk54;
    u8 fill58[0x6C - 0x58];
    s16 unk6C;
    s16 unk6E;
    s16 unk70;
    s16 unk72;
    u16 unk74;
    u16 unk76;
    u8 fill78[0x88 - 0x78];
    u32 unk88;
    struct UnkTextStruct2 *unk8C;
    struct UnkTextStruct2 unk90[4];
    u8 unkF0[4];
};

#endif // GUARD_KECLEON_ITEMS_H
