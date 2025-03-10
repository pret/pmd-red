#ifndef GUARD_CODE_IQ_SKILL_MENU_H
#define GUARD_CODE_IQ_SKILL_MENU_H

#include "constants/iq_skill.h"
#include "structs/menu.h"
#include "pokemon.h"
#include "structs/str_text.h"

// size: 0x124
struct IQSkillMenu
{
    /* 0x0 */ u32 state;
    /* 0x4 */ s16 species;
    /* 0x8 */ PokemonStruct1 *pokeStruct;
    /* 0xC */ u8 iqSkills[NUM_IQ_SKILLS];
    /* 0x24 */ u32 menuIndex;
    /* 0x28 */ u8 iqSkillIndex;
    /* 0x2C */ u32 numIQSkills;
    /* 0x30 */ s32 menuAction;
    MenuItem unk34[8];
    MenuStruct unk74;
    WindowTemplates unkC4;
};

bool8 CreateIQSkillMenu(s16 species);
u32 sub_801BF48(void);
void CleanIQSkillMenu(void);

enum IQSkillMenuStates
{
    IQ_SKILL_MENU_STATE_INIT,
    IQ_SKILL_MENU_STATE_MAIN,
    IQ_SKILL_MENU_STATE_INFO = 3,
    IQ_SKILL_MENU_STATE_EXIT
};

enum IQSkillMenuActions
{
    IQ_SKILL_MENU_NULL = 1,
    IQ_SKILL_MENU_SWITCH,
    IQ_SKILL_MENU_INFO,
};

#endif // GUARD_CODE_IQ_SKILL_MENU_H
