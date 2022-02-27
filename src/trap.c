#include "global.h"
#include "trap.h"

#include "dungeon_map_access.h"
#include "dungeon_util.h"
#include "map.h"

bool8 CanLayTrap(struct Position *pos)
{
    struct MapTile *tile = GetMapTile_2(pos->x, pos->y);
    if (tile->tileType & TILE_TYPE_STAIRS ||
        tile->roomIndex == CORRIDOR_ROOM_INDEX ||
        tile->tileType & TILE_TYPE_ROOM_EXIT)
    {
        return FALSE;
    }
    if (tile->tileType & TILE_TYPE_SHOP)
    {
        return FALSE;
    }
    if ((tile->tileType & (TILE_TYPE_FLOOR | TILE_TYPE_LIQUID)) != TILE_TYPE_FLOOR ||
        (tile->mapObject != NULL && GetEntityType(tile->mapObject) != ENTITY_TRAP))
    {
        return FALSE;
    }
    return TRUE;
}
