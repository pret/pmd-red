#ifndef GUARD_RESCUE_SCENARIO_H
#define GUARD_RESCUE_SCENARIO_H

#include "constants/rescue_dungeon_id.h"
#include "structs/str_wonder_mail.h"

void sub_80972F4(void);
void nullsub_128(void);
bool8 sub_8097318(s16 param_1);
void sub_809733C(s16 param_1, u32 param_2);
bool8 sub_8097384(s32 param_1);
void sub_80973A8(s32 param_1, u32 param_2);
bool8 RescueScenarioConquered(s32 rescueDungeonID_);
void sub_8097418(s32 index, bool32);
const u8 *GetRescueDungeonName(s16 rescueDungeonId);
const u8 *GetCurrentMissionText(s16 index);

#endif // GUARD_RESCUE_SCENARIO_H
