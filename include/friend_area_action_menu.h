#ifndef GUARD_FRIEND_AREA_ACTION_MENU_H
#define GUARD_FRIEND_AREA_ACTION_MENU_H

struct unkStruct_203B2BC
{
    // size: 0x1E0
    u32 state;
    u32 unk4;
    s16 targetPoke;
    u16 unkA;
    u32 itemIndex;
    struct HeldItem itemToGive;
    struct HeldItem item2;
    struct PokemonStruct *unk18;
    u8 unk1C;
    struct unkMoveData moveData20;
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
