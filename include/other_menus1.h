#ifndef GUARD_OTHER_MENUS1_H
#define GUARD_OTHER_MENUS1_H

#include "code_8094F88.h"
#include "main_menu1.h"
#include "structs/menu.h"
#include "pokemon.h"
#include "sprite_oam.h"
#include "structs/str_text.h"

// size: 0x504
typedef struct unkStruct_203B35C
{
    u32 unk0;
    /* 0x4 */ u32 linkStatus;
    /* 0x8 */ u32 state;
    SpriteOAM unkC;
    u32 unk14;
    u8 fill18[0x1C - 0x18];
    MenuStruct unk1C[4];
    UnkTextStruct2 unk15C[4];
    unkStruct_8035D94 unk1BC[2];
    unkStruct_203B480 unk1CC;
    unkStruct_203B480 unk1FC;
    unkStruct_203B480 unk22C;
    unkStruct_203B480 unk25C;
    unkStruct_203B480 unk28C;
    PokemonStruct1 unk2BC;
    unkStruct_203B480 unk314;
    PokemonStruct1 unk344;
    u8 unk39C[180];
    u8 unk450[180];
} unkStruct_203B35C;

void sub_8036FDC(s32);
void sub_80370D4(void);
void sub_80373C4(void);

#endif // GUARD_OTHER_MENUS1_H