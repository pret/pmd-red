#ifndef GUARD_CODE_800E9A8_H
#define GUARD_CODE_800E9A8_H

struct unkStruct_203B0CC_sub
{
    // size: 0xD0
    u32 unk0;
    s32 unk4;
    u8 fill8[0x34 - 8];
    u32 unk34;
    u32 unk38;
    u8 fill3C[0x4C - 0x3C];
    u32 unk4C;
    s32 unk50;
    u8 unk54;
    u8 fill55[0xB8 - 0x55];
    u32 unkB8;
    u8 fillBC[0xD0 - 0xBC];
};

struct unkStruct_203B0CC
{
    // size: 0x1A18
    struct unkStruct_203B0CC_sub unk0[0x20];
    u32 unk1A00;
    /* 0x1A04 */ u32 fileSelection;
    u32 unk1A08;
    u32 unk1A0C;
    u32 unk1A10;
    u8 fill1A14[0x1A18 - 0x1A14];
};

bool8 sub_800E9A8(s32 a0);
bool8 sub_800E9E4(void);
bool8 sub_800E9FC(u8 a0);

#endif
