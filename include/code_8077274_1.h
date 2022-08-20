#ifndef GUARD_CODE_8077274_1_H
#define GUARD_CODE_8077274_1_H

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
void sub_807A9B0(struct DungeonEntity * pokemon);
void sub_807A9D8(struct DungeonEntity *pokemon, struct DungeonEntity *target);
void sub_807AA30(void);

#endif // !GUARD_CODE_8077274_1_H
