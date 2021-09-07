#ifndef GUARD_GUNKNOWN_203B418_H
#define GUARD_GUNKNOWN_203B418_H

#include "dungeon_entity.h"

struct unkStruct_203B418
{
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 fill5[2];
    u8 unk7;
    u8 fill8[0x11 - 8];
    u8 unk11;
    u8 fill12[0x16D - 0x12];
    u8 unk16D;
    u8 fill16E[0x65C - 0x16E];
    u8 unk65C;
    u8 fill65D[0x66A - 0x65D];
    u16 unk66A;
    u8 fill66B[0xE23C - 0x66C];
    s16 unkE23C;
    s16 unkE23E;
    u8 fillE240[0xE265 - 0xE240];
    u8 unkE265;
    u8 fillE266[0xE26B - 0xE266];
    u8 unkE26B;
    u8 unkE26C;
    u8 fillE26D[0x1356C - 0xE26D];
    u8 unk1356C;
    u8 fill1356D[0x1358C - 0x1356D];
    struct DungeonEntity *unk1358C[0x10];
    u8 fill135CC[0x181FC - 0x135CC];
    u32 unk181FC;
    u32 unk18200;
    u32 unk18204;
    u8 unk18208[3];
    u8 unk1820B;
    u32 unk1820C;
    u32 unk18210;
    u8 padding2[3];
    u8 unk18217;
};

#endif
