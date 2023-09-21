#ifndef GUARD_DUNGEON_VISIBILITY_H
#define GUARD_DUNGEON_VISIBILITY_H

#include "structs/dungeon_entity.h"

bool8 CanSeeTarget(Entity *entity, Entity *targetEntity);
bool8 CanTargetEntity(Entity *entity, Entity *targetEntity);
bool8 sub_8045A70(Entity *entity, Entity *targetEntity);
bool8 sub_8045AAC(Entity *entity, Position *pos);
bool8 CanTargetPosition(Entity *entity, Position *pos);

#endif
