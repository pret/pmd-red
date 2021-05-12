#ifndef GUNKNOWN_203B460_H
#define GUNKNOWN_203B460_H

struct subStruct_203B460
{
    u8 unk0;
    u8 numItems;
    u8 itemIndex;
};

struct unkStruct_203B460
{
    struct subStruct_203B460 fill0[20];
    u16 unk50[0x10];
    u8 fill70[0x260 -  0x70];
    /* 0x260 */ s32 teamMoney;
    /* 0x264 */ u32 teamSavings;
};

#endif
