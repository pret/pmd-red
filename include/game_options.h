#ifndef GUARD_GAME_OPTIONS_H
#define GUARD_GAME_OPTIONS_H

struct GameOptions
{
    // TODO: find where Controls/Touch Screen are in this structure in PMD Blue

    /* 0x0 */ u8 dungeonSpeed; // 0 - Slow, 1 - Fast
    /* 0x1 */ u8 FarOffPals; // 0 - Self, 1 - Lock
    /* 0x2 */ bool8 damageTurn; // 0 - No, 1 - Yes
    /* 0x3 */ bool8 gridEnable; // 0 - Off, 1 - on
    /* 0x4 */ u8 mapOption; // 0 - Off, 1 - Clear, 2 - Shade
    /* 0x5 */ u8 fill5[3];
    /* 0x8 */ u8 windowColor; // 0 - Blue, 1 - Red, 2 - Green
    /* 0x9 */ u8 unk9; // maybe Controls?
    /* 0xA */ u8 unkA; // maybe Touch Screen?
    /* 0xB */ u8 playerGender;
    /* 0xC */ u8 unkC;
};

enum DungeonSpeed 
{
    DUNGEON_SPEED_SLOW,
    DUNGEON_SPEED_FAST,
};

enum FarOffPals
{
    FAROFFPALS_SELF,
    FAROFFPALS_LOCK,
};


// GBA has 3 options while DS has 7
enum MapOption
{
    MAP_OPTION_OFF = 0,
    MAP_OPTION_CLEAR,
    MAP_OPTION_SHADE,
    NUM_GBA_MAP_OPTIONS,
};

enum DSMapOption
{
    TOP_TEAM_DATA_NO_BOTTOM = 0,
    TOP_TEAM_DATA_CLEAR_MAP_BOTTOM,
    TOP_TEAM_DATA_SHADED_MAP_BOTTOM,
    TOP_MESSAGE_LOG_NO_BOTTOM,
    TOP_MESSAGE_LOG_CLEAR_MAP_BOTTOM,
    TOP_MESSAGE_LOG_SHADED_MAP_BOTTOM,
    TOP_MAP_AND_TEAM_NO_BOTTOM,
    NUM_DS_MAP_OPTIONS,
};

enum windowColor
{
    WINDOW_COLOR_BLUE = 0,
    WINDOW_COLOR_RED,
    WINDOW_COLOR_GREEN,
    NUM_WINDOW_COLORS,
};

void LoadGameOptions(void);
struct GameOptions * GetGameOptions(void);
void InitializeGameOptions(bool8 initializeGender);
bool8 GameOptionsNotChange(struct GameOptions *r0);


#endif
