#ifndef GUARD_FRIEND_AREA_ACTION_MENU_H
#define GUARD_FRIEND_AREA_ACTION_MENU_H

struct unkSubStruct_203B2BC
{
    u8 fill0[0x2C];
    u32 unk2C;
};


struct unkStruct_203B2BC
{
    // size: 0x1E0
    u32 state;
    u32 unk4;
    s16 unk8;
    u16 unkA;
    u32 unkC;
    struct HeldItem unk10;
    struct ItemSlot unk14;
    struct unkSubStruct_203B2BC *unk18;
    u32 unk1C;
    u32 unk20;
    u32 unk24;
    u32 unk28;
    u8 fill2C[0x68 - 0x2C];
    u32 unk68;
    u32 unk6C;
    u32 unk70;
    s32 unk74;
    u32 unk78;
    u32 unk7C;
    u8 fill80[0xFD - 0x80];
    u32 unkFD;
    u8 fill101[0x11C - 0x104];
    struct MenuItem menuItems[4];
    u8 fill120[0x16C - 0x13C];

    // Structure of some sort
    u32 unk16C;
    u8 fill170[0x180 - 0x170];

    struct UnkTextStruct2 unk180[4];
};

#endif
