#ifndef GUARD_DUNGEON_H
#define GUARD_DUNGEON_H

#include "dungeon_global_data.h"

struct DungeonName
{
    const u8 *name1;
    const u8 *name2;
};

struct DungeonDataEntry
{
    /* 0x0 */ bool8 stairDirectionUp;
    /* 0x1 */ bool8 unk1;
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
    /* 0xE */ s16 randomMovementChance; // The chance that a wild Pokémon's moveRandomly flag will be set when spawning, causing them to move randomly inside a room instead of exploring rooms.
};

extern struct DungeonDataEntry gDungeons[];
extern struct DungeonName gDungeonNames[];
const u8 *GetDungeonName1(u8 dungeon);
u32 sub_80908D8(struct DungeonLocation *dungeon);
u8 sub_8090910(struct DungeonLocation *dungeon, u32 param_2);
bool8 sub_809095C(u8 dungeon);
s8 GetRescuesAllowed(u8 dungeon);
bool8 HasCheckpoint(u8 dungeon);

#endif //GUARD_DUNGEON_H
