#ifndef GUARD_CODE_8077274_1_H
#define GUARD_CODE_8077274_1_H

void MuzzleTarget(struct Entity *pokemon, struct Entity *target);
void sub_8078E18(struct Entity * pokemon, struct Entity * target);
void sub_8078F50(struct Entity * pokemon, struct Entity * target);
void ExposeStatusTarget(struct Entity * pokemon, struct Entity * target, s16 param_3);
void IdentityItemHolders(struct Entity *pokemon, struct Entity *target);
void BlindTarget(struct Entity *pokemon, struct Entity *target);
void CrossEyeVisionTarget(struct Entity *pokemon, struct Entity *target);
void RestoreVisionTarget(struct Entity *pokemon, struct Entity *target);
void RestorePPTarget(struct Entity * pokemon,struct Entity * target, s32 param_3);
void sub_80793B0(struct Entity * pokemon,struct Entity * target, s32 param_3);
void sub_8079420(struct Entity * pokemon,struct Entity * target, s32 param_3);
void sub_8079490(struct Entity * pokemon,struct Entity * target, s32 param_3);
void sub_8079500(struct Entity * pokemon,struct Entity * target, s32 param_3);
void LongTossStatusTarget(struct Entity * pokemon,struct Entity * target);
void PierceStatusTarget(struct Entity * pokemon,struct Entity * target);
void SetChargeStatusTarget(struct Entity *pokemon, struct Entity *target, u8 newStatus, struct Move *move, u8 *message);
void sub_8079764(struct Entity * pokemon);
void sub_80797A0(struct Entity * pokemon, struct Entity * target, u8 newStatus);
void SafeguardStatusTarget(struct Entity * pokemon, struct Entity * target);
void MistStatusTarget(struct Entity * pokemon, struct Entity * target);
void WishStatusTarget(struct Entity * pokemon, struct Entity * target);
void MagicCoatStatusTarget(struct Entity * pokemon, struct Entity * target);
void LightScreenStatusTarget(struct Entity * pokemon, struct Entity * target);
void ReflectStatusTarget(struct Entity * pokemon, struct Entity * target);
void ProtectStatusTarget(struct Entity * pokemon, struct Entity * target);
void MirrorCoatStatusTarget(struct Entity * pokemon, struct Entity * target);
void EndureStatusTarget(struct Entity * pokemon, struct Entity * target);
void MirrorMoveStatusTarget(struct Entity * pokemon, struct Entity * target);
void Conversion2StatusTarget(struct Entity * pokemon, struct Entity * target);
void VitalThrowStatusTarget(struct Entity * pokemon, struct Entity * target);
void sub_8079F20(struct Entity * pokemon, struct Entity * target, u8 param_3, u8 param_4);
void sub_807A0CC(struct Entity * pokemon, struct Entity * target);
void SendSleepEndMessage(struct Entity * pokemon, struct Entity * target, bool8 param_3, bool8 param_4);
void SendNonVolatileEndMessage(struct Entity * pokemon, struct Entity * target);
void SendImmobilizeEndMessage(struct Entity * pokemon, struct Entity *target);
void SendVolatileEndMessage(struct Entity * pokemon, struct Entity *target);
void SendProtectionEndMessage(struct Entity * pokemon, struct Entity *target);
void SendWaitingEndMessage(struct Entity * pokemon, struct Entity * target, u8 waitingStatus);
void SendLinkedEndMessage(struct Entity * pokemon, struct Entity * target);
void SendMoveEndMessage(struct Entity * pokemon, struct Entity * target);
void SendTransformEndMessage(struct Entity * pokemon, struct Entity *target);
void SendEyesightEndMessage(struct Entity * pokemon,struct Entity * target);
void SendMuzzledEndMessage(struct Entity * pokemon, struct Entity * target);
void sub_807A96C(struct Entity *pokemon, struct Entity *target);
void WakeUpPokemon(struct Entity * pokemon);
void SendThawedMessage(struct Entity *pokemon, struct Entity *target);
void sub_807AA30(void);

#endif // !GUARD_CODE_8077274_1_H
