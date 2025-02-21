#ifndef CODE_801EE10_H
#define CODE_801EE10_H

#include "constants/move.h"
#include "pokemon.h"
#include "structs/menu.h"
#include "structs/str_text.h"

// size 0xBC
typedef struct unkStruct_203B270
{
    u32 unk0;
    bool8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
    /* 0x8 */ PokemonStruct1 *pokeStruct;
    /* 0xC */ u8 isTeamLeader;
    /* 0x10 */ Move *moves;
    u8 fill14[0x1C - 0x14];
    /* 0x1C */ MenuInputStruct input;
    u32 unk50;
    u32 unk54;
    UnkTextStruct3 unk58;
    const u8 *text;
} unkStruct_203B270;

u8 sub_801EE10(u32, s16 species, Move *moves, u32, const u8 *text, u32);
u32 sub_801EF38(char);
s32 sub_801F194(void);
bool8 sub_801F1A4(void);
void sub_801F1B0(bool8, bool8);
void sub_801F214(void);
void sub_801F280(bool8);

#endif // CODE_801EE10_H
