#ifndef GUARD_DUNGEON_VISIBILITY_H
#define GUARD_DUNGEON_VISIBILITY_H

#include "dungeon_entity.h"

bool8 CanSeeTarget(struct Entity *entity, struct Entity *targetEntity);
bool8 CanTargetEntity(struct Entity *entity, struct Entity *targetEntity);
bool8 sub_8045A70(struct Entity *entity, struct Entity *targetEntity);
bool8 sub_8045AAC(struct Entity *entity, struct Position *pos);
bool8 CanTargetPosition(struct Entity *entity, struct Position *pos);

#endif
