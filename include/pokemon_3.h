#ifndef GUARD_POKEMON_3_H
#define GUARD_POKEMON_3_H

struct EvolveStatus
{
    u8 evoItem1;
    u8 evoItem2;
    u8 unk6;
    u16 evolutionConditionStatus;
    s16 targetEvolveSpecies;
};

s16 GetBaseSpeciesNoUnown(s16 index);
bool8 TacticsTargetLeader(u8 tactic);
bool8 HasIQForSkill(s32 pokeIQ, u8 IQSkillIndex);
void SetIQSkill(u8 *param_1, u32 skillIndex);
bool8 IsIQSkillSet(u8 *IQSkillFlags, u32 IQSkill);
void sub_808F468(struct PokemonStruct *param_1, struct EvolveStatus *evolveStatus, u8 param_3);
u32 sub_808F734(struct PokemonStruct *pokemon, s16 _species);

#endif
