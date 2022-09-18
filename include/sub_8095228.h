#ifndef GUARD_SUB_8095228_H
#define GUARD_SUB_8095228_H

struct unkStruct_8095228
{
    /* 0x0 */ u8 mailType; // mail type
    /* 0x1 */ u8 missionType; // mission type
    /* 0x2 */ u8 unk2;
    /* 0x3 */ u8 unk3;
    /* 0x4 */ struct DungeonLocation dungeon; // dungeon
    /* 0x8 */ u32 unk8;
    /* 0xC */ s16 clientSpecies; // client pokemon
    /* 0xE */ s16 targetSpecies; // target
    u32 unk10; // TODO: verify that this is just a union of the 4 bytes in Wonder Mail
    u8 padding2[0x20 - 0x14];
    struct ItemSlot unk20;
    u8 padding3[0x28 - 0x24];
    u32 unk28;
    s8 unk2C;
    u8 padding4[0x30 - 0x2D];
};

extern struct unkStruct_8095228 *sub_8095228(u8);

#endif // GUARD_SUB_8095228_H
