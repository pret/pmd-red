#ifndef GUARD_FRIEND_RESCUE_H
#define GUARD_FRIEND_RESCUE_H

struct WonderMailStruct_203B33C
{
    // size: 0x568
    u32 unk0;
    u32 unk4;
    u8 unk8[0x36];
    u32 unk40;
    u32 unk44;
    u16 unk48[232];
    u8 unk218;
    u8 padding7[3];
    u32 unk21C;
    u8 padding[0x7C];
    u32 unk29C;
    u8 padding6[0x6C];
    u32 unk30C;
    u8 padding8[0x4C];
    u32 unk35C;
    u8 padding5[0x5C];
    struct UnkTextStruct2 unk3BC[4];
    struct ItemStruct_203B460 unk41C;
    u32 unk420; // Is this supposed to be a File like 203B2C4?
    u8 fill424[0x524 - 0x424];
    s32 unk524;
    u32 unk528;
    u8 unk52C;
    u8 unk52D;
    u8 fill52E;
    u32 unk530;
    u32 unk534;
    u16 unk538; // A7 << 3
    u32 unk53C;
    u32 unk540; // A8 << 4
    s16 unk544;
    u8 filler546[0x564 - 0x546];
    s32 unk564;
};

#endif
