#ifndef GUARD_DUNGEON_ENTITY_H
#define GUARD_DUNGEON_ENTITY_H

#include "constants/global.h"
#include "constants/move.h"
#include "item.h"
#include "position.h"

#define MAX_STAT_STAGE 20
#define STAT_MULTIPLIER_THRESHOLD 63
#define DEFAULT_STAT_STAGE 10
#define DEFAULT_STAT_MULTIPLIER 256
#define MAX_SPEED_STAGE 4
#define MAX_STOCKPILE_STAGE 3
#define NUM_SPEED_COUNTERS 5
#define NUM_PREV_POS 4

#define STAT_STAGE_ATK 0
#define STAT_STAGE_SP_ATK 1
#define STAT_STAGE_DEF 0
#define STAT_STAGE_SP_DEF 1
#define STAT_STAGE_ACCURACY 0
#define STAT_STAGE_EVASION 1

struct ActionContainer
{
    /* 0x0 */ u16 action;
    /* 0x2 */ u8 direction;
    u8 fill3;
    // Additional parameter alongside actionIndex. Used for things like indicating which move a Pokémon should use from its moveset.
    /* 0x4 */ u8 actionUseIndex;
    // Position of the Pokémon the last time it threw an item.
    /* 0x8 */ struct Position lastItemThrowPosition;
    u8 unkC;
    u8 fillD[3];
    u8 fill10[4];
    // Position of the target that the Pokémon wants throw an item at.
    /* 0x14 */ struct Position itemTargetPosition;
};

struct EntityInfo
{
    // This has different purposes for Pokémon, items, and traps.
    // Pokemon: MovementFlag
    // Items: ItemFlag
    // Traps: TrapType
    /* 0x0 */ u16 flags;
    /* 0x2 */ s16 id; // Pokémon species or item ID.
    // Everything from here on only applies to Pokémon.
    /* 0x4 */ s16 apparentID; // Shows a different Pokémon when using Transform.
    /* 0x6 */ bool8 isNotTeamMember;
    /* 0x7 */ bool8 isTeamLeader;
    /* 0x8 */ u8 shopkeeper;
    /* 0x9 */ u8 level;
    /* 0xA */ u8 teamIndex; // Leader is 0, partner is 1, etc.
    /* 0xC */ s16 IQ;
    /* 0xE */ s16 HP;
    /* 0x10 */ s16 maxHPStat;
    // Bosses have higher HP than normal for their level. This is the max HP they would normally have given their level.
    /* 0x12 */ s16 originalHP;
    /* 0x14 */ u8 atk;
    /* 0x15 */ u8 spAtk;
    /* 0x16 */ u8 def;
    /* 0x17 */ u8 spDef;
    /* 0x18 */ u32 exp;
    // Temporary stat boosts/drops from effects like Growl or Swords Dance.
    // These start at 10 and are in the range [1, 19].
    // Index 0 is Attack. Index 1 is Special Attack.
    /* 0x1C */ s16 offensiveStages[2];
    // Index 0 is Defense. Index 1 is Special Defense.
    /* 0x20 */ s16 defensiveStages[2];
    // Index 0 is accuracy. Index 1 is evasion.
    /* 0x24 */ s16 hitChancesStages[2];
    // // When a Fire-type move is used on a Pokémon with Flash Fire, this value increases the power of the Pokémon's Fire-type moves.
    /* 0x28 */ s16 flashFireBoost;
    // These start at 0x1000, and are halved by certain moves like Screech to lower the corresponding stat.
    // Index 0 is Attack. Index 1 is Special Attack.
    /* 0x2C */ s32 offensiveMultipliers[2];
    // Index 0 is Defense. Index 1 is Special Defense.
    /* 0x34 */ s32 defensiveMultipliers[2];
    /* 0x3C */ s16 hiddenPowerBasePower;
    /* 0x3E */ u8 hiddenPowerType;
    u8 fill3F;
    /* 0x40 */ u8 joinedAt; // Uses the dungeon index in dungeon.h.
    /* 0x44 */ struct ActionContainer action;
    /* 0x5C */ u8 types[2];
    /* 0x5E */ u8 abilities[2];
    /* 0x60 */ struct Item heldItem;
    u8 fill64[0x68 - 0x64];
    /* 0x68 */ struct Position prevPos[NUM_PREV_POS];
    /* 0x78 */ u8 aiObjective;
    /* 0x79 */ bool8 aiNotNextToTarget;
    /* 0x7A */ bool8 aiTargetingEnemy;
    /* 0x7B */ bool8 aiTurningAround;
    /* 0x7C */ u16 aiTargetSpawnGenID;
    /* 0x80 */ struct Entity *aiTarget;
    u8 fill84[0x88 - 0x84];
    /* 0x88 */ struct Position aiTargetPos;
    // Bitwise flags corresponding to selected IQ skills.
    /* 0x8C */ u8 IQSkillMenuFlags[4]; // IQ skills selected in the IQ skills menu.
    /* 0x90 */ u8 IQSkillFlags[4];
    /* 0x94 */ u8 tactic;
    u8 fill95[0x98 - 0x95];
    /* 0x98 */ u32 unk98;
    /* 0x9C */ u32 unk9C;
    /* 0xA0 */ u32 unkA0;
    /* 0xA4 */ u8 clientType;
    u8 fillA5[0xA8 - 0xA5];
    // Statuses are split into groups based on which ones can't overlap.
    // See status.h for which statuses are in each group.
    /* 0xA8 */ u8 sleep;
    /* 0xA9 */ u8 sleepTurns;
    u8 fillAA[0xAC - 0xAA];
    /* 0xAC */ u8 nonVolatileStatus;
    /* 0xAD */ u8 nonVolatileStatusTurns;
    /* 0xAE */ u8 nonVolatileStatusDamageCountdown;
    u8 fillAF;
    /* 0xB0 */ u8 immobilizeStatus;
    u8 fillB1[0xB4 - 0xB1];
    /* 0xB4 */ s32 unkB4;
    /* 0xB8 */ u8 immobilizeStatusTurns;
    /* 0xB9 */ u8 immobilizeStatusDamageCountdown;
    u8 fillBA[0xBC - 0xBA];
    /* 0xBC */ u8 volatileStatus;
    /* 0xBD */ u8 volatileStatusTurns;
    u8 fillBE[0xC0 - 0xBE];
    /* 0xC0 */ u8 chargingStatus;
    /* 0xC1 */ u8 chargingStatusTurns;
    /* 0xC2 */ u8 chargingStatusMoveIndex; // The position of the move in the Pokémon's moveset that triggered the status.
    u8 fillC3;
    /* 0xC4 */ u8 protectionStatus;
    /* 0xC5 */ u8 protectionStatusTurns;
    u8 fillC6[0xC8 - 0xC6];
    /* 0xC8 */ u8 waitingStatus;
    /* 0xC9 */ bool8 enemyDecoy; // True if the Pokémon is a decoy and a wild Pokémon (i.e., not an allied Pokémon).
    u8 fillCA;
    /* 0xCB */ u8 waitingStatusTurns;
    /* 0xCC */ u8 curseDamageCountdown;
    u8 fillCD[0xD0 - 0xCD];
    /* 0xD0 */ u8 linkedStatus;
    u8 fillD1[0xD4 - 0xD1];
    /* 0xD4 */ u32 unkD4;
    /* 0xD8 */ u8 unkD8;
    /* 0xD9 */ u8 linkedStatusTurns;
    /* 0xDA */ u8 linkedStatusDamageCountdown;
    u8 fillDB;
    /* 0xDC */ u8 moveStatus;
    /* 0xDD */ u8 moveStatusTurns;
    u8 fillDE[0xE0 - 0xDE];
    /* 0xE0 */ u8 itemStatus;
    u8 fillE1[0xE4 - 0xE1];
    /* 0xE4 */ u8 transformStatus;
    /* 0xE5 */ u8 transformStatusTurns;
    u8 fillE6[0xE8 - 0xE6];
    /* 0xE8 */ u8 eyesightStatus;
    /* 0xE9 */ u8 eyesightStatusTurns;
    /* 0xEA */ u8 unkEA;
    u8 fillEB;
    /* 0xEC */ bool8 muzzled;
    /* 0xED */ u8 muzzledTurns;
    u8 fillEE[0xF0 - 0xEE];
    /* 0xF0 */ bool8 powerEars;
    /* 0xF1 */ bool8 scanning;
    /* 0xF2 */ bool8 stairSpotter;
    u8 fillF3;
    /* 0xF4 */ bool8 grudge;
    /* 0xF5 */ bool8 exposed;
    /* 0xF6 */ bool8 isColorChanged;
    /* 0xF7 */ bool8 bossFlag;
    /* 0xF8 */ bool8 speedStageChanged; // Toggled when pokemon is movement speed is sped up
    /* 0xF9 */ u8 unkF9;
    /* 0xFA */ u8 terrifiedTurns; // Doubles as a bool for whether the Pokémon is terrified.
    u8 unkFB;
    // Set to true if the player makes a teammate use their held item.
    // This is done by going to the teammate's held item in the toolbox and selecting "Use".
    /* 0xFC */ bool8 useHeldItem;
    /* 0xFD */ u8 perishSongTurns; // When this reaches 0, the Pokémon faints from Perish Song. Doubles as a bool for whether the Pokémon is afflicted by Perish Song.
    u8 unkFE;
    u8 unkFF;
    /* 0x100 */ u8 targetingDecoy; // If the Pokémon is targeting a decoy, this indicates whether the decoy target is a team or wild Pokémon.
    /* 0x104 */ s32 speedStage;
    // The turn counter for movement speed up/down is split into five timers each. Multiple timers are used if the Pokémon is affected by multiple
    // speed-up/slow effects at once, like using Agility twice.
    /* 0x108 */ u8 speedUpCounters[NUM_SPEED_COUNTERS];
    /* 0x10D */ u8 speedDownCounters[NUM_SPEED_COUNTERS];
    /* 0x112 */ u8 stockpileStage;
    u8 fill113;
    // When non-zero, an AI Pokémon will move in a random direction every turn.
    // Unclear where this is set in-game; it is not set by statuses (e.g., confusion) or mission clients.
    /* 0x114 */ u32 moveRandomly;
    /* 0x118 */ struct Move moves[MAX_MON_MOVES];
    /* 0x138 */ u8 struggleMoveFlags;
    /* 0x13C */ u32 belly;
    /* 0x140 */ u32 maxBelly;
    /* 0x144 */ bool8 aiNextToTarget; // True if an AI Pokémon is following another Pokémon and is already adjacent to them.
    /* 0x145 */ bool8 recalculateFollow; // Used by the AI to defer a movement decision until after all other Pokémon have moved.
    u8 fill146;
    /* 0x147 */ bool8 waiting; // True if an AI Pokémon decided to do nothing this turn.
    /* 0x148 */ bool8 attacking;
    /* 0x149 */ u8 unk149;
    /* 0x14A */ u8 unk14A;
    u8 fill14B[0x14E - 0x14B];
    /* 0x14E */ u16 visualFlags;
    /* 0x150 */ u16 previousVisualFlags;
    /* 0x152 */ u8 unk152;
    u8 unk153;
    u8 unk154;
    u8 unk155;
    u8 fill158[0x158 - 0x156];
    u8 unk158;
    u8 unk159;
    u8 unk15A;
    u8 unk15B;
    u8 unk15C;
    u8 unk15D;
    u8 unk15E;
    u8 unk15F;
    u8 fill160[0x164 - 0x160];
    /* 0x164 */ u8 unk164;
    /* 0x165 */ u8 unk165;
    u8 fill166[0x169 - 0x166];
    u8 turnsSinceWarpScarfActivation;
    /* 0x16C */ struct Position targetPos;
    /* 0x170 */ struct Position pixelPos;
    u32 unk174;
    u8 fill178[0x17A - 0x178];
    /* 0x17A */ u16 mimicMoveIDs[MAX_MON_MOVES]; // All moves that Mimic has copied (not sure on size...)
    // Previous value of targetPosition for movement, 1 and 2 moves ago.
    /* 0x184 */ struct Position previousTargetMovePosition1;
    /* 0x188 */ struct Position32 previousTargetMovePosition2;
    /* 0x190 */ u8 lastMoveDirection; // The last direction that the Pokémon moved in.
    // Number of tiles that the Pokémon moved last, multiplied by 0x100.
    /* 0x194 */ struct Position32 lastMoveIncrement;
    /* 0x19C */ u8 walkAnimFramesLeft; // Set when the Pokémon starts moving, and counts down until the Pokémon's walk animation stops.
    u8 fill19D[0x1F4 - 0x19D];
    /* 0x1F4 */ u8 numMoveTiles; // Number of tiles to move in a turn. Can be greater than 1 if the user's movement speed is boosted.
    u8 fill1F5;
    /* 0x1F6 */ bool8 notMoving;
    u8 fill1F7[0x1FA - 0x1F7];
    /* 0x1FA */ s16 mobileTurnTimer; // When a Pokémon can pass through walls in a hallway, this counts up to 200 before the Pokémon turns in a random direction.
    /* 0x1FC */ u16 expGainedInTurn; // Used to accumulate experience when multiple enemies are defeated in one turn.
    /* 0x200 */ u32 statusIcons;
    u8 unk204;
};

// Used for Pokémon, items, and traps.
struct Entity
{
    /* 0x0 */ u32 type;
    /* 0x4 */ struct Position pos;
    /* 0x8 */ struct Position prevPos;
    // The center of the entity acccording to pixel-space coordinates, using the same origin as posWorld.
    // X = (posWorld * 24 + 16) * 256, while Y = (posWorld * 24 + 12) * 256.
    /* 0xC */ struct Position32 pixelPos;
    /* 0x14 */ struct Position32 prevPixelPos;
    s32 unk1C;
    /* 0x20 */ bool8 isVisible; // Turned off when a Pokémon faints.
    u8 fill21[0x25 - 0x21];
    /* 0x25 */ u8 room;
    // The global spawn index counter starts at 10. Each Pokémon that spawns increments the counter and
    // gets assigned the current counter value as its spawn index.
    /* 0x26 */ u16 spawnGenID;
    u8 fill28[0x2A - 0x28];
    // 0x2A and 0x2E seem to be related to the sprite animation, though not sure how they're related.
    /* 0x2A */ u16 spriteAnimationCounter;
    // Each animation has a few different sprites that it transitions between.
    // This is the index of the currently displayed sprite within the animation.
    // Differs from 0x34 as this index is only between the sprites used by the animation,
    // while 0x34 is a shared index among all sprites.
    /* 0x2C */ u16 spriteAnimationIndex;
    /* 0x2E */ u16 spriteAnimationCounter2;
    // The position of the sprite within the tile. The animation may change the position slightly.
    /* 0x30 */ struct Position spritePos;
    // Offset of the sprite from its position at the start of the animation. Changes alongside spritePos.
    /* 0x34 */ struct Position spritePosOffset;
    u8 fill38[0x48 - 0x38];
    // The sprite index to display, among the Pokémon's possible sprites.
    /* 0x48 */ u16 spriteIndexForEntity;
    /* 0x4A */ u16 spriteIndexForEntity2;
    u8 unk4C[0x50 - 0x4C];
    // Some kind of base sprite index depending on which way the Pokémon is facing.
    // and which animation is playing (e.g., idle, moving).
    // Compared to 0x48, 0x50 and 0x54 are much larger and could be global indexes among all sprites in the game.
    /* 0x50 */ u16 spriteBaseForDirection;
    u8 fill52[0x54 - 0x52];
    /* 0x54 */ u16 spriteGlobalIndex;
    u8 fill56[0x64 - 0x56];
    u32 unk64;
    u8 fill68[2];
    /* 0x6A */ u8 unk6A;
    /* 0x6A */ u8 unk6B;
    /* 0x6C */ u8 direction;
    /* 0x6D */ u8 direction2; // Duplicate of 0x6C?
    /* 0x70 */ struct EntityInfo *info;
};

enum EntityType
{
    ENTITY_NOTHING,
    ENTITY_MONSTER,
    ENTITY_TRAP,
    ENTITY_ITEM,
    ENTITY_UNK_4,
    ENTITY_UNK_5,
};

enum MovementFlag
{
    MOVEMENT_FLAG_SWAPPING_PLACES = 1 << 5,
    MOVEMENT_FLAG_WALKING = 1 << 9,
    MOVEMENT_FLAG_UNK_14 = 1 << 14,
    MOVEMENT_FLAG_SWAPPING_PLACES_PETRIFIED_ALLY = 1 << 15 // Set if the Pokémon is petrified and the leader cures them by swapping places.
};

enum ShopkeeperMode
{
    SHOPKEEPER_MODE_NORMAL,
    SHOPKEEPER_MODE_SHOPKEEPER,
    // These two modes trigger if an explosion damages the shopkeeper. The shopkeeper attacks the side that damaged it.
    SHOPKEEPER_MODE_ATTACK_ENEMIES,
    SHOPKEEPER_MODE_ATTACK_TEAM
};

enum AIObjective
{
    AI_CHASE_TARGET = 1,
    AI_CHASE_REMEMBERED_TARGET = 2,
    AI_ROAM = 3,
    AI_LEAVE_ROOM = 4,
    AI_RUN_AWAY = 5,
    AI_STAND_STILL = 6,
    AI_TAKE_ITEM = 7
};

enum ClientType
{
    CLIENT_TYPE_NONE = 0,
    CLIENT_TYPE_CLIENT = 1, // Used for mission clients that need rescuing.
    CLIENT_TYPE_DONT_MOVE = 4 // Used for Diglett in the Skarmory boss fight.
};

enum VisualFlag
{
    // Set if Run Away's visual effect (green smoke cloud) has been triggered on this floor.
    // Prevents the effect from showing again if the Pokémon stops running away and then starts running away again.
    VISUAL_FLAG_RUN_AWAY = 2
};

#endif
