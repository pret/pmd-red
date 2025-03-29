#ifndef GUARD_DUNGEON_MOVE_UTIL_H
#define GUARD_DUNGEON_MOVE_UTIL_H

#include "structs/str_moves.h"
#include "structs/dungeon_entity.h"

bool32 sub_8055A00(Entity *attacker, s32 firstMoveId, s32 var_34, s32 itemId, s32 arg_0);
void TriggerTargetAbilityEffect(Entity *attacker);
bool8 TryUseChosenMove(struct Entity *attacker, u32 r6, s32 itemId, u32 var_30, bool32 isLinkedMove, struct Move *move);
bool8 sub_8056468(Entity *entity, Move *move, const u8 *str, Entity **unkArray, bool32 itemId, bool8 arg_4, bool32 unused);
s32 sub_8056564(Entity *entity, DungeonPos *pos, Move *move, s32 r4);
void sub_80566F8(Entity *attacker, Move *move, s32 a2, bool8 a3, s32 itemId, s32 isLinkedMove);
bool8 AccuracyCalc(Entity *attacker, Entity *target, Move *move, s32 accuracyType, bool8 selfAlwaysHits);
void SetTargetsForMove(Entity **targetsArray, Entity *attacker, Move *move);
s32 SetNewTarget(s32 targetArrId, Entity **targetsArray, s32 targetFlags_, Entity *attacker, Entity *target, Move *move, bool32 canHitAnyone_);
s32 sub_8057070(Move *move);
bool8 MoveCausesPaused(Move *move);
bool8 MoveMatchesBideClassStatus(Entity *pokemon, Move *move);
bool8 IsChargingAnyTwoTurnMove(Entity *pokemon, bool8 checkCharge);
u32 sub_8057144(Entity * pokemon);
bool8 sub_80571F0(Entity * pokemon, Move *move);
bool8 sub_805727C(Entity * pokemon, Entity * target, s32 chance);
bool8 RollSecondaryEffect(Entity *pokemon, s32 chance);
bool8 CanAIUseMove(Entity *pokemon, s32 moveIndex, bool8 hasPPChecker);
bool8 CanMonsterUseMove(Entity *pokemon, Move *move, bool8 hasPPChecker);
bool8 sub_805744C(Entity * pokemon, Move *move, bool8 param_3);
void SortTargets(Entity **targetsArray, Entity *attacker);
bool8 MoveRequiresCharging(Entity* pokemon, u16 moveID);
void sub_8057588(Entity * pokemon, u8 param_2);
s16 sub_8057600(Move *move, s32 itemID);

#endif
