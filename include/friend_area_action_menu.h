#ifndef GUARD_FRIEND_AREA_ACTION_MENU_H
#define GUARD_FRIEND_AREA_ACTION_MENU_H

struct unkStruct_203B2BC
{
    // size: 0x1E0
    u32 state;
    u32 fallbackState;
    s16 targetPoke;
    u16 unkA;
    u32 id;
    struct BulkItem itemToGive;
    struct BulkItem item2;
    struct PokemonStruct *unk18;
    bool8 isTeamLeader;
    u32 moveIndex;  // some sort of move index
    u16 moveID;
    struct Move moves[8];
    u16 moveIDs[4];   // some list of move IDs

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

enum FriendAreaActionMenuStates {
    FRIEND_AREA_ACTION_MENU_INIT,
    FRIEND_AREA_ACTION_MENU_EXIT = 0x11,
};

#endif
