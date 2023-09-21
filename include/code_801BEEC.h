#ifndef GUARD_CODE_801BEEC_H
#define GUARD_CODE_801BEEC_H

#include "constants/iq_skill.h"
#include "menu.h"
#include "pokemon.h"
#include "structs/str_text.h"

// size: 0x124
struct unkStruct_203B238
{
    /* 0x0 */ u32 state;
    /* 0x4 */ s16 species;
    /* 0x8 */ PokemonStruct1 *pokeStruct;
    /* 0xC */ u8 iqSkills[NUM_IQ_SKILLS];
    u32 unk24;
    /* 0x28 */ u8 iqSkillIndex;
    /* 0x2C */ u32 numIQSkills;
    /* 0x30 */ s32 menuAction;
    MenuItem unk34[8];
    MenuStruct unk74;
    UnkTextStruct2 unkC4[4];
};

bool8 sub_801BEEC(s16 species);
u32 sub_801BF48(void);
void sub_801BF98(void);

#endif // GUARD_CODE_801BEEC_H