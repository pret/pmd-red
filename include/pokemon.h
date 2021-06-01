#ifndef POKEMON_H
#define POKEMON_H

#include "file_system.h"
#include "constants/species.h"

struct PokemonStruct
{
    // size: 0x58
    u16 unk0; // recruited??
    u8 unk2;
    u8 unk3;
    u8 fill4[0x8 - 0x4];
    s16 unk8; // species #
    u8 fillA[0x14 - 0xA];
    u16 unk14;
    u16 unk16; // HP
    u8 unk18; // attack
    u8 unk19; // sp attack
    u8 unk1A; // def
    u8 unk1B; // spdef
    u32 unk1C;
    u32 unk20;
    u8 unk24;
    u8 fill25[3];
    u8 unk28;
    u8 fill29[3];
    u32 unk2C;
    u8 fill30[0x4C - 0x30];
    /* 0x4C */ u8 name[0xA];
};

struct PokemonStruct2
{
    // size 0x64
    u16 unk0;
    u8 fill[0x62];
};

struct PokemonStruct3
{
    // size: 0x58
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u16 unk8;
    u8 fill[0x4E];
};

struct unkStruct_203B45C
{
    struct PokemonStruct pokemon[NUM_SPECIES];
    struct PokemonStruct2 pokemon2[4];
    struct PokemonStruct3 pokemon3[4];
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
    /* 0x20 */ u16 base_exp;
    /* 0x22 */ u16 unk22;
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
u8 GetPokemonType(s32 index, u32 typeIndex);;
u8 GetPokemonAbility(s16 index, u32 abilityIndex);
s16 GetDexInternalNo(s16 index, u32 r1);
s16 GetBaseRecruit(s16 index);
s16 GetAlphabetParentNo(s16 index, s32 r1);
s16 GetInternalNo(s16 index);
u32 CalculateEXPGain(s16 index, s32 level);
s16 GetPokemonEvolveConditons(s16 index, struct unkEvolve *r1);
u8 GetPokemonOverworldPalette(s16 index, u32 r1);
bool8 IsPokemonDialogueSpriteAvail(s16 index, s32 r1);
struct OpenedFile *OpenPokemonDialogueSpriteFile(s16 index);
struct OpenedFile *GetDialogueSpriteDataPtr(s16 index);

#endif // POKEMON_H  
