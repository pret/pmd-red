#ifndef GUARD_POKEMON_H
#define GUARD_POKEMON_H

#include "dungeon_global_data.h"
#include "file_system.h"
#include "item.h"
#include "constants/move.h"


#define OFFENSE_NRM 0
#define OFFENSE_SP 1

struct Offense {
    /* 0x18: att   */
    /* 0x19: spatt */
    /* 0x1a: def   */
    /* 0x1b: spdef */

    u8 att[2];
    u8 def[2];
}; 

struct unkPokeSubStruct_C
{
    u8 unk0;
    u8 fill1[3];
};

struct PokemonStruct
{
    // size: 0x58
    /* 0x0 */ u16 unk0; // recruited??
    /* 0x1 */ bool8 isTeamLeader;
    /* 0x3 */ u8 unkHasNextStage;  // set to a random value?
    /* 0x4 */ struct DungeonLocation dungeonLocation;
    /* 0x8 */ s16 speciesNum; // species #
    /* 0xC */ struct unkPokeSubStruct_C unkC[2];
    /* 0x14 */ s16 IQ;
    /* 0x16 */ u16 pokeHP; // HP
    /* 0x18 */ struct Offense offense;
    /* 0x1C */ u32 unk1C;
    /* 0x20 */ u32 IQSkills;
    /* 0x24 */ u8 unk24;
    /* 0x25 */ u8 fill25[3];
    /* 0x28 */ struct BulkItem heldItem;
    /* 0x2C */ struct Move moves[MAX_MON_MOVES];
    /* 0x4C */ u8 name[POKEMON_NAME_LENGTH];
};


struct unkStruct_808E6F4
{
    s16 unk0;
    u8 unk2;
};

struct EvolveStage
{
    s16 speciesNum;
    u8 unkHasNextStage;
};


struct unkStruct_8094184
{
    struct Move moves[MAX_MON_MOVES];
    u8 unk20;
};

struct PokemonStruct2
{
    // size 0x68
    /* 0x0 */ u16 unk0;  // corresponds to unk0 inPokemonStruct
    /* 0x2 */ bool8 isTeamLeader;   // unk2
    /* 0x3 */ u8 unkHasNextStage;   // unk3
    /* 0x4 */ struct DungeonLocation dungeonLocation;  // unk4
    /* 0x8 */ u16 IQ;    // IQ (other offset)
    /* 0xA */ u16 unkA;
    /* 0xC */ u16 unkC;
    /* 0xE */ s16 speciesNum;  // speciesNum (other offset)
    /* 0x10 */ u16 unk10;  // pokeHP
    /* 0x12 */ u16 unk12;  // pokeHP
    /* 0x14 */ struct Offense offense;  // offense (other offset)
    /* 0x18 */ u32 unk18;  // unk1C
    /* 0x1C */ struct unkStruct_8094184 moves;
    /* 0x40 */ struct Item itemSlot;  // heldItem
    /* 0x44 */ u32 unk44;  // some struct
    /* 0x48 */ u32 unk48;  // some struct (same type as 44)
    /* 0x4C */ u32 IQSkills;  // unk20
    /* 0x50 */ u8 unk50;   // unk24
    /* 0x51 */ u8 fill51[3];
    /* 0x54 */ struct unkStruct_808E6F4 unk54;
    /* 0x58 */ u8 name[POKEMON_NAME_LENGTH];  // name (other offset)
};

struct unkStruct_203B45C
{
    /* 0x0 */ struct PokemonStruct pokemon[NUM_MONSTERS];
    /* 0x8DF8 */ struct PokemonStruct2 pokemon2[4];
    /* 0x8F88 */ struct PokemonStruct team[MAX_TEAM_MEMBERS];
};

struct PreEvolution
{
    /* 0x34 */ s16 evolveFrom;
    /* 0x36 */ s16 evolveType;
};

struct EvolutionRequirements
{
    /* 0x38 */ u16 mainRequirement;
    /* 0x3A */ u16 additionalRequirement;
};

struct unkEvolve
{
    /* 0x0 */ struct PreEvolution preEvolution;
    /* 0x4 */ struct EvolutionRequirements evolutionRequirements;
};


struct MonsterDataEntry
{
    /* 0x0 */ u8* species;
    /* 0x4 */ u8* category;
    /* 0x8 */ u8 overworldPalette;
    /* 0x9 */ u8 bodySize;
    /* 0xC */ s32 movementSpeed;
    /* 0x10 */ u16 dialogueSprites; // Bitwise flags for whether a dialogue sprite/portrait is available for each emotion.
    /* 0x12 */ bool8 unk12;
    /* 0x13 */ u8 types[2];
    /* 0x15 */ u8 movementType;
    /* 0x16 */ u8 friendArea;
    /* 0x17 */ u8 abilities[2];
    /* 0x19 */ u8 shadowSize;
    /* 0x1A */ u8 fill1A; // 0 for all Pokémon.
    /* 0x1B */ u8 regenSpeed; // 100 for all Pokémon.
    /* 0x1C */ bool8 canMove; // Set to false for Pokémon who don't move unless they're the leader, like Kakuna.
    /* 0x1D */ u8 chanceAsleep;
    /* 0x1E */ u16 baseHP;
    /* 0x20 */ s32 expYield;
    /* 0x24 */ u16 baseAtkSpAtk[2];
    /* 0x28 */ u16 baseDefSpDef[2];
    /* 0x2C */ u16 weight;
    /* 0x2E */ u16 size;
    /* 0x30 */ u8 unk30; // 10 for all Pokémon.
    /* 0x31 */ u8 unk31; // 10 for all Pokémon.
    /* 0x32 */ u8 unk32; // 24 for all Pokémon.
    /* 0x33 */ bool8 toolboxEnabled; // If false, the AI can't use items. Doesn't seem to be used, as it's true for all Pokémon.
    /* 0x34 */ struct PreEvolution preEvolution;
    /* 0x38 */ struct EvolutionRequirements evolutionRequirements;
    /* 0x3C */ s16 dexInternal[2]; // dexNo and internalNo
    /* 0x40 */ s16 recruitRate;
    /* 0x42 */ s16 alphabetParent[2]; // alphabetNo and parentNo
};


// https://www.pokecommunity.com/showthread.php?t=407371
struct LevelData
{
    s32 expRequired;
    u8 gainHP;
    u8 gainUnused;
    u8 gainAtt;
    u8 gainSPAtt;
    u8 gainDef;
    u8 gainSPDef;
    u16 fillA;
};

struct unkStruct_808E218_arg
{
    u16 unk0[NUM_MONSTERS];
    u32 count;
};

struct unkStruct_808E218
{
    // leveldata? (same size)
    struct unkStruct_808E6F4 unk0[3];
};

extern struct unkStruct_203B45C *gRecruitedPokemonRef;

void LoadMonsterParameters(void);
struct unkStruct_203B45C *GetRecruitedPokemon(void);
void InitializeRecruitedPokemon(void);


void CopyMonsterNametoBuffer(u8 * buffer, s16 index);
void CopyYellowMonsterNametoBuffer(u8 *buffer, s16 index);
void CopyCyanMonsterNametoBuffer(u8 *buffer, s16 index);
void PrintColoredPokeNameToBuffer(u8 *buffer, struct PokemonStruct *pokemon, s32 colorNum);
void sub_808D9DC(u8 *buffer, struct PokemonStruct2 *param_2, s32 colorNum);
void sub_808DA0C(u8 *buffer, struct PokemonStruct2 *param_2);
void PeekPokemonItem(s16 index_, struct BulkItem* item);
void GivePokemonItem(s16 index_, struct BulkItem* item);
bool8 IsPokemonRenamed(struct PokemonStruct* pokemon);
bool8 CanMonLearnMove(u16 moveID, s16 _species);

u8 *GetCategoryString(s16 index);
u8 GetBodySize(s16 index);
u8 GetShadowSize(s16 index);
char * GetMonSpecies(s16 index);
s32 GetMovementSpeed(s16 index);
u8 GetMovementType(s16 index);
u8 GetRegenSpeed(s16 index);
bool8 CanMove(s16 index);
u8 GetChanceAsleep(s16 index);
u32 GetWeight(s16 index);
u32 GetSize(s16 index);
u8 GetFriendArea(s16 index);
u16 GetBaseHP(s16 index);
bool8 IsToolboxEnabled(s16 index);
u8 GetUnk12(s16 index);
s16 GetPokemonEvolveFrom(s16 index);
u16 GetBaseOffensiveStat(s16 index, u32 r1);
u16 GetBaseDefensiveStat(s16 index, u32 r1);
u8 GetPokemonType(s32 index, u32 typeIndex);
u8 GetPokemonAbility(s16 index, u32 abilityIndex);
s16 GetDexInternalNo(s16 index, u32 r1);
s16 GetRecruitRate(s16 index);
s16 GetAlphabetParentNo(s16 index, s32 r1);
s16 GetInternalNo(s16 index);
s32 CalculateEXPGain(s16 index, s32 level);
s16 GetPokemonEvolveConditons(s16 index, struct unkEvolve *r1);
u8 GetPokemonOverworldPalette(s16 index, u32 r1);
bool8 IsPokemonDialogueSpriteAvail(s16 index, s32 r1);
struct OpenedFile *OpenPokemonDialogueSpriteFile(s16 index);
struct OpenedFile *GetDialogueSpriteDataPtr(s16 index);
s32 GetUnownIndex(s16 index);
void sub_808E6F4(struct unkStruct_808E6F4* a1);
s32 GetEvolutionSequence(struct PokemonStruct* pokemon, struct EvolveStage* a2);
void xxx_pokemonstruct_to_pokemon2_808DE50(struct PokemonStruct2* r0, struct PokemonStruct *r1, s32 r2);
void SavePokemonStruct(struct unkStruct_8094924* a1, struct PokemonStruct* pokemon);
void RestorePokemonStruct(struct unkStruct_8094924*, struct PokemonStruct*);


#endif // GUARD_POKEMON_H
