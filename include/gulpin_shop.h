#ifndef GUARD_GULPIN_SHOP_H
#define GUARD_GULPIN_SHOP_H 

struct unkStruct_203B26C
{
// size: 0x18C
    u32 unk0;
    s32 state;
    u32 unk8;
    s16 speciesNum; // species of chosen Pokemon
    u8 unkE;
    struct Move * unk10;
    u32 unk14;
    u32 unk18;
    u16 unk1C;
    u16 unk1E;
    u32 unk20;
    u32 unk24;
    struct MenuItem unk28[8];
    u16 unk68[8];
    u32 unk78;
    u8 fill7C[0x118 - 0x7C]; 
    /* 0x118 */ struct OpenedFile *faceFile;
    /* 0x11C */ u8 *faceData;
    /* 0x120 */ u16 unk120;
    u16 unk122;
    u8 unk124;
    u8 unk125;
    u8 unk126;
    u8 unk127;
    struct OpenedFile **unk128;
    struct UnkTextStruct2 unk12C[4]; 
};

#endif
