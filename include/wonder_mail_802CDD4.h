#ifndef GUARD_WONDER_MAIL_802CDD4_H
#define GUARD_WONDER_MAIL_802CDD4_H

#include "structs/menu.h"
#include "structs/str_text.h"

// TODO: UNIFY
// size: 0xA0
typedef struct unkStruct_203B2F4
{
    MenuInputStruct input;
    u32 unk34;
    UnkTextStruct2 *unk38;
    UnkTextStruct2 unk3C[4];
    UnkTextStruct2_sub2 unk9C;
} unkStruct_203B2F4;

bool8 sub_802CDD4(u32);
u32 sub_802CE5C(bool8);
u8 sub_802CEBC(void);
void sub_802CED8(bool8 cursorSprite);
void sub_802CF14(void);
void sub_802CFD0(void);

#endif // GUARD_WONDER_MAIL_802CDD4_H
