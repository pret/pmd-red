#include "global.h"
#include "dungeon_util.h"

extern struct MapTile* GetMapTileAtPosition(s16, s16);

struct unk8049590
{
    u16 unk0;
    u16 fill2;
    u16 unk4;
    u16 unk6;
    u8 unk8;
};

extern struct unk8049590 *sub_8049590(s16, s16);

bool8 EntityExists(struct DungeonEntity *entity)
{
    if (!entity)
    {
        return FALSE;
    }
    return entity->entityType != ENTITY_NONE;
}

u32 GetEntityType(struct DungeonEntity *entity)
{
    return entity->entityType;
}

u8 GetEntityRoomIndex(struct DungeonEntity *entity)
{
    return entity->roomIndex;
}

struct DungeonEntityData *sub_8045104(struct DungeonEntity *entity)
{
    return entity->entityData;
}

struct ItemSlot *GetItemData(struct DungeonEntity *entity)
{
    return (struct ItemSlot *)entity->entityData;
}

struct DungeonEntityData *sub_804510C(struct DungeonEntity *entity)
{
    return entity->entityData;
}

struct DungeonEntityData *sub_8045110(struct DungeonEntity *entity)
{
    return entity->entityData;
}

struct MapTile *sub_8045114(struct DungeonEntity *entity)
{
    return GetMapTileAtPosition(entity->posWorldX, entity->posWorldY);
}

struct unk8049590 *sub_8045128(struct DungeonEntity *entity)
{
    return sub_8049590(entity->posWorldX, entity->posWorldY);
}
