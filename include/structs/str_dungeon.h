#ifndef GUARD_STR_DUNGEON_H
#define GUARD_STR_DUNGEON_H

#include "constants/monster.h"
#include "structs/dungeon_entity.h"
#include "file_system.h"
#include "structs/map.h"
#include "structs/rgb.h"
#include "structs/str_position.h"
#include "structs/str_traps.h"
#include "structs/str_dungeon_location.h"
#include "sprite.h"

#define DUNGEON_MAX_SIZE_X 56
#define DUNGEON_MAX_SIZE_Y 32
#define DUNGEON_MAX_WILD_POKEMON 16
#define DUNGEON_MAX_WILD_POKEMON_BODY_SIZE 16
#define DUNGEON_MAX_POKEMON (MAX_TEAM_MEMBERS + DUNGEON_MAX_WILD_POKEMON)
#define DUNGEON_MAX_TRAPS 64
#define DUNGEON_MAX_ITEMS 64

// size: 0x18
typedef struct Weather // 0xE264
{
    /* 0x0 */ u8 weather; // Uses the weather constants in weather.h.
    /* 0x1 */ u8 unkE265; // Uses the weather constants in weather.h
    /* 0x2 */ u8 weatherDamageCounter; // Timer for applying sandstorm/hail damage periodically.
    /* 0x3 */ u8 unkE267[8];
    /* 0xB */ u8 naturalWeather[8]; // The weather at the start of the floor. If the weather changes, then expires, revert back to the starting weather.
    /* 0x13 */ u8 mudSportTurns;
    /* 0x14 */ u8 waterSportTurns;
    /* 0x15 */ bool8 nullifyWeather; // Air Lock and Cloud Nine toggle this to disable weather effects
} Weather;

// size: 0x30
typedef struct UnkDungeonGlobal_unk1CE98_sub
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
} UnkDungeonGlobal_unk1CE98_sub;

// size: 0x10
typedef struct DungeonMusicPlayer
{
    /* 0x0 */ u32 state;
    /* 0x4 */ u32 fadeOutSpeed;
    /* 0x8 */ u16 fadeInSpeed;

    // dungeon_serializer.c refers to these 3 as s16, but they are almost always handled as u16
    /* 0xA */ u16 songIndex;
    /* 0xC */ u16 pastSongIndex;
    /* 0xE */ u16 queuedSongIndex;
} DungeonMusicPlayer;

// Size unknown?
typedef struct UnkDungeonGlobal_unk181E8_sub
{
    /* 0x181E8 */ DungeonPos cameraPos;       // x0
    /* 0x181EC */ DungeonPos cameraPosMirror; // x4
    /* 0x181F0 */ DungeonPos cameraPixelPos;  // x8
    /* 0x181F4 */ DungeonPos cameraPixelPosMirror; // xC
    /* 0x181F8 */ Entity *cameraTarget; // x10
    u32 unk181FC; // x14
    u32 unk18200; // x18
    u32 unk18204; // x1C
    u8 priority; // x20
    /* 0x18209 */ u8 visibilityRange; // x21 Dungeon light level.
    /* 0x1820A */ bool8 blinded; // x22 Blacks out the screen when the player has the Blinker status.
    bool8 unk1820B; // x23
    bool8 unk1820C; // x24
    bool8 unk1820D; // x25
    bool8 unk1820E; // x26
    bool8 unk1820F; // x27
    /* 0x18210 */ bool8 hallucinating; // x28 Displays Substitute and flower sprites when the player has the Cross-Eyed status.
    bool8 unk18211; // x29
    u8 unk18212; // x2A
    bool8 unk18213; // x2B
    u8 unk18214; // x2C
    u8 unk18215; // x2D
    u8 unk18216; // x2E
    u8 unk18217; // x2F
    u8 unk18218; // x30
    u8 unk18219; // x31
    u8 unk1821A; // x32
    u8 rotateModeDirection; // x33
    u8 prevRotateModeDirection; // x34
    u8 fill1821D; // x35
    s16 unk36; // x36
    s16 unk38; // x38
    s16 unk3A; // x3A
    s16 unk3C; // x3C
    s16 unk3E; // x3E
    s16 unk40; // x40
    s16 unk42; // x42
} UnkDungeonGlobal_unk181E8_sub; // x44

#define ROOM_FLAG_ALLOW_SECONDARY_TERRAIN 0x1
#define ROOM_FLAG_ALLOW_IMPERFECTIONS 0x4

// Sizeof: 0x1C
// Defines many of the key properties for dungeon generation, such as the type of layout, base number of rooms, and floor connectivity.
typedef struct FloorProperties
{
    u8 layout;
    s8 roomDensity;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 floorConnectivity;
    u8 enemyDensity;
    u8 kecleonShopChance; // Percentage chance 0-100%
    u8 monsterHouseChance; // Percentage chance 0-100%
    u8 mazeRoomChance; // Percentage chance 0-100%
    u8 unkA;
    bool8 allowDeadEnds;
    u8 secondaryStructuresBudget; // Maximum number of secondary structures that can be generated
    u8 roomFlags; // See ROOM_FLAG_
    u8 unkE;
    u8 itemDensity;
    u8 trapDensity;
    u8 unk11;
    u8 unk12;
    u8 numExtraHallways;
    u8 buriedItemDensity; // Density of buried items (in walls)
    u8 unk15;
    u8 unk16;
    u8 unk17;
    u8 unk18;
    u8 itemlessMonsterHouseChance; // Chance that a monster house will be itemless
    u8 unk1A;
} FloorProperties;

typedef struct UnkDungeonGlobal_unk1C590
{
    s16 categoryValues[NUM_ITEM_CATEGORIES];
    s16 itemValues[NUMBER_OF_ITEM_IDS];
} UnkDungeonGlobal_unk1C590;

typedef struct UnkDungeonGlobal_unk1CD98
{
    u16 unk0; // species and level
    s16 unk2[2];
} UnkDungeonGlobal_unk1CD98;

struct unkStruct_Dungeon134_sub
{
    u8 unk134;
    u32 unk138;
    u8 unk13C[2];
    u8 unk13E[2];
    u16 unk140[7];
    u32 unk150;
    u32 unk154;
    u32 unk158;
    s24_8 unk15C;
    u8 unk160;
    u8 unk161;
    u8 unk162;
    u8 unk163;
    u8 unk164;
    u8 unk165;
    u8 unk166;
    u8 unk167;
    u8 unk168;
    u8 unk169;
    u8 unk16A;
    u8 unk16B;
    u8 unk16C;
    u8 unk16D;
    u8 fill16E[0x179 - 0x16E];
    bool8 pokemonExposed;
    u8 unk17A;
};

// size 0x10
struct unkStruct_Dungeon5C4_sub
{
    s32 unk0;
    s32 unk4;
    s32 unk8;
    Entity *unkC;
};

// size: 0x8
typedef struct unkStruct_Dungeon64C
{
    u8 unk0;
    u8 unk1;
    u32 unk4;
} unkStruct_Dungeon64C;

#define UNK_1BBD4_STR_COUNT 10

struct UnkStructDungeon1BDD4
{
    u8 unk0[UNK_1BBD4_STR_COUNT][64];
    u8 unk1C054[UNK_1BBD4_STR_COUNT]; // 0x280
    u8 unk1C05E; // 0x28A
    u8 unk1C05F; // 0x28B
    s16 unk1C060; // 0x28C
    s16 unk1C062; // 0x29E
    s16 unk1C064; // 0x290
    s16 unk1C066; // 0x292
    s16 unk1C068; // 0x294
    u32 unk1C06C; // 0x298
};

#define MESSAGE_LOG_STRINGS_COUNT 20
#define MESSAGE_LOG_BUFFER_SIZE   60

struct MessageLogString
{
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 str[MESSAGE_LOG_BUFFER_SIZE];
};

#define DEFAULT_MAX_POSITION 9999
struct MinMaxPosition
{
    s32 minX;
    s32 minY;
    s32 maxX;
    s32 maxY;
};

// size: 0x58
typedef struct unkDungeon644
{
    /* 0x0 */ DungeonLocation dungeonLocation;
    /* 0x4 */ DungeonLocation dungeonLocation2;
    /* 0x8 */ unkStruct_Dungeon64C unk8;
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 fill11[3];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 unk17;
    /* 0x18 */ u8 unk18;
    /* 0x19 */ u8 unk19;
    /* 0x1A */ u8 fill1A[2];
    /* 0x1C */ s16 fractionalTurn; // Handles turn order when Pokémon have different movement speeds.
    /* 0x1E */ s16 unk1E;
    /* 0x20 */ s16 unk20;
    /* 0x22 */ s16 windTurns; // Turns remaining before getting swept out of the dungeon.
    /* 0x24 */ u16 unk24;
    /* 0x26 */ u16 bossSongIndex;
    /* 0x28 */ u8 unk28;
    /* 0x29 */ u8 unk29;
    /* 0x2A */ u8 unk2A;
    /* 0x2B */ u8 unk2B;
    /* 0x2C */ u8 unk2C;
    /* 0x2D */ bool8 monsterHouseTriggered;
    /* 0x2E */ bool8 monsterHouseTriggeredEvent;
    /* 0x2F */ u8 unk2F;
    /* 0x30 */ u8 unk30;
    /* 0x31 */ u8 unk31;
    /* 0x32 */ bool8 itemHoldersIdentified;
    /* 0x33 */ u8 unk33;
    /* 0x34 */ u8 unk34;
    /* 0x35 */ u8 unk35;
    /* 0x36 */ u8 unk36;
    /* 0x37 */ s8 unk37;
    /* 0x38 */ u32 unk38;
    /* 0x3C */ u32 unk3C;
    /* 0x40 */ s16 unk40;
    /* 0x42 */ s16 unk42;
    /* 0x44 */ s16 unk44;
    /* 0x46 */ u8 unk46;
    /* 0x47 */ u8 unk47;
    /* 0x48 */ s32 unk48;
    /* 0x4C */ s32 unk4C;
    /* 0x50 */ s32 unk50;
    /* 0x54 */ u8 unk54;
    /* 0x55 */ u8 unk55;
} unkDungeon644;

// size: 0x4
typedef struct unkDungeonE260
{
    /* 0x0 */ u16 unk0;
    /* 0x2 */ u16 unk2;
} unkDungeonE260;

// Size: 0x14
typedef struct unkDungeon2F3C
{
    /* 0x0 */ s16 species;
    /* 0x2 */ s16 level;
    /* 0x4 */ u16 moves[MAX_MON_MOVES];
    /* 0xC */ u16 unkC;
    /* 0xE */ u8 unkE[2];
    /* 0x10 */ u8 unk10[2];
} unkDungeon2F3C;

// Size :0x8
typedef struct unkDungeon57CSub
{
    s16 unk0;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
} unkDungeon57CSub;

#define UNK_DUNGEON57C_ARRAY_COUNT 8

typedef struct unkDungeon57C
{
    unkDungeon57CSub unkArray[UNK_DUNGEON57C_ARRAY_COUNT];
    s32 unk40;
} unkDungeon57C;

#define COLOR_RAMP_COUNT 256
#define UNK12A18_ARR_COUNT 29
#define UNK12A18_ARR_COUNT_2 9

// size: 0x1CEDC
typedef struct Dungeon
{
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u8 unkC;
    u8 unkD;
    u8 unkE;
    /* 0xF */ bool8 noActionInProgress; // Whether the game is currently accepting input. Set to false while action animations play.
    u8 unk10;
    u8 unk11;
    s16 unk12;
    s16 unk14;
    s16 unk16;
    u32 unk18[(0xB8 - 0x18) / 4];
    Entity *unkB8;
    Entity *unkBC;
    u8 fillC0[0x134 - 0xC0];
    struct unkStruct_Dungeon134_sub unk134;
    /* 0x17C */ RGB colorRamp[COLOR_RAMP_COUNT];
    /* 0x57C */ unkDungeon57C unk57C;
    /* 0x5C0 */ s32 unk5C0;
    /* 0x5C4 */ struct unkStruct_Dungeon5C4_sub unk5C4[3];
    /* 0x5F4 */ u8 faintStringBuffer[80];
    unkDungeon644 unk644;
    EntityInfo unk69C[MAX_TEAM_MEMBERS];
    EntityInfo unkEBC[DUNGEON_MAX_WILD_POKEMON_BODY_SIZE];
    /* 0x2F3C */ unkDungeon2F3C unk2F3C[64];
    /* 0x343C */ UnkDungeonGlobal_unk1CD98 unk343C[32];
    u8 fill353C[0x363c-0x353c];
    /* 0x363C */ u8 expYieldRankings[MONSTER_MAX];
    /* 0x37E4 */ s32 unk37E4;
    u8 fill37E8[4];
    /* 0x37EC */ u8 unk37EC;
    /* 0x37F0 */ u32 unk37F0;
    /* 0x37F4 */ s32 unk37F4;
    /* 0x37F8 */ bool8 plusIsActive[2]; // Index 0: Enemy , Index 1: Team
    /* 0x37FA */ bool8 minusIsActive[2]; // Index 0: Enemy , Index 1: Team
    /* 0x37FC */ bool8 decoyIsActive;
    /* 0x37FD */ bool8 unk37FD;
    /* 0x37FE */ bool8 deoxysDefeat; // Flag set for deoxys in Meteor Cave
    /* 0x37FE */ bool8 unk37FF;
    // dungeon_serializer.c refers to this as a u16 but elsewhere it's handled as a s16
    /* 0x3800 */ s16 deoxysForm;
    Item unk3804[DUNGEON_MAX_ITEMS];
    /* 0x3904 */ s16 numItems;
    Trap unk3908[DUNGEON_MAX_TRAPS];
    /* 0x3A08 */ bool8 forceMonsterHouse; // Forces the current floor to have monster house
    /* 0x3A09 */ bool8 unk3A09;
    /* 0x3A0A */ bool8 unk3A0A;
    /* 0x3A0B */ bool8 unk3A0B;
    /* 0x3A0C */ u8 monsterHouseRoom; // room index of monster house
    /* 0x3A0D */ u8 unk3A0D;
    /* 0x3A0E */ s16 tileset;
    /* 0x3A10 */ s16 unk3A10;
    /* 0x3A12 */ s16 unk3A12;
    /* 0x3A14 */ s16 fixedRoomNumber;
    /* 0x3A16 */ s16 unk3A16;
    /* 0x3A18 */ Tile tiles[DUNGEON_MAX_SIZE_Y][DUNGEON_MAX_SIZE_X];
    /* 0xEA18 */ DungeonPos playerSpawn;
    /* 0xEA1C */ DungeonPos stairsSpawn; // stairs location
    DungeonPos unkE220[8];
    /* 0xEA24 */ struct MinMaxPosition kecleonShopPos;
    struct MinMaxPosition unkE250;
    unkDungeonE260 unkE260;
    /* 0xE264 */ Weather weather; // Uses the weather constants in weather.h.
    /* 0xE27C */ Tile unkE27C[8][8];
    /* 0xE87C */ u8 unkE87C[8][8];
    /* 0xE8BC */ u8 unkE8BC; // Seems to be some tile's room index;
    /* 0xE8C0 */ Tile *tilePointers[DUNGEON_MAX_SIZE_Y][DUNGEON_MAX_SIZE_X];
    u8 unk104C0;
    /* 0x104C4 */ RoomData roomData[MAX_ROOM_COUNT];
    /* 0x10844 */ s16 naturalJunctionListCounts[MAX_ROOM_COUNT];
    /* 0x10884 */ DungeonPos naturalJunctionList[MAX_ROOM_COUNT][MAX_ROOM_COUNT]; // Arrays of room exits for each room.
    u16 unk11884[250][9];
    u16 unk12A18[UNK12A18_ARR_COUNT][UNK12A18_ARR_COUNT_2];
    u8 ALIGNED(4) unk12C24[0x930];
    u16 unk13554[10];
    OpenedFile *unk13568;
    u8 unk1356C;
    u8 fill1356D[0x13570 - 0x1356D];
    /* 0x13570 */ u8 unk13570;
    u8 fill13571[0x13574 - 0x13571];
    /* 0x13574 */ DungeonPos trapPos;
    /* 0x13578 */ u8 trapID;
    /* 0x13579 */ u8 unk13579;
    u8 fill1357A[0x1357C - 0x1357A];
    /* 0x1357C */ Entity *teamPokemon[MAX_TEAM_MEMBERS];
    /* 0x1358C */ Entity *wildPokemon[DUNGEON_MAX_WILD_POKEMON];
    /* 0x135CC */ Entity *activePokemon[DUNGEON_MAX_POKEMON]; // Contains both team and wild Pokémon
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
    /* 0x181E8 */ UnkDungeonGlobal_unk181E8_sub unk181e8;
    u8 fill18220[0x1BDD4 - 0x1822C];
    struct UnkStructDungeon1BDD4 unk1BDD4;
    /* 0x1BE14 */ struct MessageLogString messageLogStrings[MESSAGE_LOG_STRINGS_COUNT];
    /* 0x1C570 */ DungeonLocation unk1C570;
    /* 0x1C574 */ FloorProperties unk1C574;
    /* 0x1C590 */ UnkDungeonGlobal_unk1C590 unk1C590[4];
    u16 unk1CD70[20];
    UnkDungeonGlobal_unk1CD98 unk1CD98[32];
    UnkDungeonGlobal_unk1CE98_sub unk1CE98; // TODO: not sure how large this is
    u8 unk1CEC8;
    /* 0x1CECC */ DungeonMusicPlayer musPlayer;
} Dungeon;

extern Dungeon *gDungeon;

#endif // GUARD_STR_DUNGEON_H
