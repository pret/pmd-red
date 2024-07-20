#ifndef GUARD_MOVE_EFFECTS_TARGET_H
#define GUARD_MOVE_EFFECTS_TARGET_H

#include "structs/dungeon_entity.h"

u8 sub_8075BF4(Entity * pokemon, s32 sleepTurns);
void sub_8075C58(Entity * pokemon, Entity * target, s32 turns, bool8 displayMessage);
bool8 CannotSleep(Entity * pokemon, Entity * target, u8 param_3, bool8 displayMessage);
void NightmareStatusTarget(Entity * pokemon, Entity * target, s32 turns);
void NappingStatusTarget(Entity * pokemon, Entity * target, s32 turns);
void YawnedStatusTarget(Entity * pokemon, Entity * target, s32 turns);
void SleeplessStatusTarget(Entity * pokemon, Entity * target);
void PausedStatusTarget(Entity * pokemon, Entity * target, u8 param_3, s32 turns, bool8 displayMessage);
void InfatuateStatusTarget(Entity * pokemon, Entity * target, bool8 displayMessage);
void BurnedStatusTarget(Entity * pokemon, Entity * target, u8 param_3, bool8 displayMessage);
void PoisonedStatusTarget(Entity * pokemon, Entity * target, bool8 displayMessage);
void BadlyPoisonedStatusTarget(Entity * pokemon, Entity * target, bool8 displayMessage);
void FrozenStatusTarget(Entity * pokemon, Entity * target, bool8 displayMessage);
void SqueezedStatusTarget(Entity * pokemon, Entity * target, s16 param_3, bool32 displayMessage);
void ImmobilizedStatusTarget(Entity * pokemon, Entity * target);
void IngrainedStatusTarget(Entity * pokemon, Entity * target);
void WrapTarget(Entity * pokemon, Entity * target);
void sub_8076CB4(s32 param_1);
void PetrifiedStatusTarget(Entity * pokemon, Entity * target);
void LowerAttackStageTarget(Entity * pokemon, Entity * target, s32 index, s32 decrement, u8 param_5, bool8 displayMessage);
void LowerDefenseStageTarget(Entity * pokemon, Entity * target, s32 index, s32 decrement, u8 param_5, bool8 displayMessage);
void RaiseAttackStageTarget(Entity * pokemon, Entity * target, s32 index, s32 increment);
void RaiseDefenseStageTarget(Entity * pokemon, Entity * target, s32 index, s32 increment);

#endif
