#ifndef GUARD_GROUND_MAIN_H
#define GUARD_GROUND_MAIN_H

#include "structs/str_pokemon.h"
#include "structs/str_wonder_mail.h"

struct unkStruct_20398C8
{
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 fill5[0xB - 0x5];
    u8 unkB;
    u8 unkC;
    u8 unkD;
    WonderMailSub unk10;
    PokemonStruct1 unk18;
    u8 fill70[0x88 - 0x70];
};

// size: 0xC
typedef struct GroundConversionStruct
{
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    /* 0x8 */ u8 *text;
} GroundConversionStruct;

bool8 sub_8098F88(void);
const char *sub_8098FB4(void);

bool8 GroundMainGroundRequest(s32 r0, s32 r1, s32 r2);
bool8 GroundMainRescueRequest(s32 r0, s32 r1);
bool32 GroundMainGameEndRequest(u32 r0);
bool32 GroundMainGameCancelRequest(u32 r0);
bool8 sub_8098D80(u32 speed);

extern GroundConversionStruct gGroundConversion_811BAF4[10];

#endif // GUARD_GROUND_MAIN_H
