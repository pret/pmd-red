#ifndef GUARD_MISSION_REWARD_H
#define GUARD_MISSION_REWARD_H

#include "structs/str_mission_rewards.h"

bool8 MR_Create(MissionRewards *rewards, bool8 displayClientSprite);
u32 MR_Update(void);
void MR_Destroy(void);

#endif // GUARD_MISSION_REWARD_H
