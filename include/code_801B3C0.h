#ifndef GUARD_CODE_801B3C0_H
#define GUARD_CODE_801B3C0_H

#include "input.h"
#include "items.h"
#include "subStruct_203B240.h"
#include "text.h"

// size: 0x94
struct unkStruct_203B230
{
    s32 state;
    Item item;
    s32 unk8;
    s32 unkC;
    struct subStruct_203B240 *unk10[2];
    u8 fill18[0x20 - 0x18];
    u32 unk20;
    u32 unk24;
    UnkTextStruct2 unk28[4];
    MenuInputStructSub unk88;
};

u32 sub_801B3C0(Item *);
u32 sub_801B410(void);
void sub_801B450(void);

#endif // GUARD_CODE_801B3C0_H