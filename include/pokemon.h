#ifndef POKEMON_H
#define POKEMON_H

struct gPokemon
{
    /* 0x0 */ u8* species;
    /* 0x4 */ u8* category;
    /* 0x8 */ u8 overworld_sprite;
    /* 0x9 */ u8 size;
    /* 0xA */ u8 unkA;
    /* 0xB */ u8 unkB;
    /* 0xC */ s32 move_speed;
    /* 0x10 */ u16 dialogue_sprites;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 type_1;
    /* 0x14 */ u8 type_2;
    /* 0x15 */ u8 walkable_tiles;
    /* 0x16 */ u8 friend_area;
    /* 0x17 */ u8 ability_1;
    /* 0x18 */ u8 ability_2;
    /* 0x19 */ u8 shadow_size;
    /* 0x1A */ u8 unk1A;
    /* 0x1B */ u8 unk1B;
    /* 0x1C */ bool8 isMoving;
    /* 0x1D */ u8 unk1D;
    /* 0x1E */ u16 base_hp;
    /* 0x20 */ u16 base_exp;
    /* 0x22 */ u16 unk22; // verified
    /* 0x24 */ u16 base_att;
    /* 0x26 */ u16 base_spatt;
    /* 0x28 */ u16 base_def;
    /* 0x2A */ u16 base_spdef;
    /* 0x2C */ u16 lowkick_dmg;
    /* 0x2E */ u16 sizeorb_dmg;
    /* 0x30 */ u8 unk30;
    /* 0x31 */ u8 unk31;
    /* 0x32 */ u8 unk32;
    /* 0x33 */ bool8 unk33;
    /* 0x34 */ u16 evolve_from; //verified
    /* 0x36 */ u16 evolve_type;
    /* 0x38 */ u16 evolve_need1; // verified
    /* 0x3A */ u16 evolve_need2; // verified
    /* 0x3C */ u16 dexNo;
    /* 0x3E */ u16 internalNo; // verified
    /* 0x40 */ s16 base_recruit; // verified
    /* 0x42 */ u16 alphabetNo;
    /* 0x44 */ u16 parentNo;
    /* 0x46 */ u16 unk46;
};

#endif // POKEMON_H  
