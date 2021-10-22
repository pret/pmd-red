#include "global.h"
#include "dungeon_util.h"

bool8 EntityExists(struct DungeonEntity *entity)
{
    if (!entity)
    {
        return FALSE;
    }
    return entity->entityType != ENTITY_NONE;
}
