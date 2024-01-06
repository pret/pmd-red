#include "global.h"
#include "constants/trap.h"
#include "structs/str_dungeon.h"
#include "trap.h"

#include "dungeon_map_access.h"
#include "dungeon_util.h"
#include "structs/map.h"

extern u8 *gUnknown_80FC5FC[];
extern u8 *gUnknown_80FC5F8[];
void sub_8052364(Entity *, Position *, u8 *);
void sub_8049ED4(void);

u8 sub_803D6FC(void);
Entity *sub_8045684(u8, Position *, u8);

bool8 CanLayTrap(Position *pos)
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

bool8 LayTrap(Position *pos, u8 trapID, u8 param_3)
{
    Tile *tile;
    Entity *entity;
    int counter;
    u16 terrainType;

    tile = GetTileSafe(pos->x, pos->y);
    if (TRAP_SPIKE_TRAP < trapID) {
        counter = 0;
        while ((counter < 0x1e && (trapID = sub_803D6FC(), trapID == TRAP_WONDER_TILE))) {
            counter++;
        }
        if (counter == 0x1e) {
            trapID = TRAP_CHESTNUT_TRAP;
        }
    }
    terrainType = tile->terrainType;
    if ((terrainType & TERRAIN_TYPE_STAIRS) != 0) goto _0807FD6E;
    if (tile->room == CORRIDOR_ROOM) goto _0807FD6E;
    if ((terrainType & TERRAIN_TYPE_NATURAL_JUNCTION) != 0) goto _0807FD6E;
    if ((terrainType & TERRAIN_TYPE_SHOP) != 0) goto _0807FD6E;
    if (((terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)) != TERRAIN_TYPE_NORMAL)) goto _0807FD6E;
    if (tile->object != NULL) {
        if (GetEntityType(tile->object) != ENTITY_TRAP) goto _0807FD6E;
        GetTrapData(tile->object)->id = trapID;
        GetTrapData(tile->object)->unk1 = param_3;
        tile->object->isVisible = TRUE;
    }
    else {
        entity = sub_8045684(trapID,pos,param_3);
        if (entity == NULL)
_0807FD6E:
            return FALSE;
        else
        {
                tile->object = entity;
                tile->object->isVisible = TRUE;
        }
    }
    return TRUE;
}

bool8 sub_807FD84(Entity *entity)
{
  bool8 flag;
  flag = FALSE;
  
  if (gDungeon->unk13570 == 0) {
    return FALSE;
  }
  else {
    gDungeon->unk13570 = 0;
    flag = LayTrap(&gDungeon->trapPos,gDungeon->trapID,gDungeon->unk13579);
    if (flag) {
      sub_8052364(entity,&gDungeon->trapPos,*gUnknown_80FC5F8); // A trap was laid!
    }
    else {
      sub_8052364(entity,&gDungeon->trapPos,*gUnknown_80FC5FC); // A trap can't be laid here.
    }
    sub_8049ED4();
  }
  return flag;
}
