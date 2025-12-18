#ifndef GUARD_STRUCTS_EFFECT_DATA_H
#define GUARD_STRUCTS_EFFECT_DATA_H

// Size: 0x8
typedef struct unkStruct_800F18C
{
    /* 0x0 */ s32 effectID;
    /* 0x4 */ u32 counter;
} unkStruct_800F18C;

// Size: R=0x24 | B=?
typedef struct unkStruct_80B9CC4
{
    /* 0x00 */ u32 animType;
    /* 0x04 */ s32 effectId;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 animId;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ u8 unk18;
    /* 0x1C */ s32 unk1c;
    /* 0x20 */ s8 unk20;
    /* 0x21 */ s8 loop;
} unkStruct_80B9CC4;

// Size: 0x24
typedef struct unkStruct_80BDBC4
{
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s16 unk4;
    /* 0x06 */ s16 unk6;
    /* 0x08 */ u8 useSineWobble; // When true, apply a sine wobble to traveling effects (arcing look)
    /* 0x09 */ u8 unk9;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 soundEffectId;
    /* 0x1C */ s32 unk1C; // Amount of gUnknown_80C183C entries to scan
    /* 0x20 */ s32 unk20; // Index into gUnknown_80C183C
} unkStruct_80BDBC4;

// Size: 0xC
typedef struct unkStruct_80C183C
{
    /* 0x0 */ s16 species;
    /* 0x2 */ s16 unk2;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 soundEffectId;
} unkStruct_80C183C;

#endif // GUARD_STRUCTS_EFFECT_DATA_H
