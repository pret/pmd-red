#ifndef GUARD_POKEMON_3_H
#define GUARD_POKEMON_3_H

#include "pokemon.h"

// size: 0x8
typedef struct EvolveStatus
{
    /* 0x0 */ u8 evoItem1;
    /* 0x1 */ u8 evoItem2;
    /* 0x2 */ u8 wurmpleVal;
    /* 0x4 */ u16 evolutionConditionStatus;
    /* 0x6 */ s16 targetEvolveSpecies;
} EvolveStatus;

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
void ToggleIQSkill(u8 *param_1, u32 skillIndex);
void SetIQSkill(u8 *param_1, u32 skillIndex);
bool8 IsIQSkillSet(u8 *IQSkillFlags, u32 IQSkill);
void SetDefaultIQSkills(u8 *param_1, bool8 enableSelfCurer);
void sub_808F468(PokemonStruct1 *param_1, EvolveStatus *evolveStatus, u8 param_3);
u32 sub_808F734(PokemonStruct1 *pokemon, s16 _species);

// pokemon_3.s
extern void CreatePokemonInfoTabScreen(u32, s16, u32 *, u32 *, u32);
extern void sub_808FF20(u32 *, PokemonStruct1 *, bool8);

#endif // GUARD_POKEMON_3_H