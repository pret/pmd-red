#ifndef GUARD_STR_MOVES_H
#define GUARD_STR_MOVES_H

#include "constants/move.h"

// size: 0x24
typedef struct MoveDataEntry
{
    /* 0x0 */ u8 *name;
    /* 0x4 */ s16 basePower;
    /* 0x6 */ u8 type;
    // Determines the range of moves.
    /* 0x8 */ u16 targetingFlags[2]; // 0 for player and 1 for AI
    // The AI consider certain moves to have different range than they actually do.
    /* 0xC */ u8 basePP;
    /* 0xD */ u8 aiWeight;
    // There are multiple accuracy values. These are define with the AccuracyType enum.
    /* 0xE */ u8 accuracy[NUM_ACCURACY_TYPES];
    /* 0x11 */ u8 numberOfChainedHits; // Maximum number of times the move will hit. Used for multi-hit moves like Fury Attack.
    /* 0x12 */ u8 maxUpgradeLevel;
    /* 0x13 */ u8 critChance;
    /* 0x14 */ bool8 affectedByMagicCoat; // If true, this move is reflected by Magic Coat.
    /* 0x15 */ bool8 isSnatchable;
    /* 0x16 */ bool8 usesMouth; // If true, this move can't be used with the Muzzled status.
    /* 0x17 */ bool8 cannotHitFrozen; // Used by Status Checker to determine if a move can be used on a frozen target.
    /* 0x18 */ bool8 ignoresTaunted;
    /* 0x19 */ u8 rangeID;
    /* 0x1C */ u8 *description;
    /* 0x20 */ u8 *useText; // The text displayed when this move is used.
} MoveDataEntry;

// size: 0x8
typedef struct Move
{
    u8 moveFlags;
    u8 moveFlags2;
    u16 id;
    u8 PP;
    u8 ginseng; // How much the move is boosted by Ginsengs.
} Move;

#endif // GUARD_STR_MOVES_H