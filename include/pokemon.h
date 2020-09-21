#ifndef POKEMON_H
#define POKEMON_H

struct gPokemon
{
    /* 0x0 */ u32 species; // pointer to string
    /* 0x4 */ u32 category; // pointer to string
    /* 0x8 */ u8 palette; // between 0 - 12
    /* 0x9 */ u8 size; // between 0x01 - 0x06
    /* 0xA */ u8 unk0;
    /* 0xB */ u8 unk1;
    /* 0xC */ s32 speed;
    /* 0x10 */ u16 dial_sprite;
    /* 0x12 */ u8 unk2;
    /* 0x13 */ u8 type_1; // between 0x00 - 0x11
    /* 0x14 */ u8 type_2; // between 0x00 - 0x11
    /* 0x15 */ u8 walkable_tiles; // between 0x00 - 0x05
    /* 0x16 */ u8 friend_area; // 0x00 - 0x39
    /* 0x17 */ u8 ability_1; // between 0x00 - 0x4C
    /* 0x18 */ u8 ability_2; // between 0x00 - 0x4C
    /* 0x19 */ u8 shadow_size; // between 0x0 - 0x2
    /* 0x1A */ u8 unk3;
    /* 0x1B */ u8 unk4;
    /* 0x1C */ bool8 isMoving;
    /* 0x1D */ u8 unk5;
    /* 0x1E */ u16 base_hp;
    /* 0x20 */ u16 base_exp;
    /* 0x22 */ u16 unk6;
    /* 0x24 */ u16 base_att;
    /* 0x26 */ u16 base_sp_att;
    /* 0x28 */ u16 base_def;
    /* 0x2A */ u16 base_sp_def;
    /* 0x2C */ u16 lowkick_dmg;
    /* 0x2E */ u16 sizeorb_dmg;
    /* 0x30 */ u8 unk7;
    /* 0x31 */ u8 unk8;
    /* 0x32 */ u8 unk9;
    /* 0x33 */ bool8 unk10;
    /* 0x34 */ u16 prior_evolution;
    /* 0x36 */ u16 evol_type;
    /* 0x38 */ u16 evol_need1;
    /* 0x3A */ u16 evol_need2;
    /* 0x3C */ u16 dexNum;
    /* 0x3E */ u8 internalNum;
    /* 0x40 */ u16 base_recruit;
    /* 0x42 */ u16 unk11;
    /* 0x44 */ u16 alphaNum;
    /* 0x46 */ u16 parentNum;
};

#endif // POKEMON_H  
