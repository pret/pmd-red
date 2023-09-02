#ifndef CODE_801EE10_H
#define CODE_801EE10_H

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
    u8 *text;
} unkStruct_203B270;

#endif
