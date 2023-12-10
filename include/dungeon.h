#ifndef GUARD_DUNGEON_H
#define GUARD_DUNGEON_H

#include "structs/str_dungeon.h"

// size: 0x8
typedef struct DungeonName
{
    const u8 *name1;
    const u8 *name2;
} DungeonName;

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

extern DungeonDataEntry gDungeons[];
extern DungeonName gDungeonNames[];

s32 GetDungeonFloorCount(u8 dungeon);
const u8 *GetDungeonName1(u8 dungeon);
u32 GetMaxItemsAllowed(u8 dungeon);
s8 GetRescuesAllowed(u8 dungeon);
bool8 HasCheckpoint(u8 dungeon);
s16 GetRandomMovementChance(u8 dungeon);
void PrintYellowDungeonNametoBuffer(u8 *buffer, DungeonLocation *dungeonLocation);
void PrintDungeonLocationtoBuffer(u8 *buffer, DungeonLocation *dungeonLocation);

u32 sub_80908D8(DungeonLocation *dungeon);
u8 sub_8090910(DungeonLocation *dungeon, u32 param_2);
bool8 sub_809095C(u8 dungeon);

#endif // GUARD_DUNGEON_H
