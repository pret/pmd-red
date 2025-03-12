#ifndef GUARD_IQ_SKILL_INFO_MENU_H
#define GUARD_IQ_SKILL_INFO_MENU_H

#include "structs/menu.h"
#include "structs/str_status_text.h"
#include "structs/str_text.h"

// size: 0x94
struct IQSkillInfoMenu
{
    /* 0x0 */ s32 state;
    /* 0x4 */ u8 chosenIQSkill;
    s32 unk8;
    s32 unkC;
    STATUSTEXTS(unk10);
    u32 unk20;
    u32 unk24;
    WindowTemplates unk28;
    MenuInputStructSub unk88;
};

bool8 CreateIQSkillInfoMenu(u8 iqSkill);
u32 HandleIQSkillInfoMenuState(void);
void CleanIQSkillInfoMenu(void);

#endif // GUARD_IQ_SKILL_INFO_MENU_H
