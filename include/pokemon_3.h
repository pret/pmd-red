#ifndef GUARD_POKEMON_3_H
#define GUARD_POKEMON_3_H

#include "pokemon.h"
#include "structs/str_spawn_pokemon_data.h"

bool8 HasRecruitedMon(s32 species_);
s16 GetBaseSpecies(s16 index);
s16 GetBaseSpeciesNoUnown(s16 index);
bool8 TacticsTargetLeader(u8 tactic);
bool8 HasIQForSkill(s32 pokeIQ, u8 IQSkillIndex);
s32 GetNumAvailableIQSkills(u8 *iqSkillBuffer, s32 pokeIQ);
void CopyTacticsNameToBuffer(char *buffer, u8 tactic);
const u8 *GetIQSkillName(u8 skill);
const u8 *GetIQSkillDescription(u8 skill);
const u8 *GetTacticsDescription(u8 tactic);
void ToggleIQSkill(IqSkillFlags *iq, u32 skillIndex);
void SetIQSkill(IqSkillFlags *iq, u32 skillIndex);
bool8 IsIQSkillSet(IqSkillFlags *iq, u32 IQSkillBit);
void SetDefaultIQSkills(IqSkillFlags *iq, bool8 enableSelfCurer);
s16 ExtractSpeciesIndex(SpawnPokemonData *data);
void SetSpeciesToExtract(SpawnPokemonData *data, s32 species_);
void SetSpeciesLevelToExtract(SpawnPokemonData *data, s32 level, s32 species_);
s32 ExtractLevel(SpawnPokemonData *data);

void sub_808ED00(void);

#endif // GUARD_POKEMON_3_H
