#ifndef GUARD_POKEMON_H
#define GUARD_POKEMON_H

#include "file_system.h"
#include "item.h"


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

struct unkPokeSubStruct_4 {
    u8 unk4;
    u8 unk5;
    u16 fill6;
};

struct unkPokeSubStruct_2C 
{
    u8 unk0;
    u8 fill1;
    u16 unk2;
    u32 fill4;
};

struct unkPokeSubStruct_C
{
    u8 unk0;
    u8 fill1[3];
};

struct PokemonStruct
{
    // size: 0x58
    u16 unk0; // recruited??
    u8 unk2;
    u8 unkHasNextStage;  // set to a random value?
    struct unkPokeSubStruct_4 unk4;
    /* 0x8 */ s16 speciesNum; // species #
    u8 fillA[0xC - 0xA];
    struct unkPokeSubStruct_C unkC[2];
    /* 0x14 */ s16 IQ;
    /* 0x16 */ u16 pokeHP; // HP
    /* 0x18 */ struct Offense offense;
    u32 unk1C;
    u32 unk20;
    u8 unk24;
    u8 fill25[3];
    struct HeldItem heldItem;
    struct unkPokeSubStruct_2C unk2C[4];
    /* 0x4C */ u8 name[0xA];
};

struct PokemonStruct2
{
    // size 0x64 (comments are bit sizes)
    u16 unk0;  // 2
    bool8 unk2;   // 1
    u8 unk3;   // 7 (unkHasNextStage?)
    struct unkPokeSubStruct_4 unk4;
    u16 unk8;  // 10 (HP?)
    u16 unkA;  // 16
    u16 unkC;  // 16
    u16 unkE;  // 9 (speciesNum?)
    u16 unk10;  // 10 (IQ?)
    u16 unk12;  // 10 (HP?)
    /* 0x14 */ struct Offense offense;
    u32 unk18;  // 24 (unk1C / unk20?)
    u8 unk1C[0x40 - 0x1c];  // 36 / 0x24 bytes
    /* 0x40 */ struct ItemSlot itemSlot;
    u32 unk44;  // some struct (unkC[0]?)
    u32 unk48;  // same struct as previous (unkC[1]?)
    u32 unk4C;  // 24 (unk1C / unk20?)
    u8 unk50;   // 4 (unk24?)
    u8 fill51[3];
    u32 unk54;  // other struct
    /* 58 */ u8 name[10];
};

struct unkStruct_203B45C
{
    /* 0x0 */ struct PokemonStruct pokemon[NUM_SPECIES];
    /* 0x8DF8 */ struct PokemonStruct2 pokemon2[4];
    /* 0x8F88 */ struct PokemonStruct team[4];
};

struct EvolveStruct1
{
    /* 0x34 */ u16 evolve_from;
    /* 0x36 */ u16 evolve_type;
};

struct EvolveNeeds
{
    /* 0x38 */ u16 evolve_need1;
    /* 0x3A */ u16 evolve_need2;
};

struct unkEvolve
{
    /* 0x0 */ struct EvolveStruct1 conditions;
    /* 0x4 */ struct EvolveNeeds needs;
};


struct gPokemon
{
    /* 0x0 */ u8* species;
    /* 0x4 */ u8* category;
    /* 0x8 */ u8 overworld_palette;
    /* 0x9 */ u8 size;
    /* 0xA */ u8 unkA;
    /* 0xB */ u8 unkB;
    /* 0xC */ s32 move_speed;
    /* 0x10 */ u16 dialogue_sprites;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 types[2];
    /* 0x15 */ u8 walkable_tiles;
    /* 0x16 */ u8 friend_area;
    /* 0x17 */ u8 abilities[2];
    /* 0x19 */ u8 shadow_size;
    /* 0x1A */ u8 unk1A;
    /* 0x1B */ u8 unk1B;
    /* 0x1C */ bool8 isMoving;
    /* 0x1D */ u8 unk1D;
    /* 0x1E */ u16 base_hp;
    /* 0x20 */ s32 base_exp;
    /* 0x24 */ u16 base_att_spatt[2];
    /* 0x28 */ u16 base_def_spdef[2];
    /* 0x2C */ u16 lowkick_dmg;
    /* 0x2E */ u16 sizeorb_dmg;
    /* 0x30 */ u8 unk30;
    /* 0x31 */ u8 unk31;
    /* 0x32 */ u8 unk32;
    /* 0x33 */ bool8 unk33;
    /* 0x34 */ struct EvolveStruct1 pre;
    /* 0x38 */ struct EvolveNeeds need;
    /* 0x3C */ s16 dexInternal[2]; // dexNo and internalNo
    /* 0x40 */ s16 base_recruit;
    /* 0x42 */ s16 alphabetParent[2]; // alphabetNo and parentNo
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

struct unkStruct_808DE50
{
    u16 unk0;  // corresponds to unk0 inPokemonStruct
    u8 unk2;   // unk2
    u8 unkHasNextStage;   // unk3
    struct unkPokeSubStruct_4 unk4;  // unk4
    u16 IQ;    // IQ (other offset)
    u16 unkA;
    u16 unkC;
    s16 speciesNum;  // speciesNum (other offset)
    u16 unk10;  // pokeHP
    u16 unk12;  // pokeHP
    struct Offense offense;  // offense (other offset)
    u32 unk18;  // unk1C
    struct unkPokeSubStruct_2C unk1C[4];  // unk2C
    u8 fill3c[4];
    /* 40 */ struct ItemSlot itemSlot;  // heldItem
    u32 unk44;  // some struct
    u32 unk48;  // some struct (same type as 44)
    u32 unk4C;  // unk20
    u8 unk50;   // unk24
    u8 fill51[3];
    struct unkStruct_808E6F4 unk54;
    u8 name[10];  // name (other offset)
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
    u16 unk0[NUM_SPECIES];
    u32 count;
};

struct unkStruct_808E218 
{
    // leveldata? (same size)
    struct unkStruct_808E6F4 unk0[3];
};


void LoadMonsterParameters(void);
struct unkStruct_203B45C *GetRecruitedPokemon(void);
void InitializeRecruitedPokemon(void);


void CopySpeciesNametoBuffer(u8 * buffer, s16 index);
void CopyYellowSpeciesNametoBuffer(u8 *buffer, s16 index);
void CopyCyanSpeciesNametoBuffer(u8 *buffer, s16 index);

u8 *GetCategoryString(s16 index);
u8 GetPokemonSize(s16 index);
u8 GetShadowSize(s16 index);
char * GetMonSpecies(s16 index);
s32 GetMoveSpeed(s16 index);
u8 GetWalkableTiles(s16 index);
u8 GetUnk1B(s16 index);
bool8 GetIsMoving(s16 index);
u8 GetUnk1D(s16 index);
u16 GetLowKickDmg(s16 index);
u16 GetSizeOrbDmg(s16 index);
u8 GetFriendArea(s16 index);
u16 GetBaseHP(s16 index);
bool8 GetUnk33(s16 index);
u8 GetUnk12(s16 index);
s16 GetPokemonEvolveFrom(s16 index);
u16 GetPokemonAttSpatt(s16 index, u32 r1);
u16 GetPokemonDefSpdef(s16 index, u32 r1);
u8 GetPokemonType(s32 index, u32 typeIndex);
u8 GetPokemonAbility(s16 index, u32 abilityIndex);
s16 GetDexInternalNo(s16 index, u32 r1);
s16 GetBaseRecruit(s16 index);
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
void xxx_pokemonstruct_to_unk_808DE50(struct unkStruct_808DE50* r0, struct PokemonStruct *r1, s32 r2);
void SavePokemonStruct(struct unkStruct_8094924* a1, struct PokemonStruct* pokemon);
void RestorePokemonStruct(struct unkStruct_8094924*, struct PokemonStruct*);


#endif // GUARD_POKEMON_H  
