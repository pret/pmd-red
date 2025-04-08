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
#include "code_803E668.h"
#include "weather.h"
#include "dungeon_config.h"
#include "dungeon_misc.h"
#include "dungeon_items.h"
#include "dungeon_strings.h"

extern u32 gDungeonFramesCounter;

void sub_804EB30();
bool8 ExposeTrap(s32 x, s32 y);
void ShowWholeRevealedDungeonMap();
void sub_8049ED4();
void sub_806A5B8(Entity *);
u8 sub_8045888(Entity *);
void sub_807EC28(u32);
u8 sub_8044B28(void);
extern void sub_806F370(Entity *pokemon, Entity *target, u32, u32, u8 *, u8 moveType, s32, u32, u32, u32);
void sub_80421AC(Entity * pokemon, Entity * target);
void sub_807BB78(Entity *pokemon);
extern void sub_803F580(u32);
bool8 sub_808384C(DungeonPos *, DungeonPos *);
u8 sub_8083660(DungeonPos *);

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
    if (sub_8045888(target)) {
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
    sub_804535C(target,0);
    sub_807BB78(target);
    sub_803F580(1);
    if (sub_8045888(target)) {
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
        sub_804AC20(&target->pos);
        gDungeon->unk1 = 0;
        gDungeon->unk5C0 = -1;
        sub_807EC28(0);
    }
    sub_806A5B8(target);
    sub_8075900(target,gDungeon->forceMonsterHouse);
}
