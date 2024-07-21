#ifndef INCLUDE_FRIEND_LIST_MENU_H
#define INCLUDE_FRIEND_LIST_MENU_H

// there might be more overlap with unkStruct_203B2BC
// I was working on the moves and put the data that seemed to correspond to that
// into a separate struct
typedef struct unkStruct_203B2B4
{
    // size: 0x178
    s32 unk0;
    s32 state;
    u32 fallbackState;
    u8 unkC; // friend Area
    u8 unkD; // friend Area
    s16 species;
    u32 itemIndex;
    BulkItem item1;
    BulkItem item2;
    /* 0x1C */ PokemonStruct1 *pokeStruct;
    u32 moveIndex; // some sort of move index
    u16 moveID;
    Move moves[8];
    u16 moveIDs[4]; // some list of move IDs
    u32 menuAction1;
    s32 menuAction2;
    MenuStruct unk78;
    MenuItem unkC8[8];
    u16 unk108[8];
    UnkTextStruct2 unk118[4];
} unkStruct_203B2B4;

bool8 CreateFriendListMenu(s32 param_1);
u32 sub_8025354(void);
u8 sub_802540C(void);
void CleanFriendListMenu(void);

enum FriendListMenuStates {
    // 0
    // 1
    // 2
    // 3
    FRIEND_LIST_MENU_STATE_SUMMARY = 4,
    FRIEND_LIST_MENU_STATE_CHECK_IQ = 5,
    FRIEND_LIST_MENU_STATE_STANDBY = 7,
    FRIEND_LIST_MENU_STATE_ITEM_GIVEN = 8,
    FRIEND_LIST_MENU_STATE_ITEM_EXCHANGE = 9,
    FRIEND_LIST_MENU_STATE_TAKE = 0xA,
    FRIEND_LIST_MENU_STATE_GIVE = 0xB,
    // 0xC
    // 0xD
    FRIEND_LIST_MENU_STATE_INFO = 0xE,
    FRIEND_LIST_MENU_STATE_MOVES = 0xF,
    // 0x10
    // 0x11
    // 0x12
    FRIEND_LIST_MENU_STATE_EXIT = 0x13
};

enum FriendListMenuActions {
    FRIEND_LIST_MENU_NULL = 1,
    FRIEND_LIST_MENU_INFO = 4,
    FRIEND_LIST_MENU_SUMMARY = 4,
    FRIEND_LIST_MENU_CHECK_IQ = 5,
    FRIEND_LIST_MENU_MOVES,
    FRIEND_LIST_MENU_VISIT,
    // 8
    FRIEND_LIST_MENU_STANDBY = 9,
    FRIEND_LIST_MENU_GIVE = 0xA,
    FRIEND_LIST_MENU_TAKE,

};

#endif
