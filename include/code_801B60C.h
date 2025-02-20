#ifndef GUARD_CODE_801B60C_H
#define GUARD_CODE_801B60C_H

#include "items.h"
#include "structs/menu.h"
#include "structs/str_text.h"

// size: 0x154
typedef struct unkStruct_203B234
{
    u32 unk0;
    /* 0x4 */ u32 state;
    /* 0x8 */ u32 fallbackState;
    u8 unkC;
    Item unk10;
    struct unkStruct_8090F58 unk14;
    Item unk20;
    u32 unk24;
    MenuStruct unk28;
    MenuStruct unk78;
    /* 0xC8 */ u32 menuAction;
    MenuItem unkCC[5];
    UnkTextStruct3 unkF4;
} unkStruct_203B234;

bool8 sub_801B60C(u32, u8 id, u8 quantity);
u32 sub_801B6AC(void);
void sub_801B72C(void);

#endif // GUARD_CODE_801B60C_H
