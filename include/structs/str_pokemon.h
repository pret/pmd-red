#ifndef GUARD_STR_POKEMON_H
#define GUARD_STR_POKEMON_H

#include "constants/monster.h"
#include "structs/str_dungeon.h"
#include "structs/str_items.h"
#include "structs/str_moves.h"

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
    u32 belly; // some struct
    u32 maxBelly; // some struct (same type as 44)
    /* 0x4C */ u32 IQSkills; // unk20
    /* 0x50 */ u8 tacticIndex;
    /* 0x54 */ HiddenPower hiddenPower;
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
    /* 0x33 */ bool8 canThrowItems; // If false, the AI can't use items. Doesn't seem to be used, as it's true for all Pokémon.
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

// Definitely wrong but need to figure out better structure later
struct FaceData
{
    u8 *unk0[5];
};

#endif // GUARD_STR_POKEMON_H
