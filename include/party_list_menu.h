#ifndef GUARD_PARTY_LIST_MENU_H
#define GUARD_PARTY_LIST_MENU_H

#include "constants/move.h"
#include "items.h"
#include "menu.h"
#include "pokemon.h"
#include "text.h"

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
    UnkTextStruct2 unk220[4];
} unkStruct_203B2B8;

bool8 sub_8025EF4(PokemonStruct1 *pokeStruct);
u32 sub_8025F68(void);
bool8 sub_802604C(void);
void sub_8026058(void);

#endif // GUARD_PARTY_LIST_MENU_H