#ifndef GUARD_CONSTANTS_MOVE_H
#define GUARD_CONSTANTS_MOVE_H

#define STRUGGLE_MOVE_INDEX 4

enum MoveFlag
{
    MOVE_FLAG_EXISTS = 1 << 0,
    MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN = 1 << 1, // This move is linked with the previous move in the Pokémon's moveset.
    MOVE_FLAG_ENABLED_FOR_AI = 1 << 2, // Enabled for the AI to use.
    MOVE_FLAG_SET = 1 << 3, // This move can be triggered by pressing L+A instead of having to go to the move menu.
    MOVE_FLAG_LAST_USED = 1 << 4, // The most recent move used by the Pokémon.
    MOVE_FLAG_DISABLED = 1 << 5, // Disabled by an effect like Taunt.
    MOVE_FLAG_INTERNAL_MARKER = 1 << 7     // Possibly some kind of flag used internally to mark a move and find it again
};

enum MoveFlag2
{
    MOVE_FLAG_SEALED = 1 << 0,
    MOVE_FLAG2_UNK4 = 1 << 2,
    MOVE_FLAG_TEMPORARY = 1 << 3, // Used for moves copied by Mimic.
    MOVE_FLAG_REPLACE = 1 << 5 // Used for moves copied by Sketch.
};

enum AccuracyType
{
    // Accuracy used for all moves.
    ACCURACY_1,
    // Multiplied with the global accuracy for offensive moves (i.e., not status moves).
    ACCURACY_2,
    // Used by the AI to determine how often to use Spikes.
    // Values exist for all other moves, though they seem to be unused.
    ACCURACY_AI_CONDITION_RANDOM_CHANCE,
    NUM_ACCURACY_TYPES
};

enum TargetingFlag
{
    TARGETING_FLAG_TARGET_OTHER = 0x0,
    TARGETING_FLAG_HEAL_TEAM = 0x1,
    TARGETING_FLAG_LONG_RANGE = 0x2,
    TARGETING_FLAG_BOOST_SELF = 0x3,
    TARGETING_FLAG_MULTI_TURN = 0x4,
    TARGETING_FLAG_ATTACK_ALL = 0x5,
    TARGETING_FLAG_BOOST_TEAM = 0x6,
    TARGETING_FLAG_ITEM = 0xF,
    TARGETING_FLAG_TARGET_FRONTAL_CONE = 0x10,
    TARGETING_FLAG_TARGET_AROUND = 0x20,
    TARGETING_FLAG_TARGET_ROOM = 0x30,
    TARGETING_FLAG_TARGET_2_TILES_AHEAD = 0x40,
    TARGETING_FLAG_TARGET_LINE = 0x50,
    TARGETING_FLAG_TARGET_FLOOR = 0x60,
    TARGETING_FLAG_TARGET_SELF = 0x70,
    TARGETING_FLAG_CUT_CORNERS = 0x80,
    TARGETING_FLAG_SET_TRAP = 0x100,
    TARGETING_FLAG_HEAL_HP = 0x200,
    TARGETING_FLAG_HEAL_STATUS = 0x300,
    TARGETING_FLAG_DREAM_EATER = 0x400,
    TARGETING_FLAG_HEAL_ALL = 0x500,
    TARGETING_FLAG_EXPOSE = 0x600,
};

#endif // GUARD_CONSTANTS_MOVE_H
