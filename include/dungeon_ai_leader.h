#ifndef GUARD_DUNGEON_AI_LEADER_H
#define GUARD_DUNGEON_AI_LEADER_H

#include "dungeon_entity.h"

bool8 TargetLeader(struct Entity *pokemon);
struct Entity* GetLeaderIfVisible(struct Entity *pokemon);

#endif
