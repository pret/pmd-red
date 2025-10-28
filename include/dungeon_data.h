#ifndef GUARD_DUNGEON_DATA_H
#define GUARD_DUNGEON_DATA_H

#include "exclusive_pokemon.h"
#include "friend_area.h"
#include "constants/type.h"
#include "constants/friend_area.h"
#include "constants/iq_skill.h"
#include "constants/tactic.h"
#include "constants/dungeon.h"
#include "constants/item.h"

// size: 0x10
typedef struct DungeonDataEntry
{
    /* 0x0 */ bool8 stairDirectionUp;
    // If enabled, enemies will evolve when a team member is KOed (and doesn't revive) if their evolution spawns on the floor.
    // False for all dungeons, but the code still works if this flag is enabled.
    /* 0x1 */ bool8 enemiesEvolveWhenKOed;
    /* 0x2 */ bool8 recruitingEnabled;
    /* 0x3 */ s8 rescuesAllowed;
    /* 0x4 */ u8 maxItemsAllowed;
    /* 0x5 */ u8 maxPartyMembers;
    /* 0x6 */ bool8 levelResetTo1;
    /* 0x7 */ bool8 keepMoney;
    /* 0x8 */ bool8 leaderCanSwitch;
    /* 0x9 */ bool8 hasCheckpoint;
    /* 0xA */ bool8 enterWithoutGameSave; // If false, the dungeon will force a quicksave before entering.
    /* 0xB */ u8 HMMask; // HM mask for dungeon entry requirements (Fly, Dive, Waterfall, Surf, Water).
    /* 0xC */ s16 turnLimit;
    // The chance that a wild Pokémon's moveRandomly flag will be set when spawning,
    // causing them to move randomly inside a room instead of exploring rooms.
    /* 0xE */ s16 randomMovementChance;
} DungeonDataEntry;

extern const DungeonDataEntry gDungeons[];
extern const u8 gInvalidDungeonIDs[11];
extern const u8 gInvalidItemIDs[16];
extern const bool8 gTacticsTargetLeader[NUM_TACTICS];
extern const s16 gReqTacticLvls[NUM_TACTICS];
extern const s32 gReqIQSkillPts[NUM_IQ_SKILLS];
extern const s32 gUnknown_810A3F0[100];
extern const s16 gTypeGummiIQBoost[NUM_TYPES][NUMBER_OF_GUMMIS];
extern const s16 gUnknown_810A808[NUM_TYPES][NUMBER_OF_GUMMIS];
extern const FriendAreaSettings gFriendAreaSettings[NUM_FRIEND_AREAS];
extern const s16 gPowerBandBoost;
extern const s16 gSpecialBandBoost;
extern const s16 gDefScarfBoost;
extern const s16 gZincBandBoost;
extern const s16 gMunchBeltBoost;
extern const u8 gBestResistTypeTable[NUM_TYPES];
extern const bool8 gIsTypePhysicalTable[NUM_TYPES];
extern const s32 gUnknown_810AC90[10];
extern const s16 gFrenzyPlantIQReq;
extern const s16 gHydroCannonIQReq;
extern const s16 gBlastBurnIQReq;
extern const s16 gVoltTackleIQReq;
extern const u8 gDungeonWaterType[76];
extern const struct ExclusivePokemon gExclusivePokemon[NUM_EXCLUSIVE_POKEMON];

bool8 IsWaterDungeon(u32 r0);

#endif // GUARD_DUNGEON_DATA_H
