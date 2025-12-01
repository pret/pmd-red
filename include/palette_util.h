#ifndef GUARD_PALETTE_UTIL_H
#define GUARD_PALETTE_UTIL_H

#include "constants/palette_util.h"
#include "structs/rgb.h"

void sub_8099744(void);
void sub_8099750(void);
void sub_809975C(void);
void sub_8099768(void);
void sub_809977C(void);
void sub_80997F4(u16 a0, u16 a1);
void sub_80999D4(s32 a0);
void sub_80999E8(s32 a0);
void sub_80999FC(s32 a0);
void sub_8099A10(s32 a1, u16 a2, u16 a3);
void sub_8099A34(s32 a0);
void sub_8099A48(s32 a0);
// a0: See enum "PaletteUtilUnk0Kind"
void sub_8099A5C(s32 kind, s32 a1, RGB_Array a2);
// a0: See enum "PaletteUtilUnk0Kind"
void sub_8099AFC(s32 kind, s32 a1, RGB_Array a2);
bool8 sub_8099B94(void);
void sub_8099BE4(void);

#endif // GUARD_PALETTE_UTIL_H
