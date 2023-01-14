#ifndef GUARD_DUNGEON_AI_MOVEMENT_H
#define GUARD_DUNGEON_AI_MOVEMENT_H

#include "dungeon_entity.h"

void MoveIfPossible(struct Entity *pokemon, bool8 showRunAwayEffect);
bool8 CanTakeItem(struct Entity *pokemon);
bool8 ChooseTargetPosition(struct Entity *pokemon);
void DecideMovement(struct Entity *pokemon, bool8 showRunAwayEffect);
bool8 AvoidEnemies(struct Entity *pokemon);
bool8 Wander(struct Entity *pokemon);

#endif
