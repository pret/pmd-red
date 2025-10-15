#include "global.h"
#include "globaldata.h"
#include "one_room_orb.h"
#include "constants/ability.h"
#include "constants/weather.h"
#include "dungeon_vram.h"
#include "dungeon_message.h"
#include "code_806CD90.h"
#include "structs/str_dungeon.h"
#include "dungeon_entity_movement.h"
#include "run_dungeon.h"
#include "dungeon_generation.h"
#include "dungeon_logic.h"
#include "dungeon_map.h"
#include "dungeon_map_access.h"
#include "dungeon_util.h"
#include "math.h"
#include "move_orb_effects_1.h"
#include "moves.h"
#include "move_util.h"
#include "code_8041AD0.h"
#include "weather.h"
#include "dungeon_config.h"
#include "dungeon_misc.h"
#include "dungeon_items.h"
#include "dungeon_strings.h"
#include "warp_target.h"

void HandleOneRoomOrb(Entity *pokemon, Entity *target)
{
	bool8 bVar1;
	Tile *tile;
	s32 y;
	Entity *entity;
	s32 x;
	s32 index;
	bool8 isMonsterHouse;

	if (gDungeon->forceMonsterHouse != 0) {
		LogMessageByIdWithPopupCheckUser(pokemon,gUnknown_80FD3C8);
		return;
	}

	if (gDungeon->unk3A0B != 0) {
		LogMessageByIdWithPopupCheckUser(pokemon,gUnknown_80FD3CC);
		return;
	}

	if (IsFloorwideFixedRoom()) {
		LogMessageByIdWithPopupCheckUser(pokemon,gUnknown_80FD3D0);
		return;
	}
	isMonsterHouse = FALSE;

	for(x = 1; x < DUNGEON_MAX_SIZE_X - 1; x++)
	{
		for(y = 1; y < DUNGEON_MAX_SIZE_Y - 1; y++)
		{
			bVar1 = 0;
			tile = GetTileMut(x,y);
			tile->terrainFlags &= ~(TERRAIN_TYPE_UNK_x400);
			tile->room = 0;
			if ((tile->terrainFlags & TERRAIN_TYPE_IMPASSABLE_WALL) == 0)
			{
				if((tile->terrainFlags & TERRAIN_TYPE_UNBREAKABLE) == 0) {
					tile->spawnOrVisibilityFlags.spawn |= SPAWN_FLAG_STAIRS | SPAWN_FLAG_ITEM;
					tile->terrainFlags &= ~(TERRAIN_TYPE_NATURAL_JUNCTION);
					if ((tile->terrainFlags & TERRAIN_TYPE_IN_MONSTER_HOUSE)) {
						isMonsterHouse = TRUE;
					}
					if (GetTerrainType(tile) != TERRAIN_TYPE_SECONDARY)
						if((GetTerrainType(tile) != (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY))) {
							if (((x == 1) || (((y == 1 || (x == DUNGEON_MAX_SIZE_X - 2)) || (y == DUNGEON_MAX_SIZE_Y - 2)))) &&
								((tile->object == NULL && (gDungeon->unk644.unk2C == 0)))) {
								bVar1 = TRUE;
							}
							if (bVar1) {
                                SetTerrainSecondary(tile);
							}
							else {
								if (GetTerrainType(tile) == TERRAIN_TYPE_NORMAL) continue;
								SetTerrainNormal(tile);
								tile->terrainFlags |= TERRAIN_TYPE_UNK_x400;
							}
						}
				}
			}
		}
	}


	if (StairsAlwaysReachable(gDungeon->stairsSpawn.x,gDungeon->stairsSpawn.y,TRUE)) {
		for(x = 0; x < DUNGEON_MAX_SIZE_X; x++)
		{
			for(y = 0; y < DUNGEON_MAX_SIZE_Y; y++)
			{
				tile = GetTileMut(x,y);
				if (!(tile->terrainFlags & TERRAIN_TYPE_UNBREAKABLE))
					if(((tile->terrainFlags & (TERRAIN_TYPE_UNREACHABLE_FROM_STAIRS| TERRAIN_TYPE_UNK_x400)) == (TERRAIN_TYPE_UNREACHABLE_FROM_STAIRS| TERRAIN_TYPE_UNK_x400))) {
						SetTerrainSecondary(tile);
					}
			}
		}
	}
	if (isMonsterHouse) {
		gDungeon->monsterHouseRoom = FALSE;
	}
	for(x = 0; x < DUNGEON_MAX_SIZE_X; x++)
	{

		for(y = 0; y < DUNGEON_MAX_SIZE_Y; y++)
		{
			if (isMonsterHouse) {
				GetTileMut(x,y)->terrainFlags |= TERRAIN_TYPE_IN_MONSTER_HOUSE;
			}
			sub_8049BB0(x,y);
		}
	}

	for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
	{
		entity = gDungeon->activePokemon[index];
		if (EntityIsValid(entity)) {
			entity->room = GetTile(entity->pos.x,entity->pos.y)->room;
		}
	}
	sub_804EB30();
	sub_804AAD4();
	sub_8049884();
	DetermineAllMonsterShadow();
	UpdateMinimap();
	UpdateTrapsVisibility();
	LogMessageByIdWithPopupCheckUser(pokemon,gUnknown_80FD3A0);
	sub_803E708(0x28,0x2b);
	TryTriggerMonsterHouseWithMsg(pokemon,1);
	for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
	{
		entity = gDungeon->activePokemon[index];
		if (EntityIsValid(entity)) {
			sub_806A5B8(entity);
			if ((EntityIsValid(entity)) && (sub_80706A4(entity,&entity->pos))) {
				WarpTarget(entity,entity,0,0);
			}
		}
	}
	gDungeon->forceMonsterHouse = TRUE;
	sub_803E708(0x14,0x2b);
}
