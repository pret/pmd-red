#ifndef GUARD_SUB_8095228_H
#define GUARD_SUB_8095228_H

struct unkStruct_8095228
{
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 padding[0x10 - 0x5];
    u32 unk10;
    u8 padding2[0x20 - 0x14];
    struct ItemSlot unk20;
    u8 padding3[0x28 - 0x24];
    u32 unk28;
    s8 unk2C;
    u8 padding4[0x30 - 0x2D];
};

extern struct unkStruct_8095228 *sub_8095228(u8);

#endif // GUARD_SUB_8095228_H
