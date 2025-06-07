#include "global.h"
#include "globaldata.h"
#include "constants/ability.h"
#include "constants/weather.h"
#include "dungeon_vram.h"
#include "dungeon_message.h"
#include "code_806CD90.h"
#include "code_807CD9C.h"
#include "structs/str_dungeon.h"
#include "code_8077274_1.h"
#include "dungeon_ai.h"
#include "run_dungeon.h"
#include "dungeon_generation.h"
#include "dungeon_logic.h"
#include "dungeon_map.h"
#include "dungeon_map_access.h"
#include "dungeon_util.h"
#include "math.h"
#include "move_effects_target.h"
#include "moves.h"
#include "move_util.h"
#include "code_8041AD0.h"
#include "weather.h"
#include "dungeon_config.h"
#include "dungeon_misc.h"
#include "dungeon_items.h"
#include "dungeon_strings.h"

void HandleDroughtOrbAction(Entity *pokemon, Entity *target)
{
	s32 x;
	s32 y;
	Tile *tile;
	bool8 flag;

	flag = FALSE;
	if(IsCurrentFixedRoomBossFight())
	{
		LogMessageByIdWithPopupCheckUser(pokemon, gUnknown_80FD060);
		return;
	}

	if(IsWaterTileset())
	{
		LogMessageByIdWithPopupCheckUser(pokemon, gUnknown_80FD08C);
		return;
	}

	for (y = 0; y < DUNGEON_MAX_SIZE_Y; y++)
		for(x = 0; x < DUNGEON_MAX_SIZE_X; x++)
		{
			tile = GetTileMut(x, y);
			if(GetTerrainType(tile) == TERRAIN_TYPE_SECONDARY)
			{
			    SetTerrainNormal(tile);
				sub_80498A8(x, y);
				flag = TRUE;
			}
		}
	for (y = 0; y < DUNGEON_MAX_SIZE_Y; y++)
		for(x = 0; x < DUNGEON_MAX_SIZE_X; x++)
			sub_8049BB0(x, y);

	if(flag)
	{
		sub_80421C0(pokemon, 0x1A1);
		LogMessageByIdWithPopupCheckUser(pokemon, gUnknown_80FD05C);
	}
	else
	{
		LogMessageByIdWithPopupCheckUser(pokemon, gUnknown_80FD060);
	}
	gDungeon->unk644.unk2C = 1;
	sub_806CF60();
	ShowWholeRevealedDungeonMap();
	sub_8049ED4();
}
