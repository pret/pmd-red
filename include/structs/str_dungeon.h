#ifndef GUARD_STR_DUNGEON_H
#define GUARD_STR_DUNGEON_H

#include "global.h"
#include "constants/monster.h"
#include "structs/dungeon_entity.h"
#include "file_system.h"
#include "structs/map.h"
#include "structs/str_position.h"
#include "sprite.h"

#define DUNGEON_MAX_SIZE_X 56
#define DUNGEON_MAX_SIZE_Y 32
#define DUNGEON_MAX_WILD_POKEMON 16
#define DUNGEON_MAX_POKEMON MAX_TEAM_MEMBERS + DUNGEON_MAX_WILD_POKEMON
#define DUNGEON_MAX_TRAPS 64
#define DUNGEON_MAX_ITEMS 64

// size: 0x4
typedef struct DungeonLocation
{
    /* 0x0 */ u8 id;
    /* 0x1 */ u8 floor;
} DungeonLocation;

// size: 0x4
// This might be "RGB"... see `SetDungeonBGColorRGB()`
typedef struct Dungeon_sub
{
    u8 unk0;
    u8 unk1;
    u8 unk2;
} Dungeon_sub;

typedef struct Weather
{
    /* 0xE264 */ u8 weather; // Uses the weather constants in weather.h.
    u8 unkE265; // Uses the weather constants in weather.h
    /* 0xE266 */ u8 weatherDamageCounter; // Timer for applying sandstorm/hail damage periodically.
    /* 0xE267 */ u8 unkE267[8];
    /* 0xE26F */ u8 naturalWeather[8]; // The weather at the start of the floor. If the weather changes, then expires, revert back to the starting weather.
    /* 0xE277 */ u8 mudSportTurns;
    /* 0xE278 */ u8 waterSportTurns;
    /* 0xE279 */ bool8 nullifyWeather; // Air Lock and Cloud Nine toggle this to disable weather effects

} Weather;

// size: 0x30
typedef struct unkDungeonGlobal_unk1CE98_sub
{
    /* 0x0 */ u8 buffer1[10];
    /* 0xA */ u8 buffer2[10];
    /* 0x14 */ s16 moveID;
    /* 0x16 */ u8 fill16[0x2];
    /* 0x18 */ DungeonLocation dungeonLocation;
    /* 0x1C */ Item heldItem;
    /* 0x20 */ u32 exp;
    /* 0x24 */ s16 maxHPStat;
    /* 0x26 */ u8 atk;
    /* 0x27 */ u8 spAtk;
    /* 0x28 */ u8 def;
    /* 0x29 */ u8 spDef;
    /* 0x2A */ u8 level;
    /* 0x2B */ u8 attBoost;
    /* 0x2C */ u8 spAttBoost;
    /* 0x2D */ u8 defBoost;
    /* 0x2E */ u8 spDefBoost;
    u8 unk2F; // speedBoost?
} unkDungeonGlobal_unk1CE98_sub;

// size: 0x10
typedef struct DungeonMusicPlayer
{
    /* 0x0 */ u32 state;
    /* 0x4 */ u32 fadeOutSpeed;
    /* 0x8 */ u16 fadeInSpeed;
    /* 0xA */ u16 songIndex;
    /* 0xC */ u16 pastSongIndex;
    /* 0xE */ u16 queuedSongIndex;
} DungeonMusicPlayer;

// Size unknown?
typedef struct unkDungeonGlobal_unk181E8_sub
{
    /* 0x181E8 */ Position cameraPos;
    /* 0x181EC */ Position cameraPosMirror;
    /* 0x181F0 */ Position cameraPixelPos;
    /* 0x181F4 */ Position cameraPixelPosMirror;
    /* 0x181F8 */ Entity *cameraTarget;
    u32 unk181FC;
    u32 unk18200;
    u32 unk18204;
    u8 unk18208;
    /* 0x18209 */ u8 visibilityRange; // Dungeon light level.
    /* 0x1820A */ bool8 blinded; // Blacks out the screen when the player has the Blinker status.
    u8 unk1820B;
    u8 unk1820C;
    u8 unk1820D;
    u8 unk1820E;
    u8 unk1820F;
    /* 0x18210 */ bool8 hallucinating; // Displays Substitute and flower sprites when the player has the Cross-Eyed status.
    u8 unk18211;
    u8 unk18212;
    u8 unk18213;
    u8 unk18214;
    u8 unk18215;
    u8 fill18216;
    u8 unk18217;
    u8 fill18218;
    u8 fill18219;
    u8 unk1821A;
    u8 unk1821B;
    u8 unk1821C;
    u8 fill1821D;
    u8 fill1821E;
    u8 fill1821F;
} unkDungeonGlobal_unk181E8_sub;

// size: 0x1CEDC
typedef struct Dungeon
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
    u8 unkD;
    u8 unkE;
    /* 0xF */ bool8 noActionInProgress; // Whether the game is currently accepting input. Set to false while action animations play.
    u8 unk10;
    u8 unk11;
    s16 unk12;
    u8 fill14[0xB8 - 0x14];
    Entity *unkB8;
    Entity *unkBC;
    u8 fillC0[0x13C - 0xC0];
    u8 unk13C[2];
    u8 fill13E[0x16A - 0x13E];
    u8 unk16A;
    u8 unk16B;
    u8 unk16C;
    u8 unk16D;
    u8 fill16E[0x179 - 0x16E];
    /* 0x179 */ bool8 pokemonExposed; // True if a Pokémon on the floor has the Exposed status.
    u8 fill17A[0x17C - 0x17A];
    Dungeon_sub unk17C[0x100];
    /* 0x57C */ u8 fill57C[0x5C0 - 0x57c];
    /* 0x5C0 */ s32 unk5C0;
    /* 0x5C4 */ u8 fill5C4[0x644 - 0x5C4];
    /* 0x644 */ DungeonLocation dungeonLocation;
    u8 fill646[0x654 - 0x648];
    u8 unk654;
    u8 fill655[0x65B - 0x655];
    u8 unk65B;
    u8 unk65C;
    u8 unk65D;
    u8 fill65e[0x660 - 0x65e];
    /* 0x660 */ s16 fractionalTurn; // Handles turn order when Pokémon have different movement speeds.
    s16 unk662;
    s16 unk664;
    /* 0x666 */ s16 windTurns; // Turns remaining before getting swept out of the dungeon.
    /* 0x668 */ u16 unk668;
    u16 bossSongIndex;
    u8 unk66C;
    u8 unk66D;
    /* 0x66E */ u8 unk66E;
    u8 unk66F;
    u8 unk670;
    /* 0x671 */ bool8 monsterHouseTriggered;
    /* 0x672 */ bool8 monsterHouseTriggeredEvent;
    u8 unk673;
    u8 unk674;
    u8 unk675;
    /* 0x676 */ bool8 itemHoldersIdentified;
    u8 unk677;
    u8 unk678;
    u8 unk679;
    u8 unk67A;
    u8 unk67B[0x684 - 0x67B];
    s16 unk684;
    s16 unk686;
    s16 unk688;
    /* 0x68A */ u8 unk68A;
    u8 fill68B;
    s32 unk68C;
    s32 unk690;
    s32 unk694;
    u8 fill698;
    u8 unk699;
    u8 fill69A[0x69C - 0x69A];
    EntityInfo unk69C[4];
    EntityInfo unkEBC[1]; // Unsure about the size... See sub_8082A08()
    u8 fill10C4[0x363C - 0x10C4];
    /* 0x363C */ u8 expYieldRankings[NUM_MONSTERS];
    u8 fill37D9[0x37F0 - 0x37D9];
    /* 0x37F0 */ u32 unk37F0;
    /* 0x37F4 */ s32 unk37F4;
    /* 0x37F8 */ bool8 plusIsActive[2]; // Index 0: Enemy , Index 1: Team
    /* 0x37FA */ bool8 minusIsActive[2]; // Index 0: Enemy , Index 1: Team
    /* 0x37FC */ bool8 decoyActive;
    u8 fill37FD;
    /* 0x37FE */ bool8 deoxysDefeat; // Flag set for deoxys in Meteor Cave
    u8 fill37FF;
    s16 unk3800;
    u8 fill3802[0x3904 - 0x3802];
    /* 0x3904 */ s16 unk3904;
    u8 fill3906[0x3A08 - 0x3906];
    /* 0x3A08 */ u8 unk3A08;
    /* 0x3A09 */ u8 unk3A09;
    /* 0x3A0A */ u8 unk3A0A;
    /* 0x3A0B */ u8 unk3A0B;
    u8 unk3A0C;
    /* 0x3A0D */ u8 unk3A0D;
    /* 0x3A0E */ s16 tileset;
    /* 0x3A10 */ s16 unk3A10;
    /* 0x3A12 */ s16 unk3A12;
    /* 0x3A14 */ s16 bossBattleIndex;
    /* 0x3A16 */ s16 unk3A16;
    /* 0x3A18 */ Tile tiles[DUNGEON_MAX_SIZE_Y][DUNGEON_MAX_SIZE_X];
    Position unkE218;
    Position unkE21C;
    Position unkE220[8];
    u32 unkE240;
    u8 fillE244[0xE250 - 0xE244];
    u32 unkE250;
    u8 fillE254[0xE260 - 0xE254];
    u32 unkE260;
    /* 0xE264 */ Weather weather; // Uses the weather constants in weather.h.
    /* 0xE27C */ Tile unkE27C[8][8];
    /* 0xE87C */ u8 unkE87C[8][8];
    u32 fillE8BC;
    /* 0xE8C0 */ Tile *tilePointers[DUNGEON_MAX_SIZE_Y][DUNGEON_MAX_SIZE_X];
    u8 unk104C0;
    /* 0x104C4 */ RoomData roomData[MAX_ROOM_COUNT];
    /* 0x10844 */ s16 naturalJunctionListCounts[MAX_ROOM_COUNT];
    /* 0x10884 */ Position naturalJunctionList[MAX_ROOM_COUNT][MAX_ROOM_COUNT]; // Arrays of room exits for each room.
    u8 unk11884[0x1194];
    u8 fill12A18[0x12C24 - 0x12A18];
    u8 unk12C24[0x930];
    u8 fill13554[0x1356C - 0x13554];
    u8 unk1356C;
    u8 fill1356D[0x13570 - 0x1356D];
    /* 0x13570 */ u8 unk13570;
    u8 fill13571[0x13574 - 0x13571];
    /* 0x13574 */ Position trapPos;
    /* 0x13578 */ u8 trapID;
    /* 0x13579 */ u8 unk13579;
    u8 fill1357A[0x1357C - 0x1357A];
    /* 0x1357C */ Entity *teamPokemon[MAX_TEAM_MEMBERS];
    /* 0x1358C */ Entity *wildPokemon[DUNGEON_MAX_WILD_POKEMON];
    /* 0x135CC */ Entity *allPokemon[DUNGEON_MAX_POKEMON]; // Contains both team and wild Pokémon
    /* 0x1361C */ Entity *items[DUNGEON_MAX_ITEMS];
    /* 0x1371C */ Entity *traps[DUNGEON_MAX_TRAPS];
    /* 0x1381C */ Entity teamPokemonEntities[MAX_TEAM_MEMBERS];
    /* 0x139EC */ Entity wildPokemonEntities[DUNGEON_MAX_WILD_POKEMON];
    /* 0x1412C */ Entity itemEntities[DUNGEON_MAX_ITEMS];
    /* 0x15E2C */ Entity trapEntites[DUNGEON_MAX_TRAPS];
    /* 0x17B2C */ Entity *lightningRodPokemon;
    /* 0x17B30 */ Entity *snatchPokemon;
    /* 0x17B34 */ Entity *unk17B34;
    /* 0x17B38 */ u32 unk17B38;
    /* 0x17B3C */ u32 unk17B3C;
    /* 0x17B3C */ u32 unk17B40;
    /* 0x17B44 */ OpenedFile *sprites[MONSTER_MAX];
    /* 0x181E4 */ OpenedFile *paletFile;
    /* 0x181E8 */ unkDungeonGlobal_unk181E8_sub unk181e8;
    u8 fill18220[0x1C578 - 0x18220];
    u8 unk1C578;
    u8 fill1C579[0x1C57E - 0x1C579];
    u8 unk1C57E;
    u8 fill1C57F[0x1C58B - 0x1C57F];
    u8 unk1C58B;
    u8 fill1C58C[0x1CE98 - 0x1C58C];
    unkDungeonGlobal_unk1CE98_sub unk1CE98; // TODO: not sure how large this is
    u32 unk1CEC8;
    /* 0x1CECC */ DungeonMusicPlayer musPlayer;
} Dungeon;

extern Dungeon *gDungeon;

#endif // GUARD_STR_DUNGEON_H
