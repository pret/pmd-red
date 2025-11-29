#ifndef GUARD_GROUND_LIVES_H
#define GUARD_GROUND_LIVES_H

#include "structs/str_position.h"
#include "structs/str_ground_script.h"
#include "structs/str_ground_lives.h"
#include "structs/str_pokemon.h"
#include "structs/str_dungeon_location.h"

void AllocGroundLives(void);
void DeleteGroundLives(void);
void FreeGroundLives(void);
void GroundLives_Select(s32 mapID, s32 group, s32 sector);
void GroundLives_Cancel(s32 scriptID, s32 sector);
void GroundLives_CancelBlank_1(void);
void GroundLives_CancelBlank_2(void);
s32 sub_80A7AE8(s16);
s32 sub_80A7DDC(s16 *a0, s16 *speciesDst);
void sub_80A86C8(s32 id_, u32 flags);
void sub_80A87AC(s32 id_, s32 a1);
bool8 sub_80A87E0(s32 id_, Pokemon *a1);
Action *sub_80A882C(s32 id_);
bool8 GroundLives_ExecuteScript(s32 id_, ActionUnkIds *a1, ScriptInfoSmall *scriptInfo);
bool8 GroundLives_ExecutePlayerScriptActionLives(s32 id1_, s32 id2_);
bool8 GroundLivesNotifyAll(s32 a0_);
bool8 GroundLivesCancelAll(void);
s32 sub_80A8BBC(s32 id_);
s32 sub_80A8BD8(s32 id_, u32 *a1);
s32 sub_80A8BFC(s32 id_);
s32 sub_80A8C2C(s32 a0);
s32 sub_80A8C4C(s32 id_, DungeonLocation *dungLoc);
bool8 GroundLives_IsStarterMon(s32 id_);
bool8 IsStarterMonster(s32 monsterId_);
bool8 sub_80A8D20(void);
Pokemon *sub_80A8D54(s32 a0);
Pokemon *sub_80A8E9C(s32 id_);
void sub_80A8EC0(u8 *buffer, s32 a1);
void sub_80A8F50(u8 *buffer, s32 a1_, s32 size);
s32 sub_80A8F9C(s32 id_, PixelPos *pixelPos);
s32 sub_80A8FD8(s32 id_, PixelPos *pixelPos);
s32 sub_80A9050(s32 id_, s8 *a1);
s32 sub_80A9090(s32 id_, s32 a1_);
s16 GetFriendAreaDialogueId(s32 id_);
s32 GetLivesCollision_80A92A0(s32 id_, u32 flags, PixelPos *pixelPos1, PixelPos *pixelPos2);
void GroundLives_Action(void);
void sub_80ABA7C(void);

#endif // GUARD_GROUND_LIVES_H
