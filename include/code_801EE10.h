#ifndef CODE_801EE10_H
#define CODE_801EE10_H

#include "constants/move.h"

#include "input.h"
#include "pokemon.h"
#include "text.h"

// size 0xBC
typedef struct unkStruct_203B270
{
    u32 unk0;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
    /* 0x8 */ PokemonStruct1 *pokeStruct;
    /* 0xC */ u8 isTeamLeader;
    /* 0x10 */ Move *moves;
    u8 fill14[0x1C - 0x14];
    MenuInputStruct input;
    u32 unk50;
    u32 unk54;
    UnkTextStruct2 unk58[4];
    const u8 *text;
} unkStruct_203B270;

u8 sub_801EE10(u32, s16, Move *, u32, const u8 *, u32);

// code_801EE10.s
extern u32 sub_801EF38(u32);
extern u32 sub_801F194(void);
extern bool8 sub_801F1A4(void);
extern void sub_801F1B0(bool8, bool8);
extern void sub_801F214(void);
extern void sub_801F280(u32); // Probably bool

#endif // CODE_801EE10_H