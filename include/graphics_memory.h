#ifndef GUARD_GRAPHICS_MEMORY_H
#define GUARD_GRAPHICS_MEMORY_H

#include "structs/axdata.h"

extern RGB_Struct gFontPalette[128];

struct unkStruct_8009A1C_ptr
{
    u8 fill0;
    EfoFileData *ptr;
};

void ResetVramPalOAM(void);
void sub_8009A1C(const EfoFileData *r0, u32 palId, u32 vramDstOffset, u32 r3);
void InitFontPalette(void);
void InitGraphics(void);
void ResetScheduledMemCopies(void);
void ScheduleMemCopy(u32 *, const u32 *, u32);
void ScheduleBgTilemapCopy(u32);
void DoScheduledMemCopies(void);
void CopyBgTilemaps0And1(void);
void SetFontsBaseColor(RGB_Struct);

bool8 sub_8009A7C(struct EfbFileData *a0, s32 a1, s32 a2, s32 a3, bool8 a4, s32 *a5, s16 *a6);
void sub_8009BE4(void);

#endif // GUARD_GRAPHICS_MEMORY_H
