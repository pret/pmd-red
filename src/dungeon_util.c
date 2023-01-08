#include "global.h"
#include "dungeon_util.h"

#include "dungeon_map_access.h"

const struct Position gAdjacentTileOffsets[] = {
    {0, 1},
    {1, 1},
    {1, 0},
    {1, -1},
    {0, -1},
    {-1, -1},
    {-1, 0},
    {-1, 1}
};

bool8 EntityExists(struct Entity *entity)
{
    if (!entity)
    {
        return FALSE;
    }
    return entity->type != ENTITY_NOTHING;
}

u32 GetEntityType(struct Entity *entity)
{
    return entity->type;
}

u8 GetEntityRoom(struct Entity *entity)
{
    return entity->room;
}

struct EntityInfo* GetTrapData(struct Entity *entity)
{
    return entity->info;
}

struct Item* GetItemData(struct Entity *entity)
{
    return (struct Item *)entity->info;
}

struct EntityInfo* GetTrapData_1(struct Entity *entity)
{
    return entity->info;
}

struct Item* GetItemData_1(struct Entity *entity)
{
    return (struct Item*)entity->info;
}

struct Tile* GetTileAtEntity(struct Entity *entity)
{
    return GetTile(entity->pos.x, entity->pos.y);
}

struct Tile* GetTileAtEntitySafe(struct Entity *entity)
{
    return GetTileSafe(entity->pos.x, entity->pos.y);
}
