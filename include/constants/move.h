#ifndef GUARD_CONSTANTS_MOVE_H
#define GUARD_CONSTANTS_MOVE_H

enum MoveFlags
{
    MOVE_FLAG_EXISTS = 1 << 0,
    MOVE_FLAG_LINKED = 1 << 1, // This move is linked with the previous move in the Pokémon's moveset.
    MOVE_FLAG_ENABLED = 1 << 2, // Enabled for the AI to use.
    MOVE_FLAG_SET = 1 << 3, // This move can be triggered by pressing L+A instead of having to go to the move menu.
    MOVE_FLAG_LAST_USED = 1 << 4, // The most recent move used by the Pokémon.
    MOVE_FLAG_DISABLED = 1 << 5 // Disabled by an effect like Taunt.
};

struct MoveData
{
    u8 fill0[0x8 - 0x0];
    // Determines the range of moves.
    /* 0x8 */ u16 targetingFlags;
    /* 0xA */ u16 aiTargetingFlags; // The AI consider certain moves to have different range than they actually do.
    /* 0xC */ u8 maxPP;
    /* 0xD */ u8 defaultMoveWeight;
    u8 fillE[0x10 - 0xE];
    // Used by the AI to determine how often to use Spikes.
    // Values exist for all other moves, though they seem to be unused.
    /* 0x10 */ u8 moveUseChance;
    u8 fill11[0x17 - 0x11];
    /* 0x17 */ bool8 cannotHitFrozen; // Used by Status Checker to determine if a move can be used on a frozen target.
    /* 0x18 */ bool8 dealsDirectDamage;
};

struct PokemonMove
{
    u8 moveFlags;
    bool8 sealed;
    u16 moveID;
    u8 pp;
    u8 powerBoost; // How much the move is boosted by Ginsengs.
};

enum TargetingFlag
{
    TARGETING_FLAG_TARGET_OTHER = 0x0,
    TARGETING_FLAG_HEAL_TEAM = 0x1,
    TARGETING_FLAG_SWAP_POSITIONS = 0x2,
    TARGETING_FLAG_ATTACK_ALL = 0x5,
    TARGETING_FLAG_BOOST_TEAM = 0x6,
    TARGETING_FLAG_DONT_USE = 0xF,
    TARGETING_FLAG_TARGET_FRONTAL_CONE = 0x10,
    TARGETING_FLAG_TARGET_AROUND = 0x20,
    TARGETING_FLAG_TARGET_ROOM = 0x30,
    TARGETING_FLAG_TARGET_2_TILES_AHEAD = 0x40,
    TARGETING_FLAG_TARGET_LINE = 0x50,
    TARGETING_FLAG_TARGET_FLOOR = 0x60,
    TARGETING_FLAG_SELF_HEAL = 0x70,
    TARGETING_FLAG_CUT_CORNERS = 0x80,
    TARGETING_FLAG_SET_TRAP = 0x100,
    TARGETING_FLAG_HEAL_HP = 0x200,
    TARGETING_FLAG_HEAL_STATUS = 0x300,
    TARGETING_FLAG_DREAM_EATER = 0x400,
    TARGETING_FLAG_HEAL_ALL = 0x500,
    TARGETING_FLAG_EXPOSE = 0x600,
};

#endif
