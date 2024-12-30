#include "global.h"
#include "code_803E668.h"
#include "code_8041AD0.h"
#include "code_806CD90.h"
#include "dungeon_map_access.h"
#include "dungeon_util.h"
#include "items.h"

// TODO: Merge this file with trap.c after "HandlePokemonTrap" is in c

extern void sub_804687C(Entity *, DungeonPos *, DungeonPos *, Item *, u32);

void HandleTripTrap(Entity *pokemon, Entity *target)
{
    u32 direction;
    EntityInfo *info;
    DungeonPos pos;
    Item item;

    if (target != NULL) {
        sub_806CDD4(target, 6, NUM_DIRECTIONS);
        sub_803E708(0x10, 0x55);
        sub_806CE68(target, NUM_DIRECTIONS);
        info = GetEntInfo(target);
        if ((info->heldItem).flags & ITEM_FLAG_EXISTS) {
            item =  (info->heldItem);
            (info->heldItem).flags = 0;
            FillInventoryGaps();
            sub_80421C0(target, 400);
            direction = (info->action).direction & DIRECTION_MASK;
            pos.x = (target->pos).x + gAdjacentTileOffsets[direction].x;
            pos.y =  (target->pos).y + gAdjacentTileOffsets[direction].y;
            sub_804687C(pokemon, &target->pos, &pos, &item, 1);
        }
    }
}

void SetTrap(Tile *tile, u8 id)
{
    Trap *trapData;
    Entity *entity;

    entity = tile->object;
    if (EntityIsValid(entity)) {
        if (GetEntityType(entity) == ENTITY_TRAP) {
            trapData = GetTrapData(entity);
            trapData->id = id;
        }
        sub_8049ED4();
    }
}
