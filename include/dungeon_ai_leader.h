#ifndef GUARD_DUNGEON_AI_LEADER_H
#define GUARD_DUNGEON_AI_LEADER_H

#include "dungeon_entity.h"

bool8 TargetLeader(Entity *pokemon);
Entity* GetLeaderIfVisible(Entity *pokemon);

#endif
