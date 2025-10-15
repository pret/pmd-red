#include "global.h"
#include "globaldata.h"
#include "warp_target.h"
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
#include "dungeon_tilemap.h"
#include "dungeon_misc.h"
#include "dungeon_items.h"
#include "dungeon_strings.h"
#include "dungeon_kecleon_shop.h"
#include "dungeon_range.h"
#include "move_orb_effects_5.h"

void sub_80421AC(Entity * pokemon, Entity * target);
void sub_807BB78(Entity *pokemon);

void WarpTarget(Entity *pokemon, Entity *target, u32 param_3, DungeonPos *pos)
{
    EntityInfo *info;
    u32 direction;
    DungeonPos local_2c;
    bool8 flag;

    info = GetEntInfo(target);
    flag = FALSE;

    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    if (AbilityIsActive(target,ABILITY_SUCTION_CUPS)) {
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FCAE8);
        return;
    }
    if (IsCurrentFixedRoomBossFight()) {
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC97C);
        return;
    }
    if (param_3 == 1)
    {
        DungeonPos stairsPosition = gDungeon->stairsSpawn;
        if(stairsPosition.x == target->pos.x && stairsPosition.y == target->pos.y) {
            TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC9A0); // It's already on the stairs!
            PetrifiedStatusTarget(pokemon,target);
            return;
        }
    }

    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC584); // $m0 warped!
    TrySendImmobilizeSleepEndMsg(target,target);
    sub_80421AC(pokemon,target);
    if (ShouldDisplayEntity(target)) {
        direction = (info->action).direction;
        target->unk1C.raw += + 0x800;
        while ( target->unk1C.raw < 0xa000) {
            if ((gDungeonFramesCounter & 3) == 0) {
                direction = (direction + 1) & DIRECTION_MASK;
                info->action.direction = direction & DIRECTION_MASK;
                sub_806CE68(target,direction);
            }
            DungeonRunFrameActions(0x22);
            target->unk1C.raw += 0x800;
        }
    }


    switch(param_3)
    {
        default:
        case 0:
            if (!sub_8083660(&local_2c)) {
                local_2c = target->pos;
                flag = TRUE;
            }
            break;
        case 1:
            if (!sub_808384C(&local_2c,&gDungeon->stairsSpawn)) {
                local_2c = target->pos;
                flag = TRUE;
            }
            break;
        case 2:
            if (!sub_808384C(&local_2c,pos)) {
                local_2c = target->pos;
                flag = TRUE;
            }
            break;
        case 3:
            local_2c = *pos;
            break;

    }

    sub_80694C0(target,local_2c.x,local_2c.y,1);
    UpdateEntityPixelPos(target,0);
    sub_807BB78(target);
    UpdateCamera(1);
    if (ShouldDisplayEntity(target)) {
        direction = (info->action).direction;
        target->unk1C.raw = 0x9c00;
        do {
            if ((gDungeonFramesCounter & 3) == 0) {
                direction = (direction + 1) & DIRECTION_MASK;
                info->action.direction = direction & DIRECTION_MASK;
                sub_806CE68(target,direction);
            }
            DungeonRunFrameActions(0x22);
            target->unk1C.raw -= 0x400;
        } while (0 < target->unk1C.raw);
    }
    target->unk1C = IntToF248_2(0);
    DungeonRunFrameActions(0x22);
    if (flag) {
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FCB14); // But it dropped back at the same spot!
    }
    if (param_3 == 1) {
        PetrifiedStatusTarget(pokemon,target);
    }
    if (info->isTeamLeader) {
        DiscoverMinimap(&target->pos);
        gDungeon->unk1 = 0;
        gDungeon->unk5C0 = -1;
        sub_807EC28(0);
    }
    sub_806A5B8(target);
    TryTriggerMonsterHouseWithMsg(target,gDungeon->forceMonsterHouse);
}
