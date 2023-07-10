#ifndef GUARD_POKEMON_3_H
#define GUARD_POKEMON_3_H

s16 GetBaseSpeciesNoUnown(s16 index);
bool8 TacticsTargetLeader(u8 tactic);
bool8 HasIQForSkill(s32 pokeIQ, u8 IQSkillIndex);
void SetIQSkill(u8 *param_1, u32 skillIndex);
bool8 IsIQSkillSet(u8 *IQSkillFlags, u32 IQSkill);

#endif
