#ifndef GUARD_CODE_801C620_H
#define GUARD_CODE_801C620_H

#include "structs/menu.h"
#include "structs/subStruct_203B240.h"
#include "structs/str_text.h"

// size: 0x94
struct unkStruct_203B240
{
    /* 0x0 */ s32 state;
    /* 0x4 */ u8 chosenIQSkill;
    s32 unk8;
    s32 unkC;
    struct subStruct_203B240 *unk10[2];
    u8 fill14[0x20 - 0x18];
    u32 unk20;
    u32 unk24;
    UnkTextStruct2 unk28[4];
    MenuInputStructSub unk88;
};

bool8 CreateIQSkillInfoMenu(u8 iqSkill);
u32 HandleIQSkillInfoMenuState(void);
void CleanIQSkillInfoMenu(void);

#endif // GUARD_CODE_801C620_H
