#ifndef GUARD_COMMON_STRINGS_HINTS_H
#define GUARD_COMMON_STRINGS_HINTS_H

// size: 0x8
typedef struct Hints
{
    const u8 *heading;
    const u8 *body;
} Hints;

enum HintKind
{
    HINT_TOWN_CONTROLS_1,
    HINT_TOWN_CONTROLS_2,
    HINT_SAVING,
    HINT_ADVENTURES_WITH_FRIENDS,
    HINT_BUILDING_A_TEAM,
    HINT_MAX
};

#endif // GUARD_COMMON_STRINGS_HINTS_H