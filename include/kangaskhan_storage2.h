#ifndef GUARD_KANGASKHAN_STORAGE2_H
#define GUARD_KANGASKHAN_STORAGE2_H

#include "items.h"
#include "menu.h"
#include "text.h"

// size: 0x150
typedef struct unkStruct_203B20C
{
    /* 0x0 */ u32 state;
    u8 unk4[4];
    /* 0x8 */ Item item;
    /* 0xC */ u32 itemIndex;
    /* 0x10 */ u8 id;
    /* 0x14 */ u32 menuAction1;
    /* 0x18 */ u32 menuAction2;
    /* 0x1C */ u32 menuAction3;
    MenuItem unk20[8];
    u16 unk60[8];
    MenuStruct unk70;
    u32 unkC0;
    u32 unkC4;
    u32 unkC8;
    u32 unkCC;
    u32 unkD0;
    u32 unkD4;
    UnkTextStruct2 *unkD8;
    u32 unkDC;
    u32 unkE0;
    u8 fillE4[0xF0 - 0xE4];
    UnkTextStruct2 unkF0[4];
} unkStruct_203B20C;

bool8 sub_8017E1C(void);
u32 sub_8017E54(void);
void sub_8017EF4(void);

#endif // GUARD_KANGASKHAN_STORAGE2_H