#ifndef GUARD_KANGASKHAN_STORAGE2_H
#define GUARD_KANGASKHAN_STORAGE2_H

#include "items.h"
#include "structs/menu.h"
#include "structs/str_text.h"

enum KangaskhanStorage2States
{
    KANGASKHAN_STORAGE_2_INIT = 0,
    KANGASKHAN_STORAGE_2_MAIN = 1,
    KANGASKHAN_STORAGE_2_EXIT = 3
};

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
    unkStructFor8013AA0 unkC0;
    UnkTextStruct2 unkF0[4];
} unkStruct_203B20C;

bool8 sub_8017E1C(void);
u32 sub_8017E54(void);
void sub_8017EF4(void);

#endif // GUARD_KANGASKHAN_STORAGE2_H
