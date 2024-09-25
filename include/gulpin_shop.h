#ifndef GUARD_GULPIN_SHOP_H
#define GUARD_GULPIN_SHOP_H

#include "file_system.h"
#include "structs/menu.h"
#include "structs/str_text.h"
#include "structs/str_moves.h"

// size: 0x18C
typedef struct GulpinShopWork
{
    /* 0x0 */ u32 mode; // Corresponds to the enum: GulpinShopMode
    /* 0x4 */ s32 state;
    u32 unk8;
    /* 0xC */ s16 speciesNum; // species of chosen Pokemon
    /* 0xE */ bool8 isNextMoveLinked;
    /* 0x10 */ Move *moves;
    u16 unk14[4];
    u16 unk1C;
    u16 unk1E;
    u32 unk20;
    u32 unk24;
    MenuItem unk28[8];
    u16 unk68[8];
    MenuStruct unk78;
    u8 fillC8[0x118 - 0xC8];
    /* 0x118 */ OpenedFile *faceFile;
    /* 0x11C */ u8 *faceData;
    u16 unk120;
    u16 unk122;
    u8 unk124;
    u8 unk125;
    u8 unk126;
    u8 unk127;
    OpenedFile **unk128;
    UnkTextStruct2 unk12C[4];
} GulpinShopWork;

bool8 CreateGulpinShop(u32 mode, s16 pokeSpecies, Move *moves);
void DestroyGulpinShop(void);
bool8 GulpinIsNextMoveLinked(void);

u32 sub_801E8C0(void);

#endif // GUARD_GULPIN_SHOP_H
