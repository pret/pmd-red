#include "global.h"
#include "dungeon_engine.h"

bool8 entityExists(struct DungeonEntity *entity)
{
    if (!entity)
    {
        return FALSE;
    }
    return entity->entityType != ENTITY_NONE;
}
