#ifndef GUARD_WIGGLYTUFF_SHOP_H
#define GUARD_WIGGLYTUFF_SHOP_H

struct WigglytuffShop 
{
    // size: 0x138
    bool32 isAsleep;
    s32 state;
    s32 fallbackState;
    s32 friendAreaPrice;
    u8 chosenFriendArea;
    s16 chosenSpecies;
    u32 menuAction1;
    u32 menuAction2;
    struct MenuItem unk1C[8];
    u16 unk5C[0x8];
    struct MenuStruct unk6C;
    /* 0xBC */ struct OpenedFile *faceFile;
    /* 0xC0 */ u8 *faceData;
    u16 unkC4;
    u16 unkC6;
    u8 unkC8;
    u8 unkC9;
    u8 unkCA;
    u8 fillCB;
    u8 *unkCC;
    struct UnkTextStruct2 unkD0[4];
    u32 unk130;
    u32 unk134;
};

extern struct WigglytuffShop *gWigglytuffShop;


#endif // GUARD_WIGGLYTUFF_SHOP_H
