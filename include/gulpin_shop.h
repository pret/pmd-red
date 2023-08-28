#ifndef GUARD_GULPIN_SHOP_H
#define GUARD_GULPIN_SHOP_H

#include "constants/move.h"
#include "file_system.h"
#include "menu.h"
#include "text.h"

// size: 0x18C
struct GulpinShopWork
{
    /* 0x0 */ u32 isAsleep;
    /* 0x4 */ s32 state;
    u32 unk8;
    /* 0xC */ s16 speciesNum; // species of chosen Pokemon
    /* 0xE */ bool8 isNextMoveLinked;
    /* 0x10 */ struct Move * moves;
    u16 unk14[4];
    u16 unk1C;
    u16 unk1E;
    u32 unk20;
    u32 unk24;
    struct MenuItem unk28[8];
    u16 unk68[8];
    struct MenuStruct unk78;
    u8 fillC8[0x118 - 0xC8];
    /* 0x118 */ struct OpenedFile *faceFile;
    /* 0x11C */ u8 *faceData;
    u16 unk120;
    u16 unk122;
    u8 unk124;
    u8 unk125;
    u8 unk126;
    u8 unk127;
    struct OpenedFile **unk128;
    struct UnkTextStruct2 unk12C[4];
};

u32 CreateGulpinShop(s32 isAsleep, s16 pokeSpecies, struct Move *moves);
void DestroyGulpinShop(void);
bool8 GulpinIsNextMoveLinked(void);

#endif
