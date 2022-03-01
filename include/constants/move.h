#ifndef GUARD_CONSTANTS_MOVE_H
#define GUARD_CONSTANTS_MOVE_H

#define STRUGGLE_MOVE_INDEX 4

enum MoveFlag
{
    MOVE_FLAG_EXISTS = 1 << 0,
    MOVE_FLAG_LINKED = 1 << 1, // This move is linked with the previous move in the Pokémon's moveset.
    MOVE_FLAG_ENABLED = 1 << 2, // Enabled for the AI to use.
    MOVE_FLAG_SET = 1 << 3, // This move can be triggered by pressing L+A instead of having to go to the move menu.
    MOVE_FLAG_LAST_USED = 1 << 4, // The most recent move used by the Pokémon.
    MOVE_FLAG_DISABLED = 1 << 5 // Disabled by an effect like Taunt.
};

enum MoveFlag2
{
    MOVE_FLAG_SEALED = 1 << 0,
    MOVE_FLAG_TEMPORARY = 1 << 3, // Used for moves copied by Mimic.
    MOVE_FLAG_REPLACE = 1 << 5 // Used for moves copied by Sketch.
};

enum AccuracyType
{
    // Accuracy used for all moves.
    ACCURACY_TYPE_GLOBAL,
    // Multiplied with the global accuracy for offensive moves (i.e., not status moves).
    ACCURACY_TYPE_OFFENSIVE,
    // Used by the AI to determine how often to use Spikes.
    // Values exist for all other moves, though they seem to be unused.
    ACCURACY_TYPE_USE_CHANCE,
    NUM_ACCURACY_TYPES
};

struct MoveData
{
    u8 *namePointer;
    /* 0x4 */ s16 power;
    u8 type;
    u8 fill7;
    // Determines the range of moves.
    /* 0x8 */ u16 targetingFlags[2]; // 0 for player and 1 for AI
    // The AI consider certain moves to have different range than they actually do.
    /* 0xC */ u8 maxPP;
    /* 0xD */ u8 weight;
    // There are multiple accuracy values. These are define with the AccuracyType enum.
    /* 0xE */ u8 accuracy[NUM_ACCURACY_TYPES];
    /* 0x11 */ u8 hitCount; // Maximum number of times the move will hit. Used for multi-hit moves like Fury Attack.
    u8 unk12;
    /* 0x13 */ u8 criticalHitChance;
    /* 0x14 */ bool8 affectedByMagicCoat; // If true, this move is reflected by Magic Coat.
    /* 0x15 */ bool8 targetsUser;
    /* 0x16 */ bool8 affectedByMuzzled; // If true, this move can't be used with the Muzzled status.
    /* 0x17 */ bool8 cannotHitFrozen; // Used by Status Checker to determine if a move can be used on a frozen target.
    /* 0x18 */ bool8 dealsDirectDamage;
    u8 rangeType;
    u8 *descriptionPointer;
    u8 *useText; // The text displayed when this move is used.
};

struct PokemonMove
{
    u8 moveFlags;
    u8 moveFlags2;
    u16 moveID;
    u8 PP;
    u8 powerBoost; // How much the move is boosted by Ginsengs.
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

#endif
