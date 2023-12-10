#ifndef GUARD_DUNGEON_AI_LEADER_H
#define GUARD_DUNGEON_AI_LEADER_H

#include "structs/dungeon_entity.h"

bool8 TargetLeader(Entity *pokemon);
Entity* GetLeaderIfVisible(Entity *pokemon);
bool8 sub_8072CF4(Entity *entity);

#endif
