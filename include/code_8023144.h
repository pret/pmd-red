#ifndef GUARD_CODE_8023144_H
#define GUARD_CODE_8023144_H

struct unkStruct_203B294
{   
    // size: 0x1A8
    /* 0x0 */ s32 state;
    /* 0x4 */ s32 fallbackState;
    u8 iqSkillPreGummi[NUM_IQ_SKILLS];
    u8 iqSkillPostGummi[NUM_IQ_SKILLS];
    u32 availIQSkillPreGummi;
    u32 availIQSkillPostGummi;
    u32 unk40; // Gummi eaten flag?
    struct Gummi gummi;
    /* 0x48 */ struct PokemonStruct *pokeStruct;
    u32 itemIndex;
    struct Item item;
    struct MenuStruct unk54;
    struct MenuStruct unkA4;
    u32 menuAction;
    struct MenuItem unkF8[0x8];
    u16 unk138[0x8];
    struct UnkTextStruct2 unk148[4];
};


#endif // GUARD_CODE_8023144_H
