#ifndef GUARD_CODE_8009804_H
#define GUARD_CODE_8009804_H

#include "structs/rgb.h"

// size: 0xC
struct unkStruct_202D240
{
    u32 *unk0;
    const u32 *unk4;
    u32 size;
};

void vram_related_8009804(void);

void InitFontPalette(void);
void sub_80098A0(void);
void sub_80098BC(u32 *, const u32 *, u32);
void sub_80098F8(u32);
void sub_8009908(void);
void sub_80099C0(void);
void sub_80099F0(RGB);

#endif // GUARD_CODE_8009804_H
