#ifndef GUARD_STR_POKEMON_H
#define GUARD_STR_POKEMON_H

#include "constants/monster.h"
#include "structs/str_dungeon.h"
#include "structs/str_items.h"
#include "structs/str_moves.h"
#include "structs/str_iq_skill_flags.h"

// size: 0x4
typedef struct Offense
{
    /* 0x0 */ u8 att[2]; // Atk, SpAtk
    /* 0x2 */ u8 def[2]; // Def, SpDef
} Offense;

// size: R=0x4 | B=0x1
typedef struct unkPokeSubStruct_C
{
    /* 0x0 */ u8 level;
} unkPokeSubStruct_C;

// size: R=0x58 | B=0x40
typedef struct Pokemon
{
    /* R=0x0  | B=0x0  */ u16 flags;
    /* R=0x2  | B=0x2  */ bool8 isTeamLeader;
    /* R=0x3  | B=0x3  */ u8 level;
    /* R=0x4  | B=0x4  */ DungeonLocation dungeonLocation;
    /* R=0x8  | B=0x6  */ s16 speciesNum;
    /* R=0xC  | B=0x8  */ unkPokeSubStruct_C unkC[2];
    /* R=0x14 | B=0xA  */ s16 IQ;
    /* R=0x16 | B=0xC  */ s16 pokeHP;
    /* R=0x18 | B=0xE  */ Offense offense;
    /* R=0x1C | B=0x14 */ u32 currExp;
    /* R=0x20 | B=0x18 */ IqSkillFlags IQSkills;
    /* R=0x24 | B=0x1B */ u8 tacticIndex;
    /* R=0x28 | B=0x1C */ BulkItem heldItem;
    /* R=0x2C | B=0x1E */ Move moves[MAX_MON_MOVES];
    /* R=0x4C | B=0x36 */ u8 name[POKEMON_NAME_LENGTH];
} Pokemon;

// size: 0x4
typedef struct EvolveStage
{
    /* 0x0 */ s16 speciesNum;
    /* 0x2 */ u8 level;
} EvolveStage;

#define UNK_RECRUITED_POKEMON_ID_55AA 0x55AA
#define UNK_RECRUITED_POKEMON_ID_5AA5 0x5AA5

// size: R=0x64 | B=0x54
typedef struct DungeonMon
{
    /* R=0x0  | B=0x0  */ u16 flags; // corresponds to flags in PokemonStruct.
    /* R=0x2  | B=0x2  */ bool8 isTeamLeader;
    /* R=0x3  | B=0x3  */ u8 level;
    /* R=0x4  | B=0x4  */ DungeonLocation dungeonLocation;
    /* R=0x8  | B=0x6  */ s16 IQ;
    /* R=0xA  | B=0x8  */ s16 recruitedPokemonId; // id of corresponding gRecruitedPokemonRef->pokemon[]
    /* R=0xC  | B=0xA  */ u16 unkC;
    /* R=0xE  | B=0xC  */ s16 speciesNum;
    /* R=0x10 | B=0xE  */ u16 unk10; // pokeHP
    /* R=0x12 | B=0x10 */ u16 unk12; // pokeHP
    /* R=0x14 | B=0x12 */ Offense offense; // offense (other offset)
    /* R=0x18 | B=0x18 */ u32 currExp;
    /* R=0x1C | B=0x1C */ Moves moves;
    /* R=0x40 | B=0x36 */ Item itemSlot; // heldItem
    /* R=0x44 | B=0x3A */ FixedPoint belly;
    /* R=0x48 | B=0x3E */ FixedPoint maxBelly;
    /* R=0x4C | B=0x42 */ IqSkillFlags IQSkills;
    /* R=0x50 | B=0x45 */ u8 tacticIndex;
    /* R=0x54 | B=0x46 */ HiddenPower hiddenPower;
    /* R=0x58 | B=0x4A */ u8 name[POKEMON_NAME_LENGTH]; // name (other offset)
} DungeonMon;

// size: R=0x90E8 | B=0x6990
typedef struct RecruitedMon
{
    /* R=0x0    | B=0x0    */ Pokemon pokemon[NUM_MONSTERS];
    /* R=0x8DF8 | B=0x6740 */ DungeonMon dungeonTeam[MAX_TEAM_MEMBERS];
    /* R=0x8F88 | B=0x6890 */ Pokemon team[MAX_TEAM_MEMBERS];
} RecruitedMon;

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
    /* 0x4 */ u16 gainHP;
    /* 0x6 */ u8 gainAtt[2];
    /* 0x8 */ u8 gainDef[2];
    u16 fillA;
} LevelData;

struct StoryMonData
{
    /* 0x0 */ u8 *name;
    /* 0x4 */ s16 speciesNum;
    /* 0x6 */ u8 itemID;
    /* 0x8 */ struct DungeonLocation dungeonLocation;
    /* 0xC */ u16 moveID[MAX_MON_MOVES];
    /* 0x14 */ s16 pokeHP;
    /* 0x16 */ u16 level;
    /* 0x18 */ u16 IQ;
    s16 offenseAtk[2]; // atk, spatt, def, spdef (not sure why s16/u16 and not u8)
    s16 offenseDef[2];
    /* 0x24 */ u32 currExp;
};

#endif // GUARD_STR_POKEMON_H
