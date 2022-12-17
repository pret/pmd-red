#ifndef GUARD_CODE_8077274_1_H
#define GUARD_CODE_8077274_1_H

void MuzzleTarget(struct DungeonEntity *pokemon, struct DungeonEntity *target);
void sub_8078E18(struct DungeonEntity * pokemon, struct DungeonEntity * target);
void sub_8078F50(struct DungeonEntity * pokemon, struct DungeonEntity * target);
void ExposeStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target, s16 param_3);
void IdentityItemHolders(struct DungeonEntity *pokemon, struct DungeonEntity *target);
void BlindTarget(struct DungeonEntity *pokemon, struct DungeonEntity *target);
void CrossEyeVisionTarget(struct DungeonEntity *pokemon, struct DungeonEntity *target);
void RestoreVisionTarget(struct DungeonEntity *pokemon, struct DungeonEntity *target);
void RestorePPTarget(struct DungeonEntity * pokemon,struct DungeonEntity * target, s32 param_3);
void sub_80793B0(struct DungeonEntity * pokemon,struct DungeonEntity * target, s32 param_3);
void sub_8079420(struct DungeonEntity * pokemon,struct DungeonEntity * target, s32 param_3);
void sub_8079490(struct DungeonEntity * pokemon,struct DungeonEntity * target, s32 param_3);
void sub_8079500(struct DungeonEntity * pokemon,struct DungeonEntity * target, s32 param_3);
void LongTossStatusTarget(struct DungeonEntity * pokemon,struct DungeonEntity * target);
void PierceStatusTarget(struct DungeonEntity * pokemon,struct DungeonEntity * target);
void SetChargeStatusTarget(struct DungeonEntity *pokemon, struct DungeonEntity *target, u8 newStatus, struct PokemonMove *move, u8 *message);
void sub_8079764(struct DungeonEntity * pokemon);
void sub_80797A0(struct DungeonEntity * pokemon, struct DungeonEntity * target, u8 newStatus);
void SafeguardStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target);
void MistStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target);
void WishStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target);
void MagicCoatStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target);
void LightScreenStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target);
void ReflectStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target);
void ProtectStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target);
void MirrorCoatStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target);
void EndureStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target);
void MirrorMoveStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target);
void Conversion2StatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target);
void VitalThrowStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target);
void sub_8079F20(struct DungeonEntity * pokemon, struct DungeonEntity * target, u8 param_3, u8 param_4);
void sub_807A0CC(struct DungeonEntity * pokemon, struct DungeonEntity * target);
void SendSleepEndMessage(struct DungeonEntity * pokemon, struct DungeonEntity * target, bool8 param_3, bool8 param_4);
void SendNonVolatileEndMessage(struct DungeonEntity * pokemon, struct DungeonEntity * target);
void SendImmobilizeEndMessage(struct DungeonEntity * pokemon, struct DungeonEntity *target);
void SendVolatileEndMessage(struct DungeonEntity * pokemon, struct DungeonEntity *target);
void SendProtectionEndMessage(struct DungeonEntity * pokemon, struct DungeonEntity *target);
void SendWaitingEndMessage(struct DungeonEntity * pokemon, struct DungeonEntity * target, u8 waitingStatus);
void SendLinkedEndMessage(struct DungeonEntity * pokemon, struct DungeonEntity * target);
void SendMoveEndMessage(struct DungeonEntity * pokemon, struct DungeonEntity * target);
void SendTransformEndMessage(struct DungeonEntity * pokemon, struct DungeonEntity *target);
void SendEyesightEndMessage(struct DungeonEntity * pokemon,struct DungeonEntity * target);
void SendMuzzledEndMessage(struct DungeonEntity * pokemon, struct DungeonEntity * target);
void sub_807A96C(struct DungeonEntity *pokemon, struct DungeonEntity *target);
void WakeUpPokemon(struct DungeonEntity * pokemon);
void SendThawedMessage(struct DungeonEntity *pokemon, struct DungeonEntity *target);
void sub_807AA30(void);

#endif // !GUARD_CODE_8077274_1_H
