#ifndef GUARD_DUNGEON_MON_SPRITE_RENDER_H
#define GUARD_DUNGEON_MON_SPRITE_RENDER_H

#include "structs/dungeon_entity.h"

void UpdateMonsterSprite(Entity *entity);
void sub_806CC10(void);
void sub_806CC70(void);
void sub_806CCB4(Entity *entity, u8);
void sub_806CD90(void);
void sub_806CDD4(Entity *entity, u8, u32 direction);
void sub_806CDFC(Entity *entity, u8, u32 direction);
void sub_806CE34(Entity *entity, u32 newDir);
void sub_806CE68(Entity *entity, u32 newDir);
void sub_806CE94(Entity *entity, u32 newDir);
u8 sub_806CEBC(Entity *entity);
void sub_806CEFC(Entity *entity, u32 newDir);
void sub_806CF18(Entity *entity);
void DetermineAllMonsterShadow(void);
u32 DetermineMonsterShadow(Entity *entity);

#endif // GUARD_DUNGEON_MON_SPRITE_RENDER_H
