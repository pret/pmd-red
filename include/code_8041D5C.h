#ifndef GUARD_CODE_8041D5C_H
#define GUARD_CODE_8041D5C_H

struct subStruct_8048524
{
    u8 fill0[0x6];
    u8 unk6;
    u8 unk7;
    u8 fill8[0xE - 0x8];
    /* 0xE */ s16 HP; // HP??
    s16 unk10;
    u8 fill12[0x46 - 0x12];
    s8 unk46;
    u8 fill47[0xA4 - 0x47];
    u8 unkA4;
    u8 fillA5[0xAC - 0xA5];
    /* 0xAC */ u8 statusCondition;
    u8 fillAD[0xFB - 0xAD];
    u8 unkFB;
    u8 fillFC[0x112 - 0xFC];
    u8 unk112;
    u8 fill113[0x13C - 0x113];
    u32 unk13C;
    u8 fill140[0x15C - 0x140];
    u8 unk15C;
    u8 unk15D;
    u8 unk15E;
    u8 unk15F;
    u8 fill160[0x174 - 0x160];
    u32 unk174;
};

struct unkDungeon_8041D5C
{
    u8 fill0[4];
    s16 unk4;
    s16 unk6;
    u32 unk8;
    s32 unkC;
    s32 unk10;
    u8 fill14[0x20 - 0x14];
    u8 unk20;
    u8 unk21[0x70 - 0x21];
    struct subStruct_8048524 *unk70;
};

#endif
