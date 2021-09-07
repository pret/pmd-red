#ifndef GUARD_DUNGEON_DATA_H
#define GUARD_DUNGEON_DATA_H

#define DUNGEON_SIZE_X 55
#define DUNGEON_SIZE_Y 31

#include "dungeon_entity.h"
#include "constants/species.h"

struct DungeonGlobalData
{
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 fill5[0x7 - 0x5];
    u8 unk7;
    u8 fill8[0xF - 0x8];
    /* 0xF */ bool8 inputAllowed; // Whether the game is currently accepting input. Set to false while action animations play.
    u8 fill10;
    u8 unk11;
    u8 fill12[0x16D - 0x12];
    u8 unk16D;
    u8 fill16E[0x179 - 0x16E];
    /* 0x179 */ bool8 pokemonExposed; // True if a Pokémon on the floor has the Exposed status.
    u8 fill17A[0x645 - 0x17A];
    /* 0x645 */ u8 floorNumber;
    u8 fill646[0x660 - 0x646];
    /* 0x660 */ u8 speedTurnCounter; // Handles turn order when Pokémon have different movement speeds.
    u8 fill661[0x666 - 0x661];
    /* 0x666 */ u16 turnsRemaining; // Turns remaining before getting swept out of the dungeon.
    u8 fill668[0x671 - 0x668];
    /* 0x671 */ bool8 monsterHouseActive;
    u8 fill672[0x363C - 0x672];
    /* 0x363C */ u8 expYieldRankings[NUM_SPECIES];
    u8 fill37E3[0x37FC - 0x37D9];
    /* 0x37FC */ bool8 decoyActive;
    u8 fill37FD[0x3A0E - 0x37FD];
    /* 0x3A0E */ s16 tileset;
    u8 fill3A10[0x3A14 - 0x3A10];
    /* 0x3A14 */ s16 bossBattleIndex;
    /* 0x3A18 */ u32 mapEntities[DUNGEON_SIZE_X * DUNGEON_SIZE_Y];
    u8 fill54BC[0xE23C - 0x54BC];
    s16 unkE23C;
    s16 unkE23E;
    u8 fillE240[0xE265 - 0xE240];
    u8 unkE265;
    u8 fillE266[0xE26B - 0xE266];
    u8 unkE26B;
    u8 unkE26C;
    u8 fillE26D[0x1356C - 0xE26D];
    u8 unk1356C;
    u8 fill1356D[0x1358C - 0x1356D];
    struct DungeonEntity *unk1358C[0x10];
    u8 fill135CC[0x181FC - 0x135CC];
    u32 unk181FC;
    u32 unk18200;
    u32 unk18204;
    u8 unk18208[3];
    u8 unk1820B;
    u32 unk1820C;
    u32 unk18210;
    u8 padding2[3];
    u8 unk18217;
};

#endif
