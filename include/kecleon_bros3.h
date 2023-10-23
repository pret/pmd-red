#ifndef GUARD_KECLEON_BROS3_H
#define GUARD_KECLEON_BROS3_H

#include "structs/menu.h"
#include "structs/str_text.h"

// size: 0xA0
typedef struct unkStruct_203B21C
{
    /* 0x0 */ MenuInputStruct input;
    u32 unk34;
    UnkTextStruct2 *unk38;
    UnkTextStruct2 unk3C[4];
    u8 unk9C[4];
} unkStruct_203B21C;

u8 sub_801A20C(u32);
u32 sub_801A2A8(bool8);
u8 sub_801A37C(void);
void sub_801A398(bool8);
void sub_801A3DC(void);
void sub_801A4A4(void);

#endif // GUARD_KECLEON_BROS3_H