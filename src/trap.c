#include "global.h"
#include "trap.h"

#include "dungeon_map_access.h"
#include "dungeon_util.h"
#include "map.h"

bool8 CanLayTrap(struct Position *pos)
{
    struct Tile *tile = GetTileSafe(pos->x, pos->y);
    if (tile->terrainType & TERRAIN_TYPE_STAIRS ||
        tile->room == CORRIDOR_ROOM ||
        tile->terrainType & TERRAIN_TYPE_NATURAL_JUNCTION)
    {
        return FALSE;
    }
    if (tile->terrainType & TERRAIN_TYPE_SHOP)
    {
        return FALSE;
    }
    if ((tile->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)) != TERRAIN_TYPE_NORMAL ||
        (tile->object != NULL && GetEntityType(tile->object) != ENTITY_TRAP))
    {
        return FALSE;
    }
    return TRUE;
}
