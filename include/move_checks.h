#ifndef GUARD_MOVE_CHECKS_H
#define GUARD_MOVE_CHECKS_H

bool8 CanUseOnSelfWithStatusChecker(struct Entity *pokemon, struct Move *move);
bool8 CanUseOnTargetWithStatusChecker(struct Entity *user, struct Entity *target, struct Move *move);
bool8 HasDisabledMove(struct Move *moves);
bool8 LastUsedMoveOutOfPP(struct Move *moves);
bool8 HasLastUsedMove(struct Move *moves);

#endif
