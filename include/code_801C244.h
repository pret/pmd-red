#ifndef GUARD_CODE_801C244_H
#define GUARD_CODE_801C244_H

#include "constants/iq_skill.h"
#include "menu.h"
#include "pokemon.h"
#include "structs/str_text.h"

// size: 0xC4
struct unkStruct_203B23C
{
    /* 0x0 */ s16 species;
    /* 0x4 */ PokemonStruct1 *pokeStruct;
    /* 0x8 */ u8 iqSkills[NUM_IQ_SKILLS];
    /* 0x20 */ s32 numIQSkills;
    /* 0x24 */ MenuInputStruct input;
    u32 unk58;
    UnkTextStruct2 *unk5C;
    UnkTextStruct2 unk60[4];
    u8 unkC0;
    u8 unkC1;
    u8 unkC2;
    u8 unkC3;
};

bool8 HasNoAvailIQSkills(s16 species);

bool8 sub_801C244(s16 species, u32 index, u32);
u32 sub_801C308(bool8);
s32 sub_801C390(void);
void sub_801C3B0(bool8);
void sub_801C3F8(void);
void sub_801C4C8(void);

#endif // GUARD_CODE_801C244_H