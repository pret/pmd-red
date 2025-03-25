#ifndef GUARD_CODE_801B3C0_H
#define GUARD_CODE_801B3C0_H

#include "items.h"
#include "structs/menu.h"
#include "structs/str_status_text.h"
#include "structs/str_text.h"

// size: 0x94
typedef struct unkStruct_203B230
{
    /* 0x0 */ s32 state;
    /* 0x4 */ Item item;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
    /* 0x10 */ STATUSTEXTS(unk10);
    /* 0x20 */ u32 unk20;
    /* 0x24 */ u32 unk24;
    /* 0x28 */ WindowTemplates unk28;
    /* 0x88 */ MenuInputStructSub unk88;
} unkStruct_203B230;

bool8 InitItemDescriptionWindow(Item *item);
u32 sub_801B410(void);
void FreeItemDescriptionWindow(void);

#endif // GUARD_CODE_801B3C0_H
