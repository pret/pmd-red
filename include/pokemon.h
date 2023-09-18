#ifndef GUARD_POKEMON_H
#define GUARD_POKEMON_H

#include "dungeon_global_data.h"
#include "file_system.h"
#include "items.h"
#include "constants/move.h"


#define OFFENSE_NRM 0
#define OFFENSE_SP 1

// size: 0x4
typedef struct Offense
{
    /* 0x0 */ u8 att[2]; // Atk, SpAtk
    /* 0x2 */ u8 def[2]; // Def, SpDef
} Offense;

// size: 0x4
typedef struct unkPokeSubStruct_C
{
    u8 level;
    u8 fill1[3];
} unkPokeSubStruct_C;

enum PokemonUnk0Flags {
    FLAG_ON_TEAM = 2,
};

// size: 0x58
typedef struct PokemonStruct1
{
    u16 unk0; // Probably a union: Sometimes ldrh and sometimes ldrb. Recruited??
    /* 0x2 */ bool8 isTeamLeader;
    /* 0x3 */ u8 level;
    /* 0x4 */ DungeonLocation dungeonLocation;
    /* 0x8 */ s16 speciesNum;
    unkPokeSubStruct_C unkC[2];
    /* 0x14 */ s16 IQ;
    /* 0x16 */ u16 pokeHP;
    /* 0x18 */ Offense offense;
    /* 0x1C */ u32 currExp;
    /* 0x20 */ u32 IQSkills;
    /* 0x24 */ u8 tacticIndex;
    /* 0x28 */ BulkItem heldItem;
    /* 0x2C */ Move moves[MAX_MON_MOVES];
    /* 0x4C */ u8 name[POKEMON_NAME_LENGTH];
} PokemonStruct1;

// size: 0x4
typedef struct unkStruct_808E6F4
{
    s16 unk0;
    u8 unk2;
} unkStruct_808E6F4;

// size: 0x4
typedef struct EvolveStage
{
    /* 0x0 */ s16 speciesNum;
    /* 0x2 */ u8 level;
} EvolveStage;

// size: 0x24
typedef struct unkStruct_8094184
{
    /* 0x0 */ Move moves[MAX_MON_MOVES];
    u8 unk20;
} unkStruct_8094184;

// size: 0x64
typedef struct PokemonStruct2
{
    u16 unk0; // corresponds to unk0 in PokemonStruct
    /* 0x2 */ bool8 isTeamLeader;
    /* 0x3 */ u8 level;
    /* 0x4 */ DungeonLocation dungeonLocation;
    /* 0x8 */ u16 IQ;
    s16 unkA;
    u16 unkC;
    /* 0xE */ s16 speciesNum;
    u16 unk10; // pokeHP
    u16 unk12; // pokeHP
    /* 0x14 */ Offense offense; // offense (other offset)
    /* 0x18 */ u32 currExp;
    /* 0x1C */ unkStruct_8094184 moves;
    /* 0x40 */ Item itemSlot; // heldItem
    u32 unk44; // some struct
    u32 unk48; // some struct (same type as 44)
    /* 0x4C */ u32 IQSkills; // unk20
    /* 0x50 */ u8 tacticIndex;
    unkStruct_808E6F4 unk54;
    /* 0x58 */ u8 name[POKEMON_NAME_LENGTH]; // name (other offset)
} PokemonStruct2;

// size: 0x90E8
typedef struct unkStruct_203B45C
{
    /* 0x0 */ PokemonStruct1 pokemon[NUM_MONSTERS];
    /* 0x8DF8 */ PokemonStruct2 pokemon2[4];
    /* 0x8F88 */ PokemonStruct1 team[MAX_TEAM_MEMBERS];
} unkStruct_203B45C;

// size: 0x4
typedef struct PreEvolution
{
    /* 0x0 */ s16 evolveFrom;
    /* 0x2 */ u16 evolveType;
} PreEvolution;

// size: 0x4
typedef struct EvolutionRequirements
{
    /* 0x0 */ s16 mainRequirement;
    /* 0x2 */ u16 additionalRequirement;
} EvolutionRequirements;

// size: 0x8
typedef struct unkEvolve
{
    /* 0x0 */ PreEvolution preEvolution;
    /* 0x4 */ EvolutionRequirements evolutionRequirements;
} unkEvolve;

// size: 0x48
typedef struct MonsterDataEntry
{
    /* 0x0 */ u8* species;
    /* 0x4 */ u8* category;
    /* 0x8 */ u8 overworldPalette;
    /* 0x9 */ u8 bodySize;
    /* 0xC */ s32 movementSpeed;
    /* 0x10 */ u16 dialogueSprites; // Bitwise flags for whether a dialogue sprite/portrait is available for each emotion.
    bool8 unk12;
    /* 0x13 */ u8 types[2];
    /* 0x15 */ u8 movementType;
    /* 0x16 */ u8 friendArea;
    /* 0x17 */ u8 abilities[2];
    /* 0x19 */ u8 shadowSize;
    u8 fill1A; // 0 for all Pokémon.
    /* 0x1B */ u8 regenSpeed; // 100 for all Pokémon.
    /* 0x1C */ bool8 canMove; // Set to false for Pokémon who don't move unless they're the leader, like Kakuna.
    /* 0x1D */ u8 chanceAsleep;
    /* 0x1E */ u16 baseHP;
    /* 0x20 */ s32 expYield;
    /* 0x24 */ u16 baseAtkSpAtk[2];
    /* 0x28 */ u16 baseDefSpDef[2];
    /* 0x2C */ u16 weight;
    /* 0x2E */ u16 size;
    u8 unk30; // 10 for all Pokémon.
    u8 unk31; // 10 for all Pokémon.
    u8 unk32; // 24 for all Pokémon.
    /* 0x33 */ bool8 toolboxEnabled; // If false, the AI can't use items. Doesn't seem to be used, as it's true for all Pokémon.
    /* 0x34 */ PreEvolution preEvolution;
    /* 0x38 */ EvolutionRequirements evolutionRequirements;
    /* 0x3C */ s16 dexInternal[2]; // dexNo and internalNo
    /* 0x40 */ s16 recruitRate;
    /* 0x42 */ s16 alphabetParent[2]; // alphabetNo and parentNo
} MonsterDataEntry;

// size: 0xC | https://www.pokecommunity.com/showthread.php?t=407371
typedef struct LevelData
{
    /* 0x0 */ s32 expRequired;
    /* 0x4 */ u8 gainHP;
    /* 0x5 */ u8 gainUnused;
    /* 0x6 */ u8 gainAtt;
    /* 0x7 */ u8 gainSPAtt;
    /* 0x8 */ u8 gainDef;
    /* 0x9 */ u8 gainSPDef;
    u16 fillA;
} LevelData;

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
    unkStruct_808E6F4 unk0[3];
} unkStruct_808E218;

extern unkStruct_203B45C *gRecruitedPokemonRef;

void LoadMonsterParameters(void);
unkStruct_203B45C *GetRecruitedPokemon(void);
void InitializeRecruitedPokemon(void);

// These two need to be overridden in status_actions.c
// Uncomment when fixed
//void CopyCyanMonsterNametoBuffer(u8 *buffer, s16 index);
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
bool8 IsToolboxEnabled(s16 index);
u8 GetUnk12(s16 index);
s16 GetPokemonEvolveFrom(s16 index);
u16 GetBaseOffensiveStat(s16 index, u32 r1);
u16 GetBaseDefensiveStat(s16 index, u32 r1);
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
void sub_808E6F4(unkStruct_808E6F4 *);
s32 GetEvolutionSequence(PokemonStruct1 *pokemon, EvolveStage *);
void xxx_pokemonstruct_to_pokemon2_808DE50(PokemonStruct2 *, PokemonStruct1 *, s32);
void SavePokemonStruct(unkStruct_8094924 *, PokemonStruct1 *pokemon);
void RestorePokemonStruct(unkStruct_8094924 *, PokemonStruct1 *);
s32 sub_808E218(unkStruct_808E218_arg *, PokemonStruct1 *pokemon);

// pokemon.s
extern PokemonStruct1 *GetPlayerPokemonStruct(void);
extern void sub_808CFD0(u8 *, s16, u8 *, u8, u32 *, u16 *);
extern u32 sub_808D1DC(u8 *);
extern PokemonStruct1 *sub_808D3F8(void);
extern s32 sub_808D544(u32);
extern s32 sub_808D580(s32 *);

#endif // GUARD_POKEMON_H
