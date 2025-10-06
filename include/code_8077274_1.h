#ifndef GUARD_CODE_8077274_1_H
#define GUARD_CODE_8077274_1_H

#include "structs/dungeon_entity.h"

// TODO: Remove this file



void SetChargeStatusTarget(Entity *pokemon, Entity *target, u8 newStatus, Move *move, const u8 *message);
void sub_8079764(Entity * pokemon);
void CounterStatusTarget(Entity * pokemon, Entity * target, u8 newStatus);
void SafeguardStatusTarget(Entity * pokemon, Entity * target);
void MistStatusTarget(Entity * pokemon, Entity * target);
void WishStatusTarget(Entity * pokemon, Entity * target);
void MagicCoatStatusTarget(Entity * pokemon, Entity * target);
void LightScreenStatusTarget(Entity * pokemon, Entity * target);
void ReflectStatusTarget(Entity * pokemon, Entity * target);
void ProtectStatusTarget(Entity * pokemon, Entity * target);
void MirrorCoatStatusTarget(Entity * pokemon, Entity * target);
void EndureStatusTarget(Entity * pokemon, Entity * target);
void MirrorMoveStatusTarget(Entity * pokemon, Entity * target);
void Conversion2StatusTarget(Entity * pokemon, Entity * target);
void VitalThrowStatusTarget(Entity * pokemon, Entity * target);
void sub_8079F20(Entity * pokemon, Entity * target, u8 param_3, u8 param_4);
void sub_807A0CC(Entity * pokemon, Entity * target);
void EndSleepClassStatus(Entity * pokemon, Entity * target, bool8 param_3, bool8 param_4);
void EndBurnClassStatus(Entity * pokemon, Entity * target);
void EndFrozenClassStatus(Entity * pokemon, Entity *target);
void EndCringeClassStatus(Entity * pokemon, Entity *target);
void EndReflectClassStatus(Entity * pokemon, Entity *target);
void EndCurseClassStatus(Entity * pokemon, Entity * target, u8 curseClassStatus);
void EndLeechSeedClassStatus(Entity * pokemon, Entity * target);
void SendMoveEndMessage(Entity * pokemon, Entity * target);
void SendTransformEndMessage(Entity * pokemon, Entity *target);
void SendEyesightEndMessage(Entity * pokemon,Entity * target);
void SendMuzzledEndMessage(Entity * pokemon, Entity * target);
bool8 TrySendImmobilizeSleepEndMsg(Entity *pokemon, Entity *target);
void WakeUpPokemon(Entity * pokemon);
void SendThawedMessage(Entity *pokemon, Entity *target);
void sub_8079E34(Entity * pokemon, Entity * target, bool8 param_3);

#endif // !GUARD_CODE_8077274_1_H
