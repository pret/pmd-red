#ifndef GUARD_CODE_80227B8_H
#define GUARD_CODE_80227B8_H

#include "constants/iq_skill.h"
#include "items.h"
#include "structs/menu.h"
#include "pokemon.h"
#include "structs/str_text.h"

// size: 0x1A8
typedef struct unkStruct_203B294
{
    /* 0x0 */ s32 state;
    /* 0x4 */ s32 fallbackState;
    /* 0x8 */ u8 iqSkillPreGummi[NUM_IQ_SKILLS];
    /* 0x20 */ u8 iqSkillPostGummi[NUM_IQ_SKILLS];
    /* 0x38 */ s32 availIQSkillPreGummi;
    /* 0x3C */ s32 availIQSkillPostGummi;
    s32 unk40; // Gummi eaten flag?
    /* 0x44 */ Gummi gummi;
    /* 0x48 */ PokemonStruct1 *pokeStruct;
    /* 0x4C */ u32 itemIndex;
    /* 0x50 */ Item item;
    MenuStruct unk54;
    MenuStruct unkA4;
    /* 0xF4 */ u32 menuAction;
    MenuItem unkF8[8];
    u16 unk138[8];
    Windows unk148;
} unkStruct_203B294;

bool8 sub_80227B8(PokemonStruct1 *pkmn);
u32 sub_8022860(void);
void sub_8022908(void);

#endif // GUARD_CODE_80227B8_H
