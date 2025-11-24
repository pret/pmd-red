#ifndef GUARD_CODE_80A26CC_H
#define GUARD_CODE_80A26CC_H

#include "constants/ground_map.h"
#include "constants/script_dungeon_id.h"
#include "constants/script_id.h"

// size: 0x14
typedef struct DungeonInfo
{
    /* 0x0 */ s16 mapID1; // See enum "GroundMapID". -1 if nothing
    /* 0x2 */ s16 mapID2; // See enum "GroundMapID". -1 if nothing
    /* 0x4 */ s16 mapID3; // See enum "GroundMapID". -1 if nothing
    /* 0x6 */ s16 scriptID1; // See enum "ScriptID". -1 if nothing
    /* 0x8 */ s16 scriptID2; // See enum "ScriptID". -1 if nothing
    /* 0xA */ s16 scriptID3; // See enum "ScriptID"
    /* 0xC */ u8 dungeonID; // See enum "DungeonID"
    /* 0xE */ s16 rescueDungeonID; // See enum "RescueDungeonId"
    /* 0x10 */ u8 unk10; // Always 1
    /* 0x11 */ bool8 unk11;
} DungeonInfo;

const DungeonInfo *GetScriptDungeonInfo(s32 scriptDungeon_);
s16 ScriptDungeonIDToRescueDungeonID(s16 scriptDungeonID);
s16 sub_80A2668(s16);
s16 sub_80A2688(u8);
s16 RescueDungeonToScriptDungeonId(s16);
s16 sub_80A26CC(s16);
u8 RescueDungeonToDungeonId(s16 index);
u8 sub_80A2728(s16 index);
u8 ScriptDungeonIdToDungeonId(s16 index);
s16 sub_80A2750(s16 scriptDungeon);
bool8 IsRescueDungeonAvailable(s16 _rescueDungeonId);
bool8 sub_80A2824(u8 dungeonID);
bool8 sub_80A28F0(u8 dungeonID);
s32 sub_80A29B0(u8 *);

#endif // GUARD_CODE_80A26CC_H
