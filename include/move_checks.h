#ifndef GUARD_MOVE_CHECKS_H
#define GUARD_MOVE_CHECKS_H

bool8 CanUseOnSelfWithStatusChecker(Entity *pokemon, struct Move *move);
bool8 CanUseOnTargetWithStatusChecker(Entity *user, Entity *target, struct Move *move);
bool8 HasDisabledMove(struct Move *moves);
bool8 LastUsedMoveOutOfPP(struct Move *moves);
bool8 HasLastUsedMove(struct Move *moves);

#endif
