#ifndef GUARD_POST_OFFICE_GUIDE2_H
#define GUARD_POST_OFFICE_GUIDE2_H

#include "structs/menu.h"
#include "structs/str_text.h"

// size: 0x78
typedef struct unkStruct_203B330
{
    /* 0x0 */ MenuInputStructSub input;
    u8 unkC;
    /* 0xD */ u8 dungeonIndex;
    u32 unk10;
    WindowTemplate *unk14;
    WindowTemplates unk18;
} unkStruct_203B330;

bool8 sub_80319A4(u8, u8 dungeon, s32);
u32 sub_80319F8(void);
void sub_8031A3C(void);

#endif // GUARD_POST_OFFICE_GUIDE2_H