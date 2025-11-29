#include "global.h"
#include "globaldata.h"
#include "blow_away.h"
#include "constants/ability.h"
#include "constants/dungeon_exit.h"
#include "constants/residual_damage.h"
#include "constants/weather.h"
#include "dungeon_vram.h"
#include "dungeon_message.h"
#include "dungeon_mon_sprite_render.h"
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
#include "dungeon_8041AD0.h"
#include "weather.h"
#include "dungeon_config.h"
#include "dungeon_misc.h"
#include "dungeon_items.h"
#include "dungeon_strings.h"
#include "dungeon_pos_data.h"
#include "dungeon_damage.h"
#include "dungeon_kecleon_shop.h"
#include "dungeon_engine.h"
#include "warp_target.h"
#include "move_orb_effects_5.h"
#include "expose_trap.h"

void BlowAwayTarget(Entity *pokemon, Entity *target, u32 direction)
{
    bool8 flag;
    s32 counter;
    Entity *entity;

    counter = 10;
    if (IsCurrentFixedRoomBossFight()) {
        TryDisplayDungeonLoggableMessage3_Async(pokemon,target,gUnknown_80FC9E8); // It couldn't be knocked flying!
        return;
    }

    if (pokemon == target) {
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
        TryDisplayDungeonLoggableMessage3_Async(pokemon,target,gUnknown_80FCA10); // {POKEMON_0} couldn't be knocked flying!
        return;
    }
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
    if (AbilityIsActive(target,ABILITY_SUCTION_CUPS)) {
        TryDisplayDungeonLoggableMessage3_Async(pokemon,target,gUnknown_80FCBCC); // {POKEMON_0} is anchored! It can't be knocked flying!
        return;
    }

    GetEntInfo(target)->action.direction = (direction + 4) & DIRECTION_MASK;
    sub_806CDD4(target, 6, (direction + 4) & DIRECTION_MASK);
    sub_80421C0(target,0x1a3);
    TryDisplayDungeonLoggableMessage3_Async(pokemon,target,gUnknown_80F8A0C); // {POKEMON_0} was blown away!
    flag = TRUE;
    entity = NULL;

    while (TRUE) {
        s32 i;
        const Tile *tile;
        PixelPos pos32;
        DungeonPos pos = target->pos;

        pos.x += gAdjacentTileOffsets[direction].x;
        pos.y += gAdjacentTileOffsets[direction].y;
        if (pos.x < 0 || pos.y < 0 || DUNGEON_MAX_SIZE_X <= pos.x || DUNGEON_MAX_SIZE_Y <= pos.y) {
            break;
        }

        pos32.x = gAdjacentTileOffsets[direction].x << 0xA;
        pos32.y = gAdjacentTileOffsets[direction].y << 0xA;

        for (i = 0; i < 6; i++) {
            IncreaseEntityPixelPos(target,pos32.x,pos32.y);
            if (ShouldDisplayEntity(target) != 0) {
                DungeonRunFrameActions(0x19);
            }
        }
        tile = GetTile(pos.x, pos.y);
        if (tile->monster != NULL) {
            entity = tile->monster;
            flag = FALSE;
            break;
        }
        if (sub_80705F0(target,&pos)){
            flag = GetTerrainType(tile) != TERRAIN_TYPE_WALL;
            break;
        }
        sub_80694C0(target,pos.x,pos.y,1);
        if (--counter <= 0) {
            flag = TRUE;
            break;
        }
    }

    if (!flag) {
        sub_807D068(target,&target->pos);
        sub_806F370_Async(pokemon,target,gBlowAwayDmgValue,0,0,0,DUNGEON_EXIT_FAINTED_FROM_BEING_KNOCKED,RESIDUAL_DAMAGE_REGULAR,0,0);
    }
    if (IsFloorOver()) {
        return;
    }
    if (entity != NULL) {
        Move move;

        InitPokemonMove(&move, MOVE_REGULAR_ATTACK);
        if (!sub_80571F0(entity,&move)) {
            TrySendImmobilizeSleepEndMsg(pokemon,entity);
            sub_806F370_Async(pokemon,entity,gBlowAwayDmgValue,0,0,0,DUNGEON_EXIT_FELLED_BY_POKEMON_FLYING,RESIDUAL_DAMAGE_REGULAR,0,0);
        }
    }
    if (IsFloorOver())
        return;
    if (!EntityIsValid(target))
        return;

    sub_806A5B8(target);
    if (sub_80706A4(target,&target->pos)) {
        WarpTarget(target,target,0,0);
    }
    if (!EntityIsValid(target)) {
        return;
    }
    sub_806CE68(target,8);
    if (GetEntInfo(target)->isTeamLeader) {
        gDungeon->unk1 = 0;
        gDungeon->unk5C0 = -1;
        DiscoverMinimap(&target->pos);
        sub_807EC28(FALSE);
    }
    sub_806A5B8(target);
    TryTriggerMonsterHouseWithMsg_Async(target,gDungeon->forceMonsterHouse);
}

void sub_807D068(Entity *pokemon, DungeonPos *pos)
{
    int pixelX;
    int posY;
    int pixelY;
    int posX;
    int counter;
    int iVar8;
    s32 diff;
    PixelPos local_34;
    int incrementX;
    int incrementY;

    posX = X_POS_TO_PIXELPOS(pos->x);
    posY = Y_POS_TO_PIXELPOS(pos->y);
    diff = abs(pokemon->pixelPos.x - posX);
    if (diff < 0xc)
        diff = abs(pokemon->pixelPos.y - posY);
    if (diff >= 0xc)
    {
        iVar8 = 0;
        pixelX = (pokemon->pixelPos).x;
        pixelY = (pokemon->pixelPos).y;
        incrementX = (posX - pixelX) / 0xc;
        incrementY = (posY - pixelY) / 0xc;

        for(counter = 0; counter < 0xC; counter++)
        {
            pixelX += incrementX;
            pixelY += incrementY;
            local_34.x = pixelX;
            local_34.y = pixelY;
            pokemon->unk1C = sin_4096(iVar8) * 0xc;
            UpdateEntityPixelPos(pokemon, &local_34);
            if (ShouldDisplayEntity(pokemon)) {
                DungeonRunFrameActions(0x1a);
            }
            iVar8 = iVar8 + 0xaa;
        }
    }
    local_34.x = posX;
    local_34.y = posY;
    pokemon->unk1C = IntToF248(0);
    UpdateEntityPixelPos(pokemon,&local_34);
    DungeonRunFrameActions(0x1a);
}
