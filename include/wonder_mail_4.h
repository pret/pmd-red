#ifndef WONDER_MAIL_4_H
#define WONDER_MAIL_4_H

#include "structs/str_text.h"

u32 sub_80306A8(u32 wonderMailType, u32 r1, UnkTextStruct2_sub *r2, u32 r3);
u32 sub_8030768(u8 r0);
u8 sub_80307EC(void);
void sub_8030810(u8 r0);
void sub_803084C(void);
u8 *sub_8030894(void);
void sub_803092C(void);
bool8 HasNoWonderMailType(u32 wonderMailType);

#endif /* ifndef WONDER_MAIL_4_H */
