#ifndef GUARD_TEXT_H
#define GUARD_TEXT_H

// size: 0x48
struct UnkTextStruct1
{
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14;
    u8 *unk18;
    u8 *unk1C;
    s32 unk20;
    s32 unk24;
    void *unk28; // Somewhere in VRAM
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
    u8 fill3C[0x45 - 0x3C];
    bool8 unk45;
    u8 unk46;
};

// size: 0x4
struct UnkTextStruct2_sub
{
    // I haven't found a func that reads these separately yet, but simply making an arr[2] will cause assignments to break.
    // Some funcs only match with this union for some reason even though they don't access the variables separately...
    // The first func to break is currently sub_801A5D8 in kecleon_bros.c
    // The first func I matched that uses the array is sub_8006554 in text2.c (using the separated fields doesn't match or get even close)
    union {
        struct {
        s16 unk0;
        s16 unk2;
        } separate;
        s16 arr[2];
    } unk0;
};

// size: 0x18
struct UnkTextStruct2
{
    u8 unk0;
    u8 fill1[0x4 - 0x1];
    s32 unk4;
    struct UnkTextStruct2_sub unk8;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12;
    const u8 *unk14;
};

#endif