#ifndef GUARD_CODE_80130A8_H
#define GUARD_CODE_80130A8_H

#include "file_system.h"
#include "menu.h"

// code_80130A8.s
extern void sub_8013AA0(u32 *);
extern u32 sub_8013BBC(u32 *);
extern void sub_8013C68(u32 *);
extern void sub_80141B4(const u8 *, u32, OpenedFile **, u32);
extern void sub_8014248(const u8 *, u32, u32, const MenuItem *, void *, u32, u32, OpenedFile **, u32);
extern s32 sub_80144A4(s32 *);
extern void xxx_format_and_draw(u32, u32, const u8 *, u32, u32);

#endif // GUARD_CODE_80130A8_H