#ifndef GUARD_CODE_802DE84_H
#define GUARD_CODE_802DE84_H

#include "structs/str_802C39C.h"
#include "structs/menu.h"
#include "structs/str_text.h"

// size: 0x7C
struct unkStruct_203B300
{
    MenuInputStructSub unk0;
    /* 0xC */ unkStruct_802C39C *mail;
    u32 unk10;
    UnkTextStruct2 *unk14;
    UnkTextStruct3 unk18;
    u8 unk78[4];
};

bool8 sub_802DE84(unkStruct_802C39C *mail);
u32 sub_802DEE0(void);
void sub_802DF24(void);

#endif // GUARD_CODE_802DE84_H
