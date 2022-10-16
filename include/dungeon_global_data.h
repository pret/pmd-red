#ifndef GUARD_DUNGEON_DATA_H
#define GUARD_DUNGEON_DATA_H

#include "constants/species.h"
#include "dungeon_entity.h"
#include "global.h"
#include "map.h"
#include "position.h"

#define DUNGEON_MAX_SIZE_X 56
#define DUNGEON_MAX_SIZE_Y 32
#define DUNGEON_MAX_WILD_POKEMON 16
#define DUNGEON_MAX_POKEMON MAX_TEAM_MEMBERS + DUNGEON_MAX_WILD_POKEMON

extern struct DungeonGlobalData *gDungeonGlobalData;

struct DungeonGlobalData_sub
{
    u8 unk0;
    u8 unk1;
    u8 unk2;
};

struct DungeonGlobalData
{
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 fill5[0x7 - 0x5];
    u8 unk7;
    u8 unk8;
    u8 fill9[0xC - 0x9];
    u8 unkC;
    u8 unkD[0xF - 0xD];
    /* 0xF */ bool8 inputAllowed; // Whether the game is currently accepting input. Set to false while action animations play.
    u8 fill10;
    u8 unk11;
    s16 unk12;
    u8 fill14[0x16D - 0x14];
    u8 unk16D;
    u8 fill16E[0x179 - 0x16E];
    /* 0x179 */ bool8 pokemonExposed; // True if a Pokémon on the floor has the Exposed status.
    u8 fill17A[0x17C - 0x17A];
    struct DungeonGlobalData_sub unk17C[0x100];
    /* 0x57C */ u8 fill57C[0x644 - 0x57c];
    /* 0x644 */ u8 unk644;
    /* 0x645 */ u8 floorNumber;
    u8 fill646[0x65C - 0x646];
    u8 unk65C;
    u8 fill65D[0x660 - 0x65D];
    /* 0x660 */ u16 speedTurnCounter; // Handles turn order when Pokémon have different movement speeds.
    u8 fill662[0x666 - 0x662];
    /* 0x666 */ u16 turnsLeft; // Turns remaining before getting swept out of the dungeon.
    u8 fill668[0x66A - 0x668];
    u16 unk66A;
    u8 fill66C[0x671 - 0x66C];
    /* 0x671 */ bool8 monsterHouseActive;
    /* 0x672 */ u8 unk672;
    u8 fill673[0x674 - 0x673];
    u8 unk674;
    u8 unk675;
    /* 0x676 */ bool8 itemHoldersIdentified;
    u8 unk677[0x68A - 0x677];
    /* 0x68A */ u8 unk68A;
    u8 fill68B[0x363C - 0x68B];
    /* 0x363C */ u8 expYieldRankings[NUM_SPECIES];
    u8 fill37E3[0x37FC - 0x37D9];
    /* 0x37FC */ bool8 decoyActive;
    u8 fill37FD[0x3A0D - 0x37FD];
    /* 0x3A0D */ u8 unk3A0D;
    /* 0x3A0E */ s16 tileset;
    u8 fill3A10[0x3A14 - 0x3A10];
    /* 0x3A14 */ s16 bossBattleIndex;
    /* 0x3A18 */ struct MapTile mapTiles[DUNGEON_MAX_SIZE_Y][DUNGEON_MAX_SIZE_X];
    u8 fillE218[0xE23C - 0xE218];
    s16 unkE23C;
    s16 unkE23E;
    u8 fillE240[0xE264 - 0xE240];
    /* 0xE264 */ u8 weather; // Uses the weather constants in weather.h.
    u8 unkE265; // Uses the weather constants in weather.h
    /* 0xE266 */ u8 weatherDamageTimer; // Timer for applying sandstorm/hail damage periodically.
    u8 unkE267[0xE26B - 0xE267];
    u8 unkE26B;
    u8 weatherTurnsLeft;
    u8 fillE26D[0xE26F - 0xE26D];
    /* 0xE26F */ u8 startingWeather[8]; // The weather at the start of the floor. If the weather changes, then expires, revert back to the starting weather.
    /* 0xE277 */ u8 mudSportTurnsLeft;
    /* 0xE278 */ u8 waterSportTurnsLeft;
    /* 0xE279 */ u8 negateWeatherEffects; // Air Lock and Cloud Nine toggle this to disable weather effects
    u8 fillE27A[0xE8C0 - 0xE27A];
    /* 0xE8C0 */ struct MapTile* mapTilePointers[DUNGEON_MAX_SIZE_Y][DUNGEON_MAX_SIZE_X];
    u8 fill104C0[0x104C4 - 0x104C0];
    /* 0x104C4 */ struct MapRoom roomData[MAX_ROOM_COUNT];
    u8 fill10764[0x10844 - 0x10764];
    /* 0x10844 */ s16 numRoomExits[MAX_ROOM_COUNT];
    u8 fill10874[0x10884 - 0x10874];
    /* 0x10884 */ struct Position roomExits[MAX_ROOM_COUNT][32]; // Arrays of room exits for each room.
    u8 fill11444[0x1356C - 0x11484];
    u8 unk1356C;
    u8 fill1356D[0x13570 - 0x1356D];
    /* 0x13570 */ u8 unk13570;
    u8 fill13571[0x13574 - 0x13571];
    /* 0x13574 */ u16 unk13574;
    /* 0x13576 */ u16 unk13576;
    /* 0x13578 */ u8 unk13578;
    /* 0x13579 */ u8 unk13579;
    u8 fill1357A[0x1357C - 0x1357A];
    /* 0x1357C */ struct DungeonEntity *teamPokemon[MAX_TEAM_MEMBERS];
    /* 0x1358C */ struct DungeonEntity *wildPokemon[DUNGEON_MAX_WILD_POKEMON];
    /* 0x135CC */ struct DungeonEntity *allPokemon[DUNGEON_MAX_POKEMON]; // Contains both team and wild Pokémon
    /* 0x1361C */ struct DungeonEntity *clientPokemon[2]; // Not sure how large this array is.
    u8 fill13624[0x17B30 - 0x13624];
    /* 0x17B30 */ u32 unk17B30;
    /* 0x17B34 */ u8 fillunk1734[0x17B3C - 0x17B34];
    /* 0x17B30 */ u32 unk17B3C;
    u8 fill17B40[0x181E8 - 0x17B40];
    /* 0x181E8 */ struct Position posScreenWorld;
    /* 0x181EC */ struct Position prevPosScreenWorld;
    /* 0x181F0 */ struct Position posScreenPixel;
    /* 0x181F4 */ struct Position prevPosScreenPixel;
    /* 0x181F8 */ struct DungeonEntity *leader; // Pointer to the team leader.
    u32 unk181FC;
    u32 unk18200;
    u32 unk18204;
    u8 unk18208;
    /* 0x18209 */ u8 visibility; // Dungeon light level.
    /* 0x1820A */ bool8 displayBlinker; // Blacks out the screen when the player has the Blinker status.
    u8 unk1820B;
    u32 unk1820C;
    /* 0x18210 */ bool8 displayCrossEyed; // Displays Substitute and flower sprites when the player has the Cross-Eyed status.
    u8 fill18211[0x18217 - 0x18211];
    u8 unk18217;
    u8 fill18218[0x1C578 - 0x18218];
    u8 unk1C578;
};

#endif
