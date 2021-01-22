#ifndef POKEMON_H
#define POKEMON_H

struct EvolveStruct1
{
    /* 0x34 */ u16 evolve_from;
    /* 0x36 */ u16 evolve_type;
};

struct EvolveNeeds
{
    /* 0x38 */ u16 evolve_need1;
    /* 0x3A */ u16 evolve_need2;
};

struct gPokemon
{
    /* 0x0 */ u8* species;
    /* 0x4 */ u8* category;
    /* 0x8 */ u8 overworld_palette;
    /* 0x9 */ u8 size;
    /* 0xA */ u8 unkA;
    /* 0xB */ u8 unkB;
    /* 0xC */ s32 move_speed;
    /* 0x10 */ u16 dialogue_sprites;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 types[2];
    /* 0x15 */ u8 walkable_tiles;
    /* 0x16 */ u8 friend_area;
    /* 0x17 */ u8 abilities[2];
    /* 0x19 */ u8 shadow_size;
    /* 0x1A */ u8 unk1A;
    /* 0x1B */ u8 unk1B;
    /* 0x1C */ bool8 isMoving;
    /* 0x1D */ u8 unk1D;
    /* 0x1E */ u16 base_hp;
    /* 0x20 */ u16 base_exp;
    /* 0x22 */ u16 unk22;
    /* 0x24 */ u16 base_att_spatt[2];
    /* 0x28 */ u16 base_def_spdef[2];
    /* 0x2C */ u16 lowkick_dmg;
    /* 0x2E */ u16 sizeorb_dmg;
    /* 0x30 */ u8 unk30;
    /* 0x31 */ u8 unk31;
    /* 0x32 */ u8 unk32;
    /* 0x33 */ bool8 unk33;
    /* 0x34 */ struct EvolveStruct1 pre;
    /* 0x38 */ struct EvolveNeeds need;
    /* 0x3C */ s16 unk3C[2]; // dexNo and internalNo
    /* 0x40 */ s16 base_recruit;
    /* 0x42 */ s16 unk42[2]; // alphabetNo and parentNo
};

#endif // POKEMON_H  
