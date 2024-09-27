#ifndef GUARD_DUNGEON_ENTITY_H
#define GUARD_DUNGEON_ENTITY_H

#include "constants/global.h"
#include "structs/str_position.h"
#include "sprite.h"
#include "structs/str_items.h"
#include "structs/str_moves.h"
#include "structs/axdata.h"

#include "number_util.h"

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

typedef struct unkStruct_8044CC8
{
    u8 actionUseIndex;
    Position lastItemThrowPosition;
} unkStruct_8044CC8;

// size: 0x18
typedef struct ActionContainer
{
    /* 0x0 */ u16 action;
    /* 0x2 */ u8 direction;
    u8 fill3;
    // Additional parameter alongside actionIndex. Used for things like indicating which move a Pokémon should use from its moveset.
    /* 0x4 */ unkStruct_8044CC8 unk4[2];
    // Position of the target that the Pokémon wants throw an item at.
    /* 0x14 */ Position itemTargetPosition;
} ActionContainer;

typedef struct HiddenPower
{
    /* 0x0 */ s16 hiddenPowerBasePower;
    /* 0x2 */ u8 hiddenPowerType;
} HiddenPower;

typedef struct JoinedAt
{
    /* 0x0 */ u8 joinedAt;
    /* 0x1 */ u8 unk1;
} JoinedAt;

typedef struct AITarget
{
    /* 0x0 */ u8 aiObjective;
    /* 0x1 */ bool8 aiNotNextToTarget;
    /* 0x2 */ bool8 aiTargetingEnemy;
    /* 0x3 */ bool8 aiTurningAround;
    /* 0x4 */ u16 aiTargetSpawnGenID;
    /* 0x8 */ struct Entity *aiTarget;
    /* 0xC */ u32 unkC;
    /* 0x10 */ Position aiTargetPos;

} AITarget;

typedef struct Sleep
{
    /* 0x0 */ u8 sleep;
    /* 0x1 */ u8 sleepTurns;
} Sleep;

typedef struct NonVolatile
{
    /* 0x0 */ u8 nonVolatileStatus;
    /* 0x1 */ u8 nonVolatileStatusTurns;
    /* 0x2 */ u8 nonVolatileStatusDamageCountdown;
    /* 0x3 */ u8 unk4;
} NonVolatile;

typedef struct Immobilize
{
    /* 0x0 */ u8 immobilizeStatus;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ u8 immobilizeStatusTurns;
    /* 0x9 */ u8 immobilizeStatusDamageCountdown;
} Immobilize;

typedef struct Volatile
{
    /* 0x0 */ u8 volatileStatus;
    /* 0x1 */ u8 volatileStatusTurns;
} Volatile;

typedef struct Charging
{
    /* 0x0 */ u8 chargingStatus;
    /* 0x1 */ u8 chargingStatusTurns;
    /* 0x2 */ u8 chargingStatusMoveIndex; // The position of the move in the Pokémon's moveset that triggered the status.
} Charging;

typedef struct Protection
{
    /* 0x0 */ u8 protectionStatus;
    /* 0x1 */ u8 protectionStatusTurns;
} Protection;

typedef struct Waiting
{
    /* 0xC8 */ u8 waitingStatus;
    /* 0xC9 */ bool8 enemyDecoy; // True if the Pokémon is a decoy and a wild Pokémon (i.e., not an allied Pokémon).
    u8 unkCA;
    /* 0xCB */ u8 waitingStatusTurns;
    /* 0xCC */ u8 curseDamageCountdown;
} Waiting;

typedef struct Linked
{
    /* 0xD0 */ u8 linkedStatus;
    /* 0xD4 */ u32 unkD4;
    /* 0xD8 */ u8 unkD8;
    /* 0xD9 */ u8 linkedStatusTurns;
    /* 0xDA */ u8 linkedStatusDamageCountdown;
} Linked;


typedef struct MoveStatus
{
    /* 0xDC */ u8 moveStatus;
    /* 0xDD */ u8 moveStatusTurns;
} MoveStatus;

typedef struct ItemStatus
{
    /* 0xE0 */ u8 itemStatus;
} ItemStatus;

typedef struct TransformStatus
{
    /* 0xE4 */ u8 transformStatus;
    /* 0xE5 */ u8 transformStatusTurns;
} TransformStatus;

typedef struct EyesightStatus
{
    /* 0xE8 */ u8 eyesightStatus;
    /* 0xE9 */ u8 eyesightStatusTurns;
} EyesightStatus;

typedef struct Muzzled
{
    /* 0xEC */ bool8 muzzled;
    /* 0xED */ u8 muzzledTurns;
} Muzzled;

typedef struct Unk_Entity_x184
{
    /* 0x184 - 0x0 */ Position previousTargetMovePosition1;
    /* 0x188 - 0x4 */ Position32 previousTargetMovePosition2;
    /* 0x190 - 0xC */ s32 lastMoveDirection; // The last direction that the Pokémon moved in.
    // Number of tiles that the Pokémon moved last, multiplied by 0x100.
    /* 0x194 - 0x10*/ Position32 lastMoveIncrement;
    /* 0x19C - 0x18 */ s16 walkAnimFramesLeft; // Set when the Pokémon starts moving, and counts down until the Pokémon's walk animation stops.
    /* 0x19e - 0x1a */ u8 unk1A;
} Unk_Entity_x184 ;

// size: 0x208
typedef struct EntityInfo
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
    /* 0x24 */ s16 hitChanceStages[2];
    // // When a Fire-type move is used on a Pokémon with Flash Fire, this value increases the power of the Pokémon's Fire-type moves.
    /* 0x28 */ s16 flashFireBoost;
    // These start at 0x1000, and are halved by certain moves like Screech to lower the corresponding stat.
    // Index 0 is Attack. Index 1 is Special Attack.
    /* 0x2C */ s32 offensiveMultipliers[2];
    // Index 0 is Defense. Index 1 is Special Defense.
    /* 0x34 */ s32 defensiveMultipliers[2];
    /* 0x3C */ HiddenPower hiddenPower;
    /* 0x40 */ JoinedAt joinedAt; // Uses the dungeon index in dungeon.h.
    /* 0x44 */ ActionContainer action;
    /* 0x5C */ u8 types[2];
    /* 0x5E */ u8 abilities[2];
    /* 0x60 */ Item heldItem;
    /* 0x64 */ u8 unk64;
    /* 0x68 */ Position prevPos[NUM_PREV_POS];
    /* 0x78 */ AITarget aiTarget;
    // Bitwise flags corresponding to selected IQ skills.
    /* 0x8C */ u8 IQSkillMenuFlags[4]; // IQ skills selected in the IQ skills menu.
    /* 0x90 */ u8 IQSkillFlags[4];
    /* 0x94 */ u8 tactic;
    u8 fill95[0x98 - 0x95];
    /* 0x98 */ u32 unk98;
    /* 0x9C */ u32 unk9C;
    /* 0xA0 */ s32 unkA0;
    /* 0xA4 */ u8 clientType;
    u8 fillA5[0xA8 - 0xA5];
    // Statuses are split into groups based on which ones can't overlap.
    // See status.h for which statuses are in each group.
    /* 0xA8 */ Sleep sleep;
    /* 0xAC */ NonVolatile nonVolatile;
    /* 0xB0 */ Immobilize immobilize;
    /* 0xBC */ Volatile volatileStatus;
    /* 0xC0 */ Charging charging;
    /* 0xC4 */ Protection protection;
    /* 0xC8 */ Waiting waitingStruct;
    /* 0xD0 */ Linked linked;
    /* 0xDC */ MoveStatus moveStatus;
    /* 0xE0 */ ItemStatus itemStatus;
    /* 0xE4 */ TransformStatus transformStatus;
    /* 0xE8 */ EyesightStatus eyesightStatus;
    /* 0xEC */ Muzzled muzzled;
    /* 0xF0 */ bool8 powerEars;
    /* 0xF1 */ bool8 scanning;
    /* 0xF2 */ bool8 stairSpotter;
    /* 0xF3 */ bool8 unkF3;
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
    /* 0x113 */ u8 unk113;
    // When non-zero, an AI Pokémon will move in a random direction every turn when it is a room.
    // There is a chance of this flag being set when a wild Pokémon spawns. The chance depends on the dungeon's randomMovementChance.
    /* 0x114 */ u32 moveRandomly;
    /* 0x118 */ Move moves[MAX_MON_MOVES];
    /* 0x138 */ u8 struggleMoveFlags;
    /* 0x13C */ FixedPoint belly;
    /* 0x140 */ FixedPoint maxBelly;
    /* 0x144 */ bool8 aiNextToTarget; // True if an AI Pokémon is following another Pokémon and is already adjacent to them.
    /* 0x145 */ bool8 recalculateFollow; // Used by the AI to defer a movement decision until after all other Pokémon have moved.
    /* 0x146 */ u8 unk146;
    /* 0x147 */ bool8 waiting; // True if an AI Pokémon decided to do nothing this turn.
    /* 0x148 */ bool8 attacking;
    /* 0x149 */ u8 unk149;
    /* 0x14A */ u8 unk14A;
    /* 0x14B */ u8 unk14B;
    /* 0x14C */ u8 unk14C;
    /* 0x14D */ u8 unk14D;
    /* 0x14E */ u16 visualFlags;
    /* 0x150 */ u16 previousVisualFlags;
    /* 0x152 */ u8 unk152;
    u8 unk153;
    u8 unk154;
    u8 unk155;
    u8 unk156;
    bool8 unk157;
    u8 unk158;
    u8 unk159;
    u8 unk15A;
    u8 unk15B;
    u8 unk15C;
    u8 unk15D;
    u8 unk15E;
    u8 unk15F;
    u8 unk160;
    u8 fill161[3];
    /* 0x164 */ u8 unk164;
    /* 0x165 */ u8 unk165;
    /* 0x166 */ u8 unk166;
    /* 0x167 */ u8 unk167;
    /* 0x168 */ u8 unk168;
    /* 0x169 */ u8 turnsSinceWarpScarfActivation;
    /* 0x16C */ Position targetPos;
    /* 0x170 */ Position pixelPos;
    u32 unk174;
    u16 unk178;
    /* 0x17A */ u16 mimicMoveIDs[MAX_MON_MOVES]; // All moves that Mimic has copied (not sure on size...)
    // Previous value of targetPosition for movement, 1 and 2 moves ago.
    /* 0x184 */ Unk_Entity_x184 unk184[4];
    /* 0x1F4 */ s16 numMoveTiles; // Number of tiles to move in a turn. Can be greater than 1 if the user's movement speed is boosted.
    /* 0x1F6 */ s16 notMoving;
    /* 0x1F8 */ s16 unk1F8;
    /* 0x1FA */ s16 mobileTurnTimer; // When a Pokémon can pass through walls in a hallway, this counts up to 200 before the Pokémon turns in a random direction.
    /* 0x1FC */ u32 expGainedInTurn; // Used to accumulate experience when multiple enemies are defeated in one turn.
    /* 0x200 */ u32 statusIcons;
    u8 unk204;
} EntityInfo;

// size: 0x74 | Used for Pokémon, items, and traps.
typedef struct Entity
{
    /* 0x0 */ u32 type;
    /* 0x4 */ Position pos;
    /* 0x8 */ Position prevPos;
    // The center of the entity acccording to pixel-space coordinates, using the same origin as posWorld.
    // X = (posWorld * 24 + 16) * 256, while Y = (posWorld * 24 + 12) * 256.
    /* 0xC */ Position32 pixelPos;
    /* 0x14 */ Position32 prevPixelPos;
    s32 unk1C;
    /* 0x20 */ bool8 isVisible; // Turned off when a Pokémon faints.
    u8 fill21;
    u8 unk22;
    u8 fill23;
    u8 unk24;
    /* 0x25 */ u8 room;
    // The global spawn index counter starts at 10. Each Pokémon that spawns increments the counter and
    // gets assigned the current counter value as its spawn index.
    /* 0x26 */ u16 spawnGenID;
    /* 0x28 */ struct axObject axObj;
} Entity;

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
    // 0
    AI_CHASE_TARGET = 1,
    AI_CHASE_REMEMBERED_TARGET,
    AI_ROAM,
    AI_LEAVE_ROOM,
    AI_RUN_AWAY,
    AI_STAND_STILL,
    AI_TAKE_ITEM
};

enum ClientType
{
    CLIENT_TYPE_NONE,
    CLIENT_TYPE_CLIENT, // Used for mission clients that need rescuing.
    CLIENT_TYPE_PARTNER,
    // 3
    CLIENT_TYPE_DONT_MOVE = 4 // Used for Diglett in the Skarmory boss fight.
};

enum VisualFlag
{
    // Set if Run Away's visual effect (green smoke cloud) has been triggered on this floor.
    // Prevents the effect from showing again if the Pokémon stops running away and then starts running away again.
    VISUAL_FLAG_RUN_AWAY = 2
};

static inline EntityInfo *GetEntInfo(Entity *ent)
{
    return ent->axObj.info;
}

#endif
