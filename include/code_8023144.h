#ifndef GUARD_CODE_8023144_H
#define GUARD_CODE_8023144_H

#include "constants/iq_skill.h"
#include "input.h"
#include "items.h"
#include "menu.h"
#include "pokemon.h"
#include "text.h"

// size: 0x1A8
typedef struct unkStruct_203B294
{
    /* 0x0 */ s32 state;
    /* 0x4 */ s32 fallbackState;
    u8 iqSkillPreGummi[NUM_IQ_SKILLS];
    u8 iqSkillPostGummi[NUM_IQ_SKILLS];
    u32 availIQSkillPreGummi;
    u32 availIQSkillPostGummi;
    u32 unk40; // Gummi eaten flag?
    Gummi gummi;
    /* 0x48 */ PokemonStruct1 *pokeStruct;
    u32 itemIndex;
    Item item;
    MenuStruct unk54;
    MenuStruct unkA4;
    u32 menuAction;
    MenuItem unkF8[0x8];
    u16 unk138[0x8];
    UnkTextStruct2 unk148[4];
} unkStruct_203B294;

// size: 0x3FC
typedef struct unkStruct_3001B5C
{
    u8 unk0;
    u32 unk4;
    u32 unk8;
    s16 unkC[2];
    u32 unk10;
    u8 fill14[0x354 - 0x14];
    u8 unk354;
    u8 fill355[0x35C - 0x355];
    MenuInputStruct input;
    u32 unk390;
    UnkTextStruct2 *unk394;
    UnkTextStruct2 unk398[4];
    u8 unk3F8[4];
} unkStruct_3001B5C;

#endif // GUARD_CODE_8023144_H