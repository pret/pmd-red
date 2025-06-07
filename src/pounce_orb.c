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

extern u8 sub_8045888(Entity *);
extern void sub_807EC28(u32);

void HandlePounceOrbAction(Entity *pokemon, Entity *target, u8 r2)
{
    EntityInfo *info;
    const Tile *tile;
    DungeonPos pos;
    u32 direction = r2;
    info = GetEntInfo(target);
    if(AbilityIsActive(target, ABILITY_SUCTION_CUPS))
    {
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], target, 0);
        TryDisplayDungeonLoggableMessage3(pokemon, target, gUnknown_80FCB98);
        return;
    }
    if(IsCurrentFixedRoomBossFight())
    {
        TryDisplayDungeonLoggableMessage3(pokemon, target, gUnknown_80FC9C0);
        return;
    }
    if(direction == NUM_DIRECTIONS)
        direction = info->action.direction;
    sub_806CDD4(target, 6, direction);


    while (1)
    {
        pos.x = target->pos.x + gAdjacentTileOffsets[direction].x;
        pos.y = target->pos.y + gAdjacentTileOffsets[direction].y;

        if(pos.x <= 0 || pos.y <= 0 || pos.x > DUNGEON_MAX_SIZE_X - 2 || pos.y > DUNGEON_MAX_SIZE_Y - 2) break;

        tile = GetTile(pos.x, pos.y);

        if(tile->monster) break;
        if(GetTerrainType(tile) == TERRAIN_TYPE_WALL) break;

        sub_80694C0(target, pos.x, pos.y, 0);

        sub_804535C(target, 0);
        if(!sub_8045888(target)) continue;
        DungeonRunFrameActions(0x3A);
    }

    sub_806A5B8(target);
    if(sub_80706A4(target, &target->pos))
        WarpTarget(target, target, 0, 0);
    if(EntityIsValid(target))
    {
        sub_806CE68(target, 8);
        if(info->isTeamLeader)
        {
            sub_804AC20(&target->pos);
            sub_807EC28(0);
        }
        sub_806A5B8(target);

        sub_8075900(target, gDungeon->forceMonsterHouse);
    }
}
