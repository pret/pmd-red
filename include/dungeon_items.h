#ifndef GUARD_DUNGEON_ITEMS_H
#define GUARD_DUNGEON_ITEMS_H

#include "structs/dungeon_entity.h"
#include "structs/str_position.h"
#include "structs/str_items.h"

void sub_8045BF8(u8 *buffer, Item *item);
void sub_8045C08(u8 *buffer, Item *item);
void sub_8045C18(u8 *buffer, Item *item);
#define FORCE_STICKY_RANDOM 0
#define FORCE_STICKY_ALWAYS 1
#define FORCE_STICKY_NEVER 2
void CreateItemWithStickyChance(Item *item, u8 itemID, u32 forceSticky);
void CreateFloorItems(void);
void PickUpItemFromPos(struct DungeonPos *pos, bool8 printMsg);
bool8 AddItemToDungeonAt(DungeonPos *pos, Item *item, bool8 a2);
bool8 RemoveItemFromDungeonAt(DungeonPos *pos, bool8 a2);
bool8 sub_80462AC(Entity * entity, u8 hallucinating, u8 a2, u8 a3, u8 a4);
const u8 *sub_80464AC(Item *item);
void sub_80464C8(Entity *entity, DungeonPos *pos, Item *item);
void sub_804652C(Entity *entity1, Entity *entity2, Item *item, bool8 a3, DungeonPos *pos);
void sub_8046860(Entity *entity, DungeonPos *pos, Item *item, s32 a4);
void sub_804687C(Entity *entity, DungeonPos *pos1, DungeonPos *pos2, Item *item, s32 count);
bool8 HasHeldItem(Entity *pokemon, u8 id);
void sub_8046D20(void);
bool8 sub_8046F00(Item *item);
void ClearAllItemsWithFlag(s32 itemFlag);
void AllItemsToPlainSeed(void);
bool8 PlayerHasItemWithFlag(s32 itemFlag);
void CleanUpInventoryItems(void);
void ClearUnpaidFlagFromAllItems(void);

#endif
