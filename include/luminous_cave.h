#ifndef GUARD_LUMINOUS_CAVE_H
#define GUARD_LUMINOUS_CAVE_H

#include "file_system.h"
#include "items.h"
#include "structs/menu.h"
#include "pokemon_3.h"
#include "structs/str_text.h"

// size: 0x174
typedef struct LuminousCaveWork
{
    /* 0x0 */ bool8 evolutionComplete;
    /* 0x4 */ EvolveStatus evolveStatus;
    /* 0xC */ PokemonStruct1 *pokeStruct;
    /* 0x10 */ bool8 pokeRenamed;
    /* 0x14 */ u32 evoItem1_InvIndex; // inventory index of item
    /* 0x18 */ u32 evoItem2_InvIndex; // inventory index of item
    /* 0x1C */ Item chosenItem;
    /* 0x20 */ u32 state;
    /* 0x24 */ u32 fallbackState;
    /* 0x28 */ u32 menuAction1;
    /* 0x2C */ u32 menuAction2;
    /* 0x30 */ u32 menuAction3;
    MenuItem unk34[8];
    u16 unk74[0x8];
    MenuStruct unk84;
    u8 fillD4[0x104 - 0xD4];
    OpenedFile *unk104;
    u8 *unk108;
    u16 unk10C;
    u16 unk10E;
    u8 unk110;
    u8 unk111;
    u8 unk112;
    UnkTextStruct2 unk114[4];
} LuminousCaveWork;

void CleanLuminousCave(void);
bool8 HasEvolutionCompleted(void);

u32 sub_802465C(void);
u32 sub_80246F0(void);

#endif // GUARD_LUMINOUS_CAVE_H