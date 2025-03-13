#ifndef GUARD_CODE_801B3C0_H
#define GUARD_CODE_801B3C0_H

#include "items.h"
#include "structs/menu.h"
#include "structs/str_status_text.h"
#include "structs/str_text.h"

// size: 0x94
typedef struct unkStruct_203B230
{
    s32 state;
    /* 0x4 */ Item item;
    s32 unk8;
    s32 unkC;
    STATUSTEXTS(unk10);
    u32 unk20;
    u32 unk24;
    WindowTemplates unk28;
    MenuInputStructSub unk88;
} unkStruct_203B230;

bool8 InitItemDescriptionWindow(Item *item);
u32 sub_801B410(void);
void FreeItemDescriptionWindow(void);

#endif // GUARD_CODE_801B3C0_H
