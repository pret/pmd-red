#ifndef CODE_801EE10_H
#define CODE_801EE10_H

struct unkStruct_203B270
{
    // size 0xBC
    u32 unk0;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
    /* 0x8 */ struct PokemonStruct *pokeStruct;
    /* 0xC */ u8 isTeamLeader;
    /* 0x10 */ struct Move *moves;
    u8 fill14[0x1C - 0x14];
    u32 unk1C;
    u8 fill20[0x36 - 0x20];
    s16 unk36;
    u8 fill38[0x50 - 0x38];
    u32 unk50;
    u32 unk54;
    struct UnkTextStruct2 unk58[4];
    u8 *unkB8;
};

#endif
