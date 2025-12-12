#ifndef GUARD_CODE_803C1B4_H
#define GUARD_CODE_803C1B4_H

#include "structs/str_dungeon_location.h"
#include "structs/str_wonder_mail.h"

u32 GetDungeonTeamRankPts(DungeonLocation *dungeon, u8 r1);

void sub_803C37C(DungeonLocation *location, u8 r1, u8 *itemReward);
bool8 sub_803C4F0(WonderMail *mail);
bool8 sub_803C3E0(WonderMail *mail);
bool8 sub_803C45C(WonderMail *mail);
bool8 sub_803C610(WonderMail *param_1);
bool8 sub_803C580(WonderMail *param_1);

#endif // GUARD_CODE_803C1B4_H
