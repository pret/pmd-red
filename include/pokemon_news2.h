#ifndef GUARD_POKEMON_NEWS2_H
#define GUARD_POKEMON_NEWS2_H

#include "structs/menu.h"
#include "structs/str_text.h"

// size: 0x94
struct unkStruct_203B2D4
{
    /* 0x0 */ s32 state;
    /* 0x4 */ u8 currMailIndex;
    s32 unk8;
    s32 unkC;
    const u8 *unk10[4];
    u32 unk20;
    u32 unk24;
    UnkTextStruct3 unk28;
    MenuInputStructSub unk88;
};

bool8 sub_802B9FC(u8 mailIndex);
u32 sub_802BA8C(void);
void sub_802BACC(void);
void sub_802BC7C(void);

#endif // GUARD_POKEMON_NEWS2_H