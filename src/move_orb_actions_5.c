#include "global.h"
#include "globaldata.h"
#include "dungeon_info.h"
#include "dungeon_move_util.h"
#include "run_dungeon.h"
#include "dungeon_items.h"
#include "dungeon_map_access.h"
#include "dungeon_map.h"
#include "dungeon_message.h"
#include "dungeon_strings.h"
#include "dungeon_util.h"
#include "dungeon_misc.h"
#include "code_8077274_1.h"
#include "code_806CD90.h"
#include "status.h"

extern void sub_807F43C(Entity *, Entity *);
extern u32 GetRandomFloorItem(u32);
extern void sub_807FC3C(DungeonPos *, u32, u32);
extern void sub_8042A54(DungeonPos *);
extern void sub_8042A64(DungeonPos *);

bool8 FillInOrbAction(Entity *pokemon,Entity *target, Move *move, s32 param_4)
{
    Tile *tileToFill;
    EntityInfo *targetInfo;
    int y;
    bool8 filledInTile;
    int x;
    DungeonPos tileCoords;

    filledInTile = FALSE;
    targetInfo = GetEntInfo(target);
    if (IsBossFight()) {
        LogMessageByIdWithPopupCheckUser(pokemon,gUnknown_80FD0B8);
        return FALSE;
    }
    else
    {
        // Calculate the coordinates of the tile in front of the user
        tileCoords.x = target->pos.x + gAdjacentTileOffsets[targetInfo->action.direction].x;
        tileCoords.y = target->pos.y + gAdjacentTileOffsets[targetInfo->action.direction].y;

        sub_8042A54(&tileCoords);
        tileToFill = GetTileMut(tileCoords.x,tileCoords.y);
        if ((tileToFill->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)) == TERRAIN_TYPE_SECONDARY) {
            tileToFill->terrainType = (tileToFill->terrainType & ~(TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)) | TERRAIN_TYPE_NORMAL;

            for(y = -1; y < 2; y++)
                for(x = -1; x < 2; x++)
                    sub_80498A8(tileCoords.x + x, tileCoords.y + y);
            filledInTile = TRUE;
            sub_806CF60();
        }

        for(y = 0; y < DUNGEON_MAX_SIZE_Y; y++)
            for(x = 0; x < DUNGEON_MAX_SIZE_X; x++)
                sub_8049BB0(x,y);

        if (filledInTile) {
            sub_8042A64(&tileCoords);
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FD0B4);
        }
        else {
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FD0B8);
        }
        ShowWholeRevealedDungeonMap();
        sub_8049ED4();
        return filledInTile;
    }
}

bool8 TrapperOrbAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    u32 var;
    var = (GetEntInfo(target)->isNotTeamMember ? 2 : 1);
    sub_807FC3C(&target->pos, NUM_TRAPS, var);
    return TRUE;
}

bool8 ItemizeOrbAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    Item stack;
    DungeonPos posStruct = target->pos;

    if(GetEntInfo(target)->monsterBehavior != BEHAVIOR_FIXED_ENEMY)
    {
        TryDisplayDungeonLoggableMessage3(pokemon, target, gUnknown_80FF678);
        return FALSE;
    }
    else
    {
        target->isVisible = FALSE;
        CreateItemWithStickyChance(&stack, GetRandomFloorItem(0), 0);
        sub_80464C8(pokemon, &posStruct, &stack);
        sub_8068FE0(target, 0x218, pokemon);
        return TRUE;
    }
}

bool8 HurlOrbAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    sub_807F43C(pokemon, target);
    return TRUE;
}

bool8 MobileOrbAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    MobileStatusTarget(pokemon, target);
    return TRUE;
}

bool8 StairsOrbAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    HandleStairsOrb(pokemon, target);
    return TRUE;
}

bool8 LongtossOrbAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    LongTossStatusTarget(pokemon, target);
    return TRUE;
}

bool8 PierceOrbAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    PierceStatusTarget(pokemon, target);
    return TRUE;
}
