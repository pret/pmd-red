#ifndef GUARD_MOVE_EFFECTS_TARGET_H
#define GUARD_MOVE_EFFECTS_TARGET_H

u8 sub_8075BF4(struct DungeonEntity * pokemon, s32 sleepTurns);
void sub_8075C58(struct DungeonEntity * pokemon, struct DungeonEntity * target, s32 turns, bool8 displayMessage);
bool8 CannotSleep(struct DungeonEntity * pokemon, struct DungeonEntity * target, u8 param_3, bool8 displayMessage);
void NightmareStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target, s32 turns);
void NappingStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target, s32 turns);
void YawnedStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target, s32 turns);
void SleeplessStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target);
void PausedStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target, u8 param_3, s32 turns, bool8 displayMessage);
void InfatuateStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target, bool8 displayMessage);
void BurnedStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target, u8 param_3, bool8 displayMessage);
void PoisonedStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target, bool8 displayMessage);
void BadlyPoisonedStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target, bool8 displayMessage);
void FrozenStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target, bool8 displayMessage);
void SqueezedStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target, s16 param_3, bool32 displayMessage);
void ImmobilizedStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target);
void IngrainedStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target);
void WrapTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target);
void sub_8076CB4(s32 param_1);
void PetrifiedStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target);
void LowerAttackStageTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target, s32 index, s32 decrement, u8 param_5, bool8 displayMessage);
void LowerDefenseStageTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target, s32 index, s32 decrement, u8 param_5, bool8 displayMessage);
void RaiseAttackStageTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target, s32 index, s32 increment);
void RaiseDefenseStageTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target, s32 index, s32 increment);

#endif
