#ifndef GUARD_CODE_803C1D0_H
#define GUARD_CODE_803C1D0_H

#include "structs/str_mission_rewards.h"
#include "structs/str_wonder_mail.h"

u8 sub_803C1D0(DungeonLocation *, u8);
const u8 *GetMissionRankText(u8 index);
void sub_803C21C(WonderMail *, MissionRewards *);

#endif // GUARD_CODE_803C1D0_H
