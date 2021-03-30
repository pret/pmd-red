#ifndef CODE_8041D5C_H
#define CODE_8041D5C_H

struct subStruct_8048524
{
    u8 fill0[0x6];
    u8 unk6;
    u8 unk7;
    u8 fill8[0xAC - 0x8];
    u8 unkAC;
    u8 fillAD[0x112 - 0xAD];
    u8 unk112;
    u8 fill113[0x13C - 0x113];
    u32 unk13C;
};

struct unkDungeon_8041D5C
{
    u8 padding[0x70];
    struct subStruct_8048524 *unk70;
};

#endif
