#ifndef GUARD_GROUND_SPRITE_H
#define GUARD_GROUND_SPRITE_H

// size: 0xC
struct unkStruct_2039DB0
{
    u16 unk0;
    s16 unk2;
    u16 unk4;
    u16 unk6;
    u16 unk8;
    u16 unkA;
};

// size: 0xC
struct unkStruct_3001B7C_sub0
{
    u32 unk0;
    s32 unk4;
    u32 unk8;
};
// size: 0x4
struct unkStruct_3001B7C_sub108
{
    u16 unk0;
    s16 unk2;
};
// size: 0x110
struct unkStruct_3001B7C
{
    struct unkStruct_3001B7C_sub0 unk0[22];
    struct unkStruct_3001B7C_sub108 unk108[2];
};

void GroundSprite_Reset(s16);

#endif // GUARD_GROUND_SPRITE_H