#ifndef GUARD_DUNGEON_PROJECTILE_THROW_H
#define GUARD_DUNGEON_PROJECTILE_THROW_H

#include "structs/str_items.h"
#include "structs/str_position.h"
#include "structs/dungeon_entity.h"

struct ProjectileThrowInfo
{
    u8 unk0;
    u8 unk1;
    s16 unk2;
};

void HandleStraightProjectileThrow(Entity *pokemon, Item *item, DungeonPos *pos, s32 dir, struct ProjectileThrowInfo *a4);
void HandleCurvedProjectileThrow(Entity *entity, Item *item, DungeonPos *pos1, DungeonPos *pos2, struct ProjectileThrowInfo *a4);

#endif // GUARD_DUNGEON_PROJECTILE_THROW_H
