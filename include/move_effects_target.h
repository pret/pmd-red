#ifndef GUARD_MOVE_EFFECTS_TARGET_H
#define GUARD_MOVE_EFFECTS_TARGET_H

u8 sub_8075BF4(struct Entity * pokemon, s32 sleepTurns);
void sub_8075C58(struct Entity * pokemon, struct Entity * target, s32 turns, bool8 displayMessage);
bool8 CannotSleep(struct Entity * pokemon, struct Entity * target, u8 param_3, bool8 displayMessage);
void NightmareStatusTarget(struct Entity * pokemon, struct Entity * target, s32 turns);
void NappingStatusTarget(struct Entity * pokemon, struct Entity * target, s32 turns);
void YawnedStatusTarget(struct Entity * pokemon, struct Entity * target, s32 turns);
void SleeplessStatusTarget(struct Entity * pokemon, struct Entity * target);
void PausedStatusTarget(struct Entity * pokemon, struct Entity * target, u8 param_3, s32 turns, bool8 displayMessage);
void InfatuateStatusTarget(struct Entity * pokemon, struct Entity * target, bool8 displayMessage);
void BurnedStatusTarget(struct Entity * pokemon, struct Entity * target, u8 param_3, bool8 displayMessage);
void PoisonedStatusTarget(struct Entity * pokemon, struct Entity * target, bool8 displayMessage);
void BadlyPoisonedStatusTarget(struct Entity * pokemon, struct Entity * target, bool8 displayMessage);
void FrozenStatusTarget(struct Entity * pokemon, struct Entity * target, bool8 displayMessage);
void SqueezedStatusTarget(struct Entity * pokemon, struct Entity * target, s16 param_3, bool32 displayMessage);
void ImmobilizedStatusTarget(struct Entity * pokemon, struct Entity * target);
void IngrainedStatusTarget(struct Entity * pokemon, struct Entity * target);
void WrapTarget(struct Entity * pokemon, struct Entity * target);
void sub_8076CB4(s32 param_1);
void PetrifiedStatusTarget(struct Entity * pokemon, struct Entity * target);
void LowerAttackStageTarget(struct Entity * pokemon, struct Entity * target, s32 index, s32 decrement, u8 param_5, bool8 displayMessage);
void LowerDefenseStageTarget(struct Entity * pokemon, struct Entity * target, s32 index, s32 decrement, u8 param_5, bool8 displayMessage);
void RaiseAttackStageTarget(struct Entity * pokemon, struct Entity * target, s32 index, s32 increment);
void RaiseDefenseStageTarget(struct Entity * pokemon, struct Entity * target, s32 index, s32 increment);

#endif
