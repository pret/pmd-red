#ifndef GUARD_CODE_801C244_H
#define GUARD_CODE_801C244_H

#include "constants/iq_skill.h"
#include "structs/menu.h"
#include "pokemon.h"
#include "structs/str_text.h"
#include "structs/struct_sub80095e4.h"

// size: 0xC4
struct unkStruct_203B23C
{
    /* 0x0 */ s16 species;
    /* 0x4 */ PokemonStruct1 *pokeStruct;
    /* 0x8 */ u8 iqSkills[NUM_IQ_SKILLS];
    /* 0x20 */ s32 numIQSkills;
    /* 0x24 */ struct_Sub80095E4_2 s24;
};

bool8 HasNoAvailIQSkills(s16 species);

bool8 CreateIQSkillListMenu(s16 species, u32 index, u32);
u32 HandleIQSkillListMenuInput(bool8);
s32 GetIQSkillSelection(void);
void sub_801C3B0(bool8);
void CleanIQSkillListMenu(void);
void BuildIQSkillList(void);

#endif // GUARD_CODE_801C244_H
