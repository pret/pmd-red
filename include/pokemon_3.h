#ifndef GUARD_POKEMON_3_H
#define GUARD_POKEMON_3_H

#include "pokemon.h"

// size: 0x8
typedef struct EvolveStatus
{
    /* 0x0 */ u8 evoItem1;
    /* 0x1 */ u8 evoItem2;
    // This value is set to a random number in the range [0, 254].
    // Even values produce Silcoon while odd values produce Cascoon.
    /* 0x2 */ u8 wurmpleVal;
    /* 0x4 */ u16 evolutionConditionStatus;
    /* 0x6 */ s16 targetEvolveSpecies;
} EvolveStatus;

struct unkStruct_808FF20
{
    // size: 0x64
    s16 species;
    u8 nameBuffer[0x14];
    u8 types[2]; // 0x16
    u8 abilities[2]; // 0x18
    u8 fill1A[0x1C - 0x1A];
     DungeonLocation dungeonLocation; // 0x1C
    Item item; // 0x20
    s32 HP1;
    s32 HP2;
    s32 level;
    u32 exp;
     Offense offense;
    bool8 isTeamLeader;
    u8 atkBoost;
    u8 spAtkBoost;
    u8 defBoost;
    u8 spDefBoost;
    u8 fill3D;
    s16 IQ; // 0x3E
    s16 unk40;
    s16 fill42;
    struct unkPokeSubStruct_C unk44[2];
    u8 unk4C;
    u8 fill4D[3];
    IqSkillFlags IQSkills; // 0x50
    u8 tactic;
    u8 fill55[1];
    s16 unk56;
    u8 unk58[12];
};

struct UnkInfoTabStruct
{
    u8 unk0[0xC];
    s32 unkC[9];
};

bool8 HasRecruitedMon(s16 species);
s16 GetBaseSpecies(s16 index);
s16 GetBaseSpeciesNoUnown(s16 index);
bool8 TacticsTargetLeader(u8 tactic);
bool8 HasIQForSkill(s32 pokeIQ, u8 IQSkillIndex);
s32 GetNumAvailableIQSkills(u8 *iqSkillBuffer, s32 pokeIQ);
void CopyTacticsNameToBuffer(char *buffer, u8 tactic);
u8 *GetIQSkillName(u8 skill);
u8 *GetIQSkillDescription(u8 skill);
u8 *GetTacticsDescription(u8 tactic);
void ToggleIQSkill(IqSkillFlags *iq, u32 skillIndex);
void SetIQSkill(IqSkillFlags *iq, u32 skillIndex);
bool8 IsIQSkillSet(IqSkillFlags *iq, u32 IQSkillBit);
void SetDefaultIQSkills(IqSkillFlags *iq, bool8 enableSelfCurer);
void sub_808F468(PokemonStruct1 *param_1, EvolveStatus *evolveStatus, bool8 param_3);
s32 sub_808F700(PokemonStruct1 *pokemon);
PokemonStruct1 *sub_808F734(PokemonStruct1 *pokemon, s16 _species);
s16 ExtractSpeciesIndex(UnkDungeonGlobal_unk1CD98 *r0);
void SetSpeciesLevelToExtract(UnkDungeonGlobal_unk1CD98 *r0, s32 level, s32 species);
s32 ExtractLevel(UnkDungeonGlobal_unk1CD98 *r0);
PokemonStruct1 *sub_808F798(PokemonStruct1 *pokemon, short _species);
void CreatePokemonInfoTabScreen(s32 param_1, s32 param_2, struct unkStruct_808FF20 *mon, struct UnkInfoTabStruct *param_4, u32 windowId);
void sub_808FF20(struct unkStruct_808FF20 *param_1, struct PokemonStruct1 *pokemon, bool8 param_3);

#endif // GUARD_POKEMON_3_H
