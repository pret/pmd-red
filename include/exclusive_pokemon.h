#ifndef GUARD_EXCLUSIVE_POKEMON_H
#define GUARD_EXCLUSIVE_POKEMON_H

#include "constants/cutscenes.h"
#include "constants/tutorial_id.h"
#include "data_serializer.h"

#define NUM_EXCLUSIVE_POKEMON 12

// Size: 0x4
struct ExclusivePokemon
{
    /* 0x0 */ s16 poke_id;
    /* 0x2 */ bool8 in_rrt; // red rescue team
    /* 0x3 */ bool8 in_brt; // blue rescue team
};

typedef struct ExclusivePokemonData
{
    /* 0x00 */ bool8 unk0; // Initialized?
    /* 0x04 */ u32 monSeenFlags[MONSTER_FLAGS_U32STORAGE];
    /* 0x3C */ u32 cutsceneFlags[CUTSCENE_FLAGS_U32STORAGE];
    /* 0x48 */ u32 tempCutsceneFlags[CUTSCENE_FLAGS_U32STORAGE];
    /* 0x54 */ u32 tutorialFlags[TUTORIAL_FLAGS_U32STORAGE];
    /* 0x58 */ bool8 exclusives[NUM_EXCLUSIVE_POKEMON];
} ExclusivePokemonData;

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

extern ExclusivePokemonData *gExclusiveMonPtr;

void LoadExclusivePokemon(void);
ExclusivePokemonData *GetExclusivePokemon(void);
void InitializeExclusivePokemon(void);
void SetTempCutsceneFlag(u8 flag);
void SetCutsceneFlag(u8 flag);
void FlushTempCutsceneFlags(void);
void UnsetCutsceneFlag(u8 flag);
void ClearTempCutsceneFlags(void);
bool8 sub_80980A4(void);
void SetMonSeenFlag(s16 monID);
bool8 GetCutsceneFlag(u8 flag);
bool8 GetMonSeenFlag(s16 monID);
void SetTutorialFlag(s32 flag);
bool8 GetTutorialFlag(s32 flag);
bool8 IsExclusivePokemonUnlocked(s32 pokeID);
void UnlockExclusivePokemon(s16 pokeID);
void WriteExclusivePokemon(DataSerializer *r0);
void ReadExclusivePokemon(DataSerializer *r0);

#endif // GUARD_EXCLUSIVE_POKEMON_H
