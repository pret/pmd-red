#ifndef GUARD_EXCLUSIVE_POKEMON_H
#define GUARD_EXCLUSIVE_POKEMON_H

#include "code_8092334.h"


#define NUM_EXCLUSIVE_POKEMON 12

struct ExclusivePokemon
{
    s16 poke_id;
    bool8 in_rrt; // red rescue team
    bool8 in_brt; // blue rescue team
};

struct ExclusivePokemonData
{
    u8 unk0;
    u32 unk4[1];
    u8 fill8[0x3C - 8];
    u32 unk3C[1];
    u8 fill40[8];
    u32 unk48[3];
    u32 unk54[1];
    /* 0x58 */ bool8 Exclusives[NUM_EXCLUSIVE_POKEMON];
};

#define RED_EXCLUSIVE(species)  \
{                               \
    .poke_id = species,         \
    .in_rrt = TRUE,             \
    .in_brt = FALSE,            \
}

#define BLUE_EXCLUSIVE(species) \
{                               \
    .poke_id = species,         \
    .in_rrt = FALSE,            \
    .in_brt = TRUE,             \
}

extern struct ExclusivePokemonData *gUnknown_203B498;

void LoadExclusivePokemon(void);
struct ExclusivePokemonData *GetExclusivePokemon(void);
void InitializeExclusivePokemon(void);
void sub_8097FA8(u8 param_1);
void sub_8097FD0(u8 param_1);
void sub_8097FF8(void);
void sub_8098044(u8 param_1);
void sub_8098080(void);
u32 sub_80980A4(void);
void sub_80980B4(s16 pokeID);
bool8 sub_8098100(u8 param_1);
bool8 sub_8098134(s16 pokeID);
void SetTutorialFlag(s32 param_1);
bool32 GetTutorialFlag(s32 param_1);
bool8 IsExclusivePokemonUnlocked(s16 pokeID);
void UnlockExclusivePokemon(s16 pokeID);
void WriteExclusivePokemon(struct unkStruct_8094924 *r0);
void ReadExclusivePokemon(struct unkStruct_8094924 *r0);

#endif // GUARD_EXCLUSIVE_POKEMON_H
