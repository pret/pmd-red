#ifndef GUARD_POKEMON_H
#define GUARD_POKEMON_H

#include "constants/move.h"
#include "file_system.h"
#include "items.h"
#include "structs/str_pokemon.h"

#define OFFENSE_NRM 0
#define OFFENSE_SP 1

enum PokemonUnk0Flags
{
    FLAG_ON_TEAM = 2,
};

// size: 0x1A4
typedef struct unkStruct_808E218_arg
{
    u16 unk0[NUM_MONSTERS];
    /* 0x1A0 */ u32 count;
} unkStruct_808E218_arg;

// size: 0xC
typedef struct unkStruct_808E218
{
    // leveldata? (same size)
    HiddenPower unk0[3];
} unkStruct_808E218;

extern unkStruct_203B45C *gRecruitedPokemonRef;

void LoadMonsterParameters(void);
unkStruct_203B45C *GetRecruitedPokemon(void);
void InitializeRecruitedPokemon(void);

// These two need to be overridden in status_actions.c
// Uncomment when fixed
//u8 GetBodySize(s16 index);


void CopyMonsterNametoBuffer(u8 * buffer, s16 index);
void CopyYellowMonsterNametoBuffer(u8 *buffer, s16 index);
void PrintColoredPokeNameToBuffer(u8 *buffer, PokemonStruct1 *pokemon, s32 colorNum);
void sub_808D930(u8 *buffer, s32 index);
void sub_808D9DC(u8 *buffer, PokemonStruct2 *, s32 colorNum);
void sub_808DA0C(u8 *buffer, PokemonStruct2 *);
void PeekPokemonItem(s16 index_, BulkItem* item);
void GivePokemonItem(s16 index_, BulkItem* item);
bool8 IsPokemonRenamed(PokemonStruct1* pokemon);
bool8 CanMonLearnMove(u16 moveID, s16 _species);

u8 *GetCategoryString(s16 index);
u8 GetShadowSize(s16 index);
char * GetMonSpecies(s16 index);
s32 GetMovementSpeed(s16 index);
u8 GetMovementType(s16 index);
u8 GetRegenSpeed(s16 index);
bool8 CanMove(s16 index);
u8 GetChanceAsleep(s16 index);
u32 GetWeight(s16 index);
u32 GetSize(s16 index);
u8 GetFriendArea(s32 index);
u16 GetBaseHP(s16 index);
bool8 MonsterIDCanThrowItems(s16 index);
u8 GetUnk12(s16 index);
s16 GetPokemonEvolveFrom(s16 index);
u16 GetBaseOffensiveStat(s32 index, u32 r1);
u16 GetBaseDefensiveStat(s32 index, u32 r1);
u8 GetPokemonType(s32 index, u32 typeIndex);
u8 GetPokemonAbility(s16 index, u32 abilityIndex);
s16 GetDexInternalNo(s32 index, u32 r1);
s16 GetRecruitRate(s16 index);
s16 GetAlphabetParentNo(s16 index, s32 r1);
s16 GetInternalNo(s16 index);
s32 CalculateEXPGain(s16 index, s32 level);
s16 GetPokemonEvolveConditons(s16 index, unkEvolve *);
u8 GetPokemonOverworldPalette(s16 index, u32 r1);
bool8 IsPokemonDialogueSpriteAvail(s16 index, s32 r1);
OpenedFile *OpenPokemonDialogueSpriteFile(s16 index);
OpenedFile *GetDialogueSpriteDataPtr(s16 index);
s32 GetUnownIndex(s16 index);
void GenerateHiddenPower(HiddenPower *);
s32 GetEvolutionSequence(PokemonStruct1 *pokemon, EvolveStage *);
void xxx_pokemonstruct_to_pokemon2_808DE50(PokemonStruct2 *, PokemonStruct1 *, s32);
void SavePokemonStruct(unkStruct_8094924 *, PokemonStruct1 *pokemon);
void RestorePokemonStruct(unkStruct_8094924 *, PokemonStruct1 *);
s32 sub_808E218(unkStruct_808E218_arg *, PokemonStruct1 *pokemon);
void sub_808CFD0(PokemonStruct1 *pokemon, s16 _species, u8* name, u32 _itemID, DungeonLocation *location, u16 *moveID);
void sub_808D0D8(PokemonStruct1 *pokemon);

// pokemon.s
extern PokemonStruct1 *GetPlayerPokemonStruct(void);
extern u32 sub_808D1DC(PokemonStruct1*);
extern PokemonStruct1 *sub_808D378(void);
extern PokemonStruct1 *sub_808D3BC(void);
extern PokemonStruct1 *sub_808D3F8(void);
extern s32 GetUnitSum_808D544(u32);
extern s32 sub_808D580(s32 *);

#endif // GUARD_POKEMON_H
