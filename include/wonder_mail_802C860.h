#ifndef GUARD_WONDER_MAIL_802C860_H
#define GUARD_WONDER_MAIL_802C860_H

#include "structs/str_802C39C.h"
#include "structs/menu.h"
#include "structs/str_text.h"

// size: 0x1FC
struct unkStruct_203B2F0
{
    u32 unk0;
    /* 0x4 */ u32 state;
    u8 unk8[0xC - 0x8];
    u8 unkC;
    unkStruct_802C39C unk10;
    /* 0x68 */ u32 menuAction;
    MenuStruct unk6C;
    MenuStruct unkBC;
    MenuItem unk10C[8];
    MenuItem unk14C[8];
    u8 fill18C[0x19C - 0x18C];
    WindowTemplates unk19C;
};

bool8 InitializeJobListMenu(u32);

u32 sub_802C898(void);
void sub_802C8F4(void);

#endif // GUARD_WONDER_MAIL_802C860_H