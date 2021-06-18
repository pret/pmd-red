#ifndef GUNKNOWN_203B460_H
#define GUNKNOWN_203B460_H

struct ItemStruct_203B460
{
    u8 unk0;
    u8 numItems;
    u8 itemIndex;
};

struct subStruct_203B460
{
    u8 unk0;
    u8 unk1;
};

struct unkStruct_203B460
{
    struct ItemStruct_203B460 fill0[20];
    u16 unk50[0xF0];
    struct subStruct_203B460 unk230[8];
    struct subStruct_203B460 unk250[4]; // TODO: idk if this is identical struct or not.. Ghidra says sizes are same
    /* 0x260 */ s32 teamMoney;
    /* 0x264 */ u32 teamSavings;
};

#endif
