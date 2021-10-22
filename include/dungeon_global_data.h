#ifndef GUARD_DUNGEON_DATA_H
#define GUARD_DUNGEON_DATA_H

#define DUNGEON_MAX_SIZE_X 55
#define DUNGEON_MAX_SIZE_Y 31
#define ALL_POKEMON_SIZE 0x14

#include "constants/species.h"
#include "dungeon_entity.h"
#include "map.h"

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
    u8 fill646[0x65C - 0x646];
    u8 unk65C;
    u8 fill65D[0x660 - 0x65D];
    /* 0x660 */ u8 speedTurnCounter; // Handles turn order when Pokémon have different movement speeds.
    u8 fill661[0x666 - 0x661];
    /* 0x666 */ u16 turnsLeft; // Turns remaining before getting swept out of the dungeon.
    u8 fill668[0x66A - 0x668];
    u16 unk66A;
    u8 fill66C[0x671 - 0x66C];
    /* 0x671 */ bool8 monsterHouseActive;
    u8 fill672[0x363C - 0x672];
    /* 0x363C */ u8 expYieldRankings[NUM_SPECIES];
    u8 fill37E3[0x37FC - 0x37D9];
    /* 0x37FC */ bool8 decoyActive;
    u8 fill37FD[0x3A0D - 0x37FD];
    /* 0x3A0D */ u8 unk3A0D;
    /* 0x3A0E */ s16 tileset;
    u8 fill3A10[0x3A14 - 0x3A10];
    /* 0x3A14 */ s16 bossBattleIndex;
    u8 fill3A16[0x3A18 - 0x3A16];
    /* 0x3A18 */ struct MapTile mapTiles[DUNGEON_MAX_SIZE_X * DUNGEON_MAX_SIZE_Y];
    u8 fill54BC[0xE23C - 0xD9F0];
    s16 unkE23C;
    s16 unkE23E;
    u8 fillE240[0xE264 - 0xE240];
    /* 0xE264 */ u8 weather; // Uses the weather constants in weather.h.
    u8 unkE265;
    /* 0xE266 */ u8 weatherDamageTimer; // Timer for applying sandstorm/hail damage periodically.
    u8 fillE266[0xE26B - 0xE267];
    u8 unkE26B;
    u8 weatherTurnsLeft;
    u8 fillE26D[0xE270 - 0xE26D];
    /* 0xE270 */ u8 startingWeather; // The weather at the start of the floor. If the weather changes, then expires, revert back to the starting weather.
    u8 fillE271[0xE277 - 0xE271];
    /* 0xE277 */ u8 mudSportTurnsLeft;
    /* 0xE278 */ u8 waterSportTurnsLeft;
    u8 fillE279[0xE8C0 - 0xE279];
    /* 0xE8C0 */ u32 mapEntityPointers[DUNGEON_MAX_SIZE_X * DUNGEON_MAX_SIZE_Y];
    u8 fill10364[0x10844 - 0x10364];
    /* 0x10844 */ u16 numRoomExits[MAX_ROOM_COUNT];
    u8 fill10874[0x10884 - 0x10874];
    /* 0x10884 */ struct RoomExit roomExits[MAX_ROOM_COUNT][32]; // Arrays of room exits for each room.
    u8 fill11444[0x1356C - 0x11484];
    u8 unk1356C;
    u8 fill1356D[0x1357C - 0x1356D];
    /* 0x1357C */ struct DungeonEntity *teamPokemon[MAX_TEAM_MEMBERS];
    /* 0x1358C */ struct DungeonEntity *wildPokemon[0x10];
    /* 0x135CC */ struct DungeonEntity *allPokemon[ALL_POKEMON_SIZE]; // Contains both team and wild Pokémon
    /* 0x1361C */ struct DungeonEntity *clientPokemon[2]; // Not sure how large this array is.
    u8 fill13624[0x181F8 - 0x13624];
    /* 0x181F8 */ struct DungeonEntity *leader; // Pointer to the team leader.
    u32 unk181FC;
    u32 unk18200;
    u32 unk18204;
    u8 unk18208;
    /* 0x18209 */ u8 visibility; // Dungeon light level.
    /* 0x1820A */ bool8 displayBlinker; // Blacks out the screen when the player has the Blinker status.
    u8 unk1820B;
    u32 unk1820C;
    /* 0x18210 */ bool8 displayCrossEyed; // Displays Subsitute and flower sprites when the player has the Cross-Eyed status.
    u8 fill18211[0x18217 - 0x18211];
    u8 unk18217;
};

#endif
