#ifndef GUARD_DUNGEON_UTIL_H
#define GUARD_DUNGEON_UTIL_H

#include "constants/colors.h"
#include "constants/direction.h"
#include "structs/dungeon_entity.h"
#include "structs/str_position.h"
#include "structs/str_traps.h"
#include "structs/str_dungeon.h"
#include "structs/map.h"

static inline EntityInfo *GetEntInfo(Entity *entity)
{
    return entity->axObj.info.monster;
}

bool8 EntityIsValid(Entity *pokemon);
u32 GetEntityType(Entity *entity);
u8 GetEntityRoom(Entity *entity);
Tile *GetTileAtEntitySafe(Entity *entity);
void sub_804513C(void);
void sub_804522C(void);
void UpdateEntityPixelPos(Entity *entity, PixelPos *pos);
void SetEntityPixelPos(Entity *entity, s32 x, s32 y);
void IncreaseEntityPixelPos(Entity *entity, s32 x, s32 y);
Entity *sub_80453AC(s32 _species);
Entity *sub_804550C(s32 _species);
Item *GetItemInfo(Entity *entity);
Item *GetItemData_1(Entity *entity);
Trap *GetTrapInfo(Entity *entity);
Trap* GetTrapData_1(Entity *entity);
Entity *SpawnTrap(u8 trapID, DungeonPos *pos, u8 c);
Entity *SpawnItemEntity(DungeonPos *pos);
void sub_80457DC(Entity* ent);
bool8 ShouldMinimapDisplayEntity(Entity *ent);
bool8 ShouldDisplayEntity(Entity *ent);
bool8 CanSeeTarget(Entity *entity, Entity *targetEntity);
bool8 CanTargetEntity(Entity *entity, Entity *targetEntity);
bool8 sub_8045A70(Entity *entity, Entity *targetEntity);
bool8 sub_8045AAC(Entity *entity, DungeonPos *pos);
bool8 CanTargetPosition(Entity *entity, DungeonPos *pos);
void SubstitutePlaceholderStringTags(u8 *buffer, Entity *entity, u32 monsterColorNum);
void sub_8045ACC(void);
s32 GetTeamMemberEntityIndex(Entity *pokemon);

extern u8 gUnknown_202EE70[MAX_TEAM_BODY_SIZE];
extern u8 gUnknown_202EE76[DUNGEON_MAX_WILD_POKEMON_BODY_SIZE];

#endif // GUARD_DUNGEON_UTIL_H
