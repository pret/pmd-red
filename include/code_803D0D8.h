#ifndef GUARD_CODE_803D0D8_H
#define GUARD_CODE_803D0D8_H

#include "structs/str_wonder_mail.h"

u8 sub_803D0D8(void);
u8 sub_803D0F0(u8);
u8 sub_803D100(u8);
u8 sub_803D110(u8 *param_1, u8 *param_2, s32 size);
void sub_803D1A8(u8 *param_1, u8 *param_2, s32 size);

bool8 sub_803D204(u8 *buffer,unkStruct_203B480 *param_2);
void sub_803D2C0(u8 *buffer, unkStruct_203B480 *mail);
bool8 DecodeWonderMailPassword(u8* buffer, WonderMail *mail);
void sub_803D414(u8 *param_1,WonderMail *mail);

#endif // GUARD_CODE_803D0D8_H
