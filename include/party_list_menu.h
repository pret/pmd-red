#ifndef GUARD_PARTY_LIST_MENU_H
#define GUARD_PARTY_LIST_MENU_H

#include "constants/move.h"
#include "items.h"
#include "structs/menu.h"
#include "pokemon.h"
#include "structs/str_text.h"

// size: 0x280
typedef struct unkStruct_203B2B8
{
    /* 0x0 */ s32 state;
    /* 0x4 */ s32 fallbackState;
    bool8 unk8;
    /* 0xA */ s16 pokeSpecies;
    /* 0xC */ u32 id;
    /* 0x10 */ BulkItem item1;
    /* 0x14 */ BulkItem item2;
    /* 0x18 */ PokemonStruct1 *pokeStruct;
    /* 0x1C */ bool8 isTeamLeader;
    /* 0x20 */ u32 moveIndex;
    /* 0x24 */ u16 moveID;
    /* 0x28 */ Move moves[8];
    /* 0x68 */ u16 moveIDs[4]; // some list of move IDs
    /* 0x70 */ u32 menuAction1;
    /* 0x74 */ u32 menuAction2;
    /* 0x78 */ u32 menuAction3; // unused
    MenuStruct unk7C;
    MenuStruct unkCC;
    MenuStruct unk11C; // unused
    MenuItem unk16C[10];
    MenuItem unk1BC[10];
    u16 unk20C[10];
    WindowTemplates unk220;
} unkStruct_203B2B8;

bool8 CreatePartyListMenu(PokemonStruct1 *pokeStruct);
u32 sub_8025F68(void);
bool8 sub_802604C(void);
void CleanPartyListMenu(void);

enum PartyListMenuStates
{
    PARTY_LIST_STATE_INIT,
    PARTY_LIST_STATE_MAIN_MENU,
    PARTY_LIST_STATE_MAIN_MENU_1,
    PARTY_LIST_STATE_SUMMARY = 3,
    PARTY_LIST_STATE_CHECK_IQ = 4,
    PARTY_LIST_STATE_JOIN_TEAM = 5,
    PARTY_LIST_STATE_STANDBY = 6,
    PARTY_LIST_STATE_MAKE_LEADER = 7,
    PARTY_LIST_STATE_POKEMON_FAREWELL = 8,
    // 9
    // 0xA
    // 0xB
    PARTY_LIST_STATE_SAY_FAREWELL = 0xC,
    PARTY_LIST_STATE_CONFIRM_SAY_FAREWELL = 0xD,
    PARTY_LIST_STATE_GIVE_GUMMI = 0xe,
    PARTY_LIST_STATE_GIVEN_ITEM = 0xF,
    PARTY_LIST_STATE_GIVEN_ITEM_HELD_ITEM = 0x10,
    PARTY_LIST_STATE_TAKE_ITEM = 0x11,
    PARTY_LIST_STATE_GIVE_ITEM = 0x12,
    PARTY_LIST_STATE_GIVE_ITEM_1 = 0x13,
    // 0x14
    // 0x15
    PARTY_LIST_STATE_MOVES = 0x16,
    // 0x17
    // 0x18
    PARTY_LIST_STATE_EXIT = 0x19,

};

enum PartyListMenuActions
{
    PARTY_LIST_MENU_NULL = 1,
    PARTY_LIST_MENU_YES,
    PARTY_LIST_MENU_NO,
    PARTY_LIST_MENU_INFO = 4,
    PARTY_LIST_MENU_SUMMARY = 4,
    PARTY_LIST_MENU_CHECK_IQ,
    PARTY_LIST_MENU_JOIN_TEAM,
    PARTY_LIST_MENU_STANDBY,
    PARTY_LIST_MENU_MAKE_LEADER,
    PARTY_LIST_MENU_SAY_FAREWELL,
    PARTY_LIST_MENU_GIVE_GUMMI,
    PARTY_LIST_MENU_GIVE_ITEM,
    PARTY_LIST_MENU_TAKE_ITEM,
    PARTY_LIST_MENU_MOVES,
};

#endif // GUARD_PARTY_LIST_MENU_H
