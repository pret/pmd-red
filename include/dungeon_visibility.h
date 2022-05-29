#ifndef GUARD_DUNGEON_VISIBILITY_H
#define GUARD_DUNGEON_VISIBILITY_H

#include "dungeon_entity.h"

bool8 CanSee(struct DungeonEntity *entity, struct DungeonEntity *targetEntity);
bool8 CanSee_2(struct DungeonEntity *entity, struct DungeonEntity *targetEntity);
bool8 sub_8045A70(struct DungeonEntity *entity, struct DungeonEntity *targetEntity);
bool8 sub_8045AAC(struct DungeonEntity *entity, struct Position *pos);
bool8 InSameRoom(struct DungeonEntity *entity, struct Position *pos);

#endif
